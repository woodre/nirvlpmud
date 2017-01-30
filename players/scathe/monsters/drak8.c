inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if (arg || root()) return;

    set_name("drak");
    set_race("dragon");
    set_short("The Lord Drak");
    set_long("\
The Lord Drak is huge, his size rivaling that of most large dragons.\n\
His size however, has not taken anything away from his speed, as his\n\
claws move in a frenzy rush at you.  You tremble in fear as you gaze\n\
upon him, and question if you can overcome this mighty monster.\n");
    set_aggressive(1);
    set_level(24);
    set_hp(700);
    set_al(-1000);
    set_wc(38);
    set_ac(21);
    set_chance(75);
    set_spell_dam(30+random(10));
    set_spell_mess1("The drak's teeth rip your flesh.");
    set_spell_mess2("The drak's teeth rip the flesh of its foe.");
    set_chat_chance(20);
    load_chat("The drak hisses and spits at you.\n");
    add_money(random(1000)+40);
    move_object(clone_object("/players/scathe/closed/rod2"), this_object());
}
