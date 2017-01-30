#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "/obj/treasure.c";

int licks;

reset(){
  set_id("lollipop");
  SetMultipleIds(({"sucker", "tootise", "tootsie pop", "pop"}));
  short_desc = "A "+RED+"Tootsie "+NORM+BOLD+"Pop"+NORM+"";
 long_desc = "A small Tootsie Pop. The only obvious thought is to lick it.\n";
  set_weight(1);
  licks = 10+random(5);
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
    licks --;
      if(!licks){
        write("Excited by the intense flavor you CHOMP down and devour it instantly.\n");
 say(TPN+"'s eyes suddenly light up as "+this_player()->query_pronoun()+" CHOMPS down on it devouring it.\n");
      destruct(TO);
      TP->recalc_carry();
    return 1; }
 return 1; }
}  

query_save_flag(){ return 1; }
query_value(){ return 10; }
get(){ return 1; }



   
      
              
    
