inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"


string lore, writingnotes, title;


init()
{
   ::init();
   if (this_player() && this_player()->query_guild_name() != "cyberninja")
   {
      tell_object(this_player(), "You cannot enter here.\n");
      this_player()->move_player("guildhall#players/dune/closed/guild/rooms/guildhall");
      return;
   }
   this_player()->clear_fight_area();
   add_action("info_lore","lore");
   add_action("list_lore","list");
   if(call_other(OFFICED, "checkStone", TP, "emerald"))
   {
      add_action("new_lore","new_lore");
   }
}


reset(arg)
{
  if(!present("terminal"))
  {
    move_object(clone_object(BOARDDIR+"/oathboard.c"),this_object());
  }

  if (!arg)
  {
    set_light(1);
    short_desc="The "+FUNKYNAME+" Archives";
    long_desc=
"     A richly decorated building with one main hallway\n"+
"opens before you. Large panels of beautiful wood-carved\n"+
"paintings hang upon both of the side walls.  They depict\n"+
"scenes of war and love.  A golden plaque below each describes\n"+
"the accompanying event.  Type 'list' to see all the topics\n"+
"available.  To view the panels, try 'lore <topic>'.\n"+
"If you are of sufficient rank, you may write 'new_lore <topic>'.\n";

    items=({
"hallway", "The long hallway is carpeted and lit with golden light",
"panels","The panels stretch nearly from ceiling to floor",
"paintings","The paintings are all in unknown colorful oils",
"plaque","There are many golden plaques, each with history upon them",
"plaques","The plaques contain the lore of the "+FUNKYNAME,
   });

    dest_dir=({
ALTLOGIN,             "up",
ROOMDIR+"/emoteon.c", "down",
     });
   }
}


int info_lore(string str)
{
  /* takes str and refers to files in lore 1 or 2 directory */
  string file, topic, all;
  if(!str) {
    write("Usage: lore <topic>\n");
    return 1; }
  file = LOREDIR + "/" + str;
  if (file_size(file) >= 0) {
     call_other(MORED, "more_file", file);
     say(TPN+" studies the "+GUILDNAME+" lore.\n");
     return 1; }
  else write("There is no such lore topic.\n");
  return 1;
}


int list_lore()
{
  write("Lore topics:\n");
  ls(LOREDIR);
  return 1;
}


int new_lore(string input_title)
{
  string *input_titles, file;
  if (!input_title)
  {
    write("Usage: new_lore <title>\n");
    write("You must enter a title.\n");
    return 1;
  }

  input_titles = explode(input_title, " ");
  input_title = input_titles[0];

  write("\nYou begin writing a story song titled '" + input_title + "'.\n");
  file = LOREDIR + "/" + input_title;
  if (file_size(file) >= 0)
  {
    write("That topic already exists. Consult a guild wizard\n"+
          "if you wish to change history.\n");
    return 1;
  }
  title = input_title;
  write("Enter lore. End with '**', abort with '~q'.\n");
  write("__________________________________________________________\n");
  writingnotes = "";
  input_to("get_lore");
  return 1;
}


void get_lore(string str)
{
  if (str == "~q") {
    write("aborted.\n");
    return; }
  if (str=="**") {
    write("Ok.\n");
    lore = writingnotes;
    write_file(LOREDIR + "/" + title, lore+"\n");
    return; }
  writingnotes = writingnotes + str + "\n";
  input_to("get_lore");
}

query_no_fight() { return 1; }
CN_PK() { return 0; }

