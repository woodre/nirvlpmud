#include "/players/wocket/closed/ansi.h"

id(str){ return str == "transferob"; }

init(){
  add_action("newbody","newbody");
}

newbody(){
object newbody,oldbody;
  newbody = clone_object("/players/wocket/junk/newbody.c");
  oldbody = this_player();
  move_object(newbody,environment(oldbody));
  write("moved newbody,before exec\n");
if(!exec(newbody,oldbody)){ write("exec failed.\n"); }
exec(newbody,oldbody);
  write("exec called.\n");
  newbody->new_soul(oldbody->query_real_name());
  write("newsoul called.\n");
return 1;
}
