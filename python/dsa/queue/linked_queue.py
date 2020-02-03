"""A Queue using a Linked List like structure
"""

from .node import Node


class QueueIterator:
    def __init__(self, queue):
        self._queue = queue
        self._pointer = queue.first

    def __next__(self):
        if self._pointer is None:
            raise StopIteration()

        node = self._pointer
        self._pointer = node.next

        return node.item


class Queue:
    """Linked List Queue

    Examples
    --------
    >>> queue = Queue()
    >>> nums = [1, 2, 3]
    >>> for n in nums:
    ...     queue.enqueue(n)
    ...
    >>> queue.is_empty()
    False
    >>> len(queue)
    3
    >>> for elem in queue:
    ...     print(elem)
    ...
    1
    2
    3
    >>> queue.dequeue()
    1
    >>> queue.dequeue()
    2
    >>> queue.dequeue()
    3
    >>> queue.is_empty()
    True
    """
    def __init__(self):
        # number of items on the queue
        self._num_items = 0
        # link to least recently added node
        self._first = None
        # link to most recently added node
        self._last = None

    def enqueue(self, item):
        old_last = self._last

        last = Node()
        last.item = item
        self._last = last

        if self.is_empty():
            self._first = self._last
        else:
            old_last.next = self._last

        self._num_items = self._num_items + 1

    def dequeue(self):
        item = self._first.item
        self._first = self._first.next
        if self.is_empty():
            self._last = None
        self._num_items = self._num_items - 1

        return item

    def is_empty(self):
        return self._first is None

    def __len__(self):
        return self._num_items

    def __iter__(self):
        return QueueIterator(self)

    @property
    def first(self):
        return self._first
