#include "/players/wocket/closed/ansi.h"
#define RING "/players/wocket/wedding/ring.c"
inherit "obj/treasure";

reset(arg){
  if(arg) return 1;
set_id("marrymaker");
set_short("A marrymaker");
set_long("Its a wocket marrymaker.\n Options:\n\tmarry <person1> <person 2>\n");
set_weight(0);
}

init(){
     write("You arent suppose to have this.\n");
   add_action("marrymake","marry");
}

marrymake(string str){
string peep1,peep2;
object love1,love2;
object ring1,ring2;

if(sscanf(str,"%s %s",peep1,peep2) != 2){
    notify_fail("Usage: marry <person1> <person2>\n");
    return 0;
 }

love1 = present(peep1,environment(this_player()));
love2 = present(peep2,environment(this_player()));

if(!love1 || !love2){
    notify_fail("Usage: marry <person1> <person2>\n");
    return 0;
 }

ring1 = clone_object(RING);
ring2 = clone_object(RING);

ring1->set_spouse(peep2);
move_object(ring1,love1);

ring2->set_spouse(peep1);
move_object(ring2,love2);

tell_object(love1,"Congrats your married\n\t-wocket\n");
tell_object(love2,"Congrats your married\n\t-wocket\n");
write("The wedding has been preformed.\n");
this_player()->chan_msg(RED+"   @"+GRN+"}-,-`---"+NORM+BOLD+
               "    "+love1->query_name()+" and "+love2->query_name()+
               " have just been married    "+NORM+GRN+
               "---,-`-{"+RED+"@\n"+NORM,"junk"); 
return 1;
}                               
