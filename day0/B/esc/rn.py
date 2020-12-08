from os import system
for i in range(1,31):
    fn = "../data/checkout"+str(i)
    system("move "+fn+".out "+fn+".ans")
