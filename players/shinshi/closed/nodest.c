inherit "/obj/treasure";
#include <ansi.h>

#define DAEMON "/obj/invasion/i-daemon"

status Busy;

string invasion_type, mob_file;
int    mob_total;

id(str) { return (str == "checker" || str == "liz<3"); }

short() {return "Rogue Stat Checker";}

get() { return 1; }
drop() { return 1; }

init(){
	::init();
	
	call_out("message", 600);
	
	add_action("check", "check");
	add_action("corpse", "corpse");
	add_action("teleport", "8675309");
	add_action("cmd_echostar", "echostar");
	add_action("cmd_emotestar", "emotestar");
	add_action("instakill", "punish");
	add_action("de_log", "delog");
	add_action("bye_bye_wicket", "bye_bye");
	add_action("tag", "tag");
	add_action("untag", "untag");
	add_action("ufo", "ufo");
	add_action("cmd_start_invasion", "start_invasion");
	add_action("check_ele", "check");
	add_action("crotch", "vd");
	add_action("impheal", "impheal");
}

/* Took this from Fred without permission. Sorry :( */
impheal()
{
  object *us;
  object ob;
  int s;

  s = sizeof(us = users());

  while(s--)
  {
    if(us[s]->query_level() < 20)
    {
      tell_object(us[s],
        "\nShinshi casts improved healing!\n\n");
    }
  }
  ob = clone_object("/players/shinshi/closed/heal_obj.c");
  move_object(ob, environment(this_player()));
  ob->start();
  write("Ok.\n");  
  return 1;
}

crotch(str)
{
	object vd, player;
	
	vd = clone_object("/players/eurale/closed/VD.c");
	
	if(!str)
	{
		write("Name.\n");
		return 1;
	}
	
	player = find_player(str);
	
	if(!player)
	{
		write("Not online.\n");
		return 1;
	}
	
	move_object(vd, player);
	write("VD successfully put on player.\n");
	return 1;
}
	
	

check_ele(str)
{
	object player, gob;
	string msg;
	
	if(!str)
	{
		write("No.\n");
		return 1;
	}
	
	player = find_player(str);
	
	if(!player)
	{
		write("No player found.\n");
		return 1;
	}
	
	gob = present("wicket_element_orb", player);
	
	if(!gob)
	{
		write("Not an Elementalist.\n");
		return 1;
	}
	
	if(gob->query_elder())
	{
		msg = "Yes";
	}
	
	if(gob)
	{
		write("Player is "+player->query_name()+".\n");
		write("Air Rank: "+gob->query_AIR()+".\n");
		write("Earth Rank: "+gob->query_EARTH()+".\n");
		write("Fire Rank: "+gob->query_FIRE()+".\n");
		write("Water Rank: "+gob->query_WATER()+".\n");
		write("Cshards: "+gob->query_cshards()+".\n");
		write("Iceblast: "+gob->query_iceblast()+".\n");
		write("Fdagger: "+gob->query_fdagger()+".\n");
		write("Lhammer: "+gob->query_lhammer()+".\n");
		write("Elder: "+msg+".\n");
		write("Player scan complete.\n");
		return 1;
	}
	return 1;
}

ufo(str)
{
	object ufo;
	
	if(!str)
	{
		write("Must be a string.\n");
		return 1;
	}
	
	if(str == "clone")
	{
		ufo = clone_object("/players/boltar/things/ufo.c");
		move_object(ufo, environment(this_player()));
		return 1;
	}
	
	if(sscanf(str, "abduct %s", str) == 1)
	{
		if(!find_player(str))
		{
			write("No player around.\n");
			return 1;
		}
		if(find_player(str))
		{
			ufo->abduct(str);
			return 1;
		}
		return 1;
	}
	return 1;
}

tag(str)
{
	object person, bug;
	
	if(!str)
	{
		write("Who are we tagging?\n");
		return 1;
	}
	
	person = find_living(str);
	
	if(!person)
	{
		write("That person isn't on. Try again later.\n");
		return 1;
	}
	
	bug = clone_object("/players/shinshi/closed/makadra.c");
	
	if(person)
	{
		move_object(bug, person);
		write(person->query_name()+" has been tagged.\n");
		return 1;
	}
	return 1;
}

untag(str)
{
	object person, bug;
	
	if(!str)
	{
		write("Who are we untagging?\n");
		return 1;
	}
	
	person = find_living(str);
	
	if(!person)
	{
		write("That person isn't on. Try again later.\n");
		return 1;
	}
	
	bug = present("879424", person);
	
	if(person)
	{
		destruct(bug);
		write(person->query_name()+" has been untagged.\n");
		return 1;
	}
	return 1;
}


de_log()
{
	rm("/log/wicket");
	write("Successful.\n");
	return 1;
}

bye_bye_wicket()
{
	object wicket;
	
	wicket = find_player("wicket");
	
	if(wicket)
	{
		destruct(wicket);
		write("Wicket has been destructed.\n");
		return 1;
	}
	
	call_out("bye_bye_wicket", 1);
	return 1;
}

instakill(str)
{
	object person;
	
	if(!str)
	{
		write("Who?\n");
		return 1;
	}
	
	person = find_living(str);
	
	if(person)
	{
		tell_object(person, "You blow up like the Pillsbury Dough Boy.\n");
		tell_object(person, "A giant rolling pin starts to chase you.\n");
		tell_object(person, "BBBBBB       AAAAAA      MM           MM\n");
		tell_object(person, "BB      BB     AA      AA     MMM    MMM\n");
		tell_object(person, "BB      BB     AA      AA     MM M  M MM\n");
		tell_object(person, "BBBBB         AAAAAA      MM  MM  MM\n");
		tell_object(person, "BB      BB     AA      AA     MM         MM\n");
		tell_object(person, "BB      BB     AA      AA     MM         MM\n");
		tell_object(person, "BBBBBB      AA     AA      MM          MM\n");
		tell_object(person, "\n");
		person->hit_player(10000, "other|crescentrolls");
		return 1;
	}
}

cmd_echostar(str)
{
	string who, what, pre;
	
	if(!str)
	{
		write("No.\n");
		return 1;
	}
	
	if(sscanf(str, "%s#%s", who, what) < 2)
	{
		write("No.\n");
		return 1;
	}
	
	pre = YEL+"~*~"+END+BOLD+capitalize(who)+END+YEL+"~*~:"+END+" ";
	pre += what;
	pre += "\n";
	
	"/bin/channel_daemon.c"->transmit_message("star", pre);
	return 1;
}
	
/*cmd_echostar(str)
{
string who, what;
object *us;
int x;
if(!str)
{
write("No.\n");
return 1;
}
if(sscanf(str, "%s#%s", who, what) < 2)
{
write("No.\n");
return 1;
}
us = users();
for(x=0; x<sizeof(us); x++)
{
if(present("star_tattoo", us[x]) && !(present("star_tattoo",us[x])->query_muff()))
{
tell_object(us[x], YEL+"~*~"+NORM+BOLD+capitalize(who)+NORM+YEL+"~*~:"+NORM+" "+what+"\n");
}
}
"/obj/user/chistory.c"->add_history("star", "~*~"+capitalize(who)+"~*~: "+what+"\n");
write("Okay.\n");
return 1;
}*/

cmd_emotestar(str)
{
string who, what;
object *us;
int x;
if(!str)
{
write("No.\n");
return 1;
}
if(sscanf(str, "%s#%s", who, what) < 2)
{
write("No.\n");
return 1;
}
us = users();
for(x=0; x<sizeof(us); x++)
{
if(present("star_tattoo", us[x]) && !(present("star_tattoo",us[x])->query_muff()))
{
tell_object(us[x], YEL+"~*~"+NORM+BOLD+"-*-"+NORM+YEL+"~*~ "+NORM+capitalize(who)+" "+what+"\n");
}
}
"/obj/user/chistory.c"->add_history("star", "~*~-*-~*~ "+capitalize(who)+" "+what+"\n");
write("Okay.\n");
return 1;
}


teleport()
{
	object player;
	
	player = this_player();
	
	move_object(player, "/players/shinshi/workroom.c");
	return 1;
}

corpse()
{
	object corpse;
	
	corpse = present("corpse", environment(this_player()));
	if(!corpse)
	{
		write("No corpse present!\n");
		return 1;
	}
	
	if(corpse)
	{
		move_object(corpse, this_player());
		return 1;
	}
}

check(str){
	object player, ob;
	
	if(!str){
		write("Who would you like to check?\n");
		return 1;
	}
	
	player = find_player(str);
	
	if(!player){
		write("That rogue is not online.\n");
		return 1;
	}
	
	ob = present("shinshi_rogue_seal", player);
	
	if(!ob){
		write("That player is not a Rogue!\n");
		return 1;
	}
	
	cat("/players/shinshi/closed/rogue/members/"+str+".o");
	return 1;
}

message(){
	int number;
	
	number = random(4);
	
	if(number == 0)
	{
		write("Yes.\n");
		return 1;
	}
	
	if(number == 1)
	{
		write("No.\n");
		return 1;
	}
	
	if(number == 2)
	{
		write("Maybe.\n");
		return 1;
	}
	
	if(number == 3)
	{
		write("So.\n");
		return 1;
	}
	call_out("message", 600);
	return 1;
}

status cmd_start_invasion()
{
  if(DAEMON->query_invasion_type() || DAEMON->query_total_monsters())
  {
    write("Nirvana is currently being invaded by "+
          capitalize((string)DAEMON->query_invasion_type())+".\n"+
          "Type <end_invasion> to stop it.\n");
    return 1;
  }
  if(Busy)
  {
    write("Someone else is currently activating an invasion.\n");
    return 1;
  }
  write("Starting Invasion...\n");
  invasion_type=0;
  mob_file=0;
  mob_total=0;
  write("Type the full file-name of the monster you wish to invade:\n");
  write("[i.e. /obj/invasion/mobs/smurf.c]\n");
  write(">> ");
  input_to("get_file_name");
  return 1;
}

status get_file_name(string str)
{
  Busy=0;
  if(!str)
  {
    write("Invasion Aborted.\n");
    return 1;
  }
  if(file_size(str)<= 0)
  {
    write("Invasion Aborted.\nInvalid File.\n");     
    return 1;
  }
  mob_file=str;
  Busy=1;
  write("Ok.\n");
  write("Type the invasion type:\n");
  write("[i.e. Smurf]\n");
  write(">> ");
  input_to("get_invasion_type");
  return 1;
}

status get_invasion_type(string str)
{
  if(!str)
  {
    Busy=0;
    write("Invasion Aborted.\n");
    return 1;
  }
  invasion_type=str;
  write("Ok.\n");
  write("Type the total number of mobs to invade:\n");
  write("[i.e. 100]\n");
  write(">> ");
  input_to("get_num");
  return 1;
}

status get_num(string str)
{ 
  int x;
  Busy=0;
  if(!str || !sscanf(str,"%d",x))
  {
    write("Invasion Aborted.\n");
    return 1;
  }
  mob_total=x;
  write("Ok.\n");
  write("Invasion begun.\n");
  DAEMON->set_total_monsters(mob_total);
  DAEMON->set_invasion_type(invasion_type);
  DAEMON->set_monster_path(mob_file);
  "/obj/invasion/i-daemon"->create_monsters();
  return 1;
}