#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {   
   if(!present("eric", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/amber/eric.c"),
      this_object());
    }
  }
     
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"Citadel of Amber"+NORM;
   long_desc =
   "	You enter the Citadel of Amber.  You feast your eyes\n"+
   "on the Pattern.  It is hard to use the Pattern, unless you\n"+
   "have the blood of an Amber decendent.  Maybe you can 'walk'\n"+
   "it and run into a few Amberities.  The new Lord has taken\
   "the throne he stands before you.  You can go back 'out' be\n"+
   "he spots you.\n"; 
     	
       items = ({
         "pattern","A pattern made of a firey maze, maybe you can\n"+
         "'walk" it.",
         "Lord","Lord Eric eyes you.\",         
         });

   dest_dir = ({
         "players/brittany/amber/shadows11.c","out",
          });
   }
  
init() {
   ::init();
   add_action("out","out");
   add_action("search","search");
   add_action("walk_pattern","walk");
   }

out(str){
  tp->move_player("out#/players/brittany/amber/shadows11.c");
  return 1; }
   
walk_pattern(str){
if(!str || str != "pattern") {
        notify_fail("Where do you want to walk?\n");
        return 0; }
 
write("You  W A L K  onto the pattern, the fire blazes around you.\n");
   say(tpn+"  W A L K S  onto the pattern, the fire blazes.\n");
tp->move_player("walk#/players/brittany/amber/Veil1.c");
return 1; }
   
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}


