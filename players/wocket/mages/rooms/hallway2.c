#include "../defs.h"
#define PATH "/players/feldegast/guild/rooms/"
inherit ROOM;

reset(arg){
 if(arg) return;

  short_desc = MAG+"A Secret Hall"+NORM;
  long_desc = "   "+
              "The walls of this hallway are made up of ancient sandstone\n"+
              "blocks.  Doors line the walls each leading into a different\n"+
              "mage's study.  Torches stand next to the doors lighting the\n"+
              "passageway.  Back to the south the green light of the guildhall\n"+
              "can be made out.\n";
  set_light(1);
  items = ({
    "blocks","They are made out of ancient sandstone and are very smooth to the touch",
    "walls","Made out of sandstone blocks, they support many torches and doorways",
    "doors","Each one made of thick oak, they line the walls giving passageway to studies",
    "torches","Wooden sticks resting in cast iron rings, they light the hallway",
    "light","The light of the torches mingles with the light of the guildhall",
  });
  listens = ({
    "You hear soft chanting in the background",
  });
  smells = ({
    "default","You smell dust and age",
  });
  dest_dir = ({
    PATH+"tower5.c","south",
    "blah","study",
  });
}

init(){
  ::init();
  add_action("enter","study");
  this_player()->set_fight_area();
}

enter(){
  object home;
  if(!present("mageguildob",this_player())){
    write("What?\n");
    return 1;
  }
  say(this_player()->query_name()+" enters "+this_player()->query_possessive()+" study.\n");
  write("You enter your study.\n");
  if(present("mageguildob",this_player())->query_guildroom())
    home = present("mageguildob",this_player())->query_guildroom();
  else{
    home = clone_object("/players/wocket/mages/rooms/study.c");
    home->set_owner(this_player()->query_real_name());
    present("mageguildob",this_player())->set_guildroom(home);
  }
  move_object(this_player(),home);
  command("look",this_player());
  return 1;
}  

exit(){
  this_player()->clear_fight_area();
  return 1;
}

realm(){ return "NT"; }
GUILD_PK(){ return 1; }
