inherit "obj/clean";


id(str) { return str == "stone" || str == "sithistone" || 
                 str == "mayesa"; }

init()
{
  if (this_player()->is_player())
  {
    write_file("/players/dune/log/QUEST_OBJ",
               this_player()->query_real_name()+
               " (level "+this_player()->query_level()+
               ") took the Mayesa stone."+
               " ("+ctime()+")\n");
  }
}

get() { return 1; }
drop() { return 0; }
query_weight() { return 2; }
query_value() { return 500; }

short() { return "Mayesa, Sithi Stone of the Cat"; }

long()
{
  write(
"     This is one of the 7 Sithi Stones. It is orange in color\n"+
"and perfectly round. The stone is made of amber and resembles\n"+
"a cat's eye.\n");
}
