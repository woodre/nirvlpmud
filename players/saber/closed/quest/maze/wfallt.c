#define tp this_player()->query_name()

id(str)
  { return str == "waterfall" || str == "water"; }

short() {
  return "The top of a towering waterfall";
}

long() {
  write("The top of a towering waterfall.\n"+
     "If you're careful you could drink from it or bathe in it.\n");
}

sip_water(str)  {
  if(str == "water" || str == "waterfall" ||  str == "from waterfall")  {
    if (!call_other(this_player(), "drink_soft", 30))
  return 0;
  write("You drink form the waterfall.\n"+
    "You feel stronger and your head feels quite clear.\n");
  say(tp+" drinks from the waterfall.\n");
 call_other(this_player(), "heal_self", 10);
  return 1;
    }
  return 0;
        }

init() {
    add_action("sip_water","drink");
    add_action("bathe","bathe");
}

get()  { return 0; }
drop()  { return 1; }
query_weight()  { return 100; }

bathe(str)  {
object ob;
  if(!str)  {
  write("You strip off you clothing an step into the waterfall.\n"+
  "This is really damn COLD!!!\n");
  say(tp+" strips of "+this_player()->query_possessive()+" clothing a steps into the waterfall.\n"+
  "Damn, but that looks cold...\n");
  return 1;
        }
  if(!(ob = find_living(str))) return 0;
  if(!present(str, environment(this_player())))  {
  write(capitalize(str)+" is not here to bathe.\n");
  return 1;
        }
  write("You pull "+capitalize(str)+" into the water and begin to bathe "+ob->query_objective()+".\n");
  say(tp+" pulls "+ob->query_name()+" into the water and begins to bathe "+ob->query_objective()+".\n",ob);
  tell_object(ob, tp+" pulls you into the water and begins to bathe you!\n");
  return 1;
         }
