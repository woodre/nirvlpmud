/* This is the first room and entrance into the ruins area. A secret way leads to
   room r04.c, which can be found out if you talk to the hunter in that same room
   allowing easier access on later adventures. */
#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = RUINS;
long_desc = 
"  Dark ruins stand looming before you, it's blackened walls crumbled\n"+
"and laying about in scattered piles.  A cobblestone path leads to the\n"+ 
"ruins and disappears through a doorway and into darkness.  Lining the\n"+
"path are numerous black rose bushes and burned out tree stumps. The\n"+
"landscape to the west is glimmering slightly, as if a curtain of energy\n"+
"is before it.\n";

items = ({
  "landscape",
  "You look at the landscape and notice that it is blurred, as if\n"+
  "a field of energy hovers before it", 
  "energy",
  "The same as the curtain of energy that came to life between the\n"+
  "great pillars, this same energy holds the power to bring you\n"+
  "back to the world in which you came. You need only enter it",
  "curtain",
  "The same as the curtain of energy that came to life between the\n"+
  "great pillars, this same energy holds the power to bring you\n"+
  "back to the world in which you came. You need only enter it",  
  "ruins",
  "Dark and foreboding, you aren't quite sure what the building\n"+
  "used to be, but whatever it was, it was torn to pieces and\n"+
  "burned a long time ago",
  "walls",
  "The few that remain standing near the entrance are deeply\n"+
  "scarred and burned. In some places the fire was so intense\n"+
  "as to melt the stones",
  "piles",
  "The last remnants of parts of the walls",
  "path",
  "The path is broken and leads to the ruins entrance, what lays\n"+
  "within is unknown",
  "entrance",
  "You cannot see much beyond the darkness cast by the burned walls",
  "doorway",
  "Not really much of a doorway, it resembles more of a hole torn\n"+
  "into a wall, although you can tell that some type of door frame\n"+
  "used to exist here",
  "darkness",
  "Cast by the shadows of the broken walls. The sky allows little\n"+
  "light to shine through its blackness, giving little relief",
  "bushes",
  "They might have once been beautiful, but now they are as ruined\n"+
  "as the land and building before them",
  "stumps",
  "You look closely at the burned up stumps and see that they are huge. A\n"+
  "past reminder of what they might have been",
});

dest_dir = ({
  RMS+"r02.c","path",
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

init()
{
  ::init();
  add_action("secret_way", "circle");
  add_action("portal_enter", "enter");
}

portal_enter(string str)
{
  if(!str){ write("What?\n"); return 1; }
  if(str == "landscape" || str == "curtain" || str == "energy")
  {
    write("\n\n");  
    write("You walk into the curtain of energy that stands before the landscape...\n\n");
    write("And find yourself elsewhere.\n\n");
    say(TPN+" disappears.\n");
    move_object(TP, "/players/forbin/realms/flame_forest/RMS/ff06_08.c");
    tell_room(environment(TP), TPN+" appears suddenly between the pillars.\n", ({TP}));
    command("look", TP);
      return 1; 
  }
  write("What?\n");
    return 1;
}

secret_way(string str)
{
  if(!str){ write("What?\n"); return 1; }
  if(str == "ruins")
  {
    write("You follow a secret path around the ruins and arrive in safety.\n");
    say(TPN+" leaves.\n");
    move_object(TP, RMS+"r04.c");
    tell_room(environment(TP), TPN+" crawls out of a hole in the wall.\n", ({TP}));
    command("look", TP);
      return 1; 
  }
  write("What?\n");
    return 1;
}
