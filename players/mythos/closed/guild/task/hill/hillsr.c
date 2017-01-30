#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Hills of Deacrom ";
    long_desc =
    "You venture down into the depths of the hill.\n"+
    "Birds chirp quietly and all is calm....\n"+
    "Below you see a raging river...\n";
  items = ({
    "down","Down the hill",
    "up","Heads back",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/task/hill/hillsr.c","down",
    "/players/mythos/closed/guild/task/hill/hills.c","up",
  });
} }

realm() { return "NT"; }

init() {
 ::init();
 add_action("rand","down");
 add_action("rand2","up");
}

rand() {
string goes;
int rad;
  rad = random(10);
  if(rad < 2) { goes = "down#players/mythos/closed/guild/task/hill/drag.c"; }
  if(rad > 3) { goes = "down#players/mythos/closed/guild/task/hill/dome.c"; }
  if(rad > 6) { goes = "down#players/mythos/closed/guild/task/hill/hillsr2.c"; }
  tp->move_player(goes);
return 1;}

rand2() {
string goes;
int rad;
  rad = random(10);
  if(rad < 2) { goes = "up#players/mythos/closed/guild/task/hill/hills2.c"; }
  if(rad > 3) { goes = "up#players/mythos/closed/guild/task/hill/dome.c"; }
  if(rad > 6) { goes = "up#players/mythos/closed/guild/task/hill/hillsr2.c"; }
  tp->move_player(goes);
return 1;}
