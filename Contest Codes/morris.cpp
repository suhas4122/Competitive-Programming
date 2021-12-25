int kthele(node* curr, int k){
    if(curr->left == NULL && k==1){
        return curr->value;
    }
    if(curr->left->size == k-1){
        return curr->value;
    }
    if(curr->left->size > k-1){
        return kthele(curr->left, k);
    }else{
        return kthele(curr->right, k-curr->left->siz-1);
    }
}