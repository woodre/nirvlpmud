inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Tenjou Utena");
    set_name("Tenjou Utena");
    set_alt_name("utena");
    set_alias("tenjou");
    set_gender("female");

MOCO("/players/stark/utena/obj/propsword.c"),this_object());
MOCO("/players/stark/utena/obj/u_ring.c"),this_object());
command("wear ring");
command("wield weapon");

set_level(20);
set_hp(500);
set_al(0);
set_wc(30);
set_ac(16);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Utena straightens up her room.\n");
load_chat("Utena says: 'I wish Anthy could have more friends....'\n");
load_chat("Utena fixes her sports coat.\n");
load_chat("Utena says: 'Some day I will find my Prince.'\n");
load_chat("Utena says: 'Some day I'll know who gave me... this ring.'\n");
set_a_chat_chance(5);
load_a_chat("Utena strikes at you with her practice sword!\n");
load_a_chat("Utena says: 'Why is everyone constantly chalenging me?!'\n");
load_a_chat("Utena states: 'I will make sure Anthy can lead a normal life!'\n");


    set_long(
"Tenjou Utena is a tall, slender girl aged about sixteen years old.  \n"+
"She has big, expressive blue eyes and pink hair that falls just below \n"+
"her shoulders, layered in the front and longer in the back.  She wears \n"+
"an altered boy's uniform:  The normal royal blue coat has been flared \n"+
"at the bottom.  The normal pants are substituted for red bike shorts \n"+
"and long red socks.  She also wears a ring with a rose symbol on it on \n"+
"her left hand.  She dreams of finding the prince that gave her the \n"+
"ring, and has tried to become a prince in his footsteps.\n");

  set_chance(18);
  set_spell_mess1(
"Utena lowers to her knee and closes her eyes\n"+
"   The tranclucent ghost of Dios lowers into Utena\n"+
"      She lunges at her target with all of her energy\n"+
"         The force of the blow slams into her target!\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Utena lowers to her knee and closes her eyes\n"+
"   The tranclucent ghost of Dios lowers into Utena\n"+
"      She lunges at you with all of her energy\n"+
"         The force of the blow slams hard into you!\n"  ); /* 1ST PERSON */
  set_spell_dam(85);

  set_dead_ob(this_object());
}


init() {
::init();
add_action("search","search");
}

search(){
	write("Utena steps in you way and says: \"You can't just go around searching my room!\"\n");
return 1;}
