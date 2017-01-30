inherit "obj/treasure";
#include "/obj/ansi.h"
#define ATT ppl[i]->query_attack()
#define ATTN ppl[i]->query_attack()->query_name()
#define STUFF "/players/fred/closed/stuff.c"
#define MO move_object
#define CO clone_object
#define TO this_object()
#define ENV environment
#define JUNK "/players/fred/closed/junk.c"

reset (arg) {
if (!arg){
   set_id("telltell");
  set_long("My own wierd tell.\n"); } }

short(){
  if(this_player() != environment()) tell_object(environment(),
   "You were just viewed by "+capitalize(this_player()->query_real_name())+".\n");
    return "Woodchucktell";
  }

init() {
  if(this_player()->query_real_name() != "fred") destruct(this_object());
::init();
  add_action("tell_cmd", "tell");
  add_action("whonew", "who"); 
  add_action("say_cmd", "say"); 
  add_action("say_cmd", "'");
  add_action("hist_cmd","hname");
  add_action("cmd_finger","fin");  
  add_action("cmd_inv","INV");
  add_action("scry","scry");
  add_action("gaze","gaze");
  add_action("s_hand","shand");
  add_action("s_idest","sidest");
  add_action("cmd_echostar","echostar");
  add_action("cmd_emotestar","emotestar");
  add_action("cmd_snowball", "snowball");
  add_action("cmd_doall", "doall");
  add_action("cmd_doublexp", "doublexp");
  add_action("cmd_heal_boost","healboost");
  add_action("cmd_detox","detoxboost");
  add_action("cmd_leave","harhar");
  add_action("cmd_scan", "sscan");
  add_action("cmd_fexec", "incognito_exec");
  add_action("cmd_rcolor", "rcolor");
  add_action("cmd_rweapon", "rweapon");
  add_action("cmd_ranimal", "ranimal");
  add_action("cmd_rdino", "rdino");
}

drop(){ return 1;}

cmd_leave()
{
  move_object(this_player(), "/players/fred/workroom.c");
  write("Done.\n");
  return 1;
}

tell_cmd(str) {
  string what;
  object who;
  if(!str){ write("Tell who what?\n");
  return 1; }
  if(!sscanf(str, "%s %s", str, what)) {
    write("Tell who what?\n");
  return 1; }
    who = find_player(str);
  if(!who){   write("That person isn't logged on. \n");  return 1; }
  tell_object(who,
  BOLD+BLK+"("+BLU+"//"+YEL+environment()->query_name()+BLU+"//"+BLK+")"+NORM+": "+what+"\n");
  write("You tell "+capitalize(str)+": "+what+"\n");
  who->add_tellhistory(capitalize(this_player()->query_name())+" told you: "+what+"");
  who->Replyer("fred");
  return 1; }

say_cmd(str){
  if(!str) { write("Say what?");
  return 1; }
  write(HIY+"You say: "+NORM+str+"\n");
  say(HIY+"Fred says: "+NORM+str+"\n");
  return 1; }
  
whonew(){
 object* ppl;
  int i;
  ppl = users();
  write(
"Name:         HP:         Money:      Experience:    Level:    Fighting:\n");

  for(i = 0; i < sizeof(ppl); i++){

  tell_object(this_player(),
pad(ppl[i]->query_real_name()+"           ", 14));
tell_object(this_player(),
pad(ppl[i]->query_hp()+"/"+ppl[i]->query_mhp()+"    ", 12));
tell_object(this_player(),
pad(ppl[i]->query_money()+"           ", 12));
tell_object(this_player(), pad(ppl[i]->query_exp()+"         ", 15));
if(ppl[i]->query_extra_level()){
tell_object(this_player(),
pad(ppl[i]->query_level()+"+"+ppl[i]->query_extra_level()+"      ", 10));
}
else{                                                                          
tell_object(this_player(),
pad(ppl[i]->query_level()+"        ", 10));
 }
if(ATT){
tell_object(this_player(),
ATTN+" ["+ATT->query_hp()+"/"+ATT->query_mhp()+"]\n");
 }
else{
tell_object(this_player(),
"Not fighting.\n");
}

 }
return 1;
} 

cmd_finger(str){
  object fucko;
  fucko = clone_object("/players/mythos/closed/play/finger.c");
  move_object(fucko, this_player());
  command("fin "+str, this_player());
  destruct(fucko);
  return 1; }

 hist_cmd(str){
   object FREAK;
   if(!str){ write("Read what?\n"); return 1; }
    FREAK = find_player(str);
   if(!FREAK){ write("That person is not logged on!\n"); return 1; }
    write(BOLD+GRN+"           "+capitalize(str)+"'s Tellhistory\n"+NORM);
    write(BOLD+GRN+"< --  --  --  --  --  --  --  --  --  -- >"+NORM+"\n\n");
    FREAK->write_tellhistory();
    write(BOLD+GRN+"< --  --  --  --  --  --  --  --  --  -- >"+NORM+"\n");
    return 1; }
 
cmd_inv(str){
  object shit, blah;
  shit = clone_object("/players/fred/closed/invtool.c");
  move_object(shit, this_player());
  blah = find_player(str);
  if(!blah){ write("What?\n"); 
  destruct(shit);
  return 1; }
  command("INV "+str, this_player());
  destruct(shit);
  return 1; }

s_hand(str) { 
string what,name;
object ob,targ;
ob = 0;
  if(!str) return 0;
if(sscanf(str,"%s %s",name,what) != 2) return 0;
  targ = find_player(name);
  if(!targ) { write("Target not in play.\n"); return 1; }
  if(catch(ob = clone_object(what)))
    return (write("Object did not clone.\n"), 1);
  move_object(ob,targ);
  write("You have cloned "+what+" to "+name+"\n");
return 1; }

s_idest(str) { 
string name,what;
object ob,targ;
  if(!str) return 0;
 if(sscanf(str,"%s %s",name,what) != 2) return 0;
  targ = find_player(name);
  if(!targ) { write("Target is not in play.\n");
    return 1; }
  ob = present(what,targ);
  if(!ob) { write("Object is not on target.\n");
   return 1; }
  destruct(ob);
  write("You have dested "+what+" off "+name+"\n");
return 1; }

scry(string str) {
  object person,ob,special;
  if(!str) {
    write("Usage: scry <living>.\n");
 return 1;
  }
  person=find_player(str);
  if(!person)
    person=find_living(str);
  if(!person) {
    write(str+" can not be found.\n");
    return 1;
  }
  person->long();
  special=first_inventory(person);
  while(special) {
    string extra_str;
    extra_str=special->extra_look();
    if(extra_str)
       write(extra_str+".\n");
    special=next_inventory(special);
  }
write(capitalize(person->query_pronoun())+" is carrying: \n");
  ob = first_inventory(person);
  while (ob) {
    string sh;
    sh = call_other(ob, "short");
    if (sh)
    write(sh + ".\n");
    ob = next_inventory(ob);
  }
  return 1;
}

gaze(string str) {
  object person;
  object ob;
  if(!str) {
    write("Usage: gaze <living>\n");
    return 1;
  }
person=find_player(str);
  if(!person)
    person=find_living(str);
   if(!person || !environment(person)) {
    write(str+" can not be found.\n");
    return 1;
  }
  environment(person)->long();
  ob = first_inventory(environment(person));
  while (ob) {
    string sh;
    sh=ob->short();
    if(sh) write(sh + ".\n");
    ob=next_inventory(ob);
  }
  return 1;
}

cmd_echostar(str)
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
}

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

cmd_snowball(str) 
{
  string who;
  int x,y;
  
  if(!str)
  { 
    write("snowball <name> <num>\n");
    return 1; 
  }
  if(!sscanf(str, "%s %d", str, x)) 
  {
    write("snowball <name> <num>\n");
    return 1; 
  }
  
  who = find_player(str);

  if(!who)
  {   
    write("That person isn't logged on. \n");  
    return 1; 
  }
  
  while(y < x)
  {
    command("clone /players/wizardchild/toys/snowball.c", this_player());
    command("throw snowball at "+str+"", this_player());
    y++;
  }
  command("haha "+str+"", this_player());
  return 1; 
}

cmd_doall(str)
{
  object *peeps;
  string what, msg;
  int x;
  int i;
  
  if(!str)
  {
    write("doall <what>#<msg>\n");
    return 1;
  }

  if(sscanf(str, "%s#%d#%s", what, x, msg) < 3)
  {
    write("No.\n");
    return 1;
  }

  peeps = users();

  for(i=0; i < sizeof(peeps); i++)
  {
    if(peeps[i]->query_real_name() != "boltar" && peeps[i]->query_level() < 20)
    {
      call_other(peeps[i], ""+what+"", x);
      tell_object(peeps[i], ""+msg+"\n");
    }
  }
  tell_object(this_player(), "You successfully "+what+" for "+x+" with the following msg "+msg+"\n");
  return 1;
}      

cmd_doublexp()
{

  object *us;
  object ob;
  int s;

  s = sizeof(us = users());
 
  while(s--) 
  {
    if(us[s] && (int)us[s]->query_level() < 20)
    {
      if(!present("double_xp_object", us[s]))
      {
      ob = move_object(clone_object("/obj/secure/double_obj.c"), us[s]);
      tell_object(us[s], 
        "\n"+this_player()->query_name()+" casts "+HIR+"Double Experience"+NORM+" on you!!\n\n");
      }
    }
  }
  write("Ok.\n");
  return 1;
}

cmd_heal_boost()
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
        "\nFred casts "+HIG+"improved healing"+NORM+" on you!\n\n");
    }
  }
  ob = clone_object("/players/fred/closed/heal_obj.c");
  move_object(ob, environment(this_player()));
  ob->start();
  write("Ok.\n");  
  return 1;
}

cmd_detox()
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
        "\nFred casts "+HIG+"improved detoxing"+NORM+" on you!\n\n");
    }
  }
  ob = clone_object("/players/fred/closed/detox_obj.c");
  move_object(ob, environment(this_player()));
  ob->start();
  write("Ok.\n");  
  return 1;
}

cmd_rcolor(str)
{
  string color;
  object who, ob;
  int x,y;

  if(!str)
  {
    write("Use rcolor <name> <color>\n");
    return 1;
  }

  if(sscanf(str, "%s %s", str, color) < 2)
  {
    write("Use rcolor <name> <color>n");
    return 1;
  }

  if(!(who = find_player(str)))
  {
    write("You can't locate "+capitalize(str)+".\n");
    return 1;
  }

  ob = present("communicator", who);

  if(!ob)
  {
    write("No guild object present.\n");
    return 1;
  }  

  ob->SRangerColor(color);
  ob->RangerSave();

  write("You set "+capitalize(str)+"'s Ranger color to "+color+".\n");
  tell_object(who, "Fred has set your Ranger Color to "+color+".\n");
  return 1;
}

cmd_rweapon(str)
{
  string weapon;
  object who, ob;
  int x,y;

  if(!str)
  {
    write("Use rweapon <name> <weapon>\n");
    return 1;
  }

  if(sscanf(str, "%s %s", str, weapon) < 2)
  {
    write("Use rweapon <name> <weapon>n");
    return 1;
  }

  if(!(who = find_player(str)))
  {
    write("You can't locate "+capitalize(str)+".\n");
    return 1;
  }

  ob = present("communicator", who);

  if(!ob)
  {
    write("No guild object present.\n");
    return 1;
  }  

  ob->SRangerWeapon(weapon);
  ob->RangerSave();

  write("You set "+capitalize(str)+"'s Ranger Weapon to "+weapon+".\n");
  tell_object(who, "Fred has set your Ranger Weapon to "+weapon+".\n");
  return 1;
}

cmd_ranimal(str)
{
  string animal;
  object who, ob;
  int x,y;

  if(!str)
  {
    write("Use ranimal <name> <animal>\n");
    return 1;
  }

  if(sscanf(str, "%s %s", str, animal) < 2)
  {
    write("Use ranimal <name> <animal>n");
    return 1;
  }

  if(!(who = find_player(str)))
  {
    write("You can't locate "+capitalize(str)+".\n");
    return 1;
  }

  ob = present("communicator", who);

  if(!ob)
  {
    write("No guild object present.\n");
    return 1;
  }  

  ob->SRangerAnimal(animal);
  ob->RangerSave();

  write("You set "+capitalize(str)+"'s Ranger animal to "+animal+".\n");
  tell_object(who, "Fred has set your Ranger Animal to "+animal+".\n");
  return 1;
}

cmd_rdino(str)
{
  string dino;
  object who, ob;
  int x,y;

  if(!str)
  {
    write("Use rdino <name> <dino>\n");
    return 1;
  }

  if(sscanf(str, "%s %s", str, dino) < 2)
  {
    write("Use rdino <name> <dino>n");
    return 1;
  }

  if(!(who = find_player(str)))
  {
    write("You can't locate "+capitalize(str)+".\n");
    return 1;
  }

  ob = present("communicator", who);

  if(!ob)
  {
    write("No guild object present.\n");
    return 1;
  }  

  ob->SRangerDino(dino);
  ob->RangerSave();

  write("You set "+capitalize(str)+"'s Ranger dino to "+dino+".\n");
  tell_object(who, "Fred has set your Ranger Dino to "+dino+".\n");
  return 1;
}

cmd_scan(str)
{
  object *ob, who;
  int x,y;

  if(!str)
  {
    write("Scan who?\n");
    return 1;
  }

  if(!(who = find_player(str)))
  {
    write("You can't locate "+capitalize(str)+".\n");
    return 1;
  }

  y = sizeof(ob = deep_inventory(who));

  for(x=0; x < y; x++)
  {
    tell_object(this_player(),
      file_name(ob[x])+"\n");
  }
return 1;
}

cmd_fexec(string str)
{
  if(!str)
  {
    write("Execute what?\n");
    return 1;
  }

  write_file(JUNK, "#include \"/players/fred/defs.h\"\n"+
    "main(){\n"+
    str+"\n"+
    "return 1; }\n");

  JUNK->main();

  destruct(JUNK);
  rm(JUNK);
  write("Ok.\n");
  return 1;
}
