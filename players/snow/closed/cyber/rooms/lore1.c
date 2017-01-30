inherit "room/room";
#define TE tell_object

string lore, writingnotes, title;

init() {
 add_action("info_lore","lore");
 add_action("list_lore","list");
 if(present("implants", this_player()))
   if(present("implants", this_player())->loremaster() ||
      this_player()->query_real_name() == "dune"       ||
      this_player()->query_real_name() == "snow" )
     add_action("new_lore","new_lore");
 ::init();
}

reset(arg){
 if(!arg){
 set_light(1);
 short_desc="The CyberNinja Lore Hall";
 long_desc=
"     A richly decorated building with one main hallway\n"+
"opens before you and to the south.  Large panels of\n"+
"paintings hang upon both of the side walls.  They depict\n"+
"great historic scenes.  A golden plaque below each describes\n"+
"the accompanying event.  Type 'list' to see all the topics\n"+
"available.  If you want to look at these panels, why don't you\n"+
"try 'lore <topic>'.\n"+
"Two small doors lie in the east and west side wall.\n"+
"There are engravings upon each of them.\n";

items=({
 "hallway", "The long hallway is carpeted and lit with golden light",
 "panels","The panels stretch nearly from ceiling to floor",
 "paintings","The paintings are all in unknown colorful oils",
 "plaque","There are many golden plaques, each with history upon them",
 "plaques","The plaques contain the lore of the CyberNinja",
 "doors","The two doors are made of thick wood",
 "engravings","Which of the engravings, west engraving or east engraving?",
 "west engraving","It says, 'Office of the Sensei'",
 "east engraving","It says, 'Office of the Shogun'",
 });

  dest_dir=({
 "/players/dune/closed/guild/rooms/hallway2.c","north",
 "/players/dune/closed/guild/rooms/shogun.c","east",
 "/players/dune/closed/guild/rooms/lore2.c","south",
 "/players/dune/closed/guild/rooms/sensei.c","west",
      });
  }   }

info_lore(string str) {
/* takes str and refers to files in lore 1 or 2 directory */
  string file, topic, all;
  if(!str) {
    write("Usage: lore <topic>\n");
    return 1; }
  file = "/players/dune/closed/guild/lore1/" + str;
  if (file_size(file) >= 0) {
     call_other("/players/dune/closed/guild/_more.c",
                "more_file", file);
     say(capitalize(this_player()->query_name())+
         " studies some CyberNinja lore.\n");
     return 1; }
  else write("There is no such lore topic.\n");
  return 1;
}

list_lore() {
  write("Lore topics:\n");
  ls("/players/dune/closed/guild/lore1");
  return 1;
}

new_lore(string input_title) {
  string file;
  if(!input_title) {
    write("Usage: new_lore <title>\n");
    write("You must enter a title.\n");
    return 1; }
  file = "/players/dune/closed/guild/lore1/" + input_title;
  if (file_size(file) >= 0) {
    write("That topic already exists.  Consult an Emperor\n"+
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

get_lore(string str) {
  if (str == "~q") {
    write("aborted.\n");
    return 1; }
  if (str=="**") {
    write("Ok.\n");
    lore = writingnotes;
    write_file("/players/dune/closed/guild/lore1/"+title, lore+"\n");
    return; }
  writingnotes = writingnotes + str + "\n";
  input_to("get_lore");
}
