import matplotlib.pyplot as plt
import numpy as np

iteraction = []
sucessLevel = []

ref_arquivo = open("result20-teste.txt","r")

for linha in ref_arquivo:
    valores = linha.split()
    valores = np.array(valores)
    print(valores)
    

    iteraction.append(valores[0])
    sucessLevel.append(valores[1])

plt.axis([0, 25, 0, 20])
plt.plot(iteraction, sucessLevel, 'o')
plt.show()
