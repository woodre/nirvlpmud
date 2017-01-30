id(str) { return "fg";}
init() {
   call_other("players/boltar/workroom","init",0);
   call_other("players/boltar/workroom","reset",0);
   write("Done.\n");
   return 1;
}
