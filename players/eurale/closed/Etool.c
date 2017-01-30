/*  Eurale's Wiztool  */

#include "/players/eurale/closed/HLP/DEF.h"
#define Mv call_other(this_player(),"move_player"
#define HELP "/players/eurale/closed/Ebase.c"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

set_name("wand");
set_alias("tinker toy");
set_short(HIC+"tinker toy wand"+NORM);
set_long(
  HIR+"This wooden tinker toy wand pulses with inner life.\n"+
  "Use its power wisely or be damned!\n\n"+NORM+
BOLD+"Places:  "+NORM+
  "board  office  portal  test\n"+
"\n"+
"     Thpe '"+BOLD+"commands"+NORM+"' for wiztool commands or \n"+
"     type '"+BOLD+"help wizard"+NORM+"' for wizard commands\n"+
"\n");
set_class(25);
set_weight(0);
set_value(0);
set_light(0);
}

drop() { return 1; }
query_save_flag() { return 1; }

init() {
  ::init();
if(TPRN != "eurale") {
  write(HIR+"You feel yourself losing consciousness and pass out...\n"+NORM);
  destruct(ETO);
destruct(this_object());
}

  add_action("Office","office");
  add_action("Portal","portal");
  add_action("Board","board");
  add_action("Test","test");

  add_action("Aset","aset");
  add_action("Attrib","attrib");
  add_action("Calm","calm");
  add_action("Commands","commands");
  add_action("File","file");
  add_action("Fin","fin");
  add_action("Freeze","freeze");
  add_action("Garble","garble");
  add_action("Hand","hand");
  add_action("Heal","heal");
  add_action("Ibag","ibag");
  add_action("Idest","idest");
  add_action("Inven","I");
  add_action("Inven_room","Irm");
  add_action("Nset","nset");
  add_action("Church_player","pew");
  add_action("Register","register");
  add_action("Sset","sset");
  add_action("Tel","et");
  add_action("Unguild","unguild");
  add_action("View","view");
}

/*  ROOM LOCATIONS TO TELEPORT TO   */
Portal() { Mv,"portal#players/saber/ryllian/portal.c"); return 1; }
Board() { Mv,"board#room/adv_inner.c"); return 1; }
Test() { Mv,"test#players/eurale/testroom.c"); return 1; }
Office() { Mv,"office#players/eurale/VAMPIRES/RMS/office.c"); return 1; }

Aset(str) { return HELP->aset(str); }
Attrib(str) { return HELP->attrib(str); }
Calm(str) { return HELP->calm(str); }
Commands(str) { return HELP->commands(str); }
Church_player(str) { return HELP->church_player(str); }
File(str) { return HELP->file(str); }
Fin(str) { return HELP->fin(str); }
Freeze(str) { return HELP->freeze(str); }
Garble(str) { return HELP->garble(str); }
Hand(str) { return HELP->hand(str); }
Heal(str) { return HELP->heal(str); }
Ibag(str) { return HELP->ibag(str); }
Idest(str) { return HELP->idest(str); }
Inven(str) { return HELP->inven(str); }
Inven_room(str) { return HELP->inven_room(str); }
Nset(str) { return HELP->nset(str); }
Register(str) { return HELP->register(str); }
Sset(str) { return HELP->sset(str); }
Tel(str) { return HELP->tel(str); }
Unguild(str) { return HELP->unguild(str); }
View(str) { return HELP->view(str); }
