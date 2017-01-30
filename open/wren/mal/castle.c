#define NAME "Wren"
#define DEST "room/farmroad1"
#include "/players/wren/ansi.h"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */


id(str) { return str == "castle" || str =="megalith"|| str== "stones" || 
                 str == "crops" || str == "road"; 
        }

short() { return "Megalith"; }


long(str) { if(str=="megalith"){
              write("Ancient stones ring a clearing. Moss and lichen \n"+
                    "cling to the weathered surfaces. The forest stretches\n"+
                    "off into the distance but hasn't encroached on this \n"+
                    "location. The local farmers have also kept their farms \n"+
                    "and fields a respectable distance away as well. \n");
                    return 1;
                               } 
       else if(str=="stones"){
              write("Grass and wild flowers have grown thick around\n"+
                    "the base but no trees have taken root within\n"+
                    "the circle. These stones have stood for thousands \n"+
                    "of years and continue to bewilder people as to \n"+
                    "how these giant marble blocks were moved onto\n"+
                    "this hill and what there purpose is. Perhaps \n"+
                    "with some searching you can uncover its use. \n"); 
                    return 1;         
                       }
       else if(str=="road"){
               write("The road is heavily worn from the ox carts that carry\n"+
                     "the produce from the fields to the village proper.\n"+
                     "Still it is level and is the most direct route.\n");
                     return 1;
                           }
       else if(str=="crops"){
               write("Fields of barley, wheat, hops, and straw. To feed the \n"+
                     "villagers, to thatch the eaves, and help us all get \n"+
                     "roaring drunk. Gods bless the noble farmers.  \n");
                     return 1;
                            }
       else { write("Look at what?\n"); return 1; }
        }

init() {
    add_action("enter","enter");
    add_action("search_room","search");
    add_action("touch","touch");
       }

enter(str) {
    if (!str) {write ("Enter what?\n"); return 1;} 
        
    if (str != "megalith") return 0;
            
      write("Ancient Runes suddenly flare to life. Motes of energy \n"+
            "swirl forth and encompass the area in a blaze of light.\n");
      this_player()->move_player("into the megalith#players/wren/Area/entrance.c");
      
      tell_object(this_player(),"The magic swirls away leaving you in a new location.\n");
      tell_object(this_player(),"You hear Wren laughing. 'Hah, got you now!'.\n");
      return 1;
           }

search_room()  {
    write("Searching around the stones you discover some runes.\n");
    write("You are curious what would happen if you were to touch them.\n");
    say (this_player()->query_name() +" searches the area. \n");
    return 1;
               }

touch(str)  {
    if(!str) {write("Touch what?\n");return 1;}
    if((str)=="runes") { 
    write("Your fingers brush across the flowing script as you clear the lichen. \n"+
          "As you clear the covering it appears to be some elvish character.     \n"+
          "Crackles of mana pop between your hand and the stones. There is vast  \n"+
          "magical potential in this ancient construct. You get a feeling...     \n"+
          "  \n"+
      GRN+" #########  #########     #########    #########   #########    \n"+                  
          "   #   #      #   #         #   #        #   #       #   #      \n"+
          "   #   #      #   #"+NORM+"  <<enter megalith>>"+GRN+"  #   #       #   #      \n"+
          "   #   #      #   #         #   #        #   #       #   #      \n"+
          "   #   #      #   #         #   #        #   #       #   #      \n"+
          "-----------------------------------------------------------"+NORM+"     \n");
        return 1;
         }
       }

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
