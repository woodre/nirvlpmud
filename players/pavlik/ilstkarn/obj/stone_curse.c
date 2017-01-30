#include <ansi.h>
#define ME capitalize(name)
#define ROOM environment(owner)

/*
 * This item turns its victim to stone, preventing them from
 * executing any commands.  Player Characters are affected for
 * only a short amount of time.  NPCs are permentatly turned
 * into statues.
 */

object owner;
string name;
int smash_key;

reset(arg){
  if(arg) return;
  smash_key = random(30);
  owner = 0;
  name = "noone";
}

short() {

  if(environment(this_player()) == this_object())
    return "You have been turned to stone!";

  else if(!name)
    return "A broken statue";
  
  else
    return "A stone statue of "+ME;

}

long() {

  if(environment(this_player()) == this_object()) {
    write(
    "You have been turned to stone by the cursed gaze of the\n"+
    "Basalisk.  Your limbs are stiff and unmovable, you are not\n"+
    "even able to talk, see, or hear.  You will have to remain a\n"+
    "statue until the evil spell wears off.\n");
    return;
  }

  if(!name) write(
  "A crumbling statue of stone.  The carved figure appears so life\n"+
  "like you expect the statue to move at any moment.  It's stone face\n"+
  "is captured in the perfect expression of amazement ... and fear.\n");

  else write(
  "A stone statue of "+ME+".  The carved figure appears so life like\n"+
  "you expect "+ME+" to move at any moment.  "+ME+"'s stone face is\n"+
  "captured in the perfect expression of amazement ... and fear.\n");
  return;
}

id(str) {
  return str == "statue" || str == "stone statue" || str == "stone_curse" ||
  str == "statue of "+name || str == name;
}

get(){ return 0; }
drop(){ return 1; }

init(){
  if(!this_player() || !environment()) {
    return;
  }
  if(environment(this_player()) == this_object()) {
      add_action("nope"); add_xverb("");
      add_action("statue_look"); add_xverb("look");
      add_action("statue_look"); add_xverb("l");
  }
}

statue_look() {
  return long();
}

do_curse(ob) {
  string po;

  owner = ob;
  name = ob->query_name();
  po = ob->query_possessive();
  if(!po) po = "his";

  tell_object(owner, "\n"+
  "The Basalisk turns and looks "+HIM+"directly into your eyes!\n"+NORM+
  "You are mesmerized by the swirling "+HIR+"crimson orbs"+NORM+".\n"+
  "You panic as a numbing sensation overcomes your body!  Your limbs\n"+
  "become numb and immobile as "+HIC+"Your Body Turns to Stone!!!\n\n"+NORM);

  tell_room(environment(this_object()), "\n"+
  ME+" foolishly glances into the "+HIR+"crimson eyes"+NORM+" of the Basalisk!\n"+
  ME+" is trapped by the monsters gaze and "+po+" body "+
  HIC+"Turns to Stone!!!\n\n"+NORM);

  /*
   * If the victim is not a player then move to the void and dest
   */
  if(!ob->is_player()) {
    move_object(ob, "players/pavlik/waste_room");
    destruct(ob);
    return 1;
  }

  /* stop all following */
  ob->clear_follow();

  move_object(ob, this_object());

  call_out("remove_statue", 10+random(100));
  return 1;
}

remove_statue() {
  object obj;
  string po;
  int i;

  if(!owner) {
    move_object(this_object(), "players/pavlik/waste_room");
    destruct(this_object());
    return 1;
  }

  po = owner->query_possessive();
  if(!po) po = "his";

  tell_object(owner, "\n"+
  "A tingling sensation enters your body.  The rock-solid feeling\n"+
  "slowly leaves your limbs as you return to normal.\n\n");

  tell_room(environment(this_object()),
  ME+" slowly turns back to normal.  The stone falls away from\n"+
  po+" body and crumbles to dust.\n");

  obj = all_inventory(this_object());
  for(i=0; i<sizeof(obj); i++) {
    move_object(obj[i], environment(this_object()));
  }

  move_object(this_object(), "players/pavlik/waste_room");
  destruct(this_object());
  return 1;
}

/*
 * This function may be called by the Basalisk.  If the numbers
 * match everything in here dies instantly.
 */
do_smash(i) {
  if(i == smash_key) {

    if(!owner) {
      tell_room(environment(this_object()), "\n"+
      HIR+"SSMMMMMAAAASSSHHHHH!!!!!!!!!\n"+NORM+
      "With a mighty swing of its tail the greater Basalisk "+HIR+"BLASTS"+NORM+
      ME+"'s statue into little chunks of rock.\n\n");
      move_object(this_object(), "players/pavlik/waste_room");
      destruct(this_object());
      return 1;
    }

    tell_object(owner, "\n"+
    HIR+"SMMMMAAAAASSSHHHHHHH!!!!!!!!!!!!!!!!\n"+NORM+
    "Your stone statue is "+HIR+"blasted to pieces"+NORM+" by the Basalisk!\n"+
    "Your body is scattered across the ground as little chunks of rock!\n\n");
    
    tell_room(environment(this_object()), "\n"+
    HIR+"SSMMMMMAAAASSSHHHHH!!!!!!!!!\n"+NORM+
    "With a mighty swing of its tail the greater Basalisk "+HIR+"BLASTS"+NORM+
    ME+"'s statue into little chunks of rock.\n\n");

    move_object(this_object(), "players/pavlik/waste_room");
    owner->hit_player(10000);
    move_object(owner, "players/pavlik/ilstkarn/cliff_niche");

    destruct(this_object());
    return 1;
  }
  return 1;
}

nope(){
  write("You have been turned to stone!\n");
  if(!random(2)) {
    write("You must wait for the spell to wear off.\n");
  }
  return 1;
}

