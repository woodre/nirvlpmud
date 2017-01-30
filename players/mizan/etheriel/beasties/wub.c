inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("a wub");
    set_race("wub");
    set_short("The wub");
    set_long("This thing looks sort of like a wombat. Actually it looks\n"+
    "more like a pig. Hmm. Hold on. Maybe not. Who cares!\n");
    set_level(3);
    set_hp(40);
    set_al(0);
    set_ac(4);
    set_wc(7);
    set_chance(10);
    set_spell_dam(4);
    set_spell_mess1("The wub stands up and says: Wouldnt you rather discuss things like Ishtar or Odysseus?");
    set_spell_mess2("The wub says: You are obsessed with the idea of killing me. I wonder why.");
    set_chat_chance(5);
    load_chat("The wub rolls around.\n");
    load_chat("The wub floats sideways.\n");
    load_chat("The wub licks itself.\n");
    treasure=clone_object("obj/money.c");
    treasure->set_money(100);
    move_object(treasure, this_object());
}
