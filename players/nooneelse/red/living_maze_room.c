/*
  living_maze_room.c


  Set:
    MAZE_ROOM_SHORT to the maze rooms short desc
    MAZE_ROOM_LONG to the maze rooms long desc
*/

#include "/players/nooneelse/red/living_maze.h"

inherit "room/room";
inherit "/players/nooneelse/WIZARD_LEVEL";

string MAZE_ROOM_SHORT, MAZE_ROOM_LONG;
object monster;
int room_number;

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(MAZE_ROOM_LIGHTING);
  MAZE_ROOM_SHORT="Glaring white room";
  MAZE_ROOM_LONG=
    "The walls, ceiling and floor of this room are so glaring white that\n"+
    "it disorients you.  You can't be sure which direction is which.\n"+
    "You sense a powerful, old evil nearby.\n";

  /* example of randomly placing a monster in a room
  if ((!monster || !find_living(monster)) || random(100) <= 10) {
    monster=clone_object("/w/nooneelse/monster/scorpion");
    monster->move(this_object());
  }
  end of random monster example */
}

short() {
  if (this_player()->query_level() >= WIZARD_LEVEL)
    return MAZE_ROOM_SHORT+"  ("+query_room_number()+")\n"+
           "   (n s e w)";
  else
    return MAZE_ROOM_SHORT+"\n"+
           "   (n s e w)";
}

long() {
  write(MAZE_ROOM_LONG);
  if (this_player()->query_level() >= WIZARD_LEVEL)
    write("   (Maze room # "+query_room_number()+")\n");
  write("   There are four obvious exits: east, west, north and south\n");
}

init() {
  add_action("move", "south");
  add_action("move", "north");
  add_action("move", "east");
  add_action("move", "west");
}

move(str) {
  object destination_obj;
  string direction_verb, directions;
  int i, direction_nbr;
  directions = ({ "south", "north", "east", "west" });
  direction_verb = query_verb();
  if (direction_verb=="s") direction_verb="south";
  if (direction_verb=="n") direction_verb="north";
  if (direction_verb=="e") direction_verb="east";
  if (direction_verb=="w") direction_verb="west";
  direction_nbr = -1;
  i = 0;
  while(i < sizeof(directions)) {
    if (direction_verb==directions[i]) {
      direction_nbr = i;
      break;
    }
    i++;
  }
  if (direction_nbr < 0) {
    write("There is no '"+direction_verb+"' exit in this room.\n");
    return 1;
  }
  destination_obj = call_other(MAZE_CONTROL, "query_dest",
                               (room_number * MAZE_EXITS) + direction_nbr);
  if (!destination_obj) {
    write("There is no '"+direction_verb+"' exit.\n");
    return 1;
  }
  say(capitalize(this_player()->query_name())+
      this_player()->query_msgout()+" "+direction_verb+".\n", this_player());
  move_object(this_player(), file_name(destination_obj));
  if (this_player()->query_brief())
    tell_object(this_player(), environment(this_player())->short()+"\n");
  else
    command("look", this_player());
  return 1;
}

set_room_number(num) { room_number = num; }

query_room_number() { return room_number; }
