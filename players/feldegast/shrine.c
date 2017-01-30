#include "/players/feldegast/defines.h"
#include "/players/feldegast/log/logs.h"
#define FLOG(x) write_file(SHRINE_LOG,ctime(time())+" "+x);

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  no_fight=1;
  short_desc="A Marble Shrine";
  long_desc=
    "    This beautiful shrine brings calm and peace to your mind.  A\n"+
    "marble basin, filled with cool crystal water, stands in the center\n"+
    "of the room.  Marble columns support the tall ceiling, each pair\n"+
    "forming an archway with a word over it.\n"+
    "The following archways are open:\n"+
    "\tarena\tisland\tdesert\ttower\n"+
    "\tdark \tangel \tdreams\ttree\n";
  items=({
    "basin","The water inside the basin seems to 'reflect' depending\n"+
            "on where the looker stands",
    "water","The water inside the basin seems to 'reflect' differently\n"+
            "depending on where the looker stands",
    "columns","Roman columns of the doric or 'fluted' style",
    "archway","All you can make out is an etheriel blue glow inside the archway",
    "shadows","Perhaps you can make out a faint blue glow?  It's difficult to tell",
    "word","Each archway has a different word over it:\n"+
           "\tarena, island, desert, tower, dark, angel, dreams, and tree"
  });
  dest_dir=({
    "/room/plane12","out",
  });
}

void init() {
  ::init();


  add_action("arena","arena");
  add_action("island","island");
  add_action("desert","desert");
  add_action("tower","tower");

  add_action("dark","dark");
  add_action("angel","angel");
  add_action("dreams","dreams");
  add_action("tree","tree");

  add_action("reflect","reflect");
}

void create_portal(string destination) {
  object gate;
  object dest;
  dest = find_object(destination);
  if(dest && !present("azure portal",dest)) {
    gate=clone_object("/players/feldegast/obj/azure_portal");
    gate->set_destination("/players/feldegast/shrine");
    move_object(gate,destination);
    call_out("close_gate",120,gate);
  }
}

int arena(string str) {
  TP->move_player("through the 'arena' gate#/players/feldegast/arena/rooms/foyer");
  return 1;
}

int island(string str) {
  TP->move_player("island#/players/feldegast/island/beach1");
  return 1;
}

int desert(string str) {
#ifdef SHRINE_LOG
  FTELL(TPRN+" went 'desert'.\n");
  FLOG(pad(TPRN,20)+"desert\n");
#endif
  TP->move_player("desert#/players/feldegast/realm/JalHab/Map");
  return 1;
}

int dark(string str) {
  write(BOLD+"Warning: Sections of this area are player killing zones.\n"+NORM);
  TP->move_player("through the 'dark' portal#/players/feldegast/darkcity/street2");
  return 1;
}

int tower(string str) {
#ifdef SHRINE_LOG
  FTELL(TPRN+" went 'tower'.\n");
  FLOG(pad(TPRN,20)+"tower\n");
#endif
  TP->move_player("through the 'tower' portal#/players/feldegast/closed/tower/outside");
  return 1;
}

int angel(string str) {
  create_portal("/room/south/sforst45");
  write("You step through the archway and find yourself in a\n"+
        "distant corner of Nirvana.\n");
  this_player()->move_player("angel#room/south/sforst45");
  say(TPN+" steps into the room through an "+BLU+"azure"+NORM+" portal.\n");
  return 1;
}

int dreams(string str) {
  create_portal("/room/forest9");
  write("You step through the archway and find yourself in a\n"+
        "distant corner of Nirvana.\n");
  this_player()->move_player("dreams#room/forest9");
  say(TPN+" steps into the room through an "+BLU+"azure"+NORM+" portal.\n");
  return 1;
}

int tree(string str) {
  create_portal("/players/jaraxle/3rd/warrior/rooms/entrance");
  write("You step through the archway and find yourself... elsewhere.\n");
  this_player()->move_player("through the 'tree' portal#players/jaraxle/3rd/warrior/rooms/entrance");
  say(TPN+" steps out of an "+BLU+"azure"+NORM+" portal.\n");
  return 1;
}

void close_gate(object gate) {
  tell_room(environment(gate),"The "+BLU+"azure"+NORM+" portal closes.\n");
  destruct(gate);
}

int reflect(string str) {
  if(!str) {
    write("You see strange images in the reflection as you glimpse each archway.\n");
    return 1;
  }
  switch(str) {
    case "arena" :
      write(
        "You see a place where players can fight each other fairly and without\n"+
        "outside interference.  You also see a marketplace where valuable items\n"+
        "may be bought.\n");
      break;
    case "island" :
      write(
        "You see a wondrous tropical island with beautiful beaches and lush\n"+
        "jungles, yet under the tyranny of three hags and threatened by a\n"+
        "band of pirates.\n");
      break;
    case "angel" : write(
      "You see the statue of an angel, covered in undergrowth, in a far corner \n"+
      "of Nirvana.\n");
      break;
    case "desert" : write(
      "You see a barren desert, tainted by the presence of an evil demon.\n"+
      "You see a village filled with strange green creatures, and a city\n"+
      "of traders with many fine goods.\n");
      break;
    case "dreams" : 
      write(
        "You see in the reflecting pool a stairway leading up to a\n"+
        "city in the clouds where a totem pole can be used to guide\n"+
        "you to a distant place where an ancient people live and\n"+
        "reside atop a high plateau.\n");
      break;
    case "dark" : 
      write(
        "You see a dark city in a place between stars, a world where the light\n"+
        "fears to tread and even the fabric of reality itself is subject to\n"+
        "to the tyranny of the Strangers.\n");
      break;
    case "tower" : 
      write("You see a tower sitting in the middle of a beautiful forest.\n");
      break;
    case "tree" : 
      write("You see a dense green forest shadowed by a dark black pyramid.  A\n"+
            "looming volcano smokes tirelessly beyond the forest.  You also see\n"+
            "a purple lake beside the forest.\n");
      break;
    default: write("Reflect what?\n");
  }
  return 1;
}
