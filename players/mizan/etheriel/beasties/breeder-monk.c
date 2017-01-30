inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object armor,book,necklace,ring;
    ::reset(arg);
    if(arg) return;
    set_name("Breeder Monk");
    set_race("monk");
    set_alias("breeder");
    set_short("A Breeder Monk");
    set_long("	This is a tall, lanky individual covered in a fuzzy blue robe.\n"+
    "There are not too many features that you can make out on his face,\n"+
    "and it seems that when the light is just right, you can see right\n"+
    "through his skin!\n");
    set_level(15);
    set_hp(230);
    set_al(0);
    set_ac(23);
    set_wc(14);
    set_chance(5);
    set_spell_dam(45);
    set_spell_mess1("Breeder Monk chants a strange mantra and you are engulfed in flames!\n");
    set_chat_chance(12);
    load_chat("Breeder Monk looks around and wonders: God?? Have you come for me?\n");
    load_chat("Breeder Monk mumbles: where am I?\n");
    load_chat("Breeder Monk appears disoriented and confused.\n");
    load_chat("Breeder Monk boggles and tries to explain all of this confusion.\n");
    armor=clone_object("players/mizan/etheriel/items/blue-robe.c");
    move_object(armor, this_object());
    book=clone_object("players/mizan/etheriel/items/br-textbook.c");
    move_object(book, this_object());
    ring=clone_object("players/mizan/etheriel/items/ering.c");
    move_object(ring, this_object());
    necklace=clone_object("players/mizan/etheriel/items/br-necklace.c");
    move_object(necklace, this_object());
}

