import threading

contador = 0

def incrementar():
    global contador
    for _ in range(100000):
        contador += 1

hilo_1 = threading.Thread(target=incrementar)
hilo_2 = threading.Thread(target=incrementar)

hilo_1.start()
hilo_2.start()

hilo_1.join()
hilo_2.join()

# Este resultado puede ser menor a 200000 debido a una condición de carrera (race condition)
print("Contador final:", contador)
