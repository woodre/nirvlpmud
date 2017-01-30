inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Tokyo Tower- Obervation Deck>> ";
    long_desc =
    "               Observation Deck <Tokyo Tower>\n"+
    "You are at the observation deck of Tokyo Tower.  From here\n"+
    "you can look <gaze> at anyone in mythos's realm- japan. People \n"+
    "talk quietly amoungst themselves and look at the world from here.\n";
  items = ({
    "up","Up and Up...",
    "down","Down and down..",
  });

  dest_dir = ({
    "/players/mythos/mroom/ttower4.c","down",
    "/players/mythos/mroom/ttower6.c","up",
  });
} }

init() {
  ::init();
  add_action("ggaze","gaze");
}

ggaze(str) {
object name, obs;
int n;
if(!str) return 0;
  name = find_player(str);
  if(!name) { write("That player is not here.\n"); return 1;}
  if(name->query_level() > 20) { write("You may not look at wizes.\n"); return 1;}
  if(name->query_invis()){ write("You cannot find them.\n"); return 1; }
  if(creator(environment(name)) != "mythos") {
    write("That person is not in Mythos' realm.\n");
    write(capitalize(str)+" is in : ");
    write(environment(name)->short()+"\n");
  return 1;}
  write(capitalize(str)+" is in : ");
  write(environment(name)->short()+"\n");
  write("And is carrying the following:\n");
  obs = all_inventory(name);
  for(n = 0; n < sizeof(obs); n++) {
  if(obs[n]->short()) write(obs[n]->short()+"\n");
  }
return 1;}
