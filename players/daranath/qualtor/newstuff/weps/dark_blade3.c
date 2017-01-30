#include <ansi.h>
#define tp this_player()->query_name()
#define targ capitalize(attacker->query_name())
 inherit "obj/weapon.c";
int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("dark blade");
set_type("sword");
set_alias("blade");
set_short(BOLD+BLK+"Dark Blade"+NORM);
set_long("A blade made from the darkest of steel, this blade seems\n"+
         "extremely light and powerful for its size.\n");
set_class(18);
set_weight(2);
set_value(4400);
set_hit_func(this_object());
}

weapon_hit(attacker){
string here;
a = random(4);
here = environment(this_player());

if(a == 0){
tell_room(here,
  tp+" strikes at "+targ+" with the "+BOLD+BLK+"Dark Blade"+NORM+".\n");
if(call_other(this_player(),"query_attrib","pie") > random(50)) {
  return 3; }
}
if(a == 1){
tell_room(here,
  tp+" slashes "+targ+" with the "+BOLD+BLK+"Dark Blade"+NORM+".\n");
if(call_other(this_player(),"query_attrib","pie") > random(50)) {
  return 3; }
}
if(a > 1){
tell_room(here,
  "Shadows fill the area from the "+BOLD+BLK+"Dark Blade"+NORM+" as "+tp+" fights with it.\n");
}
}
