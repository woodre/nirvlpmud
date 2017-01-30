#define TPM this_player()->query_money()
#define tp this_player()->query_name()

inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("cat");
    set_short("A small cat");
    set_race("feline");
     set_long("A small black kitty with long whiskers.\n"+
     "You think it could give you 'info' or help you 'join' the 'felines'\n");
    set_level(5);
    set_heal(2,5);
    set_ac(13);
    set_wc(18);
    set_hp(100);
    set_al(500);
    set_gender("creature");
    set_aggressive(0);
    set_chat_chance(15);
    set_a_chat_chance(15);
    load_chat("The cat wonders if you are a feline...?\n");
    load_chat("The cat looks at you.\n");
    load_chat("The cat purrs.\n");
       load_chat("The kitty meows softly.\n");
       load_chat("The cat grooms itself.\n");
       load_chat("The cat peers at you.\n");
     load_a_chat("The cat hisses.\n");
     load_a_chat("The cat glares at you with dark yellow eyes.\n");
     set_spell_mess1("The cat rakes its foe with its claws.\n");
     set_spell_mess2("The cat rakes you with its claws.\n");
    set_chance(20);
    set_spell_dam(20);
        }
        }

init() {
  ::init();
   add_action("join","join");
   add_action("info","info");
        }

join(str) {
string club_count;
object ob;
  club_count = 0;
  if(!str)  {
  write("The cat meows: You want to join what?\n");
  return 1;
        }
  if(str == "felines")  {
  if(TPM < 5000)  {
  write("The cat meows: It costs 5000 golden coins to join the felines.\n");
  return 1;
        }

if(present("base_obj",this_player()))  {
  ob = first_inventory(this_player());
  while(ob)  {
  if(call_other(ob, "id", "base_obj"))  {
   club_count = club_count + 1;
        }
  ob = next_inventory(ob);
        }
        }
  if(club_count > 1)  {
  write("The cat meows: You belong to too many mini guilds.\n"+
    "Come back when you have left one.\n");
    return 1;
        }
  if(this_player()->query_age() < 10800)  {
    write("The cat meows: You are too young to join a mini guild.\n");
    return 1;
        }
  if(club_count > 0)  {
  if(this_player()->query_age() < 43200)  {
    write("The cat meows: You are too young to join 2 mini guilds.\n");
    return 1;
        }
        }
  move_object(clone_object("/players/saber/closed/new_mini/feline.c"),this_player());
  say("The cat meows: Welcome!!!\n"+
    "The cat gives you a ball 'o string.\n"+
   "The cat purrs loudly.\n");
  call_other(this_player(), "add_money", - 5000);
  return 1;
        }
        }

info()  {
write("\n"+
"The Felines (aka the Cat Dancers) is the mini guild composed entirely of cats\n"+
"or people with a very feline nature.  Felines have increased stealth powers,\n"+
"can extend and retract their sharp kitty claws, and have lots of feline\n"+
"emotions.  A good guild for the more fuzzy among us.\n");
  write("\n");
  return 1;
        }
