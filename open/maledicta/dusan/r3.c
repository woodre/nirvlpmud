/* A pillar blocks the way to the south, and if you look at it you find out that you can
   climb over it. The first time someone does so a small beast will jump out and prevent
   anyone from exiting the room, it is aggro. */
#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int secret_att;


reset(arg) {
  
  if(arg) return;
set_secret_att(0);  
set_light(0);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   Here the hallway continues to the east.  The roof is partially\n"+
"intact, throwing the room into deep shadows.  To the south you see\n"+
"an archway, partially blocked by a fallen pillar.  To the north is\n"+
"a small room, its walls lit by some flickering source of light. To\n"+
"the west is a hallway leading back to the entry hall.\n";

items = ({
  "roof",
  "You see that it has been spared somewhat from the ravages that\n"+
  "the entrance endured, although it is still quite blackened and\n"+
  "cracked",
  "archway",
  "Broken and blackened, it leads into a small room that is too\n"+
  "dark to see into",
  "pillar",
  "It seems to have been knocked over from the main hallway. Perhaps\n"+
  "you could climb over it?",
  "light",
  "You're not sure what it is from here",
  "shadows",
  "They are deep, foreboding, and nearly impenetrable. Seemingly at\n"+
  "home in this cursed place",
  "walls",
  "They seem to be beaten and cracked in numerous places, signs that\n"+
  "something powerful was here"
  });

dest_dir = ({
  "/players/maledicta/ruins/rooms/r2.c","west",
  "/players/maledicta/ruins/rooms/r4.c","north",
  "/players/maledicta/ruins/rooms/r6.c","east",
});

}

set_secret_att(int n){  secret_att=n;}
query_secret_att(){ return secret_att; }
   init(){
    ::init();
    
   add_action("climb_pillar", "climb");
   
}

climb_pillar(string str){
	object darkling;
	if(str == "pillar"){
         write("You climb the crumbled pillar....\n");
          if(query_secret_att() == 0){
          write("Suddenly a dark blur hurtles over the fallen pillar\n");
          write("crashing into you!  You feel long fangs sink into\n");
          write("your flesh and then the weight of the creature lifts\n");
          write("as it lightly settles back on the floor.\n");
          write(""+BOLD+""+BLK+"Darkling"+NORM+" watches you carefully.\n");
          
          darkling = clone_object("/players/maledicta/ruins/mobs/darkling.c");
          this_player()->hit_player(10);
          darkling->attack_object(this_player());
          
      /* clone a creature to the room that blocks most exits and is aggro. Only happens
         once, sets secret_att to 1 and checks it */ 
          move_object(darkling, this_object());
          set_secret_att(1);
          return 1;
          } 
          say(tpn+" climbs the pillar.\n");
          move_object(tp, "/players/maledicta/ruins/rooms/r5.c");
          tell_room(environment(tp), tpn+" arrives.\n", ({tp}));
          command("look", tp);
          return 1;
          } 
      return 1;
     }   
     
          	