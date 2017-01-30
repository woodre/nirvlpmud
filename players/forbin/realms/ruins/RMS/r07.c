#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(26, 15, "ice", "ice_cleaver.c", "cleaver");
    move_object(angel, this_object()); 
  }
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"   This rooms appears to be an old practice room.  Burned and torn\n"+
"practice dummies are spread throughout the dark room.  Ashes and\n"+
"partial remains of mats can be found covering the floor.  The walls\n"+
"and ceiling here are surprisingly intact.  Archways leading to other\n"+
"rooms can be found to the north and west.\n";

items = ({
  "dummies",
  "Once used for practice with wooden weapons, they are\n"+
  "now useless moldy burnt bags",
  "dummy",
  "A wobbly looking dummy that looks like it has been pushed\n"+
  "too many times",
  "mats",
  "You barely recognize them as such, but a single corner of\n"+
  "one reveals it to be a once heavily used practice mat",
  "floor",
  "It is covered in ash and thick soot",
  "walls",
  "The walls here are blackened from the fire, but surprisingly"+
  "untouched. Proof the fire was concentrated into areas",
  "ceiling",
  "The ceiling here is only slightly blackened as if small fires"+
  "had burned briefly and yet savagely beneath it",
  "remains",
  "You look carefully and see that they are what is left of\n"+
  "several old practice mats. They are torn and burned almost\n"+
  "beyond recognition",
  "ash",
  "Proof that some horrible fire raged throughout this room",
  "soot",
  "Proof that some horrible fire raged throughout this room"
  
});

dest_dir = ({
  RMS+"r06.c","north",
  RMS+"r05.c","west",
});

}

query_ruinsroom() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ruinsroom() && this_player()->query_level() < 40) return HIW+RUINS+NORM; 
      else { 
        sh = HIW+short_desc+" ["+NORM;
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += HIW+"]";
        return sh+NORM; 
      }
    }
    else return HIW+RUINS+NORM;   
  }
  else return "Dark room";     
}

init(){
  ::init();
  if(this_player())
    if(present("clan_symbio", this_player())){
      write(HIR+"\n\n\nAs a member of the clan, you may 'push dummy' here.\n\n\n"+NORM);
          add_action("backroom", "push");
    }
}

backroom(string str) {
  if(!present("clan_symbio", this_player())) return;
  if(this_player()->query_attack()) return 0;
  if(!str){ write("Push what?\n"); return 1; }
  if(str == "dummy") {
    move_object(this_player(), "/players/forbin/realms/ruins/RMS/backroom2");
    tell_object(this_player(), "You enter the secret lair of Clan Incognito.\n");
    command("look", this_player());
    return 1;
  }
  write("Push what?\n");
  return 1;
}

