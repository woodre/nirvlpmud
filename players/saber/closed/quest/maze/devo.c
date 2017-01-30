#define MOV_RATE 15
inherit "/obj/monster";
object ob, ob2,gold;

reset(arg) {
   ::reset(arg);
   if (!arg){
gold = clone_object("obj/money");
gold->set_money(random(5000) + 8500);
move_object(gold,this_object());
     set_name( "devourer" );
     set_gender("creature");
     set_short("The Devourer");
     set_race( "spirit");
     set_long("A monsterous creature from the plane of shadow.\n"+
       "Rumor has it that a touch from this creature can drain\n"+
       "the very life force from a person.\n");
     set_level(21);
     set_ac(18);
     set_wc(45);
     set_hp(500);
     set_heal(2,5);
     set_al(-1000);
     set_aggressive(1);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("The Devourer slithers towards you.\n");
     load_chat("The Devourer pauses for an instant.\n");
     load_chat("The Devourer whispers silently.\n");
     load_a_chat("The Devourer hisses.\n");
     load_a_chat("The Devourer draws energy from the shadows.\n");
     load_a_chat("The Devourer slithers towards you.\n");
     load_a_chat("The Devourer draws energy from you.\n"+
       "You feel weaker.\n");
     load_a_chat("You seem something in the shadows move.\n");
     set_chance(20);
     set_spell_dam(50);
     set_spell_mess1("\nThe Devourer leaches onto its for and begins to drain lifeforce.\n");
     set_spell_mess2("\nThe Devourer leaches onto you and begins to drain your lifeforce.\n");
     call_out("slam_player",10);

call_out("random_move",MOV_RATE);
   }
}

heart_beat() { if(root()) return set_heart_beat(0); ::heart_beat(); }
status random_move(){
int n;
n=random(6);
switch(n) {
case 0 : command("east"); break;
case 1 : command("north"); break;
case 2 : command("west"); break;
case 3 : command("south"); break;
case 4 : command("up"); break;
case 5 : command("down"); break;
}
call_out("random_move",MOV_RATE);
  return 1;
}

slam_player()  {
object target, HERE;
int a;
  if(!environment(this_object())) return 1;

HERE = first_inventory(environment(this_object()));

while(HERE)  {
  if(HERE->query_name() != "Devourer")  {
  if(living(HERE))  {
   if(HERE->is_player()) {
  if(call_other(HERE, "query_attrib", "sta") < random(100))  {
  tell_room(environment(this_object()),
    "\nThe Devourer slams "+HERE->query_name()+" a with a huge bolt of negative plane energy.\n\n");
  tell_room(environment(this_object()),
  "\nPropelled by a staggering surge of power ");
  while(present(HERE))  {
    switch(a)  {
    case 0 : command("north",HERE); break;
    case 1 : command("south",HERE); break;
    case 2 : command("west", HERE); break;
    case 3 : command("up"  , HERE); break;
    case 4 : command("down", HERE); break;
    case 5 : command("east", HERE); break;
        }
  if(!present(HERE))  {
    tell_room(environment(HERE),
  HERE->query_name()+" flies backwards into the room and slams against the ground with\n"+
       "a bone crunching sound.\n");
        }
  a++;
  if(a > 5) a = 0;
        }
    }
    }
    }
    }
  HERE = next_inventory(HERE);
        }
  call_out("slam_player",10);
  return 1;
        }
