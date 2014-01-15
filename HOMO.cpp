#include<cstdio>
#include<map>
#include<set>
#include<string.h>
using namespace std;

int main() {
	map <int,int> myMap;
	map<int,int>::iterator it;
	set <int> pairs;
	char operation[50];
	int cases,number;scanf("%d",&cases);
	while(cases--) {
		scanf("%s %d",operation,&number);
		if(!strcmp(operation,"insert")) {
			if(myMap.find(number)==myMap.end()) 
				myMap[number]=1;
			else {
				if(myMap[number]==1) 
					pairs.insert(number);
				myMap[number]++;
			}
		}
		else {
			if(!(myMap.find(number)==myMap.end())) {
				if(myMap[number]==1) {
					it=myMap.find(number);
					myMap.erase(it); 
				}
				else if(myMap[number]==2) {
					myMap[number]--;
					pairs.erase(number);
				}
				else
					myMap[number]--;
			}
		}
		if(myMap.size()>=2&&pairs.size())
			printf("both\n");
		else if(myMap.size()==1&&pairs.size())
			printf("homo\n");
		else if(myMap.size()>1)
			printf("hetero\n");
		else
			printf("neither\n");
	}
	return 0;
}
