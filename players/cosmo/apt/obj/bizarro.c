/* approvedby Mythos 4-26-2000 */
/*
  Alignment reverser - 5 charges valued at 300 coins each
                     - nonsaveable item
  Purpose - temporarily reverses the alignment of an NPC
          - lasts ~20 heartbeats
          - no effect on kids, pets, or other players
  Drawbacks - 25% chance of reversing the player's alignment
            - 25% chance of doing nothing
            - 5% chance of 20+rnd(10) damage
            - 5% chance of making NPC aggressive
  Unique item - can only be obtained by killing 3 lvl 15 NPCs

  Thanks to Wocket for thematic ideas.
*/

#include "/players/cosmo/closed/ansi.h"
#define USER this_player()
#define NAME USER->query_name()
#define CAP capitalize

int uses;

id(str) { return str == "pouch" || str == "dust"; }
short() { return "A pouch of Bizarro Dust ["+BOLD+uses+NORM+"]"; }  
long() { write(
  "  Dust your next foe and watch them transform into bizarro world -\n"+
  "  a place where good is evil and evil is good.\n"+   
  "  There are ["+BOLD+uses+NORM+"] dustings left in the pouch.\n"); }

query_value() { return (uses * 300); }
query_save_flag() { return 1; }
query_weight() { return 1; }
get() { return 1; }

reset(arg) {
  if(arg) return;
  uses = 5;
}
  
init() {
  add_action("use_dust", "dust");
}
   
use_dust(str){
object ob;
  if(!str) { write("Dust whom?\n"); return 1; }
  if(this_player()->query_guild_name() == "rangers")
  {
    write("You are not allowed to use these.  Thanks.\n");
    return 1;
  }
  ob = present(str,environment(USER));
  if(!ob) { write(CAP(str)+" isn't here.\n"); return 1; }
  if(environment(this_object()) != this_player()) return 0;
  if(ob->is_player() || ob->is_kid() || ob->is_pet()) {
    say(NAME+" throws some dust in the air.\n");
    write("You sprinkle the dust on "+CAP(str)+" but it has no effect.\n");
    adjust();
    return 1;
  }
  if(ob->query_npc() && living(ob)) {
    say(NAME+" throws some dust in the air.\n");
    if(0 == random(2)) {
      write(
        "You grab a handful of dust and toss it in the air. As the dust floats\n"+
        "down over "+CAP(str)+", the aura of the room feels quite different.\n");   
      ob->set_al(-1*ob->query_alignment());
      move_object(clone_object("players/cosmo/apt/obj/biz_temp"),ob);
      log_file("cosmo.bizlog",NAME+" "+USER->query_alignment()+" dusted "+CAP(str)+
                 " "+ob->query_alignment()+" at "+ctime(time())+"\n");
    } else if(0 == random(2)) {
      write("A gust of wind blows the dust straight back onto you!\n"+
            "You have entered bizarro world!\n");
      USER->add_alignment(-2*USER->query_alignment());
      move_object(clone_object("players/cosmo/apt/obj/biz_temp"),USER);
    } else {
      write(
        "A gust of wind blows the dust out of your hand before you get a\n"+
        "chance to use it.\n");
    }
    if(0 == random(20)) {
      write("A dust flake gets in your eye causing you great pain.\n");
      USER->heal_self(-20 - random(10));
    }
    if(0 == random(20)) {
      write("Some of the dust gets in "+CAP(str)+"'s eye.\n");
      tell_room(environment(USER),
        CAP(str)+" screams and turns to attack "+NAME+".\n");
      ob->attack_object(USER);
    }
    adjust();
    return 1;
  }
  return;
}

adjust() {
  uses -= 1;
  write("The pouch has ["+BOLD+uses+NORM+"] dustings left.\n");
  if(!uses){
    write("The pouch disintegrates as you use the last of the dust.\n");
    USER->set_weight(0);
    USER->recalc_carry();
    destruct(this_object());
    return 1;
  }
  return;
}
