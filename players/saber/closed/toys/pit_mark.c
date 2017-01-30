#define tp this_player()->query_name()

id(str)  {
  return str == "pit_mark" ||
         str == "pit_mark";
        }

drop()  { return 1; }

init()  {
  add_action("climb","climb");
  call_out("dest_me",1000);
        }

climb()  {
  write("You climb out of the leech pit.\n");
  say(tp+" climbs out of the leech pit.\n");
  remove_call_out("dest_me");
  destruct(this_object());
  return 1;
        }

dest_me()  {
  destruct(this_object());
  return 1;
        }
