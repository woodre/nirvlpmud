inherit "obj/treasure.c";

reset(arg)
{
    if(arg) return;
}

short() { return "An envelope"; }

long(str) {
    write("Of thick yellow paper, it has the words TOP SECRET written on it.\n");
	return;
    }
    

init() {
  add_action("trade","trade");
  return 1;
}
trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="envelope"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 1000 coins for this "+(str)+".\n");
      call_other(this_player(),"add_money",(1000));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}




id(str) { return str == "envelope" ; }

query_weight() { return 1; }

query_value() { return (350); }

/*
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
*/
