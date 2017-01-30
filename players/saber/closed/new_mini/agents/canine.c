#define TPM this_player()->query_money()
#define tp this_player()->query_name()

inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("dog");
    set_short("A small dog");
    set_race("canine");
     set_long("A small black dog with dark fur.\n"+
"You think it could give you 'info' or help you 'join' the 'canines'\n");
    set_level(8);
    set_heal(2,5);
    set_ac(15);
    set_wc(19);
    set_hp(1000);
    set_al(450);
    set_gender("creature");
    set_aggressive(0);
    set_chat_chance(15);
    set_a_chat_chance(15);
    load_chat("The dog wonders if you are a canine...?\n");
    load_chat("The dog looks at you.\n");
    load_chat("The dog scratches himself.\n");
       load_chat("The dog barks at something he hears.\n");
       load_chat("The dog chews on his leg.\n");
       load_chat("The dog eyes you.\n");
     load_a_chat("The dog growls.\n");
     load_a_chat("The dog glares at you with menacing eyes.\n");
     set_spell_mess1("The dog tears flesh from its foe.\n");
     set_spell_mess2("The dog tears flesh from its foe.\n");
    set_chance(20);
    set_spell_dam(25);
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
  write("The dog barks: You want to join what?\n");
  return 1;
        }
  if(str == "canines")  {
  if(TPM < 5000)  {
write("The dog barks: It costs 5000 golden coins to join the canines.\n");
  return 1;
        }

if(present("feline_obj",this_player()))  {
write("The canine barks: 'We don't like your kind here!'\n");
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
  write("The dog barks: You belong to too many mini guilds.\n"+
    "Come back when you have left one.\n");
    return 1;
        }
  if(this_player()->query_age() < 10800)  {
    write("The dog barks: You are too young to join a mini guild.\n");
    return 1;
        }
  if(club_count > 0)  {
  if(this_player()->query_age() < 86400)  {
    write("The dog barks: You are too young to join 2 mini guilds.\n");
    return 1;
        }
        }

move_object(clone_object
("/players/saber/closed/new_mini/canine.c"),this_player());
  say("The dog barks: Welcome!!!\n"+
    "The dog gives you a tattered collar to wear.\n"+
   "The dog grins, showing you his fangs.\n");
  call_other(this_player(), "add_money", - 5000);
  return 1;
        }
        }

info()  {
write("\n"+
"The Canines are the mini guild composed entirely of dogs or people with a very\n"+
"canine nature.  Canines have have some handy battle tricks and have lots of fun\n"+
"canine emotions.  The Canines are a good mini guild for those of you who enjoy\n"+
"the hunt and the role playing emotions.\n");
  write("\n");
  return 1;
        }
