veiculos={"BCC009":{"marca":"Fiat", "modelo":"UNO", "ano":"2003", 
                    "placa":"BCC009", "chassi":"36563652", "cor":"Branco","km":500},
         "BCC006":{"marca":"Fiat", "modelo":"Toro", "ano":"2003", 
                   "placa":"BCC006", "chassi":"36563652","cor":"Branco","km":0},
         "BCC008":{"marca":"Fiat", "modelo":"Argo", "ano":"2003", 
                   "placa":"BCC007", "chassi":"36563652","cor":"Branco","km":0}  }

motoristas={"11111":{"nome":"François", "CPF":"11111", "RG":"223212", "CNH":"34221", "km": 500, "viagens":2},
            "22222":{"nome":"Ana", "CPF":"22222", "RG":"223212", "CNH":"34221", "km":0, "viagens":0},
            "33333":{"nome":"MAria", "CPF":"33333", "RG":"223212", "CNH":"34221", "km":0, "viagens":0}}

viagens={1:{"destino":"Bacabal", 
                "origem":"Caxias", 
                "distância":250.0, 
                "motorista":motoristas["11111"], 
                "veiculo":veiculos["BCC009"]},
         2:{"destino":"Bacabel", 
                "origem":"Caxias", 
                "distância":250.0, 
                "motorista":motoristas["11111"], 
                "veiculo":veiculos["BCC009"]
               }}

manutencoes ={1:{"veiculo":veiculos["BCC009"],"data":"02-02-2023", "tipo":"preventiva","custo":1000.0},
              2:{"veiculo":veiculos["BCC009"],"data":"02-02-2023", "tipo":"preventiva","custo":1000.0} }

abastecimentos={1:{"veiculo":veiculos["BCC009"],"valor":400.0,"data":"4-2-2023","quantidade":150},
               2:{"veiculo":veiculos["BCC009"],"valor":400.0,"data":"4-2-2023","quantidade":150},
               3:{"veiculo":veiculos["BCC009"],"valor":400.0,"data":"4-2-2023","quantidade":150},}

def cadastro_motorista():
    novo_motorista = {"nome":input('Nome: '), "CPF":input('CPF: '), 
        "RG":input('RG:'), "CNH":input('CNH: '), "km":float(input("Km: ")), "viagens":int(input("Quantidade viagens: "))}
    
    motoristas.update({novo_motorista["CPF"]:novo_motorista})

    return

def pesquisa_motorista(cpf = ''):
    if len(motoristas) == 0:
        return "Não existem motoristas no sistema"
    if cpf == '':
        cpf = input('Digite o CPF do motorista procurado: ')
    motorista = motoristas.get(cpf)
    if motorista:
        return motorista
    else:
        return "Motorista não encontrado"
        
    

def editar_motorista():
    if len(motoristas) != 0:

        cpf = input("Digite o CPF: ")

        motorista = pesquisa_motorista(cpf)

        if motorista == "Motorista não encontrado":
            print(motorista)

        else:
            motorista.update({"nome":input('Nome: '), "RG":input('RG: '), "CNH":input('CNH: ')})
    else:
        print("Não existem motoristas no sistema")
    return



def deletar_motorista():
    motorista = pesquisa_motorista()
    if motorista != "Não existem motoristas no sistema" and motorista != "Motorista não encontrado":
        del motoristas[motorista["CPF"]]
    else:
        print(motorista)
    
    return

def gerenciamento_motorista():
    op = -1
    while op != 'z':
        print('a - Cadastrar Novo Motorista')
        print('b - Pesquisar Motorista')
        print('c - Editar Motorista')
        print('d - Deletar Motorista')
        print('z - Sair')
        op = input('')
        match op:
            case 'a':
                cadastro_motorista()
            case 'b':
                print(pesquisa_motorista())
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
    
    veiculos.update({novo_veiculo["placa"]:novo_veiculo})
    return

def pesquisa_veiculo(placa = ''):
    if len(veiculos) == 0:
        return "Não existem veículos no sistema"

    if placa == '':
        placa = input('Digite a placa do veículo procurado: ')

    veiculo = veiculos.get(placa)
    if veiculo:
        return veiculo
    else:
        return "Veículo não encontrado"

def editar_veiculo():
    if len(veiculos) != 0:
            
        placa = input("Digite a placa: ")

        veiculo = pesquisa_veiculo(placa)
        if veiculo == "Veículo não encontrado":
            print(veiculo)
        else:
            veiculo.update({"marca":input("Marca: "), "modelo":input("Modelo: "), "ano":input("Ano: "), 
                        "chassi":input("Chassi: "), "cor":input("Cor: ")})
    else:
        print(veiculo)
    return

def deletar_veiculo():
    veiculo = pesquisa_veiculo()
    if veiculo != "Não existem veículos no sistema" and veiculo != "Veículo não encontrado":
        del veiculos[veiculo["placa"]]
    else:
        print(veiculo)
    return

def quilometragem():
    placa = input("Digite a placa: ")
    veiculo = pesquisa_veiculo(placa)
    print(veiculo.get("km"))
    return

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
                print(pesquisa_veiculo())
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
    if motorista == "Motorista não encontrado":
        print(motorista)
        return
    if veiculo == "Veículo não encontrado":
        print(veiculo)
        return
    
    destino = input("Destino: ")
    origem = input("Origem: ")
    distancia = float(input("Distância: "))

    veiculo.update({"km":veiculo["km"]+distancia})
    motorista.update({"km":motorista["km"]+distancia, "viagens":motorista.get("viagens")+1})

    nova_viagem = {"destino":destino, "origem":origem, "distância":distancia, 
                "motorista":motorista, 
                "veiculo":veiculo}
    
    for i in viagens.keys():
        index = i
    
    viagens.update({index+1:nova_viagem})
    return

def editar_viagem():
    viagem = viagens.get(int(input("Digite o código da viagem: ")))

    if viagem:
        distancia_antiga = viagem.get("distância")
        viagem.update({"destino":input("Destino: "), "origem":input("Origem: "), "distância":float(input("Distância: "))})
        
        veiculo = viagem.get("veiculo")
        motorista = viagem.get("motorista")
        
        veiculo.update({"km":veiculo.get("km")-distancia_antiga+viagem.get("distância")})
        motorista.update({"km":motorista.get("km")-distancia_antiga+viagem.get("distância")})
    else:
        print("Esta viagem não existe")
    return


def gerenciamento_viagem():
    op_viagem = -1
    while op_viagem != "z":
        if len(motoristas) == 0 or len(veiculos) == 0:
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
    if veiculo == "Veículo não encontrado" or veiculo == "Não existem veículos no sistema":
        print(veiculo)
    else:
        novo_abastecimento = {"veiculo":veiculo,"valor":float(input("Valor: ")),"data":input("Data: "),"quantidade":int(input("Quantidade: "))}

        for i in abastecimentos.keys():
            index = i
        abastecimentos.update({index+1:novo_abastecimento})
    return

def registrar_manutencao():
    veiculo = pesquisa_veiculo()
    if veiculo == "Veículo não encontrado" or veiculo == "Não existem veículos no sistema":
        print(veiculo)
    else:
        novo_manutencao = {"veiculo":veiculo,"data":input("Data: "), "tipo":input("Tipo: "),
                            "custo":float(input("Custo: "))}

        for i in manutencoes.keys():
            print(i)
            index = i
        manutencoes.update({index+1:novo_manutencao})
    return

def relatorio():
    print("Quantidade de Motoristas: ", len(motoristas))
    print("Quantidade de Veículos: ", len(veiculos))
    
    maior_viagem = 0
    mais_km = 0
    for i in motoristas.values():
        viagens = i.get("viagens")
        km = i.get("km")
        
        if(viagens > maior_viagem):
            maior_viagem = viagens
            motorista_vi = i
        if km > mais_km:
            mais_km = km 
            motorista_km = i
            
        
    print("Motorista que mais realizou viagens: ", motorista_vi)
    print("Motorista que mais km percorreu: ", motorista_km)
    
    maior_km = 0
    for i in veiculos.values():
        if i.get("km") > maior_km:
            maior_km = i.get("km")
            veiculo = i
            
    print("Veículo com maior km: ", veiculo)
    
    despesa_abaste = 0
    for i in abastecimentos.values():
        abastecimento = i.get("valor")
        despesa_abaste += abastecimento
    print("Total de despesas com abastecimento: ", despesa_abaste)
    
    despesa_manut = 0
    for i in manutencoes.values():
        menutencao = i.get("custo")
        despesa_manut += menutencao
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
        print('1 - Gerenciamento de Motoristas')
        print('2 - Gerenciamento de Veículos')
        print('3 - Gerenciamento de Viagem')
        print('4 - Registrar Abastecimento')
        print('5 - Registrar Manutenção')
        print('6 - Relatório')
        print('0 - Sair')
        op = int(input(''))
        escolha(op)
    return

op = -1
menu(op)