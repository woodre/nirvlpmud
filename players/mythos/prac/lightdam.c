#define io  this_object()->short()
#define ao  this_object()->query_alias()
#define tp  this_player()->query_name()
#define eo  environment(this_object())
#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/amisc/treasure1";
reset(arg) {
  if(arg) return;
    set_id("lightdam");
    set_weight(100000);
    set_value(0);
    set_follow(1);
    set_mounted(0);
    set_noise(0);
}

init() {
  ::init();
  call_out("checker",3);
}

checker() {
int is_light;
  if(this_object()->query_follow()) {
  if(!present(this_object()->query_owner(),eo)) {
  if(!find_player(this_object()->query_owner())) { 
  destruct(this_object());
  return 1;}
  move_object(this_object(),environment(find_player(this_object()->query_owner())));
  }
  }
  is_light = set_light(0);
  find_player(this_object()->query_owner())->heal_self(-(is_light));
  is_light=0;
  call_out("checker",3); 
  return 1;}
  
  
