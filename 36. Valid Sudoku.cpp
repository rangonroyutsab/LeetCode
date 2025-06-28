class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        bool isValid = true;
        int  dx[]    = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int  dy[]    = {-1,  0, 1, -1, 0, 1, -1, 0, 1};

        // row-wise check
        for (int i = 0; i < 9 and isValid; i++) {
            bool isRepeat[10] = {false};
            for (int j = 0; j < 9 and isValid; j++) {
                char x = board[i][j];
                if (x == '.')
                    continue;
                if (isRepeat[x - '0']) {
                    isValid = false;
                    break;
                }
                isRepeat[x - '0'] = true;
            }
        }

        // column-wise check
        for (int i = 0; i < 9 and isValid; i++) {
            bool isRepeat[10] = {false};
            for (int j = 0; j < 9 and isValid; j++) {
                char x = board[j][i];
                if (x == '.')
                    continue;
                if (isRepeat[x - '0']) {
                    isValid = false;
                    break;
                }
                isRepeat[x - '0'] = true;
            }
        }

        // 3x3 block-wise check
        for (int i = 1; i < 9 and isValid; i += 3) {
            for (int j = 1; j < 9 and isValid; j += 3) {
                bool isRepeat[10] = {false};
                for (int k = 0; k < 9; k++) {
                    char x = board[i + dx[k]][j + dy[k]];
                    if (x == '.')
                        continue;
                    if (isRepeat[x - '0']) {
                        isValid = false;
                        break;
                    }
                    isRepeat[x - '0'] = true;
                }
            }
        }
        return isValid;
    }
};