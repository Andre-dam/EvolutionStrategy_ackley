#include <bits/stdc++.h>

#define C1 20.0
#define C2 0.2
#define C3 2.0*M_PI
#define N 30

using namespace std;

class Chromosome{
	
public:
	double output;
	std::vector<double> x_i;
	std::vector<double> stdev;
 	Chromosome();
	void ackley();
};
Chromosome::Chromosome(){
	for (int i = 0; i < N; i++){
		this->x_i.push_back(0.0);
		this->stdev.push_back(rand()%10);
		//this->x_i.push_back((rand()%31)-15.0);
	}
	this->ackley();
}
void Chromosome::ackley(){
	double aux1=0.0,aux2=0.0;
	for (int i = 0; i < N; i++){
		aux1 += pow(this->x_i[i],2);
		aux2 += cos(C3*this->x_i[i]);
	}
	aux1 = sqrt(aux1/N);
	aux2 = aux2/N;
	this->output = -C1 * exp(-C2*aux1) - exp(aux2) + C1 + 1;
}

int main(){
	srand (time(NULL));
	Chromosome a;
	for (int i = 0; i < 30; ++i)
	{
		cout << a.x_i[i]<<endl;
	}
	cout <<"output: "<< a.output;
	return 0;
}