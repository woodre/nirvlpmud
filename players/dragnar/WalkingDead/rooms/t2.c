inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";
#include <ansi.h>

int locked, open;

reset(arg) {
  object key, guard; 

  if( !present("guard") ) {
    guard = clone_object("/players/dragnar/WalkingDead/mons/guard");
    /** Add extra chats for this guard, and make it chat more **/
    guard->set_chat_chance( 6 );
    guard->load_chat("Guard says: 'Are they really dead, or just sick?'\n");
    guard->load_chat("Guard says: 'The walker slayers do not understand the walkers...'\n");
    guard->load_chat("Guard says: 'I'll keep my loved ones close, until we have a cure.'\n");
    move_object(guard, this_object());
    key = clone_object("/obj/treasure");
    key->set_name( "key" );
    key->set_short( "A silver key" );
    key->set_long( "A normal looking house key.\n");
    key->set_weight( 1 );
    key->set_value( 20 );
    key->SetMultipleIds( ({ "walkingdead_key", }) );
    move_object( key, guard );    
  }
  
  locked = 1;
  open = 0;

  if(arg) return;
  
  short_desc = BGRN+BLK+"Black Creek"+NORM;
  set_light(1);

  items=({
    "buildings", "They tower above the alley, but being this close makes it\n\
impossible to see what they are. The building on the north side of\n\
the alley has wooden door that could be entered from the alley",
    "door", "blank",
    "alley", "A typical dirty dark alley where dead bodies are usually dumped",
    "fence", "Eight feet tall with a roll of "+GRY+"barbed wire"+NORM+" at the top, it prevents\n\
Walkers from wandering into the village",
    "road","From this point it looks a standard small village road",
    "barbed wire","Razor wire with 3 inch barbs that change directions",
    "street","From this point it looks a standard small village road",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r6","west",
  });
  long_desc=
"A small alley runs east and west here and ends at the fence line.\n\
The north and south are blocked by buildings and the fence prevents\n\
passage east. The only direction is back toward the main road to\n\
the west.\n";
  update_door_status(); 
  reanimate_corpse();
}

init() {
  ::init();
  add_action("Open","open");
  add_action("Close","close");
  add_action("Unlock","unlock");
  add_action("Lock","lock");
  add_action("Enter","enter");
}

update_door_status() {
  string door_desc;
  int i;

  door_desc = "A solid wooden door which is weathered, but still strong";
  door_desc += (locked ? " (locked)" : " (unlocked)") + (open ? " (open)" : " (closed)");
  i = member( items, "door" );
  if( i >= 0 ) {
    items[i+1] = door_desc;
  }
}

Open( string str ) {
  if( !str || str != "door" )
    return 0;

  if( open ) {
    write("The door is already open.\n");
    return 1;
  }

  if( present("guard", this_object()) ) {
    write("The guard says: 'We will find a cure and save them! I will not allow you to harm them.'\n");
    return 1;
  }

  if( locked ) {
    write("The door is locked.\n");
    return 1;
  }

  open = 1;
  update_door_status();
  write("The door opens with a loud creak.\n");
  say( this_player()->query_name()+" opens the door with a load creak.\n");
  return 1;
}

Close( string str ) {
  if( !str || str != "door" )
    return 0;

  if( !open ) {
    write("The door is already closed.\n");
    return 1;
  }

  open = 0;
  update_door_status();
  write("The door closes with a loud creak.\n");
  say( this_player()->query_name()+" closes the door with a load creak.\n");
  return 1;
}

Unlock( string str ) {
  object key, key1;

  if( !str || str != "door" )
    return 0;

  if( present("guard", this_object() ) ) {
    write("The guard says: 'We will find a cure and save them! I will not allow you to harm them.'\n");
    return 1;
  }

  if( !locked ) {
    write("The door is already unlocked.\n");
    return 1;
  }

  key1 = present("key", this_player() );
  if( !key1 ) {
    write("You don't have a key.\n");
    return 1;
  }

  if( locked > 1 ) {
    write("You try to insert the key, but the lock is jammed.\n");
    return 1;
  }

  key = present("walkingdead_key", this_player() );
  if( !key ) {
    write("You try the key in the lock...\n");

    if( !random(12) ) {
      write("Unfortunately, it breaks off in the lock and is destroyed!\n");
      locked++;
      destruct( key1 );
      return 1;
    }
    else {
      if( !random(20) ) {
        write("Amazingly, the key fits and turns the tumblers!\n");
      }
      else {
        write("The key fits into the lock, but it won't turn the tumblers.\n");
        return 1;
      }
    }
  }
  else
    write("You use the guard's key to unlock the door.\n");
  
  locked = 0;
  update_door_status(); 
  say( this_player()->query_name()+" unlocked the door with a key.\n");
  return 1;
  
}

Lock( string str ) {
  object key, key1;

  if( !str || str != "door" )
    return 0;

  if( locked ) {
    write("The door is already locked.\n");
    return 1;
  }

  key1 = present("walkingdead_key", this_player() );
  if( !key1 ) {
    write("You don't have the key.\n");
    return 1;
  }

  if( locked > 1 ) {
    write("You try to insert the key, but the lock is jammed.\n");
    return 1;
  }

  write("You use the guard's key to lock the door.\n");
  locked = 1;
  update_door_status(); 
  say( this_player()->query_name()+" locked the door with a key.\n");
  return 1;
  
}

Enter( string str ) {

  if( !str || str != "door" )
    return 0;

  if( present("guard", this_object() ) ) {
    write("The guard says: 'We will find a cure and save them! I will not allow you to harm them.'\n");
    return 1;
  }

  if( !open ) {
    write("The door is closed.\n");
    return 1;
  }

  this_player()->move_player("into the doorway#/players/dragnar/WalkingDead/rooms/t8");
  return 1;
}
