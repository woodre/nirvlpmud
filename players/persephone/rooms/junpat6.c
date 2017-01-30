inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(int arg){
 if(arg) return;
  set_light(0);
  short_desc="Eerie Path";
  long_desc="The trees around the path continue to close in on almost as if they\n" +
            "were trying to persuade you to go back to the south while further north\n" +
            "it looks darker. Perhaps what worries you most is the sudden silence\n" +
            "in this part of the jungle.\n" +
            "\n";
  items=({"path","Perhaps a track would be a better description however you can see large footprints",
         "trees","They are tall and dark and you cannot even attempt to guess\n" +
                 "what kind they are",
         "jungle","The jungle surrounds you and is extremely dark and scary",
         "footprints","They definately look as if dogs made them however it is strange\n" +
                      "that you can only see footprints from two feet and not four heading\n" +
                      "east into the jungle",
        });
  dest_dir=({"players/persephone/rooms/junpatc","north",
             "players/persephone/rooms/warglr","south",
           });
}
init(){
 ::init();
  add_action("go_east","east");
  add_action("go_east","e");
}
go_east(){
 write("You go east along the path you found\n");
 this_player()->move_player("leaves east#"+"players/persephone/rooms/junpat5");
 return 1;
}
