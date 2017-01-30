


inherit "obj/monster";
object colour;

reset(arg) {
    if(arg) return;
    set_name("gate guard");
    set_alias("guard");
    set_short("A gate guard");
    set_long("A strong looking soldier clad in a suit of leather armor.\n");
    set_level(10);
    set_hp(150);
    set_ac(5);
    set_wc(16);
    set_al(200);
    ::reset();
}

