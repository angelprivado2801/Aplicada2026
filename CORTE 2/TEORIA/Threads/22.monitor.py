import threading
import time
import random
import queue

cola_temperaturas = queue.Queue()
detener = threading.Event()

def sensor_temperatura():
    while not detener.is_set():
        temp = random.uniform(20.0, 35.0)
        cola_temperaturas.put(temp)
        time.sleep(1)

def procesador_temperatura():
    lecturas = []
    while not detener.is_set() or not cola_temperaturas.empty():
        try:
            temperatura = cola_temperaturas.get(timeout=0.2)
            lecturas.append(temperatura)
            
            if len(lecturas) > 5:
                lecturas.pop(0)
                
            promedio = sum(lecturas) / len(lecturas)
            print(f"Temperatura: {temperatura:.2f} C | Promedio movil: {promedio:.2f} C")
            
            if temperatura > 30.0:
                print("¡ADVERTENCIA: Temperatura superior a 30 grados!")
                
            cola_temperaturas.task_done()
        except queue.Empty:
            pass

hilo_sensor = threading.Thread(target=sensor_temperatura)
hilo_procesador = threading.Thread(target=procesador_temperatura)

hilo_sensor.start()
hilo_procesador.start()

print("Monitor iniciado")
print("Escribe 'salir' para terminar")

while True:
    comando = input(">")
    if comando.lower() == "salir":
        detener.set()
        break
    print("Comando no reconocido")

hilo_sensor.join()
hilo_procesador.join()
print("Monitor terminado")
