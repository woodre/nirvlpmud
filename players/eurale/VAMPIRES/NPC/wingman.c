
#include "/players/eurale/closed/ansi.h"
#define TP this_player()
#define TPRN this_player()->query_real_name()
inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("man");
set_alias("vampire");
set_race("undead");
set_short("a shriveled old man");
set_long(
  "This shriveled old man is stooped over from age.  His leathery skin\n"+
  "has seen much passage of time.  He looks to be frail but there is\n"+
  "an underlying feeling that he may be much more than he appears.  On\n"+
  "his back are a pair of leathery wings, tucked neatly into his cape\n"+
  "so as to hide them as best he can.  His eyes are dark and very alert\n"+
  "as he surveys the room for anything out of place. He has spent\n"+
  "ages learning and can help you in numerous ways if you but 'ask' him.\n");

set_level(14);
set_hp(300);
set_al(0);
set_wc(18);
set_ac(11);
set_heal(5,2);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(2);
  load_chat("'Welcome fellow traveler of the night', whispers the man.\n");
  load_chat("'Have you come for you wings?' asks the old man.\n");

}

init() {
  add_action("ask","ask");
  add_action("showfangs","show_fangs");
  add_action("hidefangs","hide_fangs");
  add_action("grant","grant");
}

ask(str) {
if(!str || str == "man") {
  write("\n");
  write("The old man eyes you over carefully and says, 'I have seen\n"+
        "much and learned a great deal over time. If you are worthy,\n"+
        "you may ask for the following:\n"+
        "  I can "+BOLD+"grant wings"+NORM+"\n"+
        "  I can "+HIR+"show_fangs"+NORM+"\n"+
        "  I can also "+HIR+"hide_fangs"+NORM+"\n"+
        "  If you need an amulet, just "+BOLD+"grant amulet"+NORM+"\n"+
        "and I continue to learn so keep checking with me'...\n");
  return 1; }
}

grant(str) {
if(!str) { write("What would you like granted?\n"); return 1; }
if(str == "wings") {
if(present("batwings",TP)) {
  write("The old man snickers and points as he says, 'You already\n"+
        "have a set wings.'\n");
  return 1; }
if(TP->query_level() < 12 || TP->query_guild_exp() < 668) {
  write("The old man smiles and says, 'You'll have to come back when\n"+
       "you are worthy of flight.'\n");
  return 1; }

  write("The old man looks you straight in the eyes and whispers, 'You\n"+
        "have earned the right to fly and I will grant you that ability.\n"+
        "Use your new skill with my blessing.'  And with that he closes\n"+
        "his eyes and mumbles something incoherent.  You feel a SHARP\n"+
        "PAIN in your back and then it eases....\n");
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/batwings.c"),TP);
  return 1;
}
if(str == "amulet") {
if(present("nooneelseamulet",TP)) {
  write("The old vampire smiles and points to your amulet.\n");
  return 1; }

  write("With a slight wink, the old vampire reaches into the folds\n"+
        "of his hooded gown and brings out a black amulet.... which\n"+
        "he hands to you.\n");
  move_object(clone_object("/players/nooneelse/obj/amulet.c"),TP);
  return 1; }
}

showfangs() {
object ob;
ob = present("vampire fangs",TP);
if(ob->query_SHOWFANGS() == 1) {
  write("The old man smiles and says, 'Your fangs are already showing\n"+
        "for all to see, my child.'\n");
  return 1; }
if(ob->query_SHOWFANGS() == 0) {
  write("\nThe old man mumbles some arcane words and you feel a\n"+
        "tingling in your gums....\n");
  ob->set_SHOWFANGS(1);
  TP->save();
  return 1; }
}

hidefangs() {
object ob;
ob = present("vampire fangs",TP);
if(ob->query_SHOWFANGS() == 0) {
  write("'But your fangs are invisible now', says the old man.\n");
  return 1; }
if(ob->query_SHOWFANGS() == 1) {
  write("The old man makes some strange gestures in front of your\n"+
        "face and you feel a sharp pain in your upper gums....\n");
  ob->set_SHOWFANGS(0);
  TP->save();
  return 1; }
}
