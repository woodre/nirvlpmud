#define TPM this_player()->query_money()
#define tp this_player()->query_name()

inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("blade");
    set_short("A young swashbuckling Blade");
    set_alias("blade");
    set_race("human");
    set_long("A young swashbuckler carrying a dueling knife.\n"+
        "You think that he could give you 'info' or help you 'join'\n"+
        "the Blades.\n");
    set_level(16);
    set_heal(2,5);
    set_ac(13);
    set_wc(22);
    set_hp(400);
    set_al(500);
    set_gender("male");
    set_aggressive(0);
    set_chat_chance(15);
    set_a_chat_chance(15);
    load_chat("The blade smiles at you.\n");
    load_chat("The blade wipes off his dueling knife.\n");
    load_chat("The blade looks around.\n");
    load_chat("The blade wonders if you are a blade too?\n");
    load_chat("The blade twirls his dueling knife between his fingers.\n");
    load_a_chat("The blade slices you across the face.\n");
    load_chat("The blade punches you in the face.\n");
    set_spell_mess1("The blade slashes his foe twice.");
    set_spell_mess2("The blade slices you twice!");
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
  write("The blade asks: You want to join what?\n");
  return 1;
        }
  if(str == "blade" || str == "blades")  {
  if(TPM < 5000)  {
  write("The blade says: It costs 5000 golden coins to join the Blades.\n");
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
  write("The blade says: You belong to too many mini guilds.\n"+
    "Come back when you have left one.\n");
    return 1;
        }
  if(this_player()->query_age() < 10800)  {
    write("The blade says: You are too young to join a mini guild.\n");
    return 1;
        }
  if(club_count > 0)  {
  if(this_player()->query_age() < 86400)  {
    write("The blade says: You need to be older to join two mini guilds.\n");
    return 1;
        }
        }
  move_object(clone_object("/players/saber/closed/new_mini/blade.c"),this_player());
  say("The blade says: Welcome to the Blades!\n"+
      "The blade gives you a dueling knife.\n"+
      "The blade grins.\n");
  call_other(this_player(), "add_money", - 5000);
  return 1;
        }
        }

info()  {
write(
"The Blades are all young swashbuckling street punks from the streets of\n"+
"Ryllian.  They have been known to duel with their ever present dueling knifes\n"+
"at the slightest insult, but usually only until first blood has been head.\n"+
"Blades are good at identifying, repairing and being all around flamboyant with\n"+
"their weapons.  They also have quite a sense of humor.\n\n");
return 1;
        }
