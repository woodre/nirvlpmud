#include "/players/mythos/closed/guild/def.h"

object ob, ob2;
int n,m,check;

short() {
  string shr;
  shr = allocate(18);
  shr[0]="Shrine Center [n,e,s,w]";
  shr[1]="Smithy [n]";
  shr[2]="Forest [n,e,s,w]";
  shr[3]="Forest Pathway4 [se]";
  shr[4]="Library Entrance [portal,n]";
  shr[5]="The Post Office [n,s]";
  shr[6]="Village church";
  shr[7]="Village church";
  shr[8]="Village church";
  shr[9]="Village church";
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
  write("You have entered the entrance hall to the guild.\n"+
        "darkness shrouds this room and sounds are deadened.\n");
  write("You may go: annex <back to the library> or assembly.\n");
}

reset(arg) {
 if(!present("plaque")) {
  move_object(clone_object("/players/mythos/closed/guild/plaque.c"),this_object());
}
if(arg) return;
  check = 0;
  set_light(-2);
}
realm() {return "NT"; }
init() {
  this_player()->set_fight_area();
  if(pp) { pp->set_defence(1);}
  if (present("black_orb",tp)) {
  ob = users();
  for(n=0;n<sizeof(ob);n++) {
  if(present(fear,ob[n])) {
  tell_object(ob[n],
  HIR+"THE ORB HAS BEEN TAKEN FROM THE ASSEMBLY!\nPAIN WRACKS YOUR BODY! <50-150dam>\n"+NORM);
  ob[n]->heal_self(-50 - random(100));
  } }
  }
  if(((!present(pact,tp) && !present(fear,tp) && !(tp->query_npc())) ||
  (present("black_orb",tp)) && !check)) {
  ob = users();
  m = 0;
  for(n=0;n<sizeof(ob);n++) {
  if(present(fear,ob[n])) {
  if(ob[n]->query_level() < 20) {
  m = m+1; }
  if(m>0)
  tell_object(ob[n],
  "The GUARDIAN screams: "+HIR+"SOMEONE HAS ENTERED THE GUILD HALL!\n"+NORM);
  } }
  if(m < 1) {
  write("You may not go any further!\n");
  move_object(tp,"/room/church.c");
  return 1;}
  if(m > 0 && m < 4) {
  ob2 = clone_object("/players/mythos/closed/guild/protect.c");
  ob2->set_mult(4);
  ob2->set_mult_chance(random(10));
  ob2->set_mult_dam1(random(7));
  ob2->set_mult_dam2(random(5));
  move_object(ob2,this_object());
  ob2 = clone_object("/players/mythos/closed/guild/protect.c");
  ob2->set_mult(2+random(3));
  ob2->set_mult_chance(random(10));
  ob2->set_mult_dam1(random(7));
  ob2->set_mult_dam2(random(5));
  move_object(ob2,this_object());
  move_object(clone_object("/players/mythos/closed/guild/sniper.c"),this_object());
  }
  if(m > 3 && m < 7) {
  ob2 = clone_object("/players/mythos/closed/guild/protect.c");
  ob2->set_mult(2);
  ob2->set_mult_chance(random(10));
  ob2->set_mult_dam1(random(7));
  ob2->set_mult_dam2(random(5));
  move_object(ob2,this_object());
  move_object(clone_object("/players/mythos/closed/guild/sniper.c"),this_object());
  }
  if(m > 6) {
  ob2 = clone_object("/players/mythos/closed/guild/protect.c");
  move_object(ob2,this_object());
  }
  }
  add_action("south","assembly");
  add_action("north","annex");
}

north() {
  if(present("guardian_demon",this_object()) && present("black_orb",tp)) {
  write("The GUARDIAN blocks your way!\n");
  say(capitalize(tpn)+" is blocked by the GUARDIAN.\n");
  return 1;}
  if( present("black_orb",tp ) ) {
  write_file("/players/mythos/closed/guild/check","1"); }
  MV,"north#players/mythos/closed/guild/seclib.c");
return 1;}

south() {
if(present("guardian_demon",this_object()) && !present(fear,tp)) {
  write("The GUARDIAN blocks your way!\n");
  say(capitalize(tpn)+" is blocked by the GUARDIAN.\n");
  return 1;}
  MV,"south#players/mythos/closed/guild/assembly.c");
return 1;}
