class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> Rad;
        queue<int> Dire;
        int n = senate.size();

        for (int i=0; i<senate.size(); i++){
            if(senate[i] == 'R') Rad.push(i);
            else Dire.push(i);
        }

        while(!Rad.empty() && !Dire.empty()){
            if(Rad.front() < Dire.front()){ // Radiant 공격 순서
                Rad.push(Rad.front()+n); // n 을 더해서 다음 라운드임을 표시
                Rad.pop();
                Dire.pop();
            }
            else{ // Dire 공격 순서
                Dire.push(Dire.front()+n);
                Dire.pop();
                Rad.pop();
            }
        }

        return (Rad.empty()) ? "Dire" : "Radiant";
    }
};