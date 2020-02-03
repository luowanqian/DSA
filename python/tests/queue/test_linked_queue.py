from dsa.queue.linked_queue import Queue
import numpy as np


def test_queue():
    queue = Queue()

    nums = [1, 2, 3, 4, 5]

    for n in nums:
        queue.enqueue(n)

    assert len(queue) == len(nums)
    assert not queue.is_empty()

    traces = []
    for n in queue:
        traces.append(n)
    np.testing.assert_equal(np.array(traces), np.array(nums))

    deques = []
    while not queue.is_empty():
        deques.append(queue.dequeue())
    assert len(queue) == 0
    assert queue.is_empty()
    np.testing.assert_equal(np.array(deques), np.array(nums))
