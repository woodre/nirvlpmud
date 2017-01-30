#define tp this_player()->query_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("guitar");
   set_short("An electric guitar");
   set_long("A sleek black electric guitar.\n"+
     "You could 'jam' something to you.\n");
   set_weight(1);
   set_value(150);
}

init()  {
  add_action("play_it","jam");
        }

play_it(str)  {
if(!str)  {
  write("What do you want to jam?\n");
  return 1;
        }
write("You jam '"+str+"' on your electric guitar.\n");
say(tp+" jams '"+str+"' on "+this_player()->query_possessive()+" electric guitar.\n");
return 1;
        }
