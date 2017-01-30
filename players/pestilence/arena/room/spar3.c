/* Based on Feld's arena */
#include "/obj/clean.c"
#include "/players/pestilence/define.h"
#define FTELL(x) if(find_player("pestilence")) tell_object(find_player("pestilence"),x);


inherit "/players/pestilence/closed/std/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=""+HIK+"ARENA"+NORM+"";
  set_pk(1);
  long_desc=
"     This is a large open field.  Everything is flat as far as one\n\
can see.  To the east there is more field.  To the west it seems there\n\
is an invisible wall.  The grass on the field here, is blood soaked.\n";
items = ({
"field","A large grassy field with blood stains",
"blood","Blood stains admist the grass",
"stain","Blood stains admist the grass",
"stains","Blood stains admist the grass",
"blood stains","Blood stains admist the grass",
"grass","A large grassy field with blood stains",
"wall","It's invisible so you see nothing",
"invisible wall","It's invisible so you see nothing",
});
  dest_dir=({
    "/players/pestilence/arena/room/spar2.c","east",
  });
  enable_commands(); /* So that it will receive catch_tells */
}

void catch_tell(string str) {
  object zombie;
  object attacker;
  string name;
  tell_room("/players/pestilence/arena/room/stands","~COMBAT~"+str);
  if( sscanf(str,"%s died.",name)==1 ) {
    zombie=find_player(lower_case(name));
    if(zombie && zombie->query_hp() < 0) {
      attacker=(object)zombie->query_attack();
      if(attacker)
        write_file("/players/pestilence/arena/log",ctime(time())+" "+name+" defeated by "+(string)attacker->query_name()+" [spar]\n");
      else
        write_file("/players/pestilence/arena/log",ctime(time())+" "+name+" defeated by unknown causes. [spar]\n");
      call_out("handle_death",1,({ name, zombie }) ); /* Delayed because the corpse isn't cloned yet! */
    }
  }
}

void handle_death(mixed *info)
{
  object corpse;
  tell_room(this_object(),info[0]+" has been defeated.\nA portal engulfs "+info[0]+"'s motionless body and takes it elsewhere.\n");
  move_object(info[1],"/players/pestilence/arena/room/morgue"); 
  command("resurect",info[1]);
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
