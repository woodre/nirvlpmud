inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define MON "/players/jareel/monsters/chaos/caves/trolls/"

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
	""+HIK+"@@@@@"+NORM+LINE8+"     \n"+
	""+HIK+"@"+NORM+"-"+HIK+"@@@"+NORM+LINE9+"     \n"+
	""+HIK+"@"+NORM+"|"+HIK+"@"+NORM+"R"+HIK+"@"+NORM+LINE10+"     \n"+
	""+HIK+"@"+NORM+"|"+HIK+"@"+NORM+"-"+BOLD+"X"+NORM+LINE11+"     \n"+
	""+HIK+"@"+NORM+"-R-"+HIK+"@"+NORM+LINE12+"\n"+
		"     "+LINE13+"\n"+
	"     "+LINE14+"\n";
	
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
			"blossom","The flower looks very delicate",
	});
	
	dest_dir = ({
			
			"/players/jareel/areas/chaos/cave/grid7/hall4.c","west",
			"/players/jareel/areas/chaos/cave/grid4/hall5.c","east",
			
			
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
        tell_object(find_player("jareel"), "switch value 76..090 happened.\n");
    break;

    
    default:
        tell_object(find_player("jareel"), "switch value default happened.\n");
        getmonsters_default();
    break; 
    }
}

getmonsters_00to05()
{
    move_object(clone_object(MON+"greattroll.c"),this_object());

    if(random(2) == 1) move_object(clone_object(MON+"trollkin.c"),this_object());
}

getmonsters_06to20()
{
   move_object(clone_object(MON+"darktroll.c"),this_object());
    if(random(5) == 1)
    {
        move_object(clone_object(MON+"troll1.c"),this_object());
        if(random(3) == 1)
            move_object(clone_object(MON+"troll2.c"),this_object());
    }
}

getmonsters_21to75()
{
    if(1 == random(3))
        move_object(clone_object(MON+"trollkin.c"),this_object());
    if(1 == random(5))
        move_object(clone_object(MON+"zorakzoronlord.c"),this_object());
    if(1 == random(4))
        move_object(clone_object(MON+"kygorlitorlord.c"),this_object());
    if(1 == random(4))
        move_object(clone_object(MON+"trollshamon.c"),this_object());
    if(1 == random(6))
        move_object(clone_object(MON+"scarab.c"),this_object());

    if(1 == random(5))
    {
        move_object(clone_object(MON+"troll1.c"),this_object());
        if(random(3)==1)
            move_object(clone_object(MON+"troll2.c"),this_object());
    }
}

getmonsters_default()
{
    if(random(50)==1)  move_object(clone_object(MON+"greattroll.c"),this_object());
    if(random(20)==1)  move_object(clone_object(MON+"zorakzoronlord.c"),this_object());
    if(random(17)==1){  move_object(clone_object(MON+"troll1.c"),this_object());
    if(random(2)==1) move_object(clone_object(MON+"troll2.c"),this_object()); }
    if(random(15)==1)  move_object(clone_object(MON+"darktroll.c"),this_object());
    if(random(10)==1)  move_object(clone_object(MON+"kygorlitorlord.c"),this_object());
    if(random(7)==1)  move_object(clone_object(MON+"trollshamon.c"),this_object());
    if(random(5)==1)  move_object(clone_object(MON+"troll1.c"),this_object());
    if(random(5)==1)  move_object(clone_object(MON+"troll2.c"),this_object());
    if(random(3)==1)  move_object(clone_object(MON+"trollkin.c"),this_object());
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
