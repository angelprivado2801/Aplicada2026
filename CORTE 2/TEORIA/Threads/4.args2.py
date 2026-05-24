import threading
import time

def contar(nombre, inicio, fin, pausa):
    for numero in range(inicio, fin):
        print(f"{nombre}: {numero}")
        time.sleep(pausa)

hilo_1 = threading.Thread(target=contar, args=("Contador rapido", 1, 5, 0.5))
hilo_2 = threading.Thread(target=contar, args=("Contador lento", 10, 15, 1.0))

hilo_1.start()
hilo_2.start()
hilo_1.join()
hilo_2.join()
print("Conteos terminados")
