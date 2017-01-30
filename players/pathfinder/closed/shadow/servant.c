inherit "/obj/monster.c";

object master;
string controller;
int follow;

set_owner(str) { controller = str; }
query_owner() { return controller; }

reset(arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("servant");
  set_short("A Shadow Servant");
  set_long(
    "You peer into the darkness and faintly make out a shape that\n"+
    "looks semi-human but extremely terrifying.  You can see it obediently waiting\n"+
    "upon the commands of its master.\n");
  set_hp(130);
  set_wc(13);
  set_ac(6);
  set_level(7);
  set_alignment(0);
  follow = 1;
  call_out("goto_master", 5);
}
 /* The movement for the servant is delayed, even without lag to give */
 /* the feeling of the player being followed */

goto_master()
{
  call_out("goto_master", 5);

 /* If there is no object set up for the monsters master, make one */
 /* If the player is not on anymore, then destruct the servant */
  if(!master)
  {
    master = find_player(controller);
    if(!master)
    {
      say("You see the shadow servant give up all hope for finding its\n");
      say("master as it fades into the shadows.\n");
      remove_call_out("goto_master");
      destruct(this_object());
      return 1;
    }
    }
   if((!present(controller, environment(this_object()))) &&
     (environment(find_living(controller))->query_realm() != "NT") &&
     follow)
  {
    master = find_player(controller);

    if(!master)
    {
      say("My master has left, now I shall leave to search for\n");
      say("them.\n");
      destruct(this_object());
      return 1;
    }

    say("You see the shadow servant fade into the shadows...\n");
    move_object(this_object(), environment(master));
    say("You see the shadow servant materialize out of the shadows.\n");
    return 1;
  }
  else
  {
    say("You see the shadow servant obediantly awaiting their masters\n");
    say("return.\n");
    return 1;
  }
  return 1;
}


init()
{
  add_action("attack_something", "combat");
  add_action("do_follow", "fol");
  add_action("kamikaze", "kamikaze");
  add_action("set_my_name", "nameser");
}

do_follow()
{
  if(this_player() != master)
  {
    write("The servant hisses at you: 'You are not my master'.\n");
    return 1;
  }
  follow = 1;
  write("The servant whispers to you: I am now following you.\n");
  return 1;
}

 /* let the servant be able to attack something... but no players */

attack_something(str)
{
  object whom;

  if(!str)
  {
    write("The servant hisses at you:  I cannot attack nothing.\n");
    return 1;
  }

  if(!present(str, environment(this_object())))
  {
    write(capitalize(str) + " is not present master.\n");
    return 1;
  }

  whom = present(str, environment(this_object()));

  if(!whom->query_npc())
  {
    write("Your servant hisses: I cannot attack a player.\n");
    return 1;
  }

  this_object()->attack_object(whom);
  whom->attacked_by(this_object());
  say("You see a shadow servant plunge into combat with " + str + ".\n");
  write("You command your servant to attack.\n");
  return 1;
}

 /* lets the player change the servants name/title */


kamikaze(str)
{
  object whom;

  if(!str && !this_object()->query_attack())
  {
    write("Who do you want me to kamikaze into?\n");
    return 1;
  }

  whom = present(str, environment(this_object()));

  if(!whom)
  {
    write(capitalize(str) + " is not present.\n");
    return 1;
  }

  if(!whom->query_npc())
  {
    write("I cannot kamikaze a player.\n");
    return 1;
  }

  this_object()->spell_object(whom, "kamikaze", 50, 0);
  say("You see the shadow servant plunge into " + whom->query_real_name() +
      "'s shadow, never to return.\n");
  write("You command your shadow servant to kamikaze " +
        whom->query_real_name() + ".\n");
  return 1;
}
