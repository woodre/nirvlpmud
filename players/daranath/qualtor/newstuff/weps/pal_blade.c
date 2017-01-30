#include <ansi.h>
#define tp this_player()->query_name()
#define targ capitalize(attacker->query_name())
 inherit "obj/weapon.c";
int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("holy blade");
set_type("sword");
set_alias("blade");
set_short(WHT+"Holy Blade"+NORM);
set_long("Forged by the best dwarven craftsman in Qual'tor, then taken to the temples\n"+
         "to best blessed, the "+WHT+"Holy Blade"+NORM+" is awarded to each\n"+
         "of Qual'tors Paladins for duty in such dire circumstances.\n");
set_class(18);
set_weight(1);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
string here;
a = random(4);
here = environment(this_player());

if(a == 0){
tell_room(here,
  tp+" strikes at "+targ+" with the "+WHT+"Holy Blade"+NORM+".\n");
if(call_other(this_player(),"query_attrib","pie") > random(50)) {
  return 3; }
}
if(a == 1){
tell_room(here,
  tp+" slashes "+targ+" with the "+WHT+"Holy Blade"+NORM+".\n");
if(call_other(this_player(),"query_attrib","pie") > random(50)) {
  return 3; }
}
if(a > 1){
tell_room(here,
  "Light streams from the "+WHT+"Holy Blade"+NORM+" as "+tp+" fights with it.\n");
}
}
