Node* remove(Node* root, int data){
   Node* temp = NULL;
   if(data < root->data()){
      root->left = this->remove(root->left, data);
   }
   else if(data > root->data()){
      root->right = this->remove(root->right, data);
   }
   else{
      if(!(root->left)){
         temp = root;
         root = root->right;
         delete temp;
         temp = null;
         --(this->_size);
      }
      else if(!(root->right)){
         temp = root;
         root = root->left;
         delete temp;
         temp = NULL;
         --(this->_size);
      }
      else{
         //Member function needs to change
         temp = this->minimum(root->right);
         //will need to figure out a way to do this
         //root->data = temp->data;
         Node* temp2  = new Node(temp->data());
         temp2->left  = root->left;
         temp2->right = root->right;
         root->left   = NULL;
         root->right  = NULL;
         delete root;
         root         = temp2;
         temp2        = NULL;
         root->right  = this->delete(root->right, temp->data());
      }
   }
   return root;
}
