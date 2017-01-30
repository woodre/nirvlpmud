/*
 * My wandering workroom entrance.
 * Rumplemintz@Nirvana
 */

#pragma strong_types

#include <ansi.h>

#define START_ROOM "/room/plane11"
#define WORKROOM "/players/rumplemintz/workroom"

inherit "/obj/monster";

void
reset(status arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name(HIG+"Rumplemintz"+NORM+"'s workroom");
  set_short(HIG+"Rumplemintz"+NORM+"'s Workroom");
  set_alias("workroom");
  set_level(1);
  set_hp(999999999);
  set_ac(999999999);
  set_wander(1);
  set_wander_interval(10);
  set_wander_realm("/room/");
  move_object(this_object(), START_ROOM);
  START_ROOM->add_exit(WORKROOM, "workroom");
  WORKROOM->add_exit(START_ROOM, "down");
}

void wander() {
  object old_room_ob, new_room_ob;

  old_room_ob = environment(this_object());
  ::wander();
  new_room_ob = environment(this_object());
  old_room_ob->remove_exit("workroom");
  WORKROOM->remove_exit("down");
  WORKROOM->add_exit(file_name(new_room_ob), "down");
  new_room_ob->add_exit(WORKROOM, "workroom");
  if (WORKROOM->query_movemess())
  tell_room(WORKROOM,
"You feel the workroom move.\n"+
"Outside appears to be "+new_room_ob->short()+".\n");
}

status test_if_any_here() {    /* Overload this function so that it always
                                  returns 1 and keeps wandering */
  return 1;
}

do_damage()
{
  int i;
   say(this_player()->query_name()+" foolishly tries to attack the workroom!\n");
   write("The workroom sends a life-siphon through your body.\n");
   write("You almost die !!!\n");
   i = this_player()->query_hp();
   i+=-10;
   this_player()->heal_self(-i);
   write("The workroom decides not to destroy you.\n");
   write("You feel VERY lucky.\n");
   this_player()->stop_fight();
   this_object()->stop_fight();
   return 0;
}
