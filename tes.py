def taskOfPairing(freq):

    count = 0

    marker = False

    for i in freq:

      if i != 0:

        count += i // 2

        if i % 2 != 0 and marker:

          count += 1

          marker = False

        elif i % 2 != 0:

          marker = True
      else:

        marker = False

    print(count)


lst = []
n = int(input("Enter number of elements : "))

for i in range(0, n):
	ele = int(input())

	lst.append(ele)

taskOfPairing(lst)