// 1. Maximum Sub Array sum
int best=0, sum=0;
for(int i=0; i<A.size(); i+=1){
	sum = max(A[i], sum+A[i]);
	best = max(best, sum);
}


