//import java.util.*;
//
//public class Aug07JavaSolution {
//        int min=0, max=0;
//        Map<Integer, List<Integer>> map = new HashMap();
//        public List<List<Integer>> verticalTraversal(TreeNode root) {
//            List<List<Integer>> res = new ArrayList();
//            if(root==null) return res;
//            Queue<TreeNode> qt = new LinkedList();
//            Queue<Integer> qi = new LinkedList();
//            qt.add(root);
//            qi.add(0);//not root.val
//            while(!qt.isEmpty()){
//                int size = qt.size();
//                Map<Integer,List<Integer>> tmp = new HashMap();
//                for(int i=0;i<size;i++){
//                    TreeNode cur = qt.poll();
//                    int idx = qi.poll();
//                    if(!tmp.containsKey(idx)) tmp.put(idx, new ArrayList<Integer>());
//                    tmp.get(idx).add(cur.val);
//                    if(idx<min)  min = idx;
//                    if(idx>max)  max = idx;
//                    if(cur.left!=null){
//                        qt.add(cur.left);
//                        qi.add(idx-1);
//                    }
//                    if(cur.right!=null){
//                        qt.add(cur.right);
//                        qi.add(idx+1);
//                    }
//                }
//                for(int key : tmp.keySet()){
//                    if(!map.containsKey(key)) map.put(key, new ArrayList<Integer>());
//                    List<Integer> list = tmp.get(key);
//                    Collections.sort(list);
//                    map.get(key).addAll(list);
//                }
//
//            }
//            for (int i=min; i<=max; i++){
//                List<Integer> list = map.get(i);
//                res.add(list);
//            }
//            return res;
//        }
//    }
//
