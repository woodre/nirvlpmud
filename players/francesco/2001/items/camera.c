inherit "obj/treasure.c";

int current_page;

reset(arg)
{
    if(arg) return;
    current_page = 0;
    set_id("camera");
}

short() { return "A camera"; }

long(str) {
    write("This specialty camera had been designed to work also in \n"+
          "harsh environments, either in vacuum and in water, and \n"+
          "also in a wide range of temperatures.  Therefore it is\n"+
          "housed within a metallic container from which only the\n"+
          "main control buttons exit.\n");
	return;
    }
    
query_weight() { return 1; }

query_value() { return (200); }

init() {
  add_action("trade","trade");
  return 1;
}
trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="camera"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 500 coins for this "+(str)+".\n");
      call_other(this_player(),"add_money",(500));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}



/*
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
*/
