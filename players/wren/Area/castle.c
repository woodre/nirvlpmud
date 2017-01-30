#define NAME "Wren"
#define DEST "room/farmroad1"
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

id(str) { return str == "castle"|| str =="megalith"; }

short() { return "Megalith"; }

long() {
    write("Ancient stones ring a clearing. Moss and lichen \n"+
          "cling to the weathered surfaces. The forest stretches\n"+
          "off into the distance but hasn't encroached on this \n"+
          "location. The local farmers have also kept their farms \n"+
          "and fields a respectable distance away as well. \n");
       }

init() {
    add_action("enter","enter");
    add_action("search_room","search");
    add_action("touch","touch");
       }

enter(str) {
    if (!str) {write ("Enter what?\n"); return 1;} 
        
    if (!id(str))
	return 0;
            
      write("Ancient Runes suddenly flare to life. Motes of energy \n"+
            "swirl forth and encompass the area in a blaze of light.\n");
      this_player()->move_player("into the megalith#players/wren/Area/entrance.c");
      
      tell_object(this_player(),"The magic swirls away leaving you in a new location.\n");
      tell_object(this_player(),"You here Wren laughing. 'Hah, got you now!'.\n");
      return 1;
           }

search_room()  {
    write("Searching around the stones you discover some runes.\n");
    write("You are curious what would happen if you were to touch them.\n");
    say (this_player()->query_name() +" searches the area. \n");
    return 1;
               }

touch()  {
    if(!str) {write("Touch what?\n");return 1;}
    if(str=="runes") {
    write("Your fingers brush across the flowing script as you clear the lichen.\n"+
          "As you clear the covering it appears to be some elvish character.\n"+
          "Crackles of mana pop between your hand and the stones. There is vast\n"+
          "magical potential in this ancient construct. \n");
        return 1;
         }

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
