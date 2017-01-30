#include "/players/saber/magic/SPELL.h"
inherit "/players/saber/closed/bards/shapeobj.c";

reset(arg)  {
   if (arg) return;
   set_name("magic card");
   set_alias("card");
   set_short("A Revised Magic Card");
   set_long("A Magic Card from Wizards of the Coast.\n"+
       "The card shows a picture of a lightning bolt.\n"+
       "You might want to read it.\n");
   set_value(0);
        }

read(str)  {
  if(str == "card")  {
  write(
  "\n"+
  "You read the Magic Card.\n\n"+
  "This is a red magic card called Lightning.\n"+
  "\nTo use type <lightning: monster>\n\n");
  write(
       "                                   - A SABER product.\n");
  return 1;
        }
        }

init()  {
  ::init();
   add_action("send","lightning");
   add_action("read","read");
        }

send(str)  {
object ob;
  if(!str)  {
    write("To use type: lightning <monster>\n");
    return 1;
        }
  ob = present(str, environment(this_player()));
  if(!ob)  {
    write("You cannot find "+capitalize(str)+" anywhere.\n");
    return 1;
        }
  if(attack_spell(1,10,ob) == -1) return 0;
  TP->attack_object(ob);
  ob->hit_player(30);
  write("You hold up the magic card and invoke LIGHTNING.\n"+
    ob->query_name()+" is struck by a bolt of blazing lightning.\n");
  say(tp+" holds up a card and invokes lightning.\n"+
    ob->query_name()+" is struck by a bolt of blazing lightning.\n");
  destruct(this_object());
  write("\nThe magic card fades away.\n\n");
  return 1;
        }
