 inherit "obj/treasure";
 object pretty;
int i ;
 reset(arg)  {
  if(arg) return;
  set_id("paddle");
  set_short("A Pretty Paddle");
  set_long("This is a Pretty Paddle.  When you swat someone with this,\n"+
      "even an ugly person will turn CUTE! To use, type SWAT <player>.\n");
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
    if(present(who, environment(this_player())))  {
      pretty = clone_object("/players/arrina/treas/pretty.c");
      transfer(pretty, swatat);
  say(capitalize(str)+" was swatted with a Pretty Paddle!!\n");
  write(this_player()->query_name()+" has swatted "+swatat->query_name()+"\n"+
   "with a pretty paddle! You never noticed how CUTE "+str+" was before\n");
  tell_object(swatat, this_player()->query_name()+ " swats you with a\n"+
  "pretty paddle. You are very CUTE now!!\n");
  return 1;
        }
  write("No "+str+" here!\n");
  return 1;
        }
  return 0;
        }
