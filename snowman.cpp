#include <iostream>

#include <string>
#include <vector>
#include <stdexcept>
namespace items{
    
const std::vector<std::string> Hats {"     \n _===_"," ___ \n .....","  _  \n  /_\\ "," ___ \n (_*_)",};
const std::vector<std::string> Nose{",",".","_"," ",};
const std::vector<std::string> Eye {".","o","O","-",};
const std::vector<std::string> LeftArmsup {" ","\\"," "," ",};
const std::vector<std::string> LeftArmsdown {"<"," ","/"," ",};
const std::vector<std::string> RightArmsup {" ","/"," "," ",};
const std::vector<std::string> RightArmsdown {">"," ","\\"," ",};
const std::vector<std::string> Torso{" : ","] [","> <","   ",};
const std::vector<std::string> Base{" : ","\" \"","___","   ",};
}

using namespace std;


namespace ariel
{
    
vector<int> check_digit (int num){
    vector<int> arr = { 0, 0, 0, 0, 0, 0,0,0};
    int digit =0;
    const int max_digit=4;
    const int min_digit=1;
    const int len =8;
    const int mud=10;

for (int i = 0; i < len; i++)
    {
        digit =(num%mud);
        //catch the inlegal 8 digit numbers.
        if (digit<min_digit||digit>max_digit){
		throw std::out_of_range{"not a legal digit!"};
        }
        digit--;
        arr.at(len-1-i) = digit;
        
        
        
        num=num/mud;
    }
    return arr;


}



//  HHHHH
//  HHHHH
// X(LNR)Y
// X(TTT)Y
//  (BBB)

string  snowman(int num)
{
    const int H=0;
    const int N=1;
    const int L=2;
    const int R=3;
    const int X=4;
    const int Y=5;
    const int T=6;
    const int B=7;
    const int max_8 =99999999;
    const int min_8=10000000;
    const int legal_length=8;


    //if the len of num inlegal (fast check to catch most of the expetion)
    if (num>max_8||num<min_8){
    throw std::out_of_range{"not in range of num!"};
    }

    //put the numbers of clothes that the user chose in array.
     vector<int> arr = check_digit(num);


//That how the Snow man should be:
//  HHHHH
//  HHHHH
// X(LNR)Y
// X(TTT)Y
//  (BBB)

std::string ans=" ";
//build the snow man part by part
    // part1 (Hat):" HHHHH
    //               HHHHH"
    
    ans.append(items::Hats.at(arr.at(H)));
    ans.append("\n");
    //part2: "X(LNR)Y"
    ans.append(items::LeftArmsup.at(arr.at(X)));
    ans.append("(");
    ans.append(items::Eye.at(arr.at(L)));
    ans.append(items::Nose.at(arr.at(N)));
    ans.append(items::Eye.at(arr.at(R)));
    ans.append(")");
    ans.append(items::RightArmsup.at(arr.at(Y)));
    ans.append("\n");

    //part 3 "X(TTT)Y"
    ans.append(items::LeftArmsdown.at(arr.at(X)));
    ans.append("(");
    ans.append(items::Torso.at(arr.at(T)));
    ans.append(")");
    ans.append(items::RightArmsdown.at(arr.at(Y)));
    ans.append("\n");
    
    //part 4  " (BBB)""
    ans.append(" (");
    ans.append(items::Base.at(arr.at(B)));
    ans.append(")");
    return ans ;
}

}


