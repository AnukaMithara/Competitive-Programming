def add_in_base(a, b, base):
    max_len = max(len(a), len(b))
    a = a.zfill(max_len)
    b = b.zfill(max_len)

    result = ''
    carry = 0
    for i in range(max_len-1, -1, -1):
        total = int(a[i], base) + int(b[i], base) + carry
        carry, remainder = divmod(total, base)
        result = str(remainder) + result

    if carry != 0:
        result = str(carry) + result

    return result


def multiply_in_base(a, b, base):
    result = '0'
    for i in range(len(b)-1, -1, -1):
        carry = 0
        partial_result = ''
        for j in range(len(a)-1, -1, -1):
            total = int(a[j], base) * int(b[i], base) + carry
            carry, remainder = divmod(total, base)
            partial_result = str(remainder) + partial_result

        if carry != 0:
            partial_result = str(carry) + partial_result

        partial_result += '0' * (len(b) - 1 - i)
        result = add_in_base(result, partial_result, base)

    return result


def subtract_in_base(a, b, base):
    max_len = max(len(a), len(b))
    a = a.zfill(max_len)
    b = b.zfill(max_len)

    result = ''
    borrow = 0
    for i in range(max_len-1, -1, -1):
        total = int(a[i], base) - int(b[i], base) - borrow
        if total < 0:
            total += base
            borrow = 1
        else:
            borrow = 0
        result = str(total) + result

    return result.lstrip('0') or '0'


def divide_in_base(a, b, base):
    a = int(a, base)
    b = int(b, base)
    result = a // b
    return format(result, 'x')


def evaluate_stack(stack, base):
    result = stack.pop(0)
    while stack:
        operator = stack.pop(0)
        operand = stack.pop(0)
        if operator == '+':
            result = add_in_base(result, operand, base)
        elif operator == '*':
            result = multiply_in_base(result, operand, base)
        elif operator == '-':
            result = subtract_in_base(result, operand, base)
        elif operator == '/':
            result = divide_in_base(result, operand, base)
    return result


def evaluate_stack(stack, base):
    while len(stack) > 1:
        for i in range(len(stack)):
            if stack[i] in ['+', '-', '*', '/']:
                operator = stack[i]
                operand1 = stack[i - 2]
                operand2 = stack[i - 1]
                if operator == '+':
                    result = int(operand1, base) + int(operand2, base)
                elif operator == '-':
                    result = int(operand1, base) - int(operand2, base)
                elif operator == '*':
                    result = int(operand1, base) * int(operand2, base)
                elif operator == '/':
                    result = int(int(operand1, base) / int(operand2, base))
                stack = stack[:i - 2] + [str(result)] + stack[i + 1:]
                break
    return stack[0]


def combined_function(expression):
    base, expr = expression.split(',')
    base = int(base)
    expr = expr.replace('-', 'p').replace('+', '-').replace('p', '+').replace('*', 'p').replace(
        '/', '*').replace('p', '/').replace('(', 'p').replace(')', '(').replace('p', ')')

    # Split the expression into components
    components = []

    current_component = ""
    for char in expr:
        if char.isdigit():
            current_component += char
        else:
            if current_component:
                components.append(current_component)
                current_component = ""
            components.append(char)

    if current_component:
        components.append(current_component)

    # Perform the calculations in the given base
    stack = []
    for component in components:
        if component == '(':
            stack.append('(')
        elif component == ')':
            temp_stack = []
            while stack[-1] != '(':
                temp_stack.insert(0, stack.pop())
            stack.pop()  # remove the '('
            stack.append(evaluate_stack(temp_stack, base))
        else:
            stack.append(component)

    result = evaluate_stack(stack, base)
    return int(result, base)


expression = input()
print(combined_function(expression))
