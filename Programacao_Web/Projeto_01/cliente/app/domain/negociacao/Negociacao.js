class Negociacao
{

    constructor(data, quantidade, valor)
    {
        this._data = data;
        this._quantidade = quantidade;
        this._valor = valor;
        //Object.freeze(this); //não permite que valores sejam alterados diretamente
    }
    //get
    volume()
    {
        return this._quantidade * this._valor;
    }

    data()
    {
        return new Date(this._data.getTime());
    }

    quantidade()
    {
        return this._quantidade;
    }

    valor()
    {
        return this._valor;
    }

    //set
    set_data(data)
    {
        this._data = data
    }

    set_quantidade(quantidade)
    {
        this._quantidade = quantidade
    }

    set_valor(valor)
    {
        this._valor = valor
    }

}