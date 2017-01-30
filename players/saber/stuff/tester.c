#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("tester");
   set_short("A tester");
  set_long(
  "Type test <string> to use this test object.\n");
   set_weight(0);
   set_value(1);
}

init()
{  add_action("test_string", "test");   }

test_string(str)  {
if(!str)  {
  write("What do you want the test to say?\n");
  return 1;
        }
  tell_room("/players/saber/workroom.c",
      this_player()->query_name()+" tests '"+str+"'.\n");
  tell_room("/players/pathfinder/workroom.c",
    this_player()->query_name()+" tests '"+str+"'.\n");
  write("You use the test object.\n");
  return 1;
        }
