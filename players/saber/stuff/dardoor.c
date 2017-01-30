#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("door");
   set_alias("saber_swamp_door");
   set_short("A large iron-bound door");
   set_long(
     "A large iron bound door covered with vines.\n");
   set_weight(0);
   set_value(1);
}

init()  {
  ::init();
  add_action("enter_door","open");
  add_action("enter_door","unlock");
        }

enter_door(str)  {
  object key;
  if(str == "door")  {
    if( (key=present("saber_swamp_key", this_player())) && key->saber_swamp_door_key())  {
      write("Your key turns in the lock but the door refuses to budge.\n");
      return 1;

  }
  write("You must have the correct key to open the door.\n");
  return 1;
  }
  notify_fail("Open what?\n");
}

get()  { return 0; }
saber_swamp_door() { return 1; }
