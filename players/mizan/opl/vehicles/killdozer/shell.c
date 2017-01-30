inherit "/players/mizan/core/vehicle-shell-explosive.c";

reset(arg)
{
    ::reset();
    if (arg) return;

    set_get(1);
    set_value(200);
    set_weight(5);
    set_save_flag(1);
    set_name("shell");
    set_alias("88mm-shells");
    set_short("An 88mm howitzer shell");
    set_long("This is an 88mm howitzer shell of standard explosive variety.\n"+
             "The warhead tip is some sort of hardened steel, and the innards have some\n"+
             "with explosive of some sort. Don't drop this shell, as it would be a bad thing.\n");

    set_base_damage(20);
    set_random_damage(40);

    /*
    set_spent_ammo_file("");
    */
}