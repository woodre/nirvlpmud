

inherit "room/room";

reset(arg) {
   object obj,obj2,obj3;
   int num,k;
   if(arg) return;
    short_desc = "A big room (level 5 zone)" ;
   long_desc = "You are in a big room with large balcony. You see the sun\n"+
   "throught the windows and som flowers on a table in the middle of the room.\n"+
   "This ust be the boss' room. Everything is in its own place and everyone\n"+
   "is well-dressed but noone is speaking. You see also some men that you\n"+
   "think they can be bodyguard.";
   dest_dir =
   ({
    "/players/hurtbrain/castello/gang/gang5-10" ,"south" ,
    "/players/hurtbrain/castello/gang/gang5-6" ,"west" ,
    "/players/hurtbrain/castello/gang/gang5-4" ,"north"
    } ) ;
    num=random(3);
    for (k=0 ; k<2+num ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/gang/boss.c");
	move_object(obj,this_object());
	}
    num=random(3);
    for (k=0 ; k<2+num ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/gang/bodyguard.c");
	move_object(obj,this_object());
	}
    set_light(1) ;
}
