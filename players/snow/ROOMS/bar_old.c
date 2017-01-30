/* CyberNinja Bar 
   Changed this place to use guild credits.
 */
#define GUILD_ID     "guild_implants"

object newspaper, top_list;
object band;


reset(arg)
{
  /* added to allow guild members to write without being pk'd - Dune 8/2002 */
  if (!present("terminal"))
  {
    move_object(clone_object("/players/dune/closed/guild/boards/guildboard.c"),
    this_object());
  }
  if (!top_list || !present(top_list))
  {
    top_list = clone_object("obj/level_list");
    move_object(top_list, this_object());
  }
  if (arg) return;
  set_light( 1);
}


short() { return "The Drowned Rat"; }


init()
{
  add_action("move","surface");
  add_action("order","order");
  add_action("order","buy");
}


move()
{
  this_player()->move_player("cyberwards#players/dune/closed/guild/rooms/teleport");
    return 1;
}


long() {
  write("  You appear to be in the deeps of an ocean. Large, deadly\n"+
        "animals swim in vicious arcs around you. Occasional body\n"+
        "parts float by. The imagery is so fantastic you almost forget\n"+
        "you are in the legendary CyberJoint 'The Drowned Rat'\n"+
        "If you wish to leave you may 'surface' at any time.\n");
  price_list();
  return 1;
}


price_list()
{
  write("\n    Assorted drinks and their prices:\n"+
        "Ale <10>  Wine <150> Vodka <100>  Everclear <230>  Jolt <20>\n");
  write("\n");
  return 1;
}


order(str)
{
  string name, short_desc, mess;
  int value, cost, strength, heal;
  object gob;

  if (!str)
  {
    write("Order what ?\n");
    return 1;
  }
  if (str == "ale")
  {
    mess = "That feels good";
    heal = 1;
    value = 10;
    strength = 3;
  }
  else if (str == "wine")
  {
    mess = "You are filled with sweet warmth";
    heal = 10;
    value = 150;
    strength = 7;
  }
  else if (str == "vodka" || str == "screwdriver")
  {
    mess = "A tingling feeling goes through your body";
    heal = 10;
    value = 100;
    strength = 14;
  }
  else if (str == "everclear" || str == "ec")
  {
    mess = "A shock wave runs through your body";
    heal = 25;
    value = 230;
    strength = 20;
  }
  else if (str == "jolt" || str == "coffee")
  {
    mess = "You feel somewhat invigorated";
    heal = 0;
    value = 20;
    strength = -2;
  }
  else
  {
    write("The bartender says: What do you want?\n");
    return 1;
  }

  gob = present(GUILD_ID, this_player());
  if (!gob)
  {
    write("You are not familiar with the bar's advanced credit system.\n"+
          "Take your ancient tender elsewhere!\n");
    return 1;
  }

  cost = value;
  if (gob->balance() < cost)
  {
    write("That costs " + value + " credits, which you don't have.\n");
    return 1;
  }

  if (strength > (call_other(this_player(), "query_level") + 2))
  {
    if (strength > (call_other(this_player(), "query_level") + 5))
    {
      /* This drink is *much* too strong for the player */
      say(call_other(this_player(), "query_name", 0) + " orders a " +
          str + ", and immediately throws it up.\n");
      write("You order a " + str + ", try to drink it, and throw up.\n");
    }
    else
    {
      say(call_other(this_player(), "query_name", 0) + " orders a " +
          str + ", and spews it all over you!\n");
      write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
    }
    gob->addToBalance(-cost);
    gob->save_me();
    return 1;
  }
  if (!call_other(this_player(), "drink_alcohol", strength))
  {
    write("The bartender says: I think you've had enough.\n");
    say(call_other(this_player(), "query_name", 0) + " asks for a " +
        str + " but the bartender refuses.\n");
    return 1;
  }

  write("You pay " + cost + " credits for a " + str + ".\n");
  say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
  gob->addToBalance(-cost);
  gob->save_me();
  call_other(this_player(), "heal_self", heal);
  write(mess + ".\n");
  return 1;
}


feel() { return "no"; }
