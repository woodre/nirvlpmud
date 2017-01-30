inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define REALMSIZE 9

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Somewhere in the Mountains of Ilstkarn";
  long_desc=
  "You have bravely entered the Ilstkarken Mountains.  Somewhere in this\n"+
  "vast range of mountains is Arcydian, fortress of the evil Ilstkarn\n"+
  "Wizards.  There is an old beat up SIGN here that you should read.\n";
  items=({
	"sign",
	"Please read the sign",
  });
  dest_dir=({
	"/players/pavlik/ilstkarn/path1", "north",
	"/players/pavlik/ilstkarn/null", "leave",
  });
  if(!present("small box", this_object())) {
	move_object(clone_object("players/pavlik/ilstkarn/obj/follow_box"),
	this_object());
  }
}

query_ilstkarn(){ return "enter"; }

init(){
  ::init();
  add_action("leave","leave");
  add_action("read","read");
  add_action("author_notes","authornotes");
}

leave() {
  write("You wisely decide to flee this evil realm.\n");
  say(capitalize(this_player()->query_real_name())+" scurries into the "+
  "magic portal.\n");
  move_object(this_player(), environment("players/pavlik/ilstkarn/ilstkarn_portal"));
  command("look", this_player());
  return 1;
}

read(str) {
  if(str == "sign") {
  write("\n"+
  "Welcome Bold Adventurer!\n"+
  "	There are things you should be made aware of before continuing further\n"+
  "into this realm.  Please read carefully and take heed!\n"+
  "*	This area is quite dangerous and is inteded for players level 15 and\n"+
  "over, however anyone is welcome to enter.  Most of this realm is teleport-\n"+
  "proof, so travel carefully and mark your path well.  Brings pets and\n"+
  "other NPCs at your own risk.  This realm is not very friendly towards\n"+
  "them so don't be shocked if they happen to tumble down a deep chasm and\n"+
  "are never heard from again.\n");
  write(
  "*	Listen carefully to what the monsters tell you, it may be very\n"+
  "important later.  There are questions that need to be answered in Ilstkarn.\n");
  write(
  "*	Last, and most importantly, the Ilstkarn Realm is a place of powerful\n"+
  "evil!  If you are of good alignment you might find yourself quite\n"+
  "unwelcomed by the denizens of this realm.  If you are evil in nature\n"+
  "you might find it more beneficial to work with the creatures of this\n"+
  "realm rather than fight them.\n");
  write(
  "*	You can also type 'authornotes' from this location for some additional\n"+
  "advice from the author of this realm.\n");
  write("\n"+
  "  That is all , You have been warned.  (Enjoy!)\n"+
  "\n");
  return 1;
  }
}

author_notes() {

  write("\n"+
  "I thought it might be helpful for you if you had these additional hints:\n"+
  "  o  Room descriptions are purposefully left vague and undetailed to make\n"+
  "     it more difficult for you to navigate.  Don't waste too much time\n"+
  "     trying to look, smell or hear in general.  Items of interest will be\n"+
  "     either physical objets (rather than part of the room description) or\n"+
  "     they will be CAPITALIZED if they are only mentioned in the description.\n");
  write(
  "  o  Most of the NPCs are created randomly, so don't use them as landmarks\n"+
  "     for navigation.  The same monster is unlikely to appear twice in the\n"+
  "     same spot.  Due to the laws of randomization, some monsters may appear\n"+
  "     more than once in different locations.\n");
  write(
  "  o  That's it for now, I may add more to this after watching what other\n"+
  "     players tend to do the most.  If you have questions or comments,\n"+
  "     send mail to Pavlik. But more likely, send it to Vertebraker nowadays.\n");

  return 1;
}

okay_follow() { return 1; }
