from persistencia import *
from class_ import *

veiculos = Veiculos()
motoristas = Motoristas()
viagens = Viagens()
manutencoes = Manutencoes()
abastecimentos = Abastecimentos()



motoristas.consult()
veiculos.consult()
viagens.consult(veiculos, motoristas)
manutencoes.consult(veiculos)
abastecimentos.consult(veiculos)


def cadastro_motorista():
    novo_motorista = {"nome":input('Nome: '), "CPF":input('CPF: '), 
        "RG":input('RG:'), "CNH":input('CNH: '), "km":float(input("Km: ")), "viagens":int(input("Quantidade viagens: "))}
    motoristas.cadastro_dicionario(novo_motorista, novo_motorista["CPF"])
    motoristas.add()
    
def pesquisa_motorista(cpf = ''):
    if cpf == '':
        cpf = input("Digite o CPF do motorista procurado: ")
    motorista = motoristas.pesquisa_item(cpf)
    if motorista:
        return motorista
    return None

def editar_motorista():
    cpf = input("Digite o CPF: ")

    motorista = motoristas.pesquisa_item(cpf)

    if motorista:
        motorista.update({"nome":input('Nome: '), "RG":input('RG: '), "CNH":input('CNH: ')})
        motoristas.cadastro_dicionario(motorista, cpf)
        motoristas.add()

    else:
        print("Motorista não encontrado")

def deletar_motorista():
    motorista = pesquisa_motorista()
    if motorista:
        motoristas.deletar_item(motorista["CPF"])
        motoristas.add()
    else:
        print("Motorista não encontrado")

def gerenciamento_motorista():
    op = -1
    while op != 'z':
        print('a - Cadastrar Novo Motorista')
        print('b - Pesquisar Motorista')
        print('c - Editar Motorista')
        print('d - Deletar Motorista')
        print('z - Sair\n')
        op = input('')
        match op:
            case 'a':
                cadastro_motorista()
            case 'b':
                motorista = pesquisa_motorista()
                if motorista:
                    print(motorista)
                else:
                    print("Motorista não encontrado")
            case 'c':
                editar_motorista()
            case 'd':
                deletar_motorista()
            case 'z':
                print("Fechando...")
            case _:
                print('Opção não existente')
    return

def cadastro_veiculo():
    novo_veiculo = {"marca":input("Marca: "), "modelo":input("Modelo: "), "ano":input("Ano: "), 
                    "placa":input("Placa: "), "chassi":input("Chassi: "), "cor":input("Cor: "),"km":float(input("Km: "))}
    
    veiculos.cadastro_dicionario(novo_veiculo, novo_veiculo["placa"])
    return

def pesquisa_veiculo(placa = ''):

    if placa == '':
        placa = input('Digite a placa do veículo procurado: ')

    veiculo = veiculos.pesquisa_item(placa)
    if veiculo:
        return veiculo
    else:
        return None

def editar_veiculo():            
    placa = input("Digite a placa: ")

    veiculo = pesquisa_veiculo(placa)
    if veiculo:
        veiculo.update({"marca":input("Marca: "), "modelo":input("Modelo: "), "ano":input("Ano: "), 
                     "chassi":input("Chassi: "), "cor":input("Cor: ")})
    else:
        print("Veículo não encontrado")
    

def deletar_veiculo():
    veiculo = pesquisa_veiculo()
    if veiculo:
        veiculos.deletar_item(veiculo["placa"])
    else:
        print(veiculo)
    

def quilometragem():
    placa = input("Digite a placa: ")
    veiculo = veiculos.pesquisa_item(placa)
    if veiculo:
        print(veiculo.get("km"))
    else:
        print("Veiculo não encontrado")

def gerenciamento_veiculo():
    op = -1
    while op != 'z':
        print('a - Cadastrar Novo Veículo')
        print('b - Pesquisar Veículo')
        print('c - Editar Veículo')
        print('d - Deletar Veículo')
        print('e - Ver Quilometragem de Veículo')
        print('z - Sair')
        op = input('')
        match op:
            case 'a':
                cadastro_veiculo()
            case 'b':
                veiculo = pesquisa_veiculo()
                if veiculo:
                    print(veiculo)
                else:
                    print("Veículo não encontrado")
            case 'c':
                editar_veiculo()
            case 'd':
                deletar_veiculo()
            case 'e':
                quilometragem()
            case 'z':
                print("Fechando...")
            case _:
                print('Opção não existente')
    return

def cadastrar_viagem():
    motorista = pesquisa_motorista()
    veiculo = pesquisa_veiculo()
    if motorista == None or veiculo == None:
        print("Não foi encontrado motorista ou viagem")
        return
    
    destino = input("Destino: ")
    origem = input("Origem: ")
    distancia = float(input("Distância: "))

    veiculo.update({"km":veiculo["km"]+distancia})
    motorista.update({"km":motorista["km"]+distancia, "viagens":motorista.get("viagens")+1})

    nova_viagem = {"destino":destino, "origem":origem, "distância":distancia, 
                "motorista":motorista, 
                "veiculo":veiculo}
    i = viagens.prox_chave()
    i = str(i)
    viagens.cadastro_dicionario(nova_viagem, i)
    
    viagens.add()
    veiculos.add()
    motoristas.add()

def editar_viagem():
    viagem = viagens.pesquisa_item(input("Digite o código da viagem: "))

    if viagem:
        distancia_antiga = viagem.get("distância")
        viagem.update({"destino":input("Destino: "), "origem":input("Origem: "), "distância":float(input("Distância: "))})
        
        veiculo = viagem.get("veiculo")
        motorista = viagem.get("motorista")
        
        veiculo.update({"km":veiculo.get("km")-distancia_antiga+viagem.get("distância")})
        motorista.update({"km":motorista.get("km")-distancia_antiga+viagem.get("distância")})
        viagens.add()
        motoristas.add()
        veiculos.add()
    else:
        print("Esta viagem não existe")
    return

def gerenciamento_viagem():
    op_viagem = -1
    while op_viagem != "z":
        if motoristas.nao_existe() or veiculos.nao_existe():
            print("Não existem motoristas ou veículos cadastrados no sistema")
            return
        else:
            print("a - Cadastrar Viagem")
            print("b - Editar Viagem")
            print("z - Sair")
            op_viagem = input("")
            match op_viagem:
                case "a":
                    cadastrar_viagem()
                case "b":
                    editar_viagem()
                case "z":
                    print("Fechando...")
           
    return

def registrar_abastecimento():

    veiculo = pesquisa_veiculo()
    if veiculo:
        novo_abastecimento = {"veiculo":veiculo,"valor":float(input("Valor: ")),
                              "data":input("Data: "),"quantidade":int(input("Quantidade: "))}
        
        
        abastecimentos.cadastro_dicionario(novo_abastecimento,str(abastecimentos.prox_chave()))
    else:
        print("Veículo não encontrado")

def registrar_manutencao():
    veiculo = pesquisa_veiculo()
    if veiculo:
        print(veiculo)
    else:
        novo_manutencao = {"veiculo":veiculo,"data":input("Data: "), "tipo":input("Tipo: "),
                            "custo":float(input("Custo: "))}

        
        manutencoes.cadastro_dicionario(novo_manutencao, str(manutencoes.prox_chave()))
    return

def relatorio():
    print("Quantidade de Motoristas: ", motoristas.quantidade())
    print("Quantidade de Veículos: ", veiculos.quantidade())
    
    motorista_vi, motorista_km = motoristas.maior_motorita()
        
    print("Motorista que mais realizou viagens: ", motorista_vi)
    print("Motorista que mais km percorreu: ", motorista_km)
    
    veiculo = veiculos.maior_veiculo()
            
    print("Veículo com maior km: ", veiculo)
    
    despesa_abaste = abastecimentos.maior_abastecimento()
    
    print("Total de despesas com abastecimento: ", despesa_abaste)
    
    despesa_manut = manutencoes.maior_manutencao()
    
    print("Total de despesas de manutenção: ", despesa_manut)
    return

def escolha(op):
    match op:
        case 1:
            gerenciamento_motorista()
        case 2:
            gerenciamento_veiculo()
        case 3:
            gerenciamento_viagem()
        case 4:
            registrar_abastecimento()
        case 5:
            registrar_manutencao()
        case 6:
            relatorio()
        case 0:
            print('Encerrando...')
        case _:
            print('Opção não existente')
    return

def menu(op):
    while op != 0:
        try:
            print('1 - Gerenciamento de Motoristas')
            print('2 - Gerenciamento de Veículos')
            print('3 - Gerenciamento de Viagem')
            print('4 - Registrar Abastecimento')
            print('5 - Registrar Manutenção')
            print('6 - Relatório')
            print('0 - Sair')
            op = int(input(''))
            escolha(op)
        except Exception:
            print("Digite um número inteiro")
    return

op = -1
menu(op)