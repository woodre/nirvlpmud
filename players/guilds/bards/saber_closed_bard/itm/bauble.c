/*
 * A small bauble which people can use to peg each other.
 * Bard v3.0
 */

#include "/players/saber/closed/esc2.h"
#define MAG ESC+"[35m"
#define HIB ESC+"[1;34m"
#define NORM ESC+"[2;37;0m"
#define tp this_player()->query_name()

inherit "obj/treasure";

reset(arg)  {
  if (arg) return;
    set_id("bauble");
    set_short("A small "+MAG+"crimson"+NORM+" bauble");
    set_long("A small bauble, glowing with a soft "+MAG+"crimson"+NORM+" light.\n");
    set_weight(0);
        }

init() {
   add_action("peg","peg");
        }

peg(str)  {
object ob;
  
  if(!str)  {
    write("Who do you want to peg?\n");
    return 1;     
          }
          
  ob = present(str,environment(this_player()));
  
  if(!ob)  {
    write("There is no "+str+" here to peg.\n");
    return 1;     
          }
  
  if(present("pro_from_cantrips", ob))  {
    write("You throw a small "+MAG+"crimson"+NORM+" bauble at "+capitalize(str)+".\n");
    say(tp+" throws a small "+MAG+"crimson"+NORM+" bauble at "+capitalize(str)+".\n");
    tell_room(environment(ob),
      "\n"+HIB+"Runes of blue"+NORM+" appear before "+capitalize(str)+".\n"+
      "The bauble fades away into a "+MAG+"purple"+NORM+" haze of light.\n");
    destruct(this_object());
    return 1;
            }
          
  if(this_player()->query_guild_name() == "bards" || 
     this_player()->query_real_name() == "saber")
  {
    write("You bounce a small "+MAG+"crimson"+NORM+" bauble off of "+capitalize(str)+"'s head.\n");
    say(tp+" bounces a small "+MAG+"crimson"+NORM+" bauble off of "+capitalize(str)+"'s head.\n");
    tell_object(ob, "Ouch!\n");
    move_object(this_object(),environment(this_player()));
    return 1;
        }
        }
