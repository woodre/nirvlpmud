/* Shardak guild, (tm) Dragnar/John
 * tag / untag / inventory is (c) Balowski/Rasmus, 950131
 *   "Mowing down mc's like I'm mowing the lawn"
 */
#include "always.h"

do_tag( object ob) {
  add_attribute( "*", ob);
}

do_untag( object ob) {
  delete_attribute( "*", ob);
}

query_tag( object ob) {
  return query_attribute( "*", ob);
}

inventory( string type) {
  object ob;

  FORALL( ob, this_player())

    /* show if not invis, and if id matches 'type' */
    if (ob->short() &&
        (!type || ob->id( type))) {
      write( (query_tag( ob) ? "*" : " ") + capitalize( ob->short()) + ".\n");
    }
  return 1;
}

tag( string what) {
  object ob;

  if (!what) {
    notify_fail( "What do want to tag?\n");
    return 0;
  }

  ob= present( what, this_player());
  if (!ob)
    write( "You do not have a " + what + ".\n");
  else
    do_tag( ob);

  return 1;
}

untag( string what) {
  object ob;

  if (!what) {
    notify_fail( "What do want to untag?\n");
    return 0;
  }

  ob= present( what, this_player());
  if (!ob)
    write( "You do not have a " + what + ".\n");
  else
    do_untag( ob);

  return 1;
}
