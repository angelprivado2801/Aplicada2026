import threading
import time

def tarea(nombre, duracion):
    print(f"Inicia {nombre}")
    time.sleep(duracion)
    print(f"Termina {nombre}")

hilo_1 = threading.Thread(target=tarea, args=("Tarea 1", 3))
hilo_2 = threading.Thread(target=tarea, args=("Tarea 2", 2))

hilo_1.start()
hilo_2.start()

hilo_1.join()
hilo_2.join()
print("Todas las tareas terminaron")
