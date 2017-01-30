#include "/players/mythos/closed/guild/def.h"
object pest;
inherit "room/room";

reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = HIC+"Shimmering Field of Power"+NORM;
    long_desc =
    HIC+"Around you shimmers a field of great power!\n"+
    "There is a pedastal set within the center of the\n"+
    "room.  Beneath the pedastal a tomb lies....\n"+NORM;
  items = ({
    "pedastal","Something could be 'place'd on it",
  });

} }

realm() { return "NT"; }

init() {
 ::init();
 if(tgl != 8 || tl < 17 || qtf < 10 || !present("taormin",tp)) {
      write("Suddenly you feel that something is seriously wrong!\n");
      if(random(2)==0 && !(tp->id("rosier"))) tp->zap_object(tp);
    }
 add_action("pplace","place");
}

pplace(str) {
  if(!str) return 0;
  if(str == "jewel" || str == "taormin") {
    if(!present("taormin",tp)) { tp->zap_object(tp); return 1;}
    write("You gently place the Taormin on the pedastal.\n");
    destruct(present("taormin",tp));
    pest = tp;
    call_out("placed",10);
  return 1;}
  else return 0;
}  
placed() {
object reve;
  tell_object(pest,"Suddenly, the Taormin flashes!\n"+
                   RED+"Red Mist envelops you!\n"+NORM);
  reve = clone_object("/players/mythos/closed/guild/task/hill/revenge.c");
  move_object(reve,this_object());
  reve->attack_object(pest);
return 1;}
