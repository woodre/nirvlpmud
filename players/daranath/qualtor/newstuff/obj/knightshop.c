#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

/*
short() { return "A shop sign listing goods offered"; }
*/
long(){
write("Items for sale at Cotrone's Weapon and Armor Shop:\n\n"+
 "  250 gold coins for A Chain Coif\n"+
 "  250 gold coins for A Small Shield\n"+
 "  450 gold coins for A surcoat of Qual'tor\n"+
 "  450 gold coins for A signet ring from Qual'tor\n"+
 "  450 gold coins for A pair of Armored Boots\n"+
 "  600 gold coins for A Large Shield\n"+
 "  900 gold coins for A suit of simple Chainmail\n"+
 " 1200 gold coins for A Crusader Blade\n"+
 " 1850 gold coins for A suit of Guardian Platemail\n"+
 "\n");
}

init() {
 add_action("buy","buy");
}

buy(str) {
int cost, value;

if(!present("cotrone")){
write("Cotrone must be off keeping the peace somewhere. Please come back later.\n");
  return 1;
}
if (!str){
 write("Buy what?\n");
 return 1;
}
else if (str == "coif")  {
  write("Cotrone reaches under the counter and hands you a chain coif.\n");
  value = 250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/chain_coif.c"),this_player());
}
else if (str == "shield" || str == "small shield")  {
  write("Cotrone pulls a small shield from the wall and hands it to you.\n");
  value = 250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/sm_shield.c"),this_player());
}
else if (str == "boots") {
  write("Cotrone heads to a large wooden case and brings back a pair of boots.\n");
  value = 450;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/arm_boots.c"),this_player());
}
else if (str == "lgshield" || str == "large shield")  {
  write("Cotrone nods and pulls a large shield down from the back wall.\n");
   value = 600;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/lg_shield.c"),this_player());
}
else if (str == "ring" || str == "signet ring" || str == "qualtor ring")  {
  write("Cotrone pulls a small box out from the counter and hands you a ring.\n");
   value = 450;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/signet1.c"),this_player());
}
else if (str == "coat" || str == "coat of arms") {
  write("Cotrone nods, then hands you the symbol of Qual'tors guardsmen.\n");
   value = 450;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/surcoat1.c"),this_player());
}
else if (str == "simple" || str == "chainmail")  {
  write("Cotrone pulls out a suit of simple chainmail for you.\n");
   value = 900;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/simple_chain.c"),this_player());
}
else if (str == "blade" || str == "crusader" || str == "crusader blade") {
  write("Cotrone pulls down the weapon of Qual'tor ...  the crusader blade!\n");
   value = 1200;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/weps/crusader.c"),this_player());
}
else if (str == "plate" || str == "guardian" || str == "guardian plate") {
  write("Cotrone leaves into the back room, then comes back with a suit of armor.\n");
   value = 1850;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/guardian.c"),this_player());
}
else {
write("Cotrone asks: What do you want to buy?\n"+
      "usage: buy coif, shield, surcoat, ring, boots, large, chainmail, blade or guardian\n");
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
