#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "merchant";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A merchant selling blades and armor";
        }
long(){
write("An burley looking merchant with a cart full of blades and armor.\n"+
  "He will let you see a 'list' of what he has, so you can 'buy #' from him.\n");
        }

list()  {
write("The merchant is selling:\n"+
 pad("",10)+" "+pad("1) A short sword",28)+" :  200 golden coins\n"+
 pad("",10)+" "+pad("2) A sword",28)+" :  250 golden coins\n"+
 pad("",10)+" "+pad("3) A fine steel longsword",28)+" :  375 golden coins\n"+
 pad("",10)+" "+pad("4) A bastard sword",28)+" :  1500 golden coins\n"+
 pad("",10)+" "+pad("5) A wooden shield",28)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("6) A black shield",28)+" :  75 golden coins\n"+
 pad("",10)+" "+pad("7) A suit of 1/2 chain",28)+" :  300 golden coins\n"+
 pad("",10)+" "+pad("8) A suit of chainmail",28)+" :  700 golden coins\n"+
 "\n");
     return 1;
}

init() {
 add_action("buy","buy");
 add_action("list","list");
 add_action("kill","kill");
}

kill(str)  {
if(str == "merchant")  {
  write("The city guard will not let you.\n");
say(tp+" tries to attack the merchant, but is stopped by the city guard.\n");
  return 1;
        }
        }

buy(str) {
int cost, value;
object thing;
if (!str){
 write("Buy what?\n");
 return 1;
}
 if (str == "1")  {
   write("You buy a short sword.\n");
   value = 200;
if(TPM < value) {write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
thing = clone_object("/players/saber/weapons/ssword.c");
}
else if (str == "2")  {
  write("You buy a sword.\n");
   value = 250;
if(TPM < value) {write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/weapons/sword.c");
}
else if (str == "3")  {
  write("You buy a fine steel longsword.\n");
  value = 375;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/weapons/longsword.c");
}
else if (str == "4")  {
  write("You buy a bastard sword.\n");
  value = 1500;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/weapons/bastard.c");
}
else if (str == "5")  {
  write("You buy a wooden shield.\n");
  value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/wshield.c");
}
else if (str == "6")  {
   write("You buy a black shield.\n");
   value = 75;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/bshield.c");
}
else if (str == "7")  {
  write("You buy a suit of 1/2 chain.\n");
  value = 300;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/halfchain2.c");
}
else if (str == "8")  {
  write("You buy a suit of chainmail.\n");
  value = 700;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/chainmail.c");
}
else {
write("The merchant says: What do you want to buy?\n");
 return 1;
}

if (call_other(this_player(), "query_money", 0) < value) {
  write("That costs "+value+" gold coins, which you don't have.\n");
  return 1;
}
if(!this_player()->add_weight(thing->query_weight())) {
  write("You can not carry that item.\nNO SALE\n");
  destruct(thing);
return 1; }
cost = value;
 write("You play "+cost+" coins for a number "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " buys a "+str+".\n");
 move_object(thing,this_player());
  call_other(this_player(), "add_money", - cost);
 return 1;
}
