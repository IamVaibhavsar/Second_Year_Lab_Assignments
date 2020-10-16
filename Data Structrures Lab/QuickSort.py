'''Write C++ program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
a) Quick sort and display top five scores.'''

def partition(array, start, end):
    pivot = array[start]
    low = start + 1
    high = end

    while True:
        while low <= high and array[high] >= pivot:
            high = high - 1

        
        while low <= high and array[low] <= pivot:
            low = low + 1

        if low <= high:
            array[low], array[high] = array[high], array[low]
        
        else:
        
            break

    array[start], array[high] = array[high], array[start]

    return high

def quick_sort(array, start, end):
    if start >= end:
        return

    p = partition(array, start, end)
    quick_sort(array, start, p-1)
    quick_sort(array, p+1, end)
    
    
a=int( input("Enter number of students: "))
n = a
arr =[0 for i in range  (0 , n)]
print ("Enter the percentage of students:-" )
for i in range(0 , n):
        arr[i]=float (input("Enter the student percentage: "))

quick_sort(arr, 0, len(arr) - 1)
print("\n The sorted percentage list is: ")
for i in range(len(arr)):
            print("%0.2f" %arr[i])
print("\n The top five students percentage are:-")
z=list()
for i in range(len(arr)):
            z.append(arr[i])

z.sort(reverse=True)
print(z[0:5])
