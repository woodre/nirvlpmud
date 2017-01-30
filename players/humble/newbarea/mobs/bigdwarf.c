inherit "/obj/monster";

#include "../defs.h"

reset(arg) {
   ::reset(arg);
   if(arg) return;
    move_object(clone_object("/players/humble/newbarea/items/battleaxe.c"));
    move_object(clone_object("/players/humble/newbarea/items/dwarfhelm.c"));
    move_object(clone_object("/players/humble/newbarea/items/dwarfchainmail.c"));
    init_command("wield battleaxe");
    init_command("wear chainmail");
     init_command("wear helm");
    set_short(HIK+"Dwarf Warlord"+NORM);
    set_name(HIK+"Dwarf Warlord"+NORM);
    set_alias("warlord");
    set_alt_name("dwarf");
   set_long(
    HIW+"This is an enormous Dwarf decked out in all sorts of menacing\n"+NORM+
    HIW+"battle gear. He is much like that of a modern day general. He dons many\n"+NORM+
    HIW+"different awards and medals in the form of scars.  He truely is a\n"+NORM+
    HIW+"veteran of war and deserves his title as Warlord. The only thing\n"+NORM+
    HIW+"that baffles you still is what he and his two cronies are doing\n"+NORM+
    HIW+"such a sacred place.\n"+NORM);
   set_gender("male");
    set_race("dwarf");
    set_level(15);
    set_wc(19+random(2));
    set_ac(11+random(2));
    set_hp(250+random(50));
 add_money(200+random(230));
    set_chat_chance(5);
    set_a_chat_chance(4);
    load_chat(HIK+"Dwarven Warlord bellows:"+NORM+" I traveled 800 years to this place.\n");
    load_a_chat(HIK+"Dwarven Warlord grits his teeth:"+NORM+" You've got a lot to learn lil one.\n");
    set_chance(12);
    set_spell_mess1(
    HIK+"Dwarven Warlord"+NORM+" smashes his opponent with his battleaxe.\n");
    set_spell_mess2(
    HIK+"Dwarven Warlord"+NORM+" swings his axe high into the air.....\n"+
    HIW+"        <%> <%> <%> <%> <%> <%> <%> <%> <%> <%> <%> <%>\n"+NORM+
    HIW+"             <%> <%> <%> <%> C L E A V E <%> <%> <%> <%> \n"+NORM+
    HIW+"        <%> <%> <%> <%> <%> <%> <%> <%> <%> <%> <%> <%>\n"+NORM);
    set_spell_dam(25);
}
