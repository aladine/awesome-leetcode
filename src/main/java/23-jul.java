import java.util.*;

// Definition for a binary tree node.
 class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        LinearLCA lca = new LinearLCA(root);
        return lca.query(p, q);
    }

    public static class TreeNodeUtils {
        /**
         * return Euler Tour in an array. An Euler Tour
         * traverses every edge of a directed graph
         * exactly once and records which nodes are visited.
         * each undirected edge consists of two directed
         * edges of opposite directions.
         *
         * @param root
         * @return
         */
        public static TreeNode[] EulerTour(TreeNode root) {
            ArrayList<TreeNode> tour = new ArrayList<TreeNode>();
            EulerTour(tour, root);
            return tour.toArray(new TreeNode[0]);
        }
        private static void EulerTour(ArrayList<TreeNode> tour, TreeNode root) {
            if (root == null) {
                return;
            }
            tour.add(root);
            EulerTour(tour, root.left);
            if (root.left != null) {
                tour.add(root);
            }
            EulerTour(tour, root.right);
            if (root.right != null) {
                tour.add(root);
            }
        }
        /**
         * output levels (distance from root) in Euler tour order
         * @return
         */
        public static int[] getLevels(TreeNode root, TreeNode[] euler) {
            if (root == null || euler == null || euler.length == 0) {
                throw new IllegalArgumentException();
            }
            Map<TreeNode, Integer> node2levels = TreeNodeUtils.getLevels(root);
            int[] levels = new int[euler.length];
            for (int i = 0; i < euler.length; i++) {
                levels[i] = node2levels.get(euler[i]);
            }
            return levels;
        }
        /**
         * output levels in a Map with key as nodes
         * and values as levels. Use BFS (level-order
         * traversal) to find all levels.
         */
        public static Map<TreeNode, Integer> getLevels(TreeNode root) {
            Queue<TreeNode> toVisit = new LinkedList<TreeNode>();
            Map<TreeNode, Integer> node2level = new HashMap<TreeNode, Integer>();
            int currentLevel = 0;
            toVisit.offer(root);
            while(!toVisit.isEmpty()) {
                int currentLevelSize = toVisit.size();
                for (int i = 0; i < currentLevelSize; i++) {
                    TreeNode current = toVisit.poll();
                    if(current.left != null) {
                        toVisit.add(current.left);
                    }
                    if (current.right != null) {
                        toVisit.add(current.right);
                    }
                    node2level.put(current, currentLevel);
                }
                currentLevel++;
            }
            return node2level;
        }
    }

    public interface LCA {
        public TreeNode query(TreeNode p, TreeNode q);
    }
    public class LinearLCA implements LCA {
        private TreeNode[] euler;
        private Map<TreeNode, Integer> node2representatives;
        private int[] levels;
        private RMQ rmq;

        /**
         * initialize Euler tour, representatives, levels
         * and RMQ object
         * @param root
         */
        public LinearLCA(TreeNode root) {
            euler = TreeNodeUtils.EulerTour(root);
            node2representatives = getRepresentatives(euler);
            levels = TreeNodeUtils.getLevels(root, euler);
            this.rmq = new SparseTableRMQ(this.levels);
        }
        private Map<TreeNode, Integer> getRepresentatives(TreeNode[] euler) {
            Map<TreeNode, Integer> representatives = new HashMap<TreeNode, Integer>();
            for (int i = 0; i < euler.length; i++) {
                if (!representatives.containsKey(euler[i])) {
                    representatives.put(euler[i], i);
                }
            }
            return representatives;
        }
        public TreeNode query(TreeNode u, TreeNode v) {
            if (!node2representatives.containsKey(u) || !node2representatives.containsKey(v)) {
                throw new IllegalArgumentException();
            }
            int firstU = node2representatives.get(u);
            int firstV = node2representatives.get(v);
            return euler[rmq.min(Math.min(firstU, firstV), Math.max(firstU,firstV))];
        }
    }

    /*
     * interface for range minimum query problem
     *
     */
    public interface RMQ {
        public int min(int i, int j);
    }

    public class SparseTableRMQ implements RMQ{
        private int[][] st;
        private int[] pow;
        private int[] a;
        private int N;
        public SparseTableRMQ(int[] a) {
            this.a = a;
            N = a.length;
            if (N <= 1) {
                return;
            }
            //we get floor of lgN because
            //2*2^lgN is enough for query from 0 to N-1
            int lgN = (int) (Math.log(N)/Math.log(2));
            //pre-calculate powers of 2 to save time
            pow = pow2(lgN);
            st = new int[N][lgN + 1];
            //initialize first column
            for (int i = 0; i < N; i++) {
                st[i][0] = i;
            }
            for (int j = 1; j <= lgN; j++) {
                for (int i = 0; i < N; i++) {
                    //not all rows have lgN columns
                    //note that i is inclusive
                    if (i + pow[j] - 1 >= N) {
                        continue;
                    }
                    int leftMin = st[i][j-1];
                    int rightMin = st[i + pow[j-1]][j - 1];
                    //when there are ties, return smallest index
                    st[i][j] = a[leftMin] <= a[rightMin] ? leftMin : rightMin;
                }
            }
        }
        private int[] pow2(int n) {
            int[] pow = new int[n + 1];
            pow[0] = 1;
            for (int i = 1; i <= n; i++) {
                pow[i] = pow[i - 1] * 2;
            }
            return pow;
        }
        public int min(int i, int j) {
            if (i > j || i < 0 || j >= N) {
                throw new IllegalArgumentException();
            }
            if (N == 0) {
                return -1;
            }
            if (i == j || N == 1) {
                return i;
            }
            //find the step where 2*2^step >= j - i + 1
            int stepSize = (int) (Math.log(j - i + 1)/Math.log(2));
            if (pow[stepSize] == (j - i + 1)) {
                stepSize--;
            }
            /*
             * i------------------j
             * i--------i+step-1
             *     j-step+1-------j
             */
            int leftMin = st[i][stepSize];
            int rightMin = st[j - pow[stepSize] + 1][stepSize];

            return a[leftMin] <= a[rightMin] ? leftMin : rightMin;
        }

    }

}
