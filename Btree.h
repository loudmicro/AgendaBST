//
// Created by Juanu on 28/11/2020.
//

#ifndef AGENDALION_BTREE_H
#define AGENDALION_BTREE_H

#include "Contacto.h"

using namespace std;

struct node{
    Contacto contacto;
    node *left;
    node *right;

};

class Btree {

private:
    void destroy_tree(node *leaf);
    node *insert(Contacto &contacto, node *leaf);
    node *search (Contacto &contacto, node *leaf);
    node *search_by_id (string id, node *leaf);
    void print(node *leaf);
    node *root;
    node *delete_node(Contacto *contacto, node *leaf);
    node *findMin(node *leaf); //hecho
    node *findMax(node *leaf); //hecho
    node *createnode(Contacto &contacto);
    int count(node *root);
    void loadAll(node *root);
    node* saveAll(node *root);
    //int numberofnodes;


public:
    Btree();
    ~Btree();
    void insert(Contacto &contacto);
    void *search(Contacto &contacto);
    Contacto *search_by_id(string id);
    void destroy();
    void print();
    node *delete_node(Contacto *contacto);
    int count();
    void loadAll();
    void saveAll();




};


#endif //AGENDALION_BTREE_H
