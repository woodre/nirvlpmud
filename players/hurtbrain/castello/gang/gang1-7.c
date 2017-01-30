

inherit "room/room";

reset(arg) {
   object obj,obj2,obj3;
   int num,k;
   if(arg) return;
    short_desc = "A dusty road (level 1 zone)" ;
    long_desc = "You are in a dusty road. You think probably you are sleeping\n" +
    "and dreaming 'cause everyone here is wearing years 60's dresses.\n" +
    "You see only some child, girls and few kittens\n";
   dest_dir =
   ({
    "/players/hurtbrain/castello/gang/gang1-10" ,"south" ,
    "/players/hurtbrain/castello/gang/gang1-6" ,"west" ,
    "/players/hurtbrain/castello/gang/gang1-4" ,"north"
    } ) ;
    num=random(3);
    for (k=0 ; k<2+num ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/gang/girl.c");
	move_object(obj,this_object());
	}
    num=random(3);
    for (k=0 ; k<2+num ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/gang/shoeshine.c");
	move_object(obj,this_object());
	}
    num=random(3);
    for (k=0 ; k<2+num ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/gang/kitten.c");
	move_object(obj,this_object());
	}
    set_light(1) ;
}
