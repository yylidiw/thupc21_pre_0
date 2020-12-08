from os import system
for i in range(1,31):
    fn = "checkout"+str(i)
    system("cake.exe < ../data/"+fn+".in > ../data/"+fn+".ans")
