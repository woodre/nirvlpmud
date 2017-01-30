#define TPM this_player()->query_money()
#define tp this_player()->query_name()

inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("gypsy");
    set_short("A dark gypsy woman");
    set_race("human");
    set_alias("woman");
     set_long("A mysterious woman wearing bright gypsy cloth.\n"+
     "You think that she could give you 'info' or help you to 'join' \n"+
     "the gypsy clan.\n");
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
    load_chat("The woman wonders if you have gypsy blood.\n");
    load_chat("The dark woman glances at you with dark eyes.\n");
     load_chat("The gypsy woman whispers soft words to herself.\n");
     load_chat("The gypsy woman fingers her silver medallion.\n");
     load_a_chat("The gypsy woman curses you.\n");
     load_a_chat("The gypsy woman glares at you.\n");
     set_spell_mess1("The gypsy woman calls down a curse upon her foe.");
     set_spell_mess2("The gypsy woman calls down a curse upon you.");
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
  write("The gypsy asks: You want to join what?\n");
  return 1;
        }
  if(str == "gypsy")  {
  if(TPM < 5000)  {
  write("The gypsy says: It costs 5000 golden coins to join the gypsy kin.\n");
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
  write("The gypsy says: You belong to too many mini guilds.\n"+
    "Come back when you have left one.\n");
    return 1;
        }
  if(this_player()->query_age() < 10800)  {
    write("The gypsy says: You are too young to join a mini guild.\n");
    return 1;
        }
  if(club_count > 0)  {
  if(this_player()->query_age() < 43200)  {
    write("The gypsy says: You are too young to join 2 mini guilds.\n");
    return 1;
        }
        }
  move_object(clone_object("/players/saber/closed/new_mini/gypsy.c"),this_player());
  say("The gypsy says: Welcome, kin of my kin!\n"+
  "They gypsy places a silver medallion around your neck.\n"+
  "The gypsy woman smiles at you.\n");
  call_other(this_player(), "add_money", - 5000);
  return 1;
        }
        }

info()  {
write("\n"+
"The Gypsies are composed of people with gypsy tradition and blood.  Gypsies\n"+
"can use their fortune telling abilities on players, monsters, or even items.\n"+
"They can also cast potent curses, tell the values of items, and draw others\n"+
"into their beguiling style of dancing.\n\n");
  return 1;
        }
