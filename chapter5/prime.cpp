const int maxn = 10000001;
int prime[maxn], num = 0;
bool p[maxn];

void findPrime(int n){
    for(int i=2;i<n;i++){
        if(p[i] == false) {
            prime[num++] = i;
            for(int j=i+i;j<n;j+=i){
                p[j] = true;
            }
        }
    }
}