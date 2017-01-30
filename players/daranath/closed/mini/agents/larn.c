#define TPM this_player()->query_money()
#define tp this_player()->query_name()

inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("priestess");
    set_short("A priestess of larn");
    set_alias("priestess");
    set_race("human");
    set_long("A friendly looking warrior-priestess wearing chainmail.\n"+
"You think that she could give you 'info' or help you 'join' the\n"+
   "warrior priests of 'larn'.\n");
    set_level(16);
    set_heal(2,5);
    set_ac(13);
    set_wc(22);
    set_hp(400);
    set_al(500);
    set_gender("female");
    set_aggressive(0);
    set_chat_chance(15);
    set_a_chat_chance(15);
    load_chat("The priestess of Larn polishes her holy symbol.\n");
    load_chat("The priestess wonders if you are a servant of Larn...?\n");
    load_chat("The priestess smiles.\n");
    load_chat("The priestess says: Now where did Brother Markus go...?\n");
    load_chat("The priestess raises her hand and blesses you.\n");
    load_chat("The priestess whispers a prayer.\n");
    load_a_chat("The priestess calls upon the power of Larn!\n");
    load_a_chat("The priestess traces a symbol in the air.\n");
    set_spell_mess1("The priestess calls down the POWER of Larn upon her foe.");
    set_spell_mess2("The priestess calls down the POWER of Larn upon you.");
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
  write("The larn asks: You want to join what?\n");
  return 1;
        }
  if(str == "larn")  {
  if(TPM < 5000)  {
  write("The priestess says: It costs 5000 golden coins to join the servants of Larn.\n");
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
  write("The priestess says: You belong to too many mini guilds.\n"+
    "Come back when you have left one.\n");
    return 1;
        }
  if(this_player()->query_age() < 10800)  {
    write("The priestess says: You are too young to join a mini guild.\n");
    return 1;
        }
  if(club_count > 0)  {
  if(this_player()->query_age() < 43200)  {
    write("The priestess says: You need to be older to join two mini guilds.\n");
    return 1;
        }
        }
  move_object(clone_object("/players/saber/closed/new_mini/larn.c"),this_player());
  say("The priestess says: Welcome the the Servants of Larn!\n"+
    "The priestess gives you a holy symbol.\n"+
   "The priestess hugs you.\n");
  call_other(this_player(), "add_money", - 5000);
  return 1;
        }
        }

info()  {
write("\n"+
"The Servants of Larn are followers of the main god of the Larn of the Shadow\n"+
"of the Sun and the mortal enemies of the Church of Arate.  Larn is the deity\n"+
"of protection, life and adventure, and gifts his followers with the ability to\n"+
"summon light, heal wounds, bless companions and administer last rites to a\n"+
"corpse.\n\n");
  return 1;
        }
