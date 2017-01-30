#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("ashura")) {
   
move_object(clone_object("/players/mythos/amon/forest/ashura.c"),this_object());
  }
  if(!present("darksound")) {
   
move_object(clone_object("/players/mythos/amon/forest/darks.c"),this_object());
}
  if(!arg) {
  set_light(-1);
    short_desc = "Tower 4th Level";
    long_desc =
    "You enter a room that is dark and silent....very silent.\n"+
    "There is a heavey door behind you- strength may be needed.\n"+
    "You can barely make out a throne in the center of the room.\n"+
    "On it a man sits.  You tremble with great fear.....\n";
  items = ({
    "door","You can try to open it, but it seems that you need a lot"+
    " of strength",
    "throne","The throne is made of dark metal.  Something about it makes "+
    "you shiver.  Something is written at its base",
  });

} }
realm() {return "NT"; }
  init()  {
    ::init();
    add_action("open_door","open");
    add_action("read_throne","read");
/*     add_action("dark","dark"); - Zeus 7.26.02  (this is stupid) */
    this_player()->set_fight_area();
}

open_door() {
if(this_player()->query_ghost()) {
write("You are moved to the Shrine....\n");
move_object(this_player(),"/players/mythos/aroom/shrinear5.c");
return 1;}
  if(call_other(this_player(),"query_attrib","str") > 17) {
    int m;
    m=random(4);
    if(m==0) {
  write("You pull the door open and walk down the stairs.\n");
  say(tp+" opens the door and leaves.\n");
 
call_other(this_player(),"move_player","open#players/mythos/aroom/forest/tower3.c");
  return 1; }
  else {
    write("The door seems to move... maybe you should try again.\n");
    say(tp+" tries to open the door only to fail.\n");
    return 1; }
  return 1; }
else {
  write("The door does not budge!\n");
  say(tp+" attempts to open the door but fails.\n");
  return 1; }
return 1;
}

read_throne(str) {
  if(str == "throne") {
    write("\n");
    write(BOLD+"In the 'dark' shall ye be- forever more.\n"+
      "		"+"\t\t-The Hunter\n");
    write(NORM+"\n");
return 1;}
  else {
    write("Read what?");
    write("\n");
  return 1; }
return 1;
}

dark() {
  int n;
  n=random(4);
  if(n == 0) {
      write("You feel something grab you and take you away......!\n");
    say("\n");
    say("\t\t"+HIY+"FLASH"+NORM+"\n\nYou see light explode from the"+
           " throne!\n");
    say("You see "+tp+" disappear....\n");
move_object(clone_object("/players/mythos/amisc/forest/dark.c"),this_player());
call_other(this_player(),"move_player","dark#players/mythos/aroom/forest/dark.c");
  write_file("/players/mythos/logs/ob",ctime(time())+"\t"+
  this_player()->query_real_name()+"\t\t"+this_player()->query_level()+"\tdark\n");
return 1; }
  else {
    write("Fear floods you but then it passes...\n");
  return 1; }
  return 1;}

exit(ob) { if(ob) ob->clear_fight_area(); }
