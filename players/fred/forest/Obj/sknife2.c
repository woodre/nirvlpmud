#include "/players/fred/ansi.h"
inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("knife");
  set_short(RED+"Swiss"+NORM+" Army Knife");
  set_long(
 "   A small poket knife with many little gadgets you can use\n"+
 "on it.  There is some small writing on the knife.  For things\n"+
 "can do with this type 'knife_help'.\n" );
  set_type("knife");
  set_class(16);
  set_weight(2);
  set_value(2000);
  }

init(){
  ::init();
    add_action("knifem", "knife_help");
    add_action("openme", "knife");
    add_action("closem", "close"); 
  }

knifem(){
  write("You may use the following gadgets: blade, fork, spoon, toothpick, scissors.\n");
  write("Simply 'knife <gadget>' \n");
  return 1; }
  
openme(string str){
   object blade, fork, spoon, toothpick, scissors; 
   if(str == "blade"){
     write("You pull out the blade on the knife.\n");
     this_object()->set_short(RED+"Swiss"+NORM+" Army Knife"+BOLD+HIB+" <"+NORM+BOLD+"blade"+HIB+">"+NORM);
     this_object()->set_long(
     "   A small poket knife with many little gadgets you can use\n"+
     "on it.  There is some small writing on the knife.  For things\n"+
     "can do with this type 'knife_help'.\n" );             
     }
   else if(str == "fork"){
     write("You pull out the fork on the knife.\n");
     this_object()->set_short(RED+"Swiss"+NORM+" Army Knife"+BOLD+HIB+" <"+NORM+BOLD+"fork"+HIB+">"+NORM);
     this_object()->set_long(
     "   A small poket knife with many little gadgets you can use\n"+
     "on it.  There is some small writing on the knife.  For things\n"+
     "can do with this type 'knife_help'.\n" );
     }
   else if(str == "spoon"){
     write("You pull out the spoon on the knife.\n");
     this_object()->set_short(RED+"Swiss"+NORM+" Army Knife"+BOLD+HIB+" <"+NORM+BOLD+"spoon"+HIB+">"+NORM);    
     this_object()->set_long(
     "   A small poket knife with many little gadgets you can use\n"+
     "on it.  There is some small writing on the knife.  For things\n"+
     "can do with this type 'knife_help'.\n" );   
     }
   else if(str == "toothpick"){
     write("You pull out the toothpick on the knife.\n");
     this_object()->set_short(RED+"Swiss"+NORM+" Army Knife"+BOLD+HIB+" <"+NORM+BOLD+"toothpick"+HIB+">"+NORM);   
     this_object()->set_long(
     "   A small poket knife with many little gadgets you can use\n"+
     "on it.  There is some small writing on the knife.  For things\n"+
     "can do with this type 'knife_help'.\n" );
     }
   else if(str == "scissors"){
     write("You pull out the scissors on the knife.\n");
     this_object()->set_short(RED+"Swiss"+NORM+" Army Knife"+BOLD+HIB+" <"+NORM+BOLD+"scissors"+HIB+">"+NORM);
     this_object()->set_long(
     "   A small poket knife with many little gadgets you can use\n"+
     "on it.  There is some small writing on the knife.  For things\n"+
     "can do with this type 'knife_help'.\n" );
     }
   else {
     write("Sorry that isn't on this knife.\n");
     return 1; }
   return 1;  
 }

closem(str){
  if(!str){ write("Close what?\n"); return 1; }
  if(str == "knife"){
    write("You close the knife.\n");
    this_object()->set_short(RED+"Swiss"+NORM+" Army Knife");
    set_long(
    "   A small poket knife with many little gadgets you can use\n"+
    "on it.  There is some small writing on the knife.  Maybe you\n"+
    "could 'read' it.\n" );
    return 1; }
   }

 
 
   

