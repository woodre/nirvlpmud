inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/RandomMove.c"

reset(arg) 
{
    object thing,weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("Perfectly Normal Beast");
    set_race("beast");
    set_alias("normal beast");
    set_short("A Perfectly Normal Beast");
    set_long("This is a large, brown, wooly creature that seems to be\n"+
    "in all respects... perfectly normal...\n");
    set_level(13);
    set_hp(195);
    set_al(0);
    set_ac(10);
    set_wc(17);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Perfectly Normal Beast stampedes you!");
    set_chat_chance(20);
    load_chat("Perfectly Normal Beast thunders around.\n");
    load_chat("Perfectly Normal Beast seems to be a bit bewildered.\n");
    /*
    weapon=clone_object("players/mizan/etheriel/beasties/prefect.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/beasties/arthur.c");
    move_object(treasure, this_object());
    */
    thing=clone_object("players/mizan/etheriel/items/beast-hide");
    move_object(thing, this_object());
	}

monster_died() 
{
    this_object()->transfer_all_to(environment(this_object()));
}
