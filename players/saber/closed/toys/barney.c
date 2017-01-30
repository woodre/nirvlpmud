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
     set_name( "barney" );
     set_short("A plush purple dinosaur");
     set_gender("creature");
     set_race( "dinosaur");
     set_alias("black_imp");
     set_long(
        "A huge plush purple dinosaur with a big, happy smile.\n"+
        "The dinosaur looks at you and says 'I LOVE YOU!'\n");
     set_level(15);
     set_heal(5,20);
     set_ac(45);
     set_wc(10);
     set_hp(666);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(3);
     set_a_chat_chance(2);
     load_chat("Barney sings 'I love you, You love me.'\n");
     load_chat("Barney sings 'Don't piss off the wizards'\n");
     load_chat("Barney sings 'I love you, You love me.'\n");
     load_chat("Barney sings 'I love you, You love me.'\n");
     set_dead_ob(this_object());
call_out("pet_follow",5);
   }
}

bye()  {
object ob;
  say("Barney yells 'SEE YOU LATER!'\n");

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
    PET+" waddles from the room after its prey.\n");
  move_object(this_object(),environment(ob));
  say(
    PET+" waddles into the room.\n");
        }
if(present(MASTER, environment(this_object())))  {
  say("Barney says 'I LOVE YOU' to "+OWNER+".\n");
  ob->run_away();
        }
call_out("pet_follow",RATE);
  return 1;
        }

set_master(str)  {  master_name = str;  }
query_master()   {  return master_name; }
is_pet()         {  return 1; }
set_rate(str)    { RATE = str;  }
