inherit "obj/treasure.c";

int current_page;

reset(arg)
{
    if(arg) return;
    current_page = 0;
}

short() { return "A map"; }

long(str) {
    write("The map of the Space Shuttle 5. You can read it.\n");
	return;
    }
    

init() {
    add_action("read_map","read");
    add_action("trade","trade");;
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
           "and therefore I can only give you 750 coins for this "+(str)+".\n");
      call_other(this_player(),"add_money",(750));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}

read_map(str) {
  if (present(str)==this_object()){
     write("    \n   The Map of Space Shuttle 5\n\n"+
           "                           1   \n"+
           "                          / \\ \n"+
           "1 Cockpit                /   \\ \n"+
           "2 Navigator Room        2 - - 3\n"+
           "3 Control Room          |     |\n"+
           "4 Observatory           |  4  |\n"+
           "5 Corridor              |   \\ |\n"+
           "6 Lounge                5 - - 5\n"+
           "7 Long distance calls   | \\   |\n"+
           "8 Cargo Bay             |  6  |\n"+
           "                        |     |\n"+
           "                        7 - - 8\n" );
     return 1; }
return 0;     
}


query_weight() { return 1; }

query_value() { return (300); }

/*
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
*/
