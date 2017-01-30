/* gpbank.c: guild point bank */
#define MASTER  "/players/wizardchild/closed/logger/masterob"
#define MAXTAKE   30
#define MAXGP   1000
int amount;
short() {
  return "A guild point bank ("+amount+" gp)";
}
long()  {
  write("This very simple mechanism can hold physical strength for you, or can keep\n");
  write("physical strength that you donate for other players. Be warned, however, if\n");
  write("this is abused, then it will be lost.\n");
  write("Type \"donate <amt>\" to donate gp, or \"borrow <amt>\" to borrow gp.\n");
  return 1;
}
id(str) { return str == "bank" || str == "guild bank" || str == "guild point bank"; }
reset(arg) {
  if(arg)
    return ;
  amount = 40;
}
init() {
  add_action("donate", "donate");
  add_action("borrow", "borrow");
}
add_gp(x)  {  /* returns amount added */
  int old;
  old = amount;
  amount += x;   
  if(amount < 0) 
    amount = 0;
  if(amount > MAXGP)
    amount = MAXGP;
  return (amount-old);
}
query_gp()      { return amount;  }
query_maxtake() { return MAXTAKE; }
borrow(str) {
  int a;
  object gob;
  if(!str || !sscanf(str, "%d", a)) {
    write("Usage: borrow <amt>\n");
    return 1;
  }
  if(a <= 0) {
    write("That is not a valid number.\n");
    return 1;
  }
  if(a > MAXTAKE) {
    write("You cannot take that many guild points at one time.\n");
    return 1;
  }
  if(a > amount) {
    write("There are not that many guild points.\n");
    return 1;
  }
  gob = present("logger pack", this_player());
  if(!gob) return ;
  if(gob->query_max_gpoints() - gob->query_gpoints() < a) {
    write("You cannot take that many guild points.\n");
    return 1;
  }
  if(add_gp(-a) != -a) 
    write("Error withdrawling guild points.\n");
  else {  
    write("You borrow "+a+" guild points.\n");
    MASTER->lmaster(this_player()->query_name()+" borrows "+a+" guild points.\n");
    gob->add_gpoints(a);
  }
  return 1;
}
donate(str) {
  int a;
  object gob;
  if(!str || !sscanf(str, "%d", a)) {
    write("Usage: donate <amt>\n");
    return 1;
  }
  if(a <= 0) {
    write("That is not a valid number.\n");
    return 1;
  }
  if(a+amount > MAXGP) {
    write("The bank cannot hold that many guild points.\n");
    return 1;
  }
  gob = present("logger pack", this_player());
  if(!gob) return ;
  if(gob->query_gpoints() < a) {
    write("You do not have that many guild points.\n");
    return 1;
  }
  if(add_gp(a) != a) 
    write("Error donating guild points.\n");
  else {
    write("You donate "+a+" guild points.\n");
    gob->add_gpoints(-a);
    MASTER->lmaster(this_player()->query_name()+" donates "+a+" guild points.\n");
  }
  return 1;
}
