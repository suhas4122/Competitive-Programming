#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int aa = 0; aa < t; aa++){
		int x, y, z, k;
		cin >> x >> y >> z >> k;
        int printing[y];
		vector<int>printed;
		for(int i=0;i<y;++i)
		    cin >> printing[i];
		sort(printing, printing+y);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0;
		vector <int> ans;

		int currtime = 0, currbook = 0, machine = 0;

		while(currbook < x){
			if(!pq.empty()){
                pair<int, int> temp = pq.top();
                if(machine >= y || temp.first + printing[temp.second] <= printing[machine]){
                    int time = temp.first;
					int currmachine = temp.second;
					printed.push_back(time);
					pq.pop();
					pq.push({time + printing[currmachine], currmachine});
					++currbook;
				}
				else{
					pq.push({printing[machine], machine});
					++machine, ++currbook;
				}
			}
			else{
                pq.push({printing[machine], machine});
                ++machine, ++currbook;
			}
		}
		while(!pq.empty()){
			printed.push_back(pq.top().first);
			pq.pop();
		}

        int print_size = min((int)printed.size(),z);

		for(i=0; i<print_size; i++){
            pq.push(make_pair(printed[i]+k,1));
        }

		while(i < printed.size()){
			ans.push_back(pq.top().first);
			currtime = max(pq.top().first,printed[i]);
			pq.pop();
			pq.push(make_pair(currtime+k,1));
			++i;
		}

		while(!pq.empty()){
			ans.push_back(pq.top().first);
			pq.pop();
		}

        int n = ans.size();
		cout << ans[n-1] << "\n";
	}
	return 0;
}