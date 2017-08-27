#include "Establishment.h"

class Array
{
    std::vector<Establishment *> data;
public:
    Array(){}
    ~Array(){}
    void print ()
	{
        for(int i = 0; i < data.size(); i++)
		{
            data[i]->print_info();
        }
    }
    void push_back(Establishment &element)
	{
		data.push_back(&element);
	}
    int remove(int id)
	{
		if(id<data.size() && id>-1) 
			data.erase(data.begin()+id);
		return 1;
	}
};