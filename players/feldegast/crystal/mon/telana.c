#include "../defs.h"

inherit MONSTER;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("telana");
  set_alt_name("telana crystalstorm");
  set_short(HIC+"Telana"+NORM+BLU+" Crystalstorm");
  set_long(
"Telana Crystalstorm is a tall young woman, perhaps in her late 20's.\n"+
"Her honey-blonde hair is plaited down to her waist and her steel-grey\n"+
"eyes have flecks of violet.  She wears a white dress and a simple\n"+
"golden band on her left hand.  Telana was taught the ways of crystal\n"+
"magic by Feldegast himself and is now the tower's principle instructor.\n"
  );
  set_gender("female");
  set_race("human");
  set_level(23);
  set_wc(40);
  set_ac(30);
  set_hp(1000);
  set_al(600);
  load_spell(60, 30, 0,
    HIC+"\n\nTelana shoots a shard of crystal from the palm of her hand!\n\n",
    HIC+"\n\nTelana shoots a shard of crystal from the palm of her hand!\n\n");
  load_spell(100, 25, 0,
    "\n\nTelana bombards you with a "+HIR+"STORM OF CRYSTALS"+NORM+"\n",
    "\n\nTelana bombards #ATT# witha  "+HIR+"STORM OF CRYSTALS"+NORM+"\n");
  load_spell(80, 15, 0,
    "\n\nTelana focuses a "+HIR+"RAY OF LIGHT"+NORM+" upon you!\n",
    "\n\nTelana focuses a "+HIR+"RAY OF LIGHT"+NORM+" upon #ATT#!\n");
  set_a_chat_chance(5);
  load_a_chat("Telana's eyes glow brightly as wind whips about her hair!\n");
}

void long(string str)
{
  ::long(str);
  if(environment()->crystal_tower())
    write("You may: advance, join, abandon guild\n");
}

void init()
{
  ::init();
  if(present(GUILD_ID,TP))
  {
    add_action("cmd_advance", "advance");
    add_action("cmd_leave", "abandon");
  }
  else
    add_action("cmd_join", "join");
}

int cmd_join(string str)
{
  if(str != "crystal mages")
  {
    write("Join what?  Crystal Mages?\n");
    return 1;
  }
  if(present(GUILD_ID,TP))
  {
    write("You are already a crystal mage!\n");
    return 1;
  }
  if((string)TP->query_guild_name() == GUILD_NAME)
  {
    move_object(clone_object(GUILD_DIR+"gob.c"), TP);
    write("Telana heals your lifecrystal.\n");
    say("Telana heals "+TPN+"'s lifecrystal.\n");
    return 1;
  }
  if((int)TP->query_guild_name() ||
     (int)TP->query_guild_rank() ||
     (int)TP->query_guild_exp())
  {
    write("You already possess a guild, or your guild stats have not\nbeen properly cleared.\n");
    return 1;
  }
  if((int)TP->query_level() < 5)
  {
    write("You must be at least level 5 to join.\n");
    return 1;
  }
  write("Telana stares into your eyes as she places her hands upon your chest.\n"+
        "\t\"Are you sure you wish to do this? (y/n)\"\n");
  input_to("join_2");
  return 1;
}

void join_2(string str)
{
  if(environment(TP) != environment(this_object())) return;
  if(str!="y" && str!="Y" && str!="yes" && str!="YES")
  {
     write("Telana nods.  \"Very well.\"\n");
     return;
  }
  write("Telana closes her eyes as she places her hands over your heart\n"+
        "and concentrates.  \"Crystal is, in many ways, alien to the ways of man.\n"+
        "In order to manipulate the crystal magic, you must first become a little\n"+
        "more like IT.\"  With a shudder, you feel your heart slow within your chest.\n\n"+
        "Telana's eyes open, her blue eyes glowing with energy.\n\n"+
        "\"I am changing your heart into crystal.  It will be painful, but if you\n"+
        "survive, you will have a greater control over crystal magic than you would\n"+
        "have gained from a dozen years of study.\"\n\n"+
        "With a final flash of light, you feel your heart solidify into crystal.\n"+
        "Looking down, you see the lifecrystal now embedded in your chest.\n\n"+
        "Telana, now appearing her normal self again, smiles shyly at you and says\n"+
        "\"Welcome to the Crystal Mages!\n\n"+
        "Type "+BOLD+"info"+NORM+" for guild information.\n");
  say(TPN+" has joined the Crystal Mages!\n");
  CHANNEL->broadcast("Crystal", TPN + " has joined the Crystal Mages!\n");
  move_object(clone_object(GUILD_DIR+"gob.c"), TP);  
  TP->add_guild_rank(1);
  TP->add_guild_exp(1);
  TP->set_guild_name(GUILD_NAME);
  return;
}

int cmd_leave(string str)
{
  if(!str || str != "guild")
  {
    notify_fail("Abandon what?  Guild?\n");
    return 0;
  }
  write("Telana gazes you in the eye and asks, \"Are you sure you wish to abandon all that you\n"+
        "  have learned in this tower and be forever banished from its precincts? (y/n)\"\n");
  input_to("leave_2");
}

void leave_2(string str)
{
  if(lower_case(str) == "n")
  {
    write("Telana nods.  \"That is a wise decision.\"\n");
    return;
  }
  else if(lower_case(str) == "y")
  {
    move_object(clone_object("/players/feldegast/obj/freeze.c"), this_player());
    write("Telana says, \"You are a "+BOLD+"fool"+NORM+".  You do not "+HIR+"deserve"+NORM+" the "+HIW+"purity"+NORM+" of crystal.\"\n");
    write("With that, Telana grasps your "+HIC+"lifecrystal"+NORM+" and yanks it from your chest!\n");
    this_player()->set_guild_name(0);
    this_player()->add_guild_rank(-(int)this_player()->query_guild_rank());
    this_player()->add_guild_exp(-(int)this_player()->query_guild_exp());
    this_player()->set_home(0);
    if(present(GUILD_ID, TP)) destruct(present(GUILD_ID, TP));
    mv("/" + SAVE_DIR + lower_case(TPN) + ".o", BAN_DIR + lower_case(TPN));

/* Note to self: Check the best way to do this...This isn't right. */
    this_player()->add_exp(-((int)this_player()->query_exp()/3));
    this_player()->reset(1);

    call_out("leave_3", 1, this_player());
  }
}

void leave_3(object ob)
{
  tell_object(ob, "\nYou pass out from the pain.\n");
  this_object()->attacked_by(this_player());
  this_player()->hit_player(50 + random(250));
  if((int)ob->query_dead())
  {
    move_object(ob, "/room/church");
    if(present("freeze_ob", ob))
      destruct(present("freeze_ob", ob));
  }
  else
  {
    move_object(ob, ROOM_DIR + "outside.c");
    tell_room(ROOM_DIR + "outside", (string)ob->query_name()+" is tossed out of the tower.\n");
    call_out("leave_4", 3, ob);
  }
}

void leave_4(object ob)
{
  tell_object(ob, "\nWhen you wake up, you find yourself weak, hungry, and covered in blood.\n"+
                  "Your unconscious body was dragged outside the tower and tossed into the\n"+
                  "bushes.  You hope you made the right decision.\n");
  if(present("freeze_ob", ob))
    destruct(present("freeze_ob", ob));
}
