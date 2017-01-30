#define SET "players/braxana/horlach/location"
#define DAE  "/players/braxana/horlach/daemon.c"
#define MON  "/players/braxana/horlach/mon/"
#define WANDERLUST 30

string places;
string mon;
static object monster;

id(str) { return str == "invasion_ob_beasts"; }

reset(arg) {
  if(arg) return;
  monster = allocate(100);
  places = allocate(100);
  places[0] = "players/saber/ryllian/portal";
  places[1] = "room/vill_green";
  places[2] = "players/mythos/enterance";
  places[3] = "players/mythos/closed/guild/assembly";
  mon = allocate(100);
  mon[0] = MON+"servant.c";
  mon[1] = MON+"morph.c";
  mon[2] = MON+"firedrake.c";
  mon[3] = MON+"dom.c";
  mon[4] = MON+"dune_devil.c";
  mon[5] = MON+"defend.c";
  mon[6] = MON+"nightmare.c";
  mon[7] = MON+"bird.c";
  mon[8] = MON+"wolf.c";
  mon[9] = MON+"sandlizard.c";
  mon[10] = "";
  call_out("start",10);
}

start() {
int h;
  if(!restore_object(SET)) save_object(SET);
  for(h=0;h<100;h++) {
    if(places[h]) { 
    monster[h] = clone_object(mon[h]);
    monster[h]->set_aggressive(1);
    move_object(monster[h],places[h]); } }
  set_heart_beat(1);
return 1; }

heart_beat() {
  save_object(SET);
}

stat() {
  if(member_array(this_player(),monster) != -1) {
      places[

wander() {
  int h;
  string go;
  int j;
  for(h=0;h<100;h++) { 
    if(monster[h]) {
      if(random(100) < WANDERLUST) {
      j = random(15)
        switch(j) {
          case 0: go = "north"; monster[h]->init_command(go); 
          case 1: go = "ne"; monster[h]->init_command(go);
          case 2: go = "east"; monster[h]->init_command(go);
          case 3: go = "se";  monster[h]->init_command(go);
          case 4: go = "south";  monster[h]->init_command(go); 
          case 5: go = "sw"; monster[h]->init_command(go);
          case 6: go = "west";  monster[h]->init_command(go);
          case 7: go = "nw"; monster[h]->init_command(go);
          case 9: go = "in"; monster[h]->init_command(go);
          case 10: go = "out"; monster[h]->init_command(go);
          case 11: go = "enter"; monster[h]->init_command(go);
          case 13: go = "up"; monster[h]->init_command(go);
          case 14: go = "down"; monster[h]->init_command(go); break;
        }
     }
   }
 }
}
        
          