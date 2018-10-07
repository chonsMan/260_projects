#include "list.hpp"





ostream& operator << (ostream& out, LinkedList& list) {
	node * p;
	for(p = list.head; p!=0; p = p->next)
		out << p->data;
	out<<endl;
	return out;
} 
