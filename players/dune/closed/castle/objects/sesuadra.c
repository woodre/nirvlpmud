inherit "obj/clean";


id(str) { return str == "stone" || str == "sithistone" ||
                 str == "sesuadra"; }

init()
{
  if (this_player()->is_player())
  {
    write_file("/players/dune/log/QUEST_OBJ",
               this_player()->query_real_name()+
               " (level "+this_player()->query_level()+
               ") took the Sesuadra stone."+
               " ("+ctime()+")\n");
  }
}

get() { return 1; }
drop() { return 0; }
query_weight() { return 1; }
query_value() { return 500; }

short() { return "Sesuad'ra, Sithi Stone of Farewell"; }

long()
{
  write(
"     This is one of the 7 Sithi Stones. It is grey in color\n"+
"and is shaped like a flattened mountain.\n");
}
