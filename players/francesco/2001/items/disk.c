inherit "obj/treasure.c";

reset(arg)
{
    if(arg) return;
}

short() { return "9 inches floppy disk"; }

long(str) {
    write("This large capacity floppy disk can hold the full\n"+
          "Operating System of HAL 9000 serie computers.\n");
	return;
    }
    
id(str) { return str == "disk" ; }

query_weight() { return 1; }

query_value() { return (300); }

init() {
  add_action("trade","trade");
  return 1;
}
trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="disk"){
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


/*
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
*/
