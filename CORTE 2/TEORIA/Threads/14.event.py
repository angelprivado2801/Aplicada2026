import threading
import time

detener = threading.Event()

def tarea_periodica():
    while not detener.is_set():
        print("Tarea trabajando...")
        time.sleep(1)
    print("La tarea recibio la orden de detenerse")

hilo = threading.Thread(target=tarea_periodica)
hilo.start()

time.sleep(5)
print("Solicitando detener el thread")
detener.set()

hilo.join()
print("Programa terminado correctamente")
