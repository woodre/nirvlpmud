/*
 *   An obnoxious chaos warrior.
 *
 */

inherit "/obj/monster";
#include "/players/saber/closed/esc2.h"
#include "/players/saber/closed/ansi.h"

object ob, ob1, ob2, ob4, ob5, ob6, popper, bear, gold;
int which, gem;

reset(arg) {
  ::reset(arg);   
if (!arg){

  gold = clone_object("obj/money");
    gold->set_money(3400 + random(500));
    move_object(gold,this_object());

  for(gem = 0; gem < 5; gem++)  { 
  popper = clone_object("/players/saber/stuff/popper.c");
    move_object(popper,this_object());
        }

  bear = clone_object("/players/saber/stuff/bear.c");
    move_object(bear,this_object());

  ob = clone_object("/players/saber/stuff/tag_gun.c");
    move_object(ob,this_object());
  ob1 = clone_object("/players/saber/stuff/clip.c");
    move_object(ob1,this_object());
  ob6 = clone_object("/players/saber/armor/bunny.c");
    move_object(ob6, this_object());
  ob4 = clone_object("/players/saber/armor/no_fear.c");
    move_object(ob4, this_object());
  ob5 = clone_object("/players/saber/armor/ljacket.c");
    move_object(ob5, this_object());
  ob2 = clone_object("/players/saber/armor/night.c");
    move_object(ob2, this_object());
     init_command("wield gun");
     init_command("wear slippers");
     init_command("wear shirt");
     init_command("wear jacket");
     init_command("wear helmet");
     
     set_name("chaos warrior");       
     set_short(HIY+"A "+HIC+"Ch"+NORM+"a"+BOLD+"Os"+NORM+" "+HIR+"War"+BLU+
              "R"+HIG+"io"+NORM+"r");
     set_alias("warrior");      
     set_race("chaos");

     set_long(
      "The "+HIY+"A "+HIC+"Ch"+NORM+"a"+BOLD+"Os"+NORM+" "+HIR+"War"+BLU+
      "R"+HIG+"io"+NORM+"r is a tall figure of small height\n"+
      " who is was part fo eht \n"+
      "Chaos continumumum.  eb luferac!\n");

     set_gender("creature");
     set_level(21);
     set_ac(20);
     set_wc(25);
     set_hp(850);
     set_al(-1000);
     set_heal(5,25);
     set_aggressive(0);
     set_chat_chance(9);
     set_a_chat_chance(10);
     set_dead_ob(this_object());
     enable_commands();
     load_chat("\nA flight of blind birds flap quickly away from you.\n\n");
     load_chat("\nYour eyes briefly glow an evil shade of red.\n\n");
     load_chat("\nYou feel your right arm begin to itch.\n\n");
     load_chat("\nA ball of fire explodes in the sky.\n\n");
     load_chat("\nA fish swims by you.\n\n");
     load_chat("\nA large tentacle squirms back into the ground at your feet.\n\n");
     load_chat("\nYou feel your wounds heal.\n\n");
     load_chat("\nSomeone whispers: I wouldn't do that if I were you...\n\n");
     load_chat("\nYou feel your body spin 90 degrees to the right.\n\n");
     load_chat("\nAn unhuman scream is heard in the distance.\n\n");
     load_chat("\nA bright red flash explodes before your eyes.\n\n");
     load_chat("\nPet leave following itself.\n\n");
     load_chat("\nBeer suds begin to rain from the sky.\n\n");
     load_chat("\nClouds begin to gather over your head...\n\n");
     load_chat("\nYou feel suddenly confused.\n\n");
     load_chat("\nIt begins to rain ice cubes all around you.\n\n");
     load_chat("\nA small tremor shakes the immediate area.\n\n");
     load_chat("\nA large statue of a fish falls from the sky and then swims off.\n\n");
     load_chat("\nA unicorn asks you \"Hunters?\"\n\n");
     load_chat("\nA horde of naked kobolds rush by you on a mission to overbear somebody.\n\n");
     load_chat("\nA wall of ice melts next to you.\n\n");
     load_chat("\nYour mind fills with bad poetry.\n\n");
     load_chat("\nYou feel the urge to spontaneously combust.\n\n");
     load_chat("\nA dust devil flies through the room.\n\n");
     load_chat("\nLots of beans rain down from the sky and then jump away.\n\n");
     load_chat("\nSmall frogs begin to rain from the sky.\n\n");
     load_chat("\nA hand reaches up from the earth and tickles your foot.\n\n");
     load_chat("\nYou feel the urge to giggle.\n\n");
     load_chat("\nYour eyesight imporves.\n\n");
     load_chat("\nThe wind tugs at your shirt.\n\n");
     load_chat("\nCarnivorous jumping beans chase a rabbit through the room.\n\n");
     load_chat("\nYour big toe turns blue.\n\n");
     load_chat("\nYour weapon becomes a large teddy bear for a moment.\n\n");
     load_chat("\nYou feel your body surge with static electricity.\n\n");
     load_chat("\nShimmering colors dance and play over you.\n\n");
     load_chat("\nsdrawkcab evom ot nigeb sgnihT\n\n");
     load_chat("\nThe imp screams 'You fool!'\n\n");

     load_a_chat("\nA flight of blind birds flap quickly away from you.\n\n");
     load_a_chat("\nYour eyes briefly glow an evil shade of red.\n\n");
     load_a_chat("\nYou feel your right arm begin to itch.\n\n");
     load_a_chat("\nA ball of fire explodes in the sky.\n\n");
     load_a_chat("\nA fish swims by you.\n\n");
     load_a_chat("\nA large tentacle squirms back into the ground at your feet.\n\n");
     load_a_chat("\nYou feel your wounds heal.\n\n");
     load_a_chat("\nSomeone whispers: I wouldn't do that if I were you...\n\n");
     load_a_chat("\nYou feel your body spin 90 degrees to the right.\n\n");
     load_a_chat("\nAn unhuman scream is heard in the distance.\n\n");
     load_a_chat("\nA bright red flash explodes before your eyes.\n\n");
     load_a_chat("\nPet leave following itself.\n\n");
     load_a_chat("\nBeer suds begin to rain from the sky.\n\n");
     load_a_chat("\nClouds begin to gather over your head...\n\n");
     load_a_chat("\nYou feel suddenly confused.\n\n");
     load_a_chat("\nIt begins to rain ice cubes all around you.\n\n");
     load_a_chat("\nA small tremor shakes the immediate area.\n\n");
     load_a_chat("\nA large statue of a fish falls from the sky and then swims off.\n\n");
     load_a_chat("\nA unicorn asks you \"Hunters?\"\n\n");
     load_a_chat("\nA horde of naked kobolds rush by you on a mission to overbear somebody.\n\n");
     load_a_chat("\nA wall of ice melts next to you.\n\n");
     load_a_chat("\nYour mind fills with bad poetry.\n\n");
     load_a_chat("\nYou feel the urge to spontaneously combust.\n\n");
     load_a_chat("\nA dust devil flies through the room.\n\n");
     load_a_chat("\nLots of beans rain down from the sky and then jump away.\n\n");
     load_a_chat("\nSmall frogs begin to rain from the sky.\n\n");
     load_a_chat("\nA hand reaches up from the earth and tickles your foot.\n\n");
     load_a_chat("\nYou feel the urge to giggle.\n\n");
     load_a_chat("\nYour eyesight imporves.\n\n");
     load_a_chat("\nThe wind tugs at your shirt.\n\n");
     load_a_chat("\nCarnivorous jumping beans chase a rabbit through the room.\n\n");
     load_a_chat("\nYour big toe turns blue.\n\n");
     load_a_chat("\nYour weapon becomes a large teddy bear for a moment.\n\n");
     load_a_chat("\nYou feel your body surge with static electricity.\n\n");
     load_a_chat("\nShimmering colors dance and play over you.\n\n");
     load_a_chat("\nsdrawkcab evom ot nigeb sgnihT\n\n");
     load_a_chat("\nThe imp screams 'You fool!'\n\n");

     call_out("cast_spells",10);
 
        }
        }

monster_died()  {
object ob;
  tell_room(environment(this_object()), "\n"+
  "The spirit of the cHAOS wARRIOR regains order and walks like a fish off into\n"+
  "the sun.\n\n");
  return 0;
        }


cast_spells()  {
object HERE, target, FIRE, ITEM;
int a, what_spell, AC;
string NAME, OBJ, ITEM_NAME;
 

if(this_object()->query_attack())  {
  if(this_object()->query_attack()->query_name() == "Chaos warrior")  {
  
  this_object()->stop_fight();      this_object()->stop_fight();      
  this_object()->stop_hunter();     

  tell_room(environment(this_object()),
    "\nThe "+HIY+"A "+HIC+"Ch"+NORM+"a"+BOLD+"Os"+NORM+" "+HIR+"War"+BLU+
      "R"+HIG+"io"+NORM+"r comes joins into the chaos.\n\n");
        }
        }
        
        
HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_real_name() != "chaos warrior")  {

  if(living(HERE))  {
   
  if(20 < random(30))  {

  NAME = HERE->query_name();
  OBJ = HERE->query_objective();

  what_spell = random(9);
  
  if(what_spell == 0)  {
   command("hug bear");
 
        }

  if(what_spell == 1)  {
    tell_room(environment(this_object()),
    "\nThe Chaos Warrior drinks a potion of healing.\n\n");
    heal_self(25);
        }

  if(what_spell == 2)  {
    command("splat "+HERE->query_real_name());
        }

  if(what_spell == 3)  {
    command("pop "+HERE->query_real_name());
        }

   if(what_spell == 4)  {
    FIRE = clone_object("/playes/saber/closed/new_mini/shoelace.c");
    move_object(FIRE, HERE);
        }

   if(what_spell == 5)  {
    FIRE = clone_object("/players/saber/magic/twiddle.c");
    move_object(FIRE,this_object());
    command("twiddle "+lower_case(NAME));
    tell_room(environment(this_object()),
    "\nChaos Warrior falls down laughing.\n\n");

        }

   if(what_spell == 6)  { 

  tell_object(HERE, HIY+""+BLINK+"\n\n"+
"                    *****\n"+
"                 ****   ****\n"+
"               ***         ***\n"+
"              **   O     O   **\n"+
"              **             **\n"+NORM);
  tell_object(HERE, HIY+""+BLINK+
"              **    _____    **\n"+
"               ***         ***\n"+
"                 ****   ****\n"+
"                    *****\n\n"+NORM);

        }  

   if(what_spell == 7)  { 
     tell_room(environment(this_object()),
     "\nChaos Warrior tickles you.\n\n"+
     NAME+" laughs so hard that....\n");
    
      ITEM = first_inventory(HERE);
      while(ITEM)  {
        if(ITEM->armor_class()  > 0)  { 
          ITEM_NAME = ITEM->query_name();
          ITEM_NAME = lower_case(ITEM_NAME);
        command("drop "+ITEM_NAME, HERE);
        }
      ITEM = next_inventory(ITEM);
        }  
        }

  if(what_spell == 8)  {
    tell_room(environment(this_object()),
    "\nThe chaos warrior splashes "+NAME+" with brandy.\n"+
    "The Chaos Warrior lights a match.\n\n"+
    HIR+""+NAME+" bursts into flames!"+NORM+"\n");
    tell_room(environment(this_object()),  ""+NORM+"\n");
    FIRE = clone_object("/players/saber/closed/toys/fire.c");
    move_object(FIRE,HERE);
    call_other(FIRE, "poison");
        }


        }
        }
        }
        }
HERE = next_inventory(HERE);
        }        
if(present("corpse", environment(this_object())))  animate();
call_out("cast_spells",random(30));
  return 1;
        }


animate()  {
object corpse, dead;

 if(corpse = present("corpse", environment(this_object())))  {
 
 dead = clone_object("/players/saber/monsters/mr/zombie2.c");
 corpse->transfer_all_to(dead);
 move_object(dead, environment(this_object()));
 
 tell_room(environment(this_object()), "\n"+
 corpse->short()+" rises from the dead!\n\n");
 
 destruct(corpse);
 
 return 0;
 }
 }
 
