class Solution10Jun {
    public int searchInsert(int[] nums, int target) {
        int l = 0, h = nums.length - 1;
        if (target > nums[h]) {
            return h + 1;
        }

        while (l < h) {

            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                l = mid + 1;
            } else
                h = mid;
        }
        return l;
    }

    public void swapColor(int[] nums, int k, int l) {
        int tmp = nums[k];
        nums[k] = nums[l];
        nums[l] = tmp;
    }

    public void sortColors(int[] nums) {
        final int N = nums.length;
        int l = 0;
        int m = 0;
        int h = N - 1;
        while (m <= h) {
            if (nums[m] == 0) {
                swapColor(nums, m, l);
                l++;
                m++;
            } else if (nums[m] == 1) {
                m++;
            } else {
                swapColor(nums, m, h);
                h--;
            }
        }
    }
}