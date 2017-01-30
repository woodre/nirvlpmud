
inherit "room/room";

reset(arg) {
        int k;
        object obj;
   if(arg) return;
    short_desc = "The Gaul" ;
    long_desc = "This is a roman camp. All the soldiers are looking at you\n" +
    "not very friendly. You'd better to be careful here. It's not your\n" +
    "home and the soldiers seems to be very nervous.\n" ;
   dest_dir =
   ({
        "/players/hurtbrain/castello/dag/gaul/gaul10" ,"southwest" , 
        "/players/hurtbrain/castello/dag/gaul/gaul9" ,"southeast" ,
        "/players/hurtbrain/castello/dag/gaul/gaul20" ,"northeast" 

    }) ;
    for (k=0 ; k<3+random(4) ; ++k)  {
        obj = clone_object("/players/hurtbrain/castello/dag/soldweap.c");
        move_object(obj,this_object());
         }
    if(random(2))  {
        obj = clone_object("/players/hurtbrain/castello/dag/gaul/centurion.c");
        move_object(obj,this_object());
    }
    set_light(1) ;
}
