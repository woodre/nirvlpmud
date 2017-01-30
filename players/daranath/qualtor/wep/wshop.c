#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

short() { return "A shop sign"; }
long(){
write("Items for sale at the Weapon Shop in Qual'tor:\n"+
 "             You may buy:\n"+
 "           A wooden club            :   50 gold coins\n"+
 "           A steel scimitar         :  125 gold coins\n"+
 "           A dwarven warhammer      :  250 gold coins\n"+
 "           A dwarven mining pick    :  300 gold coins\n"+
 "           A black rose dagger      :  700 gold coins\n"+
 "           A silver short sword     :  800 gold coins\n"+
 "           Crusader blade           : 1200 gold coins\n"+
 "           A wicked scourge         : 2000 gold coins\n"+
 "           IronWood quarterstaff    : 2250 gold coins\n"+
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
else if (str == "scourge")  {
   write("You buy a wicked scourge.\n");
   value = 2000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/wep/scourge2.c"),this_player());
}
else if (str == "club" || str == "wooden club")  {
  write("You buy a wooden club.\n");
   value = 50;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/wep/wood_club.c"),this_player());
}
else if (str == "warhammer") {
  write("You buy a dwarven warhammer.\n");
  value = 250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/wep/warhammer.c"),this_player());
}
else if (str == "mining pick" || str == "pick")  {
   write("You buy a dwarven mining pick.\n");
   value = 300;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/wep/min_pick.c"),this_player());
}
else if (str == "sword" || str == "silver sword" || str == "short sword")  {
   write("You buy a silver short sword.\n");
   value = 800;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/wep/sil_sword.c"),this_player());
}
else if (str == "scimitar" || str == "steel scimitar") {
   write("You buy a steel scimitar.\n");
   value = 125;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/wep/scimitar.c"),this_player());
}
else if (str == "crusader blade" || str == "blade")  {
   write("You buy a crusader blade.\n");
   value = 1200;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/obj/crusader.c"),this_player());
}
else if (str == "dagger" || str == "black rose" || str == "black rose dagger") {
   write("You buy a black rose dagger.\n");
   value = 700;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/wep/brose_dag.c"),this_player());
}
else if (str == "quarterstaff" || str == "ironwood quarterstaff")  {
  write("You buy an ironwood quarterstaff.\n");
  value = 2250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/wep/ironwood.c"),this_player());
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
 write("You play "+cost+" coins for a "+str+".\n");
 say(call_other(this_player(), "query_name", 0) + " buys a "+str+".\n");
  call_other(this_player(), "add_money", - cost);
 return 1;
}
