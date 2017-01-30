inherit "obj/container.c";

#include <ansi.h>

#define SHOP "/obj/daemons/shop_daemon"


id(str) {
  return str == "bag" || str == "sack" || str == "rucksack" ||
   str == "tactical" || str == "tactical rucksack";
}

 reset(arg) {
  ::reset(arg); /* changed from reset() */
    if (arg) return;
    set_name("sack");
    set_short("Tactical Rucksack");
    set_long("A black nylon & canvas heavy duty rucksack.  Designed to carry\n\
tactical and survival gear, it has many pockets on the outside\n\
to carry all of your critical gear that helps keep you alive.\n\
The main compartment is very large with lots of space.  The quality\n\
of this pack is impressive, with padded straps and double stitching.\n\
There is a "+YEL+"tag"+NORM+" sewn on the Rucksack that you can read.\n");
    set_weight(1);
    set_value(550);
    set_max_weight(1000);
}


init() {
  ::init();
  add_action("cmd_read","read");
  add_action("baginv","baginv");
  add_action("Stuff","stuff");
  add_action("Stuff","unstuff");
}

baginv( string str ) {
  if( this_player() && environment(this_object()) == this_player() )
    return SHOP->list( str );
  else
    return 0;
}

status cmd_read(string arg) {
  if(!id(arg) && arg != "tag")
    return 0;
  tell_object(this_player(),
    "This rucksack allows you to "+YEL+"baginv"+NORM+" to see what is inside.\n\
You also can "+YEL+"stuff"+NORM+" and "+YEL+"unstuff"+NORM+" items from the bag.\n"+NORM);
  return 1;  
}

stuff_all( object who, string verb, string type ) {
  object ob, next;

  for( ob=first_inventory(who); ob; ob = next ) {
    next = next_inventory( ob );
    if( ob->short() && ( !type || ob->id( type )) ) {
      if( !ob->drop() && !ob->can_put_and_get() ) {
        if( verb == "stuff" )
          command( "put " + (type ? type : ob->query_name()) +" in sack", this_player() );
        else
          command( "get " + (type ? type : ob->query_name()) +" from sack", this_player() );
      }
    }
  }
}

Stuff( string what ) {
  object ob;
  string all, type, verb;
  
  verb = query_verb();
  
  if (!what) {
    write(capitalize(verb)+ " what " + (verb=="stuff" ? "into" : "from")+ " your sack?\n");
    write("You can '"+verb+" <itemname>', '"+verb+" all <itemname>', or '"+verb+" all'.\n");
    return 1;
  }
  
  if( sscanf(what, "%s %s",all,type ) == 2 ) {
    if( all == "all" ) {
      if( verb == "stuff" )
        stuff_all( this_player(), query_verb(), type );
      else
        stuff_all( this_object(), query_verb(), type );
      return 1;
    }
  }

  if( what == "all" ) {
    if( verb == "stuff" )
      stuff_all( this_player(), query_verb() );
    else
      stuff_all( this_object(), query_verb(), type );
    return 1;
  }

  if( verb == "stuff" )
    command( "put " +what+" in sack", this_player() );
  else
    command( "get " +what+" from sack", this_player() );
  return 1;
    
}

query_empty_shop() { return short_desc+" is empty."; }
query_backshop() { return this_object(); }

query_save_flag() { return 1; }
