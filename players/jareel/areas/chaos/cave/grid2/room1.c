inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define MON "/players/jareel/monsters/chaos/caves/trolls/"
#define YMON "/players/jareel/monsters/town/"

#define LINE1 "   Miles of long, dark, cold, twisting, wet, dragon breath glass,"
#define LINE2 "   caverned walls entwine in every direction.  The path beneath"
#define LINE3 "   you is not smooth, but rough, uneven molten rock; and there "
#define LINE4 "   are mounds of boulders surrounding you. The only option is "
#define LINE5 "   to climb over, or walk around, these obstacles to navigate this" 
#define LINE6 "   labyrinth. The darkness has thickened into a palpable, prickly "
#define LINE7 "   mist that can blind even the sharpest eye."

#define LINE8 "   Miles of long, dark, cold, twisting, wet, dragon breath glass,"
#define LINE9 "   caverned walls entwine in every direction. The path beneath"
#define LINE10 "   you is not smooth, but rough, uneven molten rock; and there" 
#define LINE11 "   are mounds of boulders surrounding you. The only option is "
#define LINE12 "   to climb over, or walk around, these obstacles to navigate this"
#define LINE13 "   labyrinth.  Green moss has taken root along the base of the "
#define LINE14 "   obsidian glass wall, where a strange, purple flower blossoms."

#define LINE15 "   Deep within the miles of long, dark, cold, twisting, wet, dragon "
#define LINE16 "   breath glass caverns, line of sight is hindered from thick,"
#define LINE17 "   transcendent fog. The air has thinned, making it difficult to breath;" 
#define LINE18 "   lethargy is imminent. Mounds of boulders crowd the path of "
#define LINE19 "   uneven molten rock. Somewhere nearby, a faint, crackling noise" 
#define LINE20 "   can be heard, but it’s hard to distinguish the source. "

#define LINE21 "   Deep within the miles of long, dark, cold, twisting, wet, dragon" 
#define LINE22 "   breath glass caverns, line of sight is hindered from thick, "
#define LINE23 "   transcendent fog. The air has thinned, making it difficult to breath; "
#define LINE24 "   lethargy is imminent. Mounds of boulders crowd the path of "
#define LINE25 "   uneven molten rock. Patches of damp, green moss are sporadic" 
#define LINE26 "   on the caverned walls. Water trickles slowly from above, making" 
#define LINE27 "   small puddles between the cracks in the molten rock beneath you."

#define LINE28 "   Miles within the dark, cold, twisted, wet, dragon breath glass "
#define LINE29 "   caverns you have come to a small, open area clear of debris. "
#define LINE30 "   There are several large cracks in the covert above. There is a" 
#define LINE31 "   series of dusty, stone tablets neatly stacked in the center of the" 
#define LINE32 "   path. A cool breeze wisps through, chilling the air."


#define LINE33 "   Miles within the dark, cold, twisted, wet, dragon breath glass "
#define LINE34 "   caverns you have come to a small, open area clear of debris. "
#define LINE35 "   There are several large cracks in the covert above. The cavern" 
#define LINE36 "   walls are covered with a mysterious vine that has weaved so "
#define LINE37 "   deeply in the cracks that it’s as if it were part of the cavern wall." 
#define LINE38 "   A cool breeze wisps through, chilling the air."

int monsters;

reset(arg) {
   if(arg) return;
          
short_desc=(HIK+"Troll Cavern"+NORM);
  add_property("no_teleport");
  add_property("fight_area");
  set_light(-10);
long_desc=
"\n"+
"|-+|"+HIK+"@"+NORM+LINE1+"  \n"+
"|"+HIK+"@@"+NORM+"|"+HIK+"@"+NORM+LINE2+"  \n"+
"|"+HIK+"@@"+NORM+"|"+HIK+"@"+NORM+LINE3+"   \n"+
"|"+HIK+"@"+NORM+"-|"+HIK+"@"+NORM+LINE4+"   \n"+
"|"+HIK+"@"+NORM+BOLD+"X"+NORM+HIK+"@@"+NORM+LINE5+"  \n"+
"     "+LINE6+"\n"+
"     "+LINE7+"\n";


items = ({
         "cavern","The walls of the cavern are covered with a slimy mucus",
         "wall","The wall has a thin mucus film coating it",
         "mucus","The substance drips down the wall, off the moss as you look at it",
         "moss","A basic form of plant life that coats a lot of the wall",
         "rocks","Chips of stone can be found in the caverns corners",
         "chips","Pieces of the cavern walls litter the floor",
         "light","A light illuminates the room to the south",
         "east","the cavern leads off that way",
         "south","It appears to be a room illuminated by some light source",
         "flower","Several small purple flower blossom in the moss",
         "blossom","The flower looks very delicate",
});

dest_dir = ({
"/players/jareel/areas/chaos/cave/grid2/hall10.c","north",


});

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
    case 0..2:
        tell_object(find_player("jareel"), "switch value 0..2 happened.\n");
        getmonsters_00to02();
    break;


    case 3..14:
        tell_object(find_player("jareel"), "switch value 3..14 happened.\n");
        getmonsters_03to14();
    break;


    case 15..25: 
        tell_object(find_player("jareel"), "switch value 15..25 happened.\n");
        getmonsters_15to25();
    break;

    
    case 26..40: 
        tell_object(find_player("jareel"), "switch value 26..40 happened.\n");
    break;

    
    default:
        tell_object(find_player("jareel"), "switch value default happened.\n");
        getmonsters_default();
    break; 
    }
}

getmonsters_00to02()
{
    move_object(clone_object(MON+"greattroll.c"),this_object());

    if(random(2) == 1) move_object(clone_object(MON+"trollkin.c"),this_object());
}

getmonsters_03to14()
{
   move_object(clone_object(MON+"darktroll.c"),this_object());
    if(random(5) == 1)
    {
        move_object(clone_object(MON+"troll1.c"),this_object());
        if(random(3) == 1)
            move_object(clone_object(MON+"troll2.c"),this_object());
    }
}

getmonsters_15to25()
{
    if(1 == random(3))
        move_object(clone_object(MON+"trollkin.c"),this_object());
    if(1 == random(5))
        move_object(clone_object(YMON+"yelmalian_elite_guard.c"),this_object());
    if(1 == random(4))
        move_object(clone_object(MON+"kygorlitorlord.c"),this_object());
    if(1 == random(4))
        move_object(clone_object(MON+"trollshamon.c"),this_object());
    if(1 == random(6))
        move_object(clone_object(MON+"scarab.c"),this_object());

    if(1 == random(5))
    {
        move_object(clone_object(YMON+"hermit.c"),this_object());
        if(random(3)==1)
            move_object(clone_object(MON+"troll2.c"),this_object());
    }
}

getmonsters_default()
{
    if(random(10)==1)  move_object(clone_object(MON+"greattroll.c"),this_object());
    if(random(10)==1)  move_object(clone_object(MON+"zorakzoronlord.c"),this_object());
    if(random(17)==1){  move_object(clone_object(MON+"troll1.c"),this_object());
    if(random(2)==1) move_object(clone_object(MON+"troll2.c"),this_object()); }
    if(random(8)==1)  move_object(clone_object(MON+"darktroll.c"),this_object());
    if(random(2)==1)  move_object(clone_object(MON+"kygorlitorlord.c"),this_object());
    if(random(2)==1)  move_object(clone_object(MON+"trollshamon.c"),this_object());
    if(random(15)==1)  move_object(clone_object(MON+"troll1.c"),this_object());
    if(random(15)==1)  move_object(clone_object(MON+"troll2.c"),this_object());
    if(random(13)==1)  move_object(clone_object(MON+"trollkin.c"),this_object());
}
 
init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
 
if(!str) { write("Search what?\n"); return 1; }
  write("You search the "+str+" but find nothing special.\n");
  say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}
