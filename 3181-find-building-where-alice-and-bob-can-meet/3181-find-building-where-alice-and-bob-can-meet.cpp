class Solution {
    struct Query {
        int maxHeight;
        int maxIndex;
        int qIndex;

        Query(int mH, int mI, int qI): maxHeight(mH), maxIndex(mI), qIndex(qI) {}
    };

    class IndexComparator { 
    public: 
        int operator() (Query& q1, Query& q2) {
            return q1.maxIndex > q2.maxIndex; 
        }
    }; 

    class HeightComparator { 
    public: 
        int operator() (const Query& q1, const Query& q2) {
            return q1.maxHeight > q2.maxHeight; 
        }
    }; 

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        priority_queue <Query, vector<Query>, IndexComparator> minHeapIndex;
        int index = 0;

        int maxNum = -1;
        for(int i=0; i<heights.size(); i++)
            if(maxNum < heights[i])
                maxNum = heights[i];

        for(auto& query: queries) {

            int q0 = query[0];
            int q1 = query[1];

            if(heights[query[0]] == heights[query[1]])
                if(query[0] > query[1])
                    query[0]++;
                else if(query[1] > query[0])
                    query[1]++;

            if(q0 == q1 || !(max(heights[q0], heights[q1]) == maxNum && heights[min(q0, q1)] >= heights[max(q1, q0)]))
                minHeapIndex.push(Query(max(heights[q0], heights[q1]), max(query[0], query[1]), index));

            index++;
    }

        vector<int> buildings(queries.size(), -1) ;
        priority_queue <Query, vector<Query>, HeightComparator> minHeapHeight;

        for(int i=0; i<heights.size(); i++) {
            while(!minHeapIndex.empty() && minHeapIndex.top().maxIndex == i) {
                minHeapHeight.push(minHeapIndex.top());
                minHeapIndex.pop();
            }
            
            while(!minHeapHeight.empty() && minHeapHeight.top().maxHeight <= heights[i]) {
                buildings[minHeapHeight.top().qIndex] = i;
                minHeapHeight.pop();
            }
        }


        return buildings;
    }
};
