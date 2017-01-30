/*
 *    The snake from the snake staff.
 */

inherit "/obj/monster";

string master_name;
int charges;

#define OB this_object()
#define MASTER this_object()->query_master()
#define NAME this_object()->query_name()
#define PET  this_object()->short()

reset(arg)  {
   ::reset(arg);
   if (!arg){
   
     set_name("serpent" );
     set_short("A large serpent");
     set_gender("creature");
     set_race("snake");
     set_long(
        "A six foot long, dark green serpent.\n");
     set_level(10);
     set_heal(5,20);
     set_ac(8);
     set_wc(15);
     set_hp(150);
     set_al(0);
     set_dead_ob(this_object());
call_out("pet_follow",5);
call_out("turn_back",400);
   }
}

bye()  {
object ob;
  tell_room(environment(this_object()),
    "\n"+PET+" turns into a six foot long ironwood staff.\n\n");
  ob = clone_object("/players/saber/weapons/snake_staff.c");
  move_object(ob, environment(this_object())); 
  call_other(ob, "set_charges", charges);
  remove_call_out("pet_follow");
  remove_call_out("turn_back");
  destruct(OB);
  return 1;
        }

monster_died()  {
object ob;
  remove_call_out("pet_follow");
  remove_call_out("turn_back");
  tell_room(environment(this_object()),
     "\n"+PET+" turns into a six foot long ironwood staff.\n\n");
  ob = clone_object("/players/saber/weapons/dead_snake.c");
  move_object(ob, environment(OB));
  return 0;
        }

pet_follow()  {
object ob;
  if(!find_living(MASTER))  { bye(); }
  ob = find_living(MASTER);
  if(!present(MASTER,environment(this_object())))  {
  say(
    PET+" slithers from the room after its prey.\n");
  move_object(this_object(),environment(ob));
  say(
    PET+" slithers into the room.\n");
        }
  call_out("pet_follow",6);
  return 1;
        }
        
turn_back()  {
object ob;
  tell_room(environment(this_object()),
    "\n"+PET+" turns into a six foot long ironwood staff.\n\n");
  ob = clone_object("/players/saber/weapons/snake_staff.c");
  move_object(ob, environment(this_object())); 
  remove_call_out("pet_follow");
  call_other(ob, "set_charges", charges);
  destruct(OB);
  return 1;
         }  
         
sic(str)  {
object ob;
  ob = present(str,environment(this_object()));
  if(!ob) { bye(); return 1; }
  this_object()->attack_object(ob);
  if(living(ob)) ob->attack_object(this_object());
  return 1;
       }

set_master(str)  {  master_name = str;  }
query_master()   {  return master_name; }
is_pet()         {  return 1; }
set_charges(str) { charges = str; }
