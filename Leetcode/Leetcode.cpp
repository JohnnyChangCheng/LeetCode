#include "pch.h"
#include "iostream"
#include "lc_209.hpp"

using namespace System;


int main()
{
    Solution_3  sol;
    vector<int> nums = { 2, 3, 1, 2, 4, 3 };
    std::cout << sol.minSubArrayLen(7, nums) << std::endl;
    system("PAUSE");
    return 0;
}
