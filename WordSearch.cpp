class Solution
{

public:
    bool exist(vector<vector<char>> &board, int i, int j, string word, int pos)
    {

        if (pos == word.size())
        {

            return true;
        }

        //Now,Checking that whether the cell we are accessing is withing the Grid Boundary Or Not :

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        {

            return false
        }

        if (word[pos] != board[i][j])
        {

            return false;
        }

        char temp = board[i][j];
        board[i][j] = '*';

        //Now Recursing in all the Four Directions:

        if (exist(board, i + 1, j, word, pos + 1)

            || exist(board, i - 1, j, word, pos + 1)

            || exist(board, i, j + 1, word, pos + 1)

            || exist(board, i, j - 1, word, pos + 1))

        {

            return true;
        }

        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        for (int i = 0; i < board.size(); i++)
        {

            for (int j = 0; j < board[0].size(); j++)
            {

                //Now , Implementing the Logic Here :

                if (word[0] == board[i][j] && exist(board, i, j, word, 0))

                    return true;
            }
        }

        //If We Come Out Of The Loop , this conveys that we have not found the Solution , therefore:

        return false;
    }
};