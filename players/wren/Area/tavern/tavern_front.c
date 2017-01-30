	/* The Fallen Oak Inn & Tavern*/
	/* Social option for off the green entertainment */

#include "/players/wren/ansi.h"; 
inherit "/players/vertebraker/closed/std/room.c";
int w;

reset(arg)  {   
     if(arg) return; 
 
   set_light(1);
   short_desc = "Tavern green";
   long_desc = 
"A gentle breeze shifts the dark green leaves on this cool evening.  \n\
Pale amber light shines from the windows and from the lantern hanging   \n\
in front of the stout door. In the deepening shadows beyond the lights   \n\
influence the edge of a road can be seen. The telltale hint of rain is  \n\
on the wind. A sign sways and taps against the building with a steady \n\
thumping. Perhaps this place would be a good stop for the night to \n\
escape the approaching summer thunderstorm.   \n";

      items=({		/*Remember two deep on noun descriptions*/
          "leaves","Bright green leaves dance atop the trees in the growing wind",
	  "trees","The forest rises all around the clearing",
          "forest","Old trees that have survived many seasons of harsh weather",
	  "door","A solid hardwood door with metal braces and fasteners carefully painted green",
	  "windows","These frosted glass windows present shadowy movement and lights from within",
	  "light","Amber colored lamp light spills from the windows and from the oil lantern",
	  "lantern","A sturdy glass and iron lantern that lights the way for travelers to find the door at night",
	  "shadows","Patterns of light and dark bounce below the windows hinting at movement inside",
          "road","A small but well travelled trade road which probably connects to a larger trail in the distance",
          "sign","A carefully drawn sign that is obscured in shadows but if you move closer you could probably 'read' it",
          "building","The building looks inviting and would be a good place to escape the storm",
          "storm","Occasional flashes of lightning herald the approach of a summer storm",
          "thunderstorm","Occasional flashes of lightning herald the approach of a summer storm",
          "lightning","Barely noticable in the distance over the forest these occasional flashes brighten the night"
             });

        
      dest_dir = ({
          "/players/wren/Area/entrance.c","north",
          "/players/wren/Area/tavern/tavern_hall.c","west", 
          "/room/vill_green.c","east",
/* 	  "/players/wren/Area/ "," ",
          "/players/wren/Area/ "," "  */
                 }); 
 
set_chance(5);       
add_msg("Lightning flashes slowly in the distance.\n");
add_msg("Muted thunder rolls down the road.\n");
add_msg("Scattered heavy raindrops thud softly into the dry earth.\n");
add_msg("The wind picks up and billows your clothing around you .\n");
add_msg("The sign tap, tap, taps against the side of the inn.\n");

add_listen("main","Revelry can be heard from within and the forest stillness without");
add_listen("door","You hear talking and music on the otherside");
add_listen("thunderstorm","You hear the distant wind and thunder as they cross the mountains");

add_smell("main","You smell several things from the building and the grounds around it");
add_smell("building","The evening meal is being served and you smell roast mutton and fresh bread");
add_smell("grounds","You smell wet animals and straw as well as manure and trail dust");

add_touch("door","The door feels smooth and hard as the iron that binds the planks");

add_exit_msg("west","You stumble through the dark and get lost during the storm.\n",
                    "stumbles off into the dark and stormy night.\n");
}

  init() {
    ::init();
    add_action("search_room","search");
    add_action("read_sign","read");
         }

  search_room()  {
        write("You search but find only horse and boot tracks coming in from the road\n");
        say (this_player()->query_name() +" searches the area. \n");
        return 1;
                 }

  read_sign(str) {
      if(str != "sign") {
        write("Read what?\n");
        return 0;
                       }
      if(str == "sign") {
        write("                                                                  \n");
        write("           @                           @                          \n");
        write("           @                           @                          \n");
        write("           @                           @                          \n");
        write("___________@___________________________@__________                \n");
        write("I"+GRN+"           % %                             "+NORM+"     I \n");
        write("I"+GRN+"         % $ % %  %                        "+NORM+"     I \n");
        write("I"+GRN+"        % % % % %       THE FALLEN         "+NORM+"     I \n");
        write("I"+GRN+"       $  % % $             OAK            "+NORM+"     I \n");
        write("I"+GRN+"       % % % % %  %     TAVERN & INN       "+NORM+"     I \n");
        write("I"+GRN+"      %   $ %   %   %                      "+NORM+"     I \n");
        write("I"+GRN+"        %  % % $  %                        "+NORM+"     I \n");
        write("I"+GRN+"      %  % % $  %% % %                     "+NORM+"     I \n");
        write("I"+GRN+"           &&& &&  $                       "+NORM+"     I \n");
        write("I"+GRN+"           &&&&%                           "+NORM+"     I \n");
        write("I"+GRN+"           &&&                             "+NORM+"     I \n");
        write("I"+GRN+"           &&&          friends,           "+NORM+"     I \n");
        write("I"+GRN+"          &&&&&              always welcome"+NORM+"     I \n");
        write("__________________________________________________                \n");
        write("                                                                  \n");
        write("                                                                  \n");
        say(this_player()->query_name() +" looks at the sign.\n");
        return 1;
                    }
              }   

  	/*In from a story I was working on. It will be a social spot not for combat.     */
	/*The green seems to have been taken over by pkers and other miscreants so       */
	/*People seeking to socialize need a place to go away from the cretons and       */
	/*other sorts of unwelcomes.     */
