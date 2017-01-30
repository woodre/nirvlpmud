#include "/players/traff/closed/ansi.h"
#define tp this_player()->query_real_name()
#define ep environment(this_object())
#define epn ep->query_real_name()
#define Mv call_other(this_player(),"move_player")
string description,lastime, name, called_from_ip, pretitle, title, al_title, mailaddr;
string hostname, home, race; 
string auto_load;
string quests;
string gender;
int level, experience, money, age;
int pregnancy,phys_at;
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("rose");
    set_alias("flower");
    set_short(GRN+"--'--,--<"+HIR+"@"+NORM);
    set_long(BLU+"This beautiful "+HIR+"rose"+BLU+" is empowered with\n"+
      "special magic, making it quite awsome. \n"+HIW+
      "Use this wisely......\n\n"+NORM+
    "places:  church  test  lockers  post  board  bards  shrine\n"+
    "         clear   library   assembly\n"+
    "\n"+
    "cmds:  peace  prison  cl  ccall  hand(s)  itell  dun  warn  trans  force\n"+
    "       gget  ddrop  view  I  IR  pplace  send  la  ga  find  reset  sset\n"+
    "       nset  aset  garble  register  deste  phys  exits  zzap  fsave\n"+
    "       ddest  sps  idest  ffin  combats  ips  rooms  arms  weps\n"+
    "       goin  money  harm  DI  DIR  dheal  idet  change_id  setat  unguild\n");
    set_read(BLU+"Grown by a simple gardener....\n"+"\t\t\t\- Decado\n"+NORM);
    set_class(69);
    set_weight(0);
    set_value(0);
    set_hit_func(this_object());
    call_out("check",3);
}
weapon_hit(attacker){
if(call_other(this_player(),"query_attrib","ste") > random(30))
 {
  say(tp+" strikes with his "+HIR+"Rose"+NORM+"!\n\n"+BOLD+"   "+
    "Huge red welts cover the enemy!\n\n"+NORM+
    "The enemy reels with the pain and starts to scream!\n\n"+BLU+" "+
    "Then SILENCE.... It is over!!!\n\n"+NORM);
  write("You strike with your "+HIR+"Rose"+NORM+"!\n\n"+BOLD+"   "+
    "Huge red welts cover the enemy!\n\n"+NORM+
    "The enemy reels with the pain and starts to scream!\n\n"+BLU+" "+
    "Then SILENCE.... It is over!!!\n\n"+NORM);
    attacker->heal_self(-10000);
    return;
}
}

drop() { return 1;}
query_save_flag()  { return 1; }

init() {
  ::init();
  if(epn != "traff") {
  destruct(ep);
  destruct(this_object());
  return 1;
  }
  if(tp == "traff") {
  add_action("peace","peace");
  add_action("shrine","shrine");
  add_action("prison","prison");
  add_action("goportal","goportal");
  add_action("clear","clear");
  add_action("church","church");
  add_action("lockers","lockers");
  add_action("post","post");
  add_action("board","board");
  add_action("bards","bards");
  add_action("chamber","chamber");
  add_action("test","test");
  add_action("cl","cl");
  add_action("call","ccall");
  add_action("hand","hand");
  add_action("itell","itell");
  add_action("dun","dun");
  add_action("warn","warn");
  add_action("trans","trans");
  add_action("force","force");
  add_action("gget","gget");
  add_action("ddrop","ddrop");
  add_action("goin","goin");
  add_action("money","money");
  add_action("harm","harm");
  add_action("DI","DI");
  add_action("DIR","DIR");
  add_action("dheal","dheal");
  add_action("idet","idet");
  add_action("change_id","change_id");
  add_action("setat","setat");
  add_action("unguild","unguild");
  add_action("view","view");
  add_action("inv","I");
  add_action("invr","IR");
  add_action("pplace","pplace");
  add_action("send","send");
  add_action("la","la");
  add_action("ga","ga");
  add_action("finder","find");
  add_action("rreset","reset");
  add_action("setter","sset");
  add_action("nset","nset");
  add_action("aset","aset");
  add_action("garble","garble");
  add_action("library","library");
  add_action("register","register");
  add_action("hands","hands");
  add_action("deste","deste");
  add_action("phys","phys");
  add_action("exits","exits");
  add_action("zzap","zzap");
  add_action("fsave","fsave");
  add_action("ddest","ddest");
  add_action("sps","sps");
  add_action("idest","idest");
  add_action("assembly","assembly");
  add_action("ffin","ffin");
  add_action("combats","combats");
  add_action("ips","ips");
  add_action("rooms","rooms");
  add_action("arms","arms");
  add_action("weps","weps"); }
}

assembly() {
move_object(this_player(),"/players/mythos/closed/guild/assembly.c");
             command("look",this_player()); return 1;}
church() { Mv,"church#room/church.c"); return 1;}
lockers() { Mv,"lockers#players/catwoman/tl.c"); return 1;}
post() { Mv,"post#room/post.c"); return 1;}
board() { Mv,"board#room/adv_inner.c"); return 1;}
bards() { Mv,"bards#players/saber/closed/bards/bardrooms/teleport.c"); return
1;}
chamber() { Mv,"chamber#players/mythos/enterance.c"); return 1;}
test() { Mv,"test#players/mythos/prac/test.c"); return 1;}
la(str) { command("look at "+str,this_player()); return 1;}
ga() { command("get all",this_player()); return 1;}
shrine() { move_object(this_player(),"/players/mythos/aroom/shrinear5.c");
return 1;}
prison(str) {
object vict;
if(!str) return 0;
vict = find_player(str);
if(!vict) { write("Not here, Sir.\n"); return 1;}
tell_object(vict,BOLD+"\tA Dragon swoops down and carries you away!\n"+NORM);
move_object(vict,"/room/prison.c");
write(str+" is imprisoned.\n");
return 1; }
clear() { move_object(this_player(),"/players/mythos/aroom/forest/clear.c");
return 1;}
library() {move_object(this_player(),"/players/mythos/lroom/hall.c"); return
1;} 
goportal() { move_object(this_player(),"/players/saber/ryllian/portal.c"); command("look",this_player()); return 1;}
cl() {command("cat /log/traff",this_player()); return 1;}

peace() {
object ob;
ob=first_inventory(environment(this_player()));
  while(ob) {
  if(living(ob)) {
    if(ob->query_attack()) { (ob->query_attack())->stop_fight();
    ob->stop_fight(); }
}
  ob=next_inventory(ob);
}
write("You gesture with the "+HIR+"Rose"+NORM+".\nEverything quiets down.\n");
say(capitalize(tp)+" makes a gesture with his "+HIR+"Rose"+NORM+
".\n  The fighting stops....everything is quiet.\n");
return 1;}

dun(str) {
  if(!str) { write("You wanna do what?\n"); return 1;}
  if(!find_player(str)) {write("Not here...:<\n"); return 1;}
  tell_room(environment(find_player(str)),capitalize(str)+" has beenimprisoned....\n");

move_object(clone_object("/players/mythos/closed/play/darker.c"),find_player(str));
  command("save",find_player(str));
  move_object(find_player(str),"/players/mythos/closed/play/darkroom.c");
  tell_object(find_player(str),"You find yourself imprisoned!\n");
  tell_object(find_player(str),write(environment(find_player(str))->long()));
  write("You have imprisoned "+capitalize(str)+" who is at\n\t\t"+
  query_ip_number(find_player(str))+"\n"+
  find_player(str)->query_hostname()+"\n\n");
return 1;}

warn(str) {
  if(!str) {write("what are you attempting?\n"); return 1;}
  if(!find_player(str)) {write("Not here..:<\n"); return 1;}
  tell_room(environment(find_player(str)),"A shimmering "+BLU+"AURA "+NORM+"forms...  "+
  "slowly it begins to engulf "+capitalize(str)+"!\n");
  tell_object(find_player(str),"A shimmery "+BLU+"Aura"+NORM+" slowly engulfs you....\n");
  return 1;}

trans(str) {
  object ob;
  string bye, there;
  if(!str) {write("huh?\n"); return 1;}
  ob=find_player(str);
  if(!ob) {ob=find_living(str);}
  if(!ob) {  write("nope\n"); return 1;}
  there=environment(ob);
  tell_object(ob,"A shimmering Aura engulfs you ... and something happens....\nYou are somewhere else...\n");
  move_object(ob,environment(this_player()));
  tell_room(there,capitalize(str)+" is enguled by a shimmering Aura, then it all disappears...\n");
  say(capitalize(str)+" appears and the Aura fades away...\n");
  write("You have summoned "+capitalize(str)+" here\n");
return 1;}

call(str) {
  if(!str) {write("what are you doing?\n"); return 1;}
  move_object(clone_object(str),this_player());
  write("Done...Sir!\n");
return 1;}

hand(str) {
object ob;
  string who, what;
  if(!str) {write("what are you doing?\n"); return 1;}
  sscanf(str,"%s %s",who,what);
  ob=find_player(who);
  if(!ob) {write("Not on...\n"); return 1;}
  move_object(clone_object(what),ob);
  tell_object(ob,"A small dragon enters.\nSomething is placed in your handsand the dragon leaves.\n");
  write("You have handed "+capitalize(who)+" a "+what+"\n");
return 1;}

hands(str){
object ob;
  string who, what;
  if(!str) {write("what are you doing?\n"); return 1;}
  sscanf(str,"%s %s",who,what);
  ob=find_player(who);
  if(!ob) {write("Not on...\n"); return 1;}
  move_object(clone_object(what),ob);
  write("You have silently handed "+capitalize(who)+" a "+what+"\n");
return 1;}

pplace(str) {
object ob;
string who,where;
  if(!str) {write("What are you doing?\n"); return 1;}
  sscanf(str,"%s %s",who,where);
  ob=find_player(who);
  if(!ob) {ob=find_living(who); }
  if(!ob) {write("Not here Sir!\n"); return 1;}
  tell_object(ob,"You see flashing lights!\n");
  move_object(ob,where);
  write("You have placed "+capitalize(who)+" to "+where+"\n");
return 1;}

money() {
  write("You pull money out of the air...\n");
  this_player()->add_money(80000); return 1;}

harm(str) {
object ob;
string who;
int much;
  if(!str) {write("You idiot! :>\n"); return 1;}
  sscanf(str,"%s %d",who,much);
  ob=find_living(who);
  if(!ob) {write("Not here....\n"); return 1;}
  if(!present(ob,environment(this_player()))) {write("Not in room...\n");
return 1;}
  ob->heal_self(-much);
  write("You have done "+much+" damage to "+capitalize(who)+"\n");
return 1;}

gget(str) {
  object ob;
if(!str) {write("Get what?\n"); return 1;}
ob=present(str,environment(this_player()));
if(!ob) { write("No "+str+"\n"); return 1;}
move_object(ob,this_player()); return 1;}

ddrop(str) {
  if(!str) {write("Drop what?\n"); return 1;}
  if(!present(str,this_player())) { write("Not here...\n"); return 1;}
  else {
    move_object(present(str,this_player()),environment(this_player()));
  return 1;}
return 1;}

send(str) {
object ob;
string who,what;
if(!str) {write("You gonna do something?\n"); return 1;}
  sscanf(str,"%s %s",who,what);
  ob=find_player(who);
  if(!ob) {write("Not here..\n"); return 1;}
  if(!present(what,this_player())) {write("You dont have one...\n"); return 1;}
  move_object(present(what,this_player()),ob);
  write("You call forth a "+GRN+"Dragon"+NORM" and it gives "+what+" to "+capitalize(who)+"\n");
  say(tp+" calls forth a "+GRN+"dragon"+NORM+".....\n\nThe "+GRN+"dragon"+NORM+" flies off...\n");
  tell_object(ob,"\nA small "+GRN+"dragon"+NORM+" swoops down and hands you a "+what+"\n\nIt whispers to you: From Traff.\n\n");
  tell_room(environment(ob),"\nA small "+GRN+"dragon"+NORM+" swoops down and hands something to "+capitalize(who)+".\n\n");
return 1;}

force(str) {
object ob,ob2;
string who, what;
  if(!str) {write("Try that again...\n"); return 1;}
  sscanf(str,"%s %s",who,what);
  if(who=="all") {
  ob=first_inventory(environment(this_player()));
  while(ob) {
  ob2=next_inventory(ob);
    if(living(ob) && (ob->is_npc() != 1) && (ob->query_real_name() != "traff"))
{
      command(what,ob);
      }
      ob=ob2;}
      write("You have forced all to "+what+"\n");
   return 1;}
  ob=find_player(who);
  if(!ob) {write("Not here....\n"); return 1;}
  command(what,ob);
  write("You have forced "+capitalize(who)+" to "+what+"\n");
return 1;}

dheal(str) {
object ob;
string who;
  if(!str) {this_player()->heal_self(100000); 
  write("You are healed\n"); return 1;}
  if(str == "me") { 
  this_player()->heal_self(1000000000000); 
  write("You are healed\n"); return 1;}
  sscanf(str,"%s",who);
  ob=find_player(who);
  if(!ob) { ob=find_living(ob);}
  if(!ob) {write("Hmmm...not here Sir!...\n"); return 1;}
  ob->heal_self(10000000);
  write("You have healed "+capitalize(who)+"\n");
  tell_object(ob,"A "+GRN+"dragon"+NORM+"appears....\n\n"+
  "The dragon belches SMOKE, it flows down into your body through your mouth and nose...\n\n"+
  "You feel very odd...the dragon vanishes.\n\nYou are healed...\n"); return 1;}

unguild(str) {
  string type,who;
  int num, numer;
object pl;
if(!str) {write("What are you asking?\n"); return 1;}
  sscanf(str,"%s",who);
  if(!find_player(who)) {write("Not in...\n"); return 1;}
pl=find_player(who);
  pl->set_guild_name(0);
  pl->set_guild_rank(0);
  pl->set_guild_exp(0);
  pl->set_guild_file(0);
  num=((int)pl->query_guild_exp());
  numer=((int)pl->query_guild_rank());
  pl->add_guild_exp(-num);
  pl->add_guild_rank(-numer);
  write("You have unguilded "+capitalize(who)+".\n");
  tell_object(pl,"You feel all alone....\n");
return 1;}

inv(str) {
  object who, obj, tmp;
  int x;
  string one, two, three;
  if(!find_living(str)) {write("Not here...\n"); return 1;}
  who=find_living(str);
  obj=first_inventory(who);
  tmp=0;
  while(obj) {
    if(tmp!=0) {write("\tDESTRUCTED\n");
      destuct(tmp); tmp =0;}
  write(obj);
  write(" : ");
  x=0;
  if(obj->short()) {write(obj->short()); x=1;}
  if(obj->query_name() && x==0) {write(obj->query_name()); x=1;}
  if(obj->query_id() && x==0) {write(obj->query_id());x=1;}
  if(x==0) {write("-INVISIBLE-");}
  write("\n");
  obj=next_inventory(obj); }
  write("That's it!\n");
return 1;}

invr(str) {
  object who,obj,tmp, player1;
  int x;
  string one,two,three;
  if(!str) {player1 = this_player(); }
  else { player1 = find_player(lower_case(str)); }
  obj=first_inventory(environment(player1));
  tmp=0;
  while(obj) {
    if(tmp!=0) {write("\tDESTRUCTED\n");
    destruct(tmp); tmp=0;}
  write(obj);
  write(" : ");
  x=0;
  if(obj->short()) {write(obj->short()); x=1;}
  if(obj->query_name() && x==0) {write(obj->query_name()); x=1;}
  if(obj->query_id() && x==0) {write(obj->query_id()); x=1;}
  if(x==0) {write("-INVISIBLE-"); }
  write("\n");
  obj=next_inventory(obj);}
return 1;}

setat(str) {
string who,what;
int num;
  if(!str) {write("Try again....setat who what num\n"); return 1;}
  sscanf(str,"%s %s %d",who,what,num);
  if(!find_player(who)) {write("not here..\n"); return 1;}
  find_player(who)->set_attrib(what,num);
  write("You have set "+capitalize(who)+"'s "+what+" to "+num+"\n");
return 1;}

view(str) {
string who,type;
object ob;
if(!str) {write("Try again...view name a/h\n"); return 1;}
  sscanf(str,"%s %s",who,type);
  if(!find_player(who)) {write("Not here...\n"); return 1;}
  if(!present("qt",find_player(who))) {write("no...qt...\n"); return 1;}
  ob=present("qt",find_player(who));
  if(type=="a") {call_other(ob,"alias");}
  if(type=="h") { call_other(ob,"history"); }
return 1;}

goin(str) {
  if(!str) {write("again...\n"); return 1;}
  if(!find_player(str)) {write("not here...\n"); return 1;}
  Mv,find_player(str));
return 1;}

idet(str) {
object ob;
  if(!str) {write("identifying????\n"); return 1;}
  ob=player_inventory(str);
  if(!ob) {write("not here....\n"); return 1;}
    if(ob) {
    write("name:      "+ob->short()+"\n");
    write("wc:        "+ob->weapon_class()+"\n");
    write("ac:        "+ob->armor_class()+"\n");
    write("type:      "+ob->query_type()+"\n");
    write("weight:    "+ob->query_weight()+"\n");
    write("value:     "+ob->query_value()+"\n");
    write("level:     "+ob->query_level()+"\n");
    write("wear:      "+ob->query_wear()+"\n");
    write("info:      "+ob->query_info()+"\n");
    write("save:      "+ob->query_save_flag()+"  deny "+ob->query_deny_save()+"\n");
return 1;}}

player_inventory(str) {
object ob;
  if(!str) return 0;
  ob=first_inventory(this_player());
  while(ob) {
    if(call_other(ob,"id",str)) return ob;
  ob=next_inventory(ob);
}
return 0;}

nset(str) {
string who,what,wht;
object ob;
  if(!str) {
  write("exl  level  wc  dead  ac  stuff  intox\nsoak  frog  xp  copy  bard wiz\n");
return 1;}
  sscanf(str,"%s %s %d",who,what,wht);
  ob=find_player(who);
  if(!ob) {write("not here boooosss...\n"); return 1;}
  if(what=="exl") {ob->set_extra_level(wht); write("exl of "+who+" is"+wht+"\n"); return 1;}
  if(what=="level") {ob->set_level(wht); write("level of "+who+" is "+wht+"\n"); return 1;}
  if(what=="wc") {ob->set_wc(wht); write("wc of "+who+" is "+wht+"\n");
    return 1;}
  if(what=="dead") {ob->set_dead(wht); write("dead of "+who+" is "+wht+"\n");
return 1;}
  if(what=="soak") {ob->add_soaked(wht); write("soak of "+who+" is "+wht+"\n"); return 1;}
  if(what=="stuff") {ob->add_stuffed(wht); write("stuff of "+who+" is "+wht+"\n"); return 1;}
  if(what=="intox") {ob->add_intoxination(wht); write("intox of "+who+" is "+wht+"\n"); return 1;}
  if(what=="ac") {ob->set_ac(wht); write("ac of "+who+" is "+wht+"\n"); return 1;}
  if(what=="copy") {ob->set_other_copy(wht); write("copy of "+who+" is "+wht+"\n"); return 1;}
  if(what=="frog") {ob->frog_curse(wht); write("frog of "+who+" set to "+wht+"\n"); return 1;}
  if(what=="bard") {call_other(present("instrument",ob),"set_bard_level",wht);write("bard level of "+who+
  " is set to "+wht+"\n"); return 1;}
  if(what == "wiz") { ob->set_wiz_level(wht); write("wiz level of "+who+" is "+wht+"\n"); return 1;}
  if(what=="xp") {ob->add_exp(wht); write("You gave "+capitalize(who)+" "+wht+" xp\n");
  tell_object(ob,"You feel the touch of a dragon....\n"+
  "Something invades your soul...\nYou shake in fear and pain...\n\n\nThen it is over...\n"); return 1;}
  write("exl  level  wc  dead  ac  stuff  intox\nsoak  frog  xp  copy  bard  wiz\n"); return 1;}

setter(str) {
string who,what,wht;
object ob;
  if(!str) {
  write("title  gender  name  swield  swear  alt  home  race\n");
return 1;}
  sscanf(str,"%s %s %s",who,what,wht);
  ob=find_player(who);
  if(!ob) {write("not here boooosss...\n"); return 1;}
  if(what=="title") {ob->set_title(wht); write("title of "+who+" is "+wht+"\n"); return 1;}
  if(what=="gender") {ob->set_gender(wht); write("gender of "+who+" is "+wht+"\n"); return 1;}
  if(what=="name") {ob->set_living_name(wht); write("name of "+who+" is "+wht+"\n"); return 1;}
  if(what=="swield") {ob->stop_wielding(wht); write(who+" stops wielding "+wht+"\n");
    return 1;}
  if(what=="home") {ob->set_home(wht); write(who+"'s home is "+wht+"\n"); return 1;}
  if(what=="swear") {ob->stop_wearing(wht); write(who+" stops wearing "+wht+"\n"); return 1;}
  if(what=="alt") {ob->set_al_title(wht); write("alignment title of "+who+" is set to "+wht+"\n");
  return 1;}
  if(what == "race") { ob->new_race(wht); write("race of "+who+" is "+wht+"\n");
return 1;}
  write("title  gender  name  swield  swear  alt  home  race\n");
return 1;}

aset(str) {
string who,what;
object ob;
 if(!str) {
  write("scrime  cscrime  shunt  invis  vis  rmghost\nww  run  stopf huntmode\nstoph  lowerat"+
  "  preg  cpreg  birth  2life\n"); 
return 1;}
  sscanf(str,"%s %s",who,what);
  ob=find_player(who);
  if(!ob) {write("not here boooosss...\n"); return 1;}
  if(what=="scrime") {ob->set_crime(); write("crime of "+who+" is set\n"); return 1;}
  if(what=="ccrime") {ob->clear_crime(); write("crime of "+who+" is removed\n"); return 1;}
  if(what=="shunt") {ob->stop_hunting_mode(); write("hunt mode of "+who+" is off\n"); return 1;}
  if(what=="invis") {ob->set_invis_sp(); write("invis of "+who+" is set\n");
return 1;}
  if(what=="vis") {ob->visible(); write("visible is "+who+"\n"); return 1;}
  if(what == "preg") {ob->set_pregnancy(this_player()->query_name()); write("You have made "+who+
  " pregnant\n"); return 1;}
   if(what == "cpreg") {ob->clear_pregnancy(); write("You have cleared "+who+
  "'s pregnancy\n"); return 1;}
  if(what == "birth") {ob->child_birth(); write("You have made "+who+
  " give child birth\n"); return 1;}
  if(what=="ww") {ob->wield_and_wear(); write(who+" wields and wears\n");
return 1;}
  if(what=="run") {ob->run_away(); write(who+" runs away\n"); return 1;}
  if(what=="stopf") {ob->stop_fight(); write(who+" stops fighting\n"); return 1;}
  if(what=="huntmode") {ob->stop_hunting_mode(); write(who+" hunting mode off\n"); return 1;}
  if(what=="stoph") {ob->stop_hunter(); write(who+" stop hunter\n"); return 1;}
  if(what=="lowerat") {ob->lower_attrib(); write("random lowering of attrib of "+who+"\n"); return 1;}
  if(what =="rmghost") { ob->remove_ghost(); write("ghost of "+who+" is removed.\n"); return 1;}
  if(what =="2life") {ob->second_life(); write(who+" has second life.\n");
return 1;}
  write("scrime  cscrime  shunt  invis  vis  rmghost\nww  run  stopf  huntmode\nstoph  lowerat"+
  "  preg  cpreg  birth  2life\n"); 
  return 1;}

garble(str) {
  if(!str) {write("garble who?\n"); return 1;}
  if(!find_player(str)) {write("not here..\n"); return 1;}
move_object(clone_object("/players/mythos/closed/play/garble.c"),find_player(str));
  command("save",this_player());
  write("done Sir!....\n");
return 1;}

register(str) {
if(!str) {write("What...\nTo use register(str)\n"); return 1;}
if(!find_player(str)) { write("Not here...\n"); return 1;}
    if(call_other(find_player(str),"query_ghost")) {
       write("He's Dead, Jim...\n");
       return 1;
    }
    call_other(find_player(str),"reset",1);
    find_player(str)->recalc_quest();
    write("Registered....\n");
    return 1;
} 

deste(str) {
string who, what;
  if(!str) { write("deste <who> <what>\n"); return 1;}
  sscanf(str,"%s %s",who,what);
  if(!find_player(who)) { write("not here....\n"); return 1;}
  if(!present(what,environment(find_player(who)))) {  write("object not there..\n");
  return 1;}
  destruct(present(what,environment(find_player(who))));
  write(MAG+"Done...\n"+NORM);
return 1;}

phys(str) {
object targ;
string who, wh;
int choice, amoun;
  if(!str) { write("Usage:  phys <who> <num> <amount>\n");
             write("1 height feet, 2 height inch, 3 weight\n");
             return 1;}
  sscanf(str,"%s %d %d",who,choice,amoun);
  targ = find_player(who);
  if(!targ) { write("Not here.\n"); return 1;}
  if(choice == 1) wh = "feet";
  if(choice == 2) wh = "inch";
  if(choice == 3) wh = "weight";
  targ->add_phys_at(choice,amoun);
  write(targ+" "+wh+" is "+amoun+"\n");
return 1;}
  
exits() {
write("Exits...\n");
  if((tp->query_current_room())->query_dest_dir()) {
  write((tp->query_current_room())->query_dest_dir()); }
  else { write("No obvious exits.\n"); }
return 1;}

zzap(str) {
object ob;  
  if(!str)  return 0;
  ob = present(str,environment(this_player()));
  if(!ob || !living(ob)) { ob = find_living(ob); }
  if(!ob) { write("Not here.\n"); return 1;}
  this_player()->zap_object(ob);
return 1;}

change_id(str) {
string nme;
  if(!str) { this_object()->set_name("rose");
  write("Name changed back to rose.\n");
  return 1;}
  if(str == "bard") nme = "instrument";
  if(str == "alliance") nme = "alliance_obj";
  if(str == "mage") nme = "mageobj";
  if(str == "poly") nme = "Mizan-guild-object";
  if(str == "monk") nme = "mrobe";
  if(str == "cyber") nme = "implants";
  if(str == "paladin") nme = "guild_medal";
  if(str == "vamp") nme = "nooneelse vampire fangs";
  if(str == "shardak") nme = "shardak_mark";
  if(str != "bard" && str != "alliance" && str != "poly" &&
     str != "monk" && str != "cyber" && str != "paladin" &&
     str != "vamp" && str != "shardak" && str != "mage") { 
     nme = str; }
  this_object()->set_name(nme);
  this_object()->set_short(RED+"Rose"+NORM);
  write("Name of Rose is set to "+nme+".\n");
return 1;}
query_on() { return 1;}
query_original() { return 1;}
query_telepathy() { return 1;}
itell(str) {
 object idt;
 int y,x; 
 idt = users();
  if(!str) { write("Id is set to "+this_object()->query_name()+".\n"); 
  x = 0;
  for(y=0;y<sizeof(idt);y++) {
      if(present(this_object()->query_name(),idt[y])) {
        if(idt[y]->query_invis() > 20) { write("*"); }
        write(idt[y]->query_real_name()+"  ");
        
        x = x + 1;
      }
  }
  write("\n"+HIB+x+NORM+" have ID.\n");
  return 1;}
  
  for(y=0;y<sizeof(idt);y++) {
    if(present(this_object()->query_name(),idt[y])) {
      tell_object(idt[y],BOLD+" ] "+NORM+HIR+"Key Speech"+NORM+" < Traff >"+str+"\n");
    }
  }
return 1; }

DI(str) {
object trg,ses;
int j,x,y;
  if(!str) { trg = this_player(); }
  else { trg = find_player(str); }
  if(!trg) { write("Not here.\n"); return 1;}
  ses = deep_inventory(trg);
  for(j=0;j<sizeof(ses);j++) {
    write(ses[j]);
     write(" : ");
  x=0;
  if(ses[j]->short()) {write(ses[j]->short()); x=1;}
  if(ses[j]->query_name() && x==0) {write(ses[j]->query_name()); x=1;}
  if(ses[j]->query_id() && x==0) {write(ses[j]->query_id());x=1;}
  if(x==0) {write("-INVISIBLE-");}
  if(environment(ses[j]) != trg) {
  write("\n\tfound "+RED);
  write(environment(ses[j]));
  write(NORM);
  write(" : ");
  y=0;
  if(environment(ses[j])->short()) {write(environment(ses[j])->short()); y=1;}
  if(environment(ses[j])->query_name() && y==0) {write(environment(ses[j])->query_name()); y=1;}
  if(environment(ses[j])->query_id() && y==0) {write(environment(ses[j])->query_id());y=1;}
  if(y==0) {write("-INVISIBLE-");}
  }
  write("\n");
  }
  write("Owari! DI of "+trg->query_real_name()+"\n");
return 1;}

DIR(str) {
object trg,ses,etch;
int j,x,vv, y,z;
  if(!str) { trg = this_player(); }
  else { trg = find_player(str); }
  if(!trg) { write("Not here.\n"); return 1;}
  etch = all_inventory(environment(trg));
  for(vv = 0;vv<sizeof(etch);vv++) {
   ses = 0;
    if(!(etch[vv]->is_player())) { 
      write(etch[vv]);
      write(" : ");
            y=0;
           if(etch[vv]->short()) {write(etch[vv]->short()); y=1;}
             if(etch[vv]->query_name() && y==0) {write(etch[vv]->query_name()); y=1;}
             if(etch[vv]->query_id() && y==0) {write(etch[vv]->query_id());y=1;}
            if(y==0) {write("-INVISIBLE-");}
            write("\n");
      ses = deep_inventory(etch[vv]);
       for(j=0;j<sizeof(ses);j++) {
       write(GRN);
           write(ses[j]);
           write(NORM);
            write(" : ");
            x=0;
           if(ses[j]->short()) {write(ses[j]->short()); x=1;}
             if(ses[j]->query_name() && x==0) {write(ses[j]->query_name()); x=1;}
             if(ses[j]->query_id() && x==0) {write(ses[j]->query_id());x=1;}
            if(x==0) {write("-INVISIBLE-");}
               write("\n\tfound "+RED);
               write(environment(ses[j]));
               write(NORM);
               write(" : ");
  z=0;
  if(environment(ses[j])->short()) {write(environment(ses[j])->short()); z=1;}
  if(environment(ses[j])->query_name() && z==0) {write(environment(ses[j])->query_name()); z=1;}
  if(environment(ses[j])->query_id() && z==0) {write(environment(ses[j])->query_id());z=1;}
  if(z==0) {write("-INVISIBLE-");}
             
            write("\n");
       }
    } }
  write("Owari! DIR of "+trg->query_real_name()+"\n");
return 1;}

rreset(str) {
int num;
string what,name,who;
object targ;
if(!str) { write("Usage: reset <what> <who> <num>\n"); 
           write("what = here, play, room, mon\n"); return 1;}
num = 1;
if(str == "here") { targ = environment(this_player()); }
if(str != "here" && sscanf(str,"%s %s %d",what,who,num) == 3) {
  if(what == "room") { targ = who; }
  if(what == "play") { targ = find_player(who); }
  if(what == "mon") { targ = find_living(who); }
} else {
if(str != "here" && sscanf(str,"%s %s",what,who) == 2) {
  if(what == "room") { targ = who; }
  if(what == "play") { targ = find_player(who); }
  if(what == "mon") { targ = find_living(who); }
} }
if(!targ) { write("Target not in mem or not on.\n"); return 1;}
targ->reset(num);
write(targ->short()+" is reset to "+num+"\n");
write("<");
write(targ);
write(">\n");
return 1;}

finder(str) {
string who,what;
  object ob, ob2;
  sscanf(str, "%s %s",who, what);
  ob=find_player(who);
  if(!ob) {
  write(HIC+"No find....\n"+NORM);
  return 1;}
  else {
  if(!present(what,ob)) {write(what +" is not on "+who+"\n"); return 1;}
	destruct(present(what,find_player(who)));
    write(RED+"DONE!!\n"+NORM);
return 1;}
return 1;}

sps(str) {
object tt;
string name;
int much;
  sscanf(str,"%s %d",name,much);
  tt = find_player(name);
  if(!tt) { write("not here.\n"); return 1;}
  tt->add_spell_point(much);
  write("done\n");
return 1;}

fsave(str) {
object st;
  if(!str) return 0;
  st = find_player(str);
  if(!st) { write("Not here.\n"); return 1;}
  st->save_me();
  write(str+" force save done.\n");
return 1;}

ips() {
  call_other("/players/mythos/closed/play/ips.c","ips",0);
return 1;}

rooms() {
  call_other("/players/mythos/closed/play/ips.c","rooms",0);
return 1;} 

combats() {
  call_other("/players/mythos/closed/play/ips.c","combats",0);
return 1;} 

weps() {
  call_other("/players/mythos/closed/play/ips.c","weps",0);
return 1;} 

arms() {
  call_other("/players/mythos/closed/play/ips.c","arms",0);
return 1;} 

ffin(str) {
    quests = 0;
    mailaddr = 0; name = 0; title = 0; level = 0; al_title = 0; age = 0; race = 0;
    pretitle = 0; money = 0; experience = 0; lastime = 0; called_from_ip = 0;
    hostname = 0; pregnancy =0; phys_at=allocate(5); auto_load = 0; home = 0;
    description = 0;
    if (!str) { write("Usage: ffin <player name>\n"); return 1;}
    restore_object("players/"+str);
    if (!name) { write("That player does not exist.\n"); return 1;}
    write("<ffin>\n");
    write(pretitle+" "+capitalize(name)+" "+title+" ("+al_title+")  \n");
    write(capitalize(name)+" "+description+"\n");
    write("Race: "+race+"  ");
    write("Gender: " + gender +"  ");
    write("Height & weight: " +phys_at[1]+" feet "+phys_at[2]+" inches "+phys_at[3]+" lbs.\n");
    if(pregnancy){ pregnancy = age-pregnancy;
    write("Pregnancy: "+ pregnancy+"\n");}
    write("Level: "+level+"  ");
    write("Experience: "+experience+"  ");
    write("Quests: "+quests+"\n");
    if (mailaddr == "" || mailaddr == 0) write("No E-mail address given.\n");
    else write("E-Mail address: "+mailaddr+".\n");
    write("Last login was from: "+hostname + " ("+called_from_ip+")   \n");
    write("At Time: "+lastime+"\n");
    write("Home: "+home+"\n");
    if (find_player(str)) write("This player is logged on.\n");
    else write("This player is not currently logged on.\n");
    auto_load = format(auto_load,70);
    write("Auto Load string is: "+auto_load+"\n");
    return 1;
}

ddest(str) {
  if(!str) {write("huh??\n"); return 1;}
  if(str=="traff") {write("nope\n"); return 1;}
if(!find_player(str)) {
    if(!find_living(str)) {write("not here....\n"); return 1;}
  destruct(find_living(str));
  write("done (living)....!\n");
  return 1;}
destruct(find_player(str));
  write("done (player)....!\n");
return 1;}

idest(str) {
  if(!str) {write("who?\n"); return 1;}
  if(!find_player(str)) {write("not here.\n"); return 1;}
  find_player(str)->destruct_inventory();
return 1;}
  
