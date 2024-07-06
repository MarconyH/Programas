type Seq_Carat = String
type Nomes = (Seq_Carat, Seq_Carat, Seq_Carat, Seq_Carat)

f_nomes_est :: Nomes
f_nomes_est = ("Inverno", "Outono", "Primavera", "Verão")

select_inv (x,_,_,_) = x
select_out (_,x,_,_) = x
select_pri (_,_,x,_) = x
select_ver (_,_,_,x) = x