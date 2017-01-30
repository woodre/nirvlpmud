inherit "/obj/treasure";
string ln,fyl;
int busy,strt,endn;

reset(arg) {
  if(arg) return;
  set_weight(100000000);
  set_value(0);
  set_short("An Information Sign");
  set_id("sign");
  set_long(
"This sign is to give you general information on the updates the the guild.\n"+
"If you have questions, please feel free to post them on the board here.\n"+
"To get the information you can:\n"+
"    info                 Get a broad overview of the new items (start here)\n"+
"    info barbarians      Get a detailed description of the Barbarians\n"+
"    info mystics         Get a detailed description of the Mystics\n"+
/*
"    info chronomancers   Get a detailed description of the Chronomancers\n"+
*/
"    info map             Show a map of Grimm's Maze area\n\n"+
"Again, questions should either be placed here on the board, or to one of\n"+
"the GC's since they have had time to review all of the factions.\n");
}

init() {
  add_action("info","info");
}

info(str) {
  if(busy) {
    write("The sign is in use, one second please.\n");
    return 1;
  }
  busy=1;
   strt=0;
   endn=15;
  if(!str) { gen_info(); return 1; }
  else if(str=="barbarians") { barb_info(); return 1; }
  else if(str=="mystics") { myst_info(); return 1; }
  else if(str=="chronomancers") { chron_info(); return 1; }
  else if(str=="bh") { bh_info(); return 1; }
  else if(str=="mh") { mh_info(); return 1; }
  else if(str=="chron") { com_info(); return 1; }
  else if(str=="map") { map_info(); return 1; }
  else
    write("Examine the sign.\n");
  busy=0;
  return 1;
}

gen_info() {
  fyl = "/players/grimm/factions/dopps";
  more();
  return 1;
}

more() {
  int i;
    for(i=strt+1;i<endn+1;i++) {
      ln=read_file(fyl,i);
      if(!ln) {
        busy=0;
        say(capitalize(this_player()->query_name())+" is done with the sign.\n");
        i=endn+1;
        return 1; }
      else
        write(ln);
    }
    strt=endn;
    endn+=15;
  write("Hit Return to continue...");
  input_to("more");
  return 1;
}

barb_info() {
  fyl = "/players/grimm/factions/barb_info";
  more();
return 1; }

myst_info() {
  fyl = "/players/grimm/factions/myst_info";
  more();
return 1; }

chron_info() {
  fyl = "/players/grimm/factions/chron_info";
  more();
return 1; }

bh_info() {
  fyl = "/players/grimm/factions/barb.help";
  more();
  return 1; }

mh_info() {
  fyl = "/players/grimm/factions/mystic.help";
  more();
  return 1; }

com_info() {
  fyl = "/players/grimm/factions/com.band";
  more();
  return 1; }

map_info() {
  string ln;
  int i;
  i=1;
  ln=read_file("/players/grimm/factions/map",i);
  while(ln) {
    write(ln);
    i++;
    ln=read_file("/players/grimm/factions/map",i);
  }
  busy=0;
  return 1;
}
