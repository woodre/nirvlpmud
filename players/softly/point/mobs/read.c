#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("read");
   set_short(BOLD + "Ghost" + NORM + " of Mary Read");
   set_alias("ghost");
   set_long("\
  A young woman with long black curly hair wearing a man's\n\
tan linen trousers and navy blue jacket stands confidently\n\
before you, daring you to try to pass.\n");
   set_race("ghost");
   set_level(18);
   set_ac(15);
   set_wc(26);
   set_hp(450);
   set_al(0);
   add_money(3200+random(300));   

}
void heart_beat()
{
    ::heart_beat();
    if(!attacker_ob) return;
    if(random(100) < 40)
    {
      tell_object(attacker_ob, BOLD+"\nRead moves closer and grabs your throat.\n"+
                                    "As she chokes you, you gasp for air.\n\n"+NORM);
      tell_room(environment(), "\nRead chokes " + (string)attacker_ob->query_name() + " who turns blue.\n",({ attacker_ob }));
      attacker_ob->hit_player(random(15));
    }
}
