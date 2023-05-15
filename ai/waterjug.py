# Water Jug Problem
x = 0
y = 0
while True:
  rule_number = int(input("Enter the rule number: "))
  if rule_number == 2:
    if y < 3:
      x = 0
      y = 3
  elif rule_number == 3:
    if x > 0:
      x = 0
      y = 3
  elif rule_number == 5:
    if x + y > 4:
      x = 4
      y = y - (4 - x)
  elif rule_number == 7:
    if x + y < 4:
      x = x + y
      y = 0
  elif rule_number == 9:
    x = 2
    y = 0

  print("X = {} Y = {}".format(x, y))
  if x == 2:
    print("The goal state has been reached!")
    break
