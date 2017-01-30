#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

short() { return "A shop sign"; }
long(){
write("Items for sale at the East Road Shop:\n"+
 "             You may buy:\n"+
 "           A red silk cape          :  100 gold coins\n"+
 "           A small shield           :  100 gold coins\n"+
 "           A pair of sandles        :  100 gold coins\n"+
 "           A cloak of shadows       :  250 gold coins\n"+
 "           A golden halo            :  250 gold coins\n"+
 "           A silver comb            :  275 gold coins\n"+
 "           Studded leather          :  300 gold coins\n"+
 "           A loaf of bread          :  350 gold coins\n"+
 "           Rat on a stick           :  450 gold coins\n"+
 "           Chainmail armor          :  650 gold coins\n"+
 "           A wheel of cheese        :  850 gold coins\n"+
 "           Bottle of dark red wine  : 1750 gold coins\n"+
 "           A tin of healing salve   : 1750 gold coins\n"+
 "           A sack of knucklebones   : 1750 gold coins\n"+
 "           A healing potion         :10000 gold coins\n"+
 "\n");
}

init() {
 add_action("buy");
   add_verb("buy");
}

buy(str) {
int cost, value;

if (!str){
 write("Buy what?\n");
 return 1;
}
else if (str == "cape")  {
   write("You buy a silken cape.\n");
   value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/red_cape.c"),this_player());
}
else if (str == "shield" || str == "small shield")  {
  write("You buy a small shield.\n");
   value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/sm_shield.c"),this_player());
}
else if (str == "sandles") {
  write("You buy a pair of sandles.\n");
  value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/sandles.c"),this_player());
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
else if (str == "comb" || str == "silver comb") {
   write("You buy a silver comb.\n");
   value = 275;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/sil_comb.c"),this_player());
}
else if (str == "studded leather" || str == "leather")  {
   write("You buy a suit of studded leather armor.\n");
   value = 300;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/stud_leathr.c"),this_player());
}
else if (str == "bread" || str == "loaf" || str == "loaf of bread") {
   write("You buy a loaf of bread.\n");
   value = 350;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/bread.c"),this_player());
}
else if (str == "rat" || str == "rat on a stick")  {
  write("You buy rat on a stick.\n");
  value = 450;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/rat_on_stick.c"),this_player());
}
else if (str == "chain" || str == "chainmail" || str == "chainmail armor") {
   write("You buy a suit of chainmail.");
   value = 650;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/chainmail.c"),this_player());
}
else if (str == "cheese wheel" || str == "cheese")  {
   write("You buy a wheel of cheese.\n");
   value = 850;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/cheese.c"),this_player());
}
else if (str == "wine" || str == "red wine")  {
   write("You buy a bottle of dark red wine.\n");
   value = 1750;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/redwine.c"),this_player());
}
else if (str == "salve" || str == "healing salve" || str == "tin") {
   write("You buy a tin of healing salve.\n");
   value = 1750;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/heal_salve.c"),this_player());
}
else if (str == "sack" || str == "knucklebones")  {
   write("You buy a sack of knucklebones.\n");
   value = 1750;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/kn_bones.c"),this_player());
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
