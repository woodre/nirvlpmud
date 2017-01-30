#include "lock.h"

do_lock( object ob) {
  if( query_lock( ob ) ) {
    return 1;
  }
  add_attribute( "[Locked]", ob);
  write("Locking: "+ ob->short() +".\n");
}

do_unlock( object ob) {
  if( !query_lock( ob ) ) {
    return 1;
  }
  delete_attribute( "[Locked]", ob);
  write("Unlocking: "+ob->short()+".\n");
}

query_lock( object ob) {
  return query_attribute( "[Locked]", ob );
}

inventory( string type) {
  object ob, who;

FORALL( ob, this_player())

    /* show if not invis, and if id matches 'type' */
    if (ob->short() &&
        (!type || ob->id( type))) {
      write(capitalize( ob->short()) );
      write((query_lock( ob ) ? "  [Locked]" : " ") + "\n");
    }
  return 1;
}

lock( string what) {
  object ob;
  string all_items, type;

  if (!what) {
    notify_fail( "What do want to lock?\n");
    return 0;
  }

  if( sscanf(what, "%s %s",all_items,type) == 2 ) {
    if( all_items == "all" ) {
      do_lock_all( type );
    return 1;
    }
  }
  if( what == "all" ) {
    do_lock_all( 0 );
    return 1;
  }
  ob= present( what, this_player());
  if (!ob)
    write( "You do not have a " + what + ".\n");
  else
    do_lock( ob);

  return 1;
}

unlock( string what) {
  object ob;
  string all_items, type;

  if (!what) {
    notify_fail( "What do want to unlock?\n");
    return 0;
  }

  if( sscanf(what, "%s %s",all_items,type) == 2 ) {
    if( all_items == "all" ) {
      do_unlock_all( type );
    return 1;
    }
  }
  if( what == "all" ) {
    do_unlock_all( 0 );
    return 1;
  }

  ob= present( what, this_player());
  if (!ob)
    write( "You do not have a " + what + ".\n");
  else
    do_unlock( ob);

  return 1;
}
do_lock_all( string type ) {
  object ob;

  FORALL( ob, this_player())
    if( ob->short() && ( !type || ob->id( type )) ) {
      do_lock( ob );
    }
}
do_unlock_all( string type ) {
  object ob;

  FORALL( ob, this_player())
    if( ob->short() && ( !type || ob->id( type )) ) {
      do_unlock( ob );
    }
}
