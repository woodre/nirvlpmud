#include "../defs.h"
#define Larn present("larn_obj", this_player())
#define Gothic present("gothic_obj", this_player())
#define Feline present("feline_obj", this_player())
#define Blade present("blade_obj", this_player())
#define Succubus present("succubus_obj", this_player())
#define Gypsy present("gypsy_obj", this_player())
#define Kender present("kender_obj", this_player())
#define Canine present("canine_obj", this_player())

inherit "obj/treasure";
int done;
int busy;
object ob;

reset(arg) 
{
  if(!arg)
  {
    set_id("black ball");
    set_short("A smooth Black Ball");
    set_alias("ball");
    set_long("This is a small shiney black ball. You feel it pulsing\n"+
           "even from afar. You might be able to 'grasp' it, if you\n"+
           "dare. You WILL lose all levels above 5 in the process.\n");
  }  
}

init()
{
  ::init();

  add_action("create_venom", "grasp");
  add_action("name_it", "name");
}

create_venom(string str)
{
  if(!str)
  { 
    write("Grasp what?\n");
    return 1;
  }
  if(done) return 0;
  if(TP->QL < 5)
  {
    write("You are not of sufficient level to accept the symbiote!\n");
    return 1;
  }
  if(TP->query_guild_name() && TP->query_guild_name() != 0)
  {
    write("You are in a guild.\n"); 
    return 1; 
  }
  if(TP->query_guild_rank())
  { 
    write("You are in a guild.\n"); 
    return 1; 
  }
  if(TP->query_guild_exp())
  { 
    write("You are in a guild.\n"); 
    return 1; 
  }

  write("As you grasp the Black Ball you feel something sharp prick your palm...\n");
  write(""+HIR+"AND PAIN COURSES INTO YOUR BODY..."+NORM+"\n");		
  write_file("/players/fred/log/VENOM", ctime(time())+"  "+TP->QRN+"\n");
  
  if(TP->query_exp() > 5885) 
  {
    TP->add_exp(-(TP->query_exp() - 5885));
    TP->set_level(5);
    TP->set_extra_level(0);
  } 
  if(TP->query_attrib("str") > 14)
  {
    write("         Strength drops...\n");
    TP->set_attrib("str", 14);
  }
  if(TP->query_attrib("mag") > 5)
  {
    write("         Magic drops...\n");
    TP->set_attrib("mag", 5);
  }
  if(TP->query_attrib("ste") > 14)
  {
    write("         Stealth drops...\n");
    TP->set_attrib("ste", 14);
  }
  if(TP->query_attrib("wil") > 14)
  {
    write("         Willpower drops...\n");
    TP->set_attrib("wil", 14);
  }
  if(TP->query_attrib("sta") > 14)
  {
    write("         Stamina drops...\n");
    TP->set_attrib("sta", 14);
  }
  if(TP->query_attrib("luc") > 14)
  {
    write("         Luck drops...\n");
    TP->set_attrib("luc", 14);
  }
  if(TP->query_attrib("pie") > 14)
  {
    write("         Piety drops...\n");
    TP->set_attrib("pie", 14);
  }
  if(TP->query_attrib("int") > 14)
  {
    write("         Intelligence drops...\n");
    TP->set_attrib("int", 14);
  }
  if(TP->query_attrib("dex") > 14)
  {
    write("         Dexterity drops...\n");
    TP->set_attrib("dex", 14);
  }
  if(TP->query_attrib("cha") > 14)
  {
    write("         Charisma drops...\n");
    TP->set_attrib("cha", 14);
  }
  if(Larn)
    destruct(Larn);
  if(Gothic)
    destruct(Gothic);
  if(Feline)	
    destruct(Feline);
  if(Blade)
    destruct(Blade);
  if(Succubus)
    destruct(Succubus);
  if(Gypsy)
    destruct(Gypsy);
  if(Kender)
    destruct(Kender);
  if(Canine)
    destruct(Canine); 
 
  tell_object(TP, "Mini-guilds destroyed...\n");
  TP->save_me();
  TP->reset();
  ob = clone_object("/players/fred/closed/venom/venom.c");  
  ob->add_mp(10);
  move_object(ob, TP);
  present("venom_object", TP)->ssave();
  done = 1;
  call_out("after_shock", 3, TP);
  return 1;
}		

after_shock(object ob)
{
  tell_object(ob,
    "\nThe Ball hums with life energy...\n"+
    "A piercing pain flows from your hands through your chest and into\n"+
    "your back!\n\n");
  call_out("after_shock1", 4, ob);
  return 1;
}

after_shock1(object ob)
{
  tell_object(ob,
    "The symbiotic form has traveled through your body and into your back,\n"+
    "wrapping itself about your spine.\n\n");

  tell_object(ob,
    "Even though the pain was almost unendurable, you feel a certain\n"+
    "warmth in knowing that you are now not alone.  A life form, as of\n"+
    "a stranger to you, speaks into your mind...\n\n");

  call_out("after_shock2", 5, ob);
  return 1;
}

after_shock2(object ob)
{
  tell_object(ob,
    "It says with a hiss,'Feed me, give me life, and I will insure your success\n"+
    "throughout all eternity.  I will lend you my power.  I will fill you with\n"+
    "knowledge. With our joining we will conquer all.'\n\n");

  tell_object(ob,
    "You feel as one with this being, you no longer feel the need to\n"+
    "say 'I' or 'Me', life as you know it will be shared as 'We'...\n\n\n");

  call_out("now_name", 7, ob);
  return 1;
}

now_name(object ob)
{
  tell_object(ob,
    "You feel a little strange thinking to yourself and sharing\n"+
    "all of your thoughts with this creature...Perhaps it would\n"+
    "help to 'name' it?\n\n\n");
  done = 0;
  return 1;
}

name_it(string str)
{
  int i;
  string named;
  string named2;
  if(present("venom_object", TP))
  {
    if(present("venom_object", TP)->query_symbiote() != "unnamed")
    {
      return 0;
    }
  }
  if(!str)
  {
    write("Name it what? name <name>\n");
    return 1;
  }
  named = lower_case(str);
  named2 = strlen(named);
  i=0;
  while(i < named2) 
  {
    if(str[i] < 'a' || str[i] > 'z') 
    {
      write("Invalid name:" + str + "\n");
      return 1;
    }
    i += 1;
  }
  write_file("/players/fred/log/vname",
  TP->QRN+" named "+named+"\n");
  present("venom_object", TP)->set_symbiote(named);
  write("You feel a sudden surge of content as your symbiote considers the name...\n");
  write("It speaks into your mind: '"+capitalize(str)+" will do nicely.'\n");
  command("save", TP);
  return 1;
}

query_weight(){ return 1000000; }
query_value(){ return 0; }
