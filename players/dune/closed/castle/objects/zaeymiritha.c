inherit "obj/clean";


id(str) { return str == "stone" || str == "sithistone" ||
                 str == "zaeymiritha"; }

init()
{
  if (this_player()->is_player())
  {
    write_file("/players/dune/log/QUEST_OBJ",
               this_player()->query_real_name()+
               " (level "+this_player()->query_level()+
               ") took the Zaeymiritha stone."+
               " ("+ctime()+")\n");
  }
}

get() { return 1; }
drop() { return 0; }
query_weight() { return 2; }
query_value() { return 500; }

short() { return "Zae-y'miritha, Sithi Stone of Mirth"; }

long()
{
  write(
"     This is one of the 7 Sithi Stones. It is rich green in color\n"+
"and polished smooth. You can see a lovely forest inside the stone.\n");
}
