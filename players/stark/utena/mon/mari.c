inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Hozumi Mari");
    set_name("Hozumi Mari");
    set_alt_name("mari");
    set_alias("hozumi");
    set_gender("female");

set_level(10);
set_hp(150);
set_al(200);
set_wc(14);
set_ac(8);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Mari looks up at the clouds and smiles.\n");
load_chat("Mari politely ignores you.\n");
load_chat("Mari tries to find some of the children her age.\n");
set_a_chat_chance(5);
load_a_chat("Mari bangs her fists against you!\n");
load_a_chat("Mari asks: 'Why are you trying to hurt me?'\n");
load_a_chat("Mari yells for Tsuwabuki to save her.\n");

    set_long(
"Hozumi Mari is a student in the lower grades at Ohtori Academy.  She \n"+
"wears the younger version of the schools fuku (uniform): A white blouse \n"+
"with fluffy sleeves tucked neatly into a green and white pleated skirt, \n"+
"knee high socks and a small bow tie at her neck.  She is in the same \n"+
"grade as Tsuwabuki and is one of his closest friends.\n");

  set_chance(10);
  set_spell_mess1(
"Mari shrieks and blindly smashes her attacker with her satchel\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Mari shrieks and blindly smashes you with her satchel\n"
  ); /* 1ST PERSON */
  set_spell_dam(15);

  set_dead_ob(this_object());
}

monster_died(ob){
object s;
	MOCO("/players/stark/utena/obj/satchel.c"),this_object());
        s=present("Satchel", TO);
        s->set_coins(200+random(300));
}

