def canSum (target, numbers):
    if (target == 0):
        return True
    if (target < 0):
        return False
    
    for number in numbers:
        result = canSum(target - number, numbers)
        if (result):
            return True
    return False

print(canSum(7, [2, 4]))
print(canSum(7, [2, 3, 4, 7]))
print(canSum(100, [2, 3]))
