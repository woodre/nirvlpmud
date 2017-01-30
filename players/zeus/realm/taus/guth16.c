inherit "room/room";	/*  guth16.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, guth, clone, max;

reset(arg){

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;
 max = 0;

    if(!present("gurther")){   clone = random(9);   switch(clone){
    case 0..6: break;
    case 7:  MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
    case 8: for(guth = 0; guth < 2; guth++)
              MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
    return 1; }}

 if(arg) return;
 short_desc="The Fallen Lands";
 long_desc=
"You are in a dark part of the forest.  There is however a bit of light\n"+
"making it through the trees.  The path leads to the east and west, and\n"+
"is covered by a layer of brown leaves.  There appears to be no way to\n"+
"deviate from the path.\n";
 set_light(1);
 items=({
  "forest",
"The forest is very dark and dense north and south of the path",
  "trees",
"The towering evergreen and maple trees climb high into the sky",
  "light",
"A small amount of light is filtering through the trees",
  "path",
"The path leads to the east and west through the forest.  It is covered\n"+
"by a layer of brown leaves",
  "leaves",
"The leaves on the path are rather pretty.  Many of them look as though\n"+
"not a living creature has touched them",
 });
 dest_dir=({
   "/players/zeus/realm/taus/circle4.c", "east",
   "/players/zeus/realm/taus/guth15.c", "west",
 });
}

void init(){
  ::init();
    add_action("e_dir", "east");
    add_action("wall_check", "east");
    add_action("w_dir", "west");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow() { return 1; }

set_max(x){ max = x; }

wall_check(){
  /* if wall, prevent more than max players from participating */
  /* this also means no ambushes                     */
  int *x, *c, i, j, total;
  total = 0;
  x =({  "players/zeus/realm/taus/circle1",
         "players/zeus/realm/taus/circle2",
         "players/zeus/realm/taus/circle3",
         "players/zeus/realm/taus/circle4",
         "players/zeus/realm/taus/circle5",
         "players/zeus/realm/taus/circle6",
         "players/zeus/realm/taus/circle7",
         "players/zeus/realm/taus/circle8",
         "players/zeus/realm/taus/circle9",  });
  if(this_player()->is_npc()) return 0;
  if("/players/zeus/realm/taus/circle4.c"->query_wall())
  {
    for(i = 0; i < sizeof(x); i++)
    {
      c = all_inventory(x[i]);
      for(j = 0; j < sizeof(c); j++)
      {
        if(c[j]->is_player())
          total++;   /* count up opponents */
      }
    }
    if(total >= max && random(3)) /* well, almost */
    {
      write("A strong force is stopping you from going east.\n"); 
      return 1;
    }
    else if(total >= max)
    {
      write("As you move east a strong force weakens you.\n");
      this_player()->add_hit_point(-50-random(51)); /* drain for + players */
    }
  }
}

