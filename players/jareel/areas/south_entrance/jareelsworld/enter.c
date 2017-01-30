inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

  if(!present("sign"))  {
    MOCO("/players/jareel/general_stuff/jareelworldsign.c"),this_object()); }

   if(arg) return;
    set_light(1);
    set_listen(BOLD+"The wind howls over the open area"+NORM+"\n");
    set_smell(BOLD+"The air smells fresh"+NORM+"\n");
      
short_desc=(GRN+"Jareel World"+NORM);
long_desc=
""+BOLD+"\n"+
"         __o__                                                 o    \n"+       
"           |                                                  <|>   \n"+                                                    "          / \\                                                 / \\   \n"+          
"          \\o/    o__ __o/  \\o__ __o    o__  __o    o__  __o   \\o/   \n"+       
"           |    /v     |    |     |>  /v      |>  /v      |>   |    \n"+             
"          < >  />     / \\  / \\   < > />      //  />      //   / \\   \n"+        
"  \\        |   \\      \\o/  \\o/       \\o    o/    \\o    o/     \\o/   \n"+                                                     "   o       o    o      |    |         v\\  /v __o  v\\  /v __o   |    \n"+     
"   <\\__ __/>    <\\__  / \\  / \\         <\\/> __/>   <\\/> __/>  / \\   \n"+      
"\n"+
"\n"+
"        o          o                            o           o       \n"+
"       <|>        <|>                          <|>         <|>      \n"+
"       / \\        / \\                          / \\         < >      \n"+
"       \\o/        \\o/    o__ __o    \\o__ __o   \\o/    o__ __o       \n"+
"        |          |    /V     V\\    |     |>   |    />     |>       \n"+
"       / \\        / \\  />       <\\  / \\   < >  / \\  />     < >      \n"+
"       \\o/   ||   \\o/  \\         /  \\o/        \\o/  \\       |       \n"+
"        |    oo    |    o       o    |          |    o      o       \n"+
"        \\\\__/><\\__//    <\\__ __/>   / \\        / \\   <\\__ __|>      \n"+
""+NORM+HIR+"\n"+
"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"+NORM+BLU+"\n"+
"                              Comming Soon"+NORM+HIR+"\n"+
"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"+NORM+NORM+"\n"+
""+NORM+NORM+"\n";
 
items = ({

  "path","A well traveled dirt road",
  "dirt","The dirt crumbles in your hand as you look at it",
  "prints","Footprints seem to be mostly heading to the north",
  "field","Small blades of grass sway in the breeze",
  "slope","The sloping field is covered with grass, with a path traveling to the north and south",
  "grass","An open field of grass, the blades of green grass sway in the breeze",
  "area","An open field of grass",
  "ground","The ground looks like a small militia has traveled past here",
  "footprints","The prints seem to mostly be heading north, and appear to be made from a soldiers greaves",
  "road","The dirt path has seen much travel, the dirt seems to be packed into a solid mass",

});

dest_dir = ({
"room/lanceroad4","north",
});

}

init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("Search what?\n"); return 1; }
  write("You search the "+str+" but find nothing special.\n");
  say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}
