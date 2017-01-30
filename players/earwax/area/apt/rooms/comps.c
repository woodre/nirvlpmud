#include "defs.h"
inherit ROOM;

void on_create() {
  set_area("area");
  set_short("Computer Room in Earwax's Old Apartment");
  set_long("You're standing in a small area that Earwax and Midget use \
as their computer room.  There are two computers here, and if you know \
Midget at all, you'd know that the newer computer is his.  You'd know \
this because of the sheer amount of porn being downloaded on it, and by \
the fact that it's some seriously demented shit.  The older computer, \
being Earwax's, is running a MUD client at the moment.  There is a hard \
kitchen chair in front of Midget's computer, and a recliner and footrest \
in front of Earwax's.");
  add_desc("newer computer","This is Midget's computer.  He's \
apparently downloading a ton of porn, maybe you can take a look at it.");
  add_desc("older computer","This is Earwax's computer.  He's idling \
on his other MUD, Round Table 3, and he's disconnected on Nirvana. \
Apparently, he's a wizard on both, with the same horrible name.");
  add_desc("footrest","The footrest is actually a cardboard box filled \
with maps, code, and charts of MUD-related information.  What a nerd!");
  add_desc("chair","It's a straight-backed chair of the type commonly \
found in kitchens.  Midget, however, uses it for watching porn while \
stroking his shit.");
  add_desc("recliner","This is the recliner Earwax sits in as he MUDS.\
It looks very comfortable, and is the perfect height for typing and \
watching the screen for extended periods of time.");
  add_desc("porn","&porn_desc");
  add_desc("computer","Which do you want to look at?  The 'older computer' or the 'newer computer'?");
  add_desc("computers","Which do you want to look at?  The 'older computer' or the 'newer computer'?");
  add_exit("south",APTR+"living.c");
}

void porn_desc() {
  string desc;
  int t;

  t = random(10);

  switch(t) {
    case 0 : desc = "a monkey holding his schvantz while drinking his \
own piss."; break;
    case 1 : desc = "a woman is blowing a horse.  She gags on the huge \
freaking horsedick, and starts gagging and retching.  Funny shit."; break;
    case 2 : desc = "a naked picture of Jennifer Love Hewitt."; break;
    case 3 : desc = "a grainy movie clip of some dude's hairy ass cheeks \
flapping away as he apparently pounds away on some chick.  Two problems: \
you can't see shit other than the dude's hairy ass, and you can barely \
even make that much out."; break;
    case 4 : desc = "a movie clip of Demi Moore in Striptease.  Good stuff. "; break;
    case 5 : desc = "a clip entitled 'Mimi Miyagi face-seat.'  It's bad, \
really bad.  This REALLY obese woman is sitting on some poor dude's \
face.  All you can see is her cottage-cheese ass-cheeks wrapped around \
this shiny dome that keeps getting redder and redder, as he starts to \
pass out from lack of oxygen."; break;
    case 6 : desc = "a clip from the hit XXX movie 'Wet-Nurses.'  \
Now THIS, is the kind of porn Earwax can deal with.  He'll probably get \
some hand to this later on.  Two really hot women butt-nekked and going \
at it."; break;
    case 7 : desc = "an octogenarian getting it on with what appears to \
be a teenage prostitute.  Low quality on top of it."; break;
    case 8 : desc = "some girl wearing a college sweatshirt stroking \
off a great dane.  This then progresses further, but the window mercifully \
closes out with an error message."; break;
    case 9 : desc = "the text 'You're a sick fuck!' over some guy's hand \
with the middle finger extended."; break;
  }
  write(line_wrap("You point at a random porn file and double click.  The \
screen pauses for a minute, then a new window comes up and you see "+desc+"\n"));
}
