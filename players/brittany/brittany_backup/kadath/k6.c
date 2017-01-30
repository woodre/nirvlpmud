#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int KEY;  /*  set a variable to keep track of keys  */

reset(arg) {
   if(!present("priest")) {
    move_object(clone_object("/players/brittany/kadath/NPC/nasht.c"),this_object());
   }
   if(arg) return;
   set_light(1);
KEY = 1;  /*  Start out with 1 key  */
   
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
   "     The cavern opens up into a huge room with a high ceiling.\n"+
   "The walls are made of brimstone and fireshadows blaze across it.\n"+
   "There are rows of pews on each side of a long aisle that leads up\n"+
   "to a high altar.  On the altar sits a small podium.\n";
   
   items = ({
         "walls","The walls are made of brimstone and fireshadows blaze across it",
         "ceiling","The ceiling is cut high into the cavern walls",
         "high ceiling","The ceiling is cut high into the cavern walls",
         "cavern","The cavern opens up into a huge room with a high ceiling",
         "room","A huge room in the cavern walls, with a high ceiling",
         "huge room","A huge room in the cavern walls, with a high ceiling",
         "high altar","An elevated structure, with a small podium sitting on it",
         "aisle","A long narrow aisle",
         "pews","Benches with high backs made of stone",
         
         "altar","An elevated structure, with a small podium sitting on it",
         "fireshadows","Shadows of fire blazing across the walls",
         "podium","A small podium sits on the high altar, it would be a good place to\n"+
         "hide something",
         "small podium","A small podium sits on the high altar, it would be a good place to\n"+
         "hide something",
          });
   
   dest_dir = ({
         "/players/brittany/kadath/k5.c","west",
          });
   
}

init() {
  ::init();
   add_action("search","search");
}

search(str) {
   if(present("priest",this_object())) {
      write("The priest pats you on the shoulder and shakes his head.\n");
      return 1; }

/* Check added by Feldegast 10-24-00 */
   if(!str) str = "room";
   if(!str || str != "podium") {
      notify_fail("You search the "+str+" and find nothing of interest.\n");
      return 0;
   }
   
   
    if(str == "podium" && KEY == 1) {
      write("A shiny key is retrieved from the podium\n");
     move_object(clone_object("/players/brittany/kadath/OBJ/temple_key.c"),this_player());
      KEY = 0;  /* set the variable to reflect 0 keys  */
      return 1; }
    else {
      write("You search the podium and find nothing.\n");
      return 1; }
}
