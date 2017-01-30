#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

object usps;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Newman"+NORM);
set_alias("newman");
set_alt_name("newman");
set_race("human");
set_short("Newman");
set_long(
  "  Newman, the longtime nemesis of Jerry Seinfeld, lies\n"+
  "happily on his couch, eating chips and watching TV.\n"+
  "He is vastly overweight, but doesn't seem to care, as\n"+
  "he is quite content with himself.  He delivers the mail\n"+
  "for a living, although rumor has it that he will only\n"+
  "deliver if the weather is nice outside.  Newman has always\n"+
  "been somewhat of a weakling and a coward, but he does have\n"+
  "a sinister side to him.\n");

set_level(11);
set_hp(180+random(20));
set_al(0);
set_wc(9);
set_ac(13);
set_heal(3,20);
set_aggressive(0);
set_dead_ob(this_object());
set_a_chat_chance(15);
  load_a_chat("Newman exclaims: Now who will deliver the mail?\n");

usps = clone_object("players/cosmo/apt/armor/usps");
move_object(usps,this_object());
}

monster_died() {
  destruct(usps);
  move_object(clone_object("players/cosmo/apt/obj/rubble"), environment());
  tell_room(environment(),
        "Newman flies through the air from your death blow, landing\n"+
        "squarly on a table and smashing it into pieces. All that\n"+
        "remains of the table is now rubble.\n");
return 0; }

