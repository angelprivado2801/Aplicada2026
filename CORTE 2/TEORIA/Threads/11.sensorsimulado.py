import threading
import time
import random

def leer_sensor():
    for _ in range(5):
        lectura = random.uniform(20.0, 25.0)
        print(f"Lectura del sensor: {lectura:.2f}")
        time.sleep(1)

hilo_sensor = threading.Thread(target=leer_sensor)
hilo_sensor.start()
hilo_sensor.join()
print("Lectura de sensor finalizada")
