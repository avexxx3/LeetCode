class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> matrix;
        
        {
        int rows = mat.size();
        int cols = mat[0].size();
        
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                matrix.insert({mat[i][j], pair(i, j)});
        }

        vector<int> rows(mat.size(), mat[0].size());
        vector<int> cols(mat[0].size(), mat.size());

        int size = arr.size();
        int i = 0;
        while(i < size) {
            pair p = *(matrix.find(arr[i]));

            if(!(--rows[p.second.first]) || !(--cols[p.second.second]))
                break;
            
            i++;
        }

        return i;
    }
};