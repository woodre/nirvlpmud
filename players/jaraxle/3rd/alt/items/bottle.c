#include "/players/wocket/closed/ansi.h"
inherit "obj/treasure";
int b_status;
string contents;
string b_text;

reset(arg){
   if(arg) return;
   set_alias("bottle");
   set_weight(1);
   set_value(500);
   set_long("");
}
id(str){ 
   if(!b_status) return str == "bottle";
  else return str == "spirit_in_a_bottle" || str == "bottle";
}

short(){
   if(b_status == 0){
      b_text = "empty";
      contents = "nothing";
   }
   if(b_status > 0){
      b_text = "full";
      contents = "a glooming spirit";
   }
   return "A bottle "+BLK+BOLD+"["+HIC+b_text+BLK+BOLD+"]"+NORM+""; }

init(){
   add_action("cmd_trap","capture");
}

cmd_trap(str){
   object p_spirit;
   p_spirit = present("phantom_spirit",environment(this_player()));
   
   if(!p_spirit){
      write("There are no spirits to capture here.\n");
      return 1;
   }
   if(b_status != 0){ write("The bottle is full!\n"); return 1; }
   if(str == "spirit" || str == "phantom spirit"){
      write("You swing the bottle through the spirit and absorb its force.\n");
      b_status += 1;
      destruct(p_spirit);
      return 1;
   }
   notify_fail("What would you like to capture?\n");
   return 0; }

void long(string arg)
{
   ::long(arg);
   write("A clear glass bottle with "+contents+" inside.\n");
   if(this_player()->query_attrib("int") > random(150))
      return (write("This bottle is used to "+BOLD+"capture"+NORM+" spirits.\n"));
}
