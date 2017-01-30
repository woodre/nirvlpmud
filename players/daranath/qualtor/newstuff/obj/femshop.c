#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

/*
short() { return "A shop sign listing goods offered"; }
*/
long(){
write("Items for sale at Chandra's Shop:\n\n"+
 "Silk Rose Sash .................   100 gold coins\n"+
 "Crushed Velvet Dress ...........   250 gold coins\n"+
 "Spiked Heeled Boots ............   250 gold coins\n"+
 "Lavender Vest ..................   250 gold coins\n"+
 "Lavender Skirt .................   300 gold coins\n"+
 "A box of chocolates ............   600 gold coins\n"+
 "Skintight Leather Catsuit ......  1000 gold coins\n"+
 "Mace of the Black Rose .........  1000 gold coins\n"+
 "Mithril Chainmail ..............  1250 gold coins\n"+
 "\n");
}

init() {
 add_action("buy","buy");
}

buy(str) {
int cost, value;

if(!present("chandra")){
write("Chandra is not here to take your order. Please come back later.\n");
  return 1;
}
if (!str){
 write("Buy what?\n");
 return 1;
}
else if (str == "sash")  {
  write("Chandra reaches down under the counter and hands you a white silk sash.\n");
   value = 100;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/sash.c"),this_player());
}
else if (str == "dress" || str == "velvet dress")  {
  write("Chandra reaches behind the counter and hands you a folded dress.\n");
  value = 250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/dress1.c"),this_player());
}
else if (str == "boots") {
  write("Chandra reaches behind the counter and hands you a pair of spiked boots.\n");
  value = 250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/spiked_boots.c"),this_player());
}
else if (str == "catsuit" || str == "suit")  {
  write("Chandra smirks as you ask for the Catsuit. She leave for a moment, heading\n"+
        "into the back room, then returns with the suit for you.\n");
   value = 1000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/catsuit.c"),this_player());
}
else if (str == "vest" || str == "lavender vest" || str == "lav vest")  {
   write("You buy a lavender vest.\n");
   value = 250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/lav_vest.c"),this_player());
}
else if (str == "skirt" || str == "lavender skirt") {
   write("You buy a lavender skirt.\n");
   value = 300;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/lav_skirt.c"),this_player());
}
else if (str == "mithril" || str == "chainmail")  {
write("Chandra puts a suit of light, supple chainmail upon the counter for you.\n");
   value = 1250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/mithril.c"),this_player());
}
else if (str == "mace" || str == "rose mace" || str == "black rose mace") {
write("Chandra sets a Black Rose Mace up upon the counter with a heavy 'thud'.\n");
   value = 1000;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/weps/rose_mace.c"),this_player());
}
else if (str == "box" || str == "chocolates" || str == "box of chocolates") {
write("Chandra smiles warmly and hands you a box of chocolates.\n");
   value = 600;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/heals/chocolates.c"),this_player());
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
