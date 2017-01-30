id(str){
   return str == "boat";
}
init() {
   add_action("sail","sail");
}
long(){
   write(""+
      "This is a small wooden boat made for journeys into unknown areas\n"+
      "It seems sturdy for long travels, but it rock back and forth violently\n"+
      "from the sea.  It seems this boat is designed to travel in cold\n"+
      "waters like the arctic ocean.  Maybe you can 'sail arctic' and\n"+
      "travel to the frozen northland.\n"+
      "");
   return 1;
}
short(){
   return "A Small Wooden Boat";
}
sail(arg) {
   if(!arg) { write("Sail Where?\n"); return 1; }
   if(arg !="arctic") {
      write("Sorry, but this boat only sails to the arctic.\n");
      return 1;
   }
   write("You hop on board, and set sail for the arctic.\n");
   say(capitalize(this_player()->query_real_name()) +" sails to the arctic.\n");
   call_other(this_player(),"move_player","sailing#players/snow/beach/surf2.c");
   return 1;
}
