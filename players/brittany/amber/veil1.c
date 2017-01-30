#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {   
   if(!present("random", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/amber/random.c"),
      this_object());
    }
  }
     
   if(arg) return;
   set_light(1);
    
   short_desc = BLU+"Pattern"+NORM;
   long_desc =
   "	You stand on the Pattern, and indeed it seems sometimes\n"+
   "that you can't even make progress with it...but eventually\n"+
   "you make it through to the First Veil.  You enter the area of\n"+
   "of the Second Veil.  The only way 'out is to the next veil or\n"+
   "'back' off the pattern.\n";
   
     	
       items = ({
         "pattern","A pattern made of a firey maze, maybe you can\n"+
         "'walk" it.",
         "citadel","The Citadel of Amber, the nine princes of Amber\n"+
         "reside here, you might find them in the pattern",
         });

   dest_dir = ({
         "players/brittany/amber/veil2.c","out",
         "players/brittany/amber/amber.c","back",
          });
   }
  
init() {
   ::init();
   add_action("out","out");
   add_action("search","search");
   add_action("walk_pattern","walk");
   }

out(str){
  tp->move_player("out#/players/brittany/amber/veil2.c");
  return 1; }
  
back(str){
  tp->move_player("out#/players/brittany/amber/amber.c");
  return 1; }  
   
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}


