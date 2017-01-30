inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Sonoda Keiko");
    set_name("Sonoda Keiko");
    set_alt_name("keiko");
    set_alias("sonoda");
    set_gender("female");

MOCO("/players/stark/utena/obj/tougasword.c"),this_object());
MOCO("/players/stark/utena/obj/black_ring.c"),this_object());
command("wear ring");
command("wield weapon");

set_level(20);
set_hp(525);
set_al(-1000);
set_wc(30);
set_ac(15);
set_no_clean(1);
set_aggressive(1);

set_chat_chance(3);
load_chat("Keiko sneers at you.\n");
load_chat("Keiko sizes you up and deems you unworthy.\n");
load_chat("Keiko ignores you.\n");
set_a_chat_chance(5);
load_a_chat("Keiko slaps you!\n");
load_a_chat("Keiko says: What do you want with me?!\n");
load_a_chat("Keiko screams in terror!\n");

set_long(
"Sonoda Keiko is a female student at Ohtori Academy.  She wears \n"+
"the school's traditional fuku (uniform):  A white blouse with \n"+
"fluffy sleeves tucked neatly into a green and white pleated \n"+
"skirt, knee high socks and a big red bow tied at her neck.  She \n"+
"has an abundance of brown hair that is tied up in pigtails and \n"+
"she has a somewhat innocent air about her.  She is one of Nanami's \n"+
"followers and often does her dirty work.\n");

  set_chance(30);
  set_spell_mess1(
"Keiko stares at her foe with a newfound disgust.\n"+
"   The slap she delivers resounds throughout the room.\n"+
"      Keiko yells loudly: \"I'll never forgive you!\"\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Keiko stares at you with a newfound disgust.\n"+
"   The slap she delivers resounds throughout the room.\n"+
"      Keiko yells into your face: \"I'll never forgive you!\"\n"
); /* 1ST PERSON */
  set_spell_dam(30);

  set_dead_ob(this_object());
}


monster_died(ob){
	destruct("sword");
	destruct("ring");
}

init() {
::init();
add_action("next","next");
}

next(){
	write(TO->query_name() +" stops you from advancing.\n");
return 1;}
