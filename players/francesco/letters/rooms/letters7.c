#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return; 

set_light(1);

short_desc = "Letters Department" ;
long_desc =
     "   The library of the Letters Department consists of an ample room\n"+
     "with a high ceiling.  The shelves shin up on the walls to about \n"+
     "twenty five feet.  A sliding ladder can move along the walls to\n"+
     "reach up to the higher shelves.  In the middle of the room, there \n"+
     "are a few tables with several chairs around.  A smaller shelf\n"+
     "supports a touch screen computer.  Next to this shelf there is a \n"+
     "filing cabinet which can be used to search for the books' location.\n"+
     "A suffuse light comes from a chandelier on the ceiling. \n",

items = ({
   "library","The library can supposedly host about fifty people at once",
   "chandelier","It has eight lamps, which send a potent yet relaxing light",
   "ceiling","Of a semi-circular shape, like the old roman arches",
   "chairs","Plain upholstered seats, they look comfortable",
   "shelves","They have transparent windows and are locked",
   "walls","They are behind the shelves, impossible to see",
   "ladder","A metallic ladder, with steep steps and sliding wheels",
   "tables","They are rectangular, made by robust and durable\n"+
            "plastic materials",
   "shelf","A vertical computer holder",
   "books","Oh my!  How many might they be?", 
   "computer", "It has no keyboard, only the screen is accessible and the mouse usable",
   "cabinet","About three feet tall, it has sliding drawers, to store the documents",
   "mouse","An electronic device used to 'click' on the screen",
   "screen","Black and white screen, it can be 'touch'ed to start a program",
   "drawers","They hold some documents. 'Slide' them to see more",
   "steps","The steps of the ladder have an anti-slide plastic stip on them",
   "wheels","The wheels permit to move the ladder along the shelves",
});

dest_dir = ({
  "/players/francesco/letters/rooms/letters5.c","west"
});

}

  init(){
  ::init();
  add_action("touch_puter", "touch");
  add_action("click_box","click");	
  add_action("slide_drawer", "slide");
  add_action("read_subjects","read");
}

touch_puter(str){
  if(!str) { notify_fail("Touch what?\n"); return 0;}
   if(str=="screen") {
   write("You touch the screen of the computer and a dialog box appears.\n"+
         "You might want to 'click' it with the mouse.\n"); 
   return 1;}
   notify_fail("What do you want to touch?\n"); return 0;}

click_box(str){
  if(!str){ notify_fail("Click what?\n"); return 0;}
   if(str == "box"){
   write("You click on the dialog box......\n"+
         "The screen changes.......\n"+
         "A list appears.........\n"+
         "that you can 'read'.....\n");               
  return 1;}
  notify_fail("You cant click it!\n"); return 0;}

slide_drawer(str){
  if(!str) { notify_fail("Slide what?\n"); return 0;}
   if(str=="drawers") {
   write("Only the first drawer of the catalog slides off.....\n"+
         "A long list of subjects appears......\n"+
         "that you can 'read'.......\n"); 
   return 1;}
  notify_fail("What do you want to slide???\n"); return 0;}

read_subjects(str){
  if(!str){ notify_fail("Read what?\n"); return 0;}
   if(str == "list"){
   write("\n  You read the list.......You see also the map of the library....\n"+
         "  The books are held in the shelves along the four walls of the room.\n\n"+
         "   English       Novels      Dramas        Foreign Literature\n"+
         "   Spanish                                 English Literature\n"+
         "   German                                  Art of Writing\n"+
         "   French                                  Journalism\n"+
         "   Italian                                 Sacred history\n"+
         "   Russian                                 History of Art\n"+
         "   Japanese                                Ancient History\n"+
         "   Portuguese    Muds        Essays        Modern History\n\n");               
  return 1;}
   notify_fail("You cant read it!\n"); return 0;}
