
inherit "obj/treasure";
reset(arg){
    if (arg) return;

    set_id("scroll");
    set_short("A scroll of rejuvenation");
    set_long(
      "This is a scroll of rejuvenation.  The neat, hand written black writing\n"+
      "is on a faded white parchment.  By 'read'ing this scroll, you shall\n"+
      "once again thrive with life and energy.\n");
    set_weight(1);
    set_value(10000);
}

void init(){  add_action("read_cmd", "read"); }

status read_cmd(string str){
    int x,y;
    if(str != "scroll") return 0;
    write("You read the scroll of rejuvenation...\n"+
      "You suddenly feel empowered and refreshed.\n");
    if(this_player()->query_ghost()) /* ? */
	this_player()->remove_ghost();
    else
	this_player()->heal_self(666);
    if(present("circle_object", this_player()))
    {
	x = (int)present("circle_object", this_player())->query_endurance();
	y = (int)present("circle_object", this_player())->query_max_endurance();
	present("circle_object", this_player())->add_endurance(y-x);
    }
    local_weight = 0;
    destruct(this_object());
    return 1;
}

