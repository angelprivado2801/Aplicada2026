import threading
import time

detener = threading.Event()

def trabajo_fondo():
    while not detener.is_set():
        print("[Sistema] Trabajando en segundo plano...")
        detener.wait(3)

hilo = threading.Thread(target=trabajo_fondo)
hilo.start()

while True:
    comando = input("Escribe 'salir' para detener: ")
    if comando.lower() == 'salir':
        detener.set()
        break

hilo.join()
print("Programa finalizado.")
