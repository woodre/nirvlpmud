inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Kawamura Mamiya");
    set_name("Kawamura Mamiya");
    set_alt_name("mamiya");
    set_alias("kawamura");
    set_gender("male");

set_level(19);
set_hp(475);
set_al(-200);
set_wc(28);
set_ac(16);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Mamiya touches the black rose gently.\n");
load_chat("Mamiya stares at the black rose in all it's beauty.\n");
load_chat("Mamiya looks at you blankly and smiles.\n");
set_a_chat_chance(5);
load_a_chat("Mamiya shrieks and falls backward.\n");
load_a_chat("Mamiya protects his beautiful black rose.\n");

    set_long(
"Kawamura Mamiya is dressed in a military looking uniform consisting of \n"+
"tight red pants and a fitted jacket with two black and white breast \n"+
"pockets, gold buttons and a high collar.  He wears gold shoulder bars \n"+
"with green tassels on his shoulders.  Mamiya's skin is a rich tan \n"+
"colour and he has big brown eyes.  His wavy, lavender hair is cut to \n"+
"the length of his eyes and parted in the middle.  He is conspiring to \n"+
"kill Anthy and become the Rose Bride himself.\n");

set_dead_ob(this_object());
}


init() {
::init();
add_action("search","search");
}

search(){
	write("Mamiya steps in front of his Black Rose and looks at you with fear in his eyes.\n");
return 1;}

