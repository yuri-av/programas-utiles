# IMPORTANTE: No modificar ni borrar este archivo
from hw1 import (
    valorAbsoluto,
    contarLetrasNombre,
    potenciacion,
    perimetro,
    promedioNotas,
    cambioDolar,
)

#################################################
# Funciones de Test (no modificar)
#################################################


def testValorAbsoluto():
    print("Testeando testValorAbsoluto()... ", end="")
    assert valorAbsoluto(10) == "El valor absoluto de 10 es 10"
    assert valorAbsoluto(-10) == "El valor absoluto de -10 es 10"
    assert valorAbsoluto(0) == "El valor absoluto de 0 es 0"
    print("Pasó!")


def testContarLetrasNombre():
    print("Testeando testContarLetrasNombre()... ", end="")
    assert contarLetrasNombre("Maria") == "El nombre Maria tiene 5 letras."
    assert contarLetrasNombre("Nicolás") == "El nombre Nicolás tiene 7 letras."
    print("Pasó!")


def testPotenciacion():
    print("Testeando testPotenciacion()... ", end="")
    assert potenciacion(2, 1) == 2
    assert potenciacion(2, 3) == 8
    assert potenciacion(2, 0) == 1
    print("Pasó!")


def testPerimetro():
    print("Testeando testPerimetro()... ", end="")
    assert perimetro(2, 1) == 6
    print("Pasó!")


def testPromedioNotas():
    print("Testeando testPromedioNotas()... ", end="")
    assert promedioNotas(2, 4) == 3
    assert promedioNotas(0, 10) == 5
    assert promedioNotas(10, 10) == 10
    print("Pasó!")


def testCambioDolar():
    print("Testeando testCambioDolar()... ", end="")
    assert cambioDolar(90) == "Si me das 90 pesos, te doy 1 dolares"
    assert cambioDolar(0) == "Si me das 0 pesos, te doy 0 dolares"
    assert cambioDolar(180) == "Si me das 180 pesos, te doy 2 dolares"
    print("Pasó!")
