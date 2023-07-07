class Item:
  def __init__(self, nome:str, preco:str)->None:
    self.__nome = nome
    self.__preco = preco

  def __str__(self):
    return f"Nome: {self.__nome}, Preco: {self.__preco}"

class Pedido:
  def __init__(self, numero:int, data:str, itens:list[Item] = []):
    self.__numero = numero
    self.__data = data
    self.__itens = itens
  
  def listar_item(self)->list[Item]:
    for i in self.__itens:
      print(i)
  
  def adicionar_item(self, item:Item)->None:
    self.__itens.append(item)

  def __str__(self):
    return f"{self.__numero}, {self.__data}"

class Cliente:
  def __init__(self, nome:str, email:str, pedidos:list[Pedido] = [])->None:
    self.__nome = nome
    self.__email = email
    self.__pedidos = pedidos

  def listar_pedidos(self)->list[Pedido]:
    for i in self.__pedidos:
      print(i)

  def adicionar_pedido(self, pedido:Pedido)->None:
    self.__pedidos.append(pedido)

  @property 
  def nome(self)->str:
    return self.__nome
  
  @nome.setter
  def nome(self, nome:str)->None:
    self.__nome = nome

  @property
  def email(self)->str:
    return self.__email
  
  @email.setter
  def email(self, email:str)->None:
    self.__email = email


###


# Cadastrando um cliente
cliente1 = Cliente("João", "joao@example.com")

# Criando um pedido para o cliente
pedido1 = Pedido(1, "2023-05-16")

# Adicionando produtos ao pedido
produto1 = Item("Camiseta", 29.99)
produto2 = Item("Calça", 49.99)

pedido1.adicionar_item(produto1)
pedido1.adicionar_item(produto2)

# Associando o pedido ao cliente
cliente1.adicionar_pedido(pedido1)

print(pedido1)

# Exibindo os detalhes do cliente, seus pedidos e os produtos de cada pedido
print("Detalhes do Cliente:")
print(f"Nome: {cliente1.nome}")
print(f"E-mail: {cliente1.email}")

print("\nPedidos do Cliente:")
cliente1.listar_pedidos()