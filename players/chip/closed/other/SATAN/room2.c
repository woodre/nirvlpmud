/*                                                                    
 *    File: /players/chip/closed/other/SATAN/room2.c                
 *    Function: room
 *    Author(s): Chip@Nirvana       
 *    Copyright: Copyright (c) 2008 Chip      
 *               All Rights Reserved   
 *    Source: 7/30/09           
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
    move_object(clone_object("/players/chip/closed/other/SATAN/satanmob.c"),  this_object());
 if(arg) return;
set_light(1);


	short_desc = HIR+"HELL'S PIT"+BOLD+"."+NORM;

	long_desc = BOLD+"This is the deepest circle of "+HIR+"HELL"+NORM+".\n"+
      "There is only one visible exit: retreat.\n";
      
}

init(){ 
 add_action("leave_it", "retreat");
 }

realm(){ return "NT"; }

leave_it(){
  tell_object(this_player(), 
  "You have retreated from "+HIR+"HELL"+NORM+".\n");
  write_file("/players/chip/closed/other/SATAN/attempts",
  this_player()->query_name()+" left Hell.");
  if(present("satan", this_object())){
  write_file("/players/chip/closed/other/SATAN/attempts", 
  "Satan was still there!\n");
  }
  else{
  write_file("/players/chip/closed/other/SATAN/attempts", 
  "Satan was dead!\n");
  }
  move_object(this_player(), "/players/chip/closed/other/SATAN/room1");
  command("look", this_player());
/* This is stupid.
  destruct(this_object());
 Please let me know what this line of code is intended to accomplish and I'll help to implement it
 in a way that doesn't cause enourmous grief to the player or promote cheating
 - illarion 8.20.2009 */
  return 1;
  }

