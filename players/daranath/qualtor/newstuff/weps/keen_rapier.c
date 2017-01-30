#include <ansi.h>
#define tp this_player()->query_name()
#define targ capitalize(attacker->query_name())
 inherit "obj/weapon.c";
int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("keen rapier");
set_type("sword");
set_alias("rapier");
set_short(WHT+"A keen Rapier"+NORM);
set_long("Made of Damascus steel, this rapier holds a razor-sharp edge that lesser\n"+
         "blades cannot match. Its ornate hilt and perfect balance are\n"+
         "further testimony to the craftmanship that went into\n"+
         "its creation.\n");
set_class(20);
set_weight(1);
set_value(2750);
set_hit_func(this_object());
}

query_save_flag() {return 1; }

weapon_hit(attacker){
string here;
a = random(4);
here = environment(this_player());

if(a == 0){
tell_room(here,
  tp+" strikes at "+targ+" with the "+WHT+"Keen Rapier"+NORM+".\n");
if(call_other(this_player(),"query_attrib","pie") > random(50)) {
  return 5; }
}
if(a == 1){
tell_room(here,
  tp+" slashes "+targ+" with the "+WHT+"Keen Rapier"+NORM+".\n");
if(call_other(this_player(),"query_attrib","pie") > random(50)) {
  return 7; }
}
if(a > 1){
tell_room(here,
  tp+" spins around and slashes again with the "+WHT+"Keen Rapier"+NORM+".\n");
}
}
