# IMPORTANTE: No modificar ni borrar este archivo
from hw2 import (imparYmenor, quienGana, restaPositiva, materia, estacion, mesLetrasPar, condicionAlumno, tipoFigura, tipoTriangulo)

#################################################
# Funciones de Test (no modificar)
#################################################

def testImparYmenor():
    print('Testeando testImparYmenor()... ', end='')
    assert imparYmenor(3, 5) == True
    assert imparYmenor(4, 5) == False
    assert imparYmenor(4, 4) == False
    print('Pasó!')

def testQuienGana():
    print('Testeando testQuienGana()... ', end='')
    assert quienGana("Hola", "Bye") == "Gana Hola"
    assert quienGana("Bye", "Hola") == "Gana Hola"
    assert quienGana("Hola", "Hola") == "Empate"
    print('Pasó!')

def testRestaPositiva():
    print('Testeando testRestaPositiva()... ', end='')
    assert restaPositiva(5, 3) == True
    assert restaPositiva(3, 5) == False
    assert restaPositiva(3, 3) == False
    print('Pasó!')

def testMateria():
    print('Testeando testMateria()... ', end='')
    assert materia(1) == "Introducción a la Programación"
    assert materia(2) == "Algebra y Lógica Computacional"
    assert materia(3) == "Matemática Discreta"        
    assert materia(4) == "Introducción a los Sistemas"
    assert materia(5) == "Organización de computadoras"
    assert materia(6) == "Ingles 1"
    assert materia(7) == "Análisis Matemático"
    assert materia(8) == "Algoritmos y Estructuras de Datos"
    assert materia(9) == "Programación 1"    
    assert materia(10) == "Arquitectura de Computadoras"
    print('Pasó!')

def testEstacion():
    print('Testeando testEstacion()... ', end='')
    assert estacion(1) == "Verano"
    assert estacion(2) == "Verano"
    assert estacion(3) == "Verano"        
    assert estacion(4) == "Otoño"
    assert estacion(5) == "Otoño"
    assert estacion(6) == "Otoño"
    assert estacion(7) == "Invierno"
    assert estacion(8) == "Invierno"
    assert estacion(9) == "Invierno"    
    assert estacion(10) == "Primavera"
    assert estacion(11) == "Primavera"
    assert estacion(12) == "Primavera"
    print('Pasó!')


def testMesLetrasPar():
    print('Testeando testMesLetrasPar()... ', end='')
    assert mesLetrasPar(1) == False
    assert mesLetrasPar(2) == False
    assert mesLetrasPar(3) == False
    assert mesLetrasPar(4) == False
    assert mesLetrasPar(5) == True
    assert mesLetrasPar(6) == False
    assert mesLetrasPar(7) == False
    assert mesLetrasPar(8) == True
    assert mesLetrasPar(9) == True
    assert mesLetrasPar(10) == False
    assert mesLetrasPar(11) == False
    assert mesLetrasPar(12) == False
    print('Pasó!')

def testCondicionAlumno():
    print('Testeando testCondicionAlumno()... ', end='')
    assert condicionAlumno(7,7,True) == "Promovido"
    assert condicionAlumno(7,7,False) == "Libre"
    assert condicionAlumno(4,4,True) == "Regular"
    assert condicionAlumno(4,4,False) == "Libre"
    assert condicionAlumno(3,3,True) == "Libre"
    assert condicionAlumno(3,3,False) == "Libre"
    print('Pasó!')

def testTipoFigura():
    print('Testeando testTipoFigura()... ', end='')
    assert tipoFigura(2,2,2,2) == "Es un cuadrado"
    assert tipoFigura(2,3,2,3) == "Es un rectangulo"
    assert tipoFigura(3,3,4,5) == "No es un cuadrado ni un rectangulo"
    assert tipoFigura(2,2,2,4) == "No es un cuadrado ni un rectangulo"
    assert tipoFigura(0,0,0,0) == "No es un cuadrado ni un rectangulo"
    assert tipoFigura(0,0,1,1) == "No es un cuadrado ni un rectangulo"
    print('Pasó!')

def testTipoTriangulo():
    print('Testeando testTipoTriangulo()... ', end='')
    assert tipoTriangulo(6,6,3) == "Isosceles"
    assert tipoTriangulo(2,2,2) == "Equilatero"
    assert tipoTriangulo(5,3,7) == "Escaleno"
    assert tipoTriangulo(1,2,3) == "No es un triangulo"
    print('Pasó!')


