/* 
 *  The ward chamber of the Bards Guild of Ryllian
 *  v3.0 by Geoffrey Z. / Saber
 *
 */

#define tp this_player()->query_name()

inherit "room/room";

#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

reset(int arg) {  

 if(!present("star"))  {
 move_object(clone_object("/players/saber/closed/bard/mon/star.c"), this_object());  }
 
  if(!arg){

  set_light(1);
  short_desc="Chamber of Wards";
 
  long_desc=
 BOLD+"Chamber of Wards"+NORM+"\n"+
 "The Chamber of Wards is a circular room constructed from a deeply polished\n"+
 "mahogany wood.  In the center of the room rests a deep pool of translucent\n"+
 "crystal water.  Above the pool floats a large "+BLU+"blue crystal"+NORM+", coruscating in\n"+
 "tandem with the "+BLU+"blue force shield"+NORM+" surrounding it.\n";

items=({
 "floor","The floor is smooth and dark, and constructed from beautiful mahogany wood",
 "chamber","You are in the "+BOLD+"Chamber of Wards"+NORM+"",
 "room","You are in the "+BOLD+"Chamber of Wards"+NORM+"",
 "wood","The chamber is constructed entirely from polished mahogany wood",
 "mahogany","The chamber is constructed entirely from polished mahogany wood",
 "light","The room is lit by the dim light of the glowing "+BLU+"blue"+NORM+" crystal",
 "pool","A  pool of translucent crystal water.\n"+
        "You think that you could < drink > from it or < bathe > in it",
 "crystal","A large "+BLU+"blue crystal"+NORM+" coruscting in tandom with the "+BLU+"force shield"+NORM+" surrounding it.\n"+
           "You recognize this as the shieldstone of the Bards, the anchor of the Wards\n"+
           "which protect the guild hall.\n"+
           "If you wish to donate mana towards shield upkeep, type < donate > < amount >",
 "shield","A large "+BLU+"blue crystal"+NORM+" coruscting in tandom with the "+BLU+"force shield"+NORM+" surrounding it.\n"+
          "You recognize this as the shieldstone of the Bards, the anchor of the Wards\n"+
          "which protect the guild hall.\n"+
          "If you wish to donate mana towards shield upkeep, type < donate > < amount >",
 });

  dest_dir=({
 "/players/saber/closed/bard/r/summon.c","east",
 "/players/saber/closed/bard/r/tool.c","south",
           });
  }   }
  
  
init()  {
 ::init();

 if(!present("star"))  {
 move_object(clone_object("/players/saber/closed/bard/mon/star.c"), this_object());  }

if(!present("instrument",this_player()) && this_player()->is_player())  {
  
  write("You get the brief image of a "+BLU+"blue circle"+NORM+" before\n\n"+
        BOLD+" * * * * *  B O O M  * * * * *"+NORM+"\n\n"+
        "Your body flies through space.\n\nYou find yourself somewhere new.\n");
  say(tp+" bounces off the "+BLU+"Circle of Warding"+NORM+".\n");
  move_object(this_player(),"/room/void");
  tell_room(environment(this_player()), tp+" falls screaming from the sky.\nTHUD.\n");
  return 1;
        }

  add_action("search","search");
  add_action("bathe","bathe");
  add_action("sip_water","drink");
  add_action("donate","donate");
       }


search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1; 
       }


sip_water(str)  {
  
  if (!call_other(this_player(), "drink_soft", 25))  return 0;
  
  write("You drink from the translucent crystal water.\n"+
        "Your head feels quite clear.\n");
  say(tp+" drinks from the translucent crystal water.\n");
  call_other(this_player(), "heal_self", 10);
  return 1;
    }


bathe(str)  {
object ob;

  if(!str)  {
  write("You strip off you clothing and step into the translucent crystal water.\n"+
        "The water is plesantly warm, and feels soft against your skin.\n");
  say(tp+" strips off "+this_player()->query_possessive()+" clothing and steps into the translucent crystal water.\n"+
     "A "+BLU+"blue aura"+NORM+" surrounds "+tp+".\n");

  if (!call_other(this_player(), "drink_soft", 25))  return 0;
    else call_other(this_player(), "heal_self", 10);

  return 1;
        }
        
  if(!(ob = present(str, environment(this_player())))) {
    write(capitalize(str)+" is not here to bathe.\n");
    return 1;
        }
        
  write("You pull "+capitalize(str)+" into the water and begin to bathe "+ob->query_objective()+".\n");
  say(tp+" pulls "+ob->query_name()+" into the pool and begins to bathe "+ob->query_objective()+".\n",ob);
  tell_object(ob, tp+" pulls you into the pool and begins to bathe you!\n");
  if(ob->is_player())  {    if (!call_other(this_player(), "drink_soft", 25))  return 0;
    else call_other(this_player(), "heal_self", 10);  }

  return 1;
         }


donate(str)  {
int temp, temp2, temp3;
object ob;

 if(sscanf(str,"%d",temp) !=1)  {
  write("Donate < # >\n");
  return 1;
        }
        
  ob = this_player();
  temp3 = ob->query_sp();
  temp2 = (temp*2);
  if(temp > temp3)  {
  write("You do not have that much mana.\n");
  return 1;
        }
        
  this_player()->add_money(temp2);
  this_player()->add_spell_point(-temp);
  
  write("You donate "+str+" mana towards "+BLU+"shield"+NORM+" upkeep.\n"+
        "Your spirit feels richer.\n");
  say(tp+" concentrates on the "+BLU+"crystal"+NORM+".\n");
  return 1;
        }
