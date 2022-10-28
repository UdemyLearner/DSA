vector<int> bs(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1;
    int m = s + (e - s) / 2;
    int f = -1, l = -1;
    while (s < e)
    {
        if (target == nums[m])
        {
            f = m;
            if (nums[m - 1] == target)
            {
                f = m - 1;
                l = m;
            }
            if (nums[m + 1] == target)
            {
                l = m + 1;
            }
        }
        if (nums[m] < target)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return {f, l};
}