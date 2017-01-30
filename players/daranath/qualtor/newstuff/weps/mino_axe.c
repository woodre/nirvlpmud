#include <ansi.h>
#define tp this_player()->query_name()
#define targ capitalize(attacker->query_name())
 inherit "obj/weapon.c";
int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("minotaur axe");
set_type("axe");
set_short("Minotaur BattleAxe");
set_long("A massive battleaxe, the mintoaur race is able to use it a bit better\n"+
         "due to thier larger size. A deadly weapon in the right hands.\n");
set_class(17);
set_weight(3);
set_value(750+random(750));
set_hit_func(this_object());
}

weapon_hit(attacker){
string here;
a = random(4);
here = environment(this_player());

if(a == 0){
tell_room(here,
 tp+" drives the Minotaur BattleAxe deep into "+targ+"'s body.\n");
if(call_other(this_player(),"query_attrib","str") > random(40)) {
  return 7; }
}
}
