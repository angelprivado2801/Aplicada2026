import threading
import time

def tarea(nombre):
    print(f"Iniciando {nombre}")
    time.sleep(2)
    print(f"Terminando {nombre}")

inicio = time.perf_counter()

hilo_1 = threading.Thread(target=tarea, args=("Tarea 1",))
hilo_2 = threading.Thread(target=tarea, args=("Tarea 2",))
hilo_3 = threading.Thread(target=tarea, args=("Tarea 3",))

hilo_1.start()
hilo_2.start()
hilo_3.start()

hilo_1.join()
hilo_2.join()
hilo_3.join()

fin = time.perf_counter()
print(f"Tiempo total con threads: {fin - inicio:.2f} segundos")
