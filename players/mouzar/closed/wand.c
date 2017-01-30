#include "/obj/ansi.h"
#define ME this_player()
#define env_name(obj)environment(obj)->query_name() 
#define Call(XXX,YYY,ZZZ)call_other(XXX,YYY,ZZZ)
object shadow, monshadow, name;
int disguised, level;
string tab, gu;
get() { return 1;}
drop() {return 1;}
short() {
  string who;
  who=ME->query_real_name();
  if(who!=environment(this_object())->query_real_name())
    tell_object(environment(this_object()),capitalize(who)+" has just checked your inv.\n");
  return "Mouzar's "+GRN+"Koosh"+NORM+" Wand";
  }
long(){
  write("This wand was made by The Great Mouzar with special intentions in mind.\n"+
        "It consists of several thousand green, yellow and purple rubber like things\n"+  
        "strings.  The wand is made out of pure gold.  You can hear the koosh wand humm\n"+ 
        "with strange magical Koosh power.\n");
}
id(str) { return str == "wand";}
reset(arg){
  if(arg)return;
  tab="";
  set_light(1);
}
init(){
  if(ME->query_real_name()!="mouzar"&&ME->query_real_name()!="zakk"&&!ME->query_npc()) {
    write("You are blinded by something!\n");
    tell_object(find_living("mouzar"),"Your wand has just destructed.\n");
    destruct(this_object());
    return 1;
  }
  
  add_action("trans","trans");
  add_action("ul","ul");
  add_action("do_emote","ping");
  add_action("dhl","dhl");
  add_action("go","go");
  add_action("se","se");
  add_action("awho","aw");
  add_action("iwho","iwho");
  add_action("steal","steal");
  add_action("vanish","vanish");
  add_action("force","force");
  add_action("start","start");
  add_action("codeon","codeon");
  add_action("codeoff","codeoff");
  add_action("Time","time");
  add_action("echoto","echoto");
  add_action("Trans","Trans");
  add_action("Home","Home");
  add_action("tell","Tell");
  add_action("Look","Look");
  add_action("man","man");
  add_action("patch","patch");
  add_action("info","Info");
  add_action("I","I");
  add_action("New","New");
  add_action("whom","whom");
  add_action("wz","wz");
  add_action("Post","Post");
  add_action("findallob","findallob");
  add_action("find","find");
  add_action("Guild2","Guild2");
  add_action("Church","Church");
  add_action("Shop","Shop");
  add_action("Guild","Guild");
  add_action("Goto","Goto");
  add_action("goin","goin");
  add_action("echo_all","echoall");
  add_action("remote_clone","rclone");
  add_action("disguise","change");
  add_action("undisguise","norm");
  add_action("clean_area","cleanup");
}
goin(str){
object who;
if(!str)return;
if(!find_living(str)){
write("WAND:  "+str+" isn't on the MUD!\n");
return 1;}
who=find_living(str);
move_object(ME,who);
write("WAND:  You have arrived!\n");
command("look",ME);
return 1;
}
ul(str){
if(!str)return;
command("load "+str,ME);
command("update "+str,ME);
write("WAND:  All done.\n");
return 1;
}
Goto(str){
if(!str)return;
if(!find_living(str)){write("Wand:  "+str+" not found.\n");return 1;}
move_object(ME,environment(find_living(str)));
write("WAND:  You have arrived!\n");
command("look",ME);
return 1;
}
Post(str){
if(str)return;
move_object(ME,"/room/post");
write("WAND:  You have arrived!\n");
command("look",ME);
return 1;
}
Church(str){
if(str)return;
move_object(ME,"/room/church");
write("WAND:  You have arrived!\n");
command("look",ME);
return 1;
}
Guild2(str){
if(str)return;
move_object(ME,"/players/bismarck/nomads/room");
write("WAND:  You have arrived!\n");
command("look",ME);
return 1;
}
Guild(str){
if(str)return;
move_object(ME,"/players/nooneelse/black/cult_hall");
write("WAND:  You have arrived!\n");
return 1;
}
Shop(str){
if(str)return;
move_object(ME,"/room/shop");
write("WAND:  You have arrived!\n");
command("look",ME);
return 1;
}
findallob(str){
string t1,t2,t3;
object us,ob;
int x,y;
if(!str)return;
us=users();
for(x=0;x<sizeof(us);x++){
ob=first_inventory(us[x]);
while(ob){
if(sscanf(ob,"players/%s/%s",t1,t2)==2)
if(t1==str)
{
write(us[x]->query_real_name()+": "+strip_file_name(ob)+"\n");
}
ob=next_inventory(ob);
}
}
write("WAND:  Done searching for objects created by "+str+".\n");
return 1;
}
find(str){
object us,ob;
int x;
if(!str)return;
us=users();
for(x=0;x<sizeof(us);x++){
ob=first_inventory(us[x]);
while(ob){
if(ob->id(str)){
write(us[x]->query_real_name()+"\t");
if(strlen(us[x]->query_real_name())<8)write("\t");
if(strlen(us[x]->query_real_name())<5)write("");
if(ob->short())write(ob->short());
else if(ob->query_name())write(ob->query_name());
else if(ob->query_real_name())write(ob->query_real_name());
else write("** INVIS **");
write("\n\t\t"+strip_file_name(ob)+"\n");
}
ob=next_inventory(ob);
}
}
write("WAND:  Done searching for the object: "+str+".\n");
return 1;
}
whom(str){
if(str)return;
list_players(1);
return 1;
}
wz(str){
if(str)return;
list_players(0);
return 1;
}
static list_players(type){
string one,two;
object us;
int x;
write("-=Name-=-=-=-=Level=-=Idle-=-=-=-Location-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
us=users();
for(x=0;x<sizeof(us);x++){
if(type==0&&us[x]->query_level()>19||type==1){
write(capitalize(us[x]->query_real_name()));
if(strlen(us[x]->query_real_name())<8)write("\t\t");else write("\t");
write(us[x]->query_level()+"\t");
write(query_idle(us[x])/60+"\t");
if(environment(us[x])){
if(sscanf(file_name(environment(us[x])),"%s#%s",one,two)==2)
write(one);
else write(file_name(environment(us[x])));
}else write("Location Unknown");
write("\n");
}
}
return 1;
}
New(str){
object ob,ob2;
string name,trash;
if(!str)return;
if(present(str,environment(ME)))ob=present(str,environment(ME));
if(present(str,ME))ob=present(str,ME);
if(!ob){
write("WAND:  "+str+" is not here.\n");
return 1;
}
if(sscanf(file_name(ob),"%s#%s",name,trash)!=2){
write("WAND:  Illegal filename: "+file_name(ob)+"\n");
return 1;
}
ob2=clone_object(name);
if(present(str,ME))
move_object(ob2,ME);
else move_object(ob2,environment(ME));
destruct(ob);
write("WAND:  The old object has been replaced.\n");
return 1;
}
I(str){
if(!str)str=ME->query_real_name();
if(!find_living(str)){
write("WAND:  "+str+" isn't on the MUD!\n");
return 1;
}
tab="";
long_inven(find_living(str));
return 1;
}
long_inven(str){
string tmp,trash,oldtab;
int x;
object who,ob;
ob=first_inventory(str);
if(!ob){
write("WAND:  NOTHING\n");
return 1;
}
x=0;
while(ob){
x=x+1;
write(tab+x+": ");
if(ob->short())write(ob->short());
else if(ob->query_name())write(ob->query_name());
else if(ob->query_real_name())write(ob->query_real_name());
else write("**INVIS OBJECT**");
write(" :: ");
if(sscanf(file_name(ob),"%s#%s",tmp,trash)==2)write(tmp);else write(file_name(ob));
write("\n");
write(tab+"     AC ["+ob->armor_class()+"] WC ["+ob->weapon_class()+"] VALUE ["+ob->query_value()+"] WEIGHT ["+ob->query_weight()+"]\n");
if(ob->can_put_and_get()==1){
write(capitalize(ob->short())+" contains:\n");
oldtab=tab;
tab=tab+"   ";
long_inven(ob);
tab=oldtab;
}
ob=next_inventory(ob);
}
return 1;
}
patch(str){
object ob,last_arg;
string one,two;
string who,do_str,arg,cap_name;
int iarg,check,count;
if(!str){write("WAND:  patch <object> <function> <argument>\n");return 1;}
if(sscanf(str,"%s %s %s",who,do_str,arg)==3)
{
if(sscanf(arg,"%d",iarg)==1)check=1;
}
else if(sscanf(str,"%s %s",who,do_str)==2)check=1;
else{write("WAND:  Wrong arguments!!\n");return 1;}
if(sscanf(who,"@%s@%s",one,two)==2)
{
ob=present(two,find_living(one));
}
else ob=find_ob(who);
if(!ob){Fail(who);return 1;}
if(check)last_arg=Call(ob,do_str,iarg);
else{
string x1,x2,x3,x4,x5;
if(sscanf(arg,"%s,%s",x1,x2)!=2)
last_arg=Call(ob,do_str,arg);
else if(sscanf(arg,"%s,%s,%s,%s,%s",x1,x2,x3,x4,x5)==5)
last_arg=call_other(ob,do_str,x1,x2,x3,x4,x5);
else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3,x4)==4)
last_arg=call_other(ob,do_str,x1,x2,x3,x4);
else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3)==3)
last_arg=call_other(ob,do_str,x1,x2,x3);
else if(sscanf(arg,"%s,%s,%s,%s",x1,x2)==2)
last_arg=call_other(ob,do_str,x1,x2);
else{write("WAND:  Too many arguments.\n");return 1;}
}
write("WAND:  Result = ");write(last_arg);write("\n");
while(count){
if(check)Call(ob,do_str,iarg);
else Call(ob,do_str,arg);
count-=1;
}
return 1;
}
find_ob(str){
object ob;
ob=present(str,ME);
if(!ob)ob=present(str,environment(ME));
if(!ob)ob=find_object(str);
if(!ob)ob=find_living(str);
if(!ob)ob=find_living("ghost of "+str);
return ob;
}
man(str){
int i;
string manuals;
i=0;
manuals=({"/doc","/doc/efun", "/doc/lfun","/doc/helpdir",
"/doc/build","/doc/w","/doc/LPC","/obj"});
if (str==0){
write("WAND:  The topics are :\n");
while (i <sizeof(manuals)){
write(manuals[i]+" ");
i+=1;
}
write("\n");
return 1;
}
str="/"+str;
while(i <sizeof(manuals)){
if (file_size(manuals[i]+str)==-2){
write("Sub topics "+manuals[i]+str+":\n");
ls(manuals[i]+str);
return 1;
}
if (file_size(manuals[i]+str)>0){
write(manuals[i]+str+":\n");
command("more "+manuals[i]+str,ME);
return 1;
}
i+=1;
}
write("WAND:  Not found.\n");
return 1;
}
Look(str){
object where;
string file,trash;
object ob;
if(!str)str=ME->query_real_name();
if(!find_living(str)){
write("WAND:  "+str+" isn't on the MUD!\n");
return 1;
}
where=environment(find_living(str));
ob=first_inventory(where);
where->long();
while(ob){
if(ob->query_short())write(ob->query_short());
else if(ob->query_real_name())write(ob->query_real_name());
else if(ob->query_name())write(ob->query_name());
else if(ob->short())write(ob->short());
else write("** INVIS **");
write(" :: ");
if(sscanf(file_name(ob),"%s#%s",file,trash)!=2)
write(file_name(ob)+"\n");
else write(file+"\n");
if(!living(ob))
write("   AC [ "+ob->armor_class()+" ] WC [ "+ob->weapon_class()+
" ] WEIGHT [ "+ob->query_weight()+" ] VALUE [ "+ob->query_value()+" ]\n");
else
write("   AC [ "+ob->query_ac()+" ] WC [ "+ob->query_wc()+
" ] WEIGHT [ "+ob->query_weight()+" ] MONEY [ "+ob->query_money()+" ]\n");
ob=next_inventory(ob);
}
return 1;
}
tell(str){
string who;
string what;
if(!str)return;
if(sscanf(str,"%s %s",who,what)!=2)return;
if(!find_living(who)){
write("WAND: "+who+" isn't on the MUD!\n");
return 1;
}
tell_object(find_living(who),HIR+"Mouzar tells you:["+NORM+" "+what+"\n"); 
write("You tell "+capitalize(who)+": "+what+"\n");
return 1;
}
Trans(str){
if(!str)return;
if(!find_living(str)){
write("WAND:  "+str+" isn't on the MUD!\n");
return 1;
}
move_object(find_living(str),environment(ME));
write("WAND:  "+str+" now stands in front of you.\n");
return 1;
}
Home(str){
move_object(ME,"/players/"+ME->query_real_name()+"/workroom");
write("WAND:  You have arrived!\n");
command("look",ME);
return 1;
}
info(str){
object test;
if (!str)
test=query_attack();
else
test=find_living(lower_case(str));
if (!test){
write("WAND:  "+str+" isn't here!\n");
}else{
write("WAND:  "+capitalize(str)+"'s stats:\n"+
"Level:  "+test->query_level()+"\n"+
"Exp:    "+test->query_exp()+"\n"+
"Align:  "+test->query_alignment()+"\n"+
"HP:     "+test->query_hp()+"\n"+
"SP:     "+test->query_spell_points()+"\n"+
"WC      "+test->query_wc()+"\n"+
"AC:     "+test->query_ac()+"\n"+
"Where:  "+environment(test)->short()+"\n");
return 1;
}
}
echoto(str){
string one,two;
if(!str)return;
if(sscanf(str,"%s %s",one,two)!=2)return;
if(!find_living(one)){
write("WAND:  "+one+" not found.\n");
return 1;
}
tell_object(find_living(one),two+"\n");
write("WAND:  You echoto "+one+" '"+two+"'.\n");
return 1;
}
Time(str){
if(str)return;
write("You open the lid on your watch and a small demon appears and yells\n\t\t"+
ctime(time())+"\n");
return 1;
}
strip_file_name(ob){
string good,trash;
if(sscanf(file_name(ob),"%s#%s",good,trash)!=2)return "STRIP ERROR";
return good;
}
trans(str){
object who;
object env;
object envwho;
string filenm;
who=find_living( str);
if(!who){
write( "WAND:  You cannot trans non-living things!\n");
return 1;
}
env=environment( ME);
if(!env){
write( "WAND:  Bug! You have no environment!?!\n");
return 1;
}
if(!interactive( who)){
move_object( who,env);
return 1;
}
envwho=environment( who);
tell_object( who,"A large koosh with arms swoops down from the sky and grabs you.\n"+
                 "It takes you high in the sky and brings you to Mouzar.\n");
tell_room( env,"\nYou see "+who->query_name()+" gets dropped into the room by a koosh\n"+ 
                "with arms. The Koosh flies off until called again.\n");
move_object( who,env);
tell_room( envwho,"\nYou see "+who->query_name()+" get grabed by a large koosh with arms.\n");
return 1;
}
dhl(str){
string stuff,rece;
 
object stuff1,rece1;
if((!str)||((sscanf(str,"%s %s",stuff,rece)!=2))) { 
write("WAND:  You fail to send.\n");
return 1;
}
if(!present(stuff)||!find_living(rece)) { 
write("WAND:  Stuff or receiver not present.\n");
return 1;
}
rece1=find_living(rece);
stuff1=present(stuff);
move_object(stuff1,rece1);
tell_object(rece1," A small Koosh flies in, hands you a "+stuff+" and whispers to you\n"+
"'thank Mouzar'.\n");
write( "WAND:  You sent "+stuff+" to "+rece+".\n");
return 1;
}
go (arg){
object who,where;
who=find_living(arg);
if(!who){
write("WAND:  No players with that name on.\n");
return 1;
}
where=environment(who);
say("A pit of koosh balls opens up below Mouzar and he slowly sinks into it.\n",ME);
tell_room(where,"The ground shakes and a pit of koosh balls opens up in middle of the room.\n"+
"Mouzar slowy arises from it.\n");
move_object(ME,where);
write("WAND:  You have arrived!\n");
command("look",ME);
return 1;
}
vanish(str) {
string thing,ppl;
object thing1,ppl1;
if((!str)||((sscanf(str,"%s %s",thing,ppl)!=2))){ 
write("WAND:  Wrong syntax!\n");
return 1;
}
ppl1=find_living(ppl);
thing1=present(thing,ppl1);
if(!ppl1||!thing1)
{write("WAND: Player or item not present!\n");
return 1;
}
destruct(thing1);
write("WAND:  "+thing+" is now gone from "+ppl+"'s inv.\n");
tell_object(ppl1,"Mouzar incinerates a "+thing+" from your inventory.\n");
return 1;
}
steal(str){
string thing,ppl;
object thing1,ppl1;
if((!str)||((sscanf(str,"%s %s",thing,ppl)!=2))) { 
write("WAND: Wrong syntax!\n");
return 1;
}
ppl1=find_living(ppl);
thing1=present(thing,ppl1);
if(!ppl1||!thing1)
{write("WAND: Player or item not present!\n");
return 1;
}
move_object(thing1,ME);
write("WAND:  You stole "+thing+" from  "+ppl+"!\n");
return 1;
}
force(str){
object who;
string what;
if(sscanf(str,"%s %s",who,what)==2){
if(!find_living(who)){
write("WAND:  That is not on the MUD!\n");
return 1;
}
command(what,find_living(who));
write("Done.\n");
write("WAND:  You forced "+who+" to "+what+".\n");
return 1;
}
write("WAND: force <player> <action>\n");
return 1;
}
start(){ 
object env;
env=environment(ME);
move_object(ME,"/players/nooneelse/black/cult_hall");
command("patch mouzar set_guild_name vampire",ME);
command("sharpen fangs",ME);
move_object(clone_object("/players/bismarck/closed/misc/rock"), this_player());
move_object(clone_object("/players/mouzar/closed/guild/tattoo"), ME);
move_object(ME,"/room/storage");
command("push button",ME);
command("clone /players/mouzar/closed/wfinger",ME);
move_object(ME,env);
write("WAND:  You are now ready to face the mud.\n");
say("Mouzar twitches.\n");
return 1;
}
codeon(){
command("te off",ME);
command("muffle gossip",ME);
command("muffle risque",ME);
command("muffle equip",ME);
command("muffle shout",ME);
command("muffle wiz",ME);
command("muffle junk",ME);
write("WAND:  You may now code in peace.\n");
return 1;
}
codeoff(){
command("te on",ME);
command("channel gossip",ME);
command("channel risque",ME);
command("channel equip",ME);
command("channel shout",ME);
command("channel wiz",ME);
command("channel junk",ME);
write("WAND:  You are now back on all the channels.\n");
return 1;
}
se(str){
if(!str)return 0;
write("You invis say: "+str+"\n");
say("Someone says: "+str+"\n");
return 1;
}
do_emote( str){
if(!str)return 0;
write("WAND:  You echoed '"+str+"'.\n");
say(str+".\n");
return 1;
}
iwho(str){
object us;
string is_invis;
int x,y;
if(str)return;
us=users();
write("-=-=-=-*Invis Wiz*=-=-=*Location*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
for(x=0;x<sizeof(us);x++){
is_invis=us[x]->short();
y=x+1;
if(is_invis==0){
write("["+y+"]\t"+capitalize(us[x]->query_real_name()));
if(strlen(us[x]->query_real_name())>7)
write("\t");else write("\t\t");
write(environment(us[x])->short());
write("\n");
}
}
return 1;
}
awho(str){
object us;
int x;
if(str)return;
us=users();
write("-Level-=Name=-=-=-=Sex=Guild=-=-Location=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
for(x=0;x<sizeof(us);x++){
write("{"+us[x]->query_level()+"}");
if(us[x]->query_level()<100000){write("\t");}
write(capitalize(us[x]->query_real_name()));
if(strlen(us[x]->query_real_name())>7)
write("\t");else write("\t\t");
write("\b\b\b\b\b");
if(us[x]->query_gender()=="male")
write(" M  ");
else
if(us[x]->query_gender()=="female")
write(" F  ");
else
write(" C  ");
if(us[x]->query_level()>20){
  gu = "";
  if(present("clay",us[x])){
    gu = gu + "P ";
  }
  if(present("fangs",us[x])){
    gu = gu + "V ";
  }
  if(present("KnightTemplar",us[x])){
    gu = gu + "K ";
  }
  if(present("implants",us[x])){
    gu = gu + "C ";
  }
  if(present("mythos_healer",us[x])){
    gu = gu + "H ";
  }
  if(present("ranger_object",us[x])){
    gu = gu + "PR ";
  }
  if(present("mark",us[x])){
    gu = gu + "S ";
  }
  if(present("life",us[x])){
    gu = gu + "U ";
  }
  if(gu=="") {
    write("None");
  } else { 
  write(gu); 
  }
}
if(us[x]->query_level()<21){
if(present("implants",us[x]))
write("Cyber");
else
if(present("clay",us[x]))
write("Poly");
else
if(present("KnightTemplar", us[x]))
write("Knight");
else
if(present("necro_pouch", us[x]))
write("Necro");
else
if(us[x]->query_guild_name())
write(capitalize(us[x]->query_guild_name()));
else
if(present("implants",us[x]))
write("Cyber");
else
if(present("seal",us[x]))
write("Mason");
else
if(present("mrobe",us[x]))
write("Monk");
else
write("None");
}
write("\t");
if(!environment(us[x]))write("Logging in");
else write(environment(us[x])->short());
write("\n");
}
write("-=-=-=-=-=-=-=-=-=-=-=-Players currently logged on: "+x);
if(x<10)write("-");
write("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
return 1;
}
echo_all(str){
object *us;
int i;
us=users();
for(i=sizeof(us);i>0;i--){
tell_object(us[i-1],str+"\n");}
write("WAND:  You echo to all\n\t '"+str+"'.\n");
return 1;
}
 
remote_clone(str){
string person, thing;
object who_from,what,*r_inv;
int i;
if((!str)||((sscanf(str,"%s %s",thing,person)!=2))) { 
write("WAND:  rclone <thing> <person>\n");
return 1;
}
if (!(who_from=find_living(lower_case(person)))){
write("WAND:  I couldn't find "+capitalize(person)+".\n");
return 1;
}
r_inv=all_inventory(who_from);
for (i=0;i <sizeof(r_inv);i++)
if (r_inv[i]->id(thing))
what=r_inv[i];
if (what)  {
write("WAND:  "+what->short()+" from "+who_from->query_name()+" has been cloned!\n");
move_object(clone_object(explode(file_name(what),"#")[0]),ME);
}else{
write("WAND:  "+who_from->query_possessive()+" is't in that inv.\n");
}
return 1;
}
set_disguise(ob){
if(ob) shadow = ob;
return 1;
}
set_disguised(i){ 
disguised = i; 
return 1;}
set_reserved(ob){
if(ob) monshadow = ob;
return 1;
}
disguise(str){
  string a, b, what;
  level = 0; name = 0;
  if(!str){ notify_fail("Usage: disguise <what>"); }
  str = lower_case(str);
  if(disguised){notify_fail("You are already disguised."); }
   else what = str;
   this_player()->add_sp(-50);   
   shadow = clone_object("/players/mouzar/closed/disguise");
   shadow->set_name(str);
   shadow->set_cap_name(capitalize(str));
   shadow->set_short(what);
   shadow->set_long(what);
   shadow->shadow_player(this_player());
   command("refresh", this_player());
   write("You disguise yourself as "+what+".\n");
   disguised = 1;
   return 1;
 
}
undisguise(){
if(!shadow) { write("WAND:  You are in your wonderful true form.\n"); return 1; }
shadow->stop_shadow();
name = 0; level = 0;
command("refresh", ME);
write("WAND:  You melt back to normal.\n");
disguised = 0;
return 1;
}
clean_area(){
object ob;
ob = first_inventory(environment(ME));
while(ob) {
object cur;
cur = ob;
ob = next_inventory(ob);
if(!living(cur)){
destruct(cur);
}else{
if(living(cur) && cur->query_npc() == 1)
{
destruct(cur);
}
}
}
write("WAND:  You cleand up a little.\n");
say("Mouzar snaps his fingers and whips off some sweat from his forhead.\n");
return 1;
} 
ring(str) {
  object spo, hold, ob;
  if(!str) return;
  if(sscanf(str,"%s %s", hold, spo) != 2){
    write("WAND:  Try again.\n");
    return 1;
  }
  ob = clone_object("/players/bastian/closed/ring");
  ob->set_spouce(spo);
  return 1;
}
