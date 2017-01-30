#include <ansi.h>
#define tp this_player()->query_name()
#define targ capitalize(attacker->query_name())
 inherit "obj/weapon.c";
int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("blessed axe");
set_type("axe");
set_short("Blessed Battleaxe");
set_long("Dwarven priests have bless this battle axe to help with the fighting\n"+
         "in Qual'tor. The edge of the axe shines with expert craftmanship.\n");
set_class(16);
set_light(1);
set_weight(2);
set_value(500);
set_hit_func(this_object());
}

weapon_hit(attacker){
string here;
a = random(4);
here = environment(this_player());

if(a == 0){
tell_room(here,
  tp+" swing the deadly axe overhead, burying it within "+this_player()->query_possessive()+" foe.\n");
if(call_other(this_player(),"query_attrib","pie") > random(50)) {
  return 7; }
}
if(a > 0){
tell_room(here,
  "Light streams from the "+WHT+"Blessed Axe"+NORM+" during the fight.\n");
}
}
