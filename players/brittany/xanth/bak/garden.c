#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int X;
int open;
reset(arg) {
if(!present("bear")) {   
    move_object(clone_object("/players/brittany/xanth/NPC/gummybear.c"),this_object());
   }
   open = 0;
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A candy garden"+NORM;
   long_desc =
    "     You land on something soft, it is a huge marshmallow.  A candy\n"+
    "garden appears in front of you.  Lollipops grow from the ground\n"+
    "and the weeds are made of licorice.  A house made out of candy canes\n"+
    "is west of here.\n";
   
   items = ({
         "marshmallow","A sweetened confection from the root of the marsh mallow",
         "garden","The garden is made of candy",
         "lollipops","Lollipops are growing from the ground",
         "licorice","The weeds are made of licorice",
         "house","The candy house is north of here, maybe you can enter it",
          });

   dest_dir = ({
         "/players/brittany/xanth/gar3.c","south",
         "/players/brittany/xanth/gar1.c","north",
         "/players/brittany/xanth/garden1.c","east",
         "/players/brittany/xanth/house.c","west",
              });
}

init() {
   ::init();
   add_action("open_door","open");
   add_action("unlock_door","unlock");
   add_action("west","west");
   add_action("search","search");
}
west(str) {
if(!open){
write("The door is closed.\n");
return 1;
}
   this_player()->move_player("west#/players/brittany/xanth/house.c");
return 1; }
 

unlock_door(str) {
   if(!str || str != "door") {
      notify_fail("Unlock what?\n");
return 0; }
      if(X==0) {
         write("The door clicks as it unlocks.\n");
         X ++;
         return 1; }
   }
 
open_door(str) {
if(!str || str != "door") {
         notify_fail("Open what?\n");
         return 0; }
 
      if(X==0) {
         notify_fail("The door is locked.\n");
         return 0; }
 
      if(X==1) {
         write("The door opens.\n");
         open = 1;
         X ++;
         return 1; }
 
      if(X==2) {
         notify_fail("The door is already open.\n");
         return 0; }
   }

search(str) {
      write("You search the room and find nothing.\n");
      return 1; }
