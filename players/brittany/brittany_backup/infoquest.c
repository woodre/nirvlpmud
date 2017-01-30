#define NAME "Zeus"
#define DEST "room/giant_path"
#include "/players/zeus/closed/all.h"


id(str) { return str == "path"; }

short() {  return "A path to the north and south";  }

long(){
	write(
"This dirt path leads north into a cluster of maple trees.\n"+
"This path leads north and south into the realms of Zeus.\n"+
"          Established [5.9.1999]\n");
return 1; }

  void init(){
	  add_action("north_dir", "north");
      add_action("south_dir", "south");
}

status north_dir(){
  if(this_player()->is_npc()) return 1;
  this_player()->move_player("north#/players/zeus/realm/entrance.c");
  if(find_player("zeus") && (string)this_player()->query_real_name() != "zeus")
  {
   tell_object(find_player("zeus"), HIG+
     capitalize((string)this_player()->query_real_name())+
     " just entered the castle north.\n"+NORM);
  }
  return 1; 
}

status south_dir(){
  if(this_player()->is_npc()) return 1;
  this_player()->move_player("south#/players/zeus/dealer/room.c");
  if(find_player("zeus") && (string)this_player()->query_real_name() != "zeus")
  {
    tell_object(find_player("zeus"), HIG+
      capitalize((string)this_player()->query_real_name())+
      " just entered the castle south.\n"+NORM);
  }
  return 1; 
}


reset(arg){
  object qob;
  if(arg)
    return;

  move_object(this_object(), DEST);

    /*   ---= Autoloads =---  */
  clone_object("/players/zeus/circle/circle.c");
  clone_object("/players/zeus/museum/OBJ/poison.c");
  clone_object("/players/zeus/desert/OBJ/scorpion_poison.c");

    /*   ---= Quest =--- */

  if(!present("fallen_lands",find_object("room/quest_room.c")))
  {
    qob = clone_object("obj/quest_obj");
    qob->set_name("fallen_lands");
    qob->set_hint(
      "\nSeek out the monk Tyborlek.  Ask him to tell you the story\n"+
      "of the Fallen Lands, and ask what you can do to help.\n");
    move_object(qob,"room/quest_room");
  }
}


is_castle(){    return 1;    }
