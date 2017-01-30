#include "/players/wocket/closed/ansi.h"
#include "defs.h"
#define NORTHEXIT "/players/wocket/turtleville/ALT_tspath1.c"
#define CLEARING1 "/players/wocket/f_forest/clearing.c"
#define CABINENT "/players/wocket/f_forest/cabinent.c"
inherit "/players/wocket/f_forest/inheritroom.c";

object northroom;
object southroom;
object eastroom;
object westroom;

int northexit;
int southexit;
int eastexit;
int westexit;
int monsters;

reset(arg){
if(arg) return;
MASTER->add_room(file_name(this_object()));
short_desc = "The Forest of Forgetfulness"+NORM;
long_desc = MASTER->get_long();
smells = ({
  "default","You smell the musty odor of decay",
});
listens = ({
  "default","You only here small sounds that echo in the distance",
});
items = ({
    "light","It is dusty and dim",
    "shadows","Dark grey blots that dance against the fog",
    "needles","They are grey and dead.  They cover the trees and the ground",
    "ground","It is watersoaked and covered in dead branches and needles",
    "fog","A grey that covers the ground",
    "mist","A grey that covers the ground",  
    "branches","Dead branches that have fallen from the evergreens",
    "evergreens","Tall grey trees, whos branches blot out the light",
    "tree","Tall grey trees, whos branches blot out the light",
});
set_light(1);
}

get_monsters(){
int i;
i = random(100);
monsters = 1;
switch(i){
case 0..5:  
             break;
case 6..20: 
             break;
case 21..75: 
             break;
case 76..90: break;
default:
break; 
}
}

init(){
if(!dest_dir)
get_directions();
if(monsters != 1){ get_monsters(); }
  ::init();
    add_action("newnorth","north");
    add_action("newsouth","south");
    add_action("newwest","west");
    add_action("neweast","east");
    add_action("newsay","say");
#ifndef __LDMUD__
  add_action("forgetting"); add_xverb("");
#else
  add_action("forgetting", "", 3);
#endif

}

newsay(str){
  if(!str){
    notify_fail("What would you like to say?\n");
    return 0;
  }
  write("You say, \""+str+"\"\n");
  say(this_player()->query_name()+" says, \""+str+"\"\n");
  return 1;
}

forgetting(){
  if(!random(20) && this_player()->is_player()){
    switch(random(3)){
      case 0: command("say What was I going to do?",this_player());
              break;
      case 1: command("say I was going to do something.  Wasn't I?",this_player());
              break;
      case 2: command("say I'm forgetting something aren't I?",this_player());
              break;
    }
    this_player()->add_exp(-20*this_player()->query_level());
    return 1;
  }
  return 0;
}

newnorth(){
if(!northexit) return 0;
if(!northroom){
  if(!random(5) && !CLEARING1->query_southroom()){
    northroom = CLEARING1;
  }
  else
  if(!random(20) && !NORTHEXIT->query_southroom())
    northroom = NORTHEXIT;
  else
    northroom = clone_object(DIR+"fforest.c");  
northroom->set_southroom(this_object());
}
move_me(northroom,"north");
return 1;
}

newsouth(){
if(!southexit) return 0;
if(!southroom){
  if(!random(5) && !CLEARING1->query_northroom())
    southroom = CLEARING1;
  else
  if(!random(7) && !CABINENT->query_northroom())
    southroom = CABINENT;
  else
    southroom = clone_object(DIR+"fforest.c");
    southroom->set_northroom(this_object());
}
move_me(southroom,"south");
return 1;
}

newwest(){
if(!westexit) return 0;
if(!westroom){
  if(!random(5) && !CLEARING1->query_eastroom())
    westroom = CLEARING1;
  else  
  if(!random(7) && !CABINENT->query_eastroom())
    westroom = CABINENT;
  else
    westroom = clone_object(DIR+"fforest.c");
    westroom->set_eastroom(this_object());
}
move_me(westroom,"west");
return 1;
}

neweast(){
if(!eastexit) return 0;
if(!eastroom){
  if(!random(5) && !CLEARING1->query_westroom())
    eastroom = CLEARING1;
  else
  if(!random(7) && !CABINENT->query_westroom())
    eastroom = CABINENT;
  else
    eastroom = clone_object(DIR+"fforest.c");
    eastroom->set_westroom(this_object());
}
move_me(eastroom,"east");
return 1;
}

get_directions(){
  if(northroom || random(2) == 1){
    dest_dir += ({"north",""});
    northexit = 1;
  }
  if(southroom || random(2) == 1){
    dest_dir += ({"south",""});
    southexit = 1; 
  }
  if(westroom || random(2) == 1){
    dest_dir += ({"west",""});
    westexit = 1;
  }
  if(eastroom || random(2) == 1){
    dest_dir += ({"east"});
    eastexit = 1;
  }
}

move_me(object room,string way){
  say(this_player()->query_name()+" leaves "+way+".\n");
  move_object(this_player(),room);
  command("glance",this_player());
  say(this_player()->query_name()+" arrives.\n");
}

set_northroom(obj){ northroom = obj; }
set_southroom(obj){ southroom = obj; }
set_westroom(obj){ westroom = obj; }
set_eastroom(obj){ eastroom = obj; }
