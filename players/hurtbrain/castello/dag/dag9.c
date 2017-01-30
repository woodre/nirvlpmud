

inherit "room/room";

reset(arg) {
        object obj;
        int k,num;
   if(arg) return;
        set_light(1) ;
        short_desc = "The roman store" ;
        long_desc =
        "This is a strange place where you can see many broken swords\n"+
        "and shields. It seems that here a great battle was fought.\n"+
        "Up there are the alps and the way for the Gaul.\n";

   dest_dir =
   ({
        "/players/hurtbrain/castello/dag/gaul/alp1" ,"up" ,
        "/players/hurtbrain/castello/dag/dag10" ,"west" , 
        "/players/hurtbrain/castello/dag/dag18" ,"north" , 
        "/players/hurtbrain/castello/dag/dag8" ,"east" 
    }) ;
if(!present("gaul")) {
    num=4+random(4);
        for(k=0;k<num;++k)
                {
                obj=clone_object("players/hurtbrain/castello/dag/gallo.c");
                move_object(obj,this_object());
                }
  }
}
