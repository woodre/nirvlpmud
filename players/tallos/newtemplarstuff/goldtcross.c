#include "/players/tallos/ansi.h"
#include "/players/jaraxle/define.h"
inherit "obj/armor";
#define tp owner->query_name()

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("cross") ;
   set_alias("bling");
   set_short(""+HIW+"A "+NORM+""+YEL+"GOLDEN CROSS"+HIW+" of the"+HIB+" Knights Templar"+NORM);
   set_long(" "+NORM+""+YEL+"                      \n"+
            "               \\        /                 \n"+
            "                \\      /                                    \n"+
            "                 \\    /                   \n"+
            "                  \\  /                                       \n"+
            "                   ()                          \n"+
            "                  /||\\                       \n"+
            "                 /*||*\\                                            \n"+
            "                /**||**\\                                     \n"+
            "               /***||***\\                 \n"+
            "              /****||****\\               \n"+
            "             /*LAUS||*UT**\\                \n"+
            "         ||||||||||||||||||||||                \n"+
            "             \\*LUX*||LUCIS/                 \n"+
            "              \\****||****/                \n"+
            "               \\***||***/                 \n"+
            "                \\**||**/                 \n"+
            "                 \\*||*/                 \n"+
            "                  \\||/                      \n"+ 
            "                   ||                             \n"+
            "                   ||                           \n"+
            "                   ||                                                 \n"+
            "                                "+NORM+"           \n");
   set_params("other|unholy",0,10,0);
   set_params("other|evil",0,10,0);      
   set_weight(1);
   set_value(0);
   set_type("necklace") ;
   set_ac(1) ;
}
init() {
  ::init();
  add_action("Read","read");
}
Read(str) {
if(!str) { write("What are you trying to read?\n"); return 1; }
if(str == "cross" || str == "gold cross") {
  write(""+HIW+"There is an inscription on the "+NORM+""+YEL+"cross"+HIW+":\n"+
	    "       "+NORM+""+YEL+"LAUS  UT  LUX  LUCIS\n"+
        ""+HIW+"It means: Praise to the "+HIY+"Light"+HIW+".\n");
  return 1; }
}