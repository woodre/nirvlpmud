
inherit "room/room";

reset(arg) {
   object obj;
   if(arg) return;
    short_desc = "Boss' den" ;
    long_desc = "This is the room of the boss. There are many control panel\n"+
    "on every wall and a large table in the center of the room with four\n"+
    "chairs around it. Some pictures on the wall seems to adorn the room\n"+
    "but it feels there is something evil.\n";
   dest_dir =
   ({
    "/players/hurtbrain/quest/cove_ur","east",
    "/players/hurtbrain/quest/cove_magg","northeast",
    } ) ;
    set_light(1) ;
       obj=clone_object("/players/hurtbrain/quest/e_boss.c");
       move_object(obj,this_object());
}
realm(){return "NT";}

void init() {
	::init();
	add_action("note","east");
	}

note()   {
	if(present("boss",environment(this_player())))
		{
		write("The boss won't let you pass. You have to kill him!\n");
		return 1;
		}
	}
