/*
 *   A horde of rats.
 */

inherit "/obj/monster";

object gold;

reset(arg) {

  gold = clone_object("obj/money");
    gold->set_money(4750 + random(500));
    move_object(gold,this_object());

  ::reset(arg);   
if (!arg){
     
     set_name("horde of rats");
     set_short("A horde of rats");
     set_alias("rats");
     set_race("rat");
     set_long(
        "A huge horde of rabid rats.  They have a look of dark intelligence\n"+
        "in their crimson little eyes...\n");
     set_gender("creature");
     set_level(21);
     set_ac(10);
     set_wc(28);
     set_hp(650);
     set_al(-600);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(7);
     set_dead_ob(this_object());
     load_chat("The distant sound of chanting washes over you.\n");
     load_chat("The musky sweet smell of incense invades your senses.\n"); 
     load_a_chat("The distant sound of chanting washes over you.\n");
     load_a_chat("The musky sweet smell of incense invades your senses.\n");
     load_a_chat("A rat drops to the ground, dead.\n");
     load_a_chat("A rat dies.\n");
     load_a_chat("A rat dies.\n");
     call_out("lots_of_attacks",10);

        }
        }


monster_died()  {
object ob;
  tell_room(environment(this_object()), "\n"+
  "The last members of the horde of rats splatter across the floor.\n\n");
  return 0;
        }


lots_of_attacks()  {
object HERE, target;
int a, what_spell, x, y;
string NAME;
  
HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(this_object()->query_attack())  {
  if(HERE->query_real_name() != "horde of rats")  {
  if(living(HERE))  {

  if(20 < random(28))  {
  NAME = HERE->query_name();
  what_spell = random(7);

  if(what_spell < 6)  {
    y = random(7) + 1;
    for(x=0; x<y; x++)  {
      tell_room(environment(this_object()),
      "The horde of rats swarms over "+NAME+".\n");
      HERE->hit_player(random(11)+3);
        }
        }
               
  if(what_spell == 6)  {
    tell_room(environment(this_object()),
    "More rats run in and join the horde.\n");
    this_object()->heal_self(random(50)+1);
        }

  }}}}
  
HERE = next_inventory(HERE);
        }        

call_out("lots_of_attacks",random(12));
  return 1;
        }
