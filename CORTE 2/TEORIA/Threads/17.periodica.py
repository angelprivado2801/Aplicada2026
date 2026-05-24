import threading
import time

detener = threading.Event()

def tarea_periodica():
    while not detener.is_set():
        print("Ejecutando tarea periódica...")
        # Espera de 2 segundos, pero interrumpible si detener se activa
        detener.wait(2)

hilo = threading.Thread(target=tarea_periodica)
hilo.start()

time.sleep(7)
detener.set()
hilo.join()
print("Tarea periódica detenida.")
