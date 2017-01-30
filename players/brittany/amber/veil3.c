#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {   
   if(!present("gerard", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/amber/gerard.c"),
      this_object());
    }
  }
   
   if(arg) return;
   set_light(1);
   
   long_desc =
   "	You land onto the Three Veil.  A familiar pink sand\n"+
   "desert is all around you...but nearby, maybe a half a\n"+
   "kilometer away, you recognize the Third Veil.  The Blood\n"+
   "Red Sun shines down on the scene.  The only way 'out'\n"+
   "to the next veil or 'back' off the pattern.\n";
       
     	
       items = ({
         "pattern","A pattern made of a firey maze, maybe you can\n"+
         "'walk" it.",
         "citadel","The Citadel of Amber, the nine princes of Amber\n"+
         "reside here, you might find them in the pattern",
         });

   dest_dir = ({
         "players/brittany/amber/veil4.c","out",
         "players/brittany/amber/amber.c","back",
          });
   }
  
init() {
   ::init();
   add_action("out","out");
   add_action("back","back");
   add_action("search","search");
   }

back(str){
  tp->move_player("back#/players/brittany/amber/amber.c");
  return 1; }
  
out(str){
  tp->move_player("out#/players/brittany/amber/veil4.c");
  return 1; }   
   
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}


