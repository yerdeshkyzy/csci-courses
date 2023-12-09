#include <iostream>
#include "set.h"

// This is a recursive helper function that should create and return an exact
// copy of the tree structure rooted at original
set::treenode* set::copynodes(treenode* original)
{
	if(original!=nullptr)
	{		
		treenode* current;
		current=new treenode(original->value);
		current->left=copynodes(original->left);
		current->right=copynodes(original->right);
		return current;
	} else {
		return nullptr;
	}
}	

// This is a recursive helper function that should deallocate all of the
// nodes in the tree structure rooted at node
void set::deallocatenodes(treenode* node)
{
	if(node!=nullptr)
	{
		deallocatenodes(node->left);
		deallocatenodes(node->right);
		delete node;
		node=nullptr;
	}
}


// Returns true if the value i is in the ordered set
bool set::contains(int i) const
{
	return set::containshelper(i,root);
}

bool set::containshelper(int i, treenode *node)
{
	if(node==nullptr) return false;
	else if(node->value==i) return true;
	else if(i<node->value) return containshelper(i,node->left);
	else return containshelper(i,node->right);

}

// If the value i is not previously in the ordered set,
// insert it preserving the ordering and return true;
// Otherwise return false (indicating the value was already
// in the set)
bool set::insert(int i)
{
	if(!contains(i)){
		set_size++;
		if (root==nullptr){
			root=new treenode(i);
			return true;
		} else {
			return inserthelper(i, root);
		}
	} else return false;
}


bool set::inserthelper(int i, treenode *node)
{
	if(i < node->value){
		if(node->left==nullptr){
			node->left=new treenode(i);
		} else {
			inserthelper(i,node->left);
		}
	} else if (i>node->value){
		if(node->right==nullptr){
			node->right=new treenode(i);
		} else {
			inserthelper(i,node->right);
		}
	}
	return true;
}

// If the value i is in the ordered set, remove it and return true;
// Otherwise return false (indicating the value was not in the set)
//
// WE WILL NOT IMPLEMENT THIS FOR THE ASSIGNMENT
// bool remove(int i)


// Remove everything from the set
void set::clear()
{
		set_size=0;
		deallocatenodes(root);
		root=nullptr;
}

// Returns the number of items in the set
size_t set::size() const
{
	return set_size;
}

// Returns whether or not the set is currently empty
bool set::empty() const
{
	if(set_size==0) return true;
	else return false;
}


