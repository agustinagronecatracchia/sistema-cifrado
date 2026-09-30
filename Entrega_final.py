#Funcion menu: muestra las opciones disponibles para el usuario y devuelve la opción seleccionada, maneja el caso en que el usuario ingrese una opción no válida
def mostrar_menu():
    print("\nENCRIPTACION")
    print("0. Cargar palabra")
    print("1. Encriptar por el metodo de Abecedario Desordenado")
    print("2. Desencriptar por el metodo de Abecedario Desordenado")
    print("3. Encriptar por el metodo de Vocales Invertidas")
    print("4. Desencriptar por el metodo de Vocales Invertidas")
    print("5. Salir")
    try: #pide al usuario que ingrese una opción y maneja el caso en que no ingrese un número válido
        opcion = int(input("Ingrese una opcion: "))
        return opcion
    except ValueError:
        return -1 # Retorna un valor inválido si el usuario no ingresa un número

#Función para cargar la palabra
def cargar_palabra(palabras):
    #en caso de querer cargar mas palabras se modifica el for 
    for i in range(1):  # Solo se carga una palabra
        palabra = input("Ingrese la palabra 1 (solo minusculas, sin espacios): ")
        palabras[i] = palabra
    print("Palabra cargada exitosamente.")

#Función método del abecedario desordenado
def abecedario_desordenado(palabras, modo):
    normal =      "abcdefghijklmnopqrstuvwxyz" #abecedario normal
    desordenado = "qwertyuiopasdfghjklzxcvbnm" #abecedario desordenado, cada letra corresponde a la misma posición en el abecedario normal
    print(f"\nPalabra original: {palabras[0]}")
    resultado = ""
    for letra in palabras[0]: #analiza las letras de la palabra 
        if 'a' <= letra <= 'z':
            if modo == 1:
                # Encriptar
                posicion = normal.find(letra) #busca la posición de la letra en el abecedario normal
                resultado += desordenado[posicion] #agrega la letra correspondiente del abecedario desordenado al resultado
            else:
                # Desencriptar
                posicion = desordenado.find(letra) #busca la posición de la letra en el abecedario desordenado
                resultado += normal[posicion] #agrega la letra correspondiente del abecedario normal al resultado
        else:
            # Si hay algún caracter que no es letra minúscula, lo deja igual
            resultado += letra      
    palabras[0] = resultado
    print(f"Resultado: {palabras[0]}")

# Función método de vocales invertidas
def vocales_invertidas(palabras):
    normal = "aeiou" #vocales normales, cada letra corresponde a la misma posición en la cadena de vocales invertidas
    invertidas = "uoiea" #vocales invertidas
    print(f"Palabra original: {palabras[0]}")
    resultado = ""
    for letra in palabras[0]:
        if letra in normal: #recorre la palabra y verifica si la letra es una vocal
            posicion = normal.find(letra) #busca la posición de la vocal en la cadena de vocales normales
            resultado += invertidas[posicion] #agrega la vocal correspondiente de la cadena de vocales invertidas al resultado
        else:
            resultado += letra # Si no es una vocal, la deja igual
    palabras[0] = resultado
    print(f"Resultado: {palabras[0]}")

# Función principal: conecta a las demás funciones y maneja el flujo del programa
def main():
    palabras = [""] #almacenar la palabra, se le pone comillas porque hay un solo elemento vacio dentro
    cargado = False #variables de control para verificar si se han cargado palabras 
    encriptado_metodo1 = False #variables de control para verificar si se han encriptado las palabras con cada método
    encriptado_metodo2 = False #variables de control para verificar si se han encriptado las palabras con cada método
    while True:
        opcion = mostrar_menu() #muestra el menú y obtiene la opción seleccionada por el usuario
        match opcion:
            case 0: #se cargan las palabras y se resetean las variables de control para que el usuario pueda encriptar y desencriptar nuevamente con los métodos disponibles
                cargar_palabra(palabras)
                cargado = True 
                encriptado_metodo1 = False
                encriptado_metodo2 = False
            case 1: #palabra cargada y encriiptada con el metodo 1
                if not cargado: #caso de no estar cargada la palabra
                    print("\nNo se han cargado palabras. Por favor, cargue las palabras primero.")
                elif encriptado_metodo1 or encriptado_metodo2: #para evitar que encripte una palabra ya encriptada
                    print("\nError: La palabra ya se encuentra encriptada. Desencríptela primero.")
                else: #resultado
                    print("\nAbecedario Desordenado - Encriptar")
                    abecedario_desordenado(palabras, 1)
                    encriptado_metodo1 = True
            case 2: #palabra encriptada con el metodo de abecedario desordenado y desencriptada, si no se han encriptado con el metodo de abecedario desordenado, se muestra un mensaje indicando que se debe realizar esa acción primero
                if encriptado_metodo1:
                    print("\nAbecedario Desordenado - Desencriptar")
                    abecedario_desordenado(palabras, 2)
                    encriptado_metodo1 = False
                else:
                    print("\nNo se han encriptado las palabras con el metodo de Abecedario Desordenado. Por favor, encripte primero.")       
            case 3: #palabra cargada y encriiptada con el metodo 2
                if not cargado: #caso de no estar cargada la palabra
                    print("\nNo se han cargado palabras. Por favor, cargue las palabras primero.")
                elif encriptado_metodo1 or encriptado_metodo2: #para evitar que encripte una palabra ya encriptada
                    print("\nError: La palabra ya se encuentra encriptada. Desencríptela primero.")
                else: #resultado
                    print("\nVocales Invertidas - Encriptar")
                    vocales_invertidas(palabras)
                    encriptado_metodo2 = True
            case 4: #palabra encriptada con el metodo de vocales invertidas y desencriptada, si no se han encriptado con el metodo de vocales invertidas, se muestra un mensaje indicando que se debe realizar esa acción primero
                if encriptado_metodo2:
                    print("\nVocales Invertidas - Desencriptar")
                    vocales_invertidas(palabras)
                    encriptado_metodo2 = False
                else:
                    print("\nNo se han encriptado las palabras con el metodo de Vocales Invertidas. Por favor, encripte primero.")   
            case 5: #opción para salir del programa, se muestra un mensaje de despedida y se rompe el ciclo para finalizar el programa
                print("\nSaliendo del programa. ¡Hasta luego!")
                break
            case _: #break para manejar el caso en que el usuario ingrese una opción no válida
                print("\nOpción no válida. Intente nuevamente.")
main() #llama a la función principal para iniciar el programa