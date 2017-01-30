
inherit "obj/monster";

reset(arg) {
    object money;
    money=clone_object("obj/money");
    call_other(money, "set_money", random(100)+10);
    move_object(money, this_object());
  ::reset();

    set_name("Navy Cadet");
    set_alias("cadet");
    set_short("A Navy ROTC cadet");
    set_long("This one of the many proud NAVY cadets that attend IIT.\n"+
"Even though our country needs people like him/her (pick your own damn\n"+
"gender), they are pretty easy to kill.  Unless you are a high level.\n");
    set_level(3);
    set_wc(2);
    set_ac(1);
}
