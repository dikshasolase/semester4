def set1_input():
    x = int(input("Enter the total number of elements in Set1: "))
    set1 = []
    print("Enter the elements:")
    for i in range(x):
        element = int(input())
        set1.append(element)
    return set1

def set2_input():
    x = int(input("Enter the total number of elements in Set2: "))
    set2 = []
    print("Enter the elements:")
    for i in range(x):
        element = int(input())
        set2.append(element)
    return set2

def contains(set_elements, element):
    return element in set_elements

def size(set_elements):
    return len(set_elements)


def iterator(set_elements):
    return iter(set_elements)

def intersection(set1, set2):
    return list(set(set1) & set(set2))

# Union of two sets
def union(set1, set2):
    return list(set(set1) | set(set2))

# Difference of two sets
def difference(set1, set2):
    return list(set(set1) - set(set2))

# Generate all subsets of the set
def subsets(set_elements):
    result = []
    n = len(set_elements)
    for i in range(1 << n):
        subset = []
        for j in range(n):
            if i & (1 << j):
                subset.append(set_elements[j])
        result.append(subset)
    return result

# Main program to take user input
def main():
    set1 = set1_input()  # Initial input for set1
    set2 = set2_input()  # Initial input for set2

    while True:
        print("\nChoose an operation:")
        print("1. Add element to Set1")
        print("2. Add element to Set2")
        print("3. Remove element from Set1")
        print("4. Remove element from Set2")
        print("5. Check if element is in Set1")
        print("6. Check if element is in Set2")
        print("7. Size of Set1")
        print("8. Size of Set2")
        print("9. Union of Set1 and Set2")
        print("10. Intersection of Set1 and Set2")
        print("11. Difference (Set1 - Set2)")
        print("12. Show Subsets of Set1")
        print("13. Exit")

        choice = input("Enter your choice (1-13): ")

        if choice == "1":
            element = int(input("Enter element to add to Set1: "))
            set1.append(element)
            print(f"Set1: {set1}")
            
        elif choice == "2":
            element = int(input("Enter element to add to Set2: "))
            set2.append(element)
            print(f"Set2: {set2}")
        
        elif choice == "3":
            element = int(input("Enter element to remove from Set1: "))
            if element in set1:
                set1.remove(element)
            else:
                print(f"Element {element} not found in Set1")
            print(f"Set1: {set1}")
        
        elif choice == "4":
            element = int(input("Enter element to remove from Set2: "))
            if element in set2:
                set2.remove(element)
            else:
                print(f"Element {element} not found in Set2")
            print(f"Set2: {set2}")
        
        elif choice == "5":
            element = int(input("Enter element to check in Set1: "))
            print(f"Set1 contains {element}: {contains(set1, element)}")
        
        elif choice == "6":
            element = int(input("Enter element to check in Set2: "))
            print(f"Set2 contains {element}: {contains(set2, element)}")
        
        elif choice == "7":
            print(f"Size of Set1: {size(set1)}")
        
        elif choice == "8":
            print(f"Size of Set2: {size(set2)}")
        
        elif choice == "9":
            union_set = union(set1, set2)
            print(f"Union of Set1 and Set2: {union_set}")
        
        elif choice == "10":
            intersection_set = intersection(set1, set2)
            print(f"Intersection of Set1 and Set2: {intersection_set}")
        
        elif choice == "11":
            difference_set = difference(set1, set2)
            print(f"Difference (Set1 - Set2): {difference_set}")
        
        elif choice == "12":
            subsets_set1 = subsets(set1)
            print(f"Subsets of Set1: {subsets_set1}")
        
        elif choice == "13":
            print("Exiting...")
            break
        
        else:
            print("Invalid choice, please try again.")

main()
