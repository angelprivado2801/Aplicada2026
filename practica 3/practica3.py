while True:
    a = input("Por favor ingrese un valor: ")
    aInt = int(a)
    mod = aInt%2

    if(mod==0):
        print("a es par")
    else:
        print("a es impar")

    salir = input("Persiona 's' para salir del programa ó cualquier tecla para continuar: ")
    if salir.lower() == 's':
        print("Saliendo...")
        break
