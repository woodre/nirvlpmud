#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = HIW+"The Duke Exhibit"+NORM;
long_desc = YEL+
  "   A statuesque figure leans against the mantle above the fireplace in\n"+
  "this early 20th century farmhouse.  He has a stern expression on his\n"+
  "face as he stares out from the exhibit.  There is a plaque on the wall.\n"+
  "A rope surrounds the exhibit.\n"+NORM;

items = ({
  "plaque","A pewter framed plaque.  Perhaps you should read the information written on it",
  "eyepatch","The eyepatch is sitting in a glass case next to the fireplace",
  "hat","The hat looks worn and slightly tattered from use over the years",
  "suitcase","A brown suitcase sits next to John Wayne's feet",
  "photographs","Many pictures of The Duke line the walls",
  "letters","Letters from several of John's friends and peers are framed and hang on the walls",
  "rope","A red velvet rope blocks you from entering the actual model",
});

dest_dir = ( {
    "players/nikki/Museum/Rooms/hall", "right",
});
}  }

realm() { return "NT"; }

init() {
  ::init();
     add_action("lift"); add_verb("lift");
     add_action("read"); add_verb("read");
}
lift(arg) {
  if(arg != "rope") {
     write("Lift what?\n");
     return 1;
  }    
  write("\nblah blah blah blah blah blah blah...\n\n");
  TP->move_player("in a cloud of Mist#players/nikki/Duke/Rooms/room1");
  return 1;
}
read(arg) {
    if(arg != "plaque") {
      write("Read what?\n");
      return 1;
    }
  write(HIW+
   "                        Marion Robert Morrison\n"+
   "                                 AKA\n"+
   "                        Marion Michael Morrison\n"+
   "                         The Duke, John Wayne\n"+
   "                              1907-1979\n"+
   "             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
   "   The life story of John Wayne began in the central Iowa town of Winterset.\n"+
   "He was born Marion Morrison on May 26, 1907, the son of Clyde and Mary Brown\n"+
   "Morrison.\n"+
   "   Step back in time and picture the life of a young midwestern boy and his\n"+
   "family near the turn of the century.  This modest four-room home has been\n"+
   "restored to reflect its appearance in 1907, the year of of the Duke's birth.\n"+
   "An impressive collection of John Wayne memorabilia includes unique items such\n"+
   "as the eyepatch worn in the movie"+HIR+" True Grit"+HIW+", a hat worn in "+HIR+"Rio Lobo"+HIW+", and a\n"+
   "prop suitcase used in the film "+HIR+"Stagecoach"+HIW+".  Hundreds of rare photographs of\n"+
   "the Duke are on display as well as letters from Lucille Ball, Gene Autry,\n"+
   "Maureen O'Hara, Jimmy Stewart, Kirk Douglas, Bob Hope, Ronald Reagan and\n"+
   "George Burns.  John Wayne's life and career is an inspiring example, the\n"+
   "mere mention of his name produces images of courage and patriotism.\n\n"+NORM);          
    return 1;
}

