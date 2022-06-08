def binarySearch(liste, search):
    first = 0
    last = len(liste)
    while first <= last:
        mid = (first + last)//2
        if liste[mid] == search:
            return mid
        elif liste[mid] > search:
            last = mid - 1
        else:
            first = mid + 1
    return -1

def binarySearchRecursive(liste, first, last, search):
    mid = (first + last)//2
    if first > last:
        return -1
    if liste[mid] == search:
        return mid
    elif liste[mid] > search:
        return binarySearchRecursive(liste, first, mid - 1, search)
    else:
        return binarySearchRecursive(liste, mid + 1, last, search)

def main():
    customer_IDs = [2,5,7,9,12,34,56,89]
    search = int(input("Enter the number you want to search: "))
    #index = binarySearch(customer_IDs, search)
    index = binarySearchRecursive(customer_IDs, 0, len(customer_IDs), search)
    if index != -1:
        print(f"{search} found at the index {index}.")
    else:
        print(f"{search} is not in the list.")

main()