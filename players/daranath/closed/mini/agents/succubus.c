#define TPM this_player()->query_money()
#define tp this_player()->query_name()

inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("succubus");
    set_short("A sexy looking succubus");
    set_alias("lover");
    set_race("demon");
    set_long("A sexy looking succubus dressed in a red satin teddy.\n"+
     "You think she could give you 'info' or help you to 'join' the 'succubus' race.\n");
    set_level(16);
    set_heal(2,5);
    set_ac(13);
    set_wc(22);
    set_hp(400);
    set_al(-500);
    set_gender("female");
    set_aggressive(0);
    set_chat_chance(15);
    set_a_chat_chance(15);
    load_chat("The succubus looks at you and smiles.\n");
    load_chat("The succubus wonders if you are a succubus as well...?\n");
    load_chat("The succubus runs her fingers across her bare legs.\n");
    load_chat("The succubus winks at you.\n");
    load_a_chat("The succubus glares at you.\n");
    load_a_chat("The succubus says: Damn your soul to hades!\n");
    load_a_chat("The succubus kicks you where it hurts.\n");
    set_spell_mess1("The succubus slashes her foe with wicked looking nails.");
    set_spell_mess2("The succubus slashes your face with razor sharp nails!.");
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
  write("The succubus asks: You want to join what?\n");
  return 1;
        }
  if(str == "succubus")  {
  if(TPM < 5000)  {
  write("The succubus says: It costs 5000 golden coins to join the succubuss.\n");
  return 1;
        }

if(this_player()->query_possessive() == "his")  {
  write("The succubus hisses: This is a female only guild.\n");
   return 1;
        }
if(this_player()->query_possessive() == "its")  {
  write("The succubus hisses: This is a female only guild.\n");
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
  write("The succubus says: You belong to too many mini guilds.\n"+
    "Come back when you have left one.\n");
    return 1;
        }
  if(this_player()->query_age() < 10800)  {
    write("The succubus says: You are too young to join a mini guild.\n");
    return 1;
        }
  if(club_count > 0)  {
  if(this_player()->query_age() < 43200)  {
   write("The succubus says: You are too young to join 2 mini guilds.\n");
   return 1;
        }
        }
  move_object(clone_object("/players/saber/closed/new_mini/succubus.c"),this_player());
  say("The succubus whispers: Hello my sister...\n"+
   "The succubus places a leather choker around your neck.\n"+
   "The succubus kisses you lightly.\n");
  call_other(this_player(), "add_money", - 5000);
  return 1;
        }
        }

info()  {
write(
"Succubus are members of the elite female only succubus mini guild.  They are\n"+
"known for both their incredible beauty and the wiles with which they emply\n"+
"it.  Succubus have the power to see in the dark, charm their opponents, summon\n"+
"the dreaded succubus knife and produce a staggering array of sexy emotions.\n"+
"  **  Warning: Any male found in this mini guild through any way or with\n"+
"  **  a second character will be permanently removed from all mini guilds.\n"+
"  **  This is for fems only!\n\n");
  return 1;
        }
