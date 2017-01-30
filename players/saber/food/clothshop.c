#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "merchant";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A merchant selling leather goods";
        }
long(){
write("An seductive looking merchant with a cart full of leather goods.\n"+
  "He will let you see a 'list' of what he has, so you can 'buy #' from him.\n");
        }

list()  {
write("The merchant is selling:\n"+
 pad("",10)+" "+pad("1) Leather boots",33)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("2) Stiletto heeled leather boots",33)+" :  75 golden coins\n"+
 pad("",10)+" "+pad("3) A choker",33)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("4) A black cloak",33)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("5) Leather gloves",33)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("6) Fingerless leather gloves",33)+" :  75 golden coins\n"+
 pad("",10)+" "+pad("7) A leather jacket",33)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("8) A studded leather jacket",33)+" :  250 golden coins\n"+
 pad("",10)+" "+pad("9) Skintight leather armor",33)+" :  300 golden coins\n"+
 "\n");
     return 1;
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
 add_action("buy");
   add_verb("buy");
   add_action("list");
   add_verb("list");
  add_action("kill");
   add_verb("kill");
#else
  add_action("buy", "buy");
  add_action("list", "list");
  add_action("kill", "kill");
#endif
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
   write("You buy leather boots.\n");
   value = 50;
if(TPM < value) {write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
thing = clone_object("/players/saber/armor/lboots.c");
}
else if (str == "2")  {
  write("You buy stiletto heeled leather boots.\n");
   value = 75;
if(TPM < value) {write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/slboots.c");
}
else if (str == "3")  {
  write("You buy a choker.\n");
  value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/choker.c");
}
else if (str == "4")  {
  write("You buy a black cloak.\n");
  value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/blackcloak.c");
}
else if (str == "5")  {
  write("You buy a pair of leather gloves.\n");
  value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/lgloves.c");
}
else if (str == "6")  {
   write("You buy a pair of fingerless leather gloves.\n");
   value = 75;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/finger.c");
}
else if (str == "7")  {
  write("You buy a leather jacket.\n");
  value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/ljacket.c");
}
else if (str == "8")  {
  write("You buy a studded leather jacket.\n");
  value = 250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/stljacket.c");
}
else if (str == "9")  {
  write("You buy a suit of skintight leather armor.\n");
  value = 300;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/skinleather.c");
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
