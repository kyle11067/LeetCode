#include <iostream>
// #include "two_sum.h"
// #include "three_sum.h"
// #include "string_math_to_int.h"
// #include "letterCombinations.h"
// #include "four_sum.h"
// #include "swap_nodes_pairs.h"
// #include "first_occurrence.h"
// #include "divide_two_integers.h"
// #include "next_permutation.h"
// #include "searchinrotatedsortedarray.h"
// #include "firstlast.h"
// #include "validsudoku.h"
// #include "sudokusolver.h"
#include "permute.h"
#include "countandsay.h"
#include "combinationsum.h"
#include "multiplystrings.h"
#include "jumpgameii.h"
#include "rotate.h"
#include "groupanagrams.h"
#include "maximumsubarray.h"
#include "spiralmatrix.h"
#include "jumpgame.h"
#include "mergeintervals.h"
#include "insertintervals.h"
#include "spiralmatrixii.h"
int main(int argc, char * argv[]){

/* Two sum*/
    // std::vector<int> nums = {2,7,11,15};
    // int target = 9;
    // std::vector<int> indices = twoSum(nums, target);
    // for (int ind: indices)
    // {
    //     printf("%d ", ind);
    // }
    // printf("\n");
    
    // nums = {3,2,4};
    // target = 6;
    // indices = twoSum(nums,target);
    // for (int ind: indices)
    // {
    //     printf("%d ", ind);
    // }
    // printf("\n");
    


    /* Three sum*/
    
    /*
    std::vector<int> nums = {0,0,0,0}; //{-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> vectors = threeSum(nums);
    for (vector<int> vec: vectors)
    {
        printf("[");
        for (int n: vec)
        {
            printf("%d ", n);
        }
        printf("] ");
        
    }
    */


    /* string_math_to_int   */

    // std::string expression = "3 + 5 * 2";

    // int result = string_math_to_long(expression);

    // printf("%d\n" , result);

    /* letterCombinations*/

    // std::string digits = "2379";

    // std::vector<std::string> combos = letterCombinations(digits);

    // for (std::string s: combos)
    // {
    //     printf("%s ", s.c_str());
    // }

    /* fourSum */

    /*
    std::vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    std::vector<std::vector<int>> quadruplets = fourSum(nums, target);

    for (std::vector<int> quadruplet: quadruplets)
    {
        printf("[");
        for (int n: quadruplet)
        {
            printf("%d ,", n);
        }
        printf("] ");
    }
    */

   /* swap_nodes_pairs */

   /*
   ListNode h5(5);
   ListNode h4(4, &h5);
   ListNode h3(3, &h4);
   ListNode h2(2, &h3);
   ListNode h1(1, &h2);

   ListNode * head = &h1;


   ListNode * cur = swapPairs(head);
   while (cur != NULL)
   {
        printf("%d->", cur->val);
        cur = cur->next;
   } 
    */

   /* first_occurrence*/

    /*
    string haystack = "leetcode";
    string needle = "leeto";

    int ind = strStr(haystack, needle);
    printf(" %d " , ind);
    */

   /* divide two numbers*/

   /*
   int quotient = divide(-2147483648,-1);
   printf("%d ", quotient);
    return 0;
    */


/* nextPermutation*/

/*
   vector<int> nums = {2,2,3,5,4,3,2,2,1};
      nextPermutation(nums);

   printf("[");
    for (int n: nums)
    {
        printf("%d ", n);
    }

    printf("]");
    */


   /* Search in rotated sorted array */

   /*
   vector<int> nums = {1,3};
    int ind = search(nums, 0);
    printf("%d \n", ind);
*/

    /* find firstlast */

    /*
    vector<int> nums = {-3,-2,-1 };
    std::vector<int> indices = searchRange(nums, 0);
    printf("[ %d %d ]\n", indices.at(0), indices.at(1));
    */ 

   /* valid sudoku*/

   /*
   vector<vector<char>> board = {
 {'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};
   bool valid = isValidSudoku(board);
   std::cout << valid << " " << endl;
   */

  /* sudokusolver*/

/*
vector<vector<char>> board = {
 {'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};


solveSudoku(board);
for (vector<char> v: board)
{
    for (char c: v)
    {
        printf("%c ", c);
    }
    printf("\n");
}
*/

/* countandsay*/
/*
for (int n = 1; n <= 30; n++)
{   
    string out = countAndSay(n);
    printf("%s \n", out.c_str());
}
*/

/* combinationsum*/
/*
    std::vector<int> candidates  = {2,3,5};
    int target = 8;
    std::vector<std::vector<int>>  combinations =     combinationSum(candidates, target);
    for (std::vector v: combinations)
    {
        printf("[");
        for (int i: v)
        {
            printf("%d ", i);
        }
        printf("]\n");
    }
*/

/* combinationsum2*/

/*
std::vector<int> candidates = {10,1,2,7,6,1,5};
int target = 8;
std::vector<std::vector<int>>  combinations =     combinationSum2(candidates, target);
    for (std::vector v: combinations)
    {
        printf("[");
        for (int i: v)
        {
            printf("%d ", i);
        }
        printf("]\n");
    }
*/

/* multiply strings*/
/*
std::string num1 = "123";
std::string num2 = "456";
std::string product = multiply(num1,num2);
printf("%s\n", product.c_str());
  */

 /* jumpgameii.h*/

/*
 std::vector<int> nums = {1,1,1,1};
int minjumps = jump(nums);
    printf("%d \n", minjumps);
  */

 /* permute*/
 /* */
// std::vector<int> nums = {1,2,2,3,3};
//  std::vector<std::vector<int>> permutations = permute(nums);
 /* 
 for (std::vector<int> v: permutations)
 {
    printf("[");
    for (int c : v)
    {
        printf("%d, ", c);
    }
    printf("] ");
 }
*/

/* permuteUnique*/
//  nums = {1,1,2};
/*
 std::vector<std::vector<int>> permutations = permuteUnique(nums);
  for (std::vector<int> v: permutations)
 {
    printf("[");
    for (int c : v)
    {
        printf("%d, ", c);
    }
    printf("] ");
 }
 */

/* rotate matrix*/

/*
// std::vector<std::vector<int>> matrix = {{1,2,3},
//                                         { 4,5,6   },
//                                         {7,8,9 }};
std::vector<std::vector<int>> matrix = {{1,2,3,4},
                                        {5,6,7,8},
                                        {9,10,11,12},
                                        {13,14,15,16}};
rotate(matrix);

for (std::vector<int> v : matrix)
{
    printf("[");
    for (int n: v)
    {
        printf("%d ,",n);
    }
    printf("]\n");
}
  */

 /* groupanagrams*/

 /*
 std::vector<std::string> strs = {"a"};
std::vector<std::vector<std::string>> anagrams = groupAnagrams(strs);

for (std::vector<std::string> v : anagrams)
{
    printf("[");
    for (std::string s: v)
    {
        printf("%s ," , s.c_str());
    }
    printf("]");
}
*/

/* maximumsubarray*/
/*
std::vector<int> nums = {5,4,-1,7,8};

int maxsum = maxSubArray(nums);
printf("%d\n" , maxsum);
  */

 /*spiralmatrix*/

 /*
 std::vector<std::vector<int>> matrix = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};

std::vector<int> spiral = spiralOrder(matrix);
printf("[");
for (int n : spiral)
{
    printf("%d , ",n);
}

printf("]");
*/

/* jumpgame*/

/*
std::vector<int> nums = {1,0,1,0};
bool can = canJump(nums);
printf("%d \n", can);
*/
// std::vector<std::vector<int>> intervals = {{1,4}, {4,5}};
// std::vector<std::vector<int>> mergedIntervals = merge(intervals);

// for (std::vector<int> v : mergedIntervals)
// {
//     printf("[");
//     for (int n: v)
//     {
//         printf("%d ,",n);
//     }
//     printf("]");
// }


// std::vector<std::vector<int>> intervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
// std::vector<int> newInterval = {4,8};
// std::vector<std::vector<int>> newIntervals = insert(intervals, newInterval);
// for (std::vector<int> v: newIntervals)
// {
//     printf("[");
//     for (int n: v)
//     {
//         printf("%d, ", n);
//     }
//     printf("]");
// }
int n = 6;
std::vector<std::vector<int>> matrix = generateMatrix(n);

for (std::vector<int> v: matrix)
{
    printf("[");
    for (int i: v)
    {
        printf("%d, " , i);
    }
    printf("]\n");
}



   return 0;
}
