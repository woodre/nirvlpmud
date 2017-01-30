inherit "obj/clean";


id(str) { return str == "stone" || str == "sithistone" ||
                 str == "minneyar"; }

init()
{
  if (this_player()->is_player())
  {
    write_file("/players/dune/log/QUEST_OBJ",
               this_player()->query_real_name()+
               " (level "+this_player()->query_level()+
               ") took the Minneyar stone."+
               " ("+ctime()+")\n");
  }
}

get() { return 1; }
drop() { return 0; }
query_weight() { return 2; }
query_value() { return 500; }

short() { return "Minneyar, Sithi Stone of the Universe"; }

long()
{
  write(
"     This is one of the 7 Sithi Stones. It is black in color\n"+
"and perfectly round. The stone seems to be made of some sort of\n"+
"black metal.\n");
}
