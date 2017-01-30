#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon.c";

reset(arg){
 if(arg) return;
set_alt_name("songsword");
set_alias("songsword");
set_type("sword");
set_short(BOLD+"The angelic sword of songs"+NORM);
set_class(15);
set_weight(1);
set_value(1000);
set_hit_func(this_object());
}

init(){
::init();
  if(environment(this_object()) == this_player())
  if(this_player()->query_attrib("pie") < 20){
    write("Your arm burn from holy goodness as you try to pick up the sword.\n");
  command("drop songsword",this_player());
  this_player()->add_hit_point(-random(30));
 }
set_class(15+ ((this_player()->query_attrib("str")+20)/10));
}

weapon_hit(attacker){
if(20 > random(60)){
  write(BOLD+"The blade sings with the grace of angels.\n"+OFF);
  return 5;
}
}
