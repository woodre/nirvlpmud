#define TPM this_player()->query_money()
#define tp this_player()->query_name()

inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("kender");
    set_short("A small kender with a hoopak");
    set_race("kender");
    set_long("A small kender with a hoopak and a big grin.\n"+
     "You think he could give you 'info' or help you to 'join' the 'kender' race.\n");
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
    load_chat("The kender looks at your pockets and smiles.\n");
    load_chat("The kender whistles innocently.\n");
    load_chat("The kender asks: Are you a kender too?\n");
    load_chat("The kender searches his bag.\n");
    load_chat("You catch the kender reaching for your weapon.\n");
    load_a_chat("The kender wonders if you are usually this clumsy.\n");
    load_a_chat("The kender sticks his tongue out at you.\n");
    set_spell_mess1("The kender bops his opponent over the head with a hoopak.");
    set_spell_mess2("The kender bops you over the head with his hoopak!");
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
  write("The kender asks: You want to join what?\n");
  return 1;
        }
  if(str == "kender")  {
  if(TPM < 5000)  {
  write("The kender says: It costs 5000 golden coins to join the kenders.\n");
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
  write("The kender says: You belong to too many mini guilds.\n"+
    "Come back when you have left one.\n");
    return 1;
        }
  if(this_player()->query_age() < 10800)  {
    write("The kender says: You are too young to join a mini guild.\n");
    return 1;
        }
  if(club_count > 0)  {
  if(this_player()->query_age() < 43200)  {
    write("The kender says: You are too young to join 2 mini guilds.\n");
    return 1;
        }
        }
  move_object(clone_object("/players/saber/closed/new_mini/kender.c"),this_player());
  say("The kender says: Welcome!!!\n"+
    "The kender gives you a hoopak.\n"+
    "The kender hugs you.  (check your pockets)\n");
  call_other(this_player(), "add_money", - 5000);
  return 1;
        }
        }

info()  {
write("\n"+
"Kenders are the diminutive race straight from Dragonlance.  If you're a\n"+
"Kender, sign up here.  If not, don't bother.  If you don't love them already,\n"+
"you'll hate the mini guild.  For those of you that don't know, Kenders are\n"+
"very innocent little people with no fear and overactive senses of imagination.\n"+
"They carry all sorts of items in their kender bags, and always have a hoopak\n"+
"handy.\n\n");
  return 1;
        }
