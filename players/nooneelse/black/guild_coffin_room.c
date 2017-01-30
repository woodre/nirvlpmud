/*
 guild_coffin_room.c
*/

inherit "room/room";
inherit "players/nooneelse/black/guild_rooms";

object obj, what_obj;

string str;

init() {
  ::init();

  add_action("get_coffin",   "coffin");
  add_action("enter_coffin", "enter");
  check_membership(this_player());
}

get_coffin() {
/* find out if he/she/it has one here already */
  if (!this_player()) return 0;
  if (this_player()->is_npc()) return 0;
  obj=0;
  what_obj=first_inventory(this_object());
  while (what_obj) {
    if (what_obj->query_coffin_owner_name()==
        lower_case(this_player()->query_real_name())) obj=what_obj;
    what_obj=next_inventory(what_obj);
  }
  if (obj) {
    write("You already have a coffin here.\n");
    return 1;
  }
  obj=clone_object("players/nooneelse/black/guild_coffin");
  obj->set_coffin_owner_name(this_player()->query_real_name());
  move_object(obj, this_object());
  say(this_player()->query_name()+ " mumbles some arcane gutteral words and "+
      "a coffin appears in the room.\n");
  write("You mumble some arcane gutteral words and "+
        "a coffin appears in the room.\n");
  return 1;
}

enter_coffin(str) {
  if (!str || !str=="coffin") return;
/*  prevented this for those who refused to change over to new
    guild  -  10/11/2000  Eurale
  obj=0;
  what_obj=first_inventory(this_object());
  while (what_obj) {
    if (what_obj->query_coffin_owner_name()==
        lower_case(this_player()->query_real_name())) obj=what_obj;
    what_obj=next_inventory(what_obj);
  }
  if (!obj) {
    write("You must use the 'coffin' command to get yours first.\n");
    return 1;
  }
  tell_object(this_object(), this_player()->query_name()+
              " steps into a coffin.\n");
  move_object(this_player(), obj);
  command("look", this_player());
*/
write("As you try to enter your coffin, you discover it has been\n"+
      "nailed shut.\n");
  return 1;
}

reset(arg) {
  if (arg) return;
    
  set_light(1);
  short_desc=("Vampire Guild Coffin Room");
  no_castle_flag=1;
  long_desc=
    "This is a well lit room, it seems to have been carved into\n"+
    "a HUGE obsidian boulder.  Vampires may use the 'coffin' command\n"+
    "to get a coffin or 'enter coffin' to enter their coffin.\n"+

    "\n\nNOTE: These coffin rooms don't store stuff the way the hotel does.\n"+
    "      The shelves in them will save the VALUE of the items in them, but\n"+
    "      NOT the items themselves in a crash.  If there's no crash, the\n"+
    "      items will remain in the shelves until you remove them.\n\n";

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/vguild_hall","up",
    });
  if (!present("board", this_object())) {
object board;
    board = clone_object("players/nooneelse/black/guild_board2");
    move_object(board, this_object());
  }
  return;
}

is_castle() { return 1; }


realm() { return "NT"; }
