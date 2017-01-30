/* Based on Feld's arena */
inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"

reset(arg) {
   {
      if(!present("board"))
         {
         move_object(clone_object(BOARDDIR + "/tourneyboard.c"),
            this_object());
}
      if(arg) return;
      set_light(1);
      short_desc="Streets of Netropolis";
      long_desc=
      "     The electronic streets of Netropolis glow with\n"+
      "the streaming lights of optical wires and heated lines\n"+
      "of central processing units.  A stong influence of\n"+
      "warrior blades.  The arena decorated with ancient pride\n"+
      "and suits of armor stands before the columns.\n";
      
      items=({
            "lights", "Flourescent lights that illuminating the area in red",
            "units", "Cybernetic quipment that lines the walls",
            "processing units", "Cybernetic quipment that lines the walls",
            "streets","The streets are made of dark-colored metal",
            "wires","Thick colorful wires lace along the roadside",
            "lines","CPU lines glow red with all the info passing through them",
            "arena", "Those who know the way may enter the arena",
            "arches","Several gigantic arches tower over the streets",
            "blades","The blades are symbols of ninja strength",
            "columns","Several columns hold up the dark ceiling above",
            "armor","These suits of armor serve as fitting decorations",
            "suits","These suits of armor serve as fitting decorations"});
      
      dest_dir=({
ROOMDIR + "/stands.c", "up",
ROOMDIR + "/arena.c", "west",
            ROOMDIR + "/hallway2.c", "east",
});
   }
}

init() {
   ::init();
add_action("up", "u");
add_action("up", "up");
   add_action("west","west");
   add_action("west","w");
   add_action("east","east");
add_action("east","e");
   add_action("quit","quit");
}
west() {
#ifdef __LDMUD__
write("Due to major code-compatibility issues on top of extremely poor\n\
poor code, the arena has been closed until such time as it can be\n\
recoded.  Sorry for the inconvenience - Earwax 12/16/06.\n");
return 1;
#endif
   if(this_player()->query_ghost()) {
      write("Only those that are ready for battle may enter the arena.\n");
      return 1;
}

   
      if(!present("implants",this_player())) {
         write("You must learn the way before entering the arena.\n");
         return 1;
      }

if(TP->query_hp() < TP->query_mhp()){
write("One should be totally ready for battle inside the\n");
write("Cyber Arena.  Come back when you feel you are ready.\n");
return 1;
}
      
      if(present("crotchrot",this_player()) ||
            present("toxin",this_player()) ||
         present("oath",this_player()) ||
         present("nitro",this_player()) ||
         present("poison",this_player())) {
         write("Your CyberNetica hum to life.\n");
         write("You have been dishonored in a large manner for trying\n");
         write("to take unauthorized items into the arena.\n");
         return 1;
      }
      if(this_player()->query_pl_k() < 2) {
         write("You are required to set your sparring flag by typing "+BOLD+"kill_players spar"+OFF+" before entering the arena.\n");
         say(TPN+" is stunned by a laser beam.\n");
         return 1;
      }
   }
   east(str) {
      if(this_player()->query_pl_k() > 1) {
         write("Sparring flag removed.\n");
         this_player()->rm_spar();
        }
   }
up(str) {
if(!present("implants",this_player())) {
write("Only those with honor may travel into the Balcony.\n");
return 1;
}
}
   realm() {
      return "NT";
   }
   query_no_fight() {
      return 1;
   }
   
   query_spar_area() { return 1; }
   quit() {
      write("It would not be very honorable to quit from here.\n");
      return 1;
   }
