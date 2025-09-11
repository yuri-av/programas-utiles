################################################################################################
# Nombre de archivo: hw0.py
# El repositorio donde esta tu HW0 es: github.com/unlu-edu-ar/homework-0-yuri-av
#
# Completa con tu nombre, apellido y DNI
# Nombre y Apellido: Yuri Arancibia Vieira
# DNI: 47247542
################################################################################################


#################################################
# Funciones que tenés que programar
#################################################


def hello_world():
    # Modificar este código para que la función hello_world retorne el
    # string "Hello World!"
    return "Hello World!"
hello_world()


#################################################
# Funciones de Test (no modificar)
#################################################


def test_hello_world():
    print("Testeando hello_world()... ", end="")
    assert hello_world() == "Hello World!"
    print("Pasaste!")


#################################################
# testAll y main
#################################################


def testAll():
    # comentá los tests que no querés correr!
    test_hello_world()


def main():
    testAll()


if __name__ == "__main__":
    main()
