#include "/players/wocket/closed/ansi.h"
#define MASTER "/players/wocket/caves/mastercr.c"
#define MON "/players/wocket/caves/NPC/"
inherit "/players/wocket/caves/inheritroom.c";

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
short_desc = MAG+"Dark room"+NORM;
long_desc = MASTER->get_long();
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
    "rocks","They are loose particles that fell from the walls",
    "walls","They are jagged with sharp rocks and covered in a slimy mucus",
});
}

get_monsters(){
int i;
i = random(100);
monsters = 1;
switch(i){
case 0..5:   move_object(clone_object(MON+"pojoui.c"),this_object());
             if(random(2) == 1) move_object(clone_object(MON+"plant.c"),this_object());
             break;
case 6..20:  move_object(clone_object(MON+"darknonge.c"),this_object());
             if(random(5) == 1){
             move_object(clone_object(MON+"snonge.c"),this_object());
              if(random(3) == 1)
              move_object(clone_object(MON+"snonge.c"),this_object());
             }
             break;
case 21..75: if(random(3)==1)move_object(clone_object(MON+"plant.c"),this_object());
             if(random(5)==1)
             move_object(clone_object(MON+"lippard.c"),this_object());
             if(random(4)==1)
             move_object(clone_object(MON+"wiidjin.c"),this_object());
             if(random(4)==1)
             move_object(clone_object(MON+"sponge.c"),this_object());
             if(random(6)==1)
             move_object(clone_object(MON+"nyddle.c"),this_object());
             if(random(5)==1){
             move_object(clone_object(MON+"moleman.c"),this_object());
              if(random(3)==1)
              move_object(clone_object(MON+"moleman.c"),this_object());
             }
             break;
case 76..90: break;
default:
  if(random(50)==1)  move_object(clone_object(MON+"pojoui.c"),this_object());
  if(random(20)==1)  move_object(clone_object(MON+"lippard.c"),this_object());
  if(random(17)==1){  move_object(clone_object(MON+"snonge.c"),this_object());
  if(random(2)==1) move_object(clone_object(MON+"snonge.c"),this_object()); }
  if(random(15)==1)  move_object(clone_object(MON+"darknonge.c"),this_object());
  if(random(10)==1)  move_object(clone_object(MON+"wiidjin.c"),this_object());
  if(random(7)==1)  move_object(clone_object(MON+"sponge.c"),this_object());
  if(random(5)==1)  move_object(clone_object(MON+"moleman.c"),this_object());
  if(random(5)==1)  move_object(clone_object(MON+"moleman.c"),this_object());
  if(random(3)==1)  move_object(clone_object(MON+"plant.c"),this_object());
break; 
}
}

init(){
if(!dest_dir)
get_directions();
if(this_player() && !this_player()->query_npc()) /* added by verte 6.22.01 */
if(monsters != 1){ get_monsters(); }
    add_action("newnorth","north");
    add_action("newsouth","south");
    add_action("newwest","west");
    add_action("neweast","east");

::init();
}

newnorth(){
if(!northexit) return 0;
if(!northroom){
if(random(10) == 1 && MASTER->query_sinjaroom() == 0){
    northroom = "/players/wocket/caves/sinjaroom.c";
}
else{
    northroom = clone_object("/players/wocket/caves/croom.c");
  }  
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
if(room == "/players/wocket/caves/sinjaroom.c") room = find_object(room);
if(objectp(room)) /* by verte */
this_player()->move_player(way+"#"+file_name(room));
}

set_northroom(obj){ northroom = obj; }
set_southroom(obj){ southroom = obj; }
set_westroom(obj){ westroom = obj; }
set_eastroom(obj){ eastroom = obj; }
