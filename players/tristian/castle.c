#include "/players/tristian/lib/Basicdefine.h"
#define NAME "Tristian"
#define DEST "room/forest9"


id(str) { return str == "forest" || str == "sign"; }

short() {
  return 
  "A "+HIR+BLINK+"SIGN"+NORM;
}

long() {
  write(
    "A "+HIR+"SIGN"+NORM+", perhaps you should read it to find out more information, something has changed.\n");

}

init() {
  add_action("cmd_south", "south");
  add_action("life_of_crime","crime");
  add_action("Read","read");
}

Read(str)
{
  if(!str) 
  {
    write("Read what??\n");
    return 1;
  }
  if(str == "sign") 
  {
    write(
      "You can venture south into the goblin forest, if you are small enough.\n\n"+
      "Or you can try committing a 'crime' to embark on a life of crime, this area is now\n"+
      "kill or be killed, you have been warned..\n\n");
    return 1;   
  }
}
cmd_south()
{
int lev;
  if(this_player()->is_npc())
  return 1;
  lev=(int)this_player()->query_level();
  if(lev > 8 && lev < 20) {
  write(
    "You feel like you wouldn't benefit from walking this path. *LEVEL 8 AND LOWER ONLY*\n");
  return 1;
}

  this_player()->move_player("south#/players/tristian/realms/goblin/rooms/g_room1.c");
  write_file(LOG+"enter.log",
  HIG+ctime()+" "+NORM+capitalize((string)TPRN)+" entered Goblin Area.\n");
  return 1;
}

life_of_crime()
{
  if(this_player()->is_npc())
  return 1;
  move_object(this_player(),"/players/tristian/realms/ClubFed/rooms/Start.c");
  command("look",this_player()); 
  write_file(LOG+"CF_enter.log",
  HIR+ctime()+" "+NORM+capitalize((string)TPRN)+" entered Club Fed.\n");
  return 1;
}  

reset(arg) {
    if (arg)
        return;
    move_object(this_object(), DEST);
/* No - Rumplemintz
    load_it();
*/
}

is_castle(){return 1;}

load_it(){
  clone_object("players/tristian/closed/blue.c");
  clone_object("players/tristian/closed/shank.c"); 
 }
