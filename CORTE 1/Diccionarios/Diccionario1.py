# Inicialización estándar: Mapeo de strings (claves) a enteros (valores).
# Los diccionarios usan pares clave:valor para búsquedas rápidas O(1).
sensors = {"living room": 21, "kitchen": 23, "bedroom": 20, "pantry": 22}
num_cameras = {"backyard": 6, "garage": 2, "driveway": 1}

print(sensors)
print(num_cameras)

# Mapeo String-String: Diccionario básico de equivalencias o traducciones.
translations = {"mountain": "orod", "bread": "bass", "friend": "mellon", "horse": "roch"}
print(translations)

# REGLA DE INMUTABILIDAD:
# Las claves deben ser objetos "hashables" (que no cambien, como strings, números o tuplas).
# Una lista [1, 2] es mutable, por lo tanto NO puede ser una clave. 
# La siguiente línea daría TypeError: unhashable type: 'list'
# powers = {[1, 2, 4, 8, 16]: 2, [1, 3, 9, 27, 81]: 3}

# Estructuras Anidadas: Los valores (a diferencia de las claves) pueden ser cualquier cosa.
# Aquí usamos una lista como valor para agrupar múltiples datos bajo un apellido.
children = {
    "von Trapp": ["Johannes", "Rosmarie", "Eleonore"], 
    "Corleone": ["Sonny", "Fredo", "Michael"]
}
print(children)

# Inicialización vacía: Útil para ir llenando el diccionario durante la ejecución.
my_empty_dictionary = {}
print(my_empty_dictionary)

# Inserción directa: Si la clave no existe, se crea con el valor asignado.
menu = {"oatmeal": 3, "avocado toast": 6, "carrot juice": 5, "blueberry muffin": 2}
print("Before: ", menu)
menu["cheesecake"] = 8  # Agrega nueva pareja clave:valor
print("After", menu)

# Error común de reasignación: 
# Aquí no se están agregando elementos, se está sobreescribiendo la variable completa.
# Al final, 'animals_in_zoo' solo contendrá el último diccionario asignado.
animals_in_zoo = {"dinosaurs": 0}
animals_in_zoo = {"dinosaurs": 0}
animals_in_zoo = {"horses": 2} 
print(animals_in_zoo) # Solo imprime {"horses": 2}

# Método .update(): Inserción masiva o fusión de diccionarios.
# Es más eficiente que asignar uno por uno si tienes muchos datos nuevos.
sensors = {"living room": 21, "kitchen": 23, "bedroom": 20}
print("Before", sensors)
sensors.update({"pantry": 22, "guest room": 25, "patio": 34}) # Añade 3 elementos de golpe
print("After", sensors)

# Verificación de .update() ampliando registros existentes.
user_ids = {"teraCoder": 9018293, "proProgrammer": 119238}
user_ids.update({"theLooper": 138475, "stringQueen": 85739})
print(user_ids)

# Sobrescritura de valores (Mutabilidad):
# Si asignas un valor a una clave que YA existe, el valor antiguo se pierde y se reemplaza.
menu = {"oatmeal": 3, "avocado toast": 6, "carrot juice": 5, "blueberry muffin": 2}
print("Before: ", menu)
menu["oatmeal"] = 5 # "oatmeal" cambia de 3 a 5
print("After", menu)

# Combinación de métodos: .update() para agregar y [] para corregir datos.
oscar_winners = {"Best Picture": "La La Land", "Best Actor": "Casey Affleck"}
print("Before", oscar_winners)
oscar_winners.update({"Supporting Actress": "Viola Davis"}) # Agrega nueva categoría
oscar_winners["Best Picture"] = "Moonlight" # Corrige un valor existente
print("After2", oscar_winners)

### COMPRENSIÓN DE DICCIONARIOS (Dict Comprehensions) ###

names = ['Jenny', 'Alexus', 'Sam', 'Grace']
heights = [61, 70, 67, 64]

# zip(): Crea un iterador de tuplas emparejando índices (e.g., ('Jenny', 61)).
# Es un objeto de memoria, por eso al imprimirlo no se ven los datos directamente.
zipStudents = zip(names, heights)
print("zipStudents object: ", zipStudents)

# Generación dinámica: Itera el zip y construye el diccionario en una sola línea.
students = {key:value for key, value in zip(names, heights)}
print(students)

# Ejemplo desglosado de zip + comprensión:
drinks = ["espresso", "chai", "decaf", "drip"]
caffeine = [64, 40, 0, 120]
zipped_drinks = zip(drinks, caffeine)
drinks_to_caffeine = {key:value for key, value in zipped_drinks}
print(drinks_to_caffeine)

# FLUJO COMPLETO: Creación, Modificación y Anidación Profunda.
songs = ["Like a Rolling Stone", "Imagine", "Respect"]
playcounts = [78, 44, 89]

# 1. Creación masiva
plays = {key:value for key, value in zip(songs, playcounts)}

# 2. Actualización (añadir y modificar)
plays.update({"Purple Haze": 1}) # Nuevo
plays.update({"Respect": 94})    # Modifica el existente
print("Plays: ", plays)

# 3. Diccionarios Anidados: Un diccionario donde los VALORES son otros diccionarios.
# Esto permite crear estructuras de datos complejas (como archivos JSON).
library = {
    "The Best Songs": plays, 
    "Sunday Feelings": {}    # Diccionario vacío dentro de otro
}
print(library)
