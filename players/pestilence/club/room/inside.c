#include "/open/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

short_desc = "inside "+HIK+"Pesty's"+NORM+"";
long_desc =
  "    Small tables with chairs fill this area.  There is a bar to\n"+
  "the west and restrooms are to the south.  The lights are very dim,\n"+
  "making it hard to to see the scumbags that frequent this place.\n"+
  "The way out is to the east. To the north is the stage for the\n"+
  "the dancers.\n";
add_property("NT");
add_property("PK");
set_light(1);

items = ({
  "bar","A long bar the stretches from one wall to almost the other",
  "table","A small table with three chairs around it",
  "tables","Small tables with three chairs around each one",
  "chairs","Three chairs sit around each table",
  "restrooms","Two small doors leading to the bathrooms",
  "stage","A large wooden stage to the north",
  "dancers","A few beautiful dancers strutting their stuff on the stage",
  "lights","Regular lights that are very dim",
  "doors","A small sign on the doors reads: 'Out of Service'",
  "door","A small sign on the door reads: 'Out of Service'",
  "scumbags","Some West Virgians with no teeth",
});

dest_dir = ({
"/players/pestilence/club/room/parking.c","east",
"/players/pestilence/club/room/pervert.c","north",
"/players/pestilence/club/room/bar.c","west",
});

}

init() {
  ::init();
add_action("stop","quit");
add_action("enter","enter");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("You can't quit from here.\n");
return 1; }
}
enter(str){
        if(!str){ write("You can only enter the mens or ladies room.\n"); return 1; }
        if(str == "mens"){
        write("You leave into the mens room.\n");
        move_object(this_player(), "/players/pestilence/club/room/mens.c");  
        command("look",this_player());
        return 1;
          }
        if(str == "mens room"){
        write("You leave into the mens room.\n");
        move_object(this_player(), "/players/pestilence/club/room/mens.c");  
        command("look",this_player());
        return 1;
          }        
        else if(str == "ladies"){
        write("You leave into the ladies room.\n");
        move_object(this_player(), "/players/pestilence/club/room/ladies.c");  
        command("look",this_player());
        return 1;
          }
        else if(str == "ladies room"){
        write("You leave into the ladies room.\n");
        move_object(this_player(), "/players/pestilence/club/room/ladies.c");  
        command("look",this_player());
        return 1;
          } 
        else if(!str){
          write("You can only enter the mens or ladies room.\n");
        return 0;
      
}
}
