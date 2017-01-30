#include "/players/dune/closed/guild/DEFS.h"
inherit "room/room";


string player1_name, player2_name;
object player1, player2;

init() {
  add_action("revive","revive");
  if(TP->query_level() >= 20) {
    add_action("match", "match");
    add_action("query", "st");
  }
  TP->set_fight_area();
  ::init();
  }

reset(arg){
  if(!arg){
  set_light(1);
  short_desc="The Guild Arena";
  long_desc=
"     You are in a large metallic dome.  At one end rests the giant\n"+
"statue of a kneeling ninja.  Its head reaches to the ceiling.\n"+
"A wide flat field stretches for hundreds of yards all around you.\n"+
"Overhead, a reader board hovers in mid-air.\n";

  if(TP->query_level() >= 20)
  long_desc +=
"     As a wizard, you may obtain status info on the match.\n"+
"To set up this room to analyze the stats of two combating players,\n"+
"type     'match <player1> <player2>'\n"+
"When the two players are fighting, to obtain status info about them,\n"+
"type     'st'\n";

  items=({
"statue", "The black statue is a huge replica of an ancient ninja warrior",
"field","The field is of a hard synthetic surface",
"board","You read the digital display:\n"+
"If you die, type 'revive' to come back to life. If you wish to leave\n"+
"the Guild Arena, type 'leave' to return to the arenalounge",
"dome","Neon lights suspend from the metal dome ceiling",
  });

  dest_dir=({
      });
  }
}

revive() {
  if(this_player()->query_ghost()) {
    if(TP->query_pl_k()) {
      TP->remove_ghost();
      write("Your player killing has been set.\n");
      TP->set_pl_k();
    }
    else TP->remove_ghost();
    write("Your systems draw from backup power supplies.\n");
    write("Your body quivers with life again.\n");
    TP->save_me();
  }
  return 1; 
}


match(string str) {
  string p1, p2;
  object p1ob, p2ob;
  if(!sscanf(str, "%s %s", p1, p2)) {
    write("Usage: match <player1> <player2>\n");  }
  if( !((p1ob = present(p1, this_object())) && 
  (p2ob = present(p2, this_object()))) ) {
    write(p1 + " and/or " + p2 + " are not in this room.\n");
    return 1;
  }
  player1 = p1ob;
  player1_name = capitalize(p1);
  player2 = p2ob; 
  player2_name = capitalize(p2);
  write("Match with " + p1 + " versus " + p2 + " is set.\n"+
        "When combat starts, type 'st' to view stats.\n");
  return 1;
}


query() {
  int hp1, hp2, sp1, sp2;
  hp1 = player1->query_hp();
  hp2 = player1->query_spell_point();
  sp1 = player2->query_hp();
  sp2 = player2->query_spell_point();

  write(
  pad(player1_name, 15) + "HP: " + pad(hp1, 5) + ", SP: " + pad(sp1, 5) +
  "\n" +
  pad(player2_name, 15) + "HP: " + pad(hp2, 5) + ", SP: " + pad(sp2, 5) +
  "\n");
  return 1;
}


realm() { return "NT"; }
int is_guild_arena() { return 1; }
query_spar_area() { return 1; }
feel() { return "no"; }
