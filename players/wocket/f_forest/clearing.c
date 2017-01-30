#include "/players/wocket/closed/ansi.h"
#include "defs.h"
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
  short_desc = "A clearing";
  long_desc = "   A small clearing in the dreary forest.  Trees surround the grassy\n"+
        "area.  The grey fog still covers most of the ground, however, more\n"+
        "light is capable of getting through.  The ground is still saturated\n"+
        "with water.  The stench of death ressinates throughout.\n"+OFF;
  smells = ({ "default", "You smell the stench of death", });
  listens = ({ "default","You hear the breeze whistle through the grass" });
  items = ({
    "trees","They are tall and grey surrounding the clearing",
    "fog","It is thick at your feet",
    "light","It filters down casting shadows upon the fog",
    "ground","It is very soggy",
    "grass","The tall grass is grey as viewed through the fog",
  });
  dest_dir = ({
    "","north",
    "","south",
    "","east",
    "","west",
  });
  northexit = southexit = eastexit = westexit = 1;
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
if(monsters != 1){ get_monsters(); }
::init();
    add_action("newnorth","north");
    add_action("newsouth","south");
    add_action("newwest","west");
    add_action("neweast","east");
#ifndef __LDMUD__
  add_action("forgetting"); add_xverb("");
#else
  add_action("forgetting", "", 3);
#endif
}

forgetting(){
  if(!random(20)){
    command("say What was I going to do?",this_player());
    this_player()->add_exp(-20*this_player()->query_level());
    return 1;
  }
  return 0;
}

newnorth(){
if(!northexit) return 0;
if(!northroom){
    northroom = clone_object(DIR+"fforest.c");  
northroom->set_southroom(this_object());
}
move_me(northroom,"north");
return 1;
}

newsouth(){
if(!southexit) return 0;
if(!southroom){
    southroom = clone_object(DIR+"fforest.c");
    southroom->set_northroom(this_object());
}
move_me(southroom,"south");
return 1;
}

newwest(){
if(!westexit) return 0;
if(!westroom){
    westroom = clone_object(DIR+"fforest.c");
    westroom->set_eastroom(this_object());
}
move_me(westroom,"west");
return 1;
}

neweast(){
if(!eastexit) return 0;
if(!eastroom){
    eastroom = clone_object(DIR+"fforest.c");
    eastroom->set_westroom(this_object());
}
move_me(eastroom,"east");
return 1;
}

move_me(object room,string way){
string place;
  place = way+"#"+file_name(room);
  this_player()->move_player(place);
  return 1;
}

set_northroom(obj){ northroom = obj; }
set_southroom(obj){ southroom = obj; }
set_westroom(obj){ westroom = obj; }
set_eastroom(obj){ eastroom = obj; }

query_northroom(){ return northroom; }
query_southroom(){ return southroom; }
query_westroom(){ return westroom; }
query_eastroom(){ return eastroom; }
