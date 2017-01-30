#include "/players/pavlik/closed/colors.h"
#define EN environment(this_object())
#define ME capitalize(EN->query_name())
#define IT capitalize(str)

/*
 * This spell is quite different from others...
 * The player must first successfuly 'loop this circlet' on
 * the target.  Once that is done the spell may cast and damage
 * is done on a call_out basis.  The spell is continued as long
 * as the player has enough hit points and a stat check is passed.
 * 
 * Initial Cost: 800 coins & 30 sp
 * Initial Dmg : random 25
 * Continuation Cost: 10 sp
 * Continuation Dmg : random(20)
 */

object owner;
int active;
int count;

reset(arg){
 if(arg)
   return;
 active = 0;
}

init() {
  if(!EN) return;

  /* make sure we aren't where we don't belong */
  if(living(EN) && !present("mageobj", EN) && active == 0) {
    tell_room(environment(EN),
    "A golden ring slips from "+ME+"'s body and falls to the ground.\n");
    move_object(this_object(), environment(EN));
    return;
  }
  add_action("place_loop","loop");
}

id(str){ return str == "circlet" || str == "strangle_obj"; }

short(){
  if(active == 2) return "A constricting snake (around neck)";
  else if(active == 1) return "A golden circlet (around neck)";
  else return "A golden circlet";
}

long() {
  write("A thin circlet of finely woven gold.\n");
  return;
}

query_value(){ return 50; }
query_weight(){ return 0; }
get(){ return 1; }
drop() { if(!active) return 0; else return 1; }

query_owner(){ return owner; }
set_owner(ob){ owner = ob; }
query_count(){ return count; }
query_active(){ return active; }
set_active(arg){ active = arg; }

place_loop(str) {
  int chance;
  object obj;

  if(!present(this_object(), this_player()))
    return 0;

  if(!str) {
    write("Loop what?\n");
    return 1;
  }

  obj = present(str, environment(this_player()));

  if(!obj) {
    write("There is no "+IT+" here.\n");
    return 1;
  }

  if(!obj->query_npc()) {
    write("You cannot do this to another player.\n");
    return 1;
  }

  if(present("strangle_obj", obj)) {
    write(IT+" already has a circlet.\n");
    return 1;
  }

  chance = present("mageobj", this_player())->query_total_wil();

  /* this is much harder to do if already fighting! */
  if(this_player()->query_attack())
    chance = chance - chance/3;

  write("You try to place the circlet over "+IT+"'s head.\n");

  tell_room(environment(this_player()),
  ME+" attempts to place a golden circlet around "+IT+"'s neck.\n");

  if(random(chance) < obj->query_level()) {

    /* failed to loop the circlet, suffer damage */
    write("You fail to get the circlet on "+IT+".\n");
    tell_room(environment(EN),
    ME+" fails and the golden circlet tumbles to the ground.\n"+ 
    IT+" snarls angrily and hits "+ME+".\n");
    obj->attack_object(this_player());
    this_player()->hit_player(random(20), "magical");
    move_object(this_object(), environment(this_player()));
    return 1;
  }
  else {
    tell_room(environment(EN),
    "The golden circlet slips over "+IT+"'s head.\n");
    write("You succeed!\n");
    active = 1;
    move_object(this_object(), obj);
  }
  return 1;
}

do_spell(arg) {

  /* count starts at targets level */
  count = EN->query_level();
  active = 2;

  /* do some initial damage */
  owner->add_spell_point(-30);
  EN->hit_player(10+random(50), "magical");

  call_out("exe_spell", 4);
  return 1;
}


exe_spell() {
  int dmg;

  /* if the target is gone dest this */
  if(!EN || !living(EN)){
     destruct(this_object());
     return 1;
  }              
    if(!environment(EN)) return call_out("exe_spell", 2);
  /* if the owner has left we stop */
  if(owner->query_attack() != EN) {
    tell_room(environment(EN),
    "The snake shrivels into dust and blows away with the wind.\n");
    destruct(this_object());
    return 1;
  }

  /* is the owner to tired to continue this spell? */
  if(owner->query_sp() < -30) {
    tell_object(owner, "You are to tired to continue your spell.\n");
    tell_room(environment(EN),
    "The snake shrivels into dust and blows away with the wind.\n");
    destruct(this_object());
    return 1;
  }

  /* does target break free of the spell? */
  if(count > random(present("mageobj", owner)->query_total_ench())) {
    tell_object(owner, ME+" breaks your spell!\n");
    tell_room(environment(EN),
    ME+" tears the snake from around its neck and throws it to the ground!\n"+
    "The snake shrivels into dust and blows away with the wind.\n");
    destruct(this_object());
    return 1;
  }

  /* do the damage */
  /* make sure this object doesn't kill the target */
  dmg = random(20);
  if(dmg > EN->query_hp()) dmg = EN->query_hp();
  EN->hit_player(dmg*3, "magical");
  owner->add_spell_point(-10);

  tell_room(environment(EN),
  capitalize(owner->query_name())+"'s snake squeezes tighter ...");

  if(dmg > 12) tell_room(environment(EN),
  ME+"'s eyes nearly pop out of its head!\n");
  else if(dmg > 7) tell_room(environment(EN),
  ME+"'s face turns purple.\n");
  else tell_room(environment(EN),
  ME+" gasps for breath.\n");

  count++;
  call_out("exe_spell", 4);
  return 1;
}

