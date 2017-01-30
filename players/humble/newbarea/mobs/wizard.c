/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) return;
    move_object(clone_object("/players/humble/newbarea/items/wizardcap.c"));
    move_object(clone_object("/players/humble/newbarea/items/wizrobes.c"));
    init_command("wear robes");
    init_command("wear cap");
    money=175+random(200);
    set_name(HIB+"Wizard"+NORM);
    set_short(HIB+"Wizard"+NORM);
    set_alias("wizard");
    set_alt_name("wizard");
    set_race("human");
    set_long(
    "A tall weathered wizard.  He has a long grey beard that covers his entire face.\n"+
     "His hat is tipped slightly sideways and looks puzzled or perhaps just in\n"+
    "some deep state of thinking. He is shuffling through a book slowly studying\n"+
    "everything he reads.  He seems to be completely unaware of your presence\n"+
    "or perhaps he is just not worried about you being there.\n");
    set_gender("male");
    set_level(15);
    set_wc(20);
    set_ac(12+random(1));
    set_hp(250+random(50));
    set_chat_chance(6);
    set_a_chat_chance(6);
    load_chat(BLU+"The wizard says without looking up:"+NORM+" You know I created this realm.\n");
    load_chat(BLU+"The wizard inquires:"+NORM+" What can I help you with?\n");
    load_chat(BLU+"The wizard notes:"+NORM+" I realize the sprites are upset,\n"+
    "perhaps I should do something about those dwarves.\n");
    load_a_chat(BLU+"The wizard smiles and says:"+NORM+" Remember where you came from.\n");
    set_multi_cast(0);
    add_spell("ice",
    HIB+"#MN#"+NORM+" raises his arms high above you slowly.\n"+
    BLU+"//////////////////////////////////////////////////////////////////////////\n"+NORM+
    BLU+"          ////////////****   I  C  E   ****////////////\n"+NORM+
    BLU+"//////////////////////////////////////////////////////////////////////////\n"+NORM,
    BLU+"Shards of ice rain down from nowhere.\n"+NORM,
    5,({10,10}),({"other|ice","other|good"}));

    add_spell("fire",
    HIB+"The wizard focuses for a moment then casts a spell against you.\n"+NORM+
    HIR+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM+
    HIR+"          ~~~~~~~~~~~~~~~~~~~~     F  I  R  E     ~~~~~~~~~~~~~~~~~~~~\n"+NORM+       
    HIR+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM,
    HIR+"Fire rises from the ground burning #TN#\n"+NORM,
    5,({10,10}),({"other|fire","other|good"}));

    add_spell("earthquake",
    HIB+"#MN#"+NORM+" throws his hands with force towards you.\n"+
    YEL+"##########################################################\n"+NORM+
    YEL+"             ##########   E A R T H -- Q U A K E   ##########\n"+NORM+
    YEL+"##########################################################\n"+NORM,
    YEL+"The ground begins to shake all around you.\n"+NORM,
    5,({15,15}),({"other|earth","other|good"}));

    add_spell("blast",
    HIB+"#MN#"+NORM+" raises his arms high into the air.\n"+
    HIC+"********************************************************************\n"+NORM+
    HIC+"          ***************   W A T E R -- B L A S T   ***************\n"+NORM+
    HIC+"********************************************************************\n"+NORM,
    HIC+"Water seems to flood the room.\n"+NORM,
    5,({10,10}),({"other|water","other|good"}));

    add_spell("wind",
    HIB+"#MN#"+NORM+" stretches his arms out almost touching you.\n"+NORM+
    HIM+"============================================================\n"+NORM+
    HIM+"          ====================   W  I  N  D   ====================\n"+NORM+
    HIM+"============================================================\n"+NORM,
    HIM+"Wind gusts into the room.\n"+NORM,
    5,({10,10}),({"other|wind","other|good"}));
  }
