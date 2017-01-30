inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Tsuchiya Ruka");
    set_name("Tsuchiya Ruka");
    set_alt_name("ruka");
    set_alias("tsuchiya");
    set_gender("male");

MOCO("/players/stark/utena/obj/rukasword.c"),this_object());
MOCO("/players/stark/utena/obj/r_ring.c"),this_object());
command("wield weapon");
command("wear ring");

set_level(20);
set_hp(500);
set_al(-1000);
set_wc(30);
set_ac(16);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Ruka is surrounded by his female fans.\n");
load_chat("Ruka brushes off his small but dense crowd.\n");
load_chat("Ruka shows a fencer some simple moves.\n");
load_chat("Ruka brushes his hair to the side and smiles at the spectators.\n");
set_a_chat_chance(5);
load_a_chat("Ruka shows off to the crowd as he dodges your strikes.\n");
load_a_chat("Ruka laughs merrily as he slashes at you.\n");
load_a_chat("Ruka remarks with a smile: 'You are better than I thought, good job...'\n");

set_long(
"Tsuchiya Ruka is a student at Ohtori Academy.  He wears a Student council \n"+
"outfit; A white jacket that buttons at the shoulder with a red lining and \n"+
"brass buttons, decorative gold cording and red shoulders.  His dark blue hair \n"+
"is parted down the middle and cut short; with a long lock of light blue \n"+
"hanging down the right side of his face.  This Student Council Member and \n"+
"Fencing President has been away for quite some time on a mysterious illness.\n");

  set_chance(35);
  set_spell_mess1(
"Ruka sneers as he lets his guard drop\n"+
"   Seeing the opening one of the group charges forward at him\n"+
"      With a sidestep, Ruka slashes his foe in the side!\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"Ruka sneers at you as he lets his guard drop\n"+
"   Seeing the opening you charge forward at him\n"+
"      With a sidestep, Ruka slashes across your side!\n"
  ); /* 1ST PERSON */
  set_spell_dam(25);

  set_dead_ob(this_object());
}

monster_died(ob){
object s;
		MOCO("/players/stark/utena/obj/rukajacket.c"),this_object());
        MOCO("/players/stark/utena/obj/wallet.c"),this_object());
        s=present("Wallet", TO);
        s->set_coins(500+random(2000));
}

