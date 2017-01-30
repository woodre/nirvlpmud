inherit "obj/treasure";

#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

#define ENV environment(this_object())

int first, second;
int health;
int COUNT, WHICH;

reset(arg)  {
  if(arg) return;
    set_id("scroll");
    set_short("An "+HIR+"X"+HIG+"m"+HIR+"a"+HIG+"s"+NORM+" scroll");
    set_long("A fine paper scroll covered with "+HIR+"X"+HIG+"m"+HIR+"a"+
              HIG+"s"+NORM+" runes.\n"+
             "When you read this scroll, you must target a\n"+
             "player who is wearing some sort of boots.  To\n"+
             "use, type < stocking > < player name > \n"); 
    set_weight(0);
    set_value(50);
        }

init()  {
  ::init();
  add_action("illusion_stocking","stocking");
         }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }


illusion_stocking(str)  {
object TARGET, BOOTS;

  if(!str)  {
    write("To cast the illusion, type < stocking > < player name >\n");
    return 1;
         }

  if(!(TARGET = present(str, environment(this_player()))))  {
    write(capitalize(str)+" is not present.\n");
    return 1;
         }

  if(!(BOOTS = present("boots", TARGET)))  {
    write(capitalize(str)+" is not wearing boots.\n");
    return 1;
         }

  BOOTS->set_name("stockings");
  BOOTS->set_short("A pair of "+HIR+"X"+HIG+"m"+HIR+"a"+HIG+"s"+NORM+" stockings");
  BOOTS->set_long("A comfortable pair of holiday "+
                   HIR+"X"+HIG+"m"+HIR+"a"+HIG+"s"+NORM+" stockings.\n");
  
  write("\nYou read the "+HIR+"X"+HIG+"m"+HIR+"a"+HIG+"s"+NORM+" scroll, looking at "+
         capitalize(str)+".\n"+
        capitalize(str)+"'s boots turn into a pair of "+HIR+"X"+HIG+"m"+HIR+"a"+
         HIG+"s"+NORM+" stockings!\n\n");
  say("\n"+this_player()->query_name()+" reads an "+HIR+"X"+HIG+"m"+HIR+"a"+HIG+"s"+
      NORM+" scroll, looking at "+capitalize(str)+".\n"+
         capitalize(str)+"'s boots turn into a pair of "+HIR+"X"+HIG+"m"+HIR+"a"+
         HIG+"s"+NORM+" stockings!\n\n");
  
  destruct(this_object());
  return 1;
          }
