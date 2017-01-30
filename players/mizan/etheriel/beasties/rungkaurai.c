inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure,moolah;
    ::reset(arg);
    if(arg) return;
    set_name("rungkaurai");
    set_race("rungkaurai");
    set_alias("rung");
    set_short("Rungkaurai");
    set_long("Hmm.. Well, You know that it's big, round, and somewhat \n"+
    "sheepy looking... and it changes colors once in a while, but\n"+
    "otherwise, that seems to be it.\n");
    set_level(17);
    set_hp(425);
    set_al(0);
    set_ac(14);
    set_wc(24);
    set_chat_chance(20);
    load_chat("Rungkaurai changes color.\n");
    load_chat("Rungkaurai moggles excitedly.\n");
    moolah=clone_object("obj/money");
    moolah->set_money(500+random(300));
    move_object(moolah, this_object());
    load_chat("Rungkaurai makes a strange wheezing noise.\n");
    weapon=clone_object("players/mizan/etheriel/items/nyt-book.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/items/plastic-bag.c");
    move_object(treasure, this_object());
}
