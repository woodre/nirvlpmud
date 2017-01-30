/*
 * Evil Fairy Guard
 * Cloud 2009
 */

 
#include "/obj/ansi.h"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(500) + 3000);
  move_object(gold,this_object());

     set_name("guard");
     set_alt_name("fairy");
     set_short(""+HIK+"An evil fairy guard"+NORM+"");
     set_race( "Fay");
     set_gender("male");
     set_alias("fairy");
     set_long("The guard is very tall and muscular for a fairy. His broad\n"+
              "wings pulse with a soft green glow. He looks ready for action.\n");     
     set_level(18);
     set_ac(15);
     set_wc(26+random(2));
     set_hp(400);
     set_al(-500);
     set_aggressive(0);
     set_chat_chance(1);
     load_chat("The guard says: Protect the queen!\n");
   }
}


heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
  if(attacker_ob && present(attacker_ob, environment(this_object())))
  {
    if(random(100) > 74) air_attack();

  }
}

air_attack()
{
  tell_object(attacker_ob,
    "\n\t"+HIW+""+query_name()+""+HIW+" jets forward using his strong wings and pummels you in the stomach."+NORM+"\n\n");
    
  tell_room(environment(),
   "\n\t"+HIW+""+query_name()+" jets forward using his strong wings and pummels "+
    attacker_ob->query_name()+" in the stomach."+NORM+"\n\n", ({attacker_ob}));
    
  attacker_ob->hit_player(10+random(5));
}