import threading
import time
import random
import queue

cola_datos = queue.Queue()

def productor():
    for _ in range(10):
        dato = random.randint(1, 100)
        cola_datos.put(dato)
        print(f"Productor genero: {dato}")
        time.sleep(0.5)

def consumidor():
    for _ in range(10):
        dato = cola_datos.get()
        print(f"Consumidor recibio: {dato}")
        cola_datos.task_done()

hilo_productor = threading.Thread(target=productor)
hilo_consumidor = threading.Thread(target=consumidor)

hilo_productor.start()
hilo_consumidor.start()

hilo_productor.join()
hilo_consumidor.join()
