import threading
import time

def saludar():
    for i in range(5):
        print("Hola desde el thread secundario")
        time.sleep(1)
hilo = threading.Thread(target=saludar)
hilo.start()
print("Hola desde el programa principal")
