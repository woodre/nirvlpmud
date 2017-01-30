/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())
#define TPRN this_player()->query_real_name()
int VEN;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
VEN = 0;

set_name("scorpion");
set_alias("giant scorpion");
set_short(HIG+"giant scorpion"+NORM);
set_long(
  "This creature is a giant version of the normal 4-inch long version.\n"+
  "It has a green carapace and yellowish green legs and pincers.  The\n"+
  "segmented tail is black with a vicious stinger on the end.  There\n"+
  "is a bitter smell surrounding this predator that probably comes from\n"+
  "its venom.\n");

set_race("creature");
set_level(18);
set_hp(400 + random(25));
set_al(0);
set_wc(26);
set_ac(15);
set_aggressive(1);
set_dead_ob(this_object());

set_a_chat_chance(4);
  load_a_chat("The scorpions scurries across the floor toward you.\n");
}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/pincer.c"),ob);
return 0; }

heart_beat() {
  ::heart_beat();
if(query_attack()) {
  if(random(9) == 4 && VEN == 0) {
    move_object(clone_object("/players/eurale/Lab/OBJ/scorptox.c"),
      query_attack());
    VEN = 1;
    tell_object(query_attack(),
      HIG+"You feel the scorpion's tail PUNCTURE your leg..\n"+NORM);
    write_file("/players/eurale/Lab/LOGS/scorpion",ctime(time())+"  "+
      capitalize(attacker_ob->query_name())+" infected by scorpion.\n");
    return 1; }
  }
}
