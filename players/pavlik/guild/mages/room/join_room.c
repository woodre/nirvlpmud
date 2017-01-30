#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

#define TAM CYN+"Tamuli"+NORM

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Oval Office";
  long_desc=
	"You enter a tiny office built into the wall of the Tower.  In\n"+
	"front of you is a tiny desk, with a tiny chair seated in which is a\n"+
	"tiny man.  He stares you down with tiny eyes.  Tamuli taps his tiny pen\n"+
	"on his tiny desk impatiently.  There is a tiny sign on the back wall.\n";

  items=({
    "sign",
	"A tiny sign on the backwall reads:\n"+
	"Tamuli - Head Registrar of the Mages Guild.\n"+
	"If you are interested in becoming a member of the all-powerful Mages\n"+
	"guild, you may seek more information through the text 'info'.  If you\n"+
	"have fulfilled the requirements and would like to join now, use the\n"+
	"command word 'join' to get the Registrar's attention.  If you are a\n"+
	"current member and are having a problem use the command word 'register'\n"+
	"Thank You - Mgt\n",
  });

  dest_dir=({
	ROOM_DIR+"stairs1.c",	"north",
  });

  if(!present("tamuli", this_object()))
	move_object(clone_object(NPC_DIR+"tamuli"), this_object());

}

query_mguild(){ return "Registrar's"; }

init() {
  ::init();
  add_action("guild_move","gm");
  add_action("room_me", "roomme");
  add_action("help_guild","info");
  add_action("join_guild","join");
  add_action("leave_guild","leave");
  add_action("register","register");
}


leave_guild()
{
  int rank, gxp;
  int exp, minus;

  if(tp->query_guild_name() != "mage")
  {
	write(
	  TAM+" says: You aren't even a Mage!  How can you quit the Mages Guild when\n" +
	  "you were never in it!\n" +
	  TAM+" smirks at your stupidity.\n");
	return 1;
  }

  /*
   * NOTE: Only manual leaving for now.
   */
  write(TAM+" says: You will need to speak to a guild wizard for this.\n");
  return 1;

  rank = tp->query_guild_rank();
  gxp = tp->query_guild_exp();
  tp->add_guild_rank(-rank);
  tp->add_guild_exp(-gxp);
  tp->set_guild_name(0);

  write("Tamuli says:\n"+
  "  'So, you no longer want to be a Mage.  Cannot handle it?'\n"+
  "  'Too much pressure?  Your not up to the task, are you!?!'\n"+
  "Tamuli stares you down with his beady eyes.\n");
  write("Tamuli says:\n"+
  "  'Very well, go be a silly monk or something then.'\n"+
  HIR+"You feel weakened as all your Mage Powers are stripped away.\n"+NORM);

  this_player()->set_home("room/church");
  if(present("mageobj", tp))
    destruct(present("mageobj", tp));

  write_file("/players/pavlik/guild/mages/log/JOIN",
  tp->query_real_name()+"\t"+
  "LEFT the guild: "+ctime()+"\n");

  exp = this_player()->query_exp();
  minus = exp/6;
  this_player()->add_exp(-minus);
  save_object("players/pavlik/guild/mages/players/banned/"+tp->query_real_name());
   return 1;
}


join_guild()
{
  object obj;
  string ref;
  string where;
  int    lev;
  int    exlev;

  if(restore_object("players/pavlik/guild/mages/players/banned/"+
  tp->query_real_name()))
  {
	write(
	  TAM+" says: Ah yes, I remember you.\n" +
	  TAM+" says: You will have to seek special permission to enter this guild.\n");
	return 1;
  }

  if(tp->query_guild_name() == "mage")
  {
	write(
	  TAM+" says: "+ME+", you are already a member!\n" +
	  TAM+" says: If you are having a problem with your membership use 'register'.\n");
	return 1;
  }

  if(tp->query_guild_rank() > 0 || tp->query_guild_exp() > 0 ||
    tp->query_guild_name() != 0)
  {
	write(
	  TAM+" says: You must severe all times with other guilds before you can become "+CYN+"Magi"+NORM+".\n");
	return 1;
  }

  if(tp->query_npc() == 1)
  {
	destruct(this_player());
	write("NOPE!");
	return 1;
  }

  if(tp->query_level() < 6)
  {
	write(
	  TAM+" says: You must achievee "+HIC+"level 6"+NORM+" before you can be\n" +
	  "considered for the Mages Guild.\n");
	return 1;
   }

  /** Removing sponsorship requirements --Gnar **/
#if 0
  if(!present("mage_sponsor", tp))
  {
	write(
	  TAM+" says: You must have the sponsorship of a "+CYN+"Magi"+NORM+" before you\n" +
	  "can enter this guild.\n" +
	  TAM+" says: Take care of this obligation, then return here to me.\n");
	return 1;
  }
#endif


  if(call_other(tp, "query_attrib", "int") < 14)
  {
	write(
	  TAM+" says: You do not have the brains to be "+CYN+"Magi"+NORM+".\n" +
	  TAM+" says: Perhaps if you becom more "+HIW+"intelligent"+NORM+" you can join.\n");
	return 1;
  }

  if(call_other(tp, "query_attrib", "mag") < 16)
  {
	write(
	  TAM+" says: You are not strong enough in "+MAG+"Magic"+NORM+" to join this guild.\n" +
	  TAM+" says: Perhaps you should try again later.\n");
	return 1;
  }

#if 0
  ref = present("mage_sponsor", tp)->query_sponsor();
#endif

  write(
    TAM+" says: So, you wish to become Magi?  Let's see here ...\n"+
    TAM+" searches through the large stacks of paperwork on his desk.\n");
  write(
    TAM+" says: Yes, yes ...(nodding)... "+ME+", the sponsor requirement is "+HIM+"waived"+NORM+"...\n"+
    TAM+" says: Very good.  Everything seems to be in order here, "+HIC+"You may join"+NORM+".\n");
  write(
    "The Arch Mage stands and shakes your hand.\n");
  write(
    CYN+"Tamuli the Registrar"+NORM+" says: Now, go seek Calador and he will teach you your first spells\n");
  write("\n"+HIY+
  "[Welcome to the Guild.  ***Type 'mhelp get_started' for info!*** ]\n\n"+NORM);
  
  lev = tp->query_level();
  exlev = tp->query_extra_level();

  if(exlev)
  {
	lev=exlev-1;
	where = "/room/exlv_guild";
  }
  else
  {
	lev--;
	where = "/room/adv_guild";
  }
  
  lev = (int)where->get_next_exp(lev);
  tp->add_exp(-(tp->query_exp()-lev));
  
  say(TAM+" has inducted "+ME+" into the "+HIW+"Circle of "+NORM+HIC+"Mages"+NORM+"!\n");
  tell_members(tp->query_real_name(), "has been inducted into");

  obj = clone_object(GOB_FILENAME);
  move_object(obj, tp);
  tp->add_guild_exp(1);
  tp->set_guild_name("mage");
  tp->set_home(GUILD_HOME);
  
#if 0
  present("mageobj", tp)->set_sponsor(ref+"#0+");
  destruct(present("mage_sponsor", tp));
#endif
  command("renew", tp);
  command("calcxp", tp );

  write_file("/players/pavlik/guild/mages/log/JOIN",
  capitalize(tp->query_real_name())+"\t"+
  "joined: "+ctime()+"\n");

  return 1;
}


register(){
  object obj;
  string name, one, onetwo;
  name = allocate(16);

  name = this_player()->query_real_name();
  one = extract(name,0,0);
  one = capitalize(one);
  onetwo = one + extract(name,1,1);
  write(
  "Tamuli glares at you then pulls out a huge book and begins to flip\n"+
  "through the pages.\n"+
  "Tamuli mutters: ..."+one+"..."+one+"..."+onetwo+"...\n");

  if(restore_object("players/pavlik/guild/mages/players/banned/"+name)) {
    write("Tamuli says:\n"+
    "  'Ahh, here you are `"+capitalize(name)+"` ... '\n"+
    "  'You have been stricken from out lists.  You must speak to'\n"+
    "  'the Mages Council to resolve your problem.'\n");
    return 1;
  }

  if(!restore_object("players/pavlik/guild/mages/players/"+name)){
    write(
    "Tamuli says:\n"+
    "  'No, sorry.  Your name is not in our lists.  If you still'\n"+
    "  'believe you are a member of this guild you will have to'\n"+
    "  'bring this matter to the attention of the Mages Council.'\n"+
    "  'Good day.'\n");
    write(
    "Tamuli puts the tome away and resumes his work.\n");
    return 1;
  }

  write("Tamuli says:\n"+
  "  '"+capitalize(name)+", ah yes.  Here you are.'\n"+
  "  'Everything should be fine now, thank you for your patience.'\n"+
  "The registrar makes a quick note in the book.\n"+
  "Tamuli puts the tome away and resumes his work.\n");

  if(!present("mageobj", this_player())){
    string path;
    path = "/players/pavlik/guild/mages/mageobj2";
    write("cloning "+path+"\n");
    obj = clone_object(path);
    move_object(obj, this_player());
    command("renew", this_player());
  }
  this_player()->set_guild_name("mage");
  this_player()->set_home("/players/pavlik/guild/mages/room/guild_room5");
  return 1;
}

tell_members(whom, whatm){
  object ob;
  int i;
  ob = users();
  for(i = 0; i < sizeof(ob); i++) {
    if(present("mageobj", ob[i]))
      tell_object(ob[i],
      "[] Tamuli []: "+capitalize(whom)+"  "+whatm+
      " the Circle of Mages!\n");
  }
  return 1;
}


room_me(){
  object myroom;
  if(tp->query_guild_rank() < 30){
    write("Tamuli says: You are not senior enough in this guild.\n");
    write("Tamuli says: You must be guild rank 31 or higher.\n");
    return 1;
  }
  if(tp->query_money() < 12000){
    write("Tamuli says: You need 12,000 coins to purchase residence.\n");
    return 1;
  }
  if(restore_object("/players/pavlik/guild/mages/rooms/PROOMS/"+tp->query_real_name())){
    write("Tamuli says: You already have a residence here.\n");
    return 1;
  }
  write("Tamuli says: You want a residence here in the tower?\n"+
        "Tamuli says: Nothing easier, My friend!\n"+
        "The Registrar scribbles a couple of notes down in his book.\n"+
        "Tamuli says: It is done.\n");
  myroom = clone_object("players/pavlik/guild/mages/room/personal_room");
  myroom->set_owner(tp->query_real_name());
  myroom->do_save();
  destruct(myroom);
  this_player()->add_money(-12000);
  return 1;
}


help_guild()
{
  cat("/players/pavlik/guild/mages/help/join_info");
  return 1;
}


