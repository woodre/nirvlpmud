inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,ring,boots,shield,armor,gloves,helm;
    ::reset(arg);
    if(arg) return;
    set_name("vapor knight");
    set_race("vapor knight");
    set_alias("knight");
    set_short("A Vapor Knight");
    set_long("	This appears to be just like any knight that you have seen,\n"+
    "but his armor and most of him (or its?) is totally translucent!\n");
    set_level(18);
    set_hp(395);
    set_al(400);
    set_ac(26);
    set_wc(24+random(6));
    set_chance(15);
    set_spell_dam(35);
    set_spell_mess1("The Vapor Knight lands a daring blow!");
    set_spell_mess2("The Vapor Knight cries: Death to you infidels!");
    set_chat_chance(6);
    load_chat("The Vapor Knight seems to gaze right through you...\n");
    load_chat("The Vapor Knight makes a droning noise.\n");
    load_chat("The Vapor Knight mumbles: Lord... where the fuck am I?\n");
    load_chat("The Vapor Knight asks: You there! Do you know the way out??\n");
    weapon=clone_object("players/mizan/etheriel/items/dayblade.c");
    move_object(weapon, this_object());
    boots=clone_object("players/mizan/etheriel/items/vboots.c");
    move_object(boots, this_object());
    shield=clone_object("players/mizan/etheriel/items/vshield.c");
    move_object(shield, this_object());
    armor=clone_object("players/mizan/etheriel/items/vmail.c");
    move_object(armor, this_object());
    ring=clone_object("players/mizan/etheriel/items/ering.c");
    move_object(ring, this_object());
    gloves=clone_object("players/mizan/etheriel/items/vgauntlets.c");
    move_object(gloves, this_object());
    helm=clone_object("players/mizan/etheriel/items/vhelm.c");
    move_object(helm, this_object());
}
