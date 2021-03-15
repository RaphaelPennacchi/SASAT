import matplotlib.pyplot as plt

Temperature = []
Clausules = []

ref_arquivo = open("result20-1.txt","r")
valores = []

for linha in ref_arquivo:
    valores = array(linha.split())
    print(valores)

    Temperature.append(valores)
    Clausules.append(valores)

plt.plot(Temperature, Clausules)
plt.show()
