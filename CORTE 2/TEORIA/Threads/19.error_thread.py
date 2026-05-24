import threading
import time

def tarea_con_error():
    time.sleep(2)
    resultado = 10 / 0  # Esto causará una excepción ZeroDivisionError
    print(resultado)

hilo = threading.Thread(target=tarea_con_error)
hilo.start()

for i in range(5):
    print(f"Programa principal: {i}")
    time.sleep(1)

hilo.join()
print("Fin")
