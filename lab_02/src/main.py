import time

def compute(x):
    return x*x - x*x + 4*x - 5*x + x + x

def main():
    while True:
        user_input = input("Enter number of iterations (integer): ")
        n = int(user_input)

        start = time.perf_counter()
        result = 0
        for i in range(n):
            result = compute(i)   
        end = time.perf_counter()

        elapsed_us = (end - start) * 1_000_000
        print(f"Result: {result}")
        print(f"N= {n}, Time: {elapsed_us:.0f} mcs")

        choice = input("Run again? (y/n): ").lower()
        if choice != 'y':
            break

if __name__ == "__main__":
    main()
