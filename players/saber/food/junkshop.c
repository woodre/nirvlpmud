#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "merchant";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A merchant selling assorted items";
        }
long(){
write("An cheerful merchant with a sack full of assorted items.\n"+
  "He will let you see a 'list' of what he has, so you can 'buy #' from him.\n");
        }

list()  {
write("The merchant is selling:\n"+
 pad("",10)+" "+pad("1) An emoter device",25)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("2) A silver mirror",25)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("3) A joint of grass",25)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("4) A pillow",25)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("5) A red rose",25)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("6) A pair of sunglasses",25)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("7) A leather bullwhip",25)+" : 150 golden coins\n"+
 pad("",10)+" "+pad("8) A teddy bear",25)+" :  50 golden coins\n"+
 pad("",10)+" "+pad("9) A pregnancy test",25)+" : 500 golden coins.\n\n");
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
   write("You buy an emoter\n");
   value = 50;
if(TPM < value) {write("That costs "+value+" golden coins, which you don't have.\n"); return 1; }
thing = clone_object("/players/saber/stuff/emoter.c");
}
else if (str == "3")  {
  write("You buy a joint of grass.\n");
   value = 50;
if(TPM < value) {write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/grass.c");
}
else if (str == "2")  {
  write("You buy a silver mirror.\n");
  value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/mirror.c");
}
else if (str == "4")  {
  write("You buy a pillow.\n");
  value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/pillow.c");
}
else if (str == "5")  {
  write("You buy a red rose.\n");
  value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/rose.c");
}
else if (str == "6")  {
   write("You buy a pair of shades.\n");
   value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/shades.c");
}
else if (str == "7")  {
  write("You buy a leather bullwhip.\n");
  value = 150;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/weapons/whip.c");
}
else if (str == "8")  {
  write("You buy a teddy bear.\n");
  value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/bear.c");
}
else if(str == "9") {
  write("You buy a pregnancy test [coded by Laera].\n");
  value = 500;
if(TPM<value){write("You don't have "+value+" coins.\n"); return 1; }
thing = clone_object("/players/laera/personal/ptest.c");
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
