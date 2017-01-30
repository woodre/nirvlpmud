
#include </players/tallos/ansi.h>

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

	   
object gold;
  gold = clone_object("obj/money");
  gold->set_money(100 + random(500));
  move_object(gold,this_object());

     set_name("quasit");
     set_short(""+HIB+"A Quasit"+NORM+"");
     set_race( "demon");
     set_alias("demon");
     set_long("A tiny humanoid-shaped creature with spiky horns and bat wings.\n"+
              "Its hands and feet are long and slender, with long, claw-tipped\n"+
              "digits. Warts or pustules cover its entire "+HIG+"greenish"+NORM+" skin.\n");
     set_level(10+random(2));
     set_ac(8);
     set_wc(14);
     set_hp(200);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The quasit eats the flesh from a corpse.\n");
     load_chat("The quasit looks at you and licks its lips.\n");
   }
}
