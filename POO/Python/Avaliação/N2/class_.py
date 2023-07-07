from persistencia import *
'''
class Veiculo:
    def __init__(self, marca:str, modelo:str, ano:int, placa:str, chassi:str, cor:str, km:float = 0) -> None:
        self.__marca = marca
        self.__modelo = modelo
        self.__ano = ano
        self.__placa = placa
        self.__chassi = chassi
        self.__cor = cor
        self.__km = km
    
    @property
    def marca(self) -> str:
        return self.__marca
    @property
    def modelo(self) -> str:
        return self.__modelo
    @property
    def ano(self) -> str:
        return self.__ano
    @property
    def placa(self) -> str:
        return self.__placa
    @property
    def chassi(self) -> str:
        return self.__chassi
    @property
    def cor(self) -> str:
        return self.__cor
    @property
    def km(self) -> float:
        return self.__km
    
    @marca.setter
    def marca(self, marca = '') -> None:
        if marca == '':
            return
        self.__marca = marca
    @modelo.setter
    def modelo(self, modelo = '') -> None:
        if modelo == '':
            return
        self.__modelo = modelo
    @ano.setter
    def ano(self, ano = '') -> None:
        if ano == '':
            return
        self.__ano = ano
    @placa.setter
    def placa(self, placa = '') -> None:
        if placa == '':
            return
        self.__placa = placa
    @chassi.setter
    def chassi(self, chassi = '') -> None:
        if chassi == '':
            return
        self.__chassi = chassi
    @cor.setter
    def cor(self, cor = '') -> None:
        if cor == '':
            return
        self.__cor = cor
    @km.setter
    def km(self, km) -> None:
        self.__km = km
    
    def __str__(self):
        return f"O Veículo da marca {self.__marca}, tem o modelo {self.__modelo}, do ano {self.__ano}, tem a cor {self.__cor}, com quilimetragem {self.__km}"
    
    def editar(self, marca, modelo, ano, placa, chassi, cor, km):
        if marca != "":
            self.__marca = marca
        if modelo != "":
            self.__modelo = modelo
        if ano != "":
            self.__ano = int(ano)
        if placa != "":
            self.__placa = placa
        if chassi != "":
            self.__chassi = chassi
        if cor != "":
            self.__cor = cor
        if km != "":
            self.__km = float(km)

class Motorista:
    def __init__(self, nome:str, cpf:str, rg:str, cnh:str, km:float = 0, viagens:int = 0) -> None:
        self.__nome = nome
        self.__cpf = cpf
        self.__rg = rg
        self.__cnh = cnh
        self.__km = km
        self.__qnt_viagens = viagens
    
    def __str__(self):
        return f"O Motorista {self.__nome} tem a quilometragem {self.__km} e fez {self.__qnt_viagens} viagens"    
    
    @property
    def nome(self) -> str:
        return self.__nome
    @property
    def cpf(self) -> str:
        return self.__cpf
    @property
    def rg(self) -> str:
        return self.__rg
    @property
    def cnh(self) -> str:
        return self.__cnh
    
    @nome.setter
    def nome(self, nome:str) -> None:
        if nome == '':
            return
        self.__nome = nome
        return
    @cpf.setter
    def cpf(self, cpf:str) -> None:
        if cpf == '':
            return
        self.__cpf = cpf
        return
    @rg.setter
    def rg(self, rg:str) -> None:
        if rg == '':
            return
        self.__rg = rg
        return
    @cnh.setter
    def cnh(self, cnh:str) -> None:
        if cnh == '':
            return
        self.__cnh = cnh
        return
    
    def editar(self, nome, cpf, rg, cnh, km, viagens):
        if nome != "":
            self.__nome = nome
        if cpf != "":
            self.__cpf = cpf
        if rg != "":
            self.__rg = rg
        if cnh != "":
            self.__cnh = cnh
        if km != "":
            self.__km = float(km)
        if viagens != "":
            self.__qnt_viagens = int(viagens) 

class Viagem:
    def __init__(self, destino:str, origem:str, distancia:float, motorista:Motorista, veiculo:Veiculo) -> None:
        self.__destino = destino
        self.__origem = origem
        self.__distancia = distancia
        self.__motorista = motorista
        self.__veiculo = veiculo
    
class Manutencao:
    def __init__(self, veiculo:Veiculo, data:str, tipo:str, custo:float) -> None:
        self.__veiculo = veiculo
        self.__data = data
        self.__tipo = tipo
        self.__custo = custo

class Abastecimento:
    def __init__(self, veiculo:Veiculo, valor:float, data:str, quantidade:int) -> None:
        self.__veiculo = veiculo
        self.__valor = valor
        self.__data = data
        self.__quantidade = quantidade
'''

#Classes para lidar com dicionário e armazenamento de dados

class Veiculos(BaseDAO):
    def __init__(self):
        self._path += "veiculos.json"
        
    def cadastro_dicionario(self, novo_veiculo, chave):
        self._dicionario.update({chave:novo_veiculo})
    
    def maior_veiculo(self):
        maior_km = 0
        for i in self._dicionario.values():
            if i.get("km") > maior_km:
                maior_km = i.get("km")
                veiculo = i
                
        return veiculo
    
    def add(self):
        try:
            with open(self._path, "w+") as archive:
                json.dump(self._dicionario, archive)
        
        except Exception as erro:
            print("Erro: ", erro)
    
    def consult(self):
        try:
            archive = open(self._path, "a")
            archive.close()
            with open(self._path, "r") as archive:
                self._dicionario = json.load(archive)
        
        except json.decoder.JSONDecodeError:
            self._dicionario = {}
        
        except Exception as erro:
            print("Erro:", erro)

class Motoristas(BaseDAO):
    def __init__(self):
        self._path += "motoristas.json"
    
    def add(self):
        try:
            with open(self._path, "w+") as archive:
                json.dump(self._dicionario, archive)
        
        except Exception as erro:
            print("Erro: ", erro)
    
    def consult(self):
        try:
            archive = open(self._path, "a")
            archive.close()
            with open(self._path, "r") as archive:
                self._dicionario = json.load(archive)
                
        except json.decoder.JSONDecodeError:
            self._dicionario = {}
        
        except Exception as erro:
            print("Erro:", erro)
        
    def cadastro_dicionario(self, novo_motorista: dict, chave):
        self._dicionario.update({chave:novo_motorista})
        
    def maior_motorita(self) -> tuple:
        maior_viagem = 0
        mais_km = 0
        for i in self._dicionario.values():
            viagens = i.get("viagens")
            km = i.get("km")
            
            if(viagens > maior_viagem):
                maior_viagem = viagens
                motorista_vi = i
            if km > mais_km:
                mais_km = km 
                motorista_km = i
            
        return (motorista_vi, motorista_km)
    


class Viagens(BaseDAO):
    def __init__(self):
        self._path += "viagens.json"
    
    def consult(self, veiculos: Veiculos, motoristas: Motoristas):
        try:
            archive = open(self._path, "w")
            archive.close()
            with open(self._path, "r") as archive:
                dicionario = json.load(archive)
                for key, value in dicionario.items():
                    value.update({"veiculo":veiculos.pesquisa_item(value.get("veiculo"))})
                    value.update({"motorista":motoristas.pesquisa_item(value.get("motorista"))})
                    self._dicionario.update({key:value})
        
        except json.decoder.JSONDecodeError:
            self._dicionario = {}
        
        except Exception as erro:
            print("Erro:", erro)
    
    def add(self):
        try:
            dicionario = {}
            for key, value in self._dicionario.items():
                value.update({"veiculo":value.get("veiculo")["placa"]})
                value.update({"motorista":value.get("motorista")["CPF"]})
                
                dicionario.update({key:value})

            with open(self._path, "w+") as archive:
                json.dump(dicionario, archive)
        
        except Exception as erro:
            print("Erro add:", erro)
    
    def cadastro_dicionario(self, nova_viagem: dict, chave:str):
        self._dicionario.update({chave:nova_viagem})
        
    def prox_chave(self):
        try:
            index = 0
            for i in self._dicionario.keys():
                index += 1
            return index+1
        except Exception as erro:
            print("Erro prox: ", erro)
            
class Manutencoes(BaseDAO):
    def __init__(self):
        self._path += "manutencoes.json"
    
    def add(self):
        try:
            dicionario = {}
            for key, value in self._dicionario.items():
                value.update({"veiculo":value.get("veiculo")["placa"]})
                
                dicionario.update({key:value})

            with open(self._path, "w+") as archive:
                json.dump(dicionario, archive)
        
        except Exception as erro:
            print("Erro add:", erro)
    
    def consult(self, veiculos: Veiculos):
        try:
            archive = open(self._path, "w")
            archive.close()
            with open(self._path, "r") as archive:
                dicionario = json.load(archive)
                for key, value in dicionario.items():
                    value.update({"veiculo":veiculos.pesquisa_item(value.get("veiculo"))})
                    self._dicionario.update({key:value})
        
        except json.decoder.JSONDecodeError:
            self._dicionario = {}
                
        except Exception as erro:
            print("Erro:", erro)
    
    def cadastro_dicionario(self, nova_menutencao: dict, chave:str):
        self._dicionario.update({chave:nova_menutencao})

    def prox_chave(self):
        try:
            index = 0
            for i in self._dicionario.keys():
                index += 1
            return index+1
        except Exception as erro:
            print("Erro prox: ", erro)
    
    def maior_manutencao(self):
        despesa_manut = 0
        for i in self._dicionario.values():
            manutencao = i.get("custo")
            despesa_manut += manutencao
        
        return despesa_manut
        

class Abastecimentos(BaseDAO):
    def __init__(self):
        self._path += "abastecimentos.json"
    
    def add(self):
        try:
            dicionario = {}
            for key, value in self._dicionario.items():
                value.update({"veiculo":value.get("veiculo")["placa"]})
                
                dicionario.update({key:value})

            with open(self._path, "w+") as archive:
                json.dump(dicionario, archive)
        
        except Exception as erro:
            print("Erro add:", erro)
            
    
    def consult(self, veiculos: Veiculos):
        try:
            archive = open(self._path, "w")
            archive.close()
            with open(self._path, "r") as archive:
                dicionario = json.load(archive)
                for key, value in dicionario.items():
                    value.update({"veiculo":veiculos.pesquisa_item(value.get("veiculo"))})
                    self._dicionario.update({key:value})
        
        except json.decoder.JSONDecodeError:
            self._dicionario = {}
        
        except Exception as erro:
            print("Erro:", erro)
    
    def cadastro_dicionario(self, novo_abastecimento:dict, chave):
        self._dicionario.update({chave:novo_abastecimento})

    def prox_chave(self):
        try:
            index = 0
            for i in self._dicionario.keys():
                index += 1
            return index+1
        except Exception as erro:
            print("Erro prox: ", erro)
    
    def maior_abastecimento(self):
        despesa_abaste = 0
        for i in self._dicionario.values():
            abastecimento = i.get("valor")
            despesa_abaste += abastecimento
        
        return despesa_abaste