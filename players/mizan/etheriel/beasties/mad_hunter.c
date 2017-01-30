inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object rifle, spam, jacket;
    ::reset(arg);
    if(arg) return;
    set_name("hunter");
    set_race("human");
    set_alias("hunter");
    set_short("A crazed hunter");
    set_long("This guy looks really sick. He's standing here trying to load his\n"+
    "weapon, and he seems to be talking to himself, in his glazed-eye glory...\n");
    set_level(12);
    set_hp(180);
    set_al(-1000);
    set_wc(16);
    set_ac(9);
    set_chance(20);
    set_spell_dam(12);
    set_spell_mess1("Hunter levels his gun at you and fires!");
    set_spell_mess2("Hunter lets loose a round at point-blank range!");
    set_chat_chance(10);
    load_chat("Hunter mumbles: come here Squish... come heeeeere....\n");
    load_chat("Hunter struggles with his weapon.\n");
    load_chat("Hunter grins evilly.\n");
    load_chat("Hunter says: I'mmma gonna getcha, Squish! There's nowhere to hide!\n");
    load_chat("Hunter mumbles: Stupid blue wombats.\n");
    rifle = clone_object("players/mizan/etheriel/items/rifle22.c");
    move_object(rifle, this_object());
    jacket=clone_object("players/mizan/etheriel/items/ugly-jacket.c");
    move_object(jacket, this_object());
    spam=clone_object("players/mizan/etheriel/heals/spam.c");
    move_object(spam, this_object());
}
