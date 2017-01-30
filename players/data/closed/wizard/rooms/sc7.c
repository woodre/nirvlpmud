#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Arena");
   set_long(
   "  This is a simple stone-walled room. There is a single\n"+
   "exit leading out to the hall.  Here you can fight and the\n"+
   "magic of the room will not allow you to die.\n");
   add_property("NT");
   add_item("exit",
   "A heavy oak door that leads out to the hall");
   add_exit(ROOMS+"sc6","out");
   }



void catch_tell(string str)
{
    object obj;
    string who;

    if(!str) return;
    if(sscanf(str, "%s died.", who) == 1){
      object ob;
 
      if((ob = find_player(lower_case(who))) && 
          (environment(ob) == this_object()) && ((int)ob->query_hp() <= 0)
          && !curr_revive){
          no_die(ob);
          }  
    }
}

no_die(object ob){
object peeps;
object corpse;
  peeps = first_inventory(this_object());
  while(peeps) {
    peeps->stop_fight();
    peeps->stop_fight();
    peeps->stop_hunter();
    peeps = next_inventory(peeps);
    peeps->heal_self(600);
    }
if(corpse = present("corpse", this_object())){
transfer_all 
destruct(corpse
tell_room(this_object(),
"As "+ob->query_name()+" dies, the room glows...\n"+
ob->query_name()+" stands again and lives!\n");

return 1; 
}


okay_follow() { return 1; }
query_no_fight() { return 1; }