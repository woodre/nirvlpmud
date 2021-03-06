inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define MON "/players/jareel/monsters/chaos/caves/trolls/"

int monsters;

reset(arg) 
{
    if(arg) return;

    short_desc=(HIK+"Troll Cavern"+NORM);
    long_desc=

    ""+HIK+"@"+NORM+BOLD+"X"+NORM+"--"+HIK+"@"+NORM+"     The cavern walls are coated in a slimy mucus moss.  Loose	\n"+
    ""+HIK+"@"+NORM+"|"+HIK+"@"+NORM+"|"+HIK+"@"+NORM+"     rocks hang from the rough textured wall.  The palpable\n"+
    ""+HIK+"@"+NORM+"|R|-     darkness envelopes the air in the room.  The moss can be\n"+
    "-|"+HIK+"@"+NORM+"|"+HIK+"@"+NORM+"     found in every crack and crevice in the walls.  The pass-\n"+
    ""+HIK+"@@@"+NORM+"|"+HIK+"@"+NORM+"     age leads west and north here.\n";

    items = ({
         "cavern","The walls of the cavern are covered with a slimy mucus",
         "wall,walls","The wall has a thin mucus film coating it",
         "mucus","The substance drips down the wall, off the moss as you look at it",
         "moss","A basic form of plant life that coats a lot of the wall",
         "rocks","Chips of stone can be found in the caverns corners",
         "chips","Pieces of the cavern walls litter the floor",
         "light","A light illuminates the room to the south",
         "east","the cavern leads off that way",
         "south","It appears to be a room illuminated by some light source",
         "flower","Several small purple flower blossom in the moss",
         "blossom","The flower looks very delecate",
    });

    dest_dir = ({
     
         "/players/jareel/areas/chaos/cave/grid4/room3.c","north",
         "/players/jareel/areas/chaos/cave/grid5/hall4.c","south",
         "/players/jareel/areas/chaos/cave/grid5/hall2.c","east",
     
     
    });

    /* this was missing */
    get_monsters();
}

get_monsters()
{
    int i;
    i = random(100);
    monsters = 1;

    tell_object(find_player("jareel"), "I value is :" + i + "\n");

    switch(i)
    {
    case 0..5:
        tell_object(find_player("jareel"), "switch value 0..5 happened.\n");
        getmonsters_00to05();
    break;


    case 6..20:
        tell_object(find_player("jareel"), "switch value 6..20 happened.\n");
        getmonsters_06to20();
    break;


    case 21..75: 
        tell_object(find_player("jareel"), "switch value 21..75 happened.\n");
        getmonsters_21to75();
    break;

    
    case 76..90: 
        tell_object(find_player("jareel"), "switch value 76.090 happened.\n");
    break;

    
    default:
        tell_object(find_player("jareel"), "switch value default happened.\n");
        getmonsters_default();
    break; 
    }
}

getmonsters_00to05()
{
    move_object(clone_object(MON+"troll.c"),this_object());

    if(random(2) == 1) move_object(clone_object(MON+"troll.c"),this_object());
}

getmonsters_06to20()
{
   move_object(clone_object(MON+"troll.c"),this_object());
    if(random(5) == 1)
    {
        move_object(clone_object(MON+"troll.c"),this_object());
        if(random(3) == 1)
            move_object(clone_object(MON+"troll.c"),this_object());
    }
}

getmonsters_21to75()
{
    if(1 == random(3))
        move_object(clone_object(MON+"troll.c"),this_object());
    if(1 == random(5))
        move_object(clone_object(MON+"troll.c"),this_object());
    if(1 == random(4))
        move_object(clone_object(MON+"troll.c"),this_object());
    if(1 == random(4))
        move_object(clone_object(MON+"troll.c"),this_object());
    if(1 == random(6))
        move_object(clone_object(MON+"troll.c"),this_object());

    if(1 == random(5))
    {
        move_object(clone_object(MON+"troll.c"),this_object());
        if(random(3)==1)
            move_object(clone_object(MON+"troll.c"),this_object());
    }
}

getmonsters_default()
{
    if(random(50)==1)  move_object(clone_object(MON+"troll.c"),this_object());
    if(random(20)==1)  move_object(clone_object(MON+"troll.c"),this_object());
    if(random(17)==1){  move_object(clone_object(MON+"troll.c"),this_object());
    if(random(2)==1) move_object(clone_object(MON+"troll.c"),this_object()); }
    if(random(15)==1)  move_object(clone_object(MON+"troll.c"),this_object());
    if(random(10)==1)  move_object(clone_object(MON+"troll.c"),this_object());
    if(random(7)==1)  move_object(clone_object(MON+"troll.c"),this_object());
    if(random(5)==1)  move_object(clone_object(MON+"troll.c"),this_object());
    if(random(5)==1)  move_object(clone_object(MON+"troll.c"),this_object());
    if(random(3)==1)  move_object(clone_object(MON+"troll.c"),this_object());
}

init() 
{
   ::init();
   add_action("Search","search");
}

Search(str) 
{
   
   if(!str) { write("Search what?\n"); return 1; }
   write("You search the "+str+" but find nothing special.\n");
   say(this_player()->query_name()+" searches around for something.\n");
   return 1;
}


