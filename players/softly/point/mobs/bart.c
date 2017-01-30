#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;
move_object(clone_object("/players/softly/point/obj/eight.c"),this_object());
move_object(clone_object("/players/softly/point/obj/dchain.c"),this_object());
   set_name("bart");
   set_short(BOLD + "Ghost" + NORM + " of Bartholomew Roberts");
   set_alias("ghost");
   set_long("\
  A gentleman dressed in a rich damask waistcoat and\n\
breeches sports a gold chain around his neck with a\n\
large diamond cross dangling from it.\n");
   set_race("ghost");
   set_level(20);
   set_ac(17);
   set_wc(30);
   set_hp(500);
   set_al(-800);
   add_money(2500+random(300));   

}
void heart_beat()
{
    ::heart_beat();
    if(!attacker_ob) return;
    if(random(100) < 20)
    {
      tell_object(attacker_ob, BOLD+"\nBart trips you sending you sprawling into the railing.\n\n"+NORM);
      tell_room(environment(), "\nBart trips " + (string)attacker_ob->query_name() + " who sprawls against the railing.\n",({ attacker_ob }));
      attacker_ob->hit_player(random(50));
    }
}
