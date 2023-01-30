#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

void getMatrix(std::vector<std::vector<int>>&, const std::string& );
void printMatrix(const std::vector<std::vector<int>>& );
std::pair<int, int> solution(const std::vector<std::vector<int>>&, std::vector<std::vector<int>>& );

int main()
{
    std::vector<std::vector<int>> matrix;
    std::string fileName = "Cpp_3_input_5.txt";
    getMatrix(matrix, fileName);
    if(matrix[matrix.size()-1][0] != 1) {
        std::cout<<"\nMax height is: 0 with cost: 0";
        return 0;
    }

    std::vector<std::vector<int>> result(matrix.size(), std::vector<int>(matrix[0].size(), INT32_MAX));
    // printMatrix(result);
    std::pair<int, int> ans = solution(matrix, result);
    printMatrix(result);
    std::cout<<"\nMax reachable height is: "<<ans.first<<" with cost of: "<<ans.second;

}

std::pair<int, int> solution(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& result) {
    std::queue<std::pair<int, int>> q;

    //initial case
    result[matrix.size()-1][0] = 0;
    q.push(std::make_pair(matrix.size()-1, 0));    

    while(!q.empty()) {
        std::pair<int, int> x = q.front();
        q.pop();
        //check up
        if(x.first > 0 && matrix[x.first-1][x.second] == 1) {
            if(result[x.first][x.second] + 4 < result[x.first-1][x.second]) {
                result[x.first-1][x.second] = result[x.first][x.second] + 4;
                q.push(std::make_pair(x.first-1, x.second));
            }
        }
        //check down
        if(x.first < matrix.size()-1 && matrix[x.first+1][x.second] == 1) {
            if(result[x.first][x.second] + 1 < result[x.first+1][x.second]) {
                result[x.first+1][x.second] = result[x.first][x.second] + 1;
                q.push(std::make_pair(x.first+1, x.second));
            }
        }

        //check right
        if(x.second < matrix[0].size()-1 && matrix[x.first][x.second+1] == 1) {
            if(result[x.first][x.second] + 2 < result[x.first][x.second+1]) {
                result[x.first][x.second+1] = result[x.first][x.second] + 2;
                q.push(std::make_pair(x.first, x.second+1));
            }
        }
        //check left
        if(x.second > 0 && matrix[x.first][x.second-1] == 1) {
            if(result[x.first][x.second] + 2 < result[x.first][x.second-1]) {
                result[x.first][x.second-1] = result[x.first][x.second] + 2;
                q.push(std::make_pair(x.first, x.second-1));
            }
        }
    }

    //obtain final result
    std::pair<int, int> ans;
    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[0].size();j++) {
            if(result[i][j] < INT32_MAX) {
                ans = std::make_pair(matrix.size()-i-1, result[i][j]);  //pair of height and its cost
                return ans;
            }
        }
    }
    return ans;
}


void getMatrix(std::vector<std::vector<int>>& matrix, const std::string& fileName) {
    char c;
    std::ifstream file(fileName);
    std::vector<int> rowVector;
    int row, col, index = 0;
    
    file >> row;
    file >> col;

    while(file >> c) {
        if(c == '1')
            rowVector.push_back(1);
        else if(c == '0')
            rowVector.push_back(0);
        index++;
        if(index == col) {
            index = 0;
            matrix.push_back(rowVector);
            rowVector.clear();
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& mat) {
    std::cout<<"\n";
    for(auto i : mat) {
        for(auto j : i)
            if(j == INT32_MAX)
                std::cout<<"_\t";
            else
                std::cout<<j<<"\t";
        std::cout<<"\n";
    }
}