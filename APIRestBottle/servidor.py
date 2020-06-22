#!/usr/bin/env python
# -*- coding: utf-8 -*-

from bottle import run, request, post, get, put
import json, sqlite3
import os

class Habitacion:

    def __init__(self, plazas, equipamiento, ocupacion):
        self.plazas = plazas
        self.equipamiento = equipamiento
        self.ocupacion = ocupacion

    def __repr__(self):
        return "Habitacion('{}', '{}', {})".format(self.plazas, self.equipamiento, self.ocupacion)


def create_DDBB():
    c.execute("""CREATE TABLE habitaciones (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                plazas INTEGER,
                equipamiento VARCHAR(50),
                ocupacion INTEGER
                )""")

def close_DDBB():
    conn.close()

def insert_room(room):
    with conn:
        c.execute("INSERT INTO habitaciones VALUES (null, :plazas, :equipamiento, :ocupacion)", {'plazas': room.plazas, 'equipamiento': room.equipamiento, 'ocupacion': room.ocupacion})

def get_rooms():
    c.execute("SELECT * FROM habitaciones")
    return c.fetchall()

def get_room_by_id(numid):
    c.execute("SELECT * FROM habitaciones WHERE id=:id", {'id': numid})
    return c.fetchall()

def get_room_by_ocupation(num):
    c.execute("SELECT * FROM habitaciones WHERE ocupacion=:ocupacion", {'ocupacion': num})
    return c.fetchall()

def update_plazas_room(id,valor):
    with conn:
        c.execute("""UPDATE habitaciones SET plazas = :valor
                    WHERE id = :id""",
                  {'valor': valor, 'id': id})

def update_equipamiento_room(id,valor):
    with conn:
        c.execute("""UPDATE habitaciones SET equipamiento = :valor
                    WHERE id = :id""",
                  {'valor': valor, 'id': id})

def update_ocupacion_room(id,valor):
    with conn:
        c.execute("""UPDATE habitaciones SET ocupacion = :valor
                    WHERE id = :id""",
                  {'valor': valor, 'id': id})

def remove_room(id):
    with conn:
        c.execute("DELETE from habitaciones WHERE id = :id", {'id': id})


# Dar alta habitación
@post('/altaHabitacion')
def add():

    # Recogemos los datos del json
    plazas = str(request.json.get('numeroPlazas'))
    equipamiento = str(request.json.get('equipamiento'))
    ocupada = str(request.json.get('ocupada'))

    room = Habitacion(plazas, equipamiento, ocupada)
    insert_room(room)
    room2 = get_rooms()

    # devolvemos el json creado al cliente
    return json.dumps(room2)

#Borrar alta habitación
@post('/borrarHabitacion')
def borrar():
    id = int(request.json.get('identificador'))
    print(id)
    remove_room(id)

# Consultar todas las habitaciones
@get('/Habitaciones')
def query():
    rooms = get_rooms()
    return json.dumps(rooms)

# Modificar habitación
@put('/modificarHabitacion')
def mod():
    campo = str(request.json.get('campo'))
    valor = str(request.json.get(campo))
    id = str(request.json.get("id"))

    if campo == 'plazas':
        update_plazas_room(id,int(valor))
    elif campo == 'equipamiento':
        update_equipamiento_room(id,valor)
    else:
        update_ocupacion_room(id,int(valor))


@get('/Habitacion')
def oneQuery():
    id = int(request.json.get('identificador'))
    room = get_room_by_id(id)
    return json.dumps(room)


#Consultar habitaciones ocupadas Ò las desocupadas
@get('/consultaOcupacion')
def occupation():
    num = int(request.json.get('num'))
    rooms = get_room_by_ocupation(num)
    return json.dumps(rooms)


if __name__ == '__main__':

    conn = sqlite3.connect(':memory:')
    c = conn.cursor()
    create_DDBB()

    run(host='localhost', port=8080, debug=True)
