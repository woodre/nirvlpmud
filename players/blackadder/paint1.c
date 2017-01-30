reset(arg) {
}

long(str) {
   write("A beautiful painting depicting a circle of large stones with an\n");
   write("altar in the center.\n");
}

short(str) {
   return "A painting of a circle of stones";
}

init() {
   add_action("enter","enter");
}

id(str) {
   return str == "painting";
}

enter(str) {
   if (str != "painting")
      return 0;
   say(call_other(this_player(),"query_name",0) + " enters the painting.\n");
   call_other(this_player(),"move_player","through the painting#/players/blackadder/w1/circle");
   return 1;
}
