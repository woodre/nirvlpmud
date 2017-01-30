#define tpn this_player()->query_name()
#define tp this_player()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";
object player;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Teleporter Capsule";
long_desc =
  "This is a round teleporter capsule.  The capsule will seal auto-\n"+
  "matically when it is in motion.  There is a small green button\n"+
  "located in the wall beside the door.\n";

items = ({
  "capsule","A metallic, round capsule with no windows or escape hatches.",
  "door","A narrow rectangular opening to enter and leave the capsule.",
  "wall","Smooth, shiny surface..almost irridescent.",
  "button","A round, green button with the word 'Push' on it.",
});

dest_dir = ({
/*
	"players/pain/tiny/tr1.c","exit",
*/
	"players/eurale/Drygulch/dgs16.c","exit",
});

}

init() {
  ::init();
  add_action("push","push");
}

push(str) {
if(!str) { write("Push what?\n"); return 1; }
if(str == "button") {
  write("\nYou push the green button.....\n"+
	"With a HISSSSSSSSS..... the curved door closes...\n");
  player = this_player();
  call_out("trip",2);
  return 1; }
}

trip() {
tell_object(player,
  "\nYou hear a strange humming noise and the capsule begins to vibrate.\n\n");
  call_out("trip1",2);
  return 1; }

trip1() {
tell_object(player,
  "You get the sensation that the capsule is picking up speed....\n"+
  "The lights dim a little and there are no more sounds outside..\n\n");
  call_out("trip2",2);
  return 1; }

trip2() {
tell_object(player,
  "The capsule begins to shake violently and the air warms......\n"+
  "The lights flicker.....\n\n");
  call_out("trip3",2);
  return 1; }

trip3() {
tell_object(player,
  "You can feel your speed decreasing.... and then THUMP!\n\n");
  call_out("trip4",2);
  return 1; }

trip4() {
tell_object(player,
  "The vibration begins to disappear and the humming fades...\n"+
  "And with a HIIISSSSSSSSSSSS.... the door opens.\n\n");
  call_out("trip5",1);
  return 1; }

trip5() {
  command("look",player);
  player->move_player("capsule#players/eurale/Space/teleport_down.c");
  return 1; }
