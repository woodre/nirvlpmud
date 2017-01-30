#include "/players/feldegast/log/logs.h"
#include "/players/feldegast/defines.h"
short() {
  return GRN+"A tangle vine"+NORM;
}
id(str) {
  return str=="vine";
}
long() {
  write("This is a large growth of moving and animated vines with six-inch\n"+
        "long thorns that is sitting in the middle of the path.  Maybe\n"+
        "you should find something to cut it down to size?\n");
}
init() {
  add_action("block","east");
}
block() {
  if(present("quest_shears",this_player())) {
    write("You hack away at the tangle vine with your shears and\n"+
          "it lets you pass.\n");
#ifdef PATHLOG
    write_file(PATHLOG,ctime(time())+" "+TPN+" passed the tangle vine.\n");
#endif
    return 0;
  }
  if(this_player()->query_real_name()=="uggl") {
    return 0;
  }
  write("The tangle vine blocks the path and there's no way around it.\n");
  return 1;
}
