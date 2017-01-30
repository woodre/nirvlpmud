/*
 *  The kender bag!  (version 2.0)
 *  A bag that lets the kender have lots of JUNK to play with!
 *
 */

kender_bag()  {

  object ob;
  if(present("kender_bag", this_player()))  {
    write("You sling your bag back across your shoulder.\n");
    say(this_player()->query_name()+" rearranges "+this_player()->query_possessive()+" pouches.\n");

  ob = present("kender_bag", environment(this_object()));

  destruct(ob);
  return 1;
        }

  move_object(clone_object("/players/saber/closed/new_mini/kenderbag.c"),this_player());
    write("You pull your kender bag off your shoulder and into your hand.\n");
    say(this_player()->query_name()+" rearranges "+this_player()->query_possessive()+" pouches.\n");

  return 1;
        }
