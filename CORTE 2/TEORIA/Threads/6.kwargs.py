import threading
import time

def mostrar_info(nombre, edad):
    print(f"Me llamo {nombre} y tengo {edad} años")
    time.sleep(1)

# Usando kwargs para enviar argumentos por nombre
hilo = threading.Thread(
    target=mostrar_info, 
    kwargs={"nombre": "Carlos", "edad": 28}
)
hilo.start()
hilo.join()
