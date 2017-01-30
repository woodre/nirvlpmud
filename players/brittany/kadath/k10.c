#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = CYN+"Enchanted Woods"+NORM;
   long_desc =

   "     The steps finally stop at a stone wall.  The wall is covered\n"+
   "with a strange green glow and some markings are engraved into the\n"+
   "wall.  On the wall, under the markings there is a large panel.\n";
   
   items = ({
         "steps","The steps are wide and made of stone",
         "stone wall","The wall is high and covered with a strange\n"+
         "green glow",
         "wall","Solid stone, black and rough from being chipped\n"+
         "away.  It has a natural lime green phosphorous\n"+
         "emiting from it.  A large panel is embedded into it",
         "markings","Markings engraved into the wall, maybe you could 'read' them",
         "glow","A spongy lime green fungus",
         "large panel","A large panel made of steel is embedded into the wall,\n"+
         "maybe you could 'lift' it",
         "panel","A large panel made of steel is embedded into the wall,\n"+
         "maybe you could 'lift' it",
         "panels","There are two buttons marked south and north",
         "buttons","Two round buttons marked south and north",
          });
 
   dest_dir = ({
         "/players/brittany/kadath/k9.c","up",
         });
}

init() {
   ::init();
   add_action("up","up");
   add_action("lift","lift");
   add_action("push","push");
   add_action("read","read");
   add_action("search","search");
}

up(str) {
write("You step onto the bottom steps.  You see the\n"+  
        "steps twist and turn upward out of sight.\n\n");
    say(tpn+"  steps upward out of sight.\n");
   this_player()->move_player("up#/players/brittany/kadath/k9.c");
   return 1;
}

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

read(str) {
    if(!str || str != "markings") {
        notify_fail("What do you want to read?\n");
        return 0; }
    write(
  "The markings read:\n\n"+
  "This is the entrance to the Enchanted Woods.\n");
     return 1;
}

lift(arg) {
  if(!arg) { write("Lift what?\n"); return 1; }
  if(arg !="panel") { write("You can't lift that.\n"); return 1; }
  write("You lift the panel and see two buttons marked south and north.\n"+
  "Push them to enter.\n\n");
  return 1;
}

push(str) {
  if(!str) {
    write("What would you like to push?\n"); return 1; }
  if(str=="panels") {
   write("Please specify 'push south' or 'push north'.\n");
   return 1; }
  if(str=="panel") {
    write("Please specify 'push south' or 'push north'.\n");
    return 1; }
  if(str=="south") {
 say(tpn+"  pushes the south panel.\n");
   this_player()->move_player("south#/players/brittany/kadath/k13.c");
    return 1; }
  if(str=="north") {
 say(tpn+"  pushes the north panel.\n");
   this_player()->move_player("north#/players/brittany/kadath/k11.c");
    return 1; }
  else { write("You can't push that.\n"); }
  return 1;
}
 
