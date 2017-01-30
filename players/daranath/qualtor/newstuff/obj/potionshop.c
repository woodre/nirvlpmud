#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

/*
short() { return "A shop sign listing goods offered"; }
*/
long(){
write("Heals for sale at Randal's Apothecary:\n\n"+
 "Toadstool .... .................   180 gold coins\n"+
 "Grapeshot ......................   600 gold coins\n"+
 "Wheel of Cheese .... ...........   600 gold coins\n"+
 "Turkey Leg .....................   800 gold coins\n"+
 "Luminescent Slime ..............  1000 gold coins\n"+
 "Bottle of Red Wine .............  1200 gold coins\n"+
 "Tin of Healing Salve............  1200 gold coins\n"+
 "Jello Shot .....................  1800 gold coins\n"+
 "Dark Brandy ....................  1800 gold coins\n"+
 "Vial of Gelatinous Ooze ........  1800 gold coins\n"+
 "Potion of Healing .............. 10000 gold coins\n"+
 "\n");
}

init() {
 add_action("buy","buy");
}

buy(str) {
int cost, value;

if(!present("randal")){
write("Randal is not here to take your order, and you'll never find anything\n"+
      "within this mess. You better come back later.\n");
  return 1;
}
if (!str){
 write("Randal says: What do you want to buy?\n");
 return 1;
}
else if (str == "toad" || str == "toadstool")  {
write("Randal reaches into a large jar and hands you a toadstool.\n");
  value = 180;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/toadstool.c"),this_player());
}
else if (str == "ooze" || str == "gelatinous ooze")  {
write("Randal pours a small amount of ooze into a vial, then hands it to you.\n");
   value = 1800;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/gel_ooze.c"),this_player());
}
else if (str == "shot" || str == "jello" || str == "jello shot")  {
  write("Randal reaches into a cool storage area and pulls out a pack of jello shots.\n");
   value = 1800;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/jello_shot.c"),this_player());
}
else if (str == "brandy" || str == "flask") {
  write("Randal reaches under the counter and grabs a small flask.\n");
  value = 1800;
if(TPM<value) {write("You don't have have "+value+" coins.\n"); return 1; }
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/brandy.c"),this_player());
}
else if (str == "grape" || str == "grapeshot") {
write("Randal leaves into the vineyard. He comes back a moment later with grapeshot.\n");
   value = 600;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/grapeshot.c"),this_player());
}
else if (str == "luminescent slime" || str == "slime")  {
write("Randal reaches into a large, glowing jar and scoops out some slime for you.\n");
   value = 1000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/slime.c"),this_player());
}
else if (str == "cheese wheel" || str == "cheese")  {
   write("You buy a wheel of cheese.\n");
   value = 600;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/cheese.c"),this_player());
}
else if(str == "turkey" || str == "leg" || str == "turkey leg") {
  write("You buy a leg of delicious turkey.\n");
  value = 800;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/turkey.c"),this_player());
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
else if (str == "potion" || str == "healing potion") {
   write("You buy a powerful healing potion.\n");
   value = 10000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/obj/heal_potion.c"),this_player());
}
else {
write("Randal asks: What exactly do you want to buy?\n"+
      "usage: buy toad, grape, cheese, slime, wine, tin, jello, brandy, ooze or potion.\n");
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
