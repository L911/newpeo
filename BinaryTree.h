
template<typename T>
struct Node
{
	T data;
	Node* left = nullptr;
	Node* right = nullptr;
};

template<typename T>
class BinaryTree
{
public:
	typedef void(*Hanlder)(Node<T>* node);

private:
	Node<T>* m_root;
	int m_size;

private:
	void PreOrderNode(Node<T>* node, Hanlder func) const;
	void MidOrderNode(Node<T>* node, Hanlder func) const;
	void PostOrderNode(Node<T>* node, Hanlder func) const;

public:
	BinaryTree( ) : m_size(0)
	{
		m_root = new Node<T>();
		m_root->left = nullptr;
		m_root->right = nullptr;
	}

	int Size() const
		{ return m_size; }
	int GetNodeHeight(Node<T>* node) const;
	int Height() const;
	void Add(const T& data);
	void Delete(const T& data);
	void PreOrder(Hanlder func) const;
	void MidOrder(Hanlder func) const;
	void PostOrder(Hanlder func) const;

	void LevelOrder(Node<T>* node, Hanlder func) const;

	bool Find(const T& value);
	bool FindHelper(const T& value, Node<T>* root);
};

template<typename T>
int BinaryTree<T>::GetNodeHeight(Node<T>* node) const
{
	if (node == nullptr)
		return 0;

	int lheight = GetNodeHeight(node->left);
	int rheight = GetNodeHeight(node->right);

	return lheight > rheight ? (lheight + 1) :  (rheight + 1);
}

template<typename T>
int BinaryTree<T>::Height() const
{
	return GetNodeHeight(m_root);
}

template<typename T>
void BinaryTree<T>::Add(const T& data)
{
	if (m_size == 0)
	{
		m_root->data = data;
		m_size ++;

		return;
	}

	Node<T>* node = m_root;
	while(node!=nullptr)
	{
		if(data>node->data)
		{
		   if (node->right==nullptr)
		   {
			   Node<T>* rnode = new Node<T>();
			   rnode->data = data;
			   node->right = rnode;

			   return;
		   }
		   else
		   {
			   node = node->right;
		   }
		}
		else if (data<node->data)
		{
		   if (node->left==nullptr)
		   {
			   Node<T>* lnode = new Node<T>();
			   lnode->data = data;
			   node->left = lnode;

			   return;
		   }
		   else
		   {
			   node = node->left;
		   }
		}
	}

	m_size ++;
}

template<typename T>
void BinaryTree<T>::Delete(const T& data)
{
	if (m_size == 0)
		return;

	Node<T>* p = m_root;
	Node<T>* pp = nullptr;

	while(p!= nullptr && p->data !=data)
	{
		pp = p;
		if (data>p->data)
			p = p->right;
		else if (data<p->data)
			p = p->right;
	}

	if(p == nullptr)
		return;

	// 右子树中最小
	if (p->right != nullptr && p->left != nullptr)
	{
		Node<T>* minP = p->right;
		Node<T>* minPP = p;
		while(minP->left!=nullptr)
		{
			minPP = minP;
			minP = minP->left;
		}

		p->data = minP->data;

		p = minP;
		pp = minPP;
	}

/*
	// 左子树中最大
	if (p->right != nullptr && p->left != nullptr)
	{
		Node<T>* minP = p->left;
		Node<T>* minPP = p;
		while(minP->right!=nullptr)
		{
			minPP = minP;
			minP = minP->right;
		}

		p->data = minP->data;

		p = minP;
		pp = minPP;
	}
*/

	Node<T>* child = nullptr;
	if (p->left != nullptr)
		child = p->left;
	else if (p->right != nullptr)
		child = p->right;

	if (pp == nullptr)
		m_root = child;
	else if (pp->left == p)
		pp->left = child;
	else if (pp->right == p)
		pp->right = child;
}

template<typename T>
void BinaryTree<T>::PreOrder(Hanlder func)  const
{
	if (m_root ==nullptr)
		return;

	PreOrderNode(m_root, func);
}

template<typename T>
void BinaryTree<T>::PreOrderNode(Node<T>* node, Hanlder func)  const
{
	if (node == nullptr)
		return;

	func(node);
	PreOrderNode(node->left, func);
	PreOrderNode(node->right, func);
}

template<typename T>
void BinaryTree<T>::MidOrder(Hanlder func)  const
{
	if (m_root ==nullptr)
		return;

	MidOrderNode(m_root, func);
}

template<typename T>
void BinaryTree<T>::MidOrderNode(Node<T>* node, Hanlder func)  const
{
	if (node == nullptr)
		return;

	MidOrderNode(node->left, func);
	func(node);
	MidOrderNode(node->right, func);
}

template<typename T>
void BinaryTree<T>::PostOrder(Hanlder func)  const
{
	if (m_root ==nullptr)
		return;

	PostOrderNode(m_root, func);
}

template<typename T>
void BinaryTree<T>::PostOrderNode(Node<T>* node, Hanlder func)  const
{
	if (node == nullptr)
		return;

	PostOrderNode(node->left, func);
	PostOrderNode(node->right, func);
	func(node);
}

template<typename T>
void BinaryTree<T>::LevelOrder(Node<T>* node, Hanlder func)  const
{
	if (node == nullptr)
		return;

}

template<typename T>
bool BinaryTree<T>::Find(const T& value)
{
	return FindHelper(value, m_root);
}

template<typename T>
bool BinaryTree<T>::FindHelper(const T& value, Node<T>* root)
{
	if (root == nullptr)
		return false;

	if (root->data == value)
		return true;

	if (root->data > value)
		return FindHelper(value, root->left);

	if (root->data < value)
		return FindHelper(value, root->right);

	Node<T>* node = root;
	while(node!=nullptr)
	{
		if(node->data==value)
			return true;
		else if (node->data>value)
			node = node->left;
		else if (node->data<value)
			node = node->right;
	}

	return false;
}