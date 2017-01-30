inherit "/players/mizan/core/vehicle-shell-explosive.c";

reset(arg)
{
    ::reset();
    if(arg) return;

    set_get(1);
    set_value(300);
    set_weight(5);
    set_save_flag(1);
    set_name("shell");
    set_alias("88mm-shells");
    set_short("An 88mm howitzer shell (high explosive)"); 
    set_long("This is an 88mm howitzer shell of the high explosive variety.\n"+
             "The warhead tip is tungsten carbide, and the innards are filled\n"+
             "with a compressed high explosive of some sort. Don't drop this\n"+
             "shell, as it would be a bad thing.\n");

    set_base_damage(30);
    set_random_damage(50);

    /*
    set_spent_ammo_file("");
    */
}