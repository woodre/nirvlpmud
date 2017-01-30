inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("Ettin");
    set_race("ettin");
    set_alias("ettin");
    set_short("A two-headed Ettin");
    set_long("This is a large, nasty, smelly, ugly, hungry, and funny looking Ettin.\n"+
    "You have the feeling that it's arguing with itself whether or not to pound\n"+
    "you into fist sized chunks.\n");
    set_level(15);
    set_hp(250);
    set_al(-1000);
    set_wc(22);
    set_ac(10);
    set_chance(20);
    set_spell_dam(40);
    set_spell_mess1("Ettin pounds you with its club.");
    set_spell_mess2("Ettin beats you over the head! Whomp!");
    set_chat_chance(5);
    load_chat("Ettin says twice: Oh goody...\n");
    load_chat("Ettin scratches itself.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+150);
    move_object(gold,this_object());
    armor=clone_object("players/mizan/etheriel/items/wooly.c");
    move_object(armor, this_object());
    weapon=clone_object("players/mizan/etheriel/items/club.c");
    move_object(weapon, this_object());
}
