inherit "/obj/monster";
#define MOV_RATE 25

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object ob, ob2, gold;

ob = clone_object("/players/daranath/weps/sticker.c");
gold = clone_object("obj/money");
gold->set_money(random(200));
move_object(gold, this_object());
move_object(ob,this_object());
init_command("wield sticker");

     set_name("ugly orc");
     set_short("A frightened, ugly orc");
     set_alias("orc");
     set_race("humanoid");
     set_gender("creature");
     set_long("An ugly humaniod with a piglike snout and beady little eyes.\n"+
              "A frightened look graces its face.\n");
     set_level(5);

     init_command("wear armor");
     init_command("wield weapon");

     set_ac(5);
     set_wc(9);
     set_hp(75);
     set_al(-200);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("Ugly orc screams in fear.\n");
     load_chat("Ugly orc looks you over.\n");
     load_chat("Ugly orc gets a whistful look across its face.\n");
     load_a_chat("Ugly orc screams and tries to run.\n");
     load_a_chat("Ugly orc pokes at you with its pig-sticker.\n");
     load_a_chat("Ugly orc wets itself.\n");

     call_out("random_move",27);
     call_out("get_stuff",25);
   }
  }


status random_move()  {
int n, PLAYER;
object HERE;
  if(!environment(this_object())) return 1;

HERE = first_inventory(environment(this_object()));
PLAYER = 0;

while(HERE)  {
  if(living(HERE))  {
  if(HERE->is_player())  {  PLAYER = 1; }
    }
  HERE = next_inventory(HERE);
    }
  
  if(PLAYER > 0)  {
    say("Ugly orc screams in terror.\n");
    n=random(4);
    switch(n) {
    case 0 : command("south"); break;
    case 1 : command("north"); break;
    case 2 : command("west"); break;
    case 3 : command("east"); break;
        }
        }
  call_out("random_move", MOV_RATE);
  return 1;
        }


get_stuff()  {
object STUFF, HERE;
int TAKEN;

if(environment(this_object())) {
HERE = first_inventory(environment(this_object()));
TAKEN = 0;

  while(HERE && TAKEN == 0)  {
    if(!living(HERE))  {
      if(HERE->get()) {
         if(!HERE->drop()) {
      STUFF = HERE;
      TAKEN = 1;
     } }
      }
  HERE = next_inventory(HERE);
      }
  
  if(TAKEN > 0)  {
  move_object(STUFF, this_object());
  say("\nUgly orc swipes "+STUFF->short()+" and looks at you.\n");
  say("You see a glint of hope in its eyes.\n\n");
      }
  call_out("get_stuff", 25);
}
  return 1;
      }
