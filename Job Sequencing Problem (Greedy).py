def jobSequencing(jobs):
    jobs.sort(key=lambda x: x[2], reverse=True)

    max_deadline = max(job[1] for job in jobs)
    slots = [-1] * max_deadline

    total_profit = 0

    for job in jobs:
        for j in range(job[1] - 1, -1, -1):
            if slots[j] == -1:
                slots[j] = job[0]
                total_profit += job[2]
                break

    return total_profit
