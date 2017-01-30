/*  NOte: before you change anything in this file
 *        understand that this sp heal is hard to get
 *        take a stroll as a player char through
 *        /players/mythos/closed/guild/forest/rooms/hunter.c
 *        these are found on the thorns.....
 *
 *         also, there is a chance for a lower_attrib to happen
 *         to the user 1 in 100 per time used
 *
        100 sp with type other
 *                                        -mythos
 */

#include "/players/mythos/closed/guild/def.h"
int thorn;

id(str) { return (str == "sap" || str == "essence" || str == "vine sap"); }

reset(arg) {
if(arg) return;
 thorn = 5;
}

long(){
  write("A hardened piece of clear sap- Essence of Vraith\n");
  write("To use, simply 'touch essence'\n");
  write("There are " + (thorn) + " uses left.\n");
}

short() { return "Essence of Vraith- vine sap"; }

drop() { return 0;}
get() { return 1;}
query_weight() { return 3; }
query_value() { return thorn*100; }
query_save_flag() { return 1;}
is_heal() { return "other"; }
query_potence() { return 52; }

init(){
  add_action("touch","touch");
}

touch(str) {
  if(!str) return 0;
  if(str == "essence") {
  write("You touch your hand to the Essence of Vraith.\n");
  if(pp) { write("The fae around you slowly surround you!\n"+
                 "You notice the fae seep into you....!\n"); }
  write("You feel invigorated!\n");
  say(capitalize(tpn)+" touches a hand to the Essence.\n");
  
  tp->add_spell_point(52);
  if(random(100) == 0 && !pp) { 
  wrte("For some reason your body doesn't take too well to the essence.\n");
  tp->lower_attrib(); } 
  
  thorn = thorn - 1;
  if(thorn < 1) {
  write("The Essence of Vraith disappears!\n"); 
  destruct(this_object()); }
  return 1;}
}
