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
  I borrowed the code from cosmo
*/

#include "/players/cosmo/closed/ansi.h"
#define USER this_player()
#define NAME USER->query_name()
#define CAP capitalize

int uses;

id(str) { return str == "water" || str == "bottle"; }
short() { return HIB+"Water Bottle "+NORM+" ["+BOLD+uses+NORM+"]"; }  
long() { write(
  "  Spray your next foe and watch them transform into bizarro world -\n"+
  "  a place where good is evil and evil is good.\n"+   
  "  There are ["+BOLD+uses+NORM+"] Sprays left in the bottle.\n"); }

query_value() { return (uses * 300); }
query_save_flag() { return 1; }
query_weight() { return 1; }
get() { return 1; }

reset(arg) {
  if(arg) return;
  uses = 5;
}
  
init() {
  add_action("spray", "spray");
}
   
spray(str){
object ob;
  if(!str) { write("spray whom?\n"); return 1; }
  
  ob = present(str,environment(USER));
  if(!ob) { write(CAP(str)+" isn't here.\n"); return 1; }
  if(environment(this_object()) != this_player()) return 0;
  if(ob->is_player() || ob->is_kid() || ob->is_pet()) {
    say(NAME+" sprays some water in the air.\n");
    write("You spray the water on "+CAP(str)+" but it has no effect.\n");
    adjust();
    return 1;
  }
  if(ob->query_npc() && living(ob)) {
    say(NAME+" sprays some water in the air.\n");
    if(0 == random(2)) {
      write(
        "You press on the bottle spraying it in the air. As the water comes\n"+
        "down over "+CAP(str)+", the aura of the room feels quite different.\n");   
      ob->set_al(-1*ob->query_alignment());
      move_object(clone_object("players/cosmo/apt/obj/biz_temp"),ob);
      log_file("cosmo.bizlog",NAME+" "+USER->query_alignment()+" dusted "+CAP(str)+
                 " "+ob->query_alignment()+" at "+ctime(time())+"\n");
    } else if(0 == random(2)) {
      write("A gust of wind blows the water straight back onto you!\n"+
            "You have entered bizarro world!\n");
      USER->add_alignment(-2*USER->query_alignment());
      move_object(clone_object("players/cosmo/apt/obj/biz_temp"),USER);
    } else {
      write(
        "A gust of wind blows the water straight down having no\n"+
        "chance to be of use.\n");
    }
    if(0 == random(20)) {
      write("A dab of water gets in your eye causing you great pain.\n");
      USER->heal_self(-20 - random(10));
    }
    if(0 == random(20)) {
      write("Some of the water gets in "+CAP(str)+"'s eye.\n");
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
  write("The bottle has ["+BOLD+uses+NORM+"] sprays left.\n");
  if(!uses){
    write("The bottle disintegrates as you use the last of the water.\n");
    USER->set_weight(0);
    USER->recalc_carry();
    destruct(this_object());
    return 1;
  }
  return;
}