/* THISFACTION is the string that your faction will ID to */
#define THISFACTION "Dopple-Generic"
 
 
/* Include this file for some decent generic functions */
#include "/players/grimm/factions/fact.h"
 
 
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
short() { return "Mark of the Doppleganger Faction"; }
 
 
/* Is what the player sees if they examine the object */
long() { 
  write("This is a generic faction example.\n"+
        "Type \"gh\" or \"generic_help\" for more help.\n");
  return 1;
}
 
 
/* What the object id's to */
id(str) {
  return str == THISFACTION || str == "mark";
}
 
 
/* The commands the object can do */
init() {
  add_action("help_faction","gh");
  add_action("help_faction","generic_help");
  add_action("say_it_in_lingo","gsay");
  add_action("guild_who","genwho");
  add_action("guild_tell","gentell");
  add_action("guild_emote","genemote");
  add_action("generic_shaddup","genshaddup");
  add_action("generic_attack","genatak");
  add_action("update","genupdate");
  add_action("coins_to_heal","genheal");
}
 
 
/* This gives the player the object everytime they log on */
query_auto_load() {
  return "/players/grimm/factions/generic:"+"#"+i+"#"; }
 
 
/* Decipher any variables that were stored when the player quit last */
init_arg(str) {
  sscanf(str,"#%d#",i);
}
 
 
/* Types a help menu to the player */
help_faction() {
  cat("/players/grimm/factions/generic.help");
  return 1;
}
 
 
/* Calls the Who_Is_On function in the fact.h file to show who is on */
guild_who() {
  who_is_on(1,1000);
  return 1;
}
 
 
/* Calls the Tell_The_Guilders function in the fact.h */
/* file to tell the guilders in the faction a message */
guild_tell(str) {
  if(!str) {
    write("What do you want to tell them?\n");
    return 1;
  }
  tell_the_guilders(str,"{","}");
  return 1;
}
 
 
/* Turn off the faction-emote and the faction-tell lines */
generic_shaddup() {
  write("Faction Lines: ");
  if(MUFFLED) write("OFF\n");
  else write("ON\n");
  MUFFLED = !MUFFLED;
  return 1;
}
 
 
/* A demonstration of the GetEm function */
generic_attack(str) {
  string what,cwhat;
  if(str) what=str;
  else if(TP->query_attack())
         what=TP->query_attack()->query_name();
       else {
            write("Generic attack what?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  getem(6,10,10,what,"You generically attack a "+cwhat,
        CN+" generically attacks a "+cwhat);
  return 1;
}
 
 
/* Gives the player a new copy of the item and destroys the old */
update() {
  object fact;
  fact = clone_object("/players/grimm/factions/generic");
  move_object(fact, TP);
  write("Faction Mark Restored.\n");
  destruct(TO);
  return 1;
}
 
 
/* Let the player swap coins for healing based */
/* on a HEAL_SWAP coins to 1 hp/sp ratio.      */
coins_to_heal(str) {
  int amt;
  if(!lvl_ok(11)) return 0;
  if(!sscanf(str,"%d",amt)) {
    write("How many coins do you want to swap?\n");
    return 1;
  }
  swap_coins_for_healing(amt);
  return 1;
}
