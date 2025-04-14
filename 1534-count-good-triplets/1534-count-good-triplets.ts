let condition_a: number = 0, condition_b: number = 0, condition_c: number = 0;

function checkCondition(arr: number[], i: number, j: number, k: number): boolean {
    return Math.abs(arr[i] - arr[j]) <= condition_a &&
        Math.abs(arr[j] - arr[k]) <= condition_b &&
        Math.abs(arr[i] - arr[k]) <= condition_c;
}

function countGoodTriplets(arr: number[], a: number, b: number, c: number): number {
    condition_a = a;
    condition_b = b;
    condition_c = c;

    let result: number = 0;
    let n: number = arr.length
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            for (let k = j + 1; k < n; k++) {
                result += (checkCondition(arr, i, j, k) === true ? 1 : 0);
            }
        }
    }
    return result;
};