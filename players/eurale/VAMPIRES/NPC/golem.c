#include "/players/eurale/closed/ansi.h"
#define TP this_player()
#define TPRN this_player()->query_real_name()
inherit "obj/monster";

reset(arg) {
object buyer;
  ::reset(arg);
  if(arg) return;
set_name("egor");
set_alias("golem");
set_alt_name("supply golem");
set_race("undead");
set_short("supply "+HIG+"golem"+NORM);
set_long(
  "This flesh golem stands a head and half taller than most humans and\n"+
  "weighs almost 350 pounds.  It is made up from a ghoulish collection\n"+
  "of stolen human body parts, stitched together to form a single human\n"+
  "body.  It's skin is the sickly green of partially decayed flesh. It\n"+
  "smells faintly of dug earth and dead flesh.\n");

set_level(14);
set_hp(300);
set_al(0);
set_wc(18);
set_ac(11);
set_heal(5,2);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(2);
  load_chat("The golem walks stiffly about checking inventory.\n");
  load_chat("The golem looks at you and smiles.\n");
  load_chat("Egor grunts something unintelligible.\n");

}

init() {
  add_action("equip","equip");
}

equip(str) {
if(!str) { write("Equip who?\n"); return 1; }
if(str != "me") {
  write("The golem says, 'You can only equip yourself.'\n");
  return 1; }
if(TP->query_spell_point() < 40) {
  write("'I can't help you in your current state', says the golem.\n");
  return 1; }
if(present("guild bag",TP))
  write("The golem points at your guild bag.\n");
else {
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/guild_bag"),TP);
  write("The golem grabs a bag off the shelf and hands it to "+
        capitalize(TPRN)+".\n");
  TP->add_spell_point(-10); }
if(TP->query_level() > 11) {
  write("The golem gently pushes you away and whispers, 'You're big\n"+
        "enough to fend for yourself now... be gone.'\n");
  return 1; }

if(present("black dagger",TP))
  write("The golem grunts, 'You have a dagger already.'\n");
else {
  move_object(clone_object("players/eurale/VAMPIRES/OBJ/dagger.c"),TP);
  write("The golem searches through the equipment and gives "+
        capitalize(TPRN)+" a dagger.\n"); }
if(present("black tuxedo",TP))
  write("'You already have a tuxedo', whispers the golem.\n");
else {
  move_object(clone_object("players/eurale/VAMPIRES/OBJ/tux.c"),TP);
  write("The golem takes a tuxedo off its hanger and hands it "+
        "to "+capitalize(TPRN)+".\n"); }
if(present("guild bag",TP))
  write("The golem points at your guild bag.\n");
else {
  move_object(clone_object("players/eurale/VAMPIRES/OBJ/guild_bag.c"),TP);
  write("The golem grabs a bag off the shelf and gives it to "+
        capitalize(TPRN)+".\n"); }
TP->add_spell_point(-30);
write("\nThe golem whispers, 'Good hunting.'\n");
return 1; }
