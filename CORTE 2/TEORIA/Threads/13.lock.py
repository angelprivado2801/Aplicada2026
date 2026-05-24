import threading

contador = 0
candado = threading.Lock()

def incrementar():
    global contador
    for _ in range(100000):
        with candado: # Protegemos la sección crítica
            contador += 1

hilo_1 = threading.Thread(target=incrementar)
hilo_2 = threading.Thread(target=incrementar)

hilo_1.start()
hilo_2.start()

hilo_1.join()
hilo_2.join()

print("Contador final protegido:", contador) # Siempre será 200000
