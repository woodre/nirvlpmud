#include "/players/jareel/define.h"
inherit "/obj/treasure.c";
reset(arg){
    if(arg) return;
    set_id("can");
     set_short(BOLD+"Can of Woop-Ass"+NORM+"\n");
     set_long(HIW+"A can of WOOP-ASS!!!!!!!."+NORM+"\n");
     set_weight(0);
     set_value(0); }
init() {
    ::init();
if(TP->query_level() > 20) {
    add_action("attack_it", "for");
    add_action("cmd_at","at");
}}

attack_it(str){
           string a,b;
           string att1, att2;
           sscanf(str, "%s %s", att1, att2);
           a = present(att1, environment(this_player()));
           b = present(att2, environment(this_player()));
           b->attack_object(a); 
           a->attack_object(b);
return 1;
}
int cmd_at(string str)
{
  object other_player;
  object old_room;
  string cmd, who;
  
  if(!str) return 0;
  if((int)this_player()->query_level() < 21)
    return 0;
    
  if (sscanf(str, "%s %s", who, cmd) != 2) 
  {
    write("Usage: 'at <player> <cmd>'\n");
    return 1;
  }

  other_player = find_living(who);
  if(!other_player) 
  {
    write("There is no living creature named " + who + ".\n");
    return 1;
  }

  old_room = environment(this_player());
  move_object(this_player(), environment(other_player));
  command(cmd, this_player());
  move_object(this_player(), old_room);
  return 1;
}
