#include "/players/mythos/closed/ansi.h"
#define tp this_player()
#define tl tp->query_level()
#define tpn tp->query_real_name()
#define TR tell_room(environment(this_object()
int sit;

id(str) { return str == "throne" || 
                 str == "crystal throne" || 
                 str == "glyph"; }

short() { if(sit)return BLU+"Crystal Throne"+NORM;)
          else return "Cystal Throne"; }

long() { write("\n");
         if(present(tpn,this_object())) {
         write("\n");
       }}

drop() { return 0; }
get() { return 0; }

reset(arg) {
  if(arg) return;
  sit = 0;
  call_out("sit_check",100);
}

sit_check() {
object ob;
int h,i;
i = 0;
ob = all_inventory(this_object());
for(h=0;h<sizeof<ob);h++) {
   if(living(ob[h]) && ob[h]->is_player()) i = 1;
}
if(!i) sit = 0;
call_out("sit_check",100);
return 1; }

init() {
  if(environment(this_object()) == tp) {
    destruct(tp);
  return 1; }
  if(!present(tpn,this_object()) add_action("sit","sit");
  else {
    add_action("stand","stand");
    add_action("conjure","conjure");
  }
}

conjure() {
object dem;
  write("You concentrate...\n"+
        "Suddenly SOMTHING infuses you and you chant:\n"+
        "         Karusa Bravadignya Karusa\n");
  TR,capitalize(tpn)+" suddenly chants in a deep voice:\n"+
                "      Karusa Bravadignya Karusa\n");
  write("\nYou suddenly see before you a "+RED+"Circle of"+
        "Kresh"+NORM+" appear and flare with a brillance\n"+
        "of a thousand moons....\n\n");
write("A voice whispers: What is thy bidding,Master....\n");
  TR,"\n\n\t\t\t"+RED+"F   L   A   S   H"+NORM+"\n\n\n");
  dem = clone_object("/players/mythos/dmon/djnn.c");
  dem->set_master(tp->query_real_name());
  dem->set_nameset("djinn #"+random(10000));
  /* demon conjuration switch is on in kah */
  /* and dem is set into array */
  move_object(dem,this_object());
  command("look",tp);
return 1; }

sit(str) {
  if(!str) return 0;
  if(id(str)) {
  if(sit) { 
   write("Someone is or has been sitting here.\n"+
         "Wait for the glow of the crystal to dim.\n");
  return 1; }
  sit = 1;
  write("You sit upon the throne!\n"+
        "The world about you seems to change...\n"+
      "Light fills your being and you have gained much!\n");
  move_object(tp,this_object());
  }
}

stand() {
  write("You get up from the Throne.\n");
  say(capitalize(tpn)+" gets up from the chair.\n");
  move_object(tp,environment(this_object()));
  sit = 0;
return 1; }

realm() { return "NT"; }


