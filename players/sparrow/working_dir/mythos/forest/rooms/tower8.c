#include "/players/mythos/closed/guild/def.h"
int circle_book;
inherit "room/room";
reset(arg) {
circle_book = 0;
  if(!arg) {
  set_light(0);
    short_desc = "Forbidden Castle Observatory";
    long_desc =
    "You have entered the observatory.  Above you can see the stars\n"+
    "Below you can see the world.  Everything is at peace here.  \n"+
    "Underneith your feet is a large circle of power...\n"+
    "To see where others are 'view <name>'\n";
  items = ({
    "down","You may leave the observatory",
    "circle","Inscribed are the words: Open at the lowest strength",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/tower7.c", "down",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
    if(pp){ pp->set_switch(0); }
    add_action("uuse","view");
    add_action("ddown","down");
    add_action("open","open");
}

uuse(str) {
object name, obs;
int n;
if(!str) return 0;
  name = find_player(str);
  if(!name) { write("That player is not here.\n"); return 1;}
  if(name->query_invis() > 19) { write("That player is not here.\n"); return 1; }
  write(capitalize(str)+" is in : ");
  write(environment(name)->short()+"\n");
  environment(name)->long();
  obs = all_inventory(environment(name));
  for(n = 0; n < sizeof(obs); n++) {
  if(obs[n]->short()) write(obs[n]->short()+"\n");
  }
return 1;}

ddown() {
if(pp){ pp->set_switch(1); }
}

open() {
object tome;
  if(tp->query_sp() < 5 && present("key_myrax",tp) && !circle_book) {
    write("Suddenly, a Large Gate appears before you!\n");
    write("The Ebon Key vanishes!\n");
    write("A black book appears in your hands and the Gate vanishes!\n");
    tome = clone_object("/players/mythos/closed/guild/books/book.c");
    tome->set_cond(0);
    tome->set_title("myrax");
    tome->set_last(2);
    tome->set_not(0);
    move_object(tome,tp);
    circle_book = 1;
  return 1;}
return 0;}
    
