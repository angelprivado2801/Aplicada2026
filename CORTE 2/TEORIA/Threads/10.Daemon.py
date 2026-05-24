import threading
import time

def monitorear():
    while True:
        print("Monitoreando...")
        time.sleep(1)

hilo = threading.Thread(target=monitorear, daemon=True)
hilo.start()

for i in range(5):
    print(f"Programa principal: {i}")
    time.sleep(1)
    
print("Fin del programa principal")
