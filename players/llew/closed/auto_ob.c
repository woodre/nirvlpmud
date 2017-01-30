start() {
/*
   call_other("players/llew/closed/lsong/lsong","???",0);
*/
   if(!present("obituary",find_object("room/vill_green")))
      move_object(clone_object("players/llew/Other/misc/obituary"),"room/vill_green");
}

