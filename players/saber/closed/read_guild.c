#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("couch"))  {
move_object(clone_object("/players/saber/fur/couch.c"),this_object());  }

 if(!arg){
  set_light(1);
 short_desc="Guild Chamber";
long_desc=
  "This is a chamber of the guild hall devoted to the lore of\n"+
  "the guilds of Nirvana.  Here you can find information detailing\n"+
  "all of the active guilds.\n"+
  "COMMANDS: list <to list guilds> and read <guild name>\n"+
  "There is a SIGN here that you should read.\n";

items=({
 "hall","You are in the guild hall of Nirvana",
 "floor","The floor is constructed from dark stone",
 "sign","A sign that you should read",
 });

  dest_dir=({
 "/room/adv_guild","west",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("list_guilds","list");
  add_action("read_guilds","read");
}

search() {
 write("You find nothing\n");
 say (tp +" searches the area\n");
 return 1;  }


list_guilds()  {

  write("\n GUILDS OF NIRVANA\n\n"+
  "Bards\n"+
  "Monks\n"+
  "Paladins\n"+
  "Shadows\n"+
  "Undead\n"+
  "Vampires\n"+
  "  \n");
  return 1;
        }


read_guilds(str)  {

  string guild;

if(!str)  {
  list_guilds();
  return 1;
        }

  guild = lower_case(str);

if(guild == "bard" || guild == "bards")  {
  cat("/players/saber/bards/4players");
  return 1;
        }

if(guild == "monk" || guild == "monks")  {
  write("There is no information yet for this guild.\n");
  return 1;
        }

if(guild == "paladin" || guild == "paladins")  {
  write("There is no information yet for this guild.\n");
  return 1;
        }

if(guild == "shadow" || guild == "shadows")  {
  write("There is no information yet for this guild.\n");
  return 1;
        }

if(guild == "undead")  {
  write("There is no information yet for this guild.\n");
  return 1;
        }

if(guild == "vampire" || guild == "vampires")  {
  write("There is no information yet for this guild.\n");
  return 1;
        }

if(guild == "sign")  {
  write(
   "Be warned, all that you read are advertisements for the guilds.\n"+
  "Both players and wizards tend to be loyal to the guilds which they\n"+
  "are members of, so do not completly trust what they say about their\n"+
  "own or any other guild.  *grin*\n"+
  "\n"+
  "Good luck on finding a guild, and may you by happy in it!   ;)  \n"+
  "\n							-- Saber\n");
  return 1;
        }

  write("There is no "+capitalize(str)+" guild.\n");
  return 1;
        }
