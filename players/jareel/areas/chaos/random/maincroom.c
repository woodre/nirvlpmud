#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/caves/inheritroom.c";

object northroom;
object southroom;
object eastroom;
object westroom;

int northexit;
int southexit;
int eastexit;
int westexit;

reset(arg){
     
   if(arg) return;
short_desc = MAG+"Dark room"+NORM;
long_desc = ""+
MAG+"   The walls are covered in a slimy mucus which gives off a soft \n"+
    "violet glow.  The light casts shadows against the rocky surface\n"+
    "giving refuge for the dark loving plants who grow in abundance here.\n"+
    "Loose rocks acumulate in the corners of the cavern, knocked off from\n"+
    "the walls.  A small shaft of light beams down from a hole in the \n"+
    "the ceiling giving access to the outside.\n"+NORM;

smells = ({
  "default","You smell the musty odor of decay",
});

listens = ({
  "default","You only here small sounds that echo in the distance",
});

items = ({
    "light","It glows a soft violet",
    "mucus","It covers just about everything.  The slimy substance emminates a soft violet light",
    "plants","They are white and very fragile.  They seem to feed off of the darkness",
    "rocks","They are loose particles that feel from the walls",
    "walls","They are jagged with sharp rocks and covered in a slimy mucus",
    "hole","A hole in the ceiling giving an exit to the outside world",
    "ceiling","Looking much like the walls except with a small hole in it",
});

dest_dir = ({
  "/room/south/sforst45.c","up",
  "","north",
  "","south",
  "","west",
  "","east",
});
northexit = southexit = eastexit = westexit = 1;
}

init(){
  ::init();
    add_action("newup","up");   
    add_action("newnorth","north");
    add_action("newsouth","south");
    add_action("newwest","west");
    add_action("neweast","east");

}

newup(){
object uproom;
uproom = "/room/south/sforst45.c";
move_me(uproom,"out");
return 1;
}

newnorth(){
if(!northexit) return 0;
if(!northroom){
  northroom = clone_object("/players/wocket/caves/croom.c");
    northroom->set_southroom(this_object());
}
move_me(northroom,"north");
return 1;
}

newsouth(){
if(!southexit) return 0;
if(!southroom){
    southroom = clone_object("/players/wocket/caves/croom.c");
    southroom->set_northroom(this_object());
}
move_me(southroom,"south");
return 1;
}

newwest(){
if(!westexit) return 0;
if(!westroom){
    westroom = clone_object("/players/wocket/caves/croom.c");
    westroom->set_eastroom(this_object());
}
move_me(westroom,"west");
return 1;
}

neweast(){
if(!eastexit) return 0;
if(!eastroom){
    eastroom = clone_object("/players/wocket/caves/croom.c");
    eastroom->set_westroom(this_object());
}
move_me(eastroom,"east");
return 1;
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

