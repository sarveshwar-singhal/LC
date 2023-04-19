from  typing import List
# [ 1, 2, 3, 2, 4, 1]

def get_duplicate(number: List[int]) -> List[int]:
    uniq = set()
    ans = set()
    for num in number:
        if num in uniq:
            ans.add(num)
        else:
            uniq.add(num)
    return list(ans)

class gamma:
    dangerous = 3

def main():
    number = [ 1, 2, 3, 2, 4, 1]
    c = gamma()
    d = gamma()
    print(c.dangerous)
    c.dangerous = 2
    print(d.dangerous)
    # ans = get_duplicate(number)
    # print(ans)


if __name__ == "__main__":
    main()
