inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Tsuwabuki Mitsuru");
    set_name("Tsuwabuki Mitsuru");
    set_alt_name("tsuwabuki");
    set_alias("mitsuru");
    set_gender("male");

set_level(14);
set_hp(210);
set_al(200);
set_wc(18);
set_ac(11);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Tsuwabuki checks over his satchel.\n");
load_chat("Tsuwabuki says: 'Hmm...  Nanami-Sama has History today...'\n");
load_chat("Tsuwabuki looks up at Ohtori Academy and smiles happily.\n");
set_a_chat_chance(5);
load_a_chat("Tsuwabuki ducks down and rages towards you!\n");
load_a_chat("Tsuwabuki yells: 'I will protect her!'\n");
load_a_chat("Tsuwabuki strikes at you with his satchel!\n");

set_long(
"Tsuwabuki Mitsuru is a young boy at Ohtori Academy.  He is dressed in \n"+
"the Academy's traditional boys uniform: A navy blue, high collared \n"+
"jacket, matching pants, and brass buttons.  He has endearing, short \n"+
"blonde hair and big, innocent blue eyes.  His dream is to become \n"+
"Nanami's older brother so he can care for her, but she takes advantage \n"+
"of him brutally.  Some day he may grow strong enough for her, and to \n"+
"bring Revolution to the World.\n");

  set_chance(10);
  set_spell_mess1(
"Tsuwabuki yells: \"I must stay strong for NanamiSama!!!\"\n"+
"   He swings his heavy satchel at his attacker\n"+
"      The weight of Nanamis homework smacks hard!\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Tsuwabuki yells: \"I must stay strong for NanamiSama!!!\"\n"+
"   He swings his heavy satchel at you\n"+
"      The weight of Nanamis homework smacks into you!\n"
  ); /* 1ST PERSON */
  set_spell_dam(35);

  set_dead_ob(this_object());
}


monster_died(ob){
object s;
        MOCO("/players/stark/utena/obj/satchel.c"),this_object());
        s=present("Satchel", TO);
        s->set_coins(500+random(700));
}

