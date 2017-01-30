inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Kaoru Kozue");
    set_name("Kaoru Kozue");
    set_alt_name("kozue");
    set_alias("kaoru");
    set_gender("female");

set_level(19);
set_hp(475);
set_al(-200);
set_wc(28);
set_ac(16);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Kozue smiles at you seductively.\n");
load_chat("Kozue plays with the buttons on her blouse.\n");
load_chat("Kozue leans on the piano and sighs wistfully...\n");
set_a_chat_chance(5);
load_a_chat("Kozue looks franticly for help...\n");
load_a_chat("Kozue pulls back away from you and shakes.\n");
load_a_chat("Kozue screams at you to stop!\n");

    set_long(
"Kaoru Kozue is the twin sister of Kaoru Miki.  She wears the school's \n"+
"traditional fuku (uniform): A white blouse with fluffy sleeves tucked \n"+
"neatly into a green and white pleated skirt, knee high socks and a big \n"+
"red bow tied at her neck.  Her blue hair is cut as short as her twin, \n"+
"but stylized for a woman.  She loves her twin brother enough to duel \n"+
"against those who would steal that love.\n");

  set_chance(10);
  set_spell_mess1(
"Kozue walks up to your group and slips in close\n"+
"   She slowly pulls open her blouse and breaths heavily\n"+
"      Kozue slaps hard against her foe and rakes her nails down their face!\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Kozue walks up to you and slips in close\n"+
"   She slowly pulls open her blouse and breaths heavily\n"+
"      Kozue slaps hard against you and rakes her nails down your face!\n"
  ); /* 1ST PERSON */
  set_spell_dam(25);

  set_dead_ob(this_object());
}


monster_died(ob){
object s;
        MOCO("/players/stark/utena/obj/purse.c"),this_object());
        s=present("Purse", TO);
        s->set_coins(1000+random(2000));
}

