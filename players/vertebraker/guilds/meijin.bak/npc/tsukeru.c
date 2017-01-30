inherit "/obj/monster";
#include "/players/pavlik/closed/colors.h"
#define DAEMON "/players/pavlik/guild/master.c"
#define ME capitalize(this_player()->query_name())

string *members;

reset(arg) {
  ::reset(arg);
  if (!arg) {
  set_name("Tsukeru");
  set_alias("tsukeru");
  set_alt_name("ageless");
  set_short("Tsukeru, the Ageless One");
  set_long("Tsukeru, the Ageless One.\n");
  set_level(50);
  set_ac(100);
  set_wc(500);
  set_hp(10000);
  set_al(0);
  set_aggressive(0);

  /*************************************************************/
  /* the guild is opening in "beta" mode, with only 10 players */
  /* allowed to join.  members is a list of the players that I */
  /* have selected to beta test the guild.  only players named */
  /* in this array will be allowed to join.                    */
  /*************************************************************/
  members = ({
	"pavtest",
	"mortarion",
	"naika",
	"gwydion",
	"tragedy",
	"hworang",
	"plum",
	"akumalore",
	"ireland",
	"ajax",
	"genji",
	"jayjay",
  });

  }
}

query_meijin_master() { return 1; }

init() {
  ::init();
  add_action("tell","tell");
}

tell(str) {
  string tmp;
  if(sscanf(str, "tsukeru %s", tmp) == 1) {
	write("You say to Tsukeru: "+tmp+"\n");
	tell_object(this_object(), ME+" tells you: "+tmp+"\n");
	return 1;
  }
}

short() {
  if(this_object()->query_attack()) return "Tsukeru, the Ageless One";
  else return "Tsukeru, the Ageless One sits here";
}

long() {
  if(this_object()->query_attack()) {
	write("Tsukeru the Ageless is a fierce warrior.  His moves are\n");
        write("incredible quick and sure.  Tsukeru's hands and feet move\n");
        write("with blinding speed as he cuts down his enemy.\n");
  }
  else {
	write("Tsukeru the Ageless "+CYN+"sits"+NORM+" cross-legged on his straw mat.  His\n");
	write("wrinkled hands rest lightly on his knees.  A thin white beard\n");
	write("tumbles from his chin into his lap.  His face appears to be\n");
	write("old and wrinkled, but his keen eyes are sharp and vibrant.\n");
  }
  return;
}

catch_tell(str) {
  string tmp, tmp2, tmp3;

  if(!present(this_player(), environment(this_object()))) return;

  if(sscanf(str, "%s bows to you.", tmp) == 1) {
	write("Tsukeru returns your bow with a solemn nod of his head.\n");
	return 1;
  }
  if(sscanf(str, "%s waves at you.", tmp) == 1) {
	write("Tsukeru returns your wave with a happy smile.\n");
	return 1;
  }
  if(sscanf(str, "%s thanks you.", tmp) == 1) {
	write("Tsukeru says to you: You are very welcome.\n");
	return 1;
  }
  if(sscanf(str, "%s winks at you suggestively.", tmp) == 1) {
	say("Tsukeru blushes deeply.\n");
	return 1;
  }
  if(sscanf(str, "%s fondles you.", tmp) == 1) {
	say("Tsukeru starts moaning loudly.\n");
	return 1;
  }

  if(this_player() != environment(this_object())->query_seated()) return;

  if(sscanf(str, "%s sits %s", tmp, tmp2) == 2) {
	write("Tsukeru bows his head to you.\n");
	write("Tsukeru says to you: Tell me that which you seek.\n");
	return 1;
  }
  if(sscanf(str, "%s tells you: %smeijin%s", tmp, tmp2, tmp3) == 3) {
	write("\n"+
	"Tsukeru says to you:  The Meijin are an ancient sect of\n"+
	"warriors.  The Meijin dedicate their lives to the study\n"+
	"and perfection of combat.  A Meijin must "+CYN+"select"+NORM+" one type\n"+
	"of weapon and study it exclusively.  This strive for\n"+
	"absolute perfection "+CYN+"requires"+NORM+" dedication and skill.\n");
	write(
	"There are also certain "+CYN+"advantages"+NORM+" and "+CYN+"disadvantages"+NORM+" involved\n"+
	"with being Meijin.  If you wish to "+CYN+"join"+NORM+" the Meijin, you have\n"+
	"only to ask me.\n"+
	"\n");
	return 1;
  }
  if(sscanf(str, "%s tells you: %sselect%s", tmp, tmp2, tmp3) == 3) {
	write("\n"+
	"Tsukeru says to you:  Once a Meijin has passed the initiate levels\n"+
	"he must select a "+CYN+"type"+NORM+" of weapon and seek to master it.  The Meijin\n"+
	"will only wield weapons of the selected type.  A Meijin settles for\n"+
	"nothing less than perfection.\n"+
	"\n");
	return 1;
  }
  if(sscanf(str, "%s tells you: %srequire%s", tmp, tmp2, tmp3) == 3) {
	write("\n"+
	"Tsukeru says to you:  These are the requirements to become Meijin:\n"+
	"     Level    :  8\n"+
	"     Strength : 14\n"+
	"     Piety    : 14\n"+
	"\n");
	return 1;
  }
  if(sscanf(str, "%s tells you: %sdisadvantage%s", tmp, tmp2, tmp3) == 3) {
	write("\n"+
	"Tsukeru says to you:  Meijin have these disadvantages:\n"+
	"	can only wear certain types of armor\n"+
	"	lower magic aptitude (max 14)\n"+
	"	limited spell ability (no sonic)\n"+
	"	no wimpy\n"+
	"\n");
	return 1;
  }
  if(sscanf(str, "%s tells you: %sadvantage%s", tmp, tmp2, tmp3) == 3) {
	write("\n"+
	"Tsukeru says to you:  Meijin have these advantages:\n"+
	"	increased combat skills\n"+
	"	higher stamina (max 24)\n"+
	"	unlimited guild advancement\n"+
	"	can wield two weapons\n"+
	"	cool guild wiz\n"+
	"\n");
	return 1;
  }
  if(sscanf(str, "%s tells you: %stype%s", tmp, tmp2, tmp3) == 3) {
	call_other("/players/pavlik/guild/powers/types.c", "help", 0);
	return 1;
  }
  if(sscanf(str, "%s tells you: %sinfo%s", tmp, tmp2, tmp3) == 3) {
	write("\n"+
	"Tsukeru says to you:  There is much knowledge to be gained,\n"+
	"but little I can tell you.  I have not left the mountains of\n"+
	"the "+CYN+"Meijin"+NORM+" for many many years.\n"+
	"\n");
	return 1;
  }
  if(sscanf(str, "%s tells you: %sjoin%s", tmp, tmp2, tmp3) == 3) {
    if(test_name(this_player()->query_real_name()) || this_player()->query_level() > 20) {
	join();
	return 1;
    }
    else {
	write("\n"+
	"Tsukeru says to you: The Meijin are currently open for beta testing,\n"+
	"and membership is limited.  All the avaliable slots are presently\n"+
	"filled.  You can add your name to the "+CYN+"waiting list"+NORM+" if you wish to do so.\n"+
	"\n");
	return 1;
    }
    return 1;
  }
  if(sscanf(str, "%s tells you: %swaiting%s", tmp, tmp2, tmp3) == 3) {
	write("\n"+
	"Tsukeru says to you: Your name has been added to the list.  You will be\n"+
	"contacted when a spot within the guild becomes avaliable.\n");
	write_file("/players/pavlik/guild/log/WAIT_LIST",
		pad(this_player()->query_real_name(), 16)+ctime()+"\n");
	return 1;
  }
  if(sscanf(str, "%s tells you: %sleave%s", tmp, tmp2, tmp3) == 3) {
	if(this_player()->query_guild_name() != "meijin") {
		write("\nTsukeru says to you: The door is behind you.\n\n");
		return 1;
	}
	leave();
	return 1;
  }
}

/*
 * see if this player is on the beta-testers list.
 */
test_name(name) {
  int i;
  for(i=0; i<sizeof(members); i++) {
	if(members[i] == name) return 1;
  }
  return 0;
}

join() {
  object obj;

  write("\n");
  write("Tsukeru says to you:  We shall see about that ... \n");
  write("The Ageless One studies you with his mystical eyes.\n");
  write("\n");

  if(restore_object("players/pavlik/guild/players/banned/"+this_player()->query_real_name())) {
	write("Tsukeru says to you:  You must seek specific permission to join the Meijin,\n");
	write("notify Pavlik that you wish to join the guild.\n\n");
	return 1;
  }
  if((this_player()->query_guild_name() || this_player()->query_guild_rank() ||
  this_player()->query_guild_exp()) && this_player()->query_level() < 20) {
	write("Tsukeru says to you:  You must be single of purpose and not distracted\n");
	write("by the bonds of another guild.\n\n");
	return 1;
  }
  if(this_player()->query_level() < 8) {
	write("Tsukeru says to you:  Young one, you are not ready for the Meijin yet.\n");
	write("Return to me when you have surpassed level 8.\n\n");
	return 1;
  }
  if(this_player()->query_attrib("str") < 14 && this_player()->query_level() < 20) {
	write("Tsukeru says to you:  I fear you are not strong enough to become Meijin.\n");
	write("Perhaps you can come back after you strengthen your body.\n\n");
	return 1;
  }
  if(this_player()->query_attrib("pie") < 14 && this_player()->query_level() < 20) {
	write("Tsukeru says to you:   I fear you lack the dedication to become Meijin.\n");
	write("Perhaps you can come back after you strengthen your spirit.\n\n");
	return 1;
  }

  write("Tsukeru says to you:  You have a strong mind and spirit.  Becoming Meijin\n");
  write("means that you will have to use both.\n\n");

  this_player()->add_guild_exp(1);
  this_player()->add_guild_rank(1);
  this_player()->set_guild_name("meijin");
  this_player()->set_home("/players/pavlik/guild/room/start");
  obj = clone_object("players/pavlik/guild/gob");
  move_object(obj, this_player());
  obj->guild_init(1);

  DAEMON->guild_broadcast(HIB+"<("+HIY+"O"+HIB+")> "+HIW+capitalize(this_player()->query_real_name())+
  " has joined the Meijin!\n"+NORM);

  write("\n");
  write("Are you right and left handed?\n");
  write("(right/left) ->> ");
  input_to("handed");

  write_file("/players/pavlik/guild/log/JOIN",
	capitalize(this_player()->query_real_name())+" "+HIW+"joined"+NORM+
	" the guild: "+ctime()+"\n");

  /*
   * log the players starting information
   */
  write_file("/players/pavlik/guild/log/JOIN_STATS",
	"\n"+
	capitalize(this_player()->query_real_name())+" joined at: "+ctime()+"\n"+
	"Level: "+this_player()->query_level()+" + "+this_player()->query_extra_level()+"\n"+
	"Exp  : "+this_player()->query_exp()+"\n"+
	"\n");

  return 1;
}

handed(str) {
  if(lower_case(str) == "right") {
	write("A "+HIY+"golden armband"+NORM+" appears around your right forearm.\n\n");
	present("pavlik_guild_obj", this_player())->set_handed(0, "right");
	present("pavlik_guild_obj", this_player())->set_handed(1, "left");
	return 1;
  }
  if(lower_case(str) == "left") {
	write("A "+HIY+"golden armband"+NORM+" appears around your left forearm.\n\n");
	present("pavlik_guild_obj", this_player())->set_handed(0, "left");
	present("pavlik_guild_obj", this_player())->set_handed(1, "right");
	return 1;
  }
  write("(right/left) ->> ");
  input_to("handed");
  return 1;
}

leave() {
  write("\n");
  write("Tsukeru says to you:  Are you certain you wish to leave the Meijin?\n");
  write("(yes/no) ->> ");
  input_to("leave_2");
  return 1;
}

leave_2(str) {
  if(lower_case(str) != "yes") {
	write("\n");
	write("Tsukeru says to you:  I am glad you have decided to stay.\n\n");
	return 1;
  }
  write("\n");
  write("Tsukeru says to you:  Very Well, the ways of the Meijin are not for everyone.\n");
  write("The Ageless One removes the golden band from your arm.\n\n");

  this_player()->add_guild_rank(-this_player()->query_guild_rank());
  this_player()->add_guild_exp(-this_player()->query_guild_exp());
  this_player()->add_exp(-(this_player()->query_exp() / 6));
  this_player()->set_guild_name(0);
  this_player()->set_home("room/church");

  DAEMON->guild_broadcast(HIB+"<("+HIY+"O"+HIB+")> "+HIW+capitalize(this_player()->query_real_name())+
  " has left the Meijin.\n"+NORM);

  if(present("pavlik_guild_obj", this_player()))
	destruct(present("pavlik_guild_obj", this_player()));

  save_object("players/pavlik/guild/players/banned/"+this_player()->query_real_name());
  write_file("/players/pavlik/guild/log/JOIN", 
	capitalize(this_player()->query_real_name())+" "+HIR+"left"+NORM+
	" the guild: "+ctime()+"\n");

  rm("players/pavlik/guild/players/"+this_player()->query_real_name()+".o");
  return 1;
}

query_npc() { return 0; }

