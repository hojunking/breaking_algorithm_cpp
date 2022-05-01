#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> sequence_of_integer;

bool is_feasible(sequence_of_integer& K, sequence_of_integer& deadline){
    for(int i=1; i <K.size(); i++)
        if(i > deadline[K[i]])
            return false;
    return true;
}
void schedule(int n, sequence_of_integer& deadline, sequence_of_integer &J){
    sequence_of_integer K;
    J.clear();
    J.push_back(0); // for an empty job
    J.push_back(1);
    for(int i =2; i<=n; i++){
        // K = J with i added according to nondecreasing values of deadline
        K.resize(J.size());
        copy(J.begin(), J.end(), K.begin());
        int j =1;
        while(j < K.size() && deadline[K[j]] <= deadline[i])
            j++;
        K.insert(K.begin() + j, i);
        if(is_feasible(K,deadline)){
            J.resize(K.size());
            copy(K.begin(), K.end(), J.begin());
        }
    }
}

int main(void){
    int n, max=0; cin >> n;
    sequence_of_integer deadline(n+1), K(n+1);

    //input dealine
    for(int i=1; i<n+1; i++)
        cin >> deadline[i];
    //input profit
    for(int i=1; i<n+1; i++)
        cin >> K[i];
    
    sequence_of_integer job;
    schedule(n , deadline, job);

    for(int i=1; i<job.size(); i++)
        max += K[job[i]];
    cout << max << "\n";

    for(int i=1; i<job.size(); i++){
        if(i <job.size()-1)
        cout << K[job[i]] << " ";
        else
        cout << K[job[i]] << "\n";
    }
}