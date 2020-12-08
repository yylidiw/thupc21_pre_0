from os import system
for i in range(1,16):
    fn = "sphere"+str(i)
    system("getchar.exe < "+fn+".out > tmp/"+fn+".ans")
