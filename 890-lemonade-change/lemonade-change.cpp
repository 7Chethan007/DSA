class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, n = bills.size();
        for(int i = 0; i < n; i++) {
            if(bills[i] == 5) five += 1;
            else if(bills[i] == 10) {
                if(five){// must and should have one 5
                    five -= 1;
                    ten += 1;
                }else{
                    return false;
                }
            } else{ // custome giving $20
                if(ten && five) {
                    ten -= 1;
                    five -= 1;
                }
                else if(five >= 3){ // for returning 3 fives
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};