/*
 *   A pit of leeches found within the temple of Arate.
 *
 */

inherit "/obj/monster";

reset(arg) {

  ::reset(arg);   
if (!arg){
     
     set_name("leech swarm");
     set_short("A pit full of leeches");
     set_alias("swarm");
     set_alt_name("leeches");
     set_race("leech");
     set_long(
        "A massive swarm of small leeches completely filling a large pit.\n"+
        "The slimy skin of the leeches is mottled brown and tan with occasional\n"+
        "shades of gray.\n");
     set_gender("creature");
     set_level(20);
     set_ac(12);
     set_wc(30);
     set_hp(650);
     set_al(-500);
     set_aggressive(0);
     set_dead_ob(this_object());
     call_out("suck_blood",15);
     call_out("fall_into_pit",10);
        }
        }


monster_died()  {
object ob, gold;
  tell_room(environment(this_object()), "\n"+
  "The last members of the leech swarm die.\n"+
  "\nYou see the glimmer of gold at the bottom of the pit.\n");
    gold = clone_object("obj/money");
    gold->set_money(4179 + random(1200));
    move_object(gold,this_object());
  return 0;
        }


suck_blood()  {
object HERE, target;
string NAME;
   
HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(present("pit_mark", HERE))  {
   if(living(HERE))  { 
    if(10 < random(20))  {
     NAME = HERE->query_name();
  
     tell_room(environment(this_object()),
     "The leech swarm sucks blood from "+NAME+".\n");
     HERE->heal_self(-random(12));
    
      }}}
      
HERE = next_inventory(HERE);
        }        
call_out("suck_blood",random(12));
  return 1;
        }


fall_into_pit()  {
object PIT, HERE, target;
string NAME;
   
HERE = first_inventory(environment(this_object()));

while(HERE)  {
 if(this_object()->query_attack())  {
 if(!present("pit_mark", HERE))  {
  if(HERE->query_real_name() != "leech swarm")  {
   if(living(HERE))  { 
    if(20 < random(45))  {
     NAME = HERE->query_name();
  
     tell_room(environment(this_object()),
     "\n"+NAME+" falls into the leech pit!\n\n");
     tell_object(HERE,
       "Leeches cover you!!!\n\n");
     PIT = clone_object("/players/saber/closed/toys/pit_mark.c");
     move_object(PIT, HERE);
     
      }}}}}
      
HERE = next_inventory(HERE);
        }        
call_out("fall_into_pit",random(34));
  return 1;
        }
        
        
init()  {
  ::init();
  add_action("lookat","look");
  add_action("lookat","examine");
  add_action("lookat","l");
  add_action("lookat","exa");
        }

lookat(str)  {
  if(str == "at pit" || str == "pit")  {
    write("The pit is full of leeches!\n"+
      "You think that if you fell in, you could <climb> out of it.\n");
    return 1;
        }
        }
