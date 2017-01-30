/* Amelia the barmaid, Created <5/12/00> by Jara */

#include "/players/jara/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
object gold;

  ob = clone_object("/players/jara/area1/docks/obj/clip.c");
move_object(ob,this_object());
  gold = clone_object("obj/money");
  gold->set_money(200);
move_object(gold,this_object());

  set_name("amelia");
  set_short("Amelia, the barmaid");
  set_race("human");
  set_long("Amelia has thick black hair that falls in curls halfway down her\n"+
    "back, and her pale blue eyes are set off by her long, dark lashes.\n"+
    "She has a warm smile and a delicate figure. If you're new around\n"+
    "here, you may try asking her about some"+HIW+" information"+NORM+".\n");
  set_level(14);
  set_ac(11);
  set_wc(18);
  set_hp(220);
  set_al(100);
  set_aggressive(0);
  set_chat_chance(15);
  set_a_chat_chance(10);
  load_chat("Amelia smiles warmly at you.\n");
  load_chat("The barmaid wipes down the bar with a soft cloth.\n");
  load_chat("Amelia wipes her hand on her apron.\n");
  load_a_chat("Amelia slaps you across the face.\n");
  load_a_chat("The barmaid screams loudly.\n");
  load_a_chat("Amelia kicks you.\n");
   }
}

init() {
  add_action("ask","ask");
}
ask(str) {
string what;
  if(!str) { notify_fail("Ask whom abour what?\n"); return 0; }
  if(sscanf(str,"amelia about %s",what)!=1) { notify_fail("Ask whom about what?\n"); return 0; }
  switch(what) {
  case "information":
  write(
    "Amelia smiles warmly and says, 'You must be new around here...'\n"+
    "She continues, 'If you're interested in knowing more about our\n"+
    "city, you should look for"+HIW+" Nuri"+NORM+", the old "+HIW+"fisherman"+NORM+". He loves to\n"+
    "chat with anyone that will listen...'\n"+
    "She smiles at you and begins wiping down the bar again.\n");
  return 1;
  case "nuri": case "fisherman":
  write(
    "Amelia tilts her head slightly and smiles up at you.\n"+
    "Amelia points to the south as she says, 'Nuri is usually fishing\n"+
    "just south of the tavern on the pier. He's quite a friendly old\n"+
    "man, and it's rumored he once fought "+HIW+"pirates"+NORM+" that invaded our "+HIW+"land"+NORM+"!\n"+
    "She smiles proudly at the thought and goes back to her work.\n");
  return 1;
  case "land": case "pirates":
  write(
    "Amelia giggles softly and says, 'Oh, I don't know much about\n"+
    "that! You need to talk to Nuri the fisherman.'\n"+
    "Amelia smiles up at you and continues to wipe down the bar.\n");
  return 1;
  default:
    write("Amelia giggles.  \"Oh, I don't know anything about that.\"\n");
    return 1;
  }
}
