#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
set_id("heart");
set_alias("sinja_heart");
set_short("The "+RED+"heart"+NORM+" of the dreaded Sinja worm");
set_long("This is the heart of the dreaded Sinja worm.  It is about seven times\n"+
         "the size of a human heart.  There are twenty different chambers to it\n"+
         "and the blood has a yellowish tint to it.  Legend speaks of health\n"+
         "coming from the digestion of the heart, but be warned for legend also\n"+
         "speaks of the death of many.\n");
set_weight(3);
}

init(){
  add_action("eatme","eat");
}

eatme(str){
  if(!str || str != "heart"){
    notify_fail("What would you like to eat?\n");
  return 0;
}
write("You eat the heart.\nPain rips through your body as its blood mingles with yours.\nWith a surge of strenght you seem to regain your health.\n");
say(this_player()->query_name()+" eats the Sinja's heart.\n");
this_player()->hit_player(40);
this_player()->heal_self(1000);
destruct(this_object());
return 1;
}
