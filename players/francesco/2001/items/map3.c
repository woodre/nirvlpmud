inherit "obj/treasure.c";

int current_page;

reset(arg)
{
    if(arg) return;
    current_page = 0;
}

short() { return "A map"; }

long(str) {
    write("The map of Discovery. You can read it.\n");
	return;
    }
    

init() {
    add_action("read_map","read");
    add_action("trade","trade");
}

id(str) { return str == "map" ; }
trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="map"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 600 coins for this "+(str)+".\n");
      call_other(this_player(),"add_money",(600));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}



read_map(str) {
  if (present(str)==this_object()) {
     write("    \n            The Map of the Discovery\n\n"+
           " 1 Control Deck           1 - - - 3 - - - 2        \n"+
           "                         /        |        \\      \n"+
           " 2 Pod Bay              3         6         3      \n"+
           "                       /          |          \\    \n"+
           " 3 Centrifuge         3           6           3    \n"+
           "                      |           |           |    \n"+
           " 4 Hub Link           3 - 6 - 6 - 4 - 6 - 6 - 5     \n"+
           "                      |           |           |     \n"+
           " 5 Hibernation Room   3           6           3     \n"+
           "                       \\          |          /     \n"+
           " 6 Connecting Aisles    3         6         3       \n"+
           "                         \\        |        /       \n"+
           " 7 Cargo Bay              3 - - - 3 - - - 7        \n\n" );
     return 1; }
return 0;     
}


query_weight() { return 1; }

query_value() { return (250); }

/*
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
*/
