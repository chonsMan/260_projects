#include "label.hpp"
#include <fstream>
#include <string>
#include "interface.hpp"

using namespace std;

int main(){
    ifstream stream{"test.txt"};

    Label label;
    stream >> label;
    stream.close();
     
    while (interface_execute(cin, cout, label));
    
    ofstream output{"test.txt"};
    output << label << endl;
}

