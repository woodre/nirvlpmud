#define tp this_player()->qury_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("key");
   set_alias("silver key");
   set_short("A small silver key");
   set_long(
    "A small silver key with faint runes etched upon one side.\n"+
     "You can <unlock> something with it.\n");
   set_weight(0);
   set_value(1);
}

init()  {
  ::init();
  add_action("unlock_door","unlock");
        }

unlock_door(str)  {
  if(str == "door")  {
  if(!present("iron door",environment(this_player())))  {
  write("Your key doesn't seem to work on this door.\n");
  say(tp+" tries to unlock the door but fails...\n");
  return 1;
        }
        }
        }
