/*
  living_maze_entrance.c
*/

#include "/players/nooneelse/red/living_maze.h"

inherit "room/room";
inherit "/players/nooneelse/WIZARD_LEVEL";

/*
  Set:
    The direction used to enter the maze from the maze entrance room in reset()
    The direction to leave the maze entrance from the maze entrance room
      in reset()
    The room the player goes to when they don't want to enter the maze
      in reset()
    The maze rooms short desc in short_desc in reset()
    The maze rooms long desc in long()
*/

string enter_maze_direction, leave_maze_direction, leave_maze_destination;
int room_number;

realm() { return "NT"; }

reset(arg) {
  object doppleganger_obj;
  if (arg) return 0;

  set_light(MAZE_ROOM_LIGHTING);
  short_desc="Glaring white room";
  enter_maze_direction="north";
  leave_maze_direction="down";
  leave_maze_destination="players/nooneelse/red/study";
  if (!find_living("doppleganger")) {
    doppleganger_obj=clone_object("players/nooneelse/mon/doppleganger");
    move_object(doppleganger_obj, this_object());
  }
}

long() {
  write("The walls, ceiling and floor of this room are so glaring white that\n"+
        "it disorients you.  You can't be sure which direction is which.\n"+
        "The only direction you are sure of is down, which seems to lead\n"+
        "to a fireplace.\n"+
        "   Obvious exits are: "+leave_maze_direction+" and "+
        enter_maze_direction+".\n"+
        leave_maze_direction+" -> leave maze entrance\n"+
        enter_maze_direction+" -> enter maze\n");
}

init() {
  add_action("enter_maze", enter_maze_direction);
  add_action("leave_maze", leave_maze_direction);
}

enter_maze() {
  object destination;
  if (present("doppleganger") && this_player()->query_level() < WIZARD_LEVEL) {
    write(capitalize(this_player()->query_name())+
          " stands in your way.  You cannot proceed.\n");
    say(capitalize(this_player()->query_name())+
        " stands in "+capitalize(this_player()->query_name())+
        "'s way.  "+capitalize(this_player()->query_pronoun())+
        " cannot proceed.\n", this_player());
    return 1;
  }
  if (this_player()->query_level() >= WIZARD_LEVEL)
    write("<<< A player couldn't walk past the doppleganger >>>\n");
  destination = call_other(MAZE_CONTROL, "query_dest", 1);
  if(!destination) return 0;
  say(capitalize(this_player()->query_name())+
      this_player()->query_msgout()+" "+enter_maze_direction+".\n",
      this_player());
  move_object(this_player(), file_name(destination));
  if (this_player()->query_brief())
    tell_object(this_player(), environment(this_player())->short()+"\n");
  else
    command("look", this_player());
  return 1;
}

leave_maze() {
  say(capitalize(this_player()->query_name())+
      this_player()->query_msgout()+" "+leave_maze_direction+".\n",
      this_player());
  move_object(this_player(), leave_maze_destination);
  if (this_player()->query_brief())
    tell_object(this_player(), environment(this_player())->short()+"\n");
  else
    command("look", this_player());
  return 1;
}

set_room_number(num) { room_number = num; }

query_room_number() { return room_number; }
