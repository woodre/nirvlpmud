#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

int berry;
realm() { return "NT"; }
reset(arg) {
   berry = 0;
   if(!present("handy"))  {
      if(random(10) > 6) {
         move_object(clone_object("/players/puppy/s/mob/handy.c"),this_object()); }}
   if(arg) return;
   
   set_long(
      "A table full of tools rests against the side of the hill.  Many\n"+
      "of Handy Smurf's creations rest off to the side.  Unfinished\n"+
      "pieces are stacked next to a row of blue berry bushes.  A\n"+
      "list of to-do items has fallen off the workbench.\n");
   set_light(1);
   add_listen("main", "You hear Handy Smurf tinkering with his tools.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "table", "A wooden table covered with tools and sawdust",
         "tools", "The instruments that Handy uses to create things with", 
         "hill", "The land that sloped down into this area",
         "creations", "Items that Handy Smurf has crafted",
         "bushes", "A row of blue berry bushes that seem ripe",
         "berry bushes", "A row of blue berry bushes that seem ripe",
         "blue berry bushes", "A row of blue berry bushes that seem ripe",
         "unfinished pieces", "Items that still need some work",
         "pieces", "Items that still need some work",
         "list", "A list of future creations that the Smurfs would like to see",
         "workbench", "A bench carved out of a log.  It has something underneath it"});
   dest_dir = ({
         "/players/puppy/s/rm/10.c", "north",
         "/players/puppy/s/rm/3.c", "south",
         "/players/puppy/s/rm/17.c", "hut"});
   
}
init(){
   ::init();
   add_action("search_bush","search");
   add_action("list", "read");
}

list(str){
   if(str == "list"){
      write("You do not know how to read Smurfish.\n");
      return 1; }
}

search_bush(str){
   if(berry >=1){
      write("You search the bushes, but find nothing.\n");
      return 1; }
   
   if(str == "bushes" || str == "bush" || str == "blue berry bushes"){
      write("You find a handful of blue berries!\n");
      say(this_player()->query_name()+" finds a handful of blue berries in the bushes.\n");
      move_object(clone_object("/players/puppy/s/heal/berries.c"),this_player());
      berry +=1;
      return 1; }
}
short() { int a; a = random(3);
   if (a==0) return ""+HIB+"Smurfville"+NORM+" [n,s,hut]";
   if (a==1) return ""+BLU+"Smurfville"+NORM+" [n,s,hut]";
   if (a==2) return ""+CYN+"Smurfville"+NORM+" [n,s,hut]";
}
