#pragma once
#include<queue>
#include<vector>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        std::deque<int>myDeq;     //EXAMPLE:  1,3,-1, -3, 5, 3, 6, 7
        int size = nums.size();
        std::vector<int>toReturn(size - k + 1);
        int ind = 0;

        for (int i = 0; i < k; i++) // (3, -1)  -> res[0] = myDeq.front() = 3
        {
            while (!myDeq.empty() && myDeq.back() < nums[i])
                myDeq.pop_back();

            myDeq.push_back(nums[i]);   
        }

        toReturn[ind++] = myDeq.front();

        for (int i = k; i < size; i++)  //(3 != (nums[3-3] = nums[0]), therefore we wont do pop_front for 3
        {
            if (myDeq.front() == nums[i - k]) //(3, -1, -3) & res[1] = 3 myDeq.front();
                myDeq.pop_front();           //then on the next iter 3 == nums(4-3) = nums[1] so we pop the 3 and we are left with (-1, -3)
                                            //after that we want to add 5 because i == 4 & we keep the deq monotonically decreasing, so we remove -1 and -3 and the front is now 5, res[2] = 5
            while (!myDeq.empty() && myDeq.back() < nums[i])
                myDeq.pop_back();               // MY DEQUE:
                                                // ----------------------------------------------------------------------------------------------------------------------------------------
            myDeq.push_back(nums[i]);           // biggest elements in that range | pushing smaller elements or removing the ones from the front it the current 1 we want to push is bigger
            toReturn[ind++] = myDeq.front();    // ----------------------------------------------------------------------------------------------------------------------------------------
        }
        return toReturn;
    }
};

class Solution {
    struct Node
    {
        int data;
        int ind;
        bool operator<(const Node& other)const
        {
            if (data == other.data)
                return ind < other.ind;

            return data < other.data;
        }
    };
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        //using maxHeap;
        int size = nums.size();
        std::priority_queue<Node>maxHeap;
        std::vector<int>toReturn;
        for (int i = 0; i < size; i++)
        {
            maxHeap.push({ nums[i], i });
            Node topEl = maxHeap.top();
            while (topEl.ind <= i - k)
            {
                maxHeap.pop();
                topEl = maxHeap.top();
            }
            //topEl is now valid;
            if (i >= k - 1) //за да не добавя първите 2 елемента(елемент на индекс 0 и елемент на индекс 1, 
                toReturn.push_back(topEl.data); //  трябва в масива резултат да имам толкова числа, колкото прозорчета, тоест nums.size() - k + 1)
        }

        return toReturn;
    }
};

