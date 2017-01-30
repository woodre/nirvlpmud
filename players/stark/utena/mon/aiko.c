inherit "/obj/monster";
#include "/players/stark/defs.h"
object attacker;
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("Wakiya Aiko");
    set_short("Wakiya Aiko");
    set_alias("aiko");
    set_alt_name("wakiya");
    set_gender("female");

set_level(18);
set_hp(450);
set_al(-200);
set_wc(26);
set_ac(15);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Aiko looks through her purse.\n");
load_chat("Aiko pretends she doesn't see you.\n");
load_chat("Aiko looks at you with contempt.\n");
set_a_chat_chance(3);
load_a_chat("Aiko slaps you!\n");
load_a_chat("Aiko says: Why am even dealing with you?!?!\n");
load_a_chat("Aiko screams in terror!\n");

    set_long(
"Wakiya Aiko is a female student at Ohtori Academy.  She wears \n"+
"the school's traditional fuku (uniform):  A white blouse with \n"+
"fluffy sleeves tucked neatly into a green and white pleated \n"+
"skirt, knee high socks and a big red bow tied at her neck.  Her \n"+
"shoulder length brown hair curls up at the ends and she wears \n"+
"a sneer on her face.  She follows Nanami and often does her \n"+
"dirty work.\n");

  set_chance(20);
  set_spell_mess1(
"Aiko stares at her foe with a newfound disgust.\n"+
"   The slap she delivers resounds throughout the room.\n"+
"      Aiko yells loudly: \"I don't care who you are!\"\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Aiko stares at you with a newfound disgust.\n"+
"   The slap she delivers resounds throughout the room.\n"+
"      Aiko yells into your face: \"I don't care who you are!\"\n"
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
/*attacker=TO->query_attack();*/

if(present(ob, ETO)){
	if(ob->query_attack()) {
		attack_object(ob->query_attack());
	}
}

::heart_beat();
}
