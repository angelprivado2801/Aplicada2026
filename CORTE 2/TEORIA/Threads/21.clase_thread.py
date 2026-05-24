import threading
import time

class Contador(threading.Thread):
    def __init__(self, nombre, limite):
        super().__init__()
        self.nombre = nombre
        self.limite = limite

    def run(self):
        for i in range(self.limite):
            print(f"{self.nombre} - Conteo: {i}")
            time.sleep(1)

hilo_obj = Contador("HiloClase", 5)
hilo_obj.start()
hilo_obj.join()
