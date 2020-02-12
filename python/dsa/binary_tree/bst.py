"""A simple binary search tree implementation.
"""


class Node:
    def __init__(self, key, val, num_nodes=0):
        self._key = key
        self._val = val
        self._left = None
        self._right = None
        # number of nodes in subtree rooted here
        self._num_nodes = num_nodes

    @property
    def key(self):
        return self._key

    @property
    def val(self):
        return self._val

    @property
    def left(self):
        return self._left

    @left.setter
    def left(self, val):
        self._left = val

    @property
    def right(self):
        return self._right

    @right.setter
    def right(self, val):
        self._right = val

    @property
    def num_nodes(self):
        return self._num_nodes

    @num_nodes.setter
    def num_nodes(self, val):
        self._num_nodes = val


class BinarySearchTree:
    def __init__(self):
        self._root = None

    def _size(self, x):
        if x is None:
            return 0
        else:
            return x.num_nodes

    def size(self):
        return self._size(self._root)

    def _find_subtree(self, x: Node, key):
        if x is None:
            return None

        if key < x.key:
            return self._find_subtree(x.left, key)
        elif key > x.key:
            return self._find_subtree(x.right, key)
        else:
            return x.val

    def find(self, key):
        return self._find_subtree(self._root, key)

    def _insert_subtree(self, x: Node, key, val):
        """Insert `val` in subtree rooted at `x`.

        Change `key`'s value to `val` if `key` in subtree rooted at `x`.
        Otherwise, add new node to subtree associating `key` with `val`.

        Parameters
        ----------
        x : Node
            The root of subtree.
        key : object
            Key of node.
        val : object
            Value of node.

        Returns
        -------
        Node
            The root of subtree.
        """
        if x is None:
            return Node(key, val, 1)

        if key < x.key:
            x.left = self._insert_subtree(x.left, key, val)
        elif key > x.key:
            x.right = self._insert_subtree(x.right, key, val)
        else:
            x.val = val

        x.num_nodes = self._size(x.left) + self._size(x.right) + 1

        return x

    def insert(self, key, val):
        self._root = self._insert_subtree(self._root, key, val)

    def _print_preorder(self, x: Node):
        if x is not None:
            print(f"{x.key}({x.val}, {x.num_nodes}) ", end="")
            self._print_preorder(x.left)
            self._print_preorder(x.right)

    def print_preorder(self):
        self._print_preorder(self._root)
        print()

    @property
    def root(self):
        return self._root

    def __len__(self):
        return self.size()


class BinarySearchTreeViz:
    def __init__(self):
        self._null_count = 0

    def _write_dot_null(self, data, stream, invisible):
        if invisible:
            stream.write(f"    null{self._null_count} "
                         f"[style=\"invis\", shape=point];\n")
            stream.write(f"    {data} -> null{self._null_count} "
                         f"[style=\"invis\"];\n")
        else:
            stream.write(f"    null{self._null_count} [shape=point];\n")
            stream.write(f"    {data} -> null{self._null_count};\n")

        self._null_count = self._null_count + 1

    def _write_dot_aux(self, node: Node, stream, invisible):
        if node.left is not None:
            stream.write(f"    {node.key} -> {node.left.key};\n")
            self._write_dot_aux(node.left, stream, invisible)
        else:
            self._write_dot_null(node.key, stream, invisible)

        if node.right is not None:
            stream.write(f"    {node.key} -> {node.right.key};\n")
            self._write_dot_aux(node.right, stream, invisible)
        else:
            self._write_dot_null(node.key, stream, invisible)

    def write_dot(self, bst: BinarySearchTree, file_path: str, invisible=True):
        # reset count of null node
        self._null_count = 0

        root = bst.root
        with open(file_path, "w") as stream:
            stream.write("digraph BST {\n")
            stream.write("    node [frontname=\"Arial\"];\n")

            if root is None:
                stream.write("\n")
            elif root.left is None and root.right is None:
                stream.write(f"    {root.key};\n")
            else:
                self._write_dot_aux(root, stream, invisible)
            stream.write("}\n")


if __name__ == "__main__":
    tree = BinarySearchTree()
    tree.insert(3, "S")
    tree.insert(1, "E")
    tree.insert(5, "A")
    tree.insert(0, "R")
    tree.insert(2, "C")
    tree.insert(4, "H")

    val = tree.find(5)
    print(f"Found node with key = 5: {str(val)}")

    print(f"Number of nodes: {str(len(tree))}")
    print("Pre-order traversal: ")
    tree.print_preorder()
