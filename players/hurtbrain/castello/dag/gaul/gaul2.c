

inherit "room/room";

reset(arg) {
        object obj;
        int k,num;
   if(arg) return;
        set_light(1) ;
        short_desc = "The Gaul" ;
        long_desc =
        "This is a camp of Gaul's soldiers. There are many drunked soldiers\n"+
        "and some stranges construction to repair the men from the rain.\n";
   dest_dir =
   ({
        "/players/hurtbrain/castello/dag/gaul/gaul3" ,"west" , 
        "/players/hurtbrain/castello/dag/gaul/gaul1" ,"east" ,
        "/players/hurtbrain/castello/dag/gaul/gaul9" ,"northeast" 
    }) ;
    num=4+random(4);
        for(k=0;k<num;++k)
                {
                obj=clone_object("players/hurtbrain/castello/dag/gallo.c");
                move_object(obj,this_object());
                }
}
