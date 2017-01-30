/* manager.c: squirrel manager for apr 1 fun */
/* woot actually using my lib stuff */
#define get_file_list(a) ("/players/wizardchild/lib/get_files"->get_files(a))
#define fix_time(a) ("/players/wizardchild/lib/format_time"->format_time(a))
#define SQUIRREL "/players/wizardchild/fools/sqrlmod.c"
#define HOME "/players/wizardchild/workroom"
/* start and end of april fools */
#define DEBUG
#define START 891410400
#define END   891496800

#define WAIT_TIME 180   /* monitor pop every 4 minutes */
#undef DEBUG /* no longer testing, should be ok */

int pop_size,num_cloned;
object *population; /* woah nellie this is gonna suck */
string *locations;  /* this is about 129 strings */
string *msgs, *froth_msgs, *shorts;

/* atmosphere stuff */
short() { 
  return "A squirrel manager ("+(pop_size > 0 ? "active" : "idle")+")"; 
}
id(str) { 
  return str == "squirrel manager" || str == "manager" || str == "squirrel";
}
long() {
  write("Squirrel Manager 98, by Wizardchild (all lefts reserved)\n");
  write("--------------------------------------------------------\n");
  write("There is a current population of "+pop_size+" squirrels.\n");
  write("In addition, there are "+sizeof(locations)+" rooms in memory.\n");
  write("In total, "+num_cloned+" squirrels have been generated, and\n");
  if(time() < START)
    write("the time until starting is "+format_time(START-time())+".\n");
  else
    write("the time until ending is "+format_time(END-time())+".\n");
  write("The population manager will execute in "+find_call_out("monitor_population")+" seconds.\n");
  write("Type \"flush_pop\" to kill all the cute little squirrels.\n");
  write("Type \"start_pop\" to force a squirrel spawn.\n");
}
init() { 
  if(this_player()->query_level() >= 21)
    {add_action("flush_pop","flush_pop"); add_action("start_population","start_pop"); }
}
flush_pop() {
  int i,so;
  write("Murdering all the innocent little squirrels...");
  for(i = 0, so = sizeof(population); i < so; i++)
  {
    if(population[i]) {
      destruct(population[i]); pop_size--;
    }
      population -= ({ population[i] });
    i--; so--;
  }
  write("done.\nHave a happy day, you sadist.\n");
  return 1;
}
format_time(a) {
  return fix_time(a);
}
/* i'm using the reset cycles to monitor the lifetime
 * of this thing. the idea is it will start after midnight
 * and kill itself at least 24 hours later
 */

remove_population() { flush_pop(); }
reset(arg) {
  string a, b;
  if(time() >= START && time() < END)
  if(!present("sign",find_object("/room/church"))) 
    move_object(clone_object("/players/wizardchild/fools/sign"),"/room/church");
  if(time() >= END) {
    remove_population();
    destruct(this_object());
  }
  move_object(this_object(),HOME);
  if(sizeof(locations) == 0)
#ifdef DEBUG
    locations = ({"/players/bern/newbie/entrance.c",
                  "/players/bern/newbie/house.c",
                  "/players/bern/newbie/path1.c",
                  "/players/bern/newbie/path2.c",
                  "/players/bern/newbie/path3.c",
                  "/players/bern/newbie/path4.c",
                  "/players/bern/newbie/path5.c",
                  "/players/bern/newbie/path6.c",
                  "/players/bern/newbie/road1.c",
                  "/players/bern/newbie/road2.c",
"/players/wizardchild/workroom",
                  "/players/bern/newbie/road3.c" });
#else
    locations = get_file_list("/room/*.c");
#endif
#ifndef DEBUG
  if(time() >= START) {
#else
{
#endif
    if(pop_size == 0)
      call_out("start_population",2);
    if(find_call_out("monitor_population") == -1)
        call_out("monitor_population", WAIT_TIME);
  }
  if(sizeof(msgs) == 0) set_msgs();
}
random_froth() {
  return froth_msgs[random(sizeof(froth_msgs))];
}
set_msgs() {
  msgs = ({ "A squirrel munches on a nut.\n",
            "A squirrel rolls around on the ground and pounces on a leaf.\n",
            "A squirrel shows his teeth.\n",
            "A squirrel sits on his hind legs.\n",
            "A squirrel nibbles on a small acorn.\n",
            "A squirrel sticks his head up and looks around.\n",
            "A squirrel scurries around.\n",
            "A squirrel nibbles on a twig.\n",
            "A squirrel looks at you.\n",
            "A squirrel scurries about your feet and nibbles on your shoes.\n",
            "A squirrel rolls over on the ground.\n",
            "A squirrel gives you the look of a mad, rabid creature.\n" });
  froth_msgs = ({"A squirrel froths uncontrollably.\n",
                 "A squirrel starts frothing wildly.\n",
                 "A squirrel looks at you intensely as white foam begins to form around its mouth.\n",
                 "A squirrel tries to find another squirrel to froth on.\n",
                 "A squirrel gives a nearby acorn a menacing look.\n",
                 "A squirrel tries to run up a tree, but falls over backwards.\n",
                 "A frothing squirrel runs straight into a tree, leaving a small mound of white foam.\n",
                 "A squirrel begins to nibble on his foot.\n"});
  shorts = ({"A ground squirrel",
             "A red squirrel",
              "A tree squirrel",
              "A wingless flying squirrel",
              "A striped tree squirrel",
              "A Douglas squirrel",
              "A grey squirrel",
             "A brown squirrel",
             "A squirrel you couldn't recognize with a guide"});
}
random_short() { return shorts[random(sizeof(shorts))]; }
give_squirrels(string where, int x) {
  object ob;
  for( ; x > 0; x--) {
    ob = clone_object(SQUIRREL);
    ob->set_short(random_short());
    population += ({ ob });
    move_object(ob,where);
    ob->display_message("A squirrel pops out of the woods\n");
    num_cloned++; pop_size++;
  }
}
start_population() {
  int num_rooms,i;
  if(sizeof(population) == 0)
  population = ({ }); /* i love mud memory */
  num_rooms = sizeof(locations);
  for(i = 0; i < num_rooms; i++) {
#ifndef DEBUG
    if(find_object("/room/"+locations[i]) && random(100) < 20) {
      give_squirrels("/room/"+locations[i],
                     3+random(4)-count_squirrels("/room/"+locations[i]));
#else
if(find_object(locations[i]) && random(100) < 20) {
  give_squirrels(locations[i],3+random(4)-count_squirrels(locations[i]));
#endif
    }
  }
  if(query_verb()) return 1;
}
count_squirrels(string where) {
  object *ob;
  int count,so,i;
  ob = all_inventory(where);
  for(i = 0, so = sizeof(ob); i < so; i++)
    if(ob[i]->id("squirrel")) 
      count++;
  return count;
}
emergency_load(pop,loc,siz,num) {
  population+= pop;
  pop_size += siz;
  if(sizeof(locations)==0) locations=loc;
  num_cloned += num;
}
remove_object() {
  object ob;
#ifndef DEBUG
  if(time() > START && time() < END) {
    move_object(this_object(),"/room/void");
    write("ACK! I dont think you wanted to dest me!\n");
    ob = clone_object("/players/wizardchild/fools/manager.c");
    ob->emergency_load(population,locations,pop_size,num_cloned);
  }
#endif
}
manage_population() { monitor_population(); }
monitor_population() {
  int i;
  object ob;
  while(remove_call_out("monitor_population") != -1) ;
  call_out("monitor_population",WAIT_TIME);
  /* clean up our object array, in case one of them was killed */
  for(i = 0; i < pop_size; i++) {
    if(!population[i])
      population -= ({ population[i] });
  }
  if(pop_size < 100)
    start_population(); /* if we are running low, do a respawn */
  for(i = 0; i < pop_size; i++) {
    if(random(100) < 10)
      display_random_msg(random(40),population[i]);
    if(random(100) == 0) {
      population[i]->prepare_death();
      destruct(population[i]);
      population -= ({population[i]}); i--; pop_size--;
    } else if(random(100) == 0) {
      population[i]->prepare_birth();
      give_squirrels(object_name(environment(population[i])),1);
    }else if(random(100) < 8)
      population[i]->froth();
    else if(population[i]->is_frothing() && random(100) < 3)
      population[i]->stop_froth();
    else if(random(100) < 3)
      population[i]->random_move();
    if(ob = population[i]->query_attack())
      squirrel_assault(ob);
    if(random(pop_size) < 2) start_population();
  }
}
signal_death(ob) {
  population -= ({ ob });
  pop_size--;
}
display_random_msg(x,ob) {
  ob->delayed_message(msgs[random(sizeof(msgs))],x);
}
squirrel_assault(attack) {
  object *o;
  int i,so;
  o = all_inventory(environment(attack));
  for(i = 0, so = sizeof(o);i < so; i++) {
    if(o[i]->is_squirrel())
      o[i]->attack_object(attack);
  }
}
