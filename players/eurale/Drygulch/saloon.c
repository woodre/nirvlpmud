/*  Drygulch Saloon  */

#include "defs.h"
inherit "room/room";
object hand;

reset(arg) {

if(!present("kitty")) {
  move_object(clone_object("players/eurale/Drygulch/NPC/kitty"),TO); }
if(!present("clem")) {
  hand = clone_object(HAND);
  hand->set_name("clem");
  hand->set_short("drinking hand named Clem");
  move_object(hand,TO); }
if(!present("dusty")) {
  hand = clone_object(HAND);
  hand->set_name("dusty");
  hand->set_short("Dusty");
  move_object(hand,TO); }
if(!present("cowboy")) {
  hand = clone_object(HAND);
  hand->set_name("cowboy");
  hand->set_short("a whistling cowboy");
  move_object(hand,TO); }

  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You push though the swinging doors into the saloon.  Tobacco \n"+
	"smoke and noise assault your senses.  The piano player is playing \n"+
	"a lively tune and the bar patrons are either involved in conver- \n"+
	"sation or drinking.  The saloon owner, Miss Kitty, is busy making \n"+
	"her rounds trying to keep everyone happy and spending thier money. \n";

items = ({
});

dest_dir = ({
	"players/eurale/Drygulch/dgs12.c","north",
});

}
