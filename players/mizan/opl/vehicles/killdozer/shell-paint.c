inherit "/players/mizan/core/vehicle-shell-paint.c";

reset(arg)
{
    ::reset();
    if (arg) return;

    set_get(1);
    set_value(50);
    set_weight(3);
    set_save_flag(1);
    set_name("shell");
    set_alias("88mm-shells");
    set_short("An 88mm howitzer shell (filled with dye)");
    set_long("This is an 88mm howitzer shell, but it is filled with dye instead\n"+
             "of an incindiary explosive warhead.\n");

    set_room_residue_file("/players/mizan/samples/vehicles/tiger1/shell-room-residue.c");
    set_player_residue_file("/players/mizan/samples/vehicles/tiger1/shell-player-residue.c");

    /*
    set_spent_ammo_file("");
    */
}