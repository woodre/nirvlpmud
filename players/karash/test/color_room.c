
inherit "/room/room";

#include <ansi.h>

/******************************************************************************
 * Program: color_room.c
 * Path: /players/karash/test
 * Type: room
 * Created: September 2014 by Karash
 *
 * Purpose: To show all colors
 *
 * History:
 *          
 ******************************************************************************/

reset(arg)
{
  ::reset(arg);
	
	
  if(arg) return;
  short_desc = GRY+"Color Testing"+NORM;
  long_desc=
"    This room is uesed to test color.\n";
  set_light(1);
  items=({
    "stuff",
"This is stuff",
  });

 dest_dir=({
    "/players/karash/Outpost/rooms/so02","south",
  });

}

void init()
{
  ::init();
  
tell_object(this_player(), BLK+"THIS IS A TEST BLK"+NORM+"\n");
tell_object(this_player(), RED+"THIS IS A TEST RED"+NORM+"\n");
tell_object(this_player(), GRN+"THIS IS A TEST GRN"+NORM+"\n");
tell_object(this_player(), YEL+"THIS IS A TEST YEL"+NORM+"\n");
tell_object(this_player(), BLU+"THIS IS A TEST BLU"+NORM+"\n");
tell_object(this_player(), MAG+"THIS IS A TEST MAG"+NORM+"\n");
tell_object(this_player(), CYN+"THIS IS A TEST CYN"+NORM+"\n");
tell_object(this_player(), WHT+"THIS IS A TEST WHT"+NORM+"\n");
tell_object(this_player(), HIBLK+"THIS IS A TEST HIBLK"+NORM+"\n");
tell_object(this_player(), HIK+"THIS IS A TEST HIK"+NORM+"\n");
tell_object(this_player(), GRY+"THIS IS A TEST GRY"+NORM+"\n");
tell_object(this_player(), HIR+"THIS IS A TEST HIR"+NORM+"\n");
tell_object(this_player(), HIG+"THIS IS A TEST HIG"+NORM+"\n");
tell_object(this_player(), HIY+"THIS IS A TEST HIY"+NORM+"\n");
tell_object(this_player(), HIB+"THIS IS A TEST HIB"+NORM+"\n");
tell_object(this_player(), HIM+"THIS IS A TEST HIM"+NORM+"\n");
tell_object(this_player(), HIC+"THIS IS A TEST HIC"+NORM+"\n");
tell_object(this_player(), HIW+"THIS IS A TEST HIW"+NORM+"\n");
tell_object(this_player(), BBLK+"THIS IS A TEST BBLK"+NORM+"\n");
tell_object(this_player(), BRED+"THIS IS A TEST BRED"+NORM+"\n");
tell_object(this_player(), BGRN+"THIS IS A TEST BGRN"+NORM+"\n");
tell_object(this_player(), BYEL+"THIS IS A TEST BYEL"+NORM+"\n");
tell_object(this_player(), BBLU+"THIS IS A TEST BBLU"+NORM+"\n");
tell_object(this_player(), BMAG+"THIS IS A TEST BMAG"+NORM+"\n");
tell_object(this_player(), BCYN+"THIS IS A TEST BCYN"+NORM+"\n");
tell_object(this_player(), BWHT+"THIS IS A TEST BWHT"+NORM+"\n");
tell_object(this_player(), HBBLK+"THIS IS A TEST HBBLK"+NORM+"\n");
tell_object(this_player(), HBRED+"THIS IS A TEST HBRED"+NORM+"\n");
tell_object(this_player(), HBGRN+"THIS IS A TEST HBGRN"+NORM+"\n");
tell_object(this_player(), HBYEL+"THIS IS A TEST HBYEL"+NORM+"\n");
tell_object(this_player(), HBBLU+"THIS IS A TEST HBBLU"+NORM+"\n");
tell_object(this_player(), HBMAG+"THIS IS A TEST HBMAG"+NORM+"\n");
tell_object(this_player(), HBCYN+"THIS IS A TEST HBCYN"+NORM+"\n");
tell_object(this_player(), HBWHT+"THIS IS A TEST HBWHT"+NORM+"\n");
tell_object(this_player(), NORM+"THIS IS A TEST NORM"+NORM+"\n");
tell_object(this_player(), BLK+"THIS IS A TEST"+NORM+"\n");
tell_object(this_player(), BLK+"THIS IS A TEST"+NORM+"\n");
tell_object(this_player(), BLK+"THIS IS A TEST"+NORM+"\n");
tell_object(this_player(), BLK+"THIS IS A TEST"+NORM+"\n");
tell_object(this_player(), BLK+"THIS IS A TEST"+NORM+"\n");
tell_object(this_player(), BLK+"THIS IS A TEST"+NORM+"\n");
tell_object(this_player(), BLK+"THIS IS A TEST"+NORM+"\n");
tell_object(this_player(), BLK+"THIS IS A TEST"+NORM+"\n");
tell_object(this_player(), BLK+"THIS IS A TEST"+NORM+"\n");


}