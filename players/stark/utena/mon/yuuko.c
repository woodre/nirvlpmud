inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Oose Yuuko");
    set_name("Oose Yuuko");
    set_alt_name("yuuko");
    set_alias("oose");
    set_gender("female");

set_level(18);
set_hp(450);
set_al(-200);
set_wc(26);
set_ac(15);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Yuuko checks over some surveillance photos she's taken.\n");
load_chat("Yuuko tries to sell off some of the photos to admirers.\n");
load_chat("Yuuko looks over to Nanami to admire her.\n");
load_chat("Yuuko looks at you with disgust.\n");
set_a_chat_chance(5);
load_a_chat("Yuuko slaps you!\n");
load_a_chat("Yuuko says: 'There is no reason for this!'\n");
load_a_chat("Yuuko screams in terror!\n");

set_long(
"Oose Yuuko is a female student at Ohtori Academy.  She wears the \n"+
"school's traditional fuku (uniform):  A white blouse with fluffy \n"+
"sleeves tucked neatly into a green and white pleated skirt, knee high \n"+
"socks and a big red bow tied at her neck.   Her straight brown hair is \n"+
"cut sleekly to her mouth and she has neatly curled bangs.  She is one \n"+
"of Nanami's followers and often does her dirty work.\n");

  set_chance(20);
  set_spell_mess1(
"Yuuko stares at her foe with a newfound disgust.\n"+
"   The slap she delivers resounds throughout the room.\n"+
"      Yuuko yells loudly: \"All of this is because of YOU!\"\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Yuuko stares at you with a newfound disgust.\n"+
"   The slap she delivers resounds throughout the room.\n"+
"      Yuuko yells into your face: \"All of this is because of YOU!\"\n"
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
