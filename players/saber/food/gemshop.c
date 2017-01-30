#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "merchant" || str == "jeweler";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A merchant selling gems";
        }
long(){
write("An pretty young merchant with a bag full of gems.\n"+
 "She will let you see a 'list' of what she has, so you can 'buy #' from her.\n");
        }

list()  {
write("The merchant is selling:\n"+
 pad("",10)+" "+pad("1) A Turquoise gem",25)+" :   10 golden coins\n"+
 pad("",10)+" "+pad("2) A Moonstone",25)+" :   50 golden coins\n"+
 pad("",10)+" "+pad("3) An Amber gem",25)+" :  100 golden coins\n"+
 pad("",10)+" "+pad("4) A Pearl",25)+" :  500 golden coins\n"+
 pad("",10)+" "+pad("5) An Opal",25)+" : 1000 golden coins\n"+
 pad("",10)+" "+pad("6) A Star Ruby",25)+" : 1000 golden coins\n"+
 pad("",10)+" "+pad("7) A Star Sapphire",25)+" : 1500 golden coins\n"+
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
   write("You buy a Turquoise gem.\n");
   value = 10;
if(TPM < value) {write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
thing = clone_object("/players/saber/gems/turquoise.c");
}
else if (str == "2")  {
  write("You buy a Moonstone.\n");
   value = 50;
if(TPM < value) {write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/gems/moonstone.c");
}
else if (str == "3")  {
  write("You buy an Amber gem.\n");
  value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/gems/amber.c");
}
else if (str == "4")  {
  write("You buy a Pearl.\n");
  value = 500;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/gems/pearl.c");
}
else if (str == "5")  {
  write("You buy a Opal.\n");
  value = 1000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/gems/opal.c");
}
else if (str == "6")  {
   write("You buy a Star Ruby.\n");
   value = 1000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/gems/ruby.c");
}
else if (str == "7")  {
  write("You buy a Star Sapphire.\n");
  value = 1500;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/gems/sapphire.c");
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
