#define TPM this_player()->query_money()
#define tp this_player()->query_name()

inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("hell kitten");
    set_short("A ferocious hell kitten");
    set_race("feline");
    set_alias("kitten");
    set_gender("creature");
    set_long("A small orange kitten with black ears and tiny little whiskers.\n"+
        "It has claws disproportionate to its size, and an evil glint in its eyes.\n"+
        "For some strange reason, you have a strong desire to hold it.\n");
    set_level(13);
    set_ac(13);
    set_wc(13);
    set_hp(666);
    set_al(-666);
    set_aggressive(1);
    set_chat_chance(15);
    set_a_chat_chance(10);
    load_chat("The hell kitten looks at you and snarls.\n");
    load_chat("The hell kitten purrs evilly.\n");
    load_chat("The hell kitty meows softly showing sharp teeth.\n");
    load_chat("The hell kitten grooms itself with a bloody little tongue.\n");
    load_chat("The hell kitten peers at you.\n");
     load_a_chat("The hell kitten hisses.\n");
     load_a_chat("The hell kitten glares at you with dark yellow eyes.\n");
     set_spell_mess1("The hell kitten rakes its foe with razor sharp claws.\n"+
        "scratch\nscratch\nscratch\nscratch");
     set_spell_mess2("The hell kitten rakes you with razon sharp claws.\n"+
        "scratch\nscratch\nscratch\nscratch");
     set_chance(15);
     set_spell_dam(25);
     call_out("random_move", 10);
        }
        }

get()  { return 1; }

status random_move()  {
int n;
  n = random(4);
  switch(n)  {
  case 0: command("north"); break;
  case 1: command("west");  break;
  case 2: command("south"); break;
  case 3: command("east");  break;
        }
  call_out("random_move", 10);
  return 1;
       }

quest_ob()  { return 1; }
query_save_flag()  { return 1; }
