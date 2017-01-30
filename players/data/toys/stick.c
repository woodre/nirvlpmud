 inherit "obj/treasure";
 object ugly;
int i ;
 reset(arg)  {
  if(arg) return;
  set_id("stick");
  set_short("An Ugly Stick");
  set_long("This is an Ugly Stick. When you whack someone with this,\n"+
      "the person will turn UGLY! To use, type WHACK <player>.\n");
  set_weight(1);
  set_value(100);
        }
 init()  {
  ::init();
  add_action("whack","whack");
        }
 whack(str)  {
object whackat;
 string who;
   if(!str) return 0;
  if(str != "")  {
    who = lower_case(str);
    whackat = find_living(who);
    if(whackat && whackat->query_invis() > 19)
    whackat = 0;
    if (whackat && present(whackat, environment(this_player()))) {
    if(present(who, environment(this_player())))  {
      ugly = clone_object("/players/arrina/treas/ugly.c");
      transfer(ugly, whackat);
  say( (this_player()->query_name()) + " whacked " + (whackat->query_name()) +
      " with an Ugly Stick!!\n");
  write("You have whacked "+capitalize(str)+" with an Ugly Stick!\n"+
   "You never noticed how FRIGHTFUL "+str+" was before!\n");
  tell_object(whackat, this_player()->query_name()+ " whacks you with an Ugly Stick!\n"+
  "You are very FRIGHTFUL now!!\n");
  return 1;
        }
  write("No "+str+" here!\n");
  return 1;
        }
  return 0;
        }
  }
