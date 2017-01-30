reset(arg) {
}

long(str) {
   write("A beautiful tapestry depicting a hot tub.\n");
   write("It looks curiously out of place here.\n");
}

short(str) {
   return "A beautiful hanging tapestry";
}

init() {
   add_action("enter","enter");
}

id(str) {
   return str == "tapestry";
}

enter(str) {
   if (str != "tapestry")
      return 0;
   say(call_other(this_player(),"query_name",0) + " enters the tapestry.\n");
   call_other(this_player(),"move_player","through the tapestry#/players/blackadder/hideaway");
   return 1;
}
