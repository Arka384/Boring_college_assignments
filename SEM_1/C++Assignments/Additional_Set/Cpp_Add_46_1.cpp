#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
2049874329569346590314032475981765481654981644659031654916541403247598176548165498465903165491654140324759817654816549049874320498743204987432846590316549165414032475981765481654984659031654916541403247598176548165498404987432049874326590316654916541403247598176548165498164

549165414032475981765481654981645491654140324759817654816549816454916541403247598176548165498164465903165491654140324759817654816549846590316549165414032475981765481654904987432049874320498743284659031654916541403247598176548165498465903165491654140324759817654816549840498743204987432659031654916541403247598176548165498465903165491654140324759817654816549804987432

11257200849124943433279170670345590296394826431637982736894156783614047460
6069555061521996602639841369507753377321390258486884847575965766127193320
9955053202525647820400414708801983276020521062487451802209996536703195310
2897905672581374722214270241537451528342328644195340629616583748184183010
9553987916601419343086276192729083176107434065623277401910202389884620483
00710540110084113161819115299586866213373807327629104014067572104564200428
19390546124148789927935018864897890367228383203452775119066448885949800268
32538335818666222106066306040997994899237987666011526181379195399211680401
8370032720799941115386857377456084006684714039074848

*/

void input(const std::string&, const std::string&, std::vector<int>& num1, std::vector<int>& num2);
void multiply(const std::vector<int>& , const std::vector<int>& , std::vector<int>& );


int main()
{
	std::string a, b;
	std::vector<int> num1, num2;
	std::cout << "\nEnter number 1: ";
	std::cin >> a;
	std::cout << "\nEnter number 2: ";
	std::cin >> b;
	input(a, b, num1, num2);
	std::vector<int> result((a.length() + b.length()), 0);
	
	multiply(num1, num2, result);

	// for(auto i : num1)
	//     std::cout<<i;
	// std::cout<<"\n";
	// for(auto i : num2)
	//     std::cout<<i;    
	// for(auto i : result)
	// 	std::cout<<i;
}

void multiply(const std::vector<int>& num1, const std::vector<int>& num2, std::vector<int>& output) {
	int k = 0, l = 0, carry = 0, outputSize = 0;

	for(int j=num2.size()-1;j>=0;j--) {
		for(int i=num1.size()-1;i>=0;i--) {
			int x = (num1[i] * num2[j]) + carry + output[k];
			output[k] = (x % 10);
			carry = x / 10;
			k++;
		}
		if(carry != 0) {
			output[k] = carry;
			carry = 0;
			k++;
		}
		l++;
		outputSize = k;
		k = l;
	}

	std::cout<<"\n\n";
	for(int i=outputSize-1;i>=0;i--)
		std::cout<<output[i];
	//std::reverse(output.begin(), output.end());
}


void input(const std::string& a, const std::string& b, std::vector<int>& num1, std::vector<int>& num2) {
	for (int i = 0; i < a.length(); i++)
		num1.push_back(a[i] - 48);
	for (int i = 0; i < b.length(); i++)
		num2.push_back(b[i] - 48);
}