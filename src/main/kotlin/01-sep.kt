class Solution01Sep {

    private fun isValid(A: IntArray): Boolean {
        val hour = 10 * A[0] + A[1]
        val mins = 10 * A[2] + A[3]

        return hour < 24 && mins < 60
    }

    fun largestTimeFromDigits(A: IntArray): String {
        // sort asc
        A.sort()
        if (!isValid(A)) return ""

        val lm = listOf(
            intArrayOf(A[3], A[2], A[1], A[0]),
            intArrayOf(A[3], A[2], A[0], A[1]),
            intArrayOf(A[3], A[1], A[2], A[0]),
            intArrayOf(A[3], A[1], A[0], A[2]),
            intArrayOf(A[3], A[0], A[2], A[1]),
            intArrayOf(A[3], A[0], A[1], A[2]),
            intArrayOf(A[2], A[3], A[1], A[0]),
            intArrayOf(A[2], A[3], A[0], A[1]),
            intArrayOf(A[2], A[1], A[3], A[0]),
            intArrayOf(A[2], A[1], A[0], A[3]),
            intArrayOf(A[2], A[0], A[3], A[1]),
            intArrayOf(A[2], A[0], A[1], A[3]),
            intArrayOf(A[1], A[3], A[2], A[0]),
            intArrayOf(A[1], A[3], A[0], A[2]),
            intArrayOf(A[1], A[2], A[3], A[0]),
            intArrayOf(A[1], A[2], A[0], A[3]),
            intArrayOf(A[1], A[0], A[3], A[2]),
            intArrayOf(A[1], A[0], A[2], A[3]),
            intArrayOf(A[0], A[3], A[2], A[1]),
            intArrayOf(A[0], A[3], A[1], A[2]),
            intArrayOf(A[0], A[2], A[3], A[1]),
            intArrayOf(A[0], A[2], A[1], A[3]),
            intArrayOf(A[0], A[1], A[3], A[2]),
            intArrayOf(A[0], A[1], A[2], A[3])
        )

          for (l in lm) {
            if (isValid(l)) return "${l[0]}${l[1]}:${l[2]}${l[3]}"
          }
        return ""

    }
}

/* class Solution {
    private int max_time = -1;

    public String largestTimeFromDigits(int[] A) {
        this.max_time = -1;
        permutate(A, 0);
        if (this.max_time == -1)
            return "";
        else
            return String.format("%02d:%02d", max_time / 60, max_time % 60);
    }

    protected void permutate(int[] array, int start) {
        if (start == array.length) {
            this.build_time(array);
            return;
        }
        for (int i = start; i < array.length; ++i) {
            this.swap(array, i, start);
            this.permutate(array, start + 1);
            this.swap(array, i, start);
        }
    }

    protected void build_time(int[] perm) {
        int hour = perm[0] * 10 + perm[1];
        int minute = perm[2] * 10 + perm[3];
        if (hour < 24 && minute < 60)
            this.max_time = Math.max(this.max_time, hour * 60 + minute);
    }

    protected void swap(int[] array, int i, int j) {
        if (i != j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}*/
