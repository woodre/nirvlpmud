#define tp this_player()->query_name()
int COUNT;

id(str)
  { return str == "pool" || str == "water" || str == "unholy water"; }

short() {
  return "A pool of unholy water";
}

long() {
  write("A  pool of unholy water.  You think that if you\n"+
    "<drink> from it, you may feel a lot better.\n"+
     "You can also <fill> a bottle here, and take some unholy\n"+
     "water with you.\n");
}

sip_water(str)  {
  if(str == "water" || str == "pool" || str == "from pool")  {
  if(!str)  write("Drink from what?\n");
  if(this_player()->query_alignment() > 0)  {
  this_player()->heal_self(-25);
  write("You drink from the pool of unholy water.\n"+
       "You feel your head explode with unholy fire.\n");
  return 1;
        }
    if (!call_other(this_player(), "drink_soft", 25))
  return 0;
  if(COUNT < 8)  {
  COUNT = COUNT + 1;
  write("You drink from the pool of unholy water.\n"+
     "You feel the power of Arate fill your body.\n");
  say(tp+" drinks from the pool of unholy water.\n");
 call_other(this_player(), "heal_self", 20);
  return 1;
    }
  write("The pool is low on unholy water right now.\n");
  return 1;
        }
  return 0;
        }

init() {
    add_action("sip_water","drink");
    add_action("fill","fill");
}

get()  { return 0; }
drop()  { return 1; }
query_weight()  { return 100; }

fill(str)  {
object ob;
  if(present("unholy water", this_player()))  {
  write("You already have some unholy water.\n");
  return 1;
        }
  if(COUNT < 8)  {
  COUNT = COUNT + 1;
  ob = clone_object("/players/saber/closed/quest/arate/unholy_water.c");
  move_object(ob, this_player());
  write("You fill a bottle with unholy water.\n");
  say(this_player()->query_name()+" fills a bottle with unholy water.\n");
  return 1;
        }
  write("The pool of unholy water is running low.\n");
  return 1;
        }
