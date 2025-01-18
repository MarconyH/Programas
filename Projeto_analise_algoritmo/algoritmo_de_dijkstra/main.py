import os

class Matrix:
    size_graph = -1
    matrix = []
    folder_path = "/home/marcony/Documents/Programas/Projeto_analise_algoritmo/algoritmo_de_dijkstra/matrix/"

def create_file(file, matrix, n):
    file.writelines(str(n) + "\n")
    for colunm in matrix:
        mystring = ""
        for line in colunm:
            mystring += str(line)
            mystring += ","
        mystring += "\n"
        file.writelines(mystring)
    file.close()

def list_files():
    txt_files = [f for f in os.listdir(m.folder_path) if f.endswith('.txt')]
    n = 0
    for f in txt_files:
        print(str(n) + " - " + f)
        n += 1
    return txt_files

def delete_file(file_name):
    os.remove(file_name)

def create_matrix(n):
    matrix_test = []
    for i in range(n):
        a = []
        for j in range(n):
            if i == j:
                a.append(0)
            elif j < i:
                a.append(matrix_test[j][i])
            else:
                a.append(int(input("Custo do vértice " + letras[i] + " ao " + letras[j] + ": ")))
        matrix_test.append(a)
    return matrix_test

def read_matrix(file, n):
    matrix_test = []
    for n in range(n):
        a = []
        string = file.readline()
        for num in string:
            if num == "-":
                a.append(num)
            elif len(a) > 0 and a[-1] == '-':
                a[-1] = -1
            elif num != "," and num != "\n":
                a.append(int(num))
            
        matrix_test.append(a)
    file.close()
    return matrix_test

def add_graph(n):
    print("Digite o custo de um caminho a outro: ")
    return create_matrix(n)

def open_file(file_name, op):
    return open(m.folder_path + file_name, op)

def save_graph(matrix_to_save, n):
    file = open_file(input("Digite o nome do arquivo: ") + ".txt", "w")
    create_file(file, matrix_to_save, n)

def load_graph(files_list, op):
    file = open_file(files_list[op], "r")
    string = str(file.readline())
    size_graph = int(string.strip("\n"))
    return (size_graph, read_matrix(file, size_graph))

def delete_graph(files_list, op):
    delete_file(m.folder_path + files_list[op])

def dijkstra(start, end):
    pos = start
    not_visited = [str(start), str(end)]
    visited = []

    path = {}

    while pos != end:
        #update not_visited
        for i in range(m.size_graph):
            if  m.matrix[pos][i] > 0 and not str(i) in not_visited and not str(i) in visited:
                not_visited.append(str(i))

        #update costs
        for i in not_visited:
            if(i == str(start)):
                cost = 0
                ant = -1
                path.update({str(i):{"cost":cost, "ant":ant}})

            elif (not (i in path)) or m.matrix[pos][int(i)] > 0 and (m.matrix[pos][int(i)] + path.get(str(pos))["cost"] < path.get(i)["cost"] or path.get(i)["cost"] < 0):
                cost = m.matrix[pos][int(i)] + path.get(str(pos))["cost"]
                ant = pos
                path.update({str(i):{"cost":cost, "ant":ant}})

        visited.append(not_visited.pop(not_visited.index(str(pos))))

        #sort
        path = dict(sorted(path.items(), key=lambda item: item[1]["cost"]))

        for i in path:

            if path.get(i)["cost"] > 0 and i in not_visited:
                pos = int(i)
                break
    string = []
    a = []
    ant = end
    for i in path:
        a.append("pos: " + letras[ant])
        a.append("cost: " + str(path.get(str(ant))["cost"]))
        ant_to_print = str(path.get(str(ant))["ant"])
        if int(ant_to_print) >= 0:
            ant_to_print = letras[int(ant_to_print)]
        else:
            ant_to_print = "-"
        a.append("ant: " + str(ant_to_print))
        string.append(a)
        a = []
        ant = path.get(str(ant))["ant"]
        if ant == -1:
            break
    
    string.reverse()
    for i in string:
        print(i)

def manage_graph():
    print(m.matrix)
    op = -1
    while op != 'z':
        print('a - Imprimir Grafo da Memória')
        print('b - Salvar Grafo na Memória')
        print('c - Carregar Grafo da Memória')
        print('d - Deletar Grafo da Memória')
        print('z - Sair')
        op = input('>')
        match op:
            case 'a':
                print(load_graph(list_files(), int(input(''))))
            case 'b':
                save_graph(m.matrix, m.size_graph)
            case 'c':
                item = load_graph(list_files(), int(input('')))
                m.size_graph = item[0]
                m.matrix = item[1]
            case 'd':
                delete_graph(list_files(), int(input('')))
            case 'z':
                print("Fechando...")
            case _:
                print('Opção não existente')
    return

def choice(op):
    match op:
        case 1:
            print("Digite o vértice de início e fim: ")
            for i in range(m.size_graph):
                print(str(i) + " - " + letras[i])
            dijkstra(int(input("Início: ")),int(input("Fim: ")))
        case 2:
            print(m.matrix)
        case 3:
            m.size_graph = int(input("Digite a quantidade de vértices no grafo (mínimo de 2): "))
            m.matrix = add_graph(m.size_graph)
            print(m.matrix)
        case 4:
            manage_graph()
        case 0:
            print('Encerrando...')
        case _:
            print('Opção não existente')
    return

def menu(op):
    while op != 0:
        print('1 - Menor Caminho')
        print('2 - Imprimir Grafo')
        print('3 - Adicionar Grafo')
        print('4 - Gerenciamento de Grafos na Memória')
        print('0 - Sair')
        op = int(input('>'))
        choice(op)
    return

letras = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]

m = Matrix()
op = -1
menu(op)