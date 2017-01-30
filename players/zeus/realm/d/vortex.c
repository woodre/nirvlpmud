/***************************************************/
/* When the player enters the portal, it moves 7 demons
/* to the 7 locations, 3 of which will get a piece of
/* the talisman.  May only happen once a boot.
/* 8-12 more medium sized demons will be made as well.
/***************************************************/

#include <ansi.h>
inherit "room/room";	/*  vortex.c  */
int teleport, go,x;
object *demons1, *demons2, *demons3;
string *rooms;

reset(arg){

 teleport = 0;  if(random(2)) teleport = 1;

	if(arg) return;

 go = 1;
 set_no_clean(1);
 short_desc="Beneath the tower";
 long_desc=
"This is a small room beneath the tower.  All of the walls are made\n"+
"of soft white stones, however many of them are broken or crooked.\n"+
"In the center of the room is a spherical red vortex of shimmering\n"+
"light.  The only way out is to the south.\n";
 set_light(1);
 items=({
  "walls",
"All four walls of the room are made of pale white stones, many of\n"+
"which are broken and crooked",
  "stones",
"The room is made of pale stones, all of which look very old.  Most\n"+
"of them are cracked and broken.  The floor is very uneven",
  "floor",
"The floor is very uneven because of the cooked and broken stones",
  "vortex",
"In the center of the room is a glowing red vortex of light.  It is\n"+
"slowly pulsing as it swirls and shimmers.  A forboding aura seems\n"+
"to linger around the vortex.  You could enter it",
  "light",
"The only light in the room is coming from the red vortex.  It is\n"+
"shimmering softly, casting strange shadows on the walls of the room",
 });
 dest_dir=({
	  "/players/zeus/realm/d/ent1.c", "south",
 });
}

void init(){ 
	::init(); 
	add_action("enter_cmd", "enter");
}

exit(){ if(this_player()) this_player()->clear_fight_area(); }
realm(){ if(teleport) return "NT"; }
okay_follow() { return 1; }

set_go(x){ go = x; }
query_go(){ return go; }


enter_cmd(str)
{
  object demon, r, oops;
  if(str != "vortex") return 0;
  write("You step into the vortex...\n\n\n"+
	  RED+"\t\tBurning flames consume you...\n\n\n"+NORM);
  this_player()->hit_player(25);
  if(go)
  {
    demons1 = allocate(7);
/*    demons2 = allocate(4+random(4)); */
    demons3 = allocate(8+random(5));
    rooms = allocate(31);
    for(x=0; x<sizeof(demons1); x++)
    {
      demons1[x] = 
        clone_object("/players/zeus/realm/NPC/demon_planar.c");
    }
/*    for(x=0; x<sizeof(demons2); x++)
    {
      demons2[x] = 
        clone_object("/players/zeus/realm/NPC/demon_planar.c");
    }
*/    for(x=0; x<sizeof(demons3); x++)
    {
      demons3[x] = 
        clone_object("/players/zeus/realm/NPC/demon_medium.c");
    }
    for(x=1; x<sizeof(rooms); x++)
    {
      rooms[x-1] = "/players/zeus/realm/d/r"+x;
    }
    for(x = 1; x < sizeof(demons1)+1; x++)
    {
      move_object(demons1[x-1], "/players/zeus/realm/d/p"+x);
    }
    x = 0;
    do
    {
      r = demons1[random(sizeof(demons1))];
      if(!r->query_spirit())
      {
        r->set_spirit(1);
        x++;
      }
    } while(x < 3);
/*    x = 0;
    do
    {
      oops = rooms[random(sizeof(rooms))];
      if(!present("planar demon"), oops)
      {
        move_object(demons2[x], oops);
        x++;
      }
    } while(x < sizeof(demons2));
*/    x = 0;
    do
    {
      oops = rooms[random(sizeof(rooms))];
      if(!present("planar demon"), oops)
      {
        move_object(demons3[x], oops);
        x++;
      }
    } while(x < sizeof(demons3));
    go = 0;
  }
  this_player()->move_player(
    "into the red vortex#players/zeus/realm/d/ent.c");
  return 1;
}
