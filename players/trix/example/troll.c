inherit "obj/monster.talk";

reset(arg) {
    set_name("troll");
    set_level(9);
    set_hp(100);
    set_wc(12);
    set_al(-60);
    set_short("A troll");
    set_long("It is a nasty troll that looks very aggressive.\n");
    set_aggressive(1);
    ::reset(0);
}
