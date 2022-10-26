/* Sieve */
void sieve(int N) {
	bool isPrime[N+1];
	for(int i = 0; i <= N;++i) isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i * i <= N; ++i){
		if(isPrime[i] == true){
			for(int j = i * i; j <= N ;j += i) isPrime[j] = false;
		}
	}
}

/* Power Function */
int fastExpo(int a, int n){
	if(a==0) return 0;
	if(n==0) return 1;
	a%=mod;
	if(n==2)return a*a%mod;
	if(n==1)return a;
	if(n&1)return a*fastExpo(fastExpo(a,n>>1),2)%mod;
	else return fastExpo(fastExpo(a,n>>1),2);
}

/* Euclid GCD O(log(max(a, b)))*/
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}

/* Extended Eulcid O(log(max(a, b))) */
int g, x, y;
void extended_euclid(int a, int b){
	if(b==0){
		g = a;
		x = 1;
		y = 0;
		return;
	}
	extended_euclid(b, a%b);
	int x1=x, y1=y;
	x = y1;
	y = x1 - y1*(a/b);
}

/* Fermats Principle => A^(P-1)%P = 1 where P is Prime Number*/

/* Manachers Algorithm */
int manachersAlgorithm(string s, int N) {
    string str;
	for(int i=0; i<N; i+=1){
		str += '#';
		str += s[i];
	}
	str += '#';
    int len = (2 * N) + 1;
    int P[len];
    int c = 0; //stores the center of the longest palindromic substring until now
    int r = 0; //stores the right boundary of the longest palindromic substring until now
    int maxLen = 0;
    for(int i = 0; i < len; i++) {
    	P[i] = 0;
        //get mirror index of i
        int mirror = (2 * c) - i;
        
        //see if the mirror of i is expanding beyond the left boundary of current longest palindrome at center c
        //if it is, then take r - i as P[i]
        //else take P[mirror] as P[i]
        if(i < r) {
            P[i] = min(r - i, P[mirror]);
        }
        
        //expand at i
        int a = i + (1 + P[i]);
        int b = i - (1 + P[i]);
        while(a < len && b >= 0 && str[a] == str[b]) {
            P[i]++;
            a++;
            b--;
        }
        
        //check if the expanded palindrome at i is expanding beyond the right boundary of current longest palindrome at center c
        //if it is, the new center is i
        if(i + P[i] > r) {
            c = i;
            r = i + P[i];
            
            if(P[i] > maxLen) { //update maxlen
                maxLen = P[i];
            }
        }
    }
    return maxLen;
}


/* Longest Prefix Suffix array */
void LPS(string pat){
    int j=0, i=1;
    int M = pat.size();
    while(i<M){
        if(pat[i]==pat[j]){
            lps[i] = j+1;
            i += 1;
            j += 1;
        }
        else{
            if(j==0){
                lps[i] = 0;
                i += 1;
            }
            else
                j = lps[j-1];
        }
    }
}