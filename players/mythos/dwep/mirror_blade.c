#define tp this_player()
#define eo environment(this_object())
#define tpn tp->query_real_name()
#define tl tp->query_level()
#define eeo environment(eo)
#define etp environment(tp)
#include "/players/mythos/closed/ansi.h"

inherit "obj/weapon";
int use,charges;


query_dwep() { return 1; }

query_save_flag() { return 1; } /* NONSAVEABLE */

reset(arg) {
::reset(arg);
  if(arg) return;
  set_name("mirrors");
  set_short(BLU+"The Twin Blades of Mirrors"+NORM);
  set_alias("blade");
  set_alt_name("twin");
  set_long("A \n");
  set_value(10000);
  set_weight(4);
  set_class(16);
  charges = 3 + random(10);
  use = 0;
  set_hit_func(this_object());
}

weapon_hit(attacker) {
   if(random(3) == 0) {
   return 7; }
return; }

init() {
  ::init();
  add_action("image","images");
}

image() {
object dup;
int num,h;
  if(tp->query_weapon() != this_object()) {
    write("You are not wielding the Mirror Blade!\n");
  return 1; }
  if(!tp->query_attack()) { write("You are not in combat!\n"); return 1; }
  if(use) { write("The image power is in use right now!\n"); return 1; }
  num = 2 + random(6);
  for(h=0;h<num;h++) {
    dup = clone_object("/players/mythos/dmon/dupl.c");
    dup->set_wc(tp->query_wc() + random(7));
    dup->set_ac(tp->query_ac());
    dup->set_level(1);
    dup->set_name(tpn);
    dup->set_short(tp->short());
    dup->set_own(tp);
    dup->set_hp((tp->query_hp())/10);
    move_object(dup,etp);
    dup->attack_object(tp->query_attack());
  }
  set_short(BLU+"The Twin Blades of Mirrors"+NORM+" [ "+YEL+"GLOWING"+NORM+" ]");
  call_out("fade",600);
return 1; }

fade() { 
  charges = charges - 1;
  if(charges < 1) { 
    if(living(eo)) { tell_object(eo,"The Mirror Blade crumbles.\n");
    if(eo->query_weapon() == this_object()) {
      command("unwield mirrors",eo); } }
    destruct(this_object()); 
    return 1; }
    use = 0;
    set_short(BLU+"The Twin Blades of Mirrors"+NORM); 
return 1; }