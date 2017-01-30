

inherit "room/room";

reset(arg) {
   object obj,obj2,obj3;
   int num,k;
   if(arg) return;
    short_desc = "A private room (level 3 zone)" ;
   long_desc = "This is a little private room where probably works the\n"+
   "women that are here. Some guests comes here from the other rooms to\n"+
   "make their party more enjoyable. You notice a bed in the centre of the\n"+
   "room.";
   dest_dir =
   ({
    "/players/hurtbrain/castello/gang/gang3-10" ,"south" ,
    "/players/hurtbrain/castello/gang/gang3-6" ,"west" ,
    "/players/hurtbrain/castello/gang/gang3-4" ,"north"
    } ) ;
    num=random(3);
    for (k=0 ; k<2+num ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/gang/bitch.c");
	move_object(obj,this_object());
	}
    num=random(3);
    for (k=0 ; k<2+num ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/gang/guestgun.c");
	move_object(obj,this_object());
	}
    set_light(1) ;
}
