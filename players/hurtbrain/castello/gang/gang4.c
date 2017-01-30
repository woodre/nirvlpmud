

inherit "room/room";

reset(arg) {
   if(arg) return;
    short_desc = "A corridor" ;
    long_desc = "You are in the middle of a corridor. You feel something\n" +
    "here you have never proved. A strange calm surroundes you. North from\n" +
    "here there is the level 4 zone. Have fun!\n";
   dest_dir =
   ({
    "/players/hurtbrain/castello/gang/gang3" ,"west",
    "/players/hurtbrain/castello/gang/gang5" ,"east",
    "/players/hurtbrain/castello/gang/gang4-9" ,"north"
    } ) ;
    set_light(1) ;
}
