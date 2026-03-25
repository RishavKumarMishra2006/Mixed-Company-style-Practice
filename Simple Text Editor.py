def simpleTextEditor(operations):
    stack = []
    s = ""

    result = []

    for op in operations:
        if op[0] == '1':
            stack.append(s)
            s += op[1]

        elif op[0] == '2':
            stack.append(s)
            s = s[:-int(op[1])]

        elif op[0] == '3':
            result.append(s[int(op[1]) - 1])

        elif op[0] == '4':
            s = stack.pop()

    return result
