#include "/players/mythos/closed/ansi.h"
#define tp this_player()
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("voice");
    set_alt_name("words");
    set_alias("dj_weapon");
    set_short("Voice");
    set_long("This is the voice of a DJ.  The ability to toture\n"+
             "and envelope the listeners!\n");
    set_read("Keep the Faith of Juliana's Tokyo!\n");
    set_class(20);
    set_weight(3);
    set_value(5000);
    set_type("exotic");
    set_hit_func(this_object());
}
weapon_hit(attacker){
string msg;
if(0 == random(3)) {
   write("You scream and your voice resounds through the room!\n");
   say(capitalize(tp->query_real_name())+" screams!\n");
   tell_room(environment(tp),HIG+
   "\n\nYou reel from the sound!  And blood runs down from the enemy's ears!\n\n\n"+NORM);
   attacker->hit_player(1+random(10));
if(tp->is_player() && tp->query_attrib("sta") < random(26)) {
  write("Your throat can't take the stress!\n");
  tp->add_hit_point(-1-random(10));
}
if(!(tp->id("dj")) && tp->query_attrib("wil") < random(26)) {
  write("The music overpowers you! You feel overwhelmed!\n");
  tp->set_ac(tp->query_ac() - 1);    /*ac may go negative */
} }
return 0;
}

init() {
  ::init();
  if(tp->id("dj")) {
  this_object()->set_class(45); }
  else { this_object()->set_class(20); }
} 
