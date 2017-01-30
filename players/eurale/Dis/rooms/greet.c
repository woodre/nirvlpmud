#include "DEFS.h"
inherit "room/room";
string s1,s2,s3;

reset(arg) {

if(!present("barker")) {
  move_object(clone_object("players/eurale/Dis/rooms/NPC/barker"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Phantasm Entrance";
long_desc =
	BOLD+"PHANTASM ENTRANCE"+NORM+"\n"+
	"  A small, multi-colored train has brought you to the World of \n"+
	"Phantasm.  There is a small booth just off to the side of the \n"+
	"road with a sign over the window.  Laughter and merry-making \n"+
	"can be heard off in the distance. \n";

items = ({
	"booth","This is a brightly-painted ticket booth with a front \n"+
		"window and a door on the side for the seller to enter",
	"sign","The sign reads:  Enter and enjoy the World of Phantasm \n"+
		"for a mere 1000 coins.  Just [pay barker]",
	"train","This beautiful little 'puffer' train is sometimes called \n"+
		"the Little Train that Could",
});

dest_dir = ({
	"/players/eurale/Dis/rooms/hub.c","enter",
	"players/eurale/RMS/warp.c","warp",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("enter","enter");
  add_action("ask","ask");
  add_action("pay","pay");
}

enter() {
  object ob;
    ob = present("barker");
  if(present("barker")) {
	write("The barker says:  You gotta pay first, buddy! \n");
	say("The barker prevents "+capitalize(TPRN)+" from entering. \n");
  return 1; }

  if(!present("barker")) {
    call_other(this_player(),"move_player",
	"enter#players/eurale/Dis/rooms/hub.c");
  return 1; }
}

pay(str) {
object barker;
int amt;
barker = present("barker",this_object());
  if(!str) {write("Who do you want to pay? \n"); return 1; }
  if(present("barker") && (str == "barker")) {
    amt = 1000;
  if(this_player()->query_money() < 1000) {
    write("The barker whispers, 'Come back when you have more money.'\n");
    return 1; }
    write("Thanks.... enjoy your day! \n");
    this_player()->move_player("pay#players/eurale/Dis/rooms/hub.c");
    this_player()->add_money(-amt);
if(barker)barker->add_money(amt);
    return 1; }
return 1;
}

ask(str) {
if(!str) { write("I have no idea what you want...\n"); return 1; }
sscanf(str,"%s %s %s",s1,s2,s3);
  if(s1 != "barker" && !s2  && !s3) {
    write("Ask who for what?\n"); return 1; }
  if(s1 == "barker" && s2 != "for") {
    write("The correct way is 'ask barker for something'.\n"); return 1; }
  if(s1 == "barker" && s2 == "for" && s3 == "clue") {
    say("The barker screams: HURRY, HURRY, HURRY!!!\n");
    write("The barker whispers: The signs inside tell you where to search.\n");
    return 1; }
}
