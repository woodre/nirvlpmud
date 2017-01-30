#include "/players/coldwind/define.h"
inherit "room/room";
reset(arg) {	
  if(arg) return;
set_light(1);
short_desc = ""+HIC+"M"+NORM+YEL+"a"+HIW+"g"+HIR+"i"+HIY+"c"+HIG+"a"+HIB+"l"+NORM+BOLD+" Carpet"+NORM+"";
long_desc =
"    You are riding a beautiful carpet that is floating softly above\n"+
"the ground. The carpet flies higher and as you look down you can see\n"+
"some of the castles and cities of Nirvana.\n"+
" \n"+
""+BOLD+"You feel you can Fly to:\n"+
"\n"+
""+HIY+"       Dahna      "+HIC+"Nirvana"+NORM+"\n";

items = ({
  "carpet",
  "A beautiful carpet crafted from goat hair",
  });


}

init(){
  ::init();
  add_action("dahna", "dahna");
  add_action("nirvana", "nirvana");
  
   }
  dahna(){
  say("The carpet drops "+tpn+" in Dahna desert.\n");
  write("You hold on tight to the sides of the carpet..\n"+
        "Cold wind dances on your face madly as the carpet flies\n"+
		"to the Dahana desert.\n");
move_object(this_player(), "/players/coldwind/desert/rooms/r1.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
write("You jump off the carpet into the sandy desert.\n");
return 1;
}
  nirvana(){
  say(tpn+" jumps back to Nirvana.\n");
move_object(this_player(), "/room/deep_forest1.c");
say (""+tpn+" arrives.\n");
command("look", this_player());
write("You jump off the carpet into the woods.\n");
return 1;
}	
