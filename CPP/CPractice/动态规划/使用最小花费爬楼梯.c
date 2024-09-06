#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

int minCostClimbingStairs(int *cost, int costSize)
{
    int *minCost = (int *)malloc(sizeof(int) * (costSize + 1)); // 用来存储到达每一级台阶所用的最小花费
    minCost[0] = 0;                                             // 第0级和第1级台阶不用花费就可以到达
    minCost[1] = 0;
    for (int i = 2; i <= costSize; i++) // 从第2级台阶开始计算 cost[i]是从第i级台阶向上爬的费用 爬完台阶才算登顶,即到达第costSize级台阶
    {
        minCost[i] = fmin(cost[i - 1] + minCost[i - 1], cost[i - 2] + minCost[i - 2]);
    }
    return minCost[costSize];
}