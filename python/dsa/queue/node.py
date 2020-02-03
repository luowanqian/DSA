class Node:
    def __init__(self):
        self._item = None
        self._next = None

    @property
    def item(self):
        return self._item

    @item.setter
    def item(self, value):
        self._item = value

    @property
    def next(self):
        return self._next

    @next.setter
    def next(self, value):
        self._next = value
