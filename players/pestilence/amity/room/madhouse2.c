/* Help provided by The Great Jaraxleio */
#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";
int SEARCH;

reset(arg) {
SEARCH = 0;
  if(arg) return;

short_desc = ""+BLU+"Abandoned House"+NORM+"";
long_desc =
  "    This is the front room of an abandonded house.  All the other\n"+
  "rooms appear to be boarded up.  This room has a hardwood floor.  The\n"+
  "walls are brown from all the dirt and smoking that took place in here.\n"+
  "There is a pile of cloth in the corner.\n";
set_light(1);

items = ({
"cloth","This is a pile of cloth, maybe you could search it",
"pile","This is a pile of cloth, maybe you could search it",
"rooms","The doorways to the other rooms appear to be boarded up",
"floor","A hardwood floor",
"walls","White walls covered with dirt, making their appearance to be brown",
"dirt","There is alot of brown dirt covering the walls",
"house","It is abandoned and boarded up",
"corner","A pile of cloth is in the corner",
});

dest_dir = ({
  "/players/pestilence/amity/room/madison1.c","north",
});
}

init() {
  ::init();
  add_action("search","search");
  add_action("jump_down","jump");  
}

search(arg){          
  if(SEARCH == 1){ write("The cloth has already been searched and moved.\n"); return 1; }
  if(arg == "cloth"){
    write("You search through the cloth, exposing a hole in the floor.\n"+
          "Maybe you could 'jump down' the hole.\n");        
SEARCH +=1;return 1; }
    write("Search what?\n");
return 1; }

jump_down(arg){
  if(SEARCH == 0){ write("Jump where?\n"); return 1; }

  if(arg == "down"  || arg == "down hole"  || arg == "hole"){
    write("You jump down into the basement.\n");
    say(TPN+" disappears into the floor!\n");
 move_object(this_player(), "/players/pestilence/amity/room/mad2base.c");  
  command("look",this_player());
return 1; }
    write("Jump where?\n");
return 1; }
