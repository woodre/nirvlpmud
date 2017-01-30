#include <ansi.h>
#define tp this_player()->query_name()
#define targ capitalize(attacker->query_name())
 inherit "obj/weapon.c";
int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("nameless");
set_type("sword");
set_alias("blade");
set_short("Nameless, the Legendary Blade");
set_long("With a blade as dark as the deepest shadow, the Legend\n"+
         "of Nameless began upon the day of its creation. The Coven of \n"+
         "witches and warlocks were completly drained of lifeforce\n"+
         "prior to the naming of the magical blade. Runes run along\n"+
         "its twisted hilt, forged from the backbone of a newborn\n"+
         "child. Dark steel forms the crosspiece, and blends into\n"+
         "the long, wicked blade itself.\n");
set_read("Believe in me, for I will bring thee power beyond imagination...\n");
set_class(18);
set_weight(3);
set_value(21700);
set_hit_func(this_object());
}

query_save_flag() {return 1; }

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
