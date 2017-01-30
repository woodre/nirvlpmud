#include "/players/vertebraker/define.h"
inherit ROOM;
string jnk,jnk2;
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "sanity's brink";
  long_desc =
"  This is a featureless black room.  Why is it here?\n\
\n\
A marble pedestal stands in the middle of the room.\n";
  items = ({
"pedestal","A small marble pedestal calls for you\n to "+HIB+"\""+NORM+"place"+HIB+"\""+NORM+" your palm upon it",
 });
  dest_dir = ({
"/players/vertebraker/castle/suicide","suicide", }); }

init() {
  ::init();
  add_action("cmd_place","place");
  add_action("cmd_suicide","suicide"); }

cmd_suicide() {
  tell_object(TP,
"\n\nYou feel very weak as your badly damaged body falls to the ground to die.\nYour luck is now "+(LUCK - 1)+".\n\nYou die.\nYou have a strange feeling.\nYou can see your dead body from above.\n\nSetting hit points to 1/3 max...\n\n\n");
  move_object(TP,
"/room/church");
  return 1; }

cmd_place(str) {
  write("You place your hand upon the pedestal..\n\n Energy swirls around you.....\n");
  say(TPN+" places "+POS+" hand on the pedestal and disappears.\n");
  move_object(TP,"/players/vertebraker/castle/f1");
  return 1; }
