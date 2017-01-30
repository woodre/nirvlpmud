#define tp this_player()->query_name()
#include "std.h"
int count;
object ob;

short()  {  return "Falling";  }
long()  {  write(
"\n    F\n"+
"         A\n"+
"              L\n"+
"                   L\n"+
"                        I\n"+
"                             N\n"+
"                                  G\n\n");  }

init(){
  set_light(1);
  add_action("search","search");
  add_action("down","down");
  remove_call_out("falling");
  remove_call_out("falling");
  call_out("falling",6);
}

search() {
  write("You're got to be kidding...\n");
 return 1;  }

down()  {
  write("You already are going down!\n");
  return 1;
        }

falling()  {
say("\n     F\n"+
"            A\n"+
"                   L\n"+
"                          L\n"+
"                                 I\n"+
"                                        N\n"+
"                                               G\n\n");
  count = count + 1;
  if(count == 15)  {
    say("You see the ground far below you.\n");
        }
  if(count == 17)  {
    say("The ground rushes up to meet you!\n");
        }
  if(count == 19)  {
    say("You see icy mountains and lots of snow.!!!\n");
        }
  if(count > 21)  {
    say("S P L A T\n");
  ob = first_inventory(this_object());
    while(ob)  {
    if(living(ob))  {
    call_other(ob, "move_player", "down and SPLATTERS into the ground#players/saber/closed/quest/ice/x1.c");
        }
  ob = next_inventory(this_object());
        }
  return 1;
        }
  call_out("falling",20 + random(5));
  return 1;
        }
