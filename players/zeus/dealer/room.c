
inherit "room/room";

 reset(arg){

/* Not until changes made to dealer - either MUCH more powerful or coins not stored
  - no longer stores coins 4/10/00 */
   if(!present("man")){
    move_object(clone_object(
      "/players/zeus/dealer/dealer.c"), this_object()); }
/* ;) */

  if(!arg){

  short_desc="A shady place";
  long_desc=
"You are standing in a shady area among the trees.  There is a small\n"+
"dirt path that leads away from here to the north.  There is a simple\n"+
"looking table set up near a few trees in the area, with various beakers\n"+
"and syringes of colorful liquids placed on it.\n";
  items=({
   "trees",
"The thick maple trees are very tall and have many branches.  They\n"+
"are blocking out a good deal of the suns rays, making the whole area\n"+
"comfortably shady",
  "table",
"There is a simple looking table set up near some trees.  It has quite\n"+
"a few beakers and syringes of colorful liquids on it",
  "path",
"The small dirt path leads to the north.  It is very clearly defined\n"+
"among the trees",
  "beakers",
"There are a number of large beakers placed on and beneath the table,\n"+
"each of which is filled with a very bright liquid.  They range from\n"+
"blues to red to yellows",
  "liquids",
"The colorful liquids contained within the beakers look very potent",
  "syringes",
"There are a number of empty syringes scattered across the table.\n"+
"They all look brand new and very clear",
  });
  set_light(1);
  dest_dir=({ "/room/giant_path.c", "north", });
} }
