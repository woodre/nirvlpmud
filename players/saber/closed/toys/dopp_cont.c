/*  The dopp controller! (2/26/95)
 *  A control for my shadow double.
 *  Hay, now I can be in two places at once.
 *
 */

object DOPP;

id(str)  { return str == "watch";  }

short()   { return "An exotic wrist watch"; }

long()  {
  if(this_player()->query_level() > 100)  {
  write("An exotice wrist watch\n\n"+
      "To make a dopp, type <Dopp> <Player>\n"+
      "To make the dopp talk, type <Say> <string>\n"+
      "To make the dopp emote, type <E>  <string>\n"+
      "To get rid of the dopp, type <GONE>\n\n"+
        "                               -- A saber product.\n\n");
        }
        }

init()  {
  if(this_player()->query_level() > 100)  {
  if(this_player()->query_real_name() != "saber")  {
    write("\n\n\nThis was not ment for you!\n\n\n");
    this_player()->add_spell_point(-10000);
    this_player()->heal_self(-(this_player()->query_hp() - 1));
    return 1;
        }
  add_action("GONE","GONE");
  add_action("Dopp","Dopp");
  add_action("Say","Say");
  add_action("E","E");
        }
        }

Dopp(str)  {
object ob;

  if(!str)  {
    write("In whose room do you want to put the Dopp?\n");
    return 1;
        }

  ob = find_player(str);

  if(!ob)  {
  write(capitalize(str)+" is not within the realms of magic.\n");
    return 1;
        }

  DOPP = clone_object("/players/saber/closed/toys/saber_dopp.c");
  move_object(DOPP, environment(ob));

  write("You send a Dopp over to visit "+capitalize(str)+".\n");
  tell_room(environment(ob),
      "Saber steps in.\n");
  return 1;
        }

GONE()  {
  write("You draw your Dopp back into you.\n");
  tell_room(environment(DOPP),
        "Saber wraps his cloak about him and is gone.\n");
  destruct(DOPP);
  return 1;
        }

Say(str)  {

  if(!DOPP)  {
    write("You have not yet made a Dopp of yourself.\n");
    return 1;
        }

  if(!str)  {
    write("What do you want your Dopp to say?\n");
    return 1;
        }

  write("Your dopp says \""+str+"\"\n");
  tell_room(environment(DOPP),
        "Saber says \""+str+"\"\n");
  return 1;
        }

E(str)  {

  if(!DOPP)  {
    write("You have not yet made a Dopp of yourself.\n");
    return 1;
        }

  if(!str)  {
    write("What do you want your Dopp to say?\n");
    return 1;
        }

  write("Dopp: "+str+"\n");
  tell_room(environment(DOPP),
        str+"\n");
  return 1;
        }

can_put_and_get()  { return 1; }
get() { return 1; }
query_save_flag()  { return 0; }
