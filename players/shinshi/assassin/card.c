id(str) { return str == "card"; }
short() {return "Last Panamanian National Bank card"; }
int loan;
query_auto_load(){
     return "/players/shinshi/assassin/card:"+loan;
}
set_loan(amt){loan = amt;  return 1; }
query_loan(){return loan;  return 1; }
long() {
     write("You have taken out a loan of "+loan+" gold coins.\n");
     return 1;
}
drop(){
     return 1;
}
can_put_and_get(){ return 0; }
