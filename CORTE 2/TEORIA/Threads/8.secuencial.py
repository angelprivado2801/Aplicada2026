import time

def tarea(nombre):
    print(f"Iniciando {nombre}")
    time.sleep(2)
    print(f"Terminando {nombre}")

inicio = time.perf_counter()

tarea("Tarea 1")
tarea("Tarea 2")
tarea("Tarea 3")

fin = time.perf_counter()
print(f"Tiempo total: {fin - inicio:.2f} segundos")
