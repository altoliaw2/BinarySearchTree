#include <iostream>

template <class CL1>
class Node{
	public:	CL1 cl1_Field;
    public:	Node<CL1>* op_Lt;
    public:	Node<CL1>* op_Rt;
    public: Node(CL1 cl1_Field){
        this->cl1_Field = cl1_Field;
        op_Lt = nullptr;
        op_Rt = nullptr;
    }
};

template<class CL1>
class Tree{
    public: Node<CL1>* op_Root;

    public: Tree(CL1 cl1_Data){
        op_Root = nullptr;

        op_Root = new Node<CL1>(cl1_Data);
    }

    public: ~Tree(){
        fn_TraInOrder(op_Root, true);
    }


    public: void InsNode(CL1 cl1_Data){
        Node<CL1>* op_NewN = new Node<CL1>(cl1_Data);

        for(Node<CL1>* op_Tmp= op_Root;;){
            if(op_Tmp->cl1_Field > cl1_Data){
                if(op_Tmp->op_Lt == nullptr){
                    op_Tmp->op_Lt = op_NewN;
                    break;
                }
                else{
                    op_Tmp = op_Tmp->op_Lt;
                }
            }
            else{
                if(op_Tmp->op_Rt == nullptr){
                    op_Tmp->op_Rt = op_NewN;
                    break;
                }
                else{
                    op_Tmp = op_Tmp->op_Rt;
                }
            }
        }
    }

    public: void fn_TraInOrder (Node<CL1>* op_Node, bool b_DMode =false){
        if (op_Node == nullptr){
            return;
        }
        fn_TraInOrder(op_Node->op_Lt, b_DMode);
        Node<CL1>* op_TmpR = op_Node->op_Rt;
        if(b_DMode == false){
            std::cout<<op_Node->cl1_Field<<" ";
        }
        else{
            delete op_Node;
        }
        fn_TraInOrder(op_TmpR, b_DMode);
    }
};


int main(){
    Tree<int> o_Tree(10);
    o_Tree.InsNode(5);
    o_Tree.InsNode(1);
    o_Tree.InsNode(7);
    o_Tree.InsNode(2);
    o_Tree.InsNode(40);
    o_Tree.InsNode(50);
	std::cout<<"Inorder traversal of the constructed tree: \n";
	o_Tree.fn_TraInOrder(o_Tree.op_Root);

	return 0;
}
