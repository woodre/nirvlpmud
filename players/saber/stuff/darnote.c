#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("note");
   set_alias("paper");
   set_short("A scrap of water soaked paper");
   set_long(
   "A scrap of water soaked paper.\n"+
     "There is something written upon it.\n");
   set_weight(0);
   set_value(1);
}

init()  {
  ::init();
  add_action("read_note","read");
        }

read_note(str)  {
  if(str == "paper" || str == "note")  {
  write("\n\"Journal entry 17\"\n"+
     "\n     \"Sir Garvolon, Emilia and Kylaar are dead.\"\n"+
     "     \"Killed by one of our own.  He just turned and...\"\n\n"+
     "The rest of the entry is too blured to read.\n\n");
  say(tp+" reads a note.\n");
  return 1;
        }
        }
