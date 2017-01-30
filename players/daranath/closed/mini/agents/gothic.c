#define TPM this_player()->query_money()
#define tp this_player()->query_name()

inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("gothic");
    set_short("A gothic fem");
    set_alias("fem");
    set_alt_name("goth");
    set_race("human");
    set_long("A female dressed all in black.  She has long black hair\n"+
        "and has painted her face white.  You think that she could give\n"+
        "you 'info' or help you 'join'  the 'gothics'.\n");
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
    load_chat("The goth glances at you.\n");
    load_chat("The goth wonders if you are gothic too?\n");
    load_chat("The goth looks depressed.\n");
    load_chat("The goth dances a little.\n");
    load_chat("The goth wonders if you are a servant of Larn...?\n");
    load_chat("The goth frowns.\n");
    load_a_chat("The gothic glares at you with eyes of pure hate.\n");
    load_a_chat("The gothic rakes her nails across your face.\n");
    set_spell_mess1("The goth glares at her foe.");
    set_spell_mess2("The goth glares at you.\nYou feel weak.");
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
  write("The goth asks: You want to join what?\n");
  return 1;
        }
  if(str == "gothic" || str == "gothics");
  if(TPM < 5000)  {
  write("The goth says: It costs 5000 golden coins to join the gothics.\n");
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
  write("The goth says: You belong to too many mini guilds.\n"+
    "Come back when you have left one.\n");
    return 1;
        }
  if(this_player()->query_age() < 10800)  {
    write("The goth says: You are too young to join a mini guild.\n");
    return 1;
        }
  if(club_count > 0)  {
  if(this_player()->query_age() < 43200)  {
    write("The priestess says: You need to be older to join two mini guilds.\n");
    return 1;
        }
        }
  move_object(clone_object("/players/saber/closed/new_mini/gothic.c"),this_player());
  say("The goth says: Welcome to the Gothics.\n"+
     "She checks to make sure that you have attitude (you do!)\n"+
    "The goth looks a little depressed.\n");
  call_other(this_player(), "add_money", - 5000);
  return 1;
        }

info()  {
write(
"The Gothics are new on the scene of Ryllian, but have adapted well to the city\n"+
"of eternal night.  Gothics are often moody, depressed and have tendencies to\n"+
"dress in exotic forms of black apparel.  They have no real powers (isn't that\n"+
"depressing?), but often are very good dancers.  They can also be quite evil\n"+
"when angered.\n\n");
  return 1;
        }
