/* approved by Mythos - <11-8-96> */

#include "DEFS.h"
inherit "obj/weapon.c";
int num;

reset(arg){
  ::reset(arg);
  if (arg) return;
num = 5;

set_name("wand");
set_alias("cessation wand");
set_alt_name("cessation");
set_short(HIC+"Cessation Wand"+NORM);
set_long(
	"This long, slender ice-blue crystal wand has mystical runes\n"+
	"carved down it's entire length.  It has the feel of power and\n"+
   "tingles like it's alive.\n");
set_type("club");
set_class(5);
set_weight(1);
set_value(num * 250);
set_save_flag();
}

init() {
  ::init();
  add_action("Look","look",1);
  add_action("Read","read");
  add_action("Brandish","brandish");
}

Look(str) {
if(str == "at runes" || str == "at mystical runes") {
  write("The runes spell out a message.  Maybe you could "+
	     "read them.\n");
  return 1; }
}

Read(str) {
if(!str) { write("What are you trying to read?\n"); return 1; }
if(str == "runes" || str == "mystical runes") {
  write("The runes transform before your eyes and read:  Who-so-ever\n"+
	     "shall brandish this wand will call forth a 'Crashing Silence'\n"+
             "to bring peace to all around them <"+num+"> times.\n");
  return 1; }
}

Brandish(str) {
object obj;
if(!str) { write("You must brandish something!\n"); return 1; }
if(str == "wand" || str == "cessation" || str == "cessation wand") {

if(TPHP < 40 || TPSP < 40) {
   write("You do not have enough power within to brandish the wand.\n");
return 1; }

  obj = first_inventory(ETP);
  while(obj) {
    obj->stop_fight();
    obj->stop_fight();
    obj->stop_hunter();
    obj = next_inventory(obj);
  }

write("You call forth a "+HIC+"* CRASHING SILENCE *"+NORM+
      " and feel a bit weaker...\n");
say(capitalize(TPRN)+" calls forth a "+HIC+"* CRASHING SILENCE *"+NORM+
    " and all is still..\n");
num -= 1;
TO->set_value(num * 400);
TP->add_spell_point(-40);

if(num == 0) {
  tell_room(environment(TP),
    "The wand "+HIY+"GLOWS"+NORM+" and "+HIY+"MELTS"+NORM+
    " before your eyes...\n");
  destruct(TO);
  return 1; }


  return 1; }
}
