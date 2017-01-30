
inherit "obj/monster";

reset(arg) {
    object money;
    money=clone_object("obj/money");
    call_other(money, "set_money", random(50)+100);
    move_object(money, this_object());
::reset(arg);
   if(!arg) {

    set_name("An Army ROTC cadet");
    set_alias("cadet");
    set_short("Army cadet");
    set_long("This is a cadet of the U.S. Army.\n");
    set_level(5);
    set_hp(100);
    set_wc(5);
    set_ac(2);
}
}
