#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "machine";}
query_weight() {return 0;}
query_value() {return 1;}

short() { return "A New Vending Machine"; }
long(){
write("A temporary vending machine set up so items from Qual'tor could be\n"+
      "purchased during renovations.\n\n");
write("Items for sale at the Vending Machine:\n"+
 "             You may buy:\n"+
 "           A loaf of bread          :  250 gold coins\n"+
 "           A cloak of shadows       :  250 gold coins\n"+
 "           A golden halo            :  250 gold coins\n"+
 "           A wheel of cheese        :  600 gold coins\n"+
 "           A Silver Rapier          :  650 gold coins\n"+
 "           Black Rose Mace          : 1000 gold coins\n"+
 "           Bottle of dark red wine  : 1200 gold coins\n"+
 "           A tin of healing salve   : 1200 gold coins\n"+
 "           A sack of knucklebones   : 1200 gold coins\n"+
 "           A healing potion         :10000 gold coins\n"+
 "\n");
}

init() {
 add_action("buy","buy");
}

buy(str) {
int cost, value;

if (!str){
 write("Buy what?\n");
 return 1;
}
else if (str == "rapier" || str == "silver rapier")  {
  write("You buy a Silver Rapier.\n");
   value = 650;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/weps/sil_rapier.c"),this_player());
}
else if (str == "mace") {
  write("You buy a black rose mace.\n");
  value = 1000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/weps/rose_mace.c"),this_player());
}
else if (str == "shadow cloak" || str == "cloak")  {
   write("You buy a cloak of shadows.\n");
   value = 250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/sh_cloak.c"),this_player());
}
else if (str == "halo" || str == "golden halo" || str == "golden")  {
   write("You buy a golden halo.\n");
   value = 250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/halo.c"),this_player());
}
else if (str == "bread" || str == "loaf" || str == "loaf of bread") {
   write("You buy a loaf of bread.\n");
   value = 250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/bread.c"),this_player());
}
else if (str == "cheese wheel" || str == "cheese")  {
   write("You buy a wheel of cheese.\n");
   value = 600;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/cheese.c"),this_player());
}
else if (str == "wine" || str == "red wine")  {
   write("You buy a bottle of dark red wine.\n");
   value = 1200;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/red_wine.c"),this_player());
}
else if (str == "salve" || str == "healing salve" || str == "tin") {
   write("You buy a tin of healing salve.\n");
   value = 1200;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/heal_salve.c"),this_player());
}
else if (str == "sack" || str == "knucklebones")  {
   write("You buy a sack of knucklebones.\n");
   value = 1200;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/knucklebones.c"),this_player());
}
else if (str == "potion" || str == "healing potion") {
   write("You buy a powerful healing potion.\n");
   value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/heal_potion.c"),this_player());
}
else {
write("A voice asks: What do you want to buy?\n");
 return 1;
}

if (call_other(this_player(), "query_money", 0) < value) {
  write("That costs "+value+" gold coins, which you don't have.\n");
  return 1;
}

cost = value;
 write("You pay "+cost+" coins for a "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " buys a "+str+".\n");
  call_other(this_player(), "add_money", - cost);
 return 1;
}
