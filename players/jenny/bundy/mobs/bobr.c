inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("bob rooney");
MOCO("/players/jenny/bundy/items/beer.c"),this_object());
MOCO("/players/jenny/bundy/items/shirt.c"),this_object());
init_command("wear shirt");
    set_alt_name("bob");
    set_alias("rooney");
    set_race("human");
    set_al(90);
    set_level(19);
    set_hp(490);
    set_ac(16);
   set_ac_bonus(2);
    set_wc(27);
   add_money(random(2000));
    set_gender("male");
    set_short(""+WHT+"Bob Rooney"+NORM+"");
    set_long(
      "Bob Rooney is one of Al's friends from NO'MAM.  Bob is\n"+
      "balding and overweight, but still able to whoop it up at\n"+
    "the nudie bar.\n");
 set_spell_mess2(""+BLU+"Bob Rooney kicks you in the groin."+NORM+"\n");
set_chance(15);
set_spell_dam(10+random(10));

}
heart_beat(){
string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    msg =""+BLU+"Bob Rooney kicks "+ATT_NAME+" in the groin."+NORM+"\n";
  set_spell_mess1(msg);
::heart_beat();
}
