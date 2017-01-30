inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("ChuChu");
    set_name("ChuChu");
    set_alt_name("chuchu");
    set_gender("male");

set_level(6);
set_hp(90);
set_al(0);
set_wc(10);
set_ac(5);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("ChuChu picks up a cracker.\n");
load_chat("ChuChu looks strangely at you.\n");
load_chat("ChuChu chews at a cracker.\n");
load_chat("ChuChu stuffs a whole cracker in his mouth.\n");
load_chat("ChuChu tries to swallow the cracker, but chokes slowly.\n");
load_chat("ChuChu swallows the cracker down into his stomach.\n");
load_chat("ChuChu says: 'Chuuuuuu' and smiles.\n");
set_a_chat_chance(5);
load_a_chat("ChuChu jumps at your legs.\n");
load_a_chat("ChuChu yells: 'CHUUUUUU!!!!'\n");
load_a_chat("ChuChu threatens you with his tiny fork.\n");
load_a_chat("ChuChu tries to bite into you.\n");

    set_long(
"ChuChu is the name of Anthys pet monkey and a friend to \n"+
"most.  Chuchu being the sound made by rats, and ChuChu is \n"+
"about the size of one.  His huge head is completed with \n"+
"two huge circular ears.  He wears a loop earring in his \n"+
"left ear.  He also has a very small red and yellow \n"+
"striped tie.\n");

  set_chance(10);
  set_spell_mess1(
"ChuChu charges at your group and stabs the closest person in the leg with a tiny fork!\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"ChuChu charges you and stabs you in the leg with a fork!\n"
  ); /* 1ST PERSON */
  set_spell_dam(10);

  set_dead_ob(this_object());
}


init() {
::init();
add_action("search","search");
}

search(){
	write("ChuChu steps in front of you and yells: \"CHUUUUUUUUUU!!!!!\"\n");
return 1;}
