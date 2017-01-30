inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(0);
   set_short("A red challenge lever");
   set_name("lever");

   set_long("This is a long, sinister-looking switch lever that is stuck but\n"+
  "to nothing in particular. A big, red warning sticker on it\n"+
  "reads:\n"+
  "\n"+
  "'Pull me' if you want to take on the toughest critter that walks\n"+
  "the MUD to date. Don't bitch if you die though *cackle*\n"+
  "\nAmorpha\n");

   
}


init() 
{
    ::init();
    add_action("on_pull","pull");
}

on_pull(str) 
{ 
    if(!str || str != "lever") return 0;
    write("You pull the lever and pass out. When you come to, you are elsewhere...\n");
    write("\n");
    write_file("/players/mizan/logs/c-lever",
    (this_player()->query_name()) + " pulled the lever at " + ctime() + "\n");
    this_player()->move_player("electrocuted and fozzled#players/mizan/etheriel/ROOMS/tempest.c");
    return 1;
}
