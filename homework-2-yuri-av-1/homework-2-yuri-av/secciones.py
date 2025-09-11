

def secciones(a, b):
    seccion = a
    antiguedad = b
    sueldo = 800
    if (seccion == 1):
        if (antiguedad < 5):
            sueldo = (sueldo * 0.1) + (sueldo + 120)
            return sueldo
        elif (antiguedad >= 5):
            sueldo = (sueldo * 0.2) + (sueldo + 120)
            return sueldo
    else:
        sueldo = sueldo + 250
        return sueldo

seccion = int(input("Ingrese sección 1 o 2: "))

antieguedad = int(input("Ingrese antiguedad: "))

print(secciones(seccion, antieguedad))

        