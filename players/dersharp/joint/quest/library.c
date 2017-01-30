inherit "room/room";
#include "ex.h"
int sciences;
reset(arg){
   if(arg) return;
   short_desc="Library";
   long_desc ="  You enter the library from Tilden Street\n"+
              "the music decreases in volume emmensely.  Inside\n"+
              "the library are hundreds of different sorts of books.\n"+
              "You see many encyclopedias and reference books.  You\n"+
              "also note that many of the books have been vandalized\n"+
              "in one way or another.  Only four books seem to be \n"+
              "readable at all.\n";
   set_light(1);
   sciences=0;
   dest_dir=
	({
		Quest+"tildene","north",
	});
   items=
	({
		"books","  Most of the books are in terrible shape.\n"+
                        "however there are four books that can be\n"+
                        "read: geology, trigonometry, a fodor book,\n"+
                        "and greyhawk",
	});
}
init() {
   ::init();
   add_action("Readthem","read");
}

Readthem(arg) {
   if(!arg) {
      write("Which book do you wish to peruse?\n");
      return 1;
   }
   if(arg=="book") {
      write("Which book?\n");
      return 1;
   }
   if(arg=="geology") {
      write("You quietly look through the book on geology.\n");
      write("You find a chapter on different sorts of rocks\n"+
            "and minerals.  The chapter is entitled `minerals'.\n");
      return 1;
   }
   if(arg=="minerals") {
      write("You find an interesting chapter on all sorts of \n"+
            "mierals and rocks.  It tells of diamonds, sulphur,\n"+
            "limestone and other forms of minerals and rocks.  \n"+
            "You could probably read more about each.\n");
      return 1;
   }
   if(arg=="diamond" || arg=="diamonds") {
      write("This section of the chapter tells of diamonds.\n"+
            "It goes on to say that they are formed by great heat\n"+
            "and pressure deep within the ground.  They are the hardest\n"+
            "naturally occuring minerals known to man.  They can grind\n"+
            "up any other mineral easily.\n");
      return 1;
   }
   if(arg=="sulphur") {
      write("This section is a bit damaged by water and vandals.  You\n"+
            "can make out something about it being highly flammable but\n"+
            "that is about it.\n");
      return 1;
   }
   if(arg=="limestone") {
      write("Formed under the ground by the water table limestone is\n"+
            "said to give off hydrogen when crushed.  It is found in \n"+
            "many states of the midwest and opjojfw[fw....The rest of \n"+
            "the page is torn apart.\n");
      return 1;
   }
   if(arg=="trigonometry") {
      if(sciences==0) {
         write("You open the trig book quickly to uncover the secrets\n"+
            "of the world only to find the pages are hollowed out to\n"+
            "make room for a small slide rule.  As you look at it, the\n"+
            "slide rule falls to the floor.\n");
         move_object(clone_object("/players/dersharp/joint/quest/weaps/rule"),tb);
         sciences++;
         return 1;
      }
      if(sciences!=0) {
         write("You open the trig book quickly to uncover the secrets\n"+
            "of the world only to find the pages are hollowed out to\n"+
            "hold something, but there is nothing there now...\n");
         return 1;
      }
   }
   if(arg=="fodor" || arg=="fodor book") {
      write("This is a book describing the sights and people of \n"+
            "a certain country.  The label has been torn out but it\n"+
            "describes it as being a place of great wizards, mighty\n"+
            "adventurers and fun times.  With that knowledge you know\n"+
            "it cannot be Nirvana.\n");
      return 1;
   }
   if(arg=="greyhawk") {
      write("This book outlines a world full of adventure and intrigue.\n"+
            "The lead character must battle beggars to demons to finally\n"+
            "a god itself.  The book tells of a battle to kill a beggar\n"+
            "king and his minions for a master thief....If only there was\n"+
            "a place like Greyhawk in Nirvana you know you could beat him!\n");
      return 1;
   }
   return 1;
}
