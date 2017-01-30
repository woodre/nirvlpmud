inherit "/obj/monster";

void reset(int arg){
    if(arg) return;
    ::reset(arg);
    set_name("warrior");
    set_alias("skull");
    set_race("undead");
    set_hp(random(35)+100);
    set_al(-500);
    set_aggressive(1);
    set_short("A Skull Warrior");
    set_long("The warrior is a servant of Lord Bane.\n");
    set_wc(13);
    set_ac(7);
    set_level(9);
/*
    set_chat_chance(10);
    load_chat("Warrior says: I welcome you to Lord Bane's Kingdom.\n");
    load_chat("Warrior says: There are many rooms, a shop, and a castle.\n");
    load_chat("Warrior says: Hey, don't get killed....\n");
    load_chat("Warrior says: Lord Bane is the ruler of this land.\n");
*/
    move_object(clone_object("/players/rumplemintz/weapon/bonsword"), this_object());
    move_object(clone_object("/players/rumplemintz/armor/boamulet"), this_object());
    init_command("wield sword");
    init_command("wear amulet");
}
