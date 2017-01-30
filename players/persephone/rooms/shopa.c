inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
object vikkers;
string wazoo;
reset(arg){
  if(!present("storekeeper")){
     move_object(clone_object("players/persephone/monster/jac"),TOB);
  }
  wazoo="no";
 if(!arg) {
  set_light(1);
  short_desc="Junk Shop";
  long_desc="You would not believe this but as you walk into the shop all you see\n" +
            "is rubbish. The shelves appear to be full of it and on the floor junk\n" +
            "is strewn everywhere. Even the counter appears to be covered in junk.\n" +
            "The shopkeeper appears to be busying himself and his pricing some of\n" +
            "the junk behind the counter.\n";
  items=({"rubbish","What do you think rubbish is the type of things you would\n" +
                    "normally find at a rubbish dump. However there is some junk\n" +
                    "that looks out of place",
           "junk","This is just more rubbish however there might be something of\n" +
                  "value if you move the right pile of junk",
           "counter","You cannot see the counter under all of this junk perhaps if you\n" +
                     "cleaned the counter you might find something of value",
           "floor","Perhaps it would have been better not to look at the floor\n" +
                   "as you are totally disgusted by the filth",
           "filth","This stuff looks really disgusting and you have to avert your\n" +
                   "eyes from this putrid mass of filth"});
  dest_dir=({"players/persephone/rooms/square6","north",
  });
 }
}
realm() { return "NT"; }
init(){
  ::init();
    add_action("razzle","search");
    add_action("razzle","rummage");
}
razzle(str){
  if(str=="rubbish"||str=="junk"){
   if(wazoo=="no"){
    write("You search through the junk in this store and find a strange\n" +
          "looking object that is almost square perhaps you should take it?\n");
   say(CAPTPLNM + " rummages through the rubble searching for something\n");
   vikkers=clone_object("players/persephone/closed/key4");
   move_object(vikkers,TOB);
   wazoo="yes";
   return 1;
   }
   write("You search the rubbish but find nothing of interest\n");
   say(CAPTPLNM + "searches the junk\n");
   return 1;
  }
  write("what do you want to search\n");
  say(CAPTPLNM + " looks for something to search\n");
return 1;
}
