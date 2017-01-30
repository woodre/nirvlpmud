#define TPM this_player()->query_money()
#define tp this_player()->query_name()
#define ROOT "/players/daranath/closed/market/obj/"
#include <ansi.h>

string ob, ob2;

id(str) {return str == "sign";}
query_weight() {return 0;}
query_value() {return 1;}

/*
short() { return "A shop sign"; }
*/
long(){
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
write("          "+HIR+"   Currently Available at the Bone Shop"+NORM+"\n");
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
write(HIR+"     Item Name            Coins    Credits    Notes"+NORM+"\n");
write("1: "+HIW+"Breathing Scarf"+NORM+"        100      250          \n");
write("2: "+HIW+"Bone Saw"+NORM+"               450      300        weapon\n");
write("3: "+HIW+"Rusty Meat Hook"+NORM+"        850      400        weapon\n");
write("4: "+HIW+"Unholy Essence"+NORM+"         1200     500        Unique Heal\n");
write("5: "+HIW+"Blood of Innocents"+NORM+"     1500     650        Intox Heal\n");
write("6: "+HIW+"Piece of Flesh"+NORM+"         1700     800        Food Heal\n");
write("7: "+HIW+"Shard of Bone"+NORM+"          1700     800        Drink Heal\n");
write("8: "+HIW+"Wand of Immolation"+NORM+"     500      15000      Unique Item\n");
write(WHT+"<--------------------------------------------------------------->"+NORM+"\n");
}

init() {
  add_action("market_purchase","buy");
  add_action("market_sell","sell");
}

market_purchase(str) {
int cost, value, creds;
object ob, ob2;
  ob2 = present("market_ob",this_player());

if(!str){ write("What number would you like to buy?\n"); return 1; }
if(!ob2){ write("Dralgos looks you over and says:\n"+
                "   You must be a member of the Bone Market to shop here.\n"+
                "   Why not go see Xion about joining?\n");  return 1; }

if((!(str == "bone")) && (!(str == "scarf")) && (!(str == "flesh")) && (!(str == "blood")) && (!(str == "essence")) && (!(str == "saw")) && (!(str == "wand")) && (!(str == "hook"))) {
write("What exactly do you want to purchase?.\n");
write("Please use: buy <scarf, hook, saw, essence, blood, flesh, wand or bone>\n");
return 1; }

if(str == "scarf") {
value = 100; creds = 250; ob = clone_object(ROOT+"br_scarf.c");
}
if(str == "hook") {
value = 850; creds = 400; ob = clone_object(ROOT+"meat_hook.c");
}
if(str == "saw") {
value = 450; creds = 300; ob = clone_object(ROOT+"bone_saw.c");
}
if(str == "essence") {
value = 1200; creds = 500; ob = clone_object(ROOT+"essence.c");
}
if(str == "blood") {
value = 1500; creds = 650; ob = clone_object(ROOT+"innocent.c");
}
if(str == "flesh") {
value = 1700; creds = 800; ob = clone_object(ROOT+"flesh.c");
}
if(str == "bone") {
value = 1700; creds = 800; ob = clone_object(ROOT+"bone.c");
}
if(str == "wand") {
value = 500; creds = 15000; ob = clone_object(ROOT+"mar_wand.c");
}
if(call_other(this_player(), "query_money", 0) < value) {
  write("That costs "+value+" gold coins, which you don't have.\n");
return 1; }
if(ob2->query_current() < creds) {
  write("You don't have the credits at the Bone Market to purchase that.\n");
return 1; }

cost = value;
write("You pay "+YEL+cost+NORM+" in coins and "+HIW+creds+NORM+" in credits for that item.\n");
 say(call_other(this_player(), "query_name", 0) + " buys a "+str+".\n");
  call_other(this_player(), "add_money", - cost);
  ob2->add_current(-(creds));
  ob2->save_me();
  move_object(ob, this_player());
write_file("/players/daranath/closed/log/boneshop_log",ctime(time())+" "+BOLD+this_player()->query_real_name()+NORM+" bought a "+str+"\n");
 return 1;
}

market_sell(str) {
  object sell_ob;
if(!str) {write("What do you want to sell?\n"); return 1; }

  sell_ob = present(str, this_player());

if(!present("dralgos", environment(this_object()))) {
write("Dralgos is not currently present, perhaps you can try again later.\n");
return 1; }

}

