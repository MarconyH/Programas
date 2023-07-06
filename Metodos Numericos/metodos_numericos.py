from math import log, e, sin, cos

erro = 1e-5

def f(x):
    return -0.8*(x**3)+1.994*(x**2)+20.01*x-9.86
#    return 2*log(3-cos(x), e)-3*(x**x)+5*sin(x)
#    return 0.25*(x**3)-5.876*(x**2)+5.306*x-45.89# função que queremos encontrar as raízes

def df(x):
    return -2.4*(x**2)+7.976*x+20.01
#    return 2*sin(x)/(3-cos(x))-3*(1+log(x,e))*(x**x)+5*cos(x)
#    return 0.75*(x**2)-11.752*x+5.306

def ddf(x):
    return -4.8*x+7.976
#    return (2*cos(x)*(3-cos(x))-2*(sin(x)**2))*(3-(cos(x)**(-2))-3*(x**(x-1))-(3*(1+log(x,e)**2))*(x**x)+5*sin(x))
#    return 1.5*x-11.752


def bissecao(a, b, erro):
    i = 0
    while True:
        i += 1
        fa = f(a)
        fb = f(b)
        xn = (a + b)/2
        fxn = f(xn)
        if(i == 1):
            erro_atual = "---"

        else:
            erro_atual = abs(b - a)
        print("Iteração", i, ":")
        print("Intervalo [", a, ",", b, "]")
        print("x =", xn)
        print("f(x) =", fxn)
        print("f(a) =", fa)
        #print("f(b) =", fb)
        
       
        print("Erro atual =", erro_atual)
        if i == 1:
            erro_atual = 1
        print("\n")
        if erro_atual < erro:
            print("Raiz encontrada:", xn)
            break
        if fa * fxn < 0:
            b = xn
            fb = fxn
        else:
            a = xn
            fa = fxn

def cordas(x, c, erro):
    i = 1
    while True:
        i += 1
        fx = f(x)
        fc = f(c)
        xn = x - (fx/(fx - fc))*(x - c)
        fxn = f(xn)
        erro_atual = abs(xn - x)
        print("Iteração", i, ":")
        print("Intervalo [", x, ",", c, "]")
        print("xn =", xn)
        print("f(x) =", fxn)
        print("Erro atual =", erro_atual)
        print("\n")
        x = xn
        if(erro_atual < erro):
            print("Achouu")
            break

def newton(x0, erro):
    i = 0
    while True:
        i += 1
        fx = f(x0)
        dfx = df(x0)
        xn = x0 - fx/dfx
        fxn = f(xn)
        dfxn = df(xn)
        erro_atual = abs(xn - x0)
        print("Iteração", i, ":")
        print("x =", xn)
        print("f(x) =", fxn)
        print("f'(x) = ", dfxn)
        print("Erro atual =", erro_atual)
        print("\n")
        if erro_atual < erro:
            print("Raiz encontrada:", xn)
            break
        x0 = xn

def intervalo_fixo():
    a = float(input("Digite o intervalo inferior: "))
    b = float(input("Digite o intervalo superior: "))
    
    ia = f(a)*ddf(a)
    ib = f(b)*ddf(b)

    if op == 2:
        if ia < 0:
            print("f(a): ", f(a))
        elif ib < 0:
            print("f(b): ", f(b)) 
    elif op == 3:
        if ia > 0:
            print("f(a): ", f(a))
            print("f'(a): ", df(a))
        elif ib > 0:
            print("f(b): ", f(b))
            print("f'(b): ", df(b))

    print("Intervalo inferior: ", ia)
    print("Intervalo superior: ", ib)

def intervalo():
    op = input("Intervalo fixo? y/n: ")
    if op == 'n':
        a = float(input("Digite o intervalo inferior: "))
        b = float(input("Digite o intervalo superior: "))
    elif(op == 'y'):
        intervalo_fixo()
        a = float(input("Intervalo variável: "))
        b = float(input("Intervalo fixo: "))
    i = [a, b]
    return i
op = -1
while(op != 0):
    print("Menu")
    print("1 - Bisseção")
    print("2 - Cordas")
    print("3 - Newton")
    print("0 - Sair")
    op = int(input("Digite qual método você quer usar: "))

    match op:
        case 1:
            i = intervalo()
            bissecao(i[0], i[1], erro)
        case 2:
            i = intervalo()
            cordas(i[0], i[1], erro)
        case 3:
            i = intervalo()
            newton(i[0], erro)
        case 0:
            print("Fechando programa ...")
        case _:
            print("Digite uma opção válida")

