#include "../defs.h"
inherit ROOM;

reset(int arg){
object ward;
  if(arg) return;
    is_pk = 1;
    ward = clone_object(OBJ+"/misc/livingward.c");
    ward->set_dir("south");
    ward->set_long("A large circle, formed by inlaid red stones into the floor.  It\n"+
                   "is surrounded by large arcane markings and glows a deep red.  A\n"+
                   "strange mist emanates off of the boundaries of the circle.\n");
    move_object(ward,this_object());
    set_light(1);
    short_desc= "Necromancer Stronghold";
    long_desc="  "+
       "The high archways within this room support the vaulted ceiling, chipped by\n"+
       "years of little upkeep.  The walls are carved of a white marble, interlaced\n"+
       "with delicate blue veins, which have also been dulled by age.  The center of\n"+
       "the floor holds a large circle with many arcane markings, inlaid with small\n"+
       "pieces of stone.  The circle glows softly, emanating a dark red mist.  The\n"+
       "great hall opens up through an arch to the north, and doors lead to both the\n"+
       "east and west.  A small tunnel in the southern wall leads out to the city of\n"+
       "Qual'tor.\n";

     
    items=({
     "archways","They are very high and support the vaulted ceiling",
     "ceiling","It is very high up and though vaulted very plain",
     "walls","They are covered by white marble",
     "marble","It was once delicately carved but now has become chipped from age",
     "floor","A large circle formed from inlaid stone makeup the floor",
     "circle","There are many arcane markings upon it.  It glows softly",
     "stone","The many types of stone makes up the different inlaid peices",
     "tunnel","It leads through the southern wall out to the city of Qual'tor",    
     "guild","The guild hall of the Necromancers is to the north",
    });

    dest_dir=({
      PATH+"/room/necro2.c","north",
      "/players/daranath/qualtor/necro_entry.c","south",
      PATH+"/room/necro6.c","east",
    });
}

init(){
 ::init();
  add_action("search","search");
  add_action("dar_north","north");
}

search(){
  write("Bits of bone and areas of dried blood are all about the room.\n");
  say(tp->query_name() +" searches the area.\n");
  return 1;
}

dar_north() {
  if(!GOB) {
    write("You must be a Necromancer to go any further into the guild hall.\n");
    return 1;
  }
  return 0; 
}

realm() { return "NT"; }
