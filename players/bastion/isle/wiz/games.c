inherit "room/room";
object disp;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "games";
    no_castle_flag = 1;
    long_desc = 
        "You are in an empty room. The walls are bare.\n"+
        "There is nothing here, there is an opening to the north.\n";
    dest_dir = ({"players/bastion/isle/wiz/e_hall2", "north"});
}

