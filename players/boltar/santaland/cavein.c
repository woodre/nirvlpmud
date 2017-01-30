int digcount;
id(str) { return str == "trail"; }
init() {
      digcount = 0;
       set_light( 1);
      add_action("east","east");
      add_action("dig","dig");
}
short() { return "Cave in area."; }
long() {
   write("As you move into this region of the cavern, snow falls in on top\n"+
   "of you. You feel as though you have been hurt.  It looks like you will\n"+
   "need to get the snow out of your way to get back to the main part of the\n"+
   "cavern.\n");
call_other(this_player(), "add_hit_point", -5);
}
 east() {
   if (digcount == 0) {
  write("There's too much snow, you can't walk through it.\n");
  return 1;
}
  digcount = 0;
 call_other(this_player(), "move_player", "by digging through the snow#players/boltar/santaland/snowdeep.c");
   return 1;
}
dig() {
  write("The snow is soft and you dig through it easily.\n");
  write("However your hands feel as if they are frozen.\n");
   digcount = 1;
  return 1;
}
