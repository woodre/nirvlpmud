#include <ansi.h>
#define tp this_player()->query_name()
#define targ capitalize(attacker->query_name())
 inherit "obj/weapon.c";
int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("minotaur blade");
set_type("blade");
set_short("Minotaur TwinBlade");
set_long("A twin-bladed sword, perfect for the large hands and strong body of\n"+
         "the minotaur race. This blade is considered quite valuable when it\n"+
         "can be found.\n");
set_class(17);
set_weight(2);
set_value(1500+random(1000));
set_hit_func(this_object());
}

weapon_hit(attacker){
string here;
a = random(4);
here = environment(this_player());

if(a == 0){
tell_room(here,
 tp+" spins the Minotaur TwinBlade around before slashing "+this_player()->query_possessive()+" foe.\n");
if(call_other(this_player(),"query_attrib","str") > random(50)) {
  return 8; }
}
}
