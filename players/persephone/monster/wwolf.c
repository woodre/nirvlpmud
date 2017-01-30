/* Changed level from 17 to 19, wc from 25 to 32, and hp from 425 to 450. This due to coin value and description. -Snow 1/00 */
inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset(arg){
 ::reset(arg);
  if(!arg){
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(random(2200));
   gold->set_money(2000 + random(2200));
   move_object(gold, TOB);
   set_name("werewolf");
   set_alias("wolf");
   set_short("Mean Werewolf");
   set_long("One of the strongest of the Lycanthropes this werewolf looks\n" +
           "extremely strong and savage. I would not mess with him if I were\n" +
           "you. He appears to be fidgety at your glance\n");
   set_level (19);
   set_wc(32);
   set_ac(14);
   set_hp(450);
   set_al(-350);
   set_aggressive(0);
   set_gender(1);
   set_chance(20);
   set_spell_dam(20);
   set_spell_mess1("The Werewolf howls for blood");
   set_spell_mess2("You pale as the Werewolf sinks his fangs into your neck");
  }
}
  
