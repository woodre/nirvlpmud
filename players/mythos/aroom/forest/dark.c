#include "/players/mythos/closed/ansi.h"
short() {
    return BOLD+"Darkness"+NORM;  /* Changed from write() - Snow 9/99 */
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
   add_action("quit", "");
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
  int n;
  n=random(3);
  if(n != 0) {
  write(HIG+BLINK+"The Darkness Does Not Let Go!"+NORM);
  write("\nTry 'quit' eventually it may work\n");
  return 1;
}
    return 0;
}
  return 1; }
 
 
