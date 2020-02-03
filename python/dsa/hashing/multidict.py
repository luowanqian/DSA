"""Implementation of Multidictionaries
"""


def multidict(single_dict):
    """Splits a single dictionary into multiple dictionaries.

    Parameters
    ----------
    single_dict : dict
        A python dictionary. Each key should map to a list of values.

    Returns
    -------
    list
        A list, where the first member contains the shared key values,
        and the following members contain the dictionaries that result
        from splitting the value lists from the input dictionary.

    Examples
    --------
    >>> single_dict = {
    ...     "key1": [1, 2],
    ...     "key2": [1, 3],
    ...     "key3": [1, 4]}
    >>> keys, dict1, dict2 = multidict(single_dict)
    >>> keys
    ['key1', 'key2', 'key3']
    >>> dict1
    {'key1': 1, 'key2': 1, 'key3': 1}
    >>> dict2
    {'key1': 2, 'key2': 3, 'key3': 4}
    """
    keys = list(single_dict.keys())
    if len(keys) == 0:
        return [[]]

    try:
        value_size = len(single_dict[keys[0]])
        is_list = True
    except:
        value_size = 1
        is_list = False

    dlist = [dict() for d in range(value_size)]
    for k in keys:
        if is_list:
            for i in range(value_size):
                dlist[i][k] = single_dict[k][i]
        else:
            dlist[0][k] = single_dict[k]

    return [keys] + dlist


if __name__ == "__main__":
    single_dict = {
        "key1": [1, 2],
        "key2": [1, 3],
        "key3": [1, 4]
    }
    keys, dict1, dict2 = multidict(single_dict)

    print(f"Original dict: {single_dict}")
    print(f"Keys: {keys}")
    print(f"Dict1: {dict1}")
    print(f"Dict2: {dict2}")
