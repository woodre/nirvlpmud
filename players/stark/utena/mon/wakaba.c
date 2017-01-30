inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Shinohara Wakaba");
    set_name("Shinohara Wakaba");
    set_alt_name("wakaba");
    set_alias("shinohara");
    set_gender("female");

set_level(18);
set_hp(450);
set_al(-10);
set_wc(26);
set_ac(15);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Wakaba taps her foot waiting for Utena\n");
load_chat("Wakaba thinks outloud: 'Where is my Utena!?'\n");
load_chat("Wakaba yells at the dorm: 'UTEEENNAAAAAAA!!!!!'\n");
set_a_chat_chance(5);
load_a_chat("Wakaba jumps on your back!\n");
load_a_chat("Wakaba slaps you across the face, leaving a red mark!\n");
load_a_chat("Wakaba yells: 'Stay away from me!  Someone help!'\n");

set_long(
"Shinohara Wakaba is a female student at Ohtori Academy.  She wears \n"+
"the school's traditional fuku (uniform):  A white blouse with fluffy \n"+
"sleeves tucked neatly into a green and white pleated skirt, knee high \n"+
"socks and a big red bow tied at her neck.   Her big brown eyes are full \n"+
"of life and vigor, and she bounces happily through life.  She is \n"+
"Utena's best friend and hangs on her constantly.\n");
set_dead_ob(this_object());
}
monster_died(ob){
object s;
        MOCO("/players/stark/utena/obj/purse.c"),this_object());
        s=present("Purse", TO);
        s->set_coins(500+random(1000));
}

