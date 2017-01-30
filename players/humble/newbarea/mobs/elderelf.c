inherit "/obj/monster.c";

#include "../defs.h"
reset(arg) {
   ::reset(arg);
   if(arg) return;
    move_object(clone_object("/players/humble/newbarea/items/elvenboots.c"));
    move_object(clone_object("/players/humble/newbarea/items/quarterstaff.c"));
    init_command("wield staff");
     init_command("wear boots");
    set_name(GRN+"Elder Elf"+NORM);
    set_short(GRN+"Elder Elf"+NORM);
    set_alias("elf");
    set_alt_name("elf");
   set_long(
    "This is a older elf who is very tall for an elf.  He seems to be a very quiet\n"+
    "creature with little expression on his long face.  His hair is grey and falls\n"+
    "down as low as his knees.  He seems very wise and learned in the way\n"+
    "of his peoples.  I would reccomend respecting your elders.\n");
   set_gender("male");
    set_race("elf");
    set_level(14);
    set_hp(200+random(75));
    set_wc(17+random(2));
    set_ac(10+random(2));
    add_money(400+random(135));
    set_chat_chance(5);
    set_a_chat_chance(4);
    load_chat(GRN+"Elder Elf lifts his head up and nods.\n"+NORM);
    load_a_chat(GRN+"Elder Elf says:"+NORM+" I must protect that which is sacred to us.\n");
   set_chance(5);
   set_spell_mess1(
    GRN+"Elder Elf slides his staff under his opponents feet, making them fall.\n"+NORM);
   set_spell_mess2(
    GRN+"Elder Elf sweeps you off your feet...\n"+NORM+
    HIG+"            ***************   C  R  A  C  K   ****************\n"+NORM+
    GRN+" and smashes you in the face with his quarterstaff.\n"+NORM);
    set_spell_dam(15);
}

init()
{
   monster::init();
    add_action("north", "north");
}

north()
{
    write(GRN+"The Elder Elf lowers his quarterstaffs and blocks the hall.\n"+NORM);
    say(GRN+"The Elder Elf lowers his quarterstaffs and blocks the hall.\n"+NORM);
   return 1;
  }
