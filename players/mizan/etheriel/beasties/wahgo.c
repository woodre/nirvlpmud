inherit "/players/mizan/core/monster.c";

reset(arg) 
{
    object weapon,treasure,treasure2;
    ::reset(arg);
    if(arg) return;
    set_name("wahgo the impotent ostrich");
    set_race("ostrich");
    set_alias("wahgo");
    set_short("Wahgo the impotent ostrich");
    set_long("Wahgo looks very distraught. He is startled by any sound...\n"+
    "ANY sound, so it would be very rude of you to dress up as a wolf\n"+
    "and surprise him. No, it would not be a good idea to do such a thing.\n");
    set_level(12);
    set_hp(180);
    set_al(0);
    set_ac(8);
    set_wc(16);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Wahgo goes: Yo man! You're making me pissed man!");
    set_spell_mess2("Wahgo flurfs and woggles at you!");
    set_chat_chance(20);
    load_chat("Wahgo says: Hey man... leave me alone...\n");
    load_chat("Wahgo complains: I got problems... prooooooblems.\n");
    load_chat("Wahgo beats his head against something.\n");
    weapon=clone_object("players/mizan/etheriel/items/ac-guitar.c");
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/items/spuckrifle.c");
    move_object(treasure, this_object());
    treasure2=clone_object("players/mizan/etheriel/items/spuckballs.c");
    move_object(treasure2, this_object());
}
