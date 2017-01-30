/*
  living_maze_control.c

  This is the controller of a living maze.  The maze rooms exits
  shift at each reset.  In this room a wizard can:
  'new maze'    -> make a new maze
  'show maze'   -> show the maze rooms' exits
  'clear maze'  -> clear the maze rooms' exits
  'show room #' -> show this room's number

  To define the maze:
  1. Set the definitions in living_maze.h
     example:
     MAZE_CONTROL "/players/nooneelse/red/living_maze_control"
     MAZE_SIZE    16                                    = # of rooms
     MAZE_EXITS   4                                     = # exits in each room
     MAZE_OUT     "/players/nooneelse/red/coffin_room"  = maze destination
     MAZE_IN      "/players/nooneelse/red/living_maze_entrance"
     MAZE_ROOM    "/players/nooneelse/red/living_maze_room"
     MAZE_ROOM_LIGHTING 1          =the light level to be in the maze rooms

  2. In the file named in MAZE_IN, set:
       the direction used to enter the maze
       the direction to leave the maze entrance & not enter the maze
       the short description of the maze entrance
       the long description of the maze entrance

  3. The file named in MAZE_OUT is the destination of the maze

  4. In the file named MAZE_ROOM, set:
       the short description of the maze entrance
       the long description of the maze entrance
       Decide if the room is to have monsters and/or something special
       (Either random, or have the MAZE_ROOM check itself & put the
        stuff in if it is room # x, or whatever - see living_maze_room.c)
*/

#include "living_maze.h"

inherit "room/room";
inherit "/players/nooneelse/WIZARD_LEVEL";

object maze, maze_rooms;

init() {
  add_action("new_maze",       "new");
  add_action("show_maze",      "show");
  add_action("clear_the_maze", "clear");
}

new_maze(str) {
  if (!str || str != "maze" || this_player()->query_level() < WIZARD_LEVEL)
    return 0;
  clear_maze();
  maze_rooms = 0;
  maze = 0;
  if (!find_object(MAZE_IN)) call_other(MAZE_IN, "???", 0);
  if (!find_object(MAZE_OUT)) call_other(MAZE_OUT, "???", 0);
  make_maze();
  return 1;
}

clear_the_maze(str) {
  if (!str || str != "maze" || this_player()->query_level() < WIZARD_LEVEL)
    return 0;
  clear_maze();
  write("The maze has been cleared.\n");
  return 1;
}

show_maze_4() {
  int i;
  for (i=61; i < (MAZE_SIZE * MAZE_EXITS); i++) {
    if (maze[i]) {
      write("Room "+i+" exit -> s ="+
             ((query_dest(i)->query_room_number()*MAZE_EXITS)+0)+
            "   n ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+1)+
            "   e ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+2)+
            "   w ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+3)+"\n");
    }
  }
  return 1;
}

show_maze_more_3(str) {
  if (str != "y" && str != "") return 1;
  show_maze_4();
  return 1;
}

show_maze_3() {
  int i;
  for (i=41; i < 61; i++) {
    if (maze[i]) {
      write("Room "+i+" exit -> s ="+
             ((query_dest(i)->query_room_number()*MAZE_EXITS)+0)+
            "   n ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+1)+
            "   e ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+2)+
            "   w ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+3)+"\n");
    }
  }
  write("More? [y] ");
  input_to("show_maze_more_3");
  return 1;
}

show_maze_more_2(str) {
  if (str != "y" && str != "") return 1;
  show_maze_3();
  return 1;
}

show_maze_2() {
  int i;
  for (i=21; i < 41; i++) {
    if (maze[i]) {
      write("Room "+i+" exit -> s ="+
             ((query_dest(i)->query_room_number()*MAZE_EXITS)+0)+
            "   n ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+1)+
            "   e ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+2)+
            "   w ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+3)+"\n");
    }
  }
  write("More? [y] ");
  input_to("show_maze_more_2");
  return 1;
}

show_maze_more(str) {
  if (str != "y" && str != "") return 1;
  show_maze_2();
  return 1;
}

show_maze(str) {
  int i;
  if (!str || this_player()->query_level() < WIZARD_LEVEL) return 0;
  if (str=="room #") {
    write("This room's number is "+query_room()+"\n");
    return 1;
  }
  if (!maze) return 0;

  for (i=0; i < 21; i++) {
    if (maze[i]) {
      write("Room "+i+" exit -> s ="+
             ((query_dest(i)->query_room_number()*MAZE_EXITS)+0)+
            "   n ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+1)+
            "   e ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+2)+
            "   w ="+((query_dest(i)->query_room_number()*MAZE_EXITS)+3)+"\n");
    }
  }
  write("More? [y] ");
  input_to("show_maze_more");
  return 1;
}

clear_maze() {
  int i;
  if (!maze_rooms || !pointerp(maze_rooms)) return 0;
  i = 0;
  while(i < sizeof(maze_rooms)) {
    if (maze_rooms[i]) destruct(maze_rooms[i]);
    i++;
  }
  return 1;
}

make_maze() {
  object save_maze, a_maze_room;
  int count, i, j, k, random_nbr;
  save_maze = maze;
  maze = allocate(MAZE_SIZE * MAZE_EXITS);
  if (!maze_rooms || !pointerp(maze_rooms)) maze_rooms = allocate(MAZE_SIZE);
  count = 0;
  i = 0;
  j = 0;
  k = 0;
  for (i=0; i < MAZE_SIZE; i++) {
    if (!maze_rooms[i]) {
      a_maze_room = clone_object(MAZE_ROOM);
      a_maze_room -> set_room_number(i);
      maze_rooms[i] = a_maze_room;
    }
    else
      a_maze_room = maze_rooms[i];
    for(j=0; j < MAZE_EXITS; j++) {
      random_nbr = random((MAZE_SIZE * MAZE_EXITS) - (i * MAZE_EXITS + j));
      k = 0;
      count = 0;
      while(count < (MAZE_SIZE * MAZE_EXITS) &&
            (maze[count] || k < random_nbr)) {
        if (!maze[count]) k++;
        count++;
      }
      if (maze[count]) {
        write_file("/players/nooneelse/red/MAZE_LOG",
                   "Bug->living_maze_control make_maze()!! "+
                   ctime(time())+".\n");
        maze = save_maze;
        return 0;
      }
      maze[count] = a_maze_room;
    }
  }
  maze[0] = find_object(MAZE_IN);
  maze[(MAZE_SIZE * MAZE_EXITS) - 1] = find_object(MAZE_OUT);
  return 1;
}

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="A living maze control";
  long_desc=short()+".\n"+
            "This is the controller of a living maze.\n"+
            "   'new maze'    -> make a new maze\n"+
            "   'show maze'   -> show the maze rooms' exits\n"+
            "   'clear maze'  -> clear the maze rooms' exits\n"+
            "   'show room #' -> show this room's number\n";
  new_maze("maze");
}

id(str) { return str=="maze control" || str=="maze_control" ||
                  str=="living maze control" || str=="living_maze_control";
}

realm() { return "NT"; }

query_dest(room_num) {
  if (!maze || !pointerp(maze)) make_maze();
  return(maze[room_num]);
}

query_room(num) { return maze_rooms[num]; }
