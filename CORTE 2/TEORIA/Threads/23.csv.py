import threading
import time
import random
import queue
import csv

cola_datos = queue.Queue()
detener = threading.Event()

def adquirir_datos():
    while not detener.is_set():
        dato = random.randint(100, 500)
        cola_datos.put(dato)
        time.sleep(0.5)

def guardar_csv():
    with open("resultados.csv", "w", newline="", encoding="utf-8") as archivo:
        escritor = csv.writer(archivo)
        escritor.writerow(["Marca de tiempo", "Valor"])
        
        while not detener.is_set() or not cola_datos.empty():
            try:
                valor = cola_datos.get(timeout=0.2)
                tiempo_actual = time.strftime("%H:%M:%S")
                escritor.writerow([tiempo_actual, valor])
                print(f"CSV guardado -> [{tiempo_actual}] {valor}")
                cola_datos.task_done()
            except queue.Empty:
                pass

hilo_adquisicion = threading.Thread(target=adquirir_datos)
hilo_csv = threading.Thread(target=guardar_csv)

hilo_adquisicion.start()
hilo_csv.start()

time.sleep(5) # Simula 5 segundos de recolección de datos
detener.set()

hilo_adquisicion.join()
hilo_csv.join()
print("Exportación a CSV terminada correctamente.")
