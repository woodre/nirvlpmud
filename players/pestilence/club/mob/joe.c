#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster.c";
#define TP this_player()
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("joe"); 
  set_alias("guard");
  set_short("Joe the security guard");
  set_long("Joe is five foot and ten inches tall.  He has short brown hair and\n"+
           "is average build.  Joe works as a security guard at Pesty's Club\n"+
           "while he's in between jobs.\n");
  set_race("human");
  set_gender("male");
  set_level(19);
  set_wc(28);
  set_ac(16);
  set_hp(450);
  set_heal(5,30);
  add_money(2000 + random(2000));
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Joe says: is this punk bothering you Jim?.\n");
  load_chat("Joe says: do you want me to help you Jim?.\n");
  load_chat("Joe says: I think Destinee wants me.\n");
  set_chat_chance(10);
  load_a_chat("Joe kicks you in the head.\n");
  load_a_chat("Joe smashes you with a bone crushing sound.\n");
  load_a_chat("Joe massacres you into tiny fragments.\n");
  set_a_chat_chance(30);
set_spell_mess2("Joe slams you to the floor.\n");
set_spell_mess1("Joe slams his attacker to the floor.\n");
  set_chance(20);
  set_spell_dam(15);
}

init() {
  ::init();
add_action("stop","west");
/* let people go back the way they came -Bp
add_action("stop","back");
*/
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("Joe says: Sorry, I can't let you in there.\n");
return 1; }
}

monster_died() {
  tell_room(environment(this_object()),
        "Joe falls to the floor and says: just when I find out Destinee wants me.... I die.\n");
return 0; }
