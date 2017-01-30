#include "defs.h"
inherit ROOM;

void on_create() {
  set_area("area");
  set_short("Living Room in Earwax's Old Apartment");
  set_long("This is where Earwax and his roomate Midget play video \
games and watch TV.  In Earwax's case, it's mainly football he watches \
(Da Bears!) and some baseball, and in Midget's, it's primarily porn.  \
There is a PSII, a VCR, and a huge console TV here, as well as a couple \
recliners and a small glass table.  Earwax's brother also comes over a \
lot and plays GTA3.  You can go back north, to get to the main part of \
the living room from here.");
  add_exit("north",APTR+"living.c");
  add_clone(APTM+"brother.c");
  add_desc("tv","The TV is hooked up to the PS2.  Grand Theft Auto III \
is what they have in there at the moment.  You can 'play GTA3' perhaps, \
if you like.");
  add_desc("PS2","Play-Station II, bad-ass video game system.  You can \
probably 'play GTA3' if you like.");
  add_desc("table","A small glass table that Earwax uses as a footrest, \
and Midget eats pizza off of.");
  add_desc("porn","You might be able to 'watch porn' if you're so inclined.");
  add_desc("VCR","One of Midget's porn tapes is in there right now.  If \
you're like Midget, and can't get enough, you can 'watch porn'.");
  add_desc("vcr","One of Midget's porn tapes is in there right now.  If \
you're like Midget, and can't get enough, you can 'watch porn'.");
  add_desc("recliner","There are two cheap recliners here that Midget \
probably bought at a swap meet or something.");
  add_desc("recliners","There are two cheap recliners here that Midget \
probably bought at a swap meet or something.");
}

void on_init() {
  add_action("do_play","play");
  add_action("do_watch","watch");
}

int do_play(string arg) {
  if (arg != "gta3" && arg != "GTA3") {
    notify_fail("Play what?\n");
    return 0;
  }

  if (present("earwax_brother",this_object())) {
    write(line_wrap("Earwax's brother slaps you across the back of your head and then \
goes back to playing his video game.\n"));
    say(line_wrap("Earwax's brother slaps "+this_player()->query_name()+" across the back of their head and then \
goes back to playing his video game.\n"),this_player());
    return 1;
  }

  write(line_wrap("You sit down and play some GTA3.  After a while, \
killing innocent civilians, blowing up cars, and stealing fire-trucks \
gets kind of old, so you put the controller down.\n"));
  say(line_wrap(this_player()->query_name()+" picks up a controller and \
plays some Grand Theft Auto III for a while.\n"), this_player());
  return 1;
}

int do_watch(string arg) {
  if (arg != "porn") {
    notify_fail("The only thing here you can watch is 'porn'.\n");
    return 0;
  }

  if (present("earwax_brother",this_object())) {
    write(line_wrap("Earwax's brother slaps you across the back of your head, and goes back \
to playing his video game.\n"));
    say(line_wrap("Earwax's brother slaps "+this_player()->query_name()+" across the \
back of their head, and goes back to playing his video game.\n"),
this_player());
    return 1;
  }

  write(line_wrap("You sit down and press play.  Unfortunately, the video has been \
worn out by constant use from Midget and Earwax's brother, and won't work.\n"));
  say(line_wrap(this_player()->query_name()+" sits down to watch the porn \
tape, but it's apparently worn out, and won't play.\n"),this_player());
  return 1;
}
