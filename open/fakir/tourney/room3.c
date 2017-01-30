#include "defs.h"

inherit ROOM;

string *plays;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  set_no_fight(1);
  set_no_magic(1);
  short_desc=BOLD+"Grand Tournament of Nirvana"+NORM;
  long_desc=
    "This is the room where we select our equipment.\n";
  items=({
  });
  dest_dir=({
    PATH+"room4.c","north",
  });
  plays=({ });
}

void init() {
  ::init();
  add_action("cmd_list","list");
  add_action("cmd_read","read");
  add_action("cmd_pick","pick");
  if((int)this_player()->query_level() > 20)
    add_action("cmd_renew","renew");
}

int cmd_list(string str) {
  write("The following equipment packs are available:\n"+
        "1. Offensive (sword,dagger,gorget,gauntlet,cloak)\n"+
        "2. Medium (staff,gorget,gauntlet,cloak,chainmail)\n"+
        "3. Defensive (dagger,gorget,gauntlet,cloak,greaves,platemail)\n");
  return 1;
}

int cmd_pick(string str) {
  string file;

  if(member_array(TPRN,plays)!=-1) {
    write("You've already chosen a pack!\n");
    say(TPN+" tries to get another pack from the dispenser.\n");
    FTELL(TPN+" is trying to get an extra pack.\n");
    return 1;
  }

  switch(str) {
    case "1": file=PACKPATH+"pack-o.c"; break;
    case "2": file=PACKPATH+"pack-m.c"; break;
    case "3": file=PACKPATH+"pack-d.c"; break;
    default: write("Huh?\n"); return 1;
  }

  move_object(clone_object(file),TP);
  write("You receive a pack.\n");
  plays+=({ TPRN });
  return 1;
}
  
int cmd_read(string str) {
  string *kids;
  int i;
  if(!str || str!="list") {
    notify_fail("Read what?\n");
    return 0;
  }
  kids=(string *)(MASTER->query_players());
  write("Fights:\n------\n");
  for(i=0; i < sizeof(kids); i+=2) {
    if(i==sizeof(kids)-1) {
      write("Odd man: "+capitalize(kids[i])+"\n");
    } else
      write(capitalize(kids[i])+" vs. "+capitalize(kids[i+1])+"\n");
  }
  return 1;
}

int cmd_move(string str) {
  if(query_verb()=="north" && TP->query_pl_k() < 2) {
    write("You must set your pk sparring flag before you can go\n"+
          "north.  Type <"+BOLD+"kill_players spar"+NORM+"> to set your flag.\n");
    say(TPN+" attempts to go north and fails.\n");
    return 1;
  }
  return (int)::cmd_move();
}

int cmd_renew(string str) {
  write("You renew the dispenser.\n");
  say(TPN+" has renewed the dispenser.\n");
  plays=({ });
  return 1;
}

int query_spar_area() { return 1; }