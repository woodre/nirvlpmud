/*
 * My walking workroom.  Idea from Padrone's walking castle.  Using
 * Nirvana's wandering /obj/monster to 'pull' my workroom around.
 * Putting in checks to make it non-enterable when I'm not in it.
 * Shows usage of add_item/remove_item and add_exit/remove_exit from
 * our /room/room/
 * -- Rumplemintz@Nirvana - Nov09,2010
 */

#pragma strong_types

#define MOVER "/players/rumplemintz/workroom_files/workroom_mover"
#define START_ROOM "/room/plane11"

#include <ansi.h>

inherit "room/room";

void
reset(status arg) {
  ::reset(arg);
  if (arg)
  set_light(1);
  set_short(HIG+"Rumplemintz"+NORM+"'s workroom");
  set_long(
"This is the workroom of the might wizard Rumplemintz.  He sends most of \n"+
"his time in this cozy place.  There are various papers with snippets of \n"+
"code lying around.  There is an oak desk with a brass nameplate on top of \n"+
"it.  A pair of wire baskets labelled 'Outbox' and 'Inbox' sit on the end \n"+
"of the desk.  The floor is covered in purple shag carpet, with a trap \n"+
"door in the center.  On the walls are various paintings and framed \n"+
"photographs of things that must be interesting to Rumplemintz.  There is a\n"+
"mural on the ceiling which appears to move.  Light pours in through the\n"+
"windows. Shadows cascade over the room as clouds pass by.\n");
  dest_dir = ({
    "room/vill_green", "green",
    "room/shop", "shop",
    "room/adv_guild", "guild",
    "room/church", "church",
    "room/post", "post",
    "room/adv_inner", "wizhall"
  });
  items = ({
    "papers", "The writing seems incomprehensible to you",
    "snippets", "The writing seems incomprehensible to you",
    "code", "The writing seems incomprehensible to you",
    "desk", "A grand oak desk.  There is not a spec of dust on it",
    "nameplate", ""+HIG+"Rumplemintz "+HIB+"the Libshaka"+NORM,
    "baskets", "The baskets are filled with papers",
    "outbox", "The basket is filled with papers",
    "inbox", "The basket is filled with papers",
    "floor", "It is covered in purple shag carpet",
    "door", "The door leads down to somewhere",
    "trap", "The door leads down to somewhere",
    "paintings", "They look like fingerpaintings",
    "photographs", "They appear to be children in various playful poses",
    "children", "The children are laughing and smiling",
    "fingerpaintings", "They are just swashes of color",
    "mural", "It appears to be a clock, currently it reads "+ctime(),
    "ceiling", "It has a mural on it",
    "light", "Light cascades into the room through the windows",
    "windows", "Light cascades into the room through the windows",
    "shadows", "They move through the room as the clouds pass",
    "clouds", "They are white and fluffy"
  });
  move_object(this_object(), START_ROOM);
  START_ROOM->add_exit("/players/rumplemintz/workroom", "workroom");
  add_exit(START_ROOM, "down");
  move_object(clone_object(MOVER), environment(this_object()));
  call_out("move_workroom", 20);
}

void
move_workroom() {
  object old_room_ob, new_room_ob;

  old_room_ob = environment(this_object());
  new_room_ob = environment(MOVER);

  if (new_room_ob != old_room_ob) {
    tell_room(old_room_ob, "Rumplemintz's workroom floats away.\n");
    move_object(this_object(), new_room_ob);
    old_room_ob->remove_exit("workroom");
    remove_exit("down");
    add_exit(new_room_ob, "down");
    new_room_ob->add_exit("workroom", "/players/rumplemintz/workroom");
    tell_room(new_room_ob, "Rumplemintz's workroom floats in.\n");
  }
  call_out("move_workroom", 20);
}
