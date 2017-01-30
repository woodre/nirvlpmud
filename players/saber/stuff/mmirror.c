#define tp this_player()->query_name()
#define TP this_player()

int lastime;
id(str)  { return str == "mirror" || str == "mag_mag_mirror";  }

short()  { return "A magic mirror"; }

long()  {  write(
  "This is a magic mirror of searching.\n"+
  "By typing <search> <player name> you can find <player name>.\n"+
  "\n");  }

get()  { return 0; }

init()  {
  add_action("search_player","search");
        }

search_player(str)  {
object ob;

  if(!str)  {
    write("Who do you wish to search for within the magic mirror?\n");
    return 1;
        }

  write("You gaze into the magic mirror...\n\n");
  say(tp+" gazes into the magic mirror.\n");

  if(ob = present(str, environment(TP)))  {
   if(!ob->query_invis())
    write("The object of your search is within your room...\n");
    else {
    write("There is no soul by the name of "+capitalize(str)+".\n"); }
    return 1;
        }

  if(ob = find_living(str))  {
   if(!ob->query_invis())
  {
  
  if(environment(ob))
    write(capitalize(str)+" can be found in "+call_other(environment(ob),"short")+"'\n");
  else write(capitalize(str)+" is just entering the game.\n");
   }
   else {
     write("There is no soul by the name of "+capitalize(str)+".\n"); }
    return 1;
        }

   if(!ob) {
    write("There is no soul by the name of "+capitalize(str)+".\n");
    return 1;
        }
  return 1;
       }
