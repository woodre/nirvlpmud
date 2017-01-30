

inherit "room/room";

reset(arg) {
   object obj,obj2,obj3;
   int num,k;
   if(arg) return;
    short_desc = "A lane (level 4 zone)" ;
   long_desc = "You are in a lane where the policemen block some sospect\n"+
   "men (probably gangsters). Some of them are carrying weapons but the\n"+
   "policemen are aiming them. Many people is looking at the scene a little\n"+
   "scared by the presence of some weapons.";
   dest_dir =
   ({
    "/players/hurtbrain/castello/gang/gang4-5" ,"south" ,
    "/players/hurtbrain/castello/gang/gang4-3" ,"east",
    "/players/hurtbrain/castello/gang/gang4-1" ,"northeast"
    } ) ;
    num=random(3);
    for (k=0 ; k<2+num ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/gang/killer.c");
	move_object(obj,this_object());
	}
    num=random(3);
    for (k=0 ; k<2+num ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/gang/policeman.c");
	move_object(obj,this_object());
	}
    set_light(1) ;
}
