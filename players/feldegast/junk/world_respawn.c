inherit "/obj/treasure.c";

void reset(int arg)
{
  set_id("wand");
  set_short("Wand of World Respawning");
  set_long("This is a magical wand used for reloading all of the mud's many castles.\n"+
           "Use the command world_respawn to use it.\n");
  set_weight(1);
  set_value(5);
}

void init()
{
  add_action("cmd_spawn", "world_respawn");
}

int cmd_spawn(string str)
{
  int i;
  string bleh;
  string *castles;
  string file;

  if(this_player()->query_level() < 60)
    return 0;

    
  file=read_file("/room/init_file");
  castles = explode(file, "\n");
  for(i = 0; i < sizeof(castles); i++)
  {
    bleh = castles[i]+"     ";
    bleh = bleh[0..0];
    if(bleh != "#" && bleh != " ")
    {
      write(castles[i]+"\n");
     catch( call_other(castles[i], "???")); 
    }
  }
  write("Castles loaded.\n");
  return 1;
}
