/* 

//visita preOrder
void BST::preOrder(Nodo* p) const{
    if(p!=0){
        cout << p->val << "\t";
        preOrder(p->left);
        preOrder(p->right);
    }
}


//visita inOrder
void BST::inOrder(Nodo* p) const{
    if(p!=0){
        inOrder(p->left);
        cout << p->val << "\t";
        inOrder(p->right);
    }
}

//visita postOrder
void BST::postOrder(Nodo* p) const{
    if(p!=0){
        postOrder(p->left);
        postOrder(p->right);
        cout << p->val << "\t";
    }
}

*/
