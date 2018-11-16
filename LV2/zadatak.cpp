#include <iostream>
#include <stdlib.h>
#define ARRAY_SIZE 900000

struct _Node {
    float val;
    struct _Node* next;
};
typedef _Node Node;

float slucajanBrojUnutarGranica(float a, float b)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void gen_arr(float V[], int n)
{
    for (int i = 0; i < n; i++)
    {
        V[i] = slucajanBrojUnutarGranica(0, 100);
    }
}

int seq_arr(int trazeni, float V[], int n)
{
    for (int i = 0; i < n; i++)
    {
    if(trazeni == V[i]) {
        return i;
    }
    
    }
    return 100000;
}

void gen_list(Node* node, float V[], int n)  {
    for (int i = 0; i < n; i++) {
        node->val = V[i];
        node->next = new Node;
        node = node->next;
    }
}

int seq_list(int trazeni, Node* node, int n)
{
    for (int i = 0; i < n; i++) {
        if(node->val == trazeni) {
            return i;
        }
        node = node->next;
    }
    
    return 100000;
}


int main() {
    clock_t t1,t2;
    std::cout << "Broj elementa" << ARRAY_SIZE <<std::endl;
    
    t1 = clock();
    float array[ARRAY_SIZE];
    gen_arr(array, ARRAY_SIZE);
    t2 = clock();

    std::cout <<"Formiranje niza:"<< (float) (t2-t1)/1000 << std::endl;
    
    t1 = clock();
    Node* first = new Node;  
    gen_list(first, array, ARRAY_SIZE);
    t2 = clock();
   
    std::cout << "Formiranje PP:" << (float) (t2-t1)/1000 << std::endl;
    
    t1 = clock();
    int x = seq_arr(1000,array,ARRAY_SIZE);
    t2 = clock();
    std::cout <<"Trazeenje niza:"<< (float) (t2-t1)/1000 << std::endl;


    t1 = clock();
    int y = seq_list(1000,first,ARRAY_SIZE);
    t2 = clock();
    std::cout <<"Trazeenje lsite:"<< (float) (t2-t1)/1000 << std::endl;
    std::cout<<x<<","<<y<<std::endl;
    return 0;
}
