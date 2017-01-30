

inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A corridor" ;
    long_desc = "You are in the middle of a corridor. You feel something\n" +
    "here you have never proved. A strange calm surroundes you. North from\n" +
    "here there is the level 2 zone. Have fun!\n";
   dest_dir =
   ({
    "/players/hurtbrain/castello/gang/gang1" ,"west",
    "/players/hurtbrain/castello/gang/gang3" ,"east",
    "/players/hurtbrain/castello/gang/gang2-9" ,"north"
    } ) ;
    set_light(1) ;
}
