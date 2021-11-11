#include<string>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Memory{

    bool findPage(vector<int>& frame, int val);
    bool inFrame(int value, list<int> frame);
    int findNextNotUsed(int pages[], vector<int>& frame, int pageSize, int index);

    public:
    int LRU(int pages[], int n, int capacity, int maxPages);
    int Optimal(int pages[], int pageSize, int frameSize);
    int FIFO(int pages[], int pageSize, int frameSize, int maxPageSize);
};