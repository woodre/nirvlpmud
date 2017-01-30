#include "/players/mythos/closed/guild/def.h"

short() {
  string shr;
  shr = allocate(18);
  shr[0]="Shrine Center [n,e,s,w]";
  shr[1]="Smithy [n]";
  shr[2]="Forest [n,e,s,w]";
  shr[3]="Forest Pathway4 [se]";
  shr[4]="Library Entrance [portal,n]";
  shr[5]="The Post Office [n,s]";
  shr[6]="Village Church";
  shr[7]="Village Church";
  shr[8]="Village Church";
  shr[9]="Village Church";
  shr[10]="Just for Kicks [n,s]";
  shr[11]="Just for Kicks [w,e]";
  shr[12]="The adventurers guild";
  shr[13]="The stomach [throw_up,s,blood]";
  shr[14]="BGC Tokyo [n,w,s]";
  shr[15]="Village road [west,east,south,north]";
  shr[16]="Jetty [w,e]";
  shr[17]="City of Ryllian [n,e,s,w]";
  return shr[random(18)];
}

long() {
  write("You are in the storage room.  Here you may leave items for others.\n");
  write("You may go: assembly <back to the assembly>.\n");
}

realm() {return "NT"; }
init() {
set_light(0);
  this_player()->set_fight_area();
  if(pp) { pp->set_defence(1);}
  add_action("assembly","assembly");
  if(!present("guildboard")) {
  move_object(clone_object("/players/mythos/closed/guild/board.c"),this_object());
  }
}

assembly() {
  MV,"north#players/mythos/closed/guild/assembly.c");
return 1;}

iv() {
object hr;
int n;
hr = all_inventory(this_object());
  for(n=0;n<sizeof(hr);n++) {
    write(hr[n]->short()+"\n");
  }
return 1;}
