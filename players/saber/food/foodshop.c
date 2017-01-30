#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "merchant";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A merchant selling food, drink and magical healing";
        }
long(){
write("\n");
write("An crafty merchant with a sack full of assorted drink & food & magic healing.\n"+
  "He will let you see a 'list' of what he has, so you can 'buy #' from him.\n");
        }

list()  {
write("The merchant is selling:\n"+
 pad("",10)+" "+pad("1) A bottle of wine (1 sip)",30)+" :  150 golden coins\n"+
 pad("",10)+" "+pad("2) A rod of corpse process",30)+" :  350 golden coins\n"+
 pad("",10)+" "+pad("3) A loaf of bread",30)+" : 1250 golden coins\n"+
 pad("",10)+" "+pad("4) A bottle of wine (7 sips)",30)+" : 1750 golden coins\n"+
 pad("",10)+" "+pad("5) A coin of sustenance",30)+" : 1750 golden coins\n"+
 pad("",10)+" "+pad("6) A scroll of full heal",30)+" :10000 golden coins\n"+
 pad("",10)+" "+pad("7) A Magical diet pill",30)+" :  100 golden coins\n"+
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
   write("You buy a bottle of wine\n");
   value = 150;
if(TPM < value) {write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
thing = clone_object("/players/saber/food/wine.c");
}
else if (str == "2")  {
  write("You buy a rod of process corpse.\n");
   value = 350;
if(TPM < value) {write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/process.c");
}
else if (str == "3")  {
  write("You buy a loaf of bread.\n");
  value = 1250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/food/bread.c");
}
else if (str == "4")  {
  write("You buy a bottle of wine.\n");
  value = 1750;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/food/bigwine.c");
}
else if (str == "5")  {
  write("You buy a coin of sustenance.\n");
  value = 1750;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/food/icoin.c");
}
else if (str == "6")  {
   write("You buy a scroll of full heal.\n");
   value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/food/hscroll1.c");
}
else if (str == "7")  {
  write("You buy a magical diet pill.\n");
  value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/food/diet.c");
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
 write("You pay "+cost+" coins for a number "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " buys a "+str+".\n");
 move_object(thing,this_player());
  call_other(this_player(), "add_money", - cost);
 return 1;
}
