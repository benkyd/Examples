// Hitler sort: given a list {0, 2, 5, 1, 3, 6}
//eliminate any items not in the correct order
//output {0, 2, 5, 6}. 

// This is the most efficient sorting algorithm
//at O(n) efficiency

/**
 * @param {number[]|object[]} arr - Array of elements to sort
 */
module.exports.HitlerSort = (arr) => {
    let lastElement = arr[0];
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] < lastElement) {
            arr.splice(i, 1);
        } else {
            lastElement = i;
        }
    }
    return arr;
}

// Bubble sort for comparison

/**
 * @param {number[]|object[]} arr - Array of elements to sort
 */
module.exports.BubbleSort = (arr) => {
    let len = arr.length;

}

// QuickSort for comparison

/**
 * @param {number[]|object[]} arr - Array of elements to sort
 */
module.exports.QuickSort = (arr) => {

}

// Test

const Sort = require('./index');
console.log(Sort.HitlerSort([1, 2, 3, 4, 5, 1, 3, 5, 6]));
console.log(Sort.HitlerSort([5, 6, 3, 1, 4, 7, 6, 5, 1]));
console.log(Sort.HitlerSort([6, 3, 3, 4, 7, 1, 3, 2, 5]));
console.log(Sort.HitlerSort([1, 9, 8, 4, 4, 2, 8, 2, 3]));

console.log(Sort.BubbleSort([1, 2, 3, 4, 5, 1, 3, 5, 6]));
console.log(Sort.BubbleSort([5, 6, 3, 1, 4, 7, 6, 5, 1]));
console.log(Sort.BubbleSort([6, 3, 3, 4, 7, 1, 3, 2, 5]));
console.log(Sort.BubbleSort([1, 9, 8, 4, 4, 2, 8, 2, 3]));

console.log(Sort.QuickSort([1, 2, 3, 4, 5, 1, 3, 5, 6]));
console.log(Sort.QuickSort([5, 6, 3, 1, 4, 7, 6, 5, 1]));
console.log(Sort.QuickSort([6, 3, 3, 4, 7, 1, 3, 2, 5]));
console.log(Sort.QuickSort([1, 9, 8, 4, 4, 2, 8, 2, 3]));
