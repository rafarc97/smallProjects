#!/usr/bin/env python
# -*- coding: utf-8 -*-
from time import sleep
from colorama import Fore
import requests, os, json

API_ENDPOINT = 'http://localhost:8080/Habitacion'


#Función alta habitación
def alta_habitacion():

    alta = 'S'
    while alta not in ('N','n'):
        os.system('clear')
        print(Fore.LIGHTCYAN_EX+'---------------------------ALTA HABITACIÓN------------------------\n\n'+Fore.RESET)

        try:
            plazas = int(input('\n\t'+Fore.LIGHTYELLOW_EX+ '-> Introduzca el nº plazas: '))
            equipamiento = input('\n\t-> Introduzca el equipamento: ')
            ocupado = int(input('\n\t-> Introduzca \n\t\t -> 0.Habitación NO ocupada \n\t\t -> 1.Habitación SÍ Ocupada: '))
            print(Fore.RESET)
            if (ocupado not in (0,1)):
                print(Fore.LIGHTRED_EX+'\nError. Debe introducir: 1. Número, 2. Palabra/s, 3. Número 0/1\n'+Fore.RESET)
                break
        except:
            print(Fore.LIGHTRED_EX+'\nError. Debe introducir: 1. Número, 2. Palabra/s, 3. Número 0/1\n'+Fore.RESET)
            break


        data = {
            "numeroPlazas": plazas,
            "equipamiento": equipamiento,
            "ocupada": ocupado
        }
        room = requests.post('http://localhost:8080/altaHabitacion', json=data)


        auxiliar = 0
        while auxiliar == 0:
            alta = str(input('\n¿Desea realizar un nuevo alta?'+Fore.LIGHTGREEN_EX+ ' S/s ' +Fore.RESET +'ó' + Fore.LIGHTRED_EX+ ' N/n: '+Fore.LIGHTYELLOW_EX))
            print(Fore.RESET)
            if alta not in ('s','n','S','N'):
                print(Fore.LIGHTRED_EX+'Introduce un caracter correcto'+Fore.RESET)
            else:
                auxiliar = 1

        os.system('clear')
        print(Fore.LIGHTGREEN_EX+'\nCaracter introducido correctamente.')
        if alta in ('S','s'):
            print('Vamos a realizar un nuevo alta...'+Fore.RESET)
        elif alta in ('N','n'):
            print('Cerrando proceso de alta...'+Fore.RESET)



#Función modificar habitación
def modificar_habitacion():
    aux = 0
    while aux == 0:
        auxiliar = 0
        while auxiliar == 0:
            print('----------------MODIFICAR HABITACIÓN---------------\n\n')
            id = input(Fore.LIGHTYELLOW_EX+'Introduzca el id de la habitación que desea modificar: ')
            print(Fore.RESET)

            if id.isalpha() == True:
                os.system('clear')
                print(Fore.LIGHTRED_EX+'\nCarácter erróneo.\n'+Fore.RESET)
            elif id.isalnum() == True:
                data = {
                    'identificador': id
                }
                room = requests.get('http://localhost:8080/Habitacion', json=data)

                if room.text in '[]':
                    print(Fore.RED+'No se ha encontrado la habitacion\n'+Fore.RESET)
                else:
                    auxiliar = 1

        auxiliar2 = 0
        while auxiliar2 == 0:
            print('\nIntroduzca que campo desea modificar: \n')
            print('\t' +Fore.LIGHTCYAN_EX+' -> 1. '+Fore.RESET+'Número de Plazas')
            print('\t' +Fore.LIGHTCYAN_EX+' -> 2. '+Fore.RESET+'equipamiento')
            print('\t' +Fore.LIGHTCYAN_EX+' -> 3. '+Fore.RESET+'Ocupación')
            print('\t' +Fore.LIGHTCYAN_EX+' -> 4. '+Fore.RESET+'Salir')
            respuesta = input(Fore.LIGHTYELLOW_EX+'\n\t -> ')
            print(Fore.RESET)

            if respuesta not in ('1','2','3','4'):
                print(Fore.LIGHTRED_EX+'Carácter erróneo. '+Fore.RESET)
                print(Fore.RESET)
            else:
                auxiliar2 = 1
                print(Fore.LIGHTGREEN_EX+'\nNumero introducido correctamente'+Fore.RESET)
                if respuesta == '1':
                    auxiliar4 = 0
                    while auxiliar4 == 0:
                        plazas = input(Fore.LIGHTYELLOW_EX+'\nIntroduce el nuevo número de plazas: ')
                        print(Fore.RESET)
                        if plazas.isalnum() == True:
                            auxiliar4 = 1
                            data = {
                                "plazas": plazas,
                                "campo": "plazas",
                                "id": id
                            }
                            llamada1 = requests.put('http://localhost:8080/modificarHabitacion', json=data)
                        else:
                            print(Fore.LIGHTRED_EX+'Carácter incorrecto.'+Fore.RESET)

                elif respuesta == '2':
                    auxiliar4 = 0
                    while auxiliar4 == 0:
                        equipamiento = (input(Fore.LIGHTYELLOW_EX+'\nIntroduce el nuevo equipamiento: '))
                        print(Fore.RESET)
                        if equipamiento.isalpha() == True:
                            auxiliar4 = 1
                            data = {
                                "equipamiento": equipamiento,
                                "campo": "equipamiento",
                                "id": id
                            }
                            llamada1 = requests.put('http://localhost:8080/modificarHabitacion', json=data)
                        else:
                            print(Fore.LIGHTRED_EX+'Carácter incorrecto.'+Fore.RESET)

                elif respuesta == '3':
                    auxiliar4 = 0
                    while auxiliar4 == 0:
                        ocupada = input('\n'+Fore.LIGHTYELLOW_EX+'\nIntroduce la ocupación: \n\n\t -> 1.Ocupado \n\t -> 0.No ocupado: \n')
                        print(Fore.RESET)
                        if ocupada.isalnum() == True:
                            auxiliar4 = 1
                            data = {
                                "ocupacion": ocupada,
                                "campo": "ocupacion",
                                "id": id
                            }
                            llamada1 = requests.put('http://localhost:8080/modificarHabitacion', json=data)
                        else:
                            print(Fore.LIGHTRED_EX+'Carácter incorrecto.'+Fore.RESET)

                elif respuesta == '4':
                    print('Saliendo del sistema...')

        alta = input('¿Desea realizar una nueva modificación?' +Fore.LIGHTGREEN_EX+ ' S/s ' +Fore.RESET +'ó' + Fore.LIGHTRED_EX+ ' N/n: '+Fore.LIGHTYELLOW_EX)

        aux2 = 0
        while aux2 == 0:
            if alta not in ('s', 'n', 'S', 'N'):
                print(Fore.LIGHTRED_EX+'Error. Introduce un carácter correcto\n'+Fore.RESET)
            else:
                aux2 = 1
                print(Fore.LIGHTGREEN_EX+'\n\nCaracter introducido correctamente.')
                if alta in ('S', 's'):
                    print('Vamos a realizar una nueva modificacion...'+Fore.RESET)
                elif alta in ('N', 'n'):
                    aux = 1
                    print('Saliendo del apartado "Modificar habitación"...')




#Función borrar habitación
def borrar_habitacion():
    disponible = 0
    while disponible == 0:
        print('-------------ELIMINAR DE HABITACIÓN---------------\n\n')
        disponible2 = 0
        while disponible2 == 0:
            id = input(Fore.LIGHTYELLOW_EX+'\nIntroduzca el id de la habitación que desea borrar: ')
            print(Fore.RESET)
            if id.isalpha() == False:
                disponible2 = 1
            else:
                print(Fore.LIGHTRED_EX+'Error. Debe introducir un carácter numérico...'+Fore.RESET)
        data = {
            'identificador': id
        }
        room = requests.get('http://localhost:8080/Habitacion', json=data)

        if room.text in '[]':
            print(Fore.LIGHTRED_EX+'\nNo se ha encontrado la habitacion. Inténtelo de nuevo...'+Fore.RESET)
        else:
            room = requests.post('http://localhost:8080/borrarHabitacion', json=data)
            os.system('clear')
            print(Fore.LIGHTGREEN_EX+'\nLa habitación se ha borrado satisfactoriamente.\n'+Fore.RESET)

        auxiliar2 = 0
        while auxiliar2 == 0:
            nuevaConsulta = input('\n¿Desea realizar una nueva consulta?' +Fore.LIGHTGREEN_EX+ ' S/s ' +Fore.RESET +'ó' + Fore.LIGHTRED_EX+ ' N/n: '+Fore.LIGHTYELLOW_EX)
            print(Fore.RESET)

            if nuevaConsulta in ('s', 'n', 'S', 'N'):
                auxiliar2 = 1
                os.system('clear')
                print(Fore.LIGHTGREEN_EX+'\nCaracter introducido correctamente.')

                if nuevaConsulta in ('s','S'):
                    print('\nVamos a realizar borrar una habitación'+Fore.RESET)
                else:
                    disponible = 1
                    print('\nSaliendo del apartado "Consultar habitación"...\n\n')
                    print(Fore.RESET)
            else:
                print(Fore.LIGHTRED_EX+'\nCarácter incorrecto...')




#Función consulta de TODAS las habitaciones
def consultaHabitaciones():
    os.system('clear')
    print('------------------CONSULTA HABITACIONES---------------\n\n')
    rooms = requests.get('http://localhost:8080/Habitaciones')
    nrooms = (len(eval(rooms.text)))

    if rooms.text in '[]':
        print('\n'+Fore.RED+'No existe ninguna habitacion en nuestra Base de Datos\n\n'+Fore.RESET)
    else:
        for i in range(nrooms):
            print('\nHabitacion con id nº: ' + str(eval(rooms.text)[i][0]))

            print('\t -> Plazas: ' + str(eval(rooms.text)[i][1]) + ' \n\t -> Equipamiento: ' + str(
                eval(rooms.text)[i][2]) + ' \n\t -> Ocupacion: ' + str(eval(rooms.text)[i][3]) + '\n\n')



#Función consultar UNA sola habitación
def consultaHabitacion():
    os.system('clear')
    print('-------------------CONSULTA HABITACIÓN------------------\n\n')
    auxiliar = 0
    while auxiliar == 0:
        auxiliar3 =0
        while auxiliar3 == 0:
            idHabitacion = input(Fore.LIGHTYELLOW_EX+'\nIntroduce el id de la habitación que desea consultar: ')
            print(Fore.RESET)

            if idHabitacion.isalpha() == True:
                print(Fore.LIGHTRED_EX+'Error. Carácter erróneo...'+Fore.RESET)
            else:
                auxiliar3 = 1
                id = idHabitacion
                data = {
                    "identificador": id,
                }
                room = requests.get('http://localhost:8080/Habitacion', json=data)

                if room.text in '[]':
                    print(Fore.RED+'No se ha encontrado la habitacion. Intentelo de nuevo...\n'+Fore.RESET)
                else:
                    print('\n Habitación con id nº: ' + str(eval(room.text)[0][0]))
                    print('\t -> Plazas: ' + str(eval(room.text)[0][1]) + ' \n\t -> Equipamiento: ' + str(eval(room.text)[0][2]) + ' \n\t -> Ocupacion: ' + str(eval(room.text)[0][3]) + '\n\n')



        auxiliar2 = 0
        while auxiliar2 == 0:
            nuevaConsulta = input('\n¿Desea realizar una nueva consulta?' +Fore.LIGHTGREEN_EX+ ' S/s ' +Fore.RESET +'ó' + Fore.LIGHTRED_EX+ ' N/n: '+Fore.LIGHTYELLOW_EX)
            print(Fore.RESET)

            if nuevaConsulta in ('s', 'n', 'S', 'N'):
                auxiliar2 = 1
                os.system('clear')
                print(Fore.LIGHTGREEN_EX+'\nCaracter introducido correctamente.')

                if nuevaConsulta in ('s','S'):
                    print('\nVamos a realizar una nueva consulta'+Fore.RESET)
                else:
                    auxiliar = 1
                    print('\nSaliendo del apartado "Consultar habitación"...')
                    print(Fore.RESET)
            else:
                print(Fore.LIGHTRED_EX+'\nCarácter incorrecto...')



#Función habitación ocupada
def habitacionOcupada():
    control = 0
    while control == 0:
        auxiliar2 = 0
        while auxiliar2 == 0:
            os.system('clear')
            print('------------DISPONIBILIDAD DE HABITACIONES-------------\n\n')
            num = input(Fore.LIGHTYELLOW_EX+'\tIntroduce:\n\t -> 1. Lista de habitaciones ocupadas\n\t -> 0. Lista de habitaciones desocupadas \n\t -> ')
            print(Fore.RESET)
            if num in ('0','1'):
                auxiliar2 = 1
            else:
                print(Fore.LIGHTRED_EX+'\nCarácter erróneo. Vuelve a intentarlo...\n'+Fore.RESET)
                sleep(2)


        data = {
            "num": num
        }
        rooms = requests.get('http://localhost:8080/consultaOcupacion', json=data)
        nrooms = len(eval(rooms.text))
        if nrooms == 0:
            if num in ('0'):
                print('No se ha encontrado ninguna habitación desocupada...')
            if num in ('1'):
                print('No se ha encontrado ninguna habitación ocupada...')
        else:
            for i in range(nrooms):
                if eval(rooms.text)[i][3] == 0:
                    eval(rooms.text)[i][3] = 'NO ocupada'
                else:
                    eval(rooms.text)[i][3] = 'Ocupada'

                print('\nHabitacion con id nº: ' + str(eval(rooms.text)[i][0]))
                print('\t -> Plazas: ' + str(eval(rooms.text)[i][1]) + ' \n\t -> Equipamiento: ' + str(eval(rooms.text)[i][2]) + ' \n\t -> Ocupacion: ' + str(
                    eval(rooms.text)[i][3]) + '\n')


        respuesta = input(Fore.LIGHTYELLOW_EX+'¿Desea realizar otra consulta? Introduzca' +Fore.LIGHTGREEN_EX+' s/S '+ 'ó' +Fore.LIGHTRED_EX+ ' n/N: '+Fore.LIGHTYELLOW_EX)
        print(Fore.RESET)

        if respuesta in ('s','S','n','N'):
            if respuesta in ('s','S'):
                print(Fore.LIGHTGREEN_EX+'\nCarácter introducido correctamente. Vamos a realizar una nueva consulta...\n\n'+Fore.RESET)
            else:
                control = 1
                print(Fore.LIGHTGREEN_EX+'\nCarácter introducido correctamente. Saliendo del apartado "DISPONIBILIDAD DE HABITACIONES"...\n\n'+Fore.RESET)
        else:
            print(Fore.LIGHTRED_EX+'\nError. Introduzca un carácter correcto...\n\n'+Fore.RESET)
