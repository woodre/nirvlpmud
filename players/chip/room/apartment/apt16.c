/*                                                                    
 *    File: /players/chip/room/apartment/apt16.c                
 *    Function: room
 *    Author(s): Chip@Nirvana       
 *    Copyright: Copyright (c) 2008 Chip      
 *               All Rights Reserved   
 *    Source: 5/31/08           
 *    Notes:                                                          
 *    Loads as a dark room with no exits....                                                                
 *                                                                    
 *    Change History:                                                 
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("veteran", this_object()) )
    move_object(clone_object("/players/chip/mobs/apartment/vtnmvet1.c"),  this_object());
  if(arg) return;
  set_light(1);
  short_desc = ""+HIW+"A second floor apartment"+NORM+"";
  long_desc =
    "There is absolutely nothing in this apartment. Only the usual terrible stench of\n"+
    "all the other apartments. There is, however, mold and mildew growing everywhere.\n"+
    "Also, there are stains on the floor that are likely urine, judging by the smell.\n";
    
  add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
  add_smell("urine", "The scent is strong and makes it difficult to breathe properly");
  
  items =
  ({
    "walls",
    "They are all covered in mold and mildew",
    "floor",
    "Urine stains seem to dominate the carpeting",
    "ceiling",
    "It is very moldy and some of it is hanging loosely, ready to fall as the rest of it already has",
    "dirt",
    "It is everywhere",
    "dust",
    "It covers almost everything",
    "mold",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "mildew",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "stains",
    "When you gotta go.....you gotta go",
    });

  dest_dir =
  ({
    "/players/chip/room/apartment/f2h4.c",     "hall",
  });
}