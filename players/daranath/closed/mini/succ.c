/*
 *  The succubus knife of the succubus mini guild (v2.0)
 *
 */

int w;
#include "/players/saber/closed/new_mini/extra.h"
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("knife");
    set_alt_name("succubus knife");
    set_short("A Succubus Knife");
    set_long("A long single edged knife with a wicked point and curved blade.\n"+
       "It is made of a black iron alloy, and covered in silver runes.\n");
   set_read("Type cut <player_name> (must be male) for fun.\n"+
      "This will take 40 spell points.\n");
    set_class(13);
    set_weight(1);
    set_value(1);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   w=random(10);
   if (w>6) {
  write("You stab your opponent and push the blade deep into them.\n");
  say(tp+" stabs "+this_player()->query_possessive()+" opponent and pushes the blade in deep.\n");
      return 4;
    }
}

init() {
  ::init();
add_action("cut", "cut");
}

cut(str) {
string target;
object ob, ob2;

  if(!str)  {
    write("Cut who?\n");
    return 1;
        }

ob = present(str,environment(this_player()));

  if(spell(-3000,1,50) == -1) return 0;

if(ob->query_level() > 21)  {
    write("You wouldn't want to do that.\n");
    return 1;
        }

  if(!ob)  {
    write(capitalize(str)+" is not here.\n");
    return 1;
        }

  if(ob->query_gender() == "creature")  {
    write(capitalize(str)+" is a creature.\n");
    return 1;
        }
  if(ob->query_gender() == "female")  {
    write(capitalize(str)+" is female.\n");
     return 1;
        }

  if(TP->query_gender() != "female")  {
    write("You can't use this knife!\n");
    command("drop knife", this_player());
    destruct(this_object());
    return 1;
        }

  if(present("no_sex", ob))  {
    write(ob->query_name()+" has already had his balls cut off.\n");
    return 1;
        }

 write("You reach over and grab "+CAP+"'s balls and flurish your knife.\n"+
    "You lower the knife and quickly cut "+CAP+"'s balls off.\n");
 say(tp+" reaches over and grabs "+CAP+" by the balls.\n"+
    capitalize(TP->query_pronoun())+" cuts off "+CAP+"'s balls and holds them up for all to see.\n");
 tell_object(ob, "\nOuch ouch ouch ouch ouch ouch....\n");

  move_object(clone_object("/players/saber/food/balls.c"),TP);
  move_object(clone_object("/players/saber/closed/new_mini/no_sex.c"),ob);

  ob2 = present("balls",TP);

 call_other(TP, "add_spell_point", -50);
 call_other(ob2, "set_short","The balls of "+ob->query_name()+" <bloody>");
 call_other(ob2, "set_long","The balls of "+ob->query_name()+" <bloody>\n"+
 "You think that if your balls have been cut off, you could <fix_balls>\n");
return 1;  }
