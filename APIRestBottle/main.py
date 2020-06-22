#!/usr/bin/env python
# -*- coding: utf-8 -*-

from cliente import *
from colorama import Fore,Back


def presentacion():

    os.system('clear')

    print('\n\n')
    print("             XXXXXX")
    print("             X")
    print("             X")
    print("             XXXX")
    print("             X")
    print("             X")
    print("             XXXXXX")

    sleep(0.1)
    os.system("clear")

    print("\n\n")
    print("             XXXXXX  XXXXXX")
    print("             X       X")
    print("             X       X")
    print("             XXXX    XXXXXX")
    print("             X            X")
    print("             X            X")
    print("             XXXXXX  XXXXXX")

    sleep(0.1)
    os.system("clear")



    print("\n\n")
    print("             XXXXXX  XXXXXX  XXXXXX")
    print("             X       X         XX")
    print("             X       X         XX")
    print("             XXXX    XXXXXX    XX")
    print("             X            X    XX")
    print("             X            X    XX")
    print("             XXXXXX  XXXXXX  XXXXXX")

    sleep(0.1)
    os.system("clear")


    print("\n\n")
    print("             XXXXXX  XXXXXX  XXXXXX  X      X")
    print("             X       X         XX    X      X")
    print("             X       X         XX    X      X")
    print("             XXXX    XXXXXX    XX    XXXXXXXX")
    print("             X            X    XX    X      X")
    print("             X            X    XX    X      X")
    print("             XXXXXX  XXXXXX  XXXXXX  X      X")

    sleep(0.1)
    os.system("clear")


    print("\n\n")
    print("             XXXXXX  XXXXXX  XXXXXX  X      X   XXXXXX  ")
    print("             X       X         XX    X      X  X      X ")
    print("             X       X         XX    X      X  X      X ")
    print("             XXXX    XXXXXX    XX    XXXXXXXX  X      X ")
    print("             X            X    XX    X      X  X      X ")
    print("             X            X    XX    X      X  X      X ")
    print("             XXXXXX  XXXXXX  XXXXXX  X      X   XXXXXX  ")

    sleep(0.1)
    os.system("clear")

    print("\n\n")
    print("             XXXXXX  XXXXXX  XXXXXX  X      X   XXXXXX  XXXXXXXXXXX")
    print("             X       X         XX    X      X  X      X      X")
    print("             X       X         XX    X      X  X      X      X")
    print("             XXXX    XXXXXX    XX    XXXXXXXX  X      X      X")
    print("             X            X    XX    X      X  X      X      X")
    print("             X            X    XX    X      X  X      X      X")
    print("             XXXXXX  XXXXXX  XXXXXX  X      X   XXXXXX       X")
    sleep(0.1);
    os.system("clear")

    print("\n\n")
    print("             XXXXXX  XXXXXX  XXXXXX  X      X   XXXXXX  XXXXXXXXXXX  XXXXXX ")
    print("             X       X         XX    X      X  X      X      X       X      ")
    print("             X       X         XX    X      X  X      X      X       X      ")
    print("             XXXX    XXXXXX    XX    XXXXXXXX  X      X      X       XXXX   ")
    print("             X            X    XX    X      X  X      X      X       X      ")
    print("             X            X    XX    X      X  X      X      X       X      ")
    print("             XXXXXX  XXXXXX  XXXXXX  X      X   XXXXXX       X       XXXXXX ")
    sleep(0.1);
    os.system("clear")

    print("\n\n")
    print("             XXXXXX  XXXXXX  XXXXXX  X      X   XXXXXX  XXXXXXXXXXX  XXXXXX  X           ")
    print("             X       X         XX    X      X  X      X      X       X       X           ")
    print("             X       X         XX    X      X  X      X      X       X       X           ")
    print("             XXXX    XXXXXX    XX    XXXXXXXX  X      X      X       XXXX    X           ")
    print("             X            X    XX    X      X  X      X      X       X       X           ")
    print("             X            X    XX    X      X  X      X      X       X       X           ")
    print("             XXXXXX  XXXXXX  XXXXXX  X      X   XXXXXX       X       XXXXXX  XXXXXXX     ")

    sleep(1)
    #os.system('clear')
    print("\n\n                                  TRABAJO REALIZADOR POR:\n")
    print("                            +---------------------------------+\n")
    print("                            |                                 |\n")
    print("                            |     Rafael Rodriguez Calvente   |\n")
    print("                            |                                 |\n")
    print("                            |        David García Pardo       |\n")
    print("                            |                                 |\n")
    print("                            +---------------------------------+\n")

    sleep(3)
    #os.system('clear')


if __name__ == '__main__':

    presentacion()

    respuesta = 0
    while respuesta != '7':
        print(Fore.LIGHTCYAN_EX+'\n\t---------------MENÚ--------------')
        print('\n\tElija que opción desea realizar: \n')
        print('\t -> 1. '+Fore.RESET+'Dar de alta una nueva habitación')
        print('\t'+Fore.LIGHTCYAN_EX+' -> 2. '+Fore.RESET+'Modificar los datos de una habitación')
        print('\t'+Fore.LIGHTCYAN_EX+' -> 3. '+Fore.RESET+'Consultar la lista completa de habitaciones')
        print('\t'+Fore.LIGHTCYAN_EX+' -> 4. '+Fore.RESET+'Consulta una habitación mediante identificador')
        print('\t'+Fore.LIGHTCYAN_EX+' -> 5. '+Fore.RESET+'Consultar la lista de habitaciones ocupadas o desocupadas')
        print('\t'+Fore.LIGHTCYAN_EX+' -> 6. '+Fore.RESET+'Borrar habitación')
        print('\t'+Fore.LIGHTCYAN_EX+' -> 7. '+Fore.RESET+'Salir')
        respuesta = str(input(Fore.LIGHTYELLOW_EX+'\n\t -> * '))
        print(Fore.RESET)

        auxiliar = 0
        while auxiliar == 0:
            if respuesta not in ('1','2','3','4','5','6','7'):
                respuesta = input(Fore.LIGHTRED_EX+'Carácter erróneo. Introduce un número: '+Fore.LIGHTYELLOW_EX)
                print(Fore.RESET)
            else:
                print(Fore.LIGHTGREEN_EX+'\nNúmero introducido correctamente\n'+Fore.RESET)
                auxiliar = 1

        #Dar de alta habitación
        if respuesta == '1':
            alta_habitacion()

        #Modificar habitación
        elif respuesta == '2':
            modificar_habitacion()

        #Consulta habitaciones
        elif respuesta == '3':
            consultaHabitaciones()
        # Consulta LA habitación
        elif respuesta == '4':
            consultaHabitacion()
        # Consulta habitaciones ocupadas o NO ocupadas
        elif respuesta == '5':
            habitacionOcupada()
        #Borramos habitación
        elif respuesta == '6':
            borrar_habitacion()
        # Salimos del sistema
        elif respuesta == '7':
            break

    print('\n'+Fore.LIGHTRED_EX+'Saliendo del sistema... Hasta la próxima!!\n\n')
