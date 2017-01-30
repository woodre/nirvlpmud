inherit "obj/clean";


id(str) { return str == "stone" || str == "sithistone" ||
                 str == "resurieni"; }

init()
{
  if (this_player()->is_player())
  {
    write_file("/players/dune/log/QUEST_OBJ",
               this_player()->query_real_name()+
               " (level "+this_player()->query_level()+
               ") took the Resurieni stone."+
               " ("+ctime()+")\n");
  }
}

get() { return 1; }
drop() { return 0; }
query_weight() { return 1; }
query_value() { return 500; }

short() { return "Re suri'eni, Sithi Stone of Tranquility"; }

long()
{
  write(
"     This is one of the 7 Sithi Stones. It is red in color\n"+
"and perfectly round. Inside the stone, you can see the image of\n"+
"a waterfall.\n");
}
