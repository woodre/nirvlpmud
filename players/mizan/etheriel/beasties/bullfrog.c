inherit "/players/mizan/core/monster.c";

get() 
{
    string t;
    write("The frog hops away.\n");
    t = call_other("/players/mizan/closed/RandomRoomDM.c","one_random");
    say("A frog jumps to destination " + t + ".\n");
    call_other("/players/mizan/etheriel/ROOMS/" + t, "???");
    move_object(this_object(), "/players/mizan/etheriel/ROOMS/" + t);
}

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("a frog");
    set_race("frog");
    set_short("A frog");
    set_alias("bullfrog");
    set_long("This is a typical bullfrog. It is chubby, slightly moist, and\n"+
    "most importantly, green.\n");
    set_level(1);
    set_hp(10);
    set_al(0);
    set_ac(3);
    set_wc(5);
    set_chance(10);
    set_spell_dam(1);
    set_spell_mess1("The frog goes: RIBBIT!");
    set_chat_chance(5);
    load_chat("The frog blinks.\n");
    load_chat("The frog goes: ribbit!\n");
    treasure=clone_object("obj/money.c");
    treasure->set_money(30);
    move_object(treasure, this_object());
}

query_save_flag() { return 1; }
