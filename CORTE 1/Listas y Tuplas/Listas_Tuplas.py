# Definición de una lista: estructura mutable (modificable) de elementos ordenados
my_lista = ['Rojo', 'Azul', 'Amarillo', 'Naranja', 'Violeta', 'Verde']

print(my_lista)
print(type(my_lista))  # Muestra la clase del objeto (<class 'list'>)

# Acceso por índice: los índices en Python comienzan en 0
print(my_lista[2])     # Imprime 'Amarillo'

# len() devuelve la cantidad de elementos en la lista
print("my_lista size: ", len(my_lista))

# Slicing (Rebanado): [inicio:fin_exclusivo]
print(my_lista[0:2])   # Elementos en índice 0 y 1
print(my_lista[:2])    # Atajo para empezar desde el principio hasta el índice 1

# Modificación de la lista
my_lista.append('Blanco')      # Agrega un elemento único al final
print(my_lista)

my_lista.insert(3, 'Negro')    # Inserta 'Negro' en el índice 3, desplazando el resto
print(my_lista)

# extend() une una lista a otra (en lugar de meter una lista dentro de otra)
my_lista.extend(['Marron', 'Gris']) 
print(my_lista)

# index() busca la posición de un elemento (lanza error si no existe)
print(my_lista.index('Azul'))

# Eliminación de elementos
# my_lista.remove('Magenta')   # Esto daría error porque 'Magenta' no está en la lista
my_lista.remove('Marron')      # Busca y elimina la primera coincidencia de 'Marron'
print(my_lista)

my_lista.insert(8, 'Marron')   # Re-inserta 'Marron' en una posición específica
print(my_lista)

# pop() elimina y RETORNA el último elemento de la lista
print(my_lista.pop())

size = len(my_lista)
print("size = ", size)
# print(my_lista.pop(size))    # ERROR: Daría IndexError porque el último índice es size-1

# Operador de repetición: crea una nueva lista repitiendo la original 3 veces
my_lista_3 = my_lista*3
print("my_lista_3: ", my_lista_3)

print("Sort:")
print()
# OJO: .sort() ordena la lista original "in-place" y devuelve None
my_listaSort = my_lista.sort() 
print(my_listaSort)            # Imprimirá 'None' porque el método no retorna la lista

my_NumList = [10, 9, 8, 7, 6 , 5 , 4, 3, 2, 1]
print("Ordering my_NumList: ")
my_NumList.sort()              # Ordena de menor a mayor por defecto
print(my_NumList)

# Ordenando lista de mayor a menor usando el parámetro 'reverse'
my_NumList.sort(reverse = True)
print("De mayor a menor: ", my_NumList)


################# TUPLAS ####################
###########################################
# Son inmutables: una vez creadas no se pueden modificar, añadir o borrar elementos.

print("###########################")
print("############TUPLAS#########")

# Convertir una lista a tupla (Casting)
my_tupla = tuple(my_lista)
print()
print("my_tuple: ", my_tupla)

# Acceso similar a las listas por índice
print(my_tupla[0])
print(my_tupla[2])

# Operaciones de búsqueda y conteo
print('Rojo' in my_tupla)        # Devuelve True si el elemento existe en la tupla
print(my_tupla.count('Rojo'))    # Cuenta cuántas veces aparece 'Rojo'

# Tupla con un solo elemento (Nota: para que sea tupla real debe llevar coma: ('Blanco',))
my_tupla_unitaria = ('Blanco')
print(my_tupla_unitaria)

# Empaquetado de tupla: se pueden omitir los paréntesis
my_tupla = 'Gaspar', 5, 8, 1999
print(my_tupla)

# Desempaquetado de tupla: asigna cada elemento a una variable en orden
nombre, dia, mes, año = my_tupla
print(nombre)
print(dia)
print(mes)
print(año)

print("Nombre: ", nombre, " - Dia:", dia, " - Mes: ", mes, "- Año: ", año)

# Convertir una tupla de vuelta a una lista para que sea modificable de nuevo
my_lista2=list(my_tupla)
print(my_lista2)
