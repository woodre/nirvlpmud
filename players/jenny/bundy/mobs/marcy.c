inherit "/obj/monster";
#include "/players/jenny/define.h"
object ob;
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("marcy d'arcy");
    set_alt_name("marcy");
    set_alias("d'arcy");
    set_race("human");
    set_al(-150);
    set_level(16);
    set_hp(350+random(70));
    set_ac(11+random(5));
    set_wc(18+random(6));
   set_wc_bonus(3);
    set_aggressive(1);
    set_gender("female");
    set_short(""+MAG+"Marcy D'Arcy"+NORM+"");
    set_long(
      "Marcy is the Bundy's neighbor.  She and Al have never gotten\n"+
      "along.  She works at the bank and makes good money.  After\n"+
     "her first husband Steve dumped her, she married the chronically\n"+
     "unemployed Jefferson.  It is clear Marcy wears the pants in\n"+
     "this family.\n");
  set_chat_chance(15);
  load_chat(""+YEL+"Marcy says: "+NORM+" My Jefferson just won't get a job!"+NORM+"\n");

  gold=clone_object("obj/money");
  gold->set_money(1250+random(500));
  move_object(gold,this_object());
}
heart_beat(){
if(attacker_ob && random(5) == 0) {
say(WHT+"Marcy's blouse comes open a little bit.\n"+
"\n"+
MEATN+" appears to be blinded."+NORM+"\n");
MEAT->do_damage( ({ 8+random(10) }), ({ "other|mental" }) );
return 1;}

if(!environment()) return;
if(ob = present("jefferson", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } 

::heart_beat();
}
