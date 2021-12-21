T = int(input())

for t in range(T):
    [N, V] = input().split(" ")
    [N, V] = [int(N), int(V)]

    max_v = N *(N - 1)/2
    min_v = (V + (N - V)*(N - V + 1)/2 - 1)

    print(int(max), int(min), sep=" ", end="\n")