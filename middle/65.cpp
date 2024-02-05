#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    enum state {
        initial,
        intsign,
        interger,
        point,
        point_without_int,
        fraction,
        exp,
        expsign,
        expnumber,
        end
    };
    enum charType {
        type_number,
        type_exp,
        type_point,
        type_sign,
        type_illegal
    };
    charType checkCharType(char ch) {
        if(ch >= '0' && ch <= '9') {
            return type_number;
        } else if (ch == 'e' || ch == 'E') {
            return type_exp;
        } else if (ch == '.') {
            return type_point;
        } else if (ch == '+' || ch == '-') {
            return type_sign;
        }
        return type_illegal;
    } 
    bool isNumber(string s) {
        unordered_map<state, unordered_map<charType,state>> transfer {
            {
                initial, {
                    {type_number, interger},
                    {type_point, point_without_int},
                    {type_sign, intsign}
                }
            },
            {
                point_without_int, {
                    {type_number, fraction},
                }
            },
            {
                intsign,{
                    {type_number, interger},
                    {type_point, point_without_int}
                }
            },
            {
                interger,{
                    {type_number, interger},
                    {type_point, point},
                    {type_exp, exp}
                }
            },
            {
                point, {
                    {type_number, fraction},
                    {type_exp, exp}
                }
            },
            {
                fraction,{
                    {type_number, fraction},
                    {type_exp, exp}
                }
            },
            {
                exp,{
                    {type_number, expnumber},
                    {type_sign, expsign}
                }
            },
            {
                expsign, {
                    {type_number, expnumber}
                }
            },
            {
                expnumber,{
                    {type_number, expnumber}
                }
            }
        };
        int len = s.length();
        state st = initial;
        for(int i=0; i<len; i++) {
            charType ct = checkCharType(s[i]);
            if(transfer[st].find(ct) == transfer[st].end()) {
                return false;
            }
            st = transfer[st][ct];
            if(st == end) {
                break;
            }
        } 
        if(st == interger || st == point || st == fraction || st == expnumber) {
            return true;
        }
        return false;
    }
};


int main() {
    Solution solution;

    // 编写测试用例
    std::string test_case1 = "46.e3";
    std::string test_case2 = "e9";
    std::string test_case3 = "3.";
    std::string test_case4 = ".";
    std::string test_case5 = "+.";

    // 执行测试
    std::cout << "Test Case 1: " << (solution.isNumber(test_case1) ? "True" : "False") << std::endl;
    std::cout << "Test Case 2: " << (solution.isNumber(test_case2) ? "True" : "False") << std::endl;
    std::cout << "Test Case 3: " << (solution.isNumber(test_case3) ? "True" : "False") << std::endl;
    std::cout << "Test Case 4: " << (solution.isNumber(test_case4) ? "True" : "False") << std::endl;
    std::cout << "Test Case 5: " << (solution.isNumber(test_case5) ? "True" : "False") << std::endl;

    return 0;
}
