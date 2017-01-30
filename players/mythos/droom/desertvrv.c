#include "/players/mythos/dmon/def.h"
#include "/players/mythos/droom/drom.c"
#define  MASTER  "/players/mythos/droom/master.c"
reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light_switch(2);
    set_short(RED+"Sylan Desert"+NORM,0);
    set_long("It is "+RED+"HOT"+NORM+"\n"+
             "A heat so tortuous and powerful that the senses writhe in agony.\n"+
             "The angry sun beats down upon you and sounds are deadened.\n"+
             "The eye has no place to go for all is too bright and too intense.\n"+
             "Neverending sand stretches out before you.\n",0);
    set_short(YEL+"Neverending Sands...."+NORM,1);
    set_short(RED+"The Desert of the Dying"+NORM,2);
    set_short(HIR+"The Place of the Dead"+NORM,3);
    set_short(MAG+"The SandDunes of Myth"+NORM,4);
    set_short(RED+"The Place Where Legends Meet"+NORM,5);
    set_long("The sand dunes stretch out far as your eyes can see.\n"+
             "Dreadful heat beats down upon your sweating body.\n"+
             "You wonder what could have possibly led you to trudge\n"+
             "forth into this dreadful place... what act or thought of\n"+
             "foolishness promopted you to challenge the might of the\n"+
             "Desert?\n",1);
    set_long("Your eyes are blinded by the intensity of the sand.\n"+
             "The sun's rays slam into your eyes, piercing the center\n"+
             "of your being.  No sounds help your blinded state nor smell.\n"+
             "All you know and sense is the Heat and the Light.\n",2);
    set_long("The "+YEL+"Desert"+NORM+" stretches out before you.\n"+
             "Your body shudders as the water within is forced out by\n"+
             "the great blaze above and below.  Death seems like a likely\n"+
             "and hopeful possibility.....\n",3);
    set_long("You see a flicker of movement.  Or so you thought you did.\n"+
             "The mind plays tricks upon the self as it trys to escape\n"+
             "the reality that surrounds it.  Endless upon endless dunes\n"+
             "of sand....\n",4);
    set_long("The heat is intense.  The lips and throat thirst.  The\n"+
             "mind is dulled as the scenery is neverending.  Skin is\n"+
             "in pain, the hands feel nothing.  The face is whipped by\n"+
             "the hot winds and blasting sand.\n",5);
    set_grid(0,0);
    set_realm();
  set_dir("~desertvr","n");
  set_dir("~desertvr","e");
  set_dir("~desertvr","s");
  set_dir("~desertvr","w");
  set_init_chance(0,1);
  set_init_chance(1,random(20));
  set_init_monsters("~dom.c",1);
  set_init_chance(2, random(20));
  set_init_monsters("~sandlizard.c",2);
  set_init_chance(3, random(20));
  set_init_monsters("~morph.c",3);
  set_init_chance(4, random(20));
  set_init_monsters("~morph2.c",4);
  set_init_chance(5, random(20));
  set_init_monsters("~firedrake.c",5);
  set_init_chance(6, random(10));
  set_init_monsters("~dune_devil.c",6);
  set_init_chance(7, random(8));
  set_init_monsters("~sand_devil.c",7);
} }

init() {  
  if(!present("portal") && 
    ((grid[0] == 0 && grid[1] == 0) ||
    random(10) == 0)) {
    move_object(clone_object("/players/mythos/dmisc/portal.c"),this_object());
  }
  if(!present("rubble") && 
    ((grid[0] == 0 && grid[1] == 0) ||
    random(10) == 0)) {
    move_object(clone_object("/players/mythos/dmisc/stone.c"),this_object());
  }
  ::init();
 add_action("destvr","north",1);
 add_action("destvr","south",1); 
 add_action("destvr","east",1); 
 add_action("destvr","west",1);
 if(this_player()->query_level() > 200){
  add_action("show_short","sshort");
   show_short();
 }
}

move() { return 1; }

destvr() {
  if(!hardcoded(query_verb(),grid[0],grid[1])) {
  /*
  if(query_destdir(query_destname(query_verb())) != 69) {
  if(query_destdir(query_destname(query_verb()) - 1) == "~desertvr") { */
    object plane;
    string msg;
    int tobegrid1,tobegrid2;
	tobegrid1 = tobegrid2 = 0;
    if(present("devil") && (grid[0] != 0 ||
    grid[1] != 0) && random(3) == 0) { 
    write("The devil prevents you from going anywhere.\n");
    if(this_player()->query_level() < 200) return 1; }
    if(query_verb() == "n" ||query_verb() == "north") {
      tobegrid1 = grid[0];
      tobegrid2 = grid[1] + 1;
	 
      msg = "north";
    }
    else if(query_verb() == "e" ||query_verb() == "east") {
      tobegrid1 = grid[0] + 1;
      tobegrid2 = grid[1];
      msg = "east";
    }
    else if(query_verb() == "s" ||query_verb() == "south") {
      tobegrid1 = grid[0];
      tobegrid2 = grid[1] - 1;
      msg = "south";
    }
    else if (query_verb() == "w" ||query_verb() == "west") {
      tobegrid1 = grid[0] - 1;
      tobegrid2 = grid[1];
      msg = "west";
    }
    if(MASTER->query_exist(tobegrid1,tobegrid2)) {
    plane = MASTER->query_exist(tobegrid1,tobegrid2);
    } else {
    plane = clone_object("/players/mythos/droom/desertvr.c");
    plane->set_short_value(random(6));
    plane->set_long_value(random(6));
    plane->set_grid(tobegrid1,tobegrid2); }
   move_object(this_player(),plane);
    if(!this_player()->query_invis()) {
      tell_room(this_object(),this_player()->query_name()+" leaves "+msg+".\n");
      tell_room(plane,this_player()->query_name()+" arrives.\n");
    }
    command("look",this_player());
   return 1;}
}

int hardcoded(string going,int lat,int lon) {
string bye;
if(going == "n" || going == "north") { lon = lon + 1; bye = "north"; }
if(going == "s" || going == "south") { lon = lon - 1; bye = "south"; }
if(going == "e" || going == "east") { lat = lat + 1; bye = "east"; }
if(going == "w" || going == "west") { lat = lat - 1; bye = "west"; }

      /* hardcoded rooms */
      
if(lat == 0 && lon == 0) {   
  this_player()->move_player(bye+"#players/mythos/droom/desert.c");
return 1; } 

return 0; }
  
show_short() { write(short()+"\n"); return 1; }
