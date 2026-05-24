import threading
import time
import queue

cola_cruda = queue.Queue()
cola_procesada = queue.Queue()
detener = threading.Event()

def leer_sensor():
    while not detener.is_set():
        valor = 10  # Valor simulado
        cola_cruda.put(valor)
        time.sleep(1)

def procesar_datos():
    while not detener.is_set() or not cola_cruda.empty():
        try:
            valor = cola_cruda.get(timeout=0.2)
            valor_procesado = valor * 2
            cola_procesada.put(valor_procesado)
            cola_cruda.task_done()
        except queue.Empty:
            pass

def guardar_datos():
    with open("datos_procesados.txt", "w", encoding="utf-8") as archivo:
        while not detener.is_set() or not cola_procesada.empty():
            try:
                valor = cola_procesada.get(timeout=0.2)
                archivo.write(f"{valor:.2f}\n")
                print(f"Guardado: {valor:.2f}")
                cola_procesada.task_done()
            except queue.Empty:
                pass

hilo_sensor = threading.Thread(target=leer_sensor)
hilo_procesamiento = threading.Thread(target=procesar_datos)
hilo_guardado = threading.Thread(target=guardar_datos)

hilo_sensor.start()
hilo_procesamiento.start()
hilo_guardado.start()

time.sleep(8)
detener.set()

hilo_sensor.join()
hilo_procesamiento.join()
hilo_guardado.join()

print("Programa terminado")
