#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;  
short_desc = HIY+"7 Tigers Inn"+NORM+": "+HIR+"DEMON"+NORM+""+HIB+" Hall"+NORM;
long_desc = ""+HIR+"This is a strange and dark place. It simply is a large\n"+
                  ""+NORM+""+RED+"dirt"+HIR+" room with 3 "+BLK+"holes"+HIR+" you may enter. A "+NORM+""+RED+"demonic figure"+HIR+"\n"+
                  "stands by to take you "+HIB+"back"+HIR+" to your reality.\n"+
                  "A hole \""+NORM+"Down"+HIR+"\" A hole \""+NORM+"North"+HIR+"\"  A hole \""+NORM+"Up"+HIR+"\""+NORM+"\n";
    add_object("/players/tallos/7tigers/mobs/bonedevil2.c");
    add_object("/players/tallos/7tigers/mobs/succubus1.c");
    add_item("dirt","Yes there is dirt in this room. It covers the floor. Its red in color.\n"+
                    "There are a few bones scattered in it.");
    add_item("holes","They are large enough for a dragon to move through if it wanted.");
    add_item("hole","It seems to travel somewhere else.");
    add_item("figure","He is cloaked in darkness but most certainly is there, or is he? He\n"+
                      "is ready to take you 'back' if you wish.");
    add_item("room","The room is large made of hard red rock with a dirt floor.");
    add_item("rock","It is hot to the touch and seems to bleed.");
    add_item("blood","It is dripping from the walls as if they were bleeding.");
    add_smell("main","The smell of burning sulfer is heavy in the air.");
    add_listen("main","As you listen closely you can hear the sounds of people yelling out\n"+
                      "in pain.");
    add_item("bones","They are buried in the dirt. Cleaning it away you find a small gem in\n"+
                     "the eye socket of a skull.");
    add_listen("people","It sounds as if they are being tortured with various instruments.");
    add_item("gem","set in the eye socket of a skull you find in the dirt. The gem seems\n"+
                   "to call for you to 'hold' it.");   
set_light(0);
}
init() {
  ::init();
  add_action("down","down");
  add_action("north","north");
  add_action("up","up");
  add_action("back","back");
  add_action("hold","hold");
}
hold() {
  string str5;
  str5= PATH+"/demonroom4.c";
  move_object(this_player(), PATH+"/demonroom4.c");
  command("look",this_player());
  return 1;
}
down() {
  string str4;
  str4= PATH+"/demonroom1.c";
  move_object(this_player(), PATH+"/demonroom1.c");
  command("look",this_player());
  return 1;
}
north() {
  string str3;
  str3= PATH+"/demonroom2.c";
  move_object(this_player(), PATH+"/demonroom2.c");
  command("look",this_player());
  return 1;
}
up() {
  string str2;
  str2= PATH+"/demonroom3.c";
  move_object(this_player(), PATH+"/demonroom3.c");
  command("look",this_player());
  return 1;
}
back() {
  string str;
  str= PATH+"/3ftopstairs.c";
  move_object(this_player(), PATH+"/3ftopstairs.c");
  command("look",this_player());
  return 1;
}