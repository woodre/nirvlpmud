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

set_level(18);
set_hp(450);
set_al(-200);
set_wc(26);
set_ac(15);
set_no_clean(1);
set_aggressive(0);

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

  set_chance(20);
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
  set_spell_dam(20);

  set_dead_ob(this_object());
}
monster_died(ob){
object s;
        MOCO("/players/stark/utena/obj/purse.c"),this_object());
        s=present("Purse", TO);
        s->set_coins(500+random(1000));
}

heart_beat(){
object ob;
ob=present("Kiryuu Nanami", ETO);

if(present(ob, ETO)){
	if(ob->query_attack()) {
		attack_object(ob->query_attack());
	}
}

::heart_beat();
}
