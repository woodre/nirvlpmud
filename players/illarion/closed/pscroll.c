#include "/players/illarion/dfns.h"
inherit "/obj/treasure";

void reset(status arg) {
  if(arg) return;
  
  set_id("scroll");
  set_short("A fancy scroll");
  set_long("Although constructed like a scroll of old, this one is made with\n"+
           "high quality paper.  Written on it is a three stanza poem, which\n"+
           "can be read using "+BLD("stanza1")+", "+BLD("stanza2")+", and "+
           BLD("stanza3")+".\n");
}
void init() {
  ::init();
  add_action("cmd_stanza1","stanza1");
  add_action("cmd_stanza2","stanza2");
  add_action("cmd_stanza3","stanza3");
}
status cmd_stanza1() {
   write(YEL+"[=============================================================]\n"+NORM);
   write("  |  Music in her soul, music in her touch,                  | \n"+
         "  |  Music in her eyes, warming me so much.                  | \n"+
         " |   Rightly named is Lyric, music of the mind,             |  \n"+
         "  |  Her instrument is me, that she had only to find.        | \n");
  return 1;
}
status cmd_stanza2() {
  write("  |  Sadness into strength, teardrops into steel,            | \n"+
        " |   Hatred never felt, feeling in me seal.                 |  \n"+
        " |   Rightly named is Lyric, music of the heart,            |  \n"+
        "  |  Her instrument is played, only better for the start.    | \n");
  return 1;
}
status cmd_stanza3() {
  write("  |  Distant and yet close, sightless and yet seen,          | \n"+
        "  |  Silent and yet heard, volumes would it mean,            | \n"+
        "  |  Rightly named is Lyric, music of the soul,              | \n"+
        " |   Her instrument is awed, and more playing on the roll.  |  \n");
  write(YEL+"[=============================================================]\n"+NORM);
  return 1;
}
