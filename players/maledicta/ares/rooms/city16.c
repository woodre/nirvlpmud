#include "../define.h"
#define DAEMON "/players/maledicta/templar/gdaemon.c"
#define CRIME "/players/boltar/templar/daemon/Criminal.c"
inherit ROOM;

reset(arg) {
int blah;
if(DAEMON->query_gl(2) > 5){ 
  if(!present("townguard_gate_mob", this_object())){
for(blah = 0; blah < 3; blah++){
   move_object(clone_object("/players/maledicta/ares/mobs/gate_guard2.c"), this_object());
   }
  } 
 }
if(DAEMON->gate2_condition() && !present("big_ol_gate", this_object())){
   move_object(clone_object("/players/maledicta/ares/mobs/gate2.c"), this_object());
   }
   if(arg) return;
   set_short(RED+"New Ares"+NORM);
   set_light(1);
   set_long(
YEL+"###"+NORM+HIR+"x"+NORM+YEL+"####"+NORM+"  [Main Street]\n"+
YEL+"##"+NORM+HIB+"A"+NORM+BOLD+"+---"+NORM+YEL+"#"+NORM+"\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"W"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  You stand before the gates of the castle\n"+
BOLD+"---+"+NORM+YEL+"##"+NORM+BOLD+"+-"+NORM+"  of the Templars of New Ares. They are set\n"+
YEL+"#"+NORM+HIB+"a"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+HIB+"B"+NORM+BOLD+"|"+NORM+YEL+"#"+NORM+"  within a formidable wall that is lined \n"+
YEL+"#"+NORM+HIB+"I"+NORM+YEL+"#"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  with numerous towers and spikes. High towers\n"+
YEL+"#"+NORM+BOLD+"--+---"+NORM+YEL+"#"+NORM+"  extend into the air from across the wall.\n"+
YEL+"###"+NORM+BOLD+"|"+NORM+YEL+"####"+NORM+"  The road leads back to the south.\n");
   add_item(
      "gates",
      "The large gates of the castle of the Templars of New Ares. You\n"+
      "can 'enter' the gates if you are invited");
   add_item(
      "castle",
      "This is the large spired castle of the Templars. Its walls are made\n"+
      "from a solid stone capable of resisting sieges of almost any caliber.\n"+
      "From here you can see small windows dotting the towers and walls of\n"+
      "the fortress.\n");
   add_item(
      "wall",
      "A sturdy outer wall that surrounds the inner keep and towers of the\n"+
      "castle");
   add_item(
      "towers", 
      "Tall towers the jut high into the air");
   add_item(
      "spikes",
      "Iron spikes that limit movement over the wall");
   add_item(
      "street",
      "A wide street that cuts through the center of New Ares and leads up to the\n"+
      "gates of the Templar's Castle");
   add_exit(ROOMS+"city15","south"); 
   add_exit("/players/maledicta/templar/rooms/gatehouse.c","enter");
   }

init(){
 ::init();
 add_action("get_key", "key");
 add_action("nogo", "enter");
 }

query_gate(){
if(present("big_ol_gate", this_object())) return 1;
return 0;
}

nogo(){
 if(present("townguard_gate_mob", this_object())){
   if(CRIME->Query(this_player()->query_real_name())){
      tell_room(this_object(),
      "The guard blocks the criminal "+this_player()->query_real_name()+"!\n");
      return 1;
      }
   if(DAEMON->query_war() && !present("KnightInvite", this_player())){
      tell_room(this_object(),
      "The Templar Guards block your entrance.\n"+
      "A guard shouts, \"No entrance! We are currently at War status!\"\n");
      return 1;
      }
   }
}



get_key(){
 write("\n\n"+HIM+"Map Key Code:"+NORM+"\n"+
       "   A "+HIM+"-"+NORM+"  Armorer\n"+
       "   B "+HIM+"-"+NORM+"  Bar\n"+
       "   I "+HIM+"-"+NORM+"  Inn\n"+
       "   W "+HIM+"-"+NORM+"  WeaponSmith\n"+
       "   a "+HIM+"-"+NORM+"  Alchemist\n"+
       "   x "+HIM+"-"+NORM+"  You!\n\n\n");
  return 1;
  }
