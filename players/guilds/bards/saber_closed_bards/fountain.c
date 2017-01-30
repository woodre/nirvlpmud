#define tp this_player()->query_name()

id(str)
  { return str == "pool" || str == "water"; }

short() {
  return "A pool of water";
}

long() {
  write("A  pool of enchanted water.  You think that if you\n"+
    "<drink> from it, you may feel a lot better.\n"+
    "You also have to the strong desire to <bathe> in it...\n");
}

sip_water(str)  {
  if(str == "water" || str == "pool" ||  str == "from pool")  {
    if (!call_other(this_player(), "drink_soft", 25))
  return 0;
  write("You drink from the pool of magic water.\n"+
    "You feel stronger and your head feels quite clear.\n");
  say(tp+" drink from the magic pool of water.\n");
 call_other(this_player(), "heal_self", 20);
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
  write("You strip off you clothing and step into the pool of water.\n"+
    "The pool is plesantly warm, and it feels really good...\n");
  say(tp+" strips off "+this_player()->query_possessive()+" clothing and steps into the pool.\n"+
    "Say, that looks like fun...\n");
  return 1;
        }
  if(!(ob = find_player(str)))  {
    ob = find_living(str);  }
  if(!present(str, environment(this_player())))  {
  write(capitalize(str)+" is not here to bathe.\n");
  return 1;
        }
  write("You pull "+capitalize(str)+" into the water and begin to bathe "+ob->query_objective()+".\n");
  say(tp+" pulls "+ob->query_name()+" into the pool and begins to bathe "+ob->query_objective()+".\n",ob);
  tell_object(ob, tp+" pulls you into the pool and begins to bathe you!\n");
  return 1;
         }
