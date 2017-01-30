inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object shoe,sock,film;
    ::reset(arg);
    if(arg) return;
    set_name("Mister Rogers");
    set_race("Mister Rogers");
    set_alias("rogers");
    set_short("Mister Rogers");
    set_long("This is a harmless old man, his hair combed neatly and dressed\n"+
    "neatly as well, but his clothing seems out of fashion.\n"+
    "He has this smile on his face that either makes you bubble\n"+
    "with joy, or convulse in panic.\n");
    set_level(8);
    set_hp(120);
    set_al(1000);
    set_ac(4);
    set_wc(11);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Mister Rogers cries: Why are you hitting me?");
    set_spell_mess2("Mister Rogers takes his shoe off and starts beating you with it.");
    set_chat_chance(10);
    load_chat("Mister Rogers says: Hi there, neighbor!\n");
    load_chat("Mister Rogers smiles happily.\n");
    load_chat("Mister Rogers whistles happily.\n");
    load_chat("Mister Rogers is making you sick.\n");
    shoe=clone_object("players/mizan/etheriel/items/left-shoe.c");
    move_object(shoe, this_object());
    sock=clone_object("players/mizan/etheriel/items/smelly-sock.c");
    move_object(sock, this_object());
    film=clone_object("players/mizan/etheriel/items/filmroll.c");
    move_object(film, this_object());
}
