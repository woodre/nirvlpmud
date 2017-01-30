/*
 *  A paint ball gun made by Saber.
 *
 */

inherit "obj/weapon";
#include "/players/saber/closed/ansi.h"

object streamer;
int i, charges;

reset(arg)  {
  charges = 24;
  if(arg) return;
  set_name("paintball gun");
  set_alias("gun");
  set_short("A fully automatic paintball gun");
  set_long("A fully automatic paintball gun.\n"+
        "It is chrome metal black, and has a LED light display.\n"+
        "Type < splat > < player > to hit a player.\n"+
        "Type < ammo  > to check your ammunition.\n"+
        "Type < reload > to reload with a clip.\n");
  set_class(12);
  set_weight(1);
  set_value(200);
        }

init()  {
  ::init();
  add_action("splat","splat");
  add_action("ammo","ammo");
  add_action("reload","reload");
  add_action("wizload","wizload");
        }

ammo()  {
  write("The LED light displays the number "+charges+".\n");
  return 1;
        }

reload()  {
object ob;
  if(!(ob = present("paintball clip", this_player())))  {
    write("What are you going to reload the gun with?\n");
    return 1;
        }
  charges = 24;
  write("You slam a clip into the fully automatic paintball gun.\n"+
      "The LED light displays the number 24.\n");
  say(this_player()->query_name()+" slams a new clip into "+this_player()->query_possessive()+" paintball gun.\n");
  destruct(ob);
  return 1;
        }

wizload()  {
  if(this_player()->query_level() > 20)  {
  charges = 24;
  write("You create a new clip and slam it into the paintball gun.\n"+
        "The LED light displays the number 24.\n");
  say(this_player()->query_name()+" slams a new clip into "+this_player()->query_possessive()+" paintball gun.\n");
  return 1;
        }
        }

splat(str)  {
object popat;
string who, color, splat1, splat2, splat3, splat4, splat5;
string mess;
int x, z;

  color = HIR+"M"+HIG+"U"+HIY+"L"+HIB+"T"+HIM+"I"+HIC+"C"+HIR+"O"+HIG+"L"+HIY+"O"+HIB+"R"+HIM+"E"+HIC+"D"+NORM;
  splat1 = HIR+"S"+HIG+"P"+HIY+"L"+HIB+"A"+HIM+"T"+NORM;
  splat2 = HIM+"S"+HIB+"P"+HIY+"L"+HIG+"A"+HIR+"T"+NORM;
  splat3 = HIM+"S"+HIC+"P"+HIR+"L"+HIG+"A"+HIY+"T"+NORM;
  splat4 = HIG+"S"+HIB+"P"+HIC+"L"+HIR+"A"+HIM+"T"+NORM;
  splat5 = HIC+"S"+HIB+"P"+HIM+"L"+HIG+"A"+HIR+"T"+NORM;

  if(!str)  {  write("Type <splat> <player> to use.\n");  return 1; }

  if(charges < 1)  {
    say(this_player()->query_name()+" fires "+
      this_player()->query_possessive()+" paint ball gun at "+capitalize(str)+".\n"+
      "click.\nclick.\nclick.\n");
    write("You fire at "+capitalize(str)+".\n"+
      "click.\nclick.\nclick.\n");
    write("You need to reload the gun.\n");
    return 1;
        }

    who = lower_case(str);
    popat = find_living(who);

  if(!popat || !present(who, environment(this_player()))) {
    write(capitalize(str)+" is not here to splatter.\n");
    return 1;
        }

  write("You blast "+capitalize(str)+" with a barrage of "+color+" paintballs.\n");
  say(this_player()->query_name()+" blasts "+capitalize(str)+" with a barrage of "+color+" paintballs.\n",popat);
  tell_object(popat, this_player()->query_name()+" blasts you with a barrage of "+color+" paintballs.\n");

  z = 0;  i = 0;
  z = random(4) + 1;

  while(i < z)  {
    i++;
    charges = charges - 1;
    x = random(5);
    if(x == 0)  mess = splat1;
    if(x == 1)  mess = splat2;
    if(x == 2)  mess = splat3;
    if(x == 3)  mess = splat4;
    if(x == 4)  mess = splat5;

    if(popat) if(environment(popat))
    tell_room(environment(popat), "  < < < "+mess+" > > >\n");

    if(!present("smear", popat))  {
      streamer = clone_object("/players/saber/stuff/smear.c");
      transfer(streamer, popat);
        }
        }
  return 1;
        }
