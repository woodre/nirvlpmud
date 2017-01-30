short() {return "The private room"; }
long() {
   write("You have entered what looks like a large bathroom. There is a\n"+
         "toilet, a shower, a sink, a comfortable chair, a table, and some\n"+
         "magazines on the table. There is a door to the south.\n");
   return 1;
 }
init() {
 add_action("south","south");
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
     add_action("look", "read");

 }
south() {
  call_other(this_player(), "move_player", "south#players/boltar/sprooms/clinic/sbank.c");
  return 1;
}
look(str) {
   if (!str) {
   return 0;
  }
 if (str == "magazine" || str == "magazines") {
  write("All the common girli mags and a few catalogs.\n");
  write("\n");
   return 1;
  }
 if (str == "at toilet" || str == "toilet") {
  write("A common white porcelain toilet.\n");
  write("\n");
   return 1;
  }
 if (str == "at shower" || str == "shower") {
   write("An ordinary shower stall with a glass door.\n");
  write("\n");
   return 1;
  }
 if (str == "at chair" || str == "chair") {
  write("A nice soft, padded chair with a brown fabric cover.\n");
  write("\n");
   return 1;
  }
 if (str == "at sink" || str == "sink") {
  write("A common white porcelain sink.\n");
  write("\n");
   return 1;
  }
 if (str == "table" || str == "at table") {
   write("A ordinary regtanguar coffee table in front of the soft chair.\n");
  write("\n");
   return 1;
  }
return 0;
}
reset(arg) {
 if(!arg)
 set_light(1);
}
