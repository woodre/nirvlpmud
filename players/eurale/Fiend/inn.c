/* Modified heals to be /doc/build/RULES/heals/heal3 compliant.
   Reduced all 'dine-in' heals by 15 coins as per same.
   30/150 = .2   16*150 = 2400   6/14/99  - Eurale  */


#include "/players/eurale/closed/ansi.h"
#define tp this_player()
#define tpn tp->query_real_name()
object item;
int value,m;

reset(arg) {
    if (arg) return;
    set_light(0);
}

short() {
  return "The "+BOLD+"Fiendsville Inn"+NORM;
}

init() {
  add_action("south","south");
  add_action("order","order");
  add_action("down","down");
  add_action("togo","togo");
}

south() {
  tp->move_player("east#players/eurale/Fiend/mm18.c");
    return 1;
}

down() {
  tp->move_player("into the darkness#players/eurale/Fiend/mm41.c");
  return 1; }


long() {
  write(BOLD+"                    FIENDSVILLE INN"+NORM+"\n");
  write("You are in the Fiendsville Inn.  You can purchase foodstuffs\n"+
	"here to quench your appetite and take away those hunger pangs.\n"+
	"The menu here is as follows:\n\n");
  write("              You can [order] the following meals here.\n\n");
  write("		Stuffed Peppers		:    265 coins\n");
  write("		Chicken Soup		:    335 coins\n");
  write("		Prime Rib		:    435 coins\n");
  write("		Alka Seltzer		:    250 coins\n");
  write("\n");
  write("       Or you can order one of our famous steaks [togo].\n");
  write("               Prime Rib (steak)        :   2400 coins\n");
  write(" \n");
 write("               The only obvious exit is "+BOLD+"south"+NORM+".\n");
}

order(str) {
string name, short_desc, mess;
int value, cost, strength, heal;

if(!str) { write("Order what?\n"); return 1; }
  if(str == "peppers" || str == "stuffed peppers") {
   mess = "You dig into the plate of stuffed peppers";
	heal = 20;
   value = 265;
   strength = 14; }

  else if(str == "soup" || str == "chicken soup") {
   mess = "Ahhhh, the soup really hits the spot";
	heal = 30;
   value = 335;
   strength = 12; }

  else if(str == "rib" || str == "prime rib") {
   mess = "The prime rib was huge and superbly cooked";
	heal = 40;
   value = 435;
   strength = 14; }

  else if(str == "seltzer" || str == "alka seltzer") {
   mess = "The fizzy drink makes you feel less full";
	heal = 0;
	value = 250;
   strength = -10; }

else {
  write("The waiter asks, 'What would you like to order?\n");
    return 1; }

 if (call_other(this_player(), "query_money", 0) < value) {
   write("That costs " + value + " gold coins, which you don't have.\n");
   return 1; }

if (!call_other(this_player(), "eat_food", strength)) {
	write("The proprietor says: I think you've had enough.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but the waiter refuses.\n");
   return 1; }

   write("You pay " + value + " coins for a " + str + ".\n");
   say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}

togo(str) {
m = 0;
if(str == "steak" || str == "prime rib") {
  item = clone_object("players/eurale/Fiend/OBJ/prime_rib.c");
  value = 2400;
  m = 1; }

if(m) {
if(tp->query_money() < value) {
  write("You'll have to scrounge up some more coins first.\n");
  return 1; }
if(!call_other(tp,"add_weight",call_other(item,"query_weight"))) {
  write("This is too heavy for you at the moment.\n");
  return 1; }
tp->add_money(-value);
move_object(item,tp);
say(capitalize(tpn)+" purchases a "+str+".\n");
write("You buy a "+BOLD+"prime rib"+NORM+" to go.\n");
}

else {
  write("That's not available here, sorry.\n"); }
return 1; }
