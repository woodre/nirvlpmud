inherit "/room/room";
#include <ansi.h>
#define PATH "/players/shinshi/areas/pk/rooms/"
#define MAALOX "players/eurale/VAMPIRES/OBJ/maalox"
#define STONE "players/jareel/heals/stone"
#define JAR "players/jaraxle/3rd/pyramid/items/prize3"


int cost, prize;
string *fools;
string *nontox, *illegal;


reset(arg)
{
::reset(arg);

if(!present("shinshi_plaque")) {
	move_object(clone_object("/players/shinshi/areas/pk/objs/plaque.c"),this_object());
}

if(arg) return;

        fools = ({ });

        nontox = ({
          "players/snow/heals/ice_sphere",
          "players/jenny/wings/items/painkillers",
          "players/jaraxle/closed/phoenix/heals/tear",
          "players/zeus/heals/demon_heart",
          "players/shinshi/areas/school/heals/bubbling",
        });

        illegal = ({
          "obj/heal",
          "players/hippo/heals/dna_repair",
          "players/wocket/turtleville/OBJ/regen_potion",
          "players/wocket/turtleville/OBJ/heal_potion",
          "players/saber/food/hscroll1",
          "players/snow/closed/q/polar_hide",
          "players/mizan/etherial/heals/gargle-blaster",
          "players/fred/forest/Obj/lcocaine",
          "players/hurtbrain/castello/pillow",
          "players/mythos/closed/guild/forest/armor/tunic",
          "players/mouzar/castle/under/obj/heal",
        });


	set_light(1);
	short_desc = "The "+HIK+"PK Tournament"+NORM+" entrance.";
	long_desc =
		"This is the entrance to the "+HIK+"PK Tournament "+NORM+".\n"+
		"To the left is a small desk with a bunch of sign-up sheets where\n"+
		"players may sign up for any upcoming PK Tournaments. On the wall\n"+
		"is a white piece of paper with an "+HIR+"agreement"+NORM+" on it.\n";
items =
({
	"agreement",
	"An agreement that has been pinned to the wall. You can 'view' it",
	"paper",
	"An agreement that has been pinned to the wall. You can 'view' it",
	"notice",
	"A paper that is pinned next to the agreement. You can 'view' it",
	"sheets",
	"A sign-up sheet that requires you to 'view agreement' before signing",
	"desk",
	"A desk that has sign-up sheets taped to it",
});

dest_dir =
({
	"/room/vill_green.c",	"green",
});
}



realm(){ return "NT"; }

init()
{
	::init();
	
	add_action("register", "register");
	add_action("view", "view");
        add_action("Cmd_prize", "prize");
 
        if(this_player()->query_level() > 19)
        {
          add_action("Cmd_start", "start");
          add_action("Cmd_clear", "clear");
          add_action("Cmd_check", "check");
          add_action("Cmd_scan", "scan");
          add_action("Cmd_dragon", "dragon");
        }
}

register()
{
        object *obj;
	int i;
        string path;

	cost = 15000;
	if (call_other(this_player(), "query_money", 0) < cost) 
        {
		write("You do not have enough money to register for the tournament\n");
		return 1;
	}
	
        if(!this_player()->query_pl_k())
        {
          write("You must have your PK set to register for this event.\n");
          return 1;
        }
        if(member_array(this_player()->query_real_name(), fools) > -1)
        {
          write("You have already registered.\n");
          return 1;
        }

        path = "/players/shinshi/areas/pk/logs/"+this_player()->query_real_name();
        write_file(path,  capitalize(this_player()->query_real_name())+" brought in:\n\n");

        obj = deep_inventory(this_player());
        
        for(i=0; i < sizeof(obj); i++)
        {
          write_file(path,
            object_name(obj[i])+" "+obj[i]->short()+"\n"); 
        }
        
	write("You pay the 15,000 coins to register for the PK Tournament.\n");
	this_player()->add_money(-15000);

        prize += 15000;

        fools += this_player()->query_real_name();

	write_file("/players/shinshi/areas/pk/logs/reg", this_player()->query_name() + " has entered the tourney " + ctime()[4..15] + "\n");
	return 1;
	
	write("At this time, you may not register for the tournament.\n");
	return 1;
}

view(str)
{
	if(!str)
	{
		write("What would you like to view?\n");
		return 1;
	}
	
	if(str != "agreement" && str != "notice" && str != "commands")
	{
		write("That is not here to view!\n");
		return 1;
	}
	
	if(str == "agreement")
	{
		cat("/players/shinshi/areas/pk/agreement.txt");
		return 1;
	}
	if(str == "notice")
	{
		cat("/players/shinshi/areas/pk/notice.txt");
		return 1;
	}
	
	if(str == "commands")
	{
		cat("/players/shinshi/areas/pk/commands.txt");
		return 1;
	}
}

Cmd_start()
{
  int i,x;
  string where;
  
  x = sizeof(fools);

  for(i=0; i<x; i++)
  {
    switch(random(16))
    {
      case 0: where = PATH+"rm1"; break;
      case 1: where = PATH+"rm2"; break;
      case 2: where = PATH+"rm3"; break;           
      case 3: where = PATH+"rm4"; break;
      case 4: where = PATH+"rm5"; break;
      case 5: where = PATH+"rm6"; break;
      case 6: where = PATH+"rm7"; break;
      case 7: where = PATH+"rm8"; break;
      case 8: where = PATH+"rm9"; break;
      case 9: where = PATH+"rm10"; break;
      case 10: where = PATH+"rm11"; break;
      case 11: where = PATH+"rm12"; break;
      case 12: where = PATH+"rm13"; break;
      case 13: where = PATH+"rm14"; break;
      case 14: where = PATH+"rm15"; break;
      case 15: where = PATH+"rm16"; break;
     }
   find_player(fools[i])->heal_self(10000);
   move_object(find_player(fools[i]), where);
   tell_object(find_player(fools[i]),
     "\n"+HIR+this_player()->query_name()+" launches you into the colosseum for battle."+NORM+"\n\n");
   command("look", find_player(fools[i]));
  }
  fools = ({ });
  return 1;
}

Cmd_prize()
{
  tell_object(this_player(),
    "The total prize money is currently "+prize+".\n");
  return 1;
}

Cmd_clear()
{
  fools = ({ });

  prize = 0;

  tell_object(this_player(),
    "Clearing registered players.....Done.\n");
  return 1;
}

Cmd_check()
{
  object *obj;
  object ppl, ppls;
  int a,b,reg,non,mal,sto,ill,jar;
  int x,y;
  string str1, str2, str3;

  ppl = first_inventory(environment(this_player()));

  while(ppl)
  {
    reg = 0;
    non = 0;
    mal = 0;
    sto = 0;
    ill = 0;
    jar = 0;

    ppls = next_inventory(ppl);
      
    obj = deep_inventory(ppl);
    
    for(a=0; a < sizeof(obj); a++)
    {
      if(obj[a]->is_heal())
      {
        str1 = object_name(obj[a]);
        sscanf(str1, "%s#%s", str2, str3);
      
        if(member_array(str2, nontox) > -1)
          non++;
         
        if(str2 == MAALOX)
          mal++;
            
        if(str2 == STONE)
          sto++;

        if(str2 == JAR)
          jar++;
          
        if(str2 != STONE && str2 != MAALOX && str2 != JAR &&
           (member_array(str2, nontox) == -1)) 
        {
          b = obj[a]->query_charges();
          reg += b;
        }
      }
      str1 = object_name(obj[a]);
      sscanf(str1, "%s#%s", str2, str3);

      if(member_array(str2, illegal) > -1)
        ill++;
   
    }
    if(ppl->is_player() && ppl->query_level() < 20)
    {
      if(reg > 150)
        tell_object(this_player(),
          ppl->query_name()+" has "+reg+" regs which is too many.\n");

      if(non > 10)
        tell_object(this_player(),
          ppl->query_name()+" has "+non+" nons which is too many.\n");
       
      if(mal > 21)
        tell_object(this_player(),
          ppl->query_name()+" has "+mal+" maalox which is too many.\n");
       
      if(sto > 5)
        tell_object(this_player(),
          ppl->query_name()+" has "+sto+" stones which is too many.\n");

      if(jar > 25)
        tell_object(this_player(),
          ppl->query_name()+" has "+jar+" jars which is too many.\n");

      if(((sto * 150) + (mal * 50) + (jar * 30)) > 750)
        tell_object(this_player(),
          ppl->query_name()+" has too many total detoxers.\n");
      
      if(ill > 0)
        tell_object(this_player(),
          ppl->query_name()+" has an illegal heal.\n");

     }
     ppl = ppls;   
  }
  return 1;
}
      
Cmd_scan(str)
{
  mapping heals;
  object ob, who;
  string *indices;
  int total;
  int i;

  who = find_player(str);
  
  if(!who)
  {
    write("Scan who?\n");
    return 1;
  }

  heals=([ ]);

  ob=first_inventory(who);

  while(ob)
  {
    if(ob->is_heal())
    {
      heals[ob->query_short()?ob->query_short():ob->short()]+=1;
      total++;
    }
    ob=next_inventory(ob);
  }

  indices=keys(heals);

  tell_object(this_player(),
    "Heals                         Charges\n"+
    "-------------------------------------\n");

    for(i=0; i < sizeof(indices); i++)
    {
      tell_object(this_player(),
        indices[i]);
      tell_object(this_player(),
        "\t\t\t"+heals[indices[i]]+"\n");
  }
  return 1;
}

Cmd_dragon(str)
{
  string who;
  object obj;

  if(!str)
  { 
    tell_object(this_player(),
      "Who are we checking?\n");
    return 1;
  }
  
  who = find_player(str);

  if(!who)
  {
    tell_object(this_player(),
      "Can't locate "+capitalize(str)+".\n");
    return 1;
  }

  obj = present("shardak_mark", who);  

  if(!obj)
  {
    tell_object(this_player(),
      capitalize(str)+" is not a Shardak.\n");
    return 1;
  }
  if(!obj->Dragon())
  {
    tell_object(this_player(),
      capitalize(str)+" does not have a dragon summoned.\n");
    return 1;
  }

  tell_object(this_player(),
    capitalize(str)+" has a dragon summoned.\n");
  return 1;
}      

pk_tourney(){ return 1; }
