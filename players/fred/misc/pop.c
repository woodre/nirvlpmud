#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "/obj/treasure.c";


reset(){
  set_id("lollipop");
  SetMultipleIds(({"sucker", "tootise", "tootsie pop", "pop"}));
  short_desc = "A "+RED+"Tootsie "+NORM+BOLD+"Pop"+NORM+"";
 long_desc = "A small Tootsie Pop. The only obvious thought is to lick it.\n";
  set_weight(1);
}

init(){
  ::init();
   add_action("You_are_the_weakest_link_good_bye","lick");
 }

You_are_the_weakest_link_good_bye(str){
  if(str == "sucker" || str == "tootsie" || str == "tootsie pop" ||
     str == "lollipop" || str == "pop"){
    write("You put the Tootsie Pop into your mouth and give it a lick.\n");
    say(TPN+" slowly drags "+POS+" tongue across the Tootsie Pop.\n");
 return 1; }
}  

query_save_flag(){ return 1; }
query_value(){ return 10; }
get(){ return 1; }
query_auto_load(){ return "/players/fred/misc/pop.c:"; }
