from abc import ABC, abstractclassmethod


class BaseDAO(ABC):
    @abstractclassmethod
    def add():...

    @abstractclassmethod
    def find():...

    @abstractclassmethod
    def editar():...

    @abstractclassmethod
    def deletar():...