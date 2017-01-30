inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("spuckball");
    set_race("spuckball");
    set_alias("ball");
    set_short("A big Spuckball");
    set_long("This is a gooey and spongy ball that constantly changes colors\n"+
    "as it darts around the area. It's really beginning to get annoying!\n");
    set_level(4);
    set_hp(60);
    set_al(0);
    set_ac(4);
    set_wc(5);
    set_chat_chance(4);
    load_chat("Spuckball gribbles nervously.\n");
    load_chat("Spuckball goes: 'Poofda!'.\n");
    treasure=clone_object("players/mizan/etheriel/items/spuckballs");
    move_object(treasure, this_object());
}
