inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
move_object(clone_object("/players/saber/closed/quest/items/dshadow.c"),this_object());
init_command("wear shadow");
     set_name("demon");
     set_short("A dark red demon");
    set_race("demon");
    set_gender("creature");
     set_long("A huge demon with crimson hellfire skin twisted across\n"+
       "its sleek humanoid frame.  The demons eyes are coal black, \n"+
       "and it looks up at you with hatred blazing forth.\n");
    set_level(18);
    set_ac(13);
    set_wc(26);
    set_hp(450);
    set_al(-666);
    set_aggressive(1);
    set_chat_chance(15);
    set_a_chat_chance(10);
     load_chat("The demon laughs.\n");
     load_chat("The demon's shadow twists under it.\n");
     load_chat("The demon hisses.\n");
     load_a_chat("The demon hisses out a cloud of smoke.\n");
     load_a_chat("The demon's shadow strikes at you.\n");
     load_a_chat("The demon slashes at you with razor sharp claws.\n");
     call_out("random_move", 20);
        }
        }

status random_move()  {
int n;
  n = random(4);
  switch(n)  {
  case 0: command("north"); break;
  case 1: command("west");  break;
  case 2: command("south"); break;
  case 3: command("east");  break;
        }
  call_out("random_move", 20);
  return 1;
       }

