#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  set_short("Dojo - Combat Arena");
  set_long("\
The Dojo - Combat Arena.\n\
");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_arena","north",
  });
  enable_commands();
}

void catch_tell(string str) {
  object zombie;
  object attacker;
  string name;
  tell_room(ROOMDIR+"dojo_stands","*"+str);
  if( sscanf(str,"%s died.",name)==1 ) {
      zombie = find_player(lower_case(name));
      call_out("handle_death",1,({ name, zombie }) );
    }
}

void handle_death(mixed *info)
{
  object corpse;
  tell_room(this_object(),info[0]+" has been defeated.\nA pair of attendants come in and drag out "+info[0]+"'s battered body.\n");
  move_object(info[1],ROOMDIR+"recovery.c");
  corpse = present("corpse", this_object());
  move_object(corpse, ROOMDIR+"recovery");
}

void init() {
  ::init();
  add_action("quit","quit");
}


int query_spar_area() {
  return 1;
}
string realm() {
  return "NT";
}

int kill_players(string str)
{
  if(str=="spar") {
    write("This command is no longer necessary.\n");
    return 1;
  }
}
quit(str) {
  write("You may not quit from this location.\n");
  return 1;
}
