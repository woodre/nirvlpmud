#include "/players/tristian/lib/ansi.h"

#define TP this_player()

#define NAME "tristian"

inherit "room/room";

int shield, RANDOM;



reset(arg) {

  if(arg) return;




long_desc =
  ""+HIK+"---------------------------------------------------\n"+
  "|      ||     ||     ||     ||     ||     ||      |\n"+
  "|      ||     ||     ||     ||     ||     ||      |\n"+
  "|      ||     ||     ||     ||     ||     ||      |\n"+
  "|      ||     ||     ||     ||     ||     ||      |\n"+
  "|      ||     ||     ||     ||     ||     ||      |\n"+
  "|      ||     ||     ||     ||     ||     ||      |\n"+
  "|      ||     ||     ||     ||     ||     ||      |\n"+
  "|      ||     ||     ||     ||     ||     ||      |\n"+
  "|      ||     ||     ||     ||     ||     ||      |\n"+
  "---------------------------------------------------\n"+NORM+"";
set_light(1);



items = ({

  "bars","Rusty old bars made of steel that you will see for the rest of your life",

});

dest_dir = ({

  "room/adv_inner.c","north",
  "players/tristian/realms/goblin/rooms/g_room1.c","south",

});
}


short(){ 
switch(random(9)){
   case 0: RANDOM = ""+HIR+"Alcatraz Federal Penitentary"+NORM+"";
   break;
   case 1: RANDOM = ""+HIM+"Attica State Prison"+NORM+"";
   break;
   case 2: RANDOM = ""+HIC+"Fort Leavenworth Disciplinary Barracks"+NORM+"";
   break;
   case 3: RANDOM = ""+HIR+"Andersonville"+NORM+"-Confederate Civil War Prison";
   break;
   case 4: RANDOM = ""+HIG+"Sing Sing State Prison"+NORM+"";
   break;
   case 5: RANDOM = ""+HIR+"Con Air"+NORM+"";
   break;
   case 6: RANDOM = ""+HIB+"Rikker's Island State Prison"+NORM+"";
   break;
   case 7: RANDOM = ""+HIY+"San Quinton State Prison"+NORM+"";
   break;
   case 8: RANDOM = ""+HIG+"Pelican Bay State Prison"+NORM+"";
   break;
   case 9: RANDOM = ""+HIR+"Shawshank State Prison"+NORM+"";
   break; 
}

   return ""+RANDOM+"";
}

init() {

  ::init();

  add_action("church","church");

  add_action("on"); add_verb("on");

  add_action("post"); add_verb("post");

  add_action("off"); add_verb("off");

if(this_player()->query_real_name() != NAME && shield == 1) {

  write("You feel an electric shock and see a FLASH of white light\n"+

        "as you rebound off some surrounding shield.\n");

  this_player()->move_player("off the shields#room/church");

  return 1; }

 }



church() {

  TP->move_player("church#room/church.c");


  return 1; }



static on() {

  write("You "+BOLD+"activate"+NORM+" the shield.\n");

  shield = 1;

  return 1; }



static off() {

if(TP->query_real_name() != NAME) {

  write("You are not allowed to do that!!!!!!!\n");

  return 1; }

  write("You "+BOLD+"deactivate"+NORM+" the shield.\n");

  shield = 0;

  return 1; }



post(){

  TP->move_player("post#room/post.c");

  command("look",this_player());

  return 1; }


