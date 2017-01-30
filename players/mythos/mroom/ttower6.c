inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!present("sniper")) {
    move_object(clone_object("/players/mythos/mmon/sniper.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Tokyo Tower- Special Obervation Deck>> ";
    long_desc =
    "                Special Observation Deck\n"+
    "The Special Observation Deck of Tokyo Tower.  From here you can \n"+
    "'spy' on anyone.  People are gathered together and talk quietly as\n"+
    "they look down upon the world.  You hear stories of hauntings here\n"+
    "and of black deeds being done from here.\n";
  items = ({
    "down","Down and down..",
  });

  dest_dir = ({
    "/players/mythos/mroom/ttower5.c","down",
  });
} }

init() { 
  ::init();
  add_action("sspy","spy");
}

sspy(str) {
object name, obs;
int n;
if(!str) return 0;
  name = find_player(str);
  if(!name) { write("That player is not here.\n"); return 1;}
  /* Needs a check for invisibility. -Feldegast 2/20/01 */
  if(name->query_invis()) { write("That player is not here.\n"); return 1;}
  /* Needs a check for wizards too. -Feld */
  if(name->query_level() > 20) { write("You can't spy on wizards.\n"); return 1; }
  write(capitalize(str)+" is in : ");
  write(environment(name)->short()+"\n");
  environment(name)->long();
  obs = all_inventory(environment(name));
  for(n = 0; n < sizeof(obs); n++) {
  if(obs[n]->short()) write(obs[n]->short()+"\n");
  }
return 1;}

