/*****************************************************************************
 *      File:                   miscarriage.c
 *      Function:               This file handles the miscarriage
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow All Rights Reserved.
 *      Source:                 03/14/2006
 *      Notes:                  
 *      Change History:         
 *        03/16/2006 Sparrow: Added color support and better messages.
 *        03/17/2006 Sparrow: Added headers (Happy St. Patty's Day) 
 *                            Modified final push to be more efficient
 ****************************************************************************/
#include <ansi.h>

/* Global Variables */
object Victim;

short() {
  return BLUE+"A disgusting stomach bruise"+NORM;
}
long() {
  write(HIK+"This is a nasty bruise left over from a"+
    " hard punch to your stomach!\n"+NORM);
}
get() { return 1; }
drop() { return 1; }
id(str) { return str=="bruise"; }
query_auto_load() { 
  return "/players/sparrow/areas/bwo/autoload/miscarriage.c:"; 
}

void init() {
  if (!this_player()) return;
  Victim = this_player();
  call_out("first_pains", 10);
}

/* 
 * Function name: first_pains()
 * Description:   This function simply uses tell_object to send message
 *                to prego player and then calls out second_pains() after
 *                10 seconds.
 * Arguments:     playerob - object
 * Returns:       void
 */
void 
first_pains(){
  tell_object(Victim, HIR+"You feel sharp pains in your stomach!\n"+NORM);
  call_out("second_pains",10);
}

/* 
 * Function name: second_pains()
 * Description:   This function simply uses tell_object to send message
 *                to prego player and then calls out final_pains() after
 *                10 seconds.
 * Arguments:     playerob - object
 * Returns:       void
 */
void 
second_pains(){
  tell_object(Victim, 
    HIR+"You feel sharp pains in your stomach!"+NORM+"\n"+
    HIW+"You feel a "+NORM+RED+"warm liquid"+
    HIW+" run down the inside of your leg!\n"+NORM);
  call_out("final_push",10);
}

/* 
 * Function name: final_push()
 * Description:   This function sends messages to the player and the
 *                room, clears pregnancy from playerob, clones the fetus,
 *                moves it to room, initiates battle between the fetus
 *                and the mother, and self destructs the autoload.
 * Arguments:     playerob - object
 * Returns:       void
 */
void 
final_push(){
  object ob;
  ob = clone_object("/players/sparrow/areas/bwo/npc/fetus.c");
  tell_object(Victim, 
    HIK+"\nYou are thrown to your knees in "+HIR+"SHEER AGONY"+HIK+"!\n"+
    "Your stomach begins to burn as you feel the fetus writhe in pain.\n"+
    "Finially the pressure is released onto the ground!\n\n"+NORM
  );
  environment(this_object())->clear_pregnancy();
  move_object(ob,environment(Victim));
  tell_room(environment(Victim),HIR+"\nA Child of the "+HIK+"Dark"+
  HIR+" is born!\n\n"+NORM);
  ob->attacked_by(Victim);
  destruct(this_object());
}
