inherit "room/room";
reset(arg) {
  set_light(0);
    short_desc = ">>>>>><<<<<<";
    long_desc =
    "You are in a small room....\n";

  dest_dir = ({
    "/players/mythos/closed/guild/task/1/6.c", "north",
    "/players/mythos/closed/guild/task/1/6.c", "south",
    "/players/mythos/closed/guild/task/1/6.c", "east",
    "/players/mythos/closed/guild/task/1/6.c", "west",
  });
} }

init() {
  ::init();
  add_action("grin","north");
  add_action("grin","south"); 
  add_action("grin","east"); 
  add_action("grin","west");
}

grin() {
int v;
v = random(6);
if(v == 0) {  move_object(tp,"/players/mythos/closed/guild/task/1/1.c");
              command("look",tp); }
if(v == 1) {  move_object(tp,"/players/mythos/closed/guild/task/1/2.c");
              command("look",tp); }
if(v == 2) {  move_object(tp,"/players/mythos/closed/guild/task/1/3.c");
              command("look",tp); } 
if(v == 3) {  move_object(tp,"/players/mythos/closed/guild/task/1/4.c");
              command("look",tp); }
if(v == 4) {  move_object(tp,"/players/mythos/closed/guild/task/1/5.c");
              command("look",tp); }
if(v == 5) {  move_object(tp,"/players/mythos/closed/guild/task/1/6.c");
              command("look",tp); } 
return 1;}
