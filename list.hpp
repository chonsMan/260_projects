#ifndef LIST_HPP
#define LIST_HPP
struct node{ //Template-abstractly representing all nodes
	song data; //Field inside node of type T 
	node* next; //Next is a field of type node ptr
};//struct 	

struct list{
public:
	list();
	~list();

	void addInsert(song s);			


	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);
private:
	node * head;
	node * curr;
	node * temp;
};
#endif

