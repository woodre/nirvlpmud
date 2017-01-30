#include "std.h"
 int shield, notin;
 object ufo;
init() {
  no_clean = 1;
  add_action("on"); add_verb("on");
  add_action("pty","pty");
  add_action("post"); add_verb("post");
  add_action("off"); add_verb("off");
  add_action("out"); add_verb("out");
  add_action("north"); add_verb("north");
  add_action("west"); add_verb("west");
  add_action("east"); add_verb("east");
  add_action("ufo","ufo");
  set_light( 1);
  if(this_player()->query_real_name() != "boltar" && shield == 1) {
  write("You feel an electric shock and see a flash of green light as\n");
  write("you rebound off the defense shield.\n");
  if (notin == 1) {
  write("Boltar is not in or on another job right now, please leave a\n");
  write("message at the post office.\n");
  }
  this_player()->move_player("off the shields#players/boltar/lv1/landing");
 }
 }
static on() {
   shield = 1;
   write("shields activated.\n");
   return 1;
   }
static off() {
   if (call_other(this_player(), "query_real_name", 0) != "boltar") {
  write("You are not allowed to do that!!!!!!!\n");
    return 1;
    }
   shield = 0;
   notin = 0;
   write("shields deacivated.\n");
   return 1;
   }
out() {
   shield = 1;
   notin = 1;
   write("shields on, out message on.\n");
   return 1;
   }

short() {
 int t;
 t = random(29);
 if(t==0)   return "Boltar's workroom";
 if(t==1) return "Soul Food Cafe";
 if(t==2) return "Bob's Country Bunker";
 if(t==3) return "The Palace Hotel Ballroom";
 if(t==4) return "1060 W. Addison";
 if(t==5) return "Dixie Mall";
 if(t==6) return "The Tripple Rock Church";
 if(t==7) return "Saint Helen of the Blessed Shroud Orphanage";
 if(t==8) return "Curl up and Dye Salon";
 if(t==9) return "Ray's Music Exchange";
 if(t==10) return "The Double up Lounge";
 if(t==11) return "The Chez Paul";
 if(t==12) return "Daley Plaza";
 if(t==13) return "Maxwell Street";
 if(t==14) return "The Armada Room";
 if(t==15) return "Joliet Correctional Facility";
 if(t==16) return "East 95th Street Bridge";
 if(t==17) return "SRO Hotel";
 if(t==18) return "The Aerosol Factory";
 if(t==19) return "Mrs. Tarantino's House";
 if(t==20) return "Outside the Holiday Inn";
 if(t==21) return "Morgan Park Theater";
 if(t==22) return "29 Cove Road";
 if(t==23) return "a h0liday in Sweden";
 if(t==24) return "Camelot ... Camelot ...";
 if(t==25) return "Castle Anthrax (in great peril)";
 if(t==26) return "Bridge of Death";
 if(t==27) return "castle on a swamp";
 if(t==28) return "the cave of Caerbannog";
 if(t==29) return "This space intentionally left blank";
 }
 long() {
 write("shields are at " + shield + "   not in message is at " + notin + "\n");
 write(""+
           "This is Boltar's workroom, the walls are covered with drawings\n" +
           "of his great designs and inventions.\n");
  }
west() {
  call_other(this_player(), "move_player", "west#players/boltar/sprooms/hall.c");
  return 1;
  }
east() {
  call_other(this_player(), "move_player", "east#players/boltar/lv1/landing.c");
  return 1;
 }
 north() {
  call_other(this_player(), "move_player", "north#room/alley");
  return 1;
  }
post(){
  object mobj;
/*
   mobj = clone_object("/obj/mail_reader.c");
   move_object(mobj, this_player());
*/
move_object(this_player(), "room/post");
   return 1;
  }
pty(){
  move_object(clone_object("players/boltar/closed/party"),this_object());
  return 1;
  }
ufo(str) {
  if(str=="track") {
    write(file_name(environment(ufo)));
    return 1;
  }
  if(str=="clone") {
    ufo = clone_object("/players/boltar/things/ufo");
    move_object(ufo,this_object());
    return 1;
  }
  if(find_player(str)) {
    ufo->move_player("up into the sky#"+file_name(environment(find_player(str))));
    return 1;
   }
   ufo->move_me(str);
  if(sscanf(str,"abduct %s",str)==1) {
   ufo->move_player("up into the sky#"+file_name(environment(find_player(str))));
   ufo->abduct(str);
   return 1;
  }
return 1;
}
