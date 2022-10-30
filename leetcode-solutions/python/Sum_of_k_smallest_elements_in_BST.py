# Python3 program to find Sum Of All
# Elements smaller than or equal to
# Kth Smallest Element In BST

INT_MAX = 2147483647

# Binary Tree Node
""" utility that allocates a newNode
with the given key """


class createNode:

    # Construct to create a newNode
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None


# A utility function to insert a new
# Node with given key in BST and also
# maintain lcount ,Sum
def insert(root, key):
    # If the tree is empty, return a new Node
    if (root == None):
        return createNode(key)

    # Otherwise, recur down the tree
    if (root.data > key):
        root.left = insert(root.left, key)

    elif (root.data < key):
        root.right = insert(root.right, key)

    # return the (unchanged) Node pointer
    return root


# function return sum of all element smaller
# than and equal to Kth smallest element
def ksmallestElementSumRec(root, k, count):
    # Base cases
    if (root == None):
        return 0
    if (count[0] > k[0]):
        return 0

    # Compute sum of elements in left subtree
    res = ksmallestElementSumRec(root.left, k, count)
    if (count[0] >= k[0]):
        return res

    # Add root's data
    res += root.data

    # Add current Node
    count[0] += 1
    if (count[0] >= k[0]):
        return res

    # If count is less than k, return
    # right subtree Nodes
    return res + ksmallestElementSumRec(root.right,
                                        k, count)


# Wrapper over ksmallestElementSumRec()
def ksmallestElementSum(root, k):
    count = [0]
    return ksmallestElementSumRec(root, k, count)


# Driver Code
if __name__ == '__main__':
    """ 20
        / \
    8 22
    / \
    4 12
        / \
        10 14
        """
    root = None
    root = insert(root, 20)
    root = insert(root, 8)
    root = insert(root, 4)
    root = insert(root, 12)
    root = insert(root, 10)
    root = insert(root, 14)
    root = insert(root, 22)

    k = [3]
    print(ksmallestElementSum(root, k))


