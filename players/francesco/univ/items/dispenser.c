#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";


reset(arg){
    if (arg) return;
   

set_id("dispenser");
  set_alias("dispenser");
set_short(""+HIW+"An automatic food/beverages/alcohols dispenser"+NORM);
set_long("The dispenser holds a sign:  we are sorry,  sold out.\n"+
         "You might want to ask the personel for your needs.\n");

}


init() {
  ::init();
if(this_player() != environment(this_object())) 
  return; 
}


get(str) {
    if (str == "dispenser") {
        write("Dont try to steal the full content of the dispenser.\n"+
              "You should consume your items here.\n"+
              "No take away allowed.\n");
        return 0;
    }
    return 0;
}
