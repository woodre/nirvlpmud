/*                                       
 *  File:   /players/mosobp/areas/BATTLE/rooms/b1.c    
 *  Function:  room                      
 *  Author(s):  Mosobp@Nirvana           
 *  Copyright: copyright (c) 2008 Mosobp 
 *             all rights reserved            
 *                                       
 *                                       
 *  Source:  6/17/08                     
 *  Notes:                               
 *                                       
 *                                       
 *  Change History:                      
 */

#include "/sys/lib.h"

#include "/obj/ansi.h"

inherit "room/room";

int x;
reset(arg)
{
  ::reset(arg);
  if( !present("saibaman1", this_object()) )
    call_out("get_saibaman1", 1);
  if( !present("saibaman2", this_object()) )
    call_out("get_saibaman2", 1);
  if(arg) return;
  set_light(1);
  short_desc = GRN+"An open field"+NORM;
  long_desc =
  "  An open area of land with plush green grass\n"+
  "all around. Far off to the east a cliff rises into\n"+
  "the sky. The sky seems to darken as it nears the cliff.\n"+
  "Looking down a rabbit scurries across the grass.\n";
  
  items= 
  ({
    "grass",
    "Plush green grass with flowers occasionally growing in it",
    "cliff",
    "The cliff is off to the east",
    "sky",
    "The sky above is clear and normal, as it reaches the cliff it darkens",
    "rabbit",
    "A furry little rabbit with a fluffy white tail",
  });

  dest_dir =
  ({
    "players/mosobp/areas/BATTLE/rooms/b2.c",  "east",
    "players/mosobp/areas/BATTLE/rooms/b5.c",  "southeast",
    "players/mosobp/areas/BATTLE/rooms/b4.c",  "south",
  });
}

void get_saibaman1(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/mosobp/areas/BATTLE/NPC/saibaman1.c"), this_object());
    }
  tell_room(this_object(), "\n");
}

void get_saibaman2(){
  for(x=0; x<1; x++)
    {
  move_object(clone_object("/players/mosobp/areas/BATTLE/NPC/saibaman2.c"), this_object());
    }
  tell_room(this_object(), "\n");
}