#include <stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	auto s = [](int x){for(int i=0;i<x;++i) printf(" ");};
	s(a-1); printf(".\n");
	for(int i=1;i<a;++i){
		s(a-i-1);
		printf("/");
		for(int j=1;j<2*i;++j)
			printf("%c",'@'+(j<=i?j:2*i-j));
		printf("\\\n");
	}
}