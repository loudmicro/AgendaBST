//
// Created by Juanu on 28/11/2020.
//

#include <fstream>
#include "Btree.h"

using namespace std;

Btree::Btree() {

    root = nullptr;

}

Btree::~Btree() {
    //destroy();
}

void Btree::destroy_tree(node *leaf) {

    if (leaf != nullptr) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }

}


node *Btree::createnode(Contacto &contacto) {

    node *temp = new node;
    temp->contacto = contacto;
    temp->left = nullptr;
    temp->right = nullptr;

    return temp;

}

void Btree::insert(Contacto &contacto) {

    root = insert(contacto, root);

}

node *Btree::insert(Contacto &contacto, node *leaf) {

    if (leaf == nullptr)
        leaf = createnode(contacto);
    else if (contacto <= leaf->contacto)
        leaf->left = insert(contacto, leaf->left);
    else
        leaf->right = insert(contacto,leaf->right);
    return leaf;


}

node *Btree::search(Contacto &contacto, node *leaf) {

    if (leaf != nullptr) {

        if (contacto == leaf->contacto) {
            return leaf;
        }
        //si es menor que lo busque en la rama de la izq
        if (contacto < leaf->contacto) {
            return search(contacto, leaf->left);
        }

        if (contacto > leaf->contacto) {
            return search(contacto, leaf->right);
        }

    }
    return nullptr;


}

void Btree::print(node *leaf) {


    if (leaf == nullptr) {
        return;
    } else {

        print(leaf->left);
        cout << leaf->contacto<< "\n";
        print(leaf->right);

    }

}

void Btree::print() {
    print(root);
    cout << "\n";

}


void *Btree::search(Contacto &contacto) {
    return search(contacto, root);
}

void Btree::destroy() {
    destroy_tree(root);
}

node *Btree::findMin(node *leaf) {
    if (leaf == nullptr) {
        return nullptr;
    } else if (leaf->left == nullptr) {
        return leaf;
    } else
        return findMin(leaf->left);

}

node *Btree::findMax(node *leaf) {
    if (leaf == nullptr) {
        return nullptr;
    } else if (leaf->right == nullptr) {
        return leaf;
    } else
        return findMax(leaf->right);

}

node *Btree::delete_node(Contacto *contacto, node *root) {
    node *temp;

    //caso base
    if (root == nullptr) {
        return root;
    }
    //si el nodo es menor que la raiz que vuelva a ejecturase pero con el nodo de la izq
    if (*contacto < root->contacto) {
        root->left = delete_node(contacto, root->left);
    }
        //si el nodo es mayot que la raiz que vuelva a ejecturase pero con el nodo de la derecha
    else if (*contacto > root->contacto) {
        root->right = delete_node(contacto, root->right);
    }
        //si el contacto es el mismo que en el nodo, es el que queremos eliminar
    else {
        //vamos a ver si tiene hijos el nodo

        //si no tiene hijo a la izq
        if (root->left == nullptr) {
            temp = root->right;
            delete root;
            return temp;
        }
        //si no tiene hijo a la derecha
        if (root->right == nullptr) {
            temp = root->left;
            delete root;
            return temp;
        }

        //si tiene dos hijos hay que buscar el menor en el arbol de la derecha
        temp = findMin(root->right);
        //copiamos el sucesor
        root->contacto = temp->contacto;

        //borramos el sucesor
        root->right = delete_node(&temp->contacto, root->right);

    }

    return root;


}

node *Btree::delete_node(Contacto *contacto) {

    return delete_node(contacto, root);
}

int Btree::count() {
    //numberofnodes = 0;
    return count(root);
}

int Btree::count(node *root) {

    if (root == nullptr) {
        return 0;
    } else {

        return 1 + count(root->left) + count(root->right);
    }


}

Contacto *Btree::search_by_id(string id) {

    node *resul = search_by_id(id, root);
    Contacto *temp = &resul->contacto;
    return temp;
}

node *Btree::search_by_id(string id, node *leaf) {

    if (leaf != nullptr) {

        if (id == leaf->contacto.getId()) {
            return leaf;
        }
        //si es menor que lo busque en la rama de la izq
        if (id < leaf->contacto.getId()) {
            return search_by_id(id, leaf->left);
        }else{
            return search_by_id(id, leaf->right);
        }

    } else {
        return nullptr;
    }


    return nullptr;
}



void Btree::loadAll() {
    loadAll(this->root);

}

void Btree::saveAll() {
    saveAll(this->root);

}

void Btree::loadAll(node *root) {
    //TODO implementar



}

node* Btree::saveAll(node *root) {
    //TODO implementar
    return nullptr;

}










