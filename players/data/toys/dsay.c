/* ***********************************************
 * dsay.c
 *
 * Earwax 2/10/04
 * 
 * A toy command - makes it appear to everyone in the room that
 * they are saying the message.
 *
 * **********************************************/

#include <ansi.h>

status dsay(string arg) {
  object ob;

  /* Check for valid string to say */
  if (!arg || arg == "") {
    notify_fail("What is it you want to say?\n");
    return 0;
  }

  /* Cycle through the inventory of the room */
  ob = first_inventory(environment(this_player()));

  while(ob) {
    /* If they are a player, echo it to them */
    if (living(ob) && (status)ob->is_player()) {
tell_object(ob, (string)ob->query_name() + " says: " + arg + "\n");
    }

    /* Move onto next object in room */
    ob = next_inventory(ob);
  }

  write("Masked say completed.\n");
  return 1;
}
