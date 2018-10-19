#include "label.hpp"
#include <fstream>
#include <string>
#include "interface.hpp"

using namespace std;

int main(){
    Label label;

    ifstream { "test.txt" } >> label;

    Interface interface {cin, cout, label};
    while (interface.execute());

    ofstream { "test.txt" } << label << endl;
}

