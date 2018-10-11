#include "list.hpp"
#include "label.hpp"
#include "artist.hpp"
#include <sstream>
#include <string>

using namespace std;

int main(){
    string source{"Eminem;rapper from Michigan;good rapper\n"};
    stringstream stream{source}; 
    Artist artist = Artist::parse(stream);

    cout << artist << endl;
}

