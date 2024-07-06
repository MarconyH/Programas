type Peso = Float
type Idade = Int

type Pessoa = (String, Idade, Peso, String)


f_joao, f_maria :: Pessoa

f_joao = ("João Pedro", 19, 75.45, "Basquete")
f_maria = ("Maria Eduarda", 22, 80.5, "Vôlei")

select_nome (n, i, p, e) = n
select_idade (n, i, p, e) = i
select_peso (n, i, p, e) = p
select_esporte (n, i, p, e) = e