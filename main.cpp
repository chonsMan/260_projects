#include "label.hpp"
#include <sstream>
#include <string>

using namespace std;

int main(){
    string source{
        "!Eminem;rapper from Michigan;good rapper\n"
        "Lose Yourself;5.0;100;200\n"
        "Rap God;4.2;123;456\n"
        "!The Beatles;Some guys from England;They did some stuff\n"
        "Hard Day's Night;500.2;2;4\n"
        "That Other Song;2.1;2000;3000\n"
    };
    stringstream stream{source};

    Label label;
    stream >> label;

    cout << label << endl;
}

