#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "merchant";}
query_weight() {return 0;}
query_value() {return 1;}

short()  { return "A merchant selling magic items";
        }
long(){
write("An old merchant with a sack full of magic items.\n"+
  "He will let you see a 'list' of what he has, so you can 'buy #' from him.\n");
        }

list()  {
write("The merchant is selling:\n"+
 pad("",10)+" "+pad("1) An emoter device",25)+" :   50 golden coins\n"+
 pad("",10)+" "+pad("2) An eternal torch",25)+" :  500 golden coins\n"+
 pad("",10)+" "+pad("3) A scroll of identify",25)+" :  150 golden coins\n"+
 pad("",10)+" "+pad("4) A rod corpse processor",25)+" :  350 golden coins\n"+
 pad("",10)+" "+pad("5) A ring of strength",25)+" : 1000 golden coins\n"+
 pad("",10)+" "+pad("6) A bag of holding",25)+" :  1500 golden coins\n"+
 pad("",10)+" "+pad("7) A gender bender",25)+" :10000 golden coins\n"+
 "\n");
     return 1;
}

init() {
  add_action("kill","kill");
  add_action("list","list");
  add_action("buy","buy");
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
else if (str == "2")  {
  write("You buy an eternal torch.\n");
   value = 500;
if(TPM < value) {write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/etorch.c");
}
else if (str == "3")  {
 /* Objects are not Allowed to Give out Hard Numbers! - Pavlik */
/* my scroll of identify used instead, 6.5.01 - Vertebraker */
/*
 write("Sorry, this item is out of stock.\n");
  return 1;
*/

/*
  write("You buy a rock of identify.\n");
  value = 150;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/idscroll.c");
*/

   write("You buy a scroll of identify.\n");
  value = 150;
   thing = clone_object("/players/vertebraker/misc/mage/items/id");
}
else if (str == "4")  {
  write("You buy a rod of processing.\n");
  value = 350;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/process.c");
}
else if (str == "5")  {
  write("You buy a ring of strength.\n");
  value = 1000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/armor/strring.c");
}
else if (str == "6")  {
   write("You buy a bag of holding.\n");
   value = 1500;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/mbag.c");
}
else if (str == "7")  {
  write("You buy a gender bender.\n");
  value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
thing = clone_object("/players/saber/stuff/bender.c");
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
