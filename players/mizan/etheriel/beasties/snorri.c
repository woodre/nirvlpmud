inherit "obj/monster";
reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("snorri");
    set_race("snorri");
    set_alias("snori");
    set_short("Snorri");
    set_long("The thing called Snorri seems to be just another colored blob\n"+
    "of ether-muck, but one thing stands out from it. It seems to make you\n"+
    "happy. You feel so happy and joyous when its around you that you...\n"+
    "that you... that you want to KILL it!\n");
    set_level(14);
    set_hp(210);
    set_al(1000);
    set_ac(11);
    set_wc(18);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Snorri flies through your head! You feel a bit woozy.");
    set_spell_mess2("Snorri floats through your stomach and makes you feel like tossing cookies.");
    set_chat_chance(4);
    load_chat("Snorri makes a puffing noise.\n");
    load_chat("You feel happy! Ecstatic! Bubbling with joy!\n");
    weapon=clone_object("players/mizan/etheriel/heals/gargle-blaster.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/items/spuckballs.c");
    move_object(treasure, this_object());
}

