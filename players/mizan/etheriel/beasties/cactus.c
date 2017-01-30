inherit "/players/mizan/core/monster.c";
/* #include "/players/mizan/closed/amelia/RandomMove.c"; */

init() 
{
    ::init();
    add_action("hugme","hug");
}

hugme(str) 
{
    if(str!="cactus") return 0;
    write("You hug the cactus. OUCH!!\n");
    say(capitalize(this_player()->query_name())+" hugs the cactus. You wince in pain just looking at it.\n");
    return 1;
}

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("a cactus");
    set_race("cactus");
    set_short("A small, animated golden-barrel cactus");
    set_long("This is a stout green plant with yellow spikes all over it.\n"+
    "Yowsa! Looks painful if you sat on it.\n");
    set_level(2);
    set_hp(30);
    set_al(0);
    set_ac(6);
    set_wc(3);
    set_chance(10);
    set_spell_dam(2);
    set_spell_mess1("The cactus goes: Hey buddy! Do ya mind?");
    set_spell_mess2("The cactus pokes you. OUCH!!");
    set_chat_chance(5);
    load_chat("The cactus looks wistfully at you.\n");
    load_chat("The cactus says: All I want is to be hugged.\n");
    load_chat("The cactus says: A roast beef sandwich would be nice too.\n");
    load_chat("The cactus gets lost in a daydream.\n");
    treasure=clone_object("obj/money.c");
    treasure->set_money(60);
    move_object(treasure, this_object());
}
