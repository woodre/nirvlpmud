inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("peg bundy");
    set_alt_name("peg");
    set_alias("bundy");
    set_race("human");
    set_al(75);
    set_level(18);
    set_hp(420+random(60));
MOCO("/players/jenny/bundy/items/bon.c"),this_object());
    set_wc(24+random(3));
    set_ac(11+random(5));
    set_gender("female");
    set_short(""+RED+"Peg Bundy"+NORM+"");
    set_long(
      "Peg is a tall woman with big red hair.  She is wearing orange spandex\n"+

      "pants and a tight fitting tiger striped top.  Peg does not cook,\n"+
     "clean, pay bills, work, or buy groceries.\n");
      set_spell_mess2(""+RED+"Peg starts to nag you.  Her voice cuts through you like a knife."+NORM+"\n");
set_chance(23);
set_spell_dam(10+random(30));

     load_chat(""+MAG+"Peg says: "+NORM+" SSSHHHHHHH!!!!  I'm watching Oprah."+NORM+"\n");
}
heart_beat(){
string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    msg =""+YEL+"Peg starts to nag "+ATT_NAME+"."+NORM+"\n";
  set_spell_mess1(msg);
::heart_beat();
}
