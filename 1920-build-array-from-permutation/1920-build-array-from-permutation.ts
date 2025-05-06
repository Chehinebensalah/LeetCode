function buildArray(nums: number[]): number[] {
    const n: number = nums.length;
    let result_array: number[] = [];
    for (let i = 0; i < n; i++) {
        result_array[i] = nums[nums[i]];
    }
    return result_array;
};