#define STARTROOM "/players/feldegast/tourney/room4.c"
#define ARENA "/players/feldegast/tourney/arena.c"

#include "defs.h"

inherit "obj/weapon";

object *arenas;

reset(arg) {
  if(arg) return;
  set_name("staff");
  set_type("staff");
  set_short(HIM+"Staff"+NORM+" of "+HIY+"Ceremonies"+NORM);
  set_long(
"This is the official staff of the master of ceremonies at a Nirvana tournament\n"+
"or arena event.  It is a tall pole with a gold spiral along it's entire length\n"+
"that leads up to a silver eagle in flight on the head.\n"+
"Commands:\n"+
"  Tbegin\n"+
"  Twatch\n"+
"  Trefresh\n"+
"  Tadd\n"+
"  Tdelete\n"+
"  Tlist\n"+
""
  );
  set_weight(5);
  set_value(15000);
  set_class(25);
}

void init() {
  ::init();
  add_action("cmd_begin","Tbegin");
  add_action("cmd_watch","Twatch");
  add_action("cmd_refresh","Trefresh");
  add_action("cmd_add","Tadd");
  add_action("cmd_delete","Tdelete");
  add_action("cmd_list","Tlist");
  add_action("cmd_shuffle","Tshuffle");
}

cmd_begin(string str) {
  object *kids;  
  string *names;
  object a;
  object ob;
  int i,size;

  kids=({ });
  names=MASTER->query_players();
  for(i=0,size=sizeof(names); i < size; i++) {
    kids[i]=present(names[i],STARTROOM);
    if(!kids[i]) {
      write(capitalize(names[i])+" is not in the ready room.  Fight aborted.\n");
      return 1;
    }
  }

/* This requires at least two people to work. */
  if(sizeof(kids) < 2) {
    write("There are not enough people.\n");
    return 1;
  }
  if(!str && (sizeof(kids) % 2) == 1) {
    write("There are an odd number of players.  You may override this check\n"+
          "by providing an argument to this command.\n");
    return 1;
  }

  for(i=0; i < sizeof(kids); i+=2) {
    if(i < sizeof(kids)-1) {
      a=clone_object(ARENA);
      arenas+=({ a });
      write("Fight: "+kids[i]->query_name()+" vs. "+kids[i+1]->query_name()+"\n");
      move_object(kids[i],a);
      move_object(kids[i+1],a);              
      tell_object(kids[i],"You are led out onto the field, where you face off against\n"+
                          "your opponent: "+kids[i+1]->query_name()+".\n");  
      tell_object(kids[i+1],"You are led out onto the field, where you face off against\n"+
                            "your opponent: "+kids[i]->query_name()+".\n");
      command("look",kids[i]);
      command("look",kids[i+1]);
      MASTER->add_fight(a,kids[i]);
      MASTER->add_fight(a,kids[i+1]);
    } else { /* This shouldn't happen! */
      int ran;
      ran=random(sizeof(arenas));
      move_object(kids[i],arenas[ran]);
      MASTER->add_fight(arenas[ran],kids[i]);
      write(kids[i]->query_name()+" is the spare.  Moved to arena #"+ran+".\n");
    }
  }
  return 1;
}

int cmd_watch(string str) {
  MASTER->cmd_who();
  return 1;
}

int cmd_refresh(string str) {
  MASTER->refresh();
  write("All arenas destructed.  Mappings reset to null.\n");
  return 1;
}

int cmd_list(string str) {
  string *kids;
  int i;
  kids=(string *)(MASTER->query_players());
  write("Fights:\n------\n");
  for(i=0; i < sizeof(kids); i+=2) {
    if(i==sizeof(kids)-1) {
      write("Odd man: "+capitalize(kids[i])+"\n");
      write("Clone a monster and use 'Tadd' to add it to the list of players.\n"+
            "Then reshuffle.\n");
    } else
    write(capitalize(kids[i])+" vs. "+capitalize(kids[i+1])+"\n");
  }
  return 1;
}

int cmd_shuffle(string str) {
  if(str && str=="random")
    MASTER->shuffle_players(1);
  else
    MASTER->shuffle_players(0);
  write("Players shuffled.\n");
  cmd_list(0);
  return 1;
}

int cmd_add(string str) {
  MASTER->add_player(str);
  write("Added "+str+"\n");
  return 1;
}

int cmd_remove(string str) {
  MASTER->remove_player(str);
  write("Removed "+str+"\n");
  return 1;
}

