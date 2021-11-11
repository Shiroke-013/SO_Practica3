#include "memory.h"
using namespace std;

bool Memory::findPage(vector<int>& frame, int val)
{
    for (int i = 0; i< frame.size(); i++)
    {
        if (frame[i] == val)
        {
            return true;
        }
    }
    return false;
}

int Memory::findNextNotUsed(int pages[], vector<int>& frame, int pageSize, int index)
{
    int res = -1, farthest = index;
    for (int i = 0; i< frame.size(); i++)
    {
        int j;
        for (j = index; j<pageSize; j++)
        {
            if (frame[i] == pages[j] && j>farthest)
            {
                farthest = j;
                res = i;
            }
            break;
        }

        if(j == pageSize)
        {
            return i;
        }
    }
    return (res == -1) ? 0:res;
}

int Memory::LRU(int pages[], int n, int capacity, int maxPages)
{
    unordered_set<int> set;
    unordered_map<int, int> indexes;
    int page_faults = -1;
    int lru = INT_MAX, lru_val;

    if (n<=maxPages)
    {
        page_faults = 0;
        for(int i=0; i<n; i++)
        {
            if(set.size() < capacity)
            {
                if(set.find(pages[i]) == set.end()) 
                {
                    set.insert(pages[i]);
                    page_faults++;
                }

                indexes[pages[i]] = i;
            }

            else
            {
              if (set.find(pages[i]) == set.end())
              {
                for(auto it=set.begin(); it!=set.end(); it++)
                {
                  if(indexes[*it]< lru)
                  {
                    lru = indexes[*it];
                    lru_val = *it;
                  }
                }

                set.erase(lru_val);
                set.insert(pages[i]);
                page_faults++;
              }

              indexes[pages[i]] = i;
            }
        }
    }

    return page_faults;
}

int Memory::Optimal(int pages[], int pageSize, int frameSize)
{
    vector<int> frame;
    int page_faults = 0;

    for (int i = 0; i < pageSize; i++)
    {
        if (!findPage(frame, pages[i]))
        {
            if (frame.size() < frameSize)
            {
                frame.push_back(pages[i]);
                page_faults++;
            }
            else {
                int j = findNextNotUsed(pages, frame, pageSize, i + 1);
                frame[j] = pages[i];
                page_faults++;
            }  
        }
    }
    
    return page_faults;
}

bool Memory::inFrame(int value, list<int> frame)
{
    bool status = false;
    for(auto it = frame.begin(); it!= frame.end(); it++)
    {
        if (*it == value)
        {
            status = true;
            break;
        }
    }

    return status;
}

int Memory::FIFO(int pages[], int pageSize, int frameSize, int maxPageSize)
{
    list<int> frame;
    int page_fault = 0;

    if(pageSize <= maxPageSize)
    {
        for(int i = 0; i<pageSize; i++)
        {
            if(!inFrame(pages[i], frame))
            {
                if(frame.size()<frameSize)
                {
                    frame.push_back(pages[i]);
                }
                else {
                    frame.pop_front();
                    frame.push_back(pages[i]);
                }
                page_fault++;
            }
        }
    }

    return page_fault;
}