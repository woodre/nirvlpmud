#include "/obj/clean.c"
#include "def.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Sparring Arena";
  set_pk(1);
  long_desc=
"     You are in a large circular chamber with a high ceiling and fine\n\
white sand on the floor to soak up any incidental blood that may be\n\
spilt.  Bright flaming torches light the room along the walls.  An\n\
open gate leads east.\n";
  dest_dir=({
    PATH+"spar_entry","east"
  });
  enable_commands(); /* So that it will receive catch_tells */
}

void catch_tell(string str) {
  object zombie;
  object attacker;
  string name;
  tell_room("/players/feldegast/arena/rooms/stands2","*"+str);
  if( sscanf(str,"%s died.",name)==1 ) {
    zombie=find_player(lower_case(name));
    if(zombie && zombie->query_hp() < 0) {
      attacker=(object)zombie->query_attack();
      if(attacker)
        write_file(LOG_PATH+"arena.log",ctime(time())+" "+name+" defeated by "+(string)attacker->query_name()+" [spar]\n");
      else
        write_file(LOG_PATH+"arena.log",ctime(time())+" "+name+" defeated by unknown causes. [spar]\n");
      call_out("handle_death",1,({ name, zombie }) ); /* Delayed because the corpse isn't cloned yet! */
    }
  }
}

void handle_death(mixed *info)
{
  object corpse;
  tell_room(this_object(),info[0]+" has been defeated.\nA pair of attendants come in and drag out "+info[0]+"'s battered body.\n");
  move_object(info[1],PATH+"recovery.c");      
  command("regenerate",info[1]);
  corpse=present("corpse",this_object());
  if(corpse) {
    move_object(corpse,environment(info[1]));
    command("get all from corpse",info[1]);
    destruct(corpse);
  } else FTELL("Corpse not found!\n");
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
