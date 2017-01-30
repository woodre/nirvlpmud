#include <ansi.h>
inherit "/obj/monster"; /* fear this shit inheriting monster.talk :) */

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("cyclops");
set_alias("scott");
set_short("Cyclops of the Xmen");
    set_race("xman");
    set_long(
"  Before you is a man wracked with doubts and problems.  He is Cyclops,\n"+
"of the world famous X-men.  He wears a ruby visor to help him harness his\n"+
"natural ability to shoot optic beams from his eyes.  He has had many\n"+
"hardships.  His girlfried turned into an alien creature, then came back\n"+
"but he had already married her clone, she developed powers as well, and\n"+
"then it gets really confusing.  He is also having problems maintaing the\n"+
"leadership of the X-men.  He has been challenged by Storm.  Even with all\n"+
"of these problems though, he is kind of a whiner.\n");
move_object(clone_object("/players/unsane/xmen/visor.c"), this_object());
move_object(clone_object("/players/unsane/xmen/uniform.c"),this_object());
   set_level(18);
   set_ac(15);
   set_wc(26);
   set_hp(650);
   set_al(250);
/*
set_chance(20);
set_spell_dam(30);
set_spell_mess2("Cyclops blasts you with an optic beam!");
set_spell_mess1("Cyclops blasts his foe with an optic beam!");
*/
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
   load_chat("Cyclops says: Dammit Storm!  I'm capable of leadership.\n");
  load_chat("Cyclops says: Professor X placed me in charge.\n");
  load_chat("Cyclops stares intensely at Storm.\n");
  load_chat("Cyclops smashes his fist against the console.\n");
  load_chat("Cyclops says: I'll worry about wolverine.\n");
load_a_chat("Cyclops says: I'll show you I'm capable now.\n");
load_a_chat("Cyclops says: Wolverine, Colossus, come here!\n");
  load_a_chat("Cyclops says: Yes, I really have time for this..\n");
  set_wc_bonus(5); /* 1/5 chance of 15 avg [3] * 1.25  ~ 5 */
}
}

heart_beat()
{
     ::heart_beat();
     if(!random(5) && attacker_ob)
       optic_beam();
}

optic_beam()
{
     tell_object(attacker_ob, "Cyclops blasts you with an " + RED + "optic beam" + NORM + "!\n");
     tell_room(environment(), "Cyclops blasts " + attacker_ob->query_name() + " with an " + RED + "optic beam" + NORM + "!\n");
     attacker_ob->hit_player(random(30), "other|laser");
}
