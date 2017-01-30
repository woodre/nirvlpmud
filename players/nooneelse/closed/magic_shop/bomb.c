/*
  bomb.c
*/

#include "/obj/user/junk_only.c"

#define FUSE_TIME 10

int fuse_lit, fuse_counter;
object target_room;

init() {
  add_action("set_room",   "set");
  add_action("light",      "light");
  add_action("extinguish", "extinguish");
  add_action("throw_bomb", "throw");
}

set_room(str) {
  if (!str || str!="room") return 0;
  target_room=environment(this_player());
  write("The bomb is set to target this room.\n");
  return 1;
}

light(str) {
  if (!str) return 0;
  if (!id(str) && str!="fuse") return 0;
  if (fuse_counter < FUSE_TIME) {
    write("It's already lit.\n");
    return 1;
  }
  fuse_lit=1;
  fuse_counter -= 1;
  write("The fuse starts to sputter.\n");
  say(this_player()->query_name()+" lights the fuse on a bomb!\n",
      this_player());
  call_out("tick", 1, 0);
  return 1;
}

extinguish(str) {
  if (!str) return 0;
  if (!id(str) && str!="fuse") return 0;
  if (!fuse_lit) return 0;
  write("You burn your fingers, but the fuse remains lit!\n");
  return 1;
}

throw_bomb(str) {
  int i, nbr, no_more;
  string s1, s2;

  if (!str) return 0;
  if (!id(str)) return 0;
  if (target_room) {
    move_object(this_object(), target_room);
    write("The bomb arcs high into the air as you throw it.\n");
    say(this_player()->query_name()+
        " throws a bomb which arcs high into the air.\n", this_player());
  }
  else {
    move_object(this_object(), environment(this_player()));
    write("The bomb arcs high into the air and lands at your feet.\n");
    say(this_player()->query_name()+
        " throws a bomb which arcs high into the air and lands at your feet.\n",
        this_player());
  }
  return 1;
}

tick(str) {
  object obj, next_obj, this_room_obj;
  if (living(environment(this_object())))
    this_room_obj=environment(environment(this_object()));
  else
    this_room_obj=environment(this_object());
  fuse_counter -= 1;
  if (fuse_counter > 0) {
    tell_room(this_room_obj, "\nThe bomb's fuse sputters.\n");
    call_out("tick", 1, 0);
    return 0;
  }
  tell_room(this_room_obj,
            "\n"+
            "BBBBB   OOOO   OOOO  MM     MM  !!!\n"+
            "B    B O    O O    O M M   M M  !!!\n"+
            "B    B O    O O    O M  M M  M  !!!\n"+
            "BBBBB  O    O O    O M   M   M  !!!\n"+
            "B    B O    O O    O M       M  !!!\n"+
            "B    B O    O O    O M       M  \n"+
            "BBBBB   OOOO   OOOO  M       M  !!!\n\n");
  chan_msg("You hear the echoes of an explosion.\n");
  obj = first_inventory(this_room_obj);
  while (obj) {
    next_obj=next_inventory(obj);
    if (obj->is_npc()) obj->hit_player(50);
    obj=next_obj;
  }
  destruct(this_object());
  return 1;
}

reset(arg) {
  fuse_counter=FUSE_TIME;
  fuse_lit=0;
}

query_save_flag() { return 1; }

get(str) { return 1; }
drop(str) { return 0; }

query_value() { return 40000; }

short() {
  if (fuse_lit) {
    if (this_player()->query_level()>=21)
      return "A small metal ball with a sputtering fuse on top.\n"+
             "(Fuse countdown counter="+fuse_counter+")\n";
    else
      return "A small metal ball with a sputtering fuse on top";
  }
  else
    return "A small metal ball with a fuse on top";
}

long() {
  write(short()+".\n"+
        "The fuse smells slightly of kerosene.\n"+
  "  set room        - to set this room as the bomb's target\n"+
  "  light fuse      - to light the fuse\n"+
  "  extinguish fuse - to extinguish the fuse\n"+
  "  throw bomb      - to throw the bomb into the room it's set for\n"+
  "                    (if it's not set, it'll land in your room)\n"+
  "                    (if you're in the room when it goes off, it\n"+
  "                     may kill you.  This is an EXTREMELY dangerous item.)\n"+
        "\nA small label says: Made by Nooneelse's Doodads Inc.\n");
}

id(str) { return str=="bomb" || str=="ball" || str=="metal ball"; }
