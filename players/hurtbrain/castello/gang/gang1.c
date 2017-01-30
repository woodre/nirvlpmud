

inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A corridor" ;
    long_desc = "You are at the beginning of a corridor. You feel something\n" +
    "here you have never proved. A strange calm surroundes you. North from\n" +
    "here there is the level 1 zone. Have fun!\n";
   dest_dir =
   ({
    "/players/hurtbrain/castello/entrance" ,"out"  ,
    "/players/hurtbrain/castello/gang/gang2" ,"east",
    "/players/hurtbrain/castello/gang/gang1-9" ,"north"
    } ) ;
    set_light(1) ;
}
