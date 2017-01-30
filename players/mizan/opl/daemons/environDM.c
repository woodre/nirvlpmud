/*****************************************************************************
 *      File:                   environDM.c
 *      Function:               Reponsible for the emotes in the realm
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:                 
 *      Change History:         
 ****************************************************************************/
#include "../definitions.h"

string *lava_emotes;
string *forest_emotes;
string *grid_emotes;
string *water_emotes;

get() {
    return 0;
}
short() {
    return "A server named (environ)";
}
id(str) {
    return str == "environ" || str == "server";
}


void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);
    
    if(!arg)
    {
	lava_emotes = ({
	"Sizzling lava boils and bubbles around you.",
	"A loud crackle can be heard, as a once-solid rock explodes underneath the lava.",
	"The bright glow coming from all around you can't be a good thing.",
	"Pop. Crackle. Sizzle. It's not a breakfast cereal... it's rocks melting!",
	"The intensity of heat keeping this lava hot is mind boggling.\nWhere is this energy coming from? You wonder...",
	});

	water_emotes = ({
	"A splash from the water nearby unsettles you somewhat.\nThat was probably one HUGE fish...",
	"The water dampens the noise around you.\nThat means you can't hear THEM, but they can still hear YOU.",
	"The wind ripples to surface of the water with just enough gust to give\nthem a slight wavelike definition. You see things swimming underneath.",
	"Drip. Drip. Splash.\nThat might have been water dropping from the cavern ceiling far above.",
	});

	grid_emotes = ({
	"Looking up, you wonder how high the cavern ceiling is.\nIt feels like about 800 feet or so where you are currently standing.",
	"The wind in the cavern is slight, but it makes an almost sinister howling.\nSomewhere else in the cavern there must be a choke point.",
	"A tiny flash of light goes off in the distance, and you catch a light of it.\nIt's probably a flash from a camera going off somewhere.",
	"Pigeons can be seen flying overhead.\n...or are they... bats?",
	"The wind gusts somewhat, and the cavern howls- reminding you that\nyou're probably several miles underground or so.",
	"Twinking, tiny lights installed in the roof of the cavern appear to be like\nstars at your current vantage point. What they actually do is anyone's guess.",
	"The sound of footsteps coming from nearby puts you on the defensive.",
	"The wind dies down momentarily, and with it, that eerie howling sound.",
	});

	forest_emotes = ({
	"The wind rustles gently between the giant fungal stalks before you.",
	"A 'hooting' noise is heard as the wind is trapped in the canopy overhead",
	"You see the Overpowerlord's blimp adjust its position overhead.\nThe glint of light reflecting off a lens catches your eye,",
	"Through the canopy overhead, the tiny points of light from the cavern roof\nappear like twinkling, glistening stars.",
	"From the corner of your eye, you catch the shape of something flying\nfar overhead. It circles slowly and appears to be watching you.",
	"The wind picks up momentarily, singing through the fungal trunks\nIt sounds eerily otherworldly yet beautiful.",
	"The oddly fragrant fungal stalks remind you of the smell of cinammon.\nIt's a welcome break from the poop smell underfoot.",
	"You swear that you could hear far-off bells and drums here in the fungal forest.",
	"Moving through the fungal forest, you experience an odd sensation of peace.",
	"Giant mushrooms wither and withdraw from your touch as you approach them.",
	"Strange, unknown giant fungus seem to almost sing to each other, you can\nalmost hear it too. It's as if they are alerting each other to your presence.",
	});
    }

    remove_call_out("do_emote");
    call_out("do_emote", 60 + random(60));
}

do_emote()
{
    object ob;
    int i;
    object room;

    ob = users();

    for(i = 0; i < sizeof(ob); i ++)
    {
        room = environment(ob[i]);
        if(room && creator(room) == "mizan")
	{
            if(call_other(room, "is_lava"))
	    {
		tell_object(ob[i], "\n" + lava_emotes[random(sizeof(lava_emotes))] + "\n");
            }
	    else if(call_other(room, "is_water"))
	    {
	        tell_object(ob[i], "\n" + water_emotes[random(sizeof(water_emotes))] + "\n");
	    }
	    else if(call_other(room, "is_forest"))
	    {
		tell_object(ob[i], "\n" + forest_emotes[random(sizeof(forest_emotes))] + "\n");
	    }
	    if(call_other(room, "query_index"))
	    {
		tell_object(ob[i], "\n" + grid_emotes[random(sizeof(grid_emotes))] + "\n");
            }
	}
    }
}
