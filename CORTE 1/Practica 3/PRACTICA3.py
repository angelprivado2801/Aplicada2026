while True:
    a = input("Por favor ingrese un valor")
    aInt = int(a)
    mod = aInt%2

    if(mod == 0):
        print("a es un PAR")
    else:
        print("a NO es PAR, es IMPAR")
    salir = input("¿Desea Finalizar? Si=s, No=n").lower()
    if salir == "s":
        break
