#include "/players/jaraxle/define.h"
inherit "obj/treasure";

reset(arg){
   if(arg) return;
   set_alias("scroll");
   set_weight(1);
   set_value(0);
   set_short("Scroll of Nirvana");
   set_long("A thick scroll, rolled up into a tube.\n");
}
id(str){ 
   return str == "scroll of nirvana" || str == "scroll" || str == "nirvana";
}


init(){
   add_action("cmd_teleport","intone");
   add_action("cmd_read","read");
}

cmd_read(str){
   if(str == "scroll" || str == "scroll of nirvana" || str == "nirvava scroll"){
      write("\n"+
         "  A long time ago a prophet was born unto the land.\n"+
         "  with his birth came a new language of the gods.\n"+
         "\n"+
         "  Many people tried to mimic the spoken word of\n"+
         "  the true prophet, but only one man had been of\n"+
         "  the knowledge to document such task.  Written in\n"+
         "  blood from my own flesh I have inked the page of\n"+
         "  this scroll with what I have learned.\n"+
         "\n"+
         "  Hidden within the scripture of this scroll are\n"+
         "  the phrases I have learned.\n"+
         "\n"+
         "                               Armageddon.\n");  
      return 1; }
   notify_fail("Read what?\n");
   return 0; }

cmd_teleport(str){
   
   if(str == "norhop shuway"){
      write("You intone the words, 'Norhop Shuway'\n");
      say(TP+" intones some words in a strange tongue.\n");
      return 1;
   }
   if(str == "hohel kutkh"){
      write("You intone the words, 'Hohel Kutkh'\n");
      say(TP+" intones some words in a strange tongue.\n");
      return 1;
   }
   notify_fail("What would you like to intone?\n");
   return 0; }

void long(string arg)
{
   ::long(arg);
   if(this_player()->query_attrib("int") > random(150))
      return (write("This scroll has incantations of teleportation\n"+
         "upon which can be intoned when you read it.\n"));
}
