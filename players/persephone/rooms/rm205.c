inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
string walling;
reset(arg){
 if(!arg) {
  walling="no";
  set_light(1);
  short_desc="Hotel Room";
  long_desc="This room is not the most impressive hotel room you have seen as it\n" +
            "does not match the splendour of what you would expect of a room in an\n" +
            "international hotel. To the north is the corridor which appears to be the\n" +
            "the only exit.  There is something troubling however as the walls\n" +
            "seem to be closer than they should be.\n" +
            "\n";
  items=({"furnishings","Just the ordinary run of the mill type hotel furnishings\n" +
                        "including a a double bed, television, bar fridge, chairs,\n" +
                        "table, lamp, and a spyhole",
          "walls","The walls are painted white and very plain however the spyhole\n" +
                  "in the west wall has you puzzled",
          "wall","The west wall seems extremely troubling not only because of the\n" +
                 "spyhole but also it seems out of place\n",
          "spyhole","You can see another room through the spyhole however you cannot\n" +
                    "tell what is in it",
           "bed","This is just a standard double bed with no sheets or blankets on it",
           "television","A small portable television that is securelly mounted into\n" +
                        "the east wall",
          "chairs","They are just plain wooden chairs",
          "table","It is just an ordinary looking table with no distinguishing features",
          "lamp","It looks like any other gas lamp you have ever seen",
           "fridge","Bar fridge is not exactly the right term for this you think it\n" +
          "it might be an icebox",
          });
  dest_dir=({"players/persephone/rooms/hcorr2a.c","north",
           });
 }
}
realm() { return "NT"; }
init(){
  ::init();
    add_action("tap","tap");
    add_action("tap","knock");
    add_action("tap","search");
    add_action("wibble","west");
    add_action("wibble","w");
}
tap(str){
  if(str=="wall"){
    write("Your hand passes through the wall almost if it were not there\n");
    say(CAPTPLNM + " taps on the wall.\n");
    walling="yes";
  return 1;
  }
  write("What do you want to tap?!?!?\n");
return 1;
}
wibble(){
  if(walling=="yes"){
    if(!present("woblestart",TPL)){
      write("The wall seems to stop you\n");
      say(CAPTPLNM + " walks into the western wall\n");
    return 1;
    }
    write("You walk through the western wall into a hidden room\n");
    TPL->move_player("west through the wall#" + "players/persephone/rooms/hidden1");
  return 1;
  }
  write("You walk into the wall\n");
return 1;
}
