/**
 * @param {number[]} nums
 * @return {number}
 */
function removeDuplicates(nums) {
    console.log("removeDuplicates start");
    var i = 0;
    for (var j = 1; j < nums.length; j++) {
        if (nums[i] == nums[j]) {
            console.log("i = " + i + ",nums =" + nums[i]);
            console.log(nums[j]);
            continue;
        } else {
            i++;
            nums[i] = nums[j];
        }
    }
    return i;
}