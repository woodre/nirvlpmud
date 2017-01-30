 inherit "obj/treasure";
 object pretty;
int i ;
 reset(arg)  {
  if(arg) return;
  set_id("paddle");
  set_short("A Pretty Paddle");
  set_long("This is a Pretty Paddle.  When you swat someone with this,\n"+
      "even an ugly person will turn CUTE! To use, type SWAT <player>.\n");
 set_weight(1);
 set_value(100);
        }
 init()  {
  ::init();
  add_action("swat","swat");
        }
 swat(str)  {
object swatat;
 string who;
  if(str != "")  {
    who = lower_case(str);
    swatat = find_living(who);
if(swatat && swatat->query_invis() > 19)
     swatat = 0;
    if (swatat && present(swatat, environment(this_player()))) {
    if(present(who, environment(this_player())))  {
      pretty = clone_object("/players/arrina/treas/pretty.c");
      transfer(pretty, swatat);
  say( (this_player()->query_name()) + " swatted " + (swatat->query_name()) +
      " with a Pretty Paddle!!\n");
  write("You have swatted "+capitalize(str)+" with a pretty paddle!\n"+
   "You never noticed how CUTE "+str+" was before!\n");
  tell_object(swatat, this_player()->query_name()+ " swats you with a Pretty Paddle!\n"+
  "You are very CUTE now!!\n");
  return 1;
        }
  write("No "+str+" here!\n");
  return 1;
        }
  return 0;
        }
}
