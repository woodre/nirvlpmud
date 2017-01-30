inherit "/obj/monster";

string master_name, pet_leave, deliver_string;
object mark;
int RATE;

#define OB this_object()
#define MASTER this_object()->query_master()
#define NAME this_object()->query_name()
#define OWNER capitalize(this_object()->query_master())
#define PET capitalize(this_object()->short())
#define GENDER find_living(MASTER)->query_possessive()
#define CALL this_object()->query_CALL()

reset(arg)  {
mark = clone_object("/players/saber/closed/toys/all_mark.c");
move_object(mark,this_object());
   ::reset(arg);
   if (!arg){
     set_name( "imp" );
     set_short("An ugly red imp");
     set_gender("creature");
     set_race( "demon");
     set_alias("black_imp");
     set_long(
        "An ugly little red imp with delicate black wings.\n"+
        "The imp has eyes of ebony and fangs of ivory white.\n");
     set_level(15);
     set_heal(5,20);
     set_ac(45);
     set_wc(10);
     set_hp(666);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(3);
     set_a_chat_chance(2);
     load_chat("The imp screams 'Thats what you get for pissing off a wizard!'\n");
     load_chat("The imp laughs a wicked laugh.\n");
     load_a_chat("The imp screams 'You fool!'\n");
     set_dead_ob(this_object());
call_out("pet_follow",5);
   }
}

bye()  {
object ob;
  say("The imp screams 'SEE YOU LATER!'\n");

  remove_call_out("pet_follow");
  destruct(OB);
  return 1;
        }

monster_died()  {
object ob;
int DAMAGE;
  ob = find_player(MASTER);
  DAMAGE = random(50);
  ob->hit_player(random(DAMAGE));
  remove_call_out("pet_follow");
  tell_room(environment(this_object()),
     PET+" falls to the ground with a thud.\n\n");
  tell_room(environment(this_object()),
      capitalize(MASTER)+" screams in pain.\n\n");
return 0;
        }

pet_follow()  {
object ob;
if(!find_player(MASTER))  { bye(); }
  ob = find_player(MASTER);
if(!present(MASTER,environment(this_object())))  {
  say(
    PET+" flies from the room after its prey.\n");
  move_object(this_object(),environment(ob));
  say(
    PET+" flies into the room.\n");
        }
if(present(MASTER, environment(this_object())))  {
  say("The imp SCREAMS at "+OWNER+".\n");
  ob->run_away();
        }
call_out("pet_follow",RATE);
  return 1;
        }

set_master(str)  {  master_name = str;  }
query_master()   {  return master_name; }
is_pet()         {  return 1; }
set_rate(str)    { RATE = str;  }
