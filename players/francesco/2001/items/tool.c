#include "/players/francesco/univ/ansi.h"
inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if (arg) return;
   
set_name("tool");
set_alias("knife");
set_alt_name("weapon");
set_short("A tool");
set_long("This tool is basically a knife, like the one anciently used by\n"+
         "the Swiss Army.  By simple movements, it can be used either as\n"+
         "a knife, or as a screw driver,  or as a saw, or as a scissor,\n"+ 
         "or as a can opener, or even as a toothpick.  After the technology\n"+
         "demands increased, it had been added some new features which make\n"+
        "it effective also in electronic devices repair and maintenance.\n");
set_type("knife");
  set_class(15);
  set_weight(1);
  set_value(300);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
 if(W>8)  {return random(3)+4;}
 if(W<1)  {return random(2)+2;}
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
    if(str=="tool"){
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

