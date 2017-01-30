

inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A corridor" ;
    long_desc = "You are at the bottom of a corridor. You feel something\n" +
    "here you have never proved. A strange calm surroundes you. North from\n" +
    "here there is the level 5 zone. Have fun!\n";
   dest_dir =
   ({
    "/players/hurtbrain/castello/gang/gang4" ,"west",
    "/players/hurtbrain/castello/gang/gang5-9" ,"north"
    } ) ;
    set_light(1) ;
}
