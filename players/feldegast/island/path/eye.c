#include "/players/feldegast/log/logs.h"
#include "/players/feldegast/defines.h"
short() {
  return "An all-seeing, all-knowing eye";
}
id(str) {
  return str=="eye";
}
long() {
  write(
"This all-seeing, all-knowing eye is difficult to look at for long.\n"+
"Like some huge orb torn from the socket of a god, it stares into\n"+
"your heart and sees all that is evil and unpure.\n"
  );
}
init() {
  add_action("block","south");
}
block() {
  if(present("mirror",this_player())) {
    write("You hold the mirror in front of you as you creap along the path.\n"+
          "Before long, you are out of its sight.\n");
#ifdef PATHLOG
    write_file(PATHLOG,ctime(time())+" "+TPN+" passed the eye.\n");
#endif
    return 0;
  }
  if(this_player()->query_real_name()=="horrenda") {
    return 0;
  }
  write(
"The great eye stares into your soul, seeing your darkest secrets and\n"+
"your hidden shames.  You collapse on the ground and somehow manage to\n"+
"drag yourself away from its gaze.\n"
  );
  return 1;
}
