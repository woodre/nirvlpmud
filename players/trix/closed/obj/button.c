#include "/players/boltar/things/esc.h"
query_auto_load() { return "/players/trix/closed/obj/button.c:"; }
object who;
reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="button") return 1;
        return 0;
}

long() {
        write( "A featureless button, try and <push> it.\n");
}

short()
  { return "A button"; }
init()
{
  add_action( "push","push");
}

push(arg)
{ if(arg!="button") { notify_fail("Push what?\n"); return; }
  who=this_player();
  call_out("surprise",1);
  return 1;
}
surprise()
{ 
int i;
object rose;
tell_object(who,esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m");
tell_object(who,"\n             |    |    ----    ----    ----   \\  \/\n");
tell_object(who,"             |----|   |    |   |___|   |___|   \\\/\n");
tell_object(who,"             |    |   |----|   |       |       \/\n"); 
tell_object(who,"             |    |   |    |   |       |      \/\n\n");
tell_object(who,"             ------\n");
tell_object(who,"             |     |\n");
tell_object(who,"             |     |\n");
tell_object(who,"             |-----       ----\n");
tell_object(who,"             |     \\      |   |   ----   \\  \/\n");
tell_object(who,"             |      | === |   |  |    |   \\\/\n");
tell_object(who,"             |      |     |   |  |----|   \/\n");
tell_object(who,"             -------      ----   |    |  \/\n");
tell_object(who,esc+"[0m");
tell_object(who,"\n           You are overwhelmed by a rain of roses...\n");
for(i=1;i<=30;i++)
 {  rose=clone_object("/players/trix/closed/obj/rose2");
    if(random(2)) { move_object(rose,who); }
     else { move_object(rose,environment(who)); }
 }
}
 
get() {
        return 1;
}
drop() {
        return 0;
}
