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
     set_name( "elemental" );
     set_short("a CHaoS EleMEnTaL");
     set_gender("creature");
     set_race( "elemental");
     set_long(
        "CHOAS can NoT be SeEN.\n"+
        "AnD CHaOs cAn noT bE FElT.\n"+
        "ChAOs JUsT is?!  RiGht?\n");
     set_level(18);
     set_heal(5,20);
     set_ac(random(20) + 5);
     set_wc(random(20) + 15);
     set_hp(random(200) + 400);
     set_al(-1000 + random(2000));
     set_aggressive(0);
     set_chat_chance(8);
     set_a_chat_chance(2);
     load_chat("A flight of blind birds flap quickly away from you.\n");
     load_chat("Your eyes briefly glow an evil shade of red.\n");
     load_chat("You feel your right arm begin to itch.\n");
     load_chat("A ball of fire explodes in the sky.\n");
     load_chat("A fish swims by you.\n");
     load_chat("A large tentacle squirms back into the ground at your feet.\n");
     load_chat("You feel your wounds heal.\n");
     load_chat("Someone whispers: I wouldn't do that if I were you...\n");
     load_chat("You feel your body spin 90 degrees to the right.\n");
     load_chat("An unhuman scream is heard in the distance.\n");
     load_chat("A bright red flash explodes before your eyes.\n");
     load_chat("Pet leave following itself.\n");
     load_chat("Beer suds begin to rain from the sky.\n");
     load_chat("Clouds begin to gather over your head...\n");
     load_chat("You feel suddenly confused.\n");
     load_chat("It begins to rain ice cubes all around you.\n");
     load_chat("A small tremor shakes the immediate area.\n");
     load_chat("A large statue of a fish falls from the sky and then swims off.\n");
     load_chat("A unicorn asks you \"\Hunters?\"\n");
     load_chat("A horde of naked kobolds rush by you on a mission to overbear somebody.\n");
     load_chat("A wall of ice melts next to you.\n");
     load_chat("Your mind fills with bad poetry.\n");
     load_chat("You feel the urge to spontaneously combust.\n");
     load_chat("A dust devil flies through the room.\n");
     load_chat("Lots of beans rain down from the sky and then jump away.\n");
     load_chat("Small frogs begin to rain from the sky.\n");
     load_chat("A hand reaches up from the earth and tickles your foot.\n");
     load_chat("You feel the urge to giggle.\n");
     load_chat("Your eyesight imporves.\n");
     load_chat("The wind tugs at your shirt.\n");
     load_chat("Carnivorous jumping beans chase a rabbit through the room.\n");
     load_chat("Your big toe turns blue.\n");
     load_chat("Your weapon becomes a large teddy bear for a moment.\n");
     load_chat("You feel your body surge with static electricity.\n");
     load_chat("Shimmering colors dance and play over you.\n");
     load_chat("sdrawkcab evom ot nigeb sgnihT\n");
     load_a_chat("The imp screams 'You fool!'\n");
     set_dead_ob(this_object());
call_out("pet_follow",5);
   }
}

bye()  {
object ob;
int goodbye;
  goodbye = random(5);

  if(goodbye < 2)  {
  say("The chAoS ElemENTal fades back into the elements from which it came.\n");
        }
  if(goodbye == 3)  {
  say("The CHaoS ELEMentAl explodes into pretty purple bunny slippers and is gone.\n");
        }
  if(goodbye > 2)  {
  say("The CHaOs eleMenTal decides to stay and is gone.\n");
        }

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
     PET+" falls up to the ground with a smoosh.\n\n");
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
    PET+" hops from the room after its pretty.\n");
  move_object(this_object(),environment(ob));
  say(
    PET+" hops into your reality.\n");
        }
if(present(MASTER, environment(this_object())))  {
 /*
  say("The imp SCREAMS at "+OWNER+".\n");
 */
        }
call_out("pet_follow",RATE);
  return 1;
        }

set_master(str)  {  master_name = str;  }
query_master()   {  return "mizan"; }
is_pet()         {  return 1; }
set_rate(str)    { RATE = str;  }
