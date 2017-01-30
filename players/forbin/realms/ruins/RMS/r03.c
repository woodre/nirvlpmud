/* A pillar blocks the way to the south, and if you look at it you find out that you can
   climb over it. The first time someone does so a small beast will jump out and prevent
   anyone from exiting the room, it is aggro. */
#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";


int secret_att;


reset(arg) {
  
  if(arg) return;
set_secret_att(0);  
set_light(-1);

short_desc = RUINS;
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
  RMS+"r02.c","west",
  RMS+"r04.c","north",
  RMS+"r06.c","east",
});

}

query_ruinsroom() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ruinsroom() && this_player()->query_level() < 40) return HIW+RUINS+NORM; 
      else { 
        sh = HIW+short_desc+" ["+NORM;
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += HIW+"]";
        return sh+NORM; 
      }
    }
    else return HIW+RUINS+NORM;   
  }
  else return "Dark room";     
}

set_secret_att(int n){  secret_att=n;}
query_secret_att(){ return secret_att; }

init()
{
  ::init();
  add_action("climb_pillar", "climb");
}

climb_pillar(string str)
{
  object darkling;
  if(str == "pillar")
  {
    write("You climb the crumbled pillar....\n");
    if(query_secret_att() == 0)
    {
      write("Suddenly a dark blur hurtles over the fallen pillar\n");
      write("crashing into you!  You feel long fangs sink into\n");
      write("your flesh and then the weight of the creature lifts\n");
      write("as it lightly settles back on the floor.\n");
      write(""+BOLD+""+BLK+"Darkling"+NORM+" watches you carefully.\n");
          
      darkling = clone_object(NPC+"darkling.c");
      this_player()->hit_player(10);
      darkling->attack_object(this_player());
          
      /* clone a creature to the room that blocks most exits and is aggro. Only happens
         once, sets secret_att to 1 and checks it */ 
      move_object(darkling, this_object());
      set_secret_att(1);
        return 1;
    } 
    say(TPN+" climbs the pillar.\n");
    move_object(TP, RMS+"r05.c");
    tell_room(environment(TP), TPN+" arrives.\n", ({TP}));
    command("look", TP);
      return 1;
  } 
    return 1;
}   
     
            