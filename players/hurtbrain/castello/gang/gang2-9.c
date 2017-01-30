

inherit "room/room";

reset(arg) {
   object obj,obj2,obj3;
   int num,k;
   if(arg) return;
    short_desc = "A party (level 2 zone)" ;
   long_desc = "You find yourself in a big room with hundreds of men, \n"+
   "probably it's a party . Many people is dancing but the most part is\n"+
   "talking. Every man is dressed in blue dress and top-hat and every woman\n"+
   "in white long dress and ostrich feathers.";
   dest_dir =
   ({
    "/players/hurtbrain/castello/gang/gang2" ,"south" ,
    "/players/hurtbrain/castello/gang/gang2-8" ,"west" ,
    "/players/hurtbrain/castello/gang/gang2-10" ,"east",
    "/players/hurtbrain/castello/gang/gang2-6" ,"north"
	});
    num=random(3);
    for (k=0 ; k<2+num ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/gang/boy.c");
	move_object(obj,this_object());
	}
    num=random(3);
    for (k=0 ; k<2+num ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/gang/guesthat.c");
	move_object(obj,this_object());
	}
    set_light(1) ;
}
