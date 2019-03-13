#include <iostream>
#include <stdio.h>
#define OR 0
#define AND 1

using namespace std;
// int prevOp = OR;

void printStream(int bits[], int i, int limit){

	if(i>limit) return;
	
	if(i==limit){
		printf("p");
		return;
	}

	if(i==limit-1){
		if(bits[i]==0){
			printf("p * ");
			printStream(bits, limit, limit);
			// prevOp = AND;
		}else{
			printf("p | ");
			printStream(bits, limit, limit);
			// prevOp = OR;
		}
		return;
	}

	if(bits[i]==0 && bits[i+1] == 1){
		printf("p * (");
		printStream(bits, ++i, limit);
		printf(")");
		// prevOp = AND;
	}else{
		if(bits[i]==1){
			printf("p | ");
		}else{
			printf("p * ");
		}
		printStream(bits, ++i, limit);
	}
}

int main()
{
	float prob, t_prob;
	int precision, t_prec;
	cout << "Enter the probability: ";
	cin >> prob;
	if(prob < 0.0f || prob > 1.0f){
		cout << "Invalid input for probability: MUST BE BETWEEN 0 and 1" << endl;
		return 1;
	}
	else if (prob == 0.0f || prob == 1.0f){
		cout << prob << endl;
		return 0;
	}
	// 0 < prob < 1
	cout << "Precision in binary digits: ";
	cin >> precision;
	t_prob = prob;
	int bits[precision];
	for(int i=0; i<precision; ++i){
		t_prob *= 2;
		bits[i] = (int)t_prob;
		t_prob = (t_prob >= 1) ? t_prob - 1 : t_prob;
	}
	int limit = precision -1 ;
	while(limit > 0 && bits[limit]==0) --limit;
	printStream(bits, 0, limit);
	cout << endl;
	return 0;
}