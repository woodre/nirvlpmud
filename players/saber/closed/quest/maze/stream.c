#define tp this_player()->query_name()

id(str)
  { return str == "stream" || str == "water"; }

short() {
  return "A stream of dark water running to the east";
}

long() {
  write("A stream of dark water.\n"+
     "You could probably drink from it or bathe in it.\n");
}

sip_water(str)  {
  if(str == "water" || str == "stream" ||  str == "from pool")  {
    if (!call_other(this_player(), "drink_soft", 30))
  return 0;
  write("You drink from the pool of magic water.\n"+
    "You feel stronger and your head feels quite clear.\n");
  say(tp+" drink from the magic pool of water.\n");
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
  write("You strip off you clothing an step into the stream.\n"+
  "The stream is really COLD!!!\n");
  say(tp+" strips of "+this_player()->query_possessive()+" clothing a steps into the stream.\n"+
  "Damn, but that looks cold...\n");
  return 1;
        }
  if(!(ob = find_living(str)))  {
    ob = find_living(str);  }
  if(!present(str, environment(this_player())))  {
  write(capitalize(str)+" is not here to bathe.\n");
  return 1;
        }
  write("You pull "+capitalize(str)+" into the water and begin to bathe "+ob->query_objective()+".\n");
  say(tp+" pulls "+ob->query_name()+" into the water and begins to bathe "+ob->query_objective()+".\n",ob);
  tell_object(ob, tp+" pulls you into the water and begins to bathe you!\n");
  return 1;
         }
