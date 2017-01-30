#include "/players/mythos/closed/guild/def.h"
object targ;
int jj;
inherit "room/room";
reset(arg) {
jj = 0;
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Outside Tokyo Station>> ";
    long_desc =
    "                Outside Tokyo Station\n"+
    "You stand outside the main train station.  There is an odd looking\n"+
    "gravestone here.  Down the road you can see the medical center and \n"+
    "rehab center.\n";
  items = ({
    "in","Go into the train station",
    "rehab","The rehab center",
    "medical","The medical center",
    "gravestone","The Gravestone of Masakado",
  });

  dest_dir = ({
    "/players/mythos/mroom/tokyo.c", "in",
    "/players/mythos/mroom/rehab.c","rehab",
    "/players/mythos/mroom/med.c","medical",
  });
} }

init() {
  ::init();
  add_action("ttouch","touch");
  if(pp) {
  add_action("ccome","come");
  }
}

ttouch(str) {
if(!str) return 0;
  if(str == "tomb" || str == "gravestone" || str == "masakado") {
    if(!pp) {
      write("You feel sick....\n");
      move_object(clone_object("/players/mythos/mmisc/snipe.c"),tp);
      return 1;}
    if(tgl != 4 || tl < 9 || qtf < 5) {
      write("Nothing happens...\n");
    return 1;}
    if(!jj) {
    write("A small man steps out from the shadows.\n"+
          "He is wearing a long, fancy, white robe\n"+
          "and he carries a small wooden wand.\n");
    write("\nHe asks you to 'come' with him.\n");
    return 1;}
    write("You must wait awhile....\n");
  return 1;}
}

ccome() {
  if(tgl != 4) {  write("what?\n"); return 1;}
  if(jj) { tp->zap_object(tp); return 1; }
    jj = 1;
  write("You follow the man and he leads you to\n"+
        "a large field.  In the center of the field\n"+
        "is a large tree.  He stops right below it.\n");
  write("He waits quietly.\n");
  move_object(tp,"/players/mythos/closed/guild/task/5/sakura.c");
  return 1;
}
