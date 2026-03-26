# #### Get A Key (Acceso Directo)
# Acceso mediante corchetes []. Es la forma más rápida O(1).
# Si la clave no existe, el programa se detiene con un KeyError.
building_heights = {"Burj Khalifa": 828, "Shanghai Tower": 632, "Abraj Al Bait": 601, "Ping An": 599, "Lotte World Tower": 554.5, "One World Trade": 541.3}
print(building_heights["Burj Khalifa"]) 

zodiac_elements = {"water": ["Cancer", "Scorpio", "Pisces"], "fire": ["Aries", "Leo", "Sagittarius"], "earth": ["Taurus", "Virgo", "Capricorn"], "air":["Gemini", "Libra", "Aquarius"]}
print(zodiac_elements["earth"])

# ## Verificación previa con 'in'
# Antes de acceder, validamos si la clave existe para evitar errores de ejecución.
key_to_check = "Landmark 81"
if key_to_check in building_heights:
   print(building_heights["Landmark 81"]) # Solo se ejecuta si la clave existe

# Inserción/Actualización simple
zodiac_elements["energy"] = "Not a Zodiac element"

# ## Safely Get a Key (Acceso Seguro con .get)
# .get() busca la clave, pero si no la encuentra, devuelve None en lugar de romper el código.
# Es ideal para consultar bases de datos o APIs donde los campos pueden faltar.
building_heights = {"Burj Khalifa": 828, "Shanghai Tower": 632}
print(building_heights.get("Shanghai Tower")) # Retorna 632
print(building_heights.get("My House"))       # Retorna None

# ### Lógica de respaldo (Fallback)
# Usamos .get() dentro de condicionales para asignar valores por defecto si el dato es nulo.
user_ids = {"teraCoder": 100019, "pythonGuy": 182921}

if user_ids.get("teraCoder") == None:
   tc_id = 1000
else: 
   tc_id = user_ids.get("teraCoder")
print(tc_id)

# Variable de seguridad si el usuario no existe
stack_id = 0
if user_ids.get("superStackSmash") == None:
      stack_id = 100000
print(stack_id)

# ### Delete a Key (Extracción con .pop)
# .pop(clave, valor_por_defecto) cumple doble función:
# 1. Borra el par clave:valor del diccionario.
# 2. Retorna el valor borrado para guardarlo en una variable.
raffle = {223842: "Teddy Bear", 872921: "Concert Tickets", 320291: "Gift Basket"}
# Si 320291 existe, lo saca; si no, devuelve "No Prize" (evita errores).
puesto_borrado = raffle.pop(320291, "No Prize")
print(raffle)

# Ejemplo de acumulación extrayendo recursos (lógica de videojuegos)
available_items = {"health potion": 10, "stamina grains": 15, "power stew": 30}
health_points = 20

# Sumamos puntos extrayendo el objeto del inventario (desaparece de available_items)
health_points += available_items.pop("stamina grains", 0)
health_points += available_items.pop("power stew", 0)
health_points += available_items.pop("mystic bread", 0) # No existe, suma 0 gracias al default

# ## Get All Keys (.keys)
# Devuelve una vista de todas las claves. Útil para saber qué etiquetas tenemos.
test_scores = {"Grace":[80, 90], "Jeffrey":[88, 81], "Pedro":[98, 95]}
print(list(test_scores)) # Convertir la vista a lista para visualización

for student in test_scores.keys():
  print(student)

# ## Get All Values (.values)
# Extrae solo los datos. Es perfecto para cálculos numéricos masivos.
num_exercises = {"functions": 10, "syntax": 13, "control flow": 15}
total_exercises = 0

for exercises in num_exercises.values():
  total_exercises += exercises # Suma todos los valores sin importar la clave
print("Total de ejercicios:", total_exercises)

# ## Get All Items (.items)
# El método más completo. Devuelve parejas (tuplas) de clave y valor.
# Permite "desempaquetar" ambas en el bucle 'for' directamente.
biggest_brands = {"Apple": 184, "Google": 141.7, "Microsoft": 80}

for company, value in biggest_brands.items():
 print(company + " vale " + str(value) + " billones. ")

# Ejemplo de estadísticas con .items()
pct_women_in_occupation = {"CEO": 28, "Engineering Manager": 9, "Pharmacist": 58}

for occupation, percentage in pct_women_in_occupation.items():
  print("Mujeres representan el " + str(percentage) + "% en: " + occupation)
