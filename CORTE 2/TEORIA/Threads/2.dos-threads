import threading
import time

def contar(nombre):
    for i in range(5):
        print(f"{nombre}: {i}")
        time.sleep(1)

hilo_a = threading.Thread(target=contar, args=("Hilo A",))
hilo_b = threading.Thread(target=contar, args=("Hilo B",))

hilo_a.start()
hilo_b.start()
