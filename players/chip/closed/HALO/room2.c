/*                                                                    
 *    File: /players/chip/closed/other/HALO/room2.c                
 *    Function: room
 *    Author(s): Chip@Nirvana       
 *    Copyright: Copyright (c) 2013 Chip      
 *               All Rights Reserved   
 *    Source: 1/5/13           
 *    Notes:                                                          
 *                                                                    
 *                                                                    
 *    Change History:                                                 
 */

inherit "/room/room";
#include "/players/chip/ansi.h"

object who;

reset(arg){
	::reset(arg);
  if( !present("satan", this_object()) )
    move_object(clone_object("/players/chip/closed/other/HALO/masterchief.c"),  this_object());
 if(arg) return;
set_light(1);


	short_desc = HIG+"Pillar of Autumn"+BOLD+"."+NORM;

	long_desc = BOLD+"You are aboard the "+HIG+"Pillar of Autumn"+NORM+".\n"+
      "There is only one visible exit: retreat.\n";
      
}

init(){ 
 add_action("leave_it", "retreat");
 }

realm(){ return "NT"; }

leave_it(){
  tell_object(this_player(), 
  "You have retreated from the Pillar of Autumn.\n");
  write_file("/players/chip/closed/other/HALO/attempts",
  this_player()->query_name()+" left the Pillar of Autumn.");
  if(present("chief", this_object())){
  write_file("/players/chip/closed/other/HALO/attempts", 
  "Master Chief was still there!\n");
  }
  else{
  write_file("/players/chip/closed/other/HALO/attempts", 
  "Master Chief was dead!\n");
  }
  move_object(this_player(), "/room/vill_green.c");
  command("look", this_player());
  return 1;
  }

