
/*  placed on /players/mythos/amon/forest/fudo.c
 *  a funky little snake caller weapon
 *                                  - mythos
 *
 *  - approved by PAIN
 */
 
#include "/players/mythos/closed/ansi.h"
object rep, reps;
int n, a;
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("snake");
  set_alias("green snake");
  set_short("A green snake");
  set_long("A long green snake.  This snake is a very odd\n"+
           "one in that it allows itself to be used as a weapon.\n");
  set_class(20);
  set_weight(7);
  set_value(10000);
  a = 0;
  set_hit_func(this_object());
}

/* This is one of the best weapons on the game... It should not be storable  -Snow */

weapon_hit(attacker){
  if(random(3) == 0) {
    if(0 == random(2)) {
      reps = all_inventory(environment(this_player()));
      for(n = 0; n <sizeof(reps); n++) {
        if(reps[n]->id("snake")) { a = a + 1; }
      }
       if(a < 10) {
      tell_room(environment(this_player()),"A snake slithers into the room!\n");
      if(attacker) {
      rep = clone_object("/players/mythos/amon/forest/snake.c");
      rep->set_owner(this_player());
      move_object(rep,environment(this_player()));
      rep->attack_object(attacker); }
      this_player()->heal_self(-5-random(10)); }
      a = 0;
      return -3; }
      this_player()->heal_self(-1-random(5));
   return 7; }
 return -4; 
}
