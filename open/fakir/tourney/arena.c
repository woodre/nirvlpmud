/*
This is the room where most of the fighting happens.  In most cases
it will be dynamically allocated.  It has the usual sparring area
stuff, and there is no teleportation.  You cannot 'leave' until
your opponent is defeated.  It keeps track of how many people are
in the room, and if nobody's in there it destructs itself.  Anything
said in this room is piped through a daemon and up to the stands.
The players cannot leave this place until only one person remains.
*/
#include "defs.h"

inherit ROOM;

int peeps;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  set_pk(1);
  set_no_teleport(1);
  short_desc=BOLD+"Grand Tournament of Nirvana"+NORM;
  long_desc=
    "This is an arena.\n";
  items=({
  });
  dest_dir=({
    PATH+"room2.c","leave",
  });
  enable_commands(); /* To enable catch_tell */
}

void init() {
  ::init();
  add_action("quit","quit");
  if((int)TP->is_player() && (int)TP->query_level() < 20) peeps++;
}

void exit() {
  if(TP && TP->is_player() && (int)TP->query_level() < 20) peeps--;
  if(peeps <= 0) call_out("clean_up",1);
}

int cmd_move(string str) {
  if(peeps!=1) {
    write("You cannot leave until all of your opponents are defeated.\n"+
          "There are "+(peeps-1)+" remaining.  If there's nobody else\n"+
          "here, then ask for assistance from Feldegast or Fakir.\n");
    say(TPN+" attempts to flee the arena.\n");
    return 1;
  }
  MASTER->remove_fight(this_object(),TP);
  return (int)::cmd_move(str);
}

void catch_tell(string str) {
  object zombie;
  object attacker;
  string name;
  string msg;
  MASTER->pipe_in(this_object(),str);
  if( sscanf(str,"%s died.",name)==1 ) {
    zombie=find_player(lower_case(name));
    if(zombie && zombie->query_hp() < 0) {
      attacker=(object)zombie->query_attack();
      if(attacker) {
        msg=ctime(time())+" "+name+" was defeated by "+(string)attacker->query_name()+"\n";
        CHANNEL->broadcast("arena",msg);
        write_file(LOG_PATH+"tournament.log",msg);
      }
      else
        write_file(LOG_PATH+"tournament.log",ctime(time())+" "+name+" defeated by unknown causes. [spar]\n");
      call_out("handle_death",1,({ name, zombie }) ); /* Delayed because the corpse isn't cloned yet! */
    }
  }
}

void handle_death(mixed *info)
{
  object corpse;
  tell_room(this_object(),info[0]+" has been defeated.\nA pair of attendants come in and drag out "+info[0]+"'s battered body.\n");
  move_object(info[1],PATH+"room1.c");      
  command("res",info[1]);
  corpse=present("corpse",this_object());
  if(corpse) {
    move_object(corpse,environment(info[1]));
    command("get all from corpse",info[1]);
    destruct(corpse);
  } else FTELL("Corpse not found!\n");
  
}

int query_spar_area() {
  return 1;
}
string realm() {
  return "NT";
}

quit(str) {
  write("You may not quit from this location.\n");
  return 1;
}

void clean_up() {
  destruct(this_object());
}
