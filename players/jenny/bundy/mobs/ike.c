inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("Ike");
MOCO("/players/jenny/bundy/items/tot.c"),this_object());
    set_alt_name("ike");
    set_race("human");
    set_al(70);
    set_level(19);
    set_hp(480);
    set_ac(16);
    set_wc(28);
    set_gender("male");
   add_money(random(2000));
    set_short(""+GRN+"Ike"+NORM+"");
    set_long(
      "Ike is one of Al's friends from NO'MAM.  He is tall and\n"+
      "a little overweight.  He likes watching 'psycho dad' and\n"+
     "going to the nudie bar.\n");
 set_spell_mess2(""+YEL+"Ike punches you in the stomach."+NORM+"\n");
set_chance(15);
set_spell_dam(8+random(10));
}
heart_beat(){
string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    msg =""+YEL+"Ike punches "+ATT_NAME+" in the stomach."+NORM+"\n";
  set_spell_mess1(msg);
::heart_beat();
}
