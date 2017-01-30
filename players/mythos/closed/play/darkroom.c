#include "/players/mythos/closed/ansi.h"
short() {
    write(BOLD+"Darkness"+NORM);
}

long() {
    write(HIR+BLINK+"\n\n\t\tYou Were Warned!\n\n"+NORM);
    write("The darkness shrouds you...It is frightening!\n");
    write("You realize that there is no escape!\n");
}

reset(arg) {
  if(!present("darksound")) {
    move_object(clone_object("/players/mythos/amon/forest/darks.c"),this_object()); }
    if (arg)
	return;
    set_light(1);
}

init() {
#ifndef __LDMUD__
    add_action("quit");add_xverb("");
#else
   add_action("quit", "", 3);
#endif
}

quit() {
  if(this_player()->query_real_name() == "mythos") {
    write("\n");
    write(HIB+"The darkness pulls back....\n"+"And something says: Yes master.\n");
    write(NORM+"\n");
    call_other(this_player(),"move_player","quit#players/mythos/workroom.c");
  return 1; }
    else {
  write(HIG+BLINK+"The Darkness Does Not Let Go!"+NORM);
  write("\n");
  return 1;
}
  return 1; }
