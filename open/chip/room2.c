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

#include "/players/chip/ansi.h"

object who;

reset(arg){
 if(arg) return;
set_light(1);
}

long(){
write(BOLD+"This is the deepest circle of "+HIR+"HELL"+NORM+".\n"+
      "There is only one visible exit: retreat.\n\n");
      
short(){ return HIR+"HELL'S PIT"+BOLD+"."+NORM; }

init(){ 
 add_action("leave_it", "retreat");
 }

realm(){ return "NT"; }

leave_it(){
  tell_object(this_player(), 
  "You have retreated from "+HIR+"HELL"+NORM+".\n");
  write_file("/players/chip/closed/other/SATAN/attempts",
  this_player()->query_name()+" left the arena.");
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
  destruct(this_object());
  return 1;
  }

