import threading
import time

def saludar(nombre):
    for i in range(3):
        print(f"Hola, {nombre}. Mensaje {i}")
        time.sleep(1)

hilo = threading.Thread(target=saludar, args=("Salvatore",))
hilo.start()
hilo.join()
print("Fin del programa")
