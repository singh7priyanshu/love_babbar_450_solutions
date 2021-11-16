def min_max_elements(arr):
    A = sorted(arr)
    minimum_element = A[0]
    maximum_element = A[-1]
    return(minimum_element, maximum_element)