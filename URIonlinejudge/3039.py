entrada = int(input())
boneca = 0
carro = 0
if(entrada<=1000 and entrada > -1):
  for i in range(0,entrada):
    name = input().split()
    if(name[1] == 'F'):boneca+=1
    elif(name[1] == 'M'):carro+=1

  print("%d carrinhos" % carro)
  print("%d bonecas" % boneca)
