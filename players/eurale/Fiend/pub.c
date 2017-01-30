/* Modified heals to be /doc/build/RULES/heals/heal3 compliant.
   Reduced all 'dine-in' heals by 15 coins as per same.
    30/150 = .2    16*150 = 2400     6/14/99  - Eurale  */

#include "/players/eurale/closed/ansi.h"
#define tp this_player()
#define tpn this_player()->query_real_name()
object item;
int value,m;

reset(arg) {
    if (arg) return;
    set_light(0);
}

short() {
  return "The "+BOLD+"Fiendsville Pub"+NORM;
}

init() {
  add_action("east","east");
  add_action("order","order");
  add_action("down","down");
  add_action("togo","togo");
}

down() {
  tp->move_player("into the darkness#players/eurale/Fiend/mm42.c");
  return 1; }

east() {
  tp->move_player("east#players/eurale/Fiend/mm12.c");
    return 1;
}

long() {
  write("                 You are in the "+BOLD+"Fiendsville Pub"+NORM+"\n");
  write(" \n");
    write("                 A large wooden sign here says:\n");
  write("         You can [order] the following libations here.\n\n");
  write("		Dark Beer		:    185 coins\n");
  write("		Hot Toddy		:    405 coins\n");
  write("		Planter Punch		:    785 coins\n");
  write("		Black Coffee		:    225 coins\n");
  write("\n");
  write("         Or you may order these items [togo].\n\n");
  write("               Bottle of Punch         :   2400 coins\n");
  write("               Bottle of Ginsing Tea   :   2400 coins\n\n");
  write(" \n");
    write("               The only obvious exit is "+BOLD+"east"+NORM+".\n");
}

order(str) {
string name, short_desc, mess;
int value, cost, strength, heal;

if(!str) { write("Order what?\n"); return 1; }
	if(str == "beer" || str == "dark beer") {
	mess = "That feels good";
	heal = 20;
   value = 185;
   strength = 14; }

else if (str == "toddy" || str == "hot toddy") {
	mess = "A tingling feeling goes through your body";
	heal = 30;
   value = 405;
   strength = 10; }

else if (str == "punch" || str == "planter punch") {
	mess = "A shock wave runs through your body";
	heal = 40;
   value = 785;
   strength = 6; }

else if (str == "coffee" || str == "black") {
	mess = "You feel somewhat less inebriated";
	heal = 0;
	value = 225;
   strength = -10; }

else {
       write("The bartender says: What do you want?\n");
    return 1; }

 if (call_other(this_player(), "query_money", 0) < value) {
   write("That costs " + value + " gold coins, which you don't have.\n");
   return 1; }

if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("The bartender says: I think you've had enough.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but the bartender refuses.\n");
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
if(str == "punch") {
  item = clone_object("players/eurale/Fiend/OBJ/punch.c");
  value = 2400;
  m = 1; }
if(str == "tea" || str == "ginsing") {
  item = clone_object("players/eurale/Fiend/OBJ/tea.c");
  value = 2400;
  m = 1; }

if(m) {
if(tp->query_money() < value) {
  write("You'll need more coins to purchase that!\n");
  return 1; }

if(!call_other(tp,"add_weight",call_other(item,"query_weight"))) {
  write("You can't carry this item with that load...\n");
  return 1; }

tp->add_money(-value);
move_object(item,tp);
write("You order a "+BOLD+str+NORM+" to go!\n");
say(capitalize(tpn)+" orders a "+str+" to go.\n"); }
else {
  write("That item is not available to go, sorry.\n"); }
return 1;
}
