/* Include this file for some decent generic functions */
#include "/players/paulasx/closed/wytch/fact.h"
/* WYTCH is the string that your faction will ID to */
#define WYTCH "Doppe-Wytch"
 
int i;               /* not used, but is in for demo */
 
 
/* Reset is used to initialize any global variables upon cloning the item */
reset(arg) {
  if(arg) return;
  i = 0;
  MUFFLED = 0;
}/*  set_heart_beat(1);
}
 
 
heart_beat() {
}
*/
 
 
/* Is what the player sees if they do an 'i' */
short() { return "Pentagram Necklace of the Dopple-Wytch"; }
 
 
/* Is what the player sees if they examine the object */
long() { 
  write("The necklace is made of human bones, crushed\n"+
            "and formed into a pentagram.  There is a small trickle\n"+
            "of blood coming from the center.  The necklace feels\n"+
            "very warm to the touch.\n"+
        "Type \"wh\" or \"wytch_help\" for more help.\n");
  return 1;
}
 
 
/* What the object id's to */
id(str) {
  return str == WYTCH || str == "necklace";
}
 
 
/* The commands the object can do */
init() {
  add_action("help_wytch","wh");
  add_action("help_wytch","wytch_help");
  add_action("wytch_say","wsay");
  add_action("wytch_who","wwho");
  add_action("wytch_tell","wtell");
  add_action("wytch_emote","wmote");
  add_action("wytch_shaddup","wshaddup");
  add_action("wytch_attack","watak");
  add_action("update","conjure");
  add_action("wytch_heal","wheal");
}
 
 
/* This gives the player the object everytime they log on */
query_auto_load() {
  return "/players/paulasx/closed/wytch/wytch.c:"+"#"+i+"#"; }
 
 
/* Decipher any variables that were stored when the player quit last */
init_arg(str) {
  sscanf(str,"#%d#",i);
}
 
 
/* Types a help menu to the player */
help_wytch() {
  cat("/players/paulasx/closed/wytch/wytch.help");
  return 1;
}
 
 
/* Calls the Who_Is_On function in the fact.h file to show who is on */
wytch_who() {
  who_is_on(1,1000);
  return 1;
}
 
 
/* Calls the Tell_The_Guilders function in the fact.h */
/* file to tell the guilders in the faction a message */
wytch_tell(str) {
  if(!str) {
    write("What do you want to tell them?\n");
    return 1;
  }
  tell_the_guilders(str,"{","}");
  return 1;
}
 
 
/* Turn off the faction-emote and the faction-tell lines */
wytch_shaddup() {
  write("Faction Lines: ");
  if(MUFFLED) write("OFF\n");
  else write("ON\n");
  MUFFLED = !MUFFLED;
  return 1;
}
 
 
/* A demonstration of the GetEm function */
wytch_attack(str) {
  string what,cwhat;
  if(str) what=str;
  else if(TP->query_attack())
         what=TP->query_attack()->query_name();
       else {
            write("Wytch slap what?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  getem(6,10,10,what,"You raise your hands at "+cwhat,
        CN+" burns a "+cwhat);
  return 1;
}
 
 
/* Gives the player a new copy of the item and destroys the old */
update() {
  object fact;
  fact = clone_object("/players/paulasx/closed/wytch/wytch");
  move_object(fact, TP);
  write("Necklace updated.\n");
  destruct(TO);
  return 1;
}
 
 
/* Let the player swap coins for healing based */
/* on a HEAL_SWAP coins to 1 hp/sp ratio.      */
wytch_heal(str) {
  int amt;
  if(!lvl_ok(11)) return 0;
  if(!sscanf(str,"%d",amt)) {
    write("How many coins do you want to swap?\n");
    return 1;
  }
  swap_coins_for_healing(amt);
  return 1;
}
