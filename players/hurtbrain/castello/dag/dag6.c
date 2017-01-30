
inherit "room/room";

reset(arg) {
    object mark;
   if(arg) return;
    short_desc = "Mark's room" ;
    long_desc = "You enter a beautiful large room. All you see\n" +
    "here is charming; there's a wonderful table in the middle\n" +
    "of the room, some chairs around it and a bust of a young\n" +
    "charming man near you.\n" ;
    dest_dir =
    ({
    "/players/hurtbrain/castello/dag/dag5" ,"south"  ,
    "/players/hurtbrain/castello/dag/dag7" ,"west"
    }) ;
  
        mark = clone_object("/players/hurtbrain/castello/dag/mark.c");
        move_object(mark,this_object());
    set_light(1) ;
}
