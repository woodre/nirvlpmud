#include <ansi.h>
#define TPM this_player()->query_money()
#define tp this_player()->query_name()

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

/*
short() { return "A shop sign listing goods offered"; }
*/
long(){
write("Items for sale here at Daranath's dirty little Secrets:\n\n"+
  " 250 gold -> A pair of silver handcuffs\n"+
  " 350 gold -> China doll mask\n"+
  " 500 gold -> Silver tongue piercing\n"+
  " 600 gold -> Slave's collar\n"+
  " 600 gold -> Cat 'o nine tails (weapon)\n"+
  " 750 gold -> Silver pendant\n"+
  " 800 gold -> Black leather corset\n"+
  "    "+HIY+"and coming soon...."+NORM+"\n"+
  "2250 gold -> Large purple dildo (weapon)\n\n"+
  "                      DISCLAIMER\n"+
  "The items in this store are of a humorous nature. Nothing purchased here\n"+
  "should be taken overly seriously. If you are offended by certain things, use\n"+
  "your head and DO NOT purchase them. If ANYONE here uses anything from this shop\n"+
  "to torture, humiliate or offend another player after being asked not too, I \n"+
  "will remove the item, and come down HARSHLY on the offending player.\n\n"+
  "        YOU HAVE BEEN WARNED ...   -Daranath\n\n"+
 "\n");
}

init() {
 add_action("buy","buy");
}

buy(str) {
int cost, value;

if(!present("dom")){
write("The mistress must be present to purchase toys, slave!\n");
  return 1;
}
if (!str){
write("Dominatrix snaps: Be clear on what you want, slave!\n");
 return 1;
}
else if (str == "mask" || str == "china mask")  {
write("Dominatrix gives you a sly grin, then hands over a white mask.\n");
  value = 350;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/doll_mask.c"),this_player());
}
else if (str == "collar" || str == "slave collar")  {
write("Dominatrix toss a leather collar upon the counter and demands: \n"+
      "Put it on right now, slave!\n");
   value = 600;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/collar.c"),this_player());
}
else if (str == "corset" || str == "black corset" || str == "leather corset")  {
write("Dominatrix nods in approval, then reaches under the counter and pulls out\n"+
      "a black leather corset. She slides it across the counter for you.\n");
   value = 800;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/black_corset.c"),this_player());
}
else if (str == "dildo" || str == "purple dildo") {
/*
write("Dominatrix arches an eyebrow at you, then composes herself. She reaches for\n"+
      "a large purple object under the counter and tosses it at you.\n");
   value = 2250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/weps/pur_dildo.c"),this_player());
*/
write("Dominatrix says: That's not available yet, Worm!\n");
return 1;
}
else if (str == "handcuffs" || str == "handcuff")  {
write("Dominatrix strikes out and grabs ahold of your arm, slapping the cuffs\n"+
      "on one wrist. She then turns her back on you.\n");
   value = 250;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/handcuffs.c"),this_player());
}
else if (str == "pendant" || str == "silver pendant" || str == "chain") {
write("Dominatrix turns and pulls a silver chain from a peghook on the back wall.\n");
   value = 750;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/sil_pend.c"),this_player());
}
else if (str == "cat" || str == "whip")  {
write("Dominatrix tosses the weapon up upon the counter for you to take.\n");
  value = 450;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/weps/cat9tails.c"),this_player());
}
else if (str == "pierce" || str == "piercing" || str == "tongue piercing") {
write("Dominatrix looks you over, then shrugs helplessly and hands you a small,\n"+
      "silver stud. She then turns and ignores you.\n");
   value = 650;
if(TPM<value){write("You don't have "+value+" coins.\n");return 1;}
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/tpierce.c"),this_player());
}
else {
write("The Dominatrix snaps: What do you want to buy?\n");
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
