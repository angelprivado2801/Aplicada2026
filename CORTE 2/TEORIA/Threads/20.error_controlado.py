import threading
import time

def tarea_con_error_controlado():
    try:
        time.sleep(2)
        resultado = 10 / 0
        print(resultado)
    except ZeroDivisionError:
        print("Error dentro del thread: division por cero")

hilo = threading.Thread(target=tarea_con_error_controlado)
hilo.start()

for i in range(5):
    print(f"Programa principal: {i}")
    time.sleep(1)

hilo.join()
print("Fin")
