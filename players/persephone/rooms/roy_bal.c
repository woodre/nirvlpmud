inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
object sulkey;
string snazzled;
reset(arg){
 if(!arg) {
snazzled="no";
 set_light(0);
  short_desc="Royal Ballroom";
  long_desc="This is the royal ballroom of the Chelsea Hotel where all the\n" +
            "functions involving royalty are held. As you entered this room you\n" +
            "noticed the cloak room and security desk and you could not help but\n" +
            "be amazed by the granduer of the the dance floor and the large table\n" +
            "in the middle of the room with a chandelier hanging over it.\n" +
            "\n";
  items=({"chandelier","The chandelier while unique troubles you as you think\n" +
                       "that there might be something out of place",
          "table","The table is simply stunning and made out of mahogany",
          "cloakroom","The cloakroom appears to be boarded off",
          "dancefloor","What nicer than a polished wooden floor",
        });
  dest_dir=({"players/persephone/rooms/rsuite","south",
           });
 }
}
realm() { return "NT"; }
init(){
  ::init();
    add_action("glab","search");
    add_action("glab","examine");
}
glab(str){
  if(str=="chandelier"){
   if(snazzled=="no"){
    write("You search the chandelier to find an intricate silver key that\n" +
          "you take immediately.\n");
    say(CAPTPLNM + " searches the chandelier and pockets a shiny object\n");
    sulkey=clone_object("players/persephone/closed/silkey");
    move_object(sulkey,TPL);
    snazzled="yes";
   return 1;
   }
   write("You search the chandelier only to find an empty hidden compartment\n");
  return 1;
  }
  write("What are you trying to search??\n");
return 1;
}
