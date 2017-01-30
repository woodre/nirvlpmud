/*  The imp controller! (2/13/95)
 *  A control for the nasty little imp...
 *
 */

id(str)  { return str == "remote";  }

short()  { return "An imp remote control";  }

long()  {
  write("A small remote control device.\n\n\n"+
        "To use type <scare> <player name> <how often> <1 or 2>\n"+
        "\nTo call off the imp, type <abscond>\n\n"+
        "                               -- A saber product.\n\n");
        }

init()  {
  if(this_player()->query_level() > 100)  {
  add_action("abscond","abscond");
  add_action("scare","scare");
        }
        }

scare(str)  {
object ob, TO;
string target;
int number, type;

  if(!str)  {
    write("Who do you want to sic the imp on?\n");
    return 1;
        }

  if(sscanf(str, "%s %d %d", target, number, type) !=3)  {
    write("Type scare <player> <number> <1 or 2>\n");
    return 1;
        }

  ob = find_player(target);

  if(!ob)  {
    write("The imp says '"+capitalize(target)+" is not within the realms of magic.'\n");
    return 1;
        }

  if(type == 1)  {
    TO = clone_object("/players/saber/closed/toys/barney.c");  }
  else  {
  TO = clone_object("/players/saber/closed/toys/imp.c");
        }
  move_object(TO, environment(this_player()));

  call_other(TO, "set_master", target);
  call_other(TO, "set_rate", number);
  write("You summon up an monster to scare "+capitalize(target)+".\n");
  tell_object(ob,
        "\nYou suddenly get a very icky feeling...\n");
  return 1;
        }

abscond()  {
object ob;
  ob = find_living("black_imp");
  write("You touch a button and call off the monster.\n");
  call_other(ob, "bye");
  return 1;
        }

can_put_and_get()  { return 1; }
get() { return 1; }
query_save_flag()  { return 0; }
