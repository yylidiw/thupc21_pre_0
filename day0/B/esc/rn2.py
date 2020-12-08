from os import system
for i in range(1,31):
    fn = "checkout"+str(i)+".ans"
    system("getchar.exe < ../data/"+fn+" > ../data/tmp/"+fn)
