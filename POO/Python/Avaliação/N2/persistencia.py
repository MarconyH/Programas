import json
from abc import ABC, abstractclassmethod

class BaseDAO(ABC):
    _path = "dados/" 
    _dicionario = {}
    

        
    def pesquisa_item(self, chave):
        return self._dicionario.get(chave)
    
    def deletar_item(self, chave):
        self._dicionario.pop(chave)
        
    def nao_existe(self):
        if len(self._dicionario) == 0:
            return True
        return False

    def quantidade(self):
        return len(self._dicionario)
    
    @abstractclassmethod
    def cadastro_dicionario(self):...
    
    @abstractclassmethod
    def add(self) -> None:...
        
    @abstractclassmethod
    def consult(self) -> None:...
        
    