      /*                                                                    
       *    File: /players/chip/room/apartment/apt4.c                
       *    Function: room
       *    Author(s): Chip@Nirvana       
       *    Copyright: Copyright (c) 2008 Chip      
       *               All Rights Reserved   
       *    Source: 5/31/08           
       *    Notes:                                                          
       *                                                                    
       *                                                                    
       *    Change History:                                                 
       */
#include <ansi.h>
inherit "/room/room";

reset(arg)
{
::reset(arg);

if(arg) return;

set_light(1);

short_desc = ""+HIW+"A first floor apartment"+NORM+"";

long_desc =
    "The apartment here seems to have been a long time hangout for teenagers who have\n"+
    "nowhere else to go to party and such. There are empty blunt tubes, crumpled empty\n"+
    "cigarette packs, empty liqour and beer bottles, and empty rolling paper packs all\n"+
    "over the place. In the center of the room stands a dinner table, with four unsturdy\n"+
    "looking chairs that stand at even ninety-degree increments around it.\n";

  add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
  add_smell("urine", "The scent is strong and makes it difficult to breathe properly");
  add_smell("ashtray", "The smell of burned pot still emanates from it");
  add_smell("roaches", "The smell of burned pot still emanates from them");
  
  items =
  ({
    "tubes",
    "Plenty of them are here, empty. People really do love to smoke handrolled marijuana cigars",
    "bottles",
    "Beer and liqour bottles of all brands and types. They are all empty of course",
    "packs",
    "Do you want to look at the 'rolling paper packs', or the 'cigarette packs'?",
    "rolling paper packs",
    "Cigarette rolling papers of all brands have apparently been used to roll joints here",
    "cigarette packs",
    "Everyone likes different brands! Camel Menthol Wides seem to dominate the others here though",
    "mold",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "mildew",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "table",
    "All that is on this old kitchen table is some empty bottles and an ashtray",
    "ashtray",
    "There are no cigarette butts in it oddly. Plenty of joint and blunt roaches though",
    "chairs",
    "There are four of them placed neatly around the table",
    });

dest_dir =
({
	"/players/chip/room/apartment/f1h1.c",     "hall",
	});

}