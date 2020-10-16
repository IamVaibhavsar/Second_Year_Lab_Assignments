#Name:Abhishek Tilwar
#Roll No:2101001
#Class: SE-A(Computer)
#Prn:72031575B
#DSL  Assignment-6


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


'''
Output:-

Enter number of students: 7
Enter the percentage of students:-
Enter the student percentage: 32.46
Enter the student percentage: 12.35
Enter the student percentage: 67.36
Enter the student percentage: 95.44
Enter the student percentage: 36.44
Enter the student percentage: 87.63
Enter the student percentage: 55.32

 The sorted percentage list is:
12.35
32.46
36.44
55.32
67.36
87.63
95.44

The top five students percentage are:-
[95.44, 87.63, 67.36, 55.32, 36.44]
'''
