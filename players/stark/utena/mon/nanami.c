inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Kiryuu Nanami");
    set_name("Kiryuu Nanami");
    set_alt_name("nanami");
    set_alias("kiryuu");
    set_gender("female");

MOCO("/players/stark/utena/obj/nanamisword.c"),this_object());
MOCO("/players/stark/utena/obj/n_ring.c"),this_object());
command("wear ring");
command("wield weapon");

set_level(19);
set_hp(575);
set_al(-1000);
set_wc(28);
set_ac(15);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Nanami looks over her plans for the day.\n");
load_chat("Nanami yells: 'Tsuwabuki!' and waits for him to arrive.\n");
load_chat("Nanami looks at you with contempt.\n");
load_chat("Nanami orders other students around.\n");
set_a_chat_chance(5);
load_a_chat("Nanami slashes at you blindly.\n");
load_a_chat("Nanami yells for her admirers to save her.\n");
load_a_chat("Nanami lungest frantically at you.\n");
load_a_chat("Nanami screams: 'Touga!!!'.\n");

set_long(
"Kiryuu Nanami is the ultimate snob.  She has a lithe, slender figure, \n"+
"long wavy blond hair and an air of undeniable superiority about her.  \n"+
"She wears the school's traditional fuku (uniform): A white blouse with \n"+
"fluffy sleeves tucked neatly into a green and white pleated skirt, knee \n"+
"high socks and a big red bow tied at her neck. Nanami is Touga's little \n"+
"sister and is violently protective of him.\n");

  set_chance(20);
  set_spell_mess1(
"Nanami daintily raises her hand to the side of her mouth.\n"+
"   A light laugh slowly grows into a psychotic cackle.\n"+
"      Nanami quickly stabs a dagger into her foes side!\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Nanami daintly raises her hand to the side of her mouth.\n"+
"   A light laugh slowly grows into a psychotic cackle.\n"+
"      Nanami quickly stabs a dagger into your side!\n"
  ); /* 1ST PERSON */
  set_spell_dam(30);

  set_dead_ob(this_object());
}


monster_died(ob){
object s;
        MOCO("/players/stark/utena/obj/purse.c"),this_object());
        s=present("Purse", TO);
        s->set_coins(1000+random(2000));
}
