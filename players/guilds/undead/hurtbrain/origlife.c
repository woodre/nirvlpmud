#include "/players/boltar/things/esc.h"
#define VISION_SPELL 30
#define MELT_SPELL 15
#define SEND_SPELL 10
#define SECOND_LEVEL 5000
#define THIRD_LEVEL 15000
#define FOURTH_LEVEL 35000
#define FIFTH_LEVEL 75000
#define SIXTH_LEVEL 155000
#define SPEED_SPELL 30
#define TITLE_SPELL 10
#define DOG_SPELL 50
#define SEVENTH_LEVEL 315000
#define EIGHTH_LEVEL 635000
#define GUILD_COM 700000
#define GUILD_COM2 1000000
#define FOG_SPELL 30
#define LIGHTNING_SPELL 50
#define CHARM_SPELL 20
#define GLARE_SPELL 40
#define SHADOWS_SPELL 40
#define BURN_SPELL 2
#define GLOW_SPELL 10
#define QGM_SPELL 10
#define QUARTZ_SPELL 10
#define HAND_SPELL 30
#define ANIMATE_SPELL 60
#define EVOKE_SPELL 20
#define CHILL_SPELL 40
/* this should cost enough to limit the number of times it may cast  */
#define WEAKEN_SPELL 40
#define FING_SPELL 100
/* this command is too powerfull for only a 100 sp cost it has been raised*/
#define KNOW_SPELL 20
#define FEIGN_SPELL 40
#define SCAN_SPELL 10
#define RAISE_SPELL 100
#define LOW_ARMOR_SPELL 500
#define LOW_WEAPON_SPELL 600
#define HIGH_ARMOR_SPELL 800
#define HIGH_WEAPON_SPELL 1200
#define TOMB_SPELL 30
#define GRAB_SPELL 40
#define FIX_SPELL 25
#define PLAGUE_SPELL 50
#define STORM_SPELL 200
#define BLAST_SPELL 200


string dirname;
string randname;
int noentrance;
int hide_on;
object name,this;
int flag_follow,lasthp,lastsp,mon_on;
int muffled,gmuffled,touch_spell;
int guild_whimpy;
int weakwait,chillwait;
int first;
int glow_turn,glow_flag;
string morph;
object weakwho,chillwho;
object ex_att;
string inp;
int hand_on;
int xsp, xhp;
int num_more;
int lev_out;
object grabwho;
int grabwc;
object ewho;
object plagwho;
object stormwho;
   object mate;
int plagwait,plagdur;
int stormwait,stormdur;
int grabwait;
set_noentrance() { noentrance=1; return noentrance; }
me() { this=this_player(); return this_player(); }
RN() { return capitalize(me()->query_real_name()); }
rn() { return me()->query_real_name(); }
rn2()  { if(this)  return this->query_real_name(); return this_player()->query_real_name(); }
query_muffle() { return muffled; }
query_gmuffle() { return gmuffled; }                          
get() { return 1; }
id(str) { return str=="life" | str=="soul-undead"; }
short() { return capitalize(environment(this_object())->query_real_name())+"'s life"; }

pet_zone() {
  string temp;
  temp = environment(this_player())->short();
  if(temp != "Village green [n,w,e]") {
    write("You fail from this location.\n");
    return 0;
  }
  else return 1;
}

query_auto_load()
{  return "/players/"+randname+"/life.c:";
}
long() {
   write("\tThis is the 'UNDEAD' symbol.\n"+
      "Use 'comm' to get a full list of commands.\n"+
      "    'com1' for level 1 command list.\n"+
      "    'com2' for levels 2-3 command list.\n"+
      "    'com3' for levels 4-5 command list.\n"+
      "    'com4' for levels 6-7 command list.\n"+
      "    'com5' for levels 8 command list.\n");
   if(guild_level() >= 10)  {
      write("Use 'comh' to get a list of guild creator commands.\n");
   }
}

guild_level() { 
   int lev;
   if(rn2()=="hurtbrain" || rn2()=="trix" || rn2()=="gorgan")  {
      morph="Dracolich";
      if(!lev_out)  lev_out=100;
      lev=lev_out;
      return lev;
   }
   if(rn2()=="nikki" || rn2()=="jaraxle") {
      morph="Banshee";
      lev=25;
      return lev;
   }
   if(!first)
      lev=me()->query_guild_exp();
   else
      lev=environment(this_object())->query_guild_exp();
   first=1;
   if(lev < SECOND_LEVEL)
      {
      morph="Skeleton";
      lev=1;
   }
   else if(lev < THIRD_LEVEL)
      {
      morph="Zombie";
      lev=2;
   }
   else if(lev < FOURTH_LEVEL)
      {
      morph="Ghoul";
      lev=3;
   }
   else if(lev < FIFTH_LEVEL)
      {
      morph="Shadow";
      lev=4;
   }
   else if(lev < SIXTH_LEVEL)
      {
      morph="Wight";
      lev=5;
   }
   else if(lev < SEVENTH_LEVEL)
      {
      morph="Wraith";
      lev=6;
   }
   else if(lev < EIGHTH_LEVEL)
      {
      morph="Spectre";
      lev=7;
   }
   else if(lev < GUILD_COM)
      {
      morph="Lich";
      lev=8;
   }
   else if(lev < GUILD_COM2)
      {
      morph="Special";
      lev=10;
   }
   else {
      morph="Special";
      lev=50;
   }
   return lev;
}

query_dirname() { tell_object(this_player(),capitalize(dirname)+".\n"); return 1; }
query_randname() { tell_object(this_player(),capitalize(randname)+".\n"); return 1; }
init() {
   int prob;
   string nname;
   mon_on=0;
   guild_whimpy=-1;
   prob=random(100);
   if(prob<50)
      randname="trix";
   else
      randname="hurtbrain";
   call_out("heartb",3);
   this=this_player();
   if(!this->query_npc())
      {
      nname=this->query_real_name();
      call_other("/players/trix/closed/guild/gcroom","impulse",nname);
   }
   call_other(this,"add_guild_rank",guild_level()-this->query_guild_rank());
   call_other(this_player(),"set_guild_name","undead");
   touch_spell=guild_level()*5;
   lev_out=100;
   call_out("entrance",0);
   add_action("reject","reject");
/*
   add_action("apprentice","apprentice");
*/
    add_action("uemotes","uemotes");
    add_action("cl_edit","editor");
   add_action("uquit","quit");
   add_action("creat_flyer","flyer");
   add_action("whistle","whystle");
   add_action("speed","speed");
   add_action("dog","dog");
   add_action("tomb","tomb");
   add_action("ecnart","ecnart");
   add_action("lead","lead");
   add_action("kill"); add_verb("kill");
   add_action("tell"); add_verb("tell");
   add_action("awho","nwho");
   add_action("leave","guildleave");
   add_action("set_lev","set_lev");
   add_action("com1","com1");
   add_action("com2","com2");
   add_action("com3","com3");
   add_action("com4","com4");
   add_action("com5","com5");
   add_action("comh","comh");
   add_action("promote","promote");
   add_action("gdemote","gdemote");
   add_action("new_command","new_command");
   add_action("new_command2","new_command2");
   add_action("quit","quit");
   add_action("communicate"); add_verb("say");
   add_action("communicate"); add_xverb("\"");
   add_action("communicate"); add_xverb("'");
   add_action("inv","i");
   add_action("renew","renew");
   add_action("hide","hide");
   add_action("set_touch","set_touch");
   add_action("set_whimpy","set_whimpy");
   add_action("utm","utm");
   add_action("gcw","gcw");
   add_action("gcm","gcm");
/*
   add_action("mon","mon");
*/
   add_action("emote","emote");
   add_action("du","du");
   add_action("ut","ut");
   add_action("ue","ue");
   add_action("gct","gct");
   add_action("gce","gce");
   add_action("comm","comm");
   add_action("title","title");
   add_action("trance","trance");
   add_action("rankme","rankme");
   add_action("low_armor","mvest");
   add_action("low_weapon","fball");
   add_action("high_armor","ffield");
   add_action("high_weapon","fwhip");
/*
   add_action("raise","revive");
*/
   add_action("aid","aid");
   add_action("score","sc");
   add_action("score","score");
   add_action("scan","scan");
   add_action("feign","feign");
   add_action("turn","turn");
   add_action("fog","fog");
   add_action("lightning","lightning");
   add_action("glare","Glare");
   add_action("touch","touch");
   add_action("shadows","shadows");
   add_action("charm","charm");
   add_action("vision","vision");
   add_action("melt","umelt");
   add_action("send","send");
   add_action("qgm","qgm");
   add_action("burn","burn");
   add_action("glow","glow");
   add_action("quartz","quartz");
   add_action("hand","hand");
   add_action("animate","animate");
   add_action("call","call");
   add_action("store_spell_points","ssp");
   add_action("store_hit_points","shp");
   add_action("xpts","stored");
   add_action("get_spell_points","gsp");
   add_action("get_hit_points","ghp");
   add_action("evoke","evoke");
/*
   add_action("chill","chill");
   add_action("weaken","weaken");
   add_action("fing","fing");
*/
   add_action("do_compare","know");
/*
   add_action("grab","grab");
   add_action("fix","fix");
   add_action("plague","plague");
   add_action("storm","storm");
   add_action("blast","blast");
*/
   add_action("guildfix","guildfix");
/* add_action("appfix","appfix"); */
/* BEGINNING OF EMOTE ADD_ACTIONS */
    add_action("ugrin","ugrin");
    add_action("usmile","usmile");
    add_action("uglare","uglare");
    add_action("ugreet","ugreet");
    add_action("uwater","uwater");
    add_action("uoblige","uoblige");
    add_action("uthreaten","uthreaten");
/* END OF EMOTE ADD_ACTIONS */
   if(this->query_level()<20) 
      {
      mon_on=1;
      tell_object(this,"Guild Monitor on.\n");
   }
}

entrance()
{
   if(!noentrance)
      { 
      guild_channel_mess(this->query_name()+" comes back to non-life.\n");
    /*
      if(!this->query_wimpy())
         {
         guild_whimpy=25;        
         tell_object(this,"Brave mode.\nDefault wimpy off. Guild Whimpy is set to 25%.\n");
      }
      else
         {
         tell_object(this,"Wimpy mode.\nDefault wimpy on. Guild Whimpy is OFF.\n");
         guild_whimpy=-1;
      } 
   */
tell_object(this,"\n\n\t\t\t"+esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+
            "  ***>>> MEN AT WORK! <<<***"+esc+"[0m"+
          "\n\t             Read the note about it on guild board!\n\n\n");
      tell_object(this,"->> ");
      noentrance=1;
   }
   return 1;
}

uquit()
{   guild_channel_mess(RN()+" falls asleep and leaves this world.\n");  
   this->quit();
   return 1;
}


guild_channel_mess(str){
   object *us,life;
   int x;
   if(this->query_invis()||this->query_level()>20)  return 0;
   us=users();
   for(x=0;x<sizeof(us);x++){
      life=present("soul-undead",us[x]);
      if(life&&!life->query_muffle()){
         tell_object(us[x],"[*UNDEAD*]: "+str+"\n");
       }
   }
   return 1;
}

set_touch(str)  {
   int num;
   if(guild_level() < 2 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!str)  {
      write("Usage: set_touch <number>\n");
      return 1;
   }
   if(!sscanf(str,"%d",num))
      {
      write("You have to write a number.\n");
      return 1;
   }
   if(num < 0 || num > guild_level()*5)
      {
      write("Number not in available range.\n");
      return 1;
   }
   write("Power of touch set to "+num+".\n");
   touch_spell=num;
   return 1;
}

utm()  {
   if(!muffled)  {
      write("Guild messages muffled.\n");
      muffled=1;
   }
   else  {
      write("Ear muffle off.\n");
      muffled=0;
   }
   return 1;
}

gcw(str) {
   object us,life;
   int x;
   int lev;
   int invis;
   if(guild_level() != 10 && guild_level() != 100 && guild_level() != 25)  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(str) return;
   write("*-----------------------------------------------------------------------------*\n");
   write("|*Undead*===*G.Level*==*Location*=============================================|\n");
   write("*-----------------------------------------------------------------------------*\n");
   us=users();
   for(x=0;x<sizeof(us);x++) {
      invis=us[x]->query_invis();
      life=present("soul-undead",us[x]);
      if(life &&life->guild_level()>=10&& invis<this_player()->query_level()){
         if(invis) { write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"); }
         write(capitalize(us[x]->query_real_name()));
         if(strlen(us[x]->query_real_name())>7)
            write("\t"); else write("\t\t");
         write(esc+"[0m");
         lev=call_other(present("soul-undead",us[x]),"guild_level");
         write(lev+" ");
         if(call_other(present("soul-undead",us[x]),"query_gmuffle"))
            write("m");
         write("\t");
         write(environment(us[x])->short());
         write("\n");
       }
   }
   return 1;
}
gcm()  {
   if(!gmuffled)  {
      write("Guild Leaders messages muffled.\n");
      gmuffled=1;
   }
   else  {
      write("Guild Leaders ear muffle off.\n");
      gmuffled=0;
   }
   return 1;
}

drop() {
   return 1;
}

comh()  {
   if(guild_level() < 10 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   cat("/players/"+dirname+"/closed/guild/helpdir/pent6.com");
   return 1;
}

comm(str) {
   if(str)  return;
   if(!num_more)  num_more=1;
   if(num_more<6)  {
      cat("/players/"+dirname+"/closed/guild/helpdir/pent"+num_more+".com");
      if(num_more < 5)  {
         write("More (q or Q to exit):");
         input_to("more");
      }
      else num_more=0;
      ++num_more;
      return 1;
   }
   return 1;
}

more(arg)  {
   if(arg=="q" || arg=="Q")  {
      num_more=1;
      write("\n");
   }
   else  {
      inp=arg;
      comm();
   }
   return 1;
}
com1(str) {
   if(str)  return;
   cat("/players/"+dirname+"/closed/guild/helpdir/pent1.com");
   return 1;
}
com2(str) {
   if(str)  return;
   write("Spell                                                 Cost(sp) Level\n\n");
   cat("/players/"+dirname+"/closed/guild/helpdir/pent2.com");
   return 1;
}
com3(str) {
   if(str)  return;
   write("Spell                                                 Cost(sp) Level\n\n");
   cat("/players/"+dirname+"/closed/guild/helpdir/pent3.com");
   return 1;
}
com4(str) {
   if(str)  return;
   write("Spell                                                 Cost(sp) Level\n\n");
   cat("/players/"+dirname+"/closed/guild/helpdir/pent4.com");
   return 1;
}

com5(str) {
   if(str)  return;
   write("Spell                                                 Cost(sp) Level\n\n");
   cat("/players/"+dirname+"/closed/guild/helpdir/pent5.com");
   return 1;
}
ut(str) {
   object us;
   int x;
   if(!str) return;
   if(muffled)  {
      write("The channel is muffled.\n");
      return 1;
   }
   us=users();
   for(x=0;x<sizeof(us); x++) {
      if(present("soul-undead",us[x]) && !call_other(present("soul-undead",us[x]),"query_muffle"))
         tell_object(us[x],format("[*"+RN()+"*] "+str+"\n",75));
   }
   return 1;
}
ue(str) {
   object us;
   int x;
   if(!str) return;
   if(muffled)  {
      write("The channel is muffled.\n");
      return 1;
   }
   us=users();
   for(x=0;x<sizeof(us);x++) {
      if(present("soul-undead",us[x]) && !call_other(present("soul-undead",us[x]),"query_muffle"))
         tell_object(us[x],format("[*] "+RN()+" "+str+"\n",75));
   }
   return 1;
}
gct(str) {
   object us,soul;
   int x;
   if(!str) return;
   if(gmuffled)  {
      write("The channel is muffled.\n");
      return 1;
   }
   us=users();
   for(x=0;x<sizeof(us); x++) {
      soul=present("soul-undead",us[x]);
      if(soul&&call_other(soul,"guild_level")>=10 && !call_other(soul,"query_gmuffle"))
         tell_object(us[x],format("[*!"+RN()+"!*] "+str+"\n",75));
   }
   return 1;
}
gce(str) {
   object us,soul;
   int x;
   if(!str) return;
   if(gmuffled)  {
      write("The channel is muffled.\n");
      return 1;
   }
   us=users();
   for(x=0;x<sizeof(us);x++) {
      soul=present("soul-undead",us[x]);
      if(soul&&call_other(soul,"guild_level")>=10 && !call_other(soul,"query_gmuffle"))
         tell_object(us[x],format("[*!*] "+RN()+" "+str+"\n",75));
   }
   return 1;
}
du(str) {
   object us,life,aura;
   int x;
   int lev;
   int invis;
   if(str) return;
   write("*-----------------------------------------------------------------------------*\n");
   write("|*Undead*---*G.Level*--*Location*---------------------------------------------|\n");
   write("*-----------------------------------------------------------------------------*\n");
   us=users();
   for(x=0;x<sizeof(us);x++) {
      invis=us[x]->query_invis();
      life=present("soul-undead",us[x]);
      aura=present("aura-undead",us[x]);
      if((life||aura) && invis<this_player()->query_level()){
         if(invis) { write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"); }
         write(capitalize(us[x]->query_real_name()));
         if(strlen(us[x]->query_real_name())>7)
            write("\t"); else write("\t\t");
         write(esc+"[0m");
         if(life) {
            lev=life->guild_level();
            write(lev+" ");
            if(call_other(present("soul-undead",us[x]),"query_muffle"))
            write("m");
          }
         else write("\b[App]");
         write("\t");
         write(environment(us[x])->short());
         write("\n");
       }
   }
   return 1;
}

turn(str) {
   object new;
   if(guild_level() < 10 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!str) return;
   sscanf(str,"%s undead",str);
   new = find_player(str);
   if(!new) {
      write("Life: I could not find '"+str+"'\n");
      return 1;
   }
   if(!present(new,environment(me())))  {
      write("Life: "+new->query_name()+" is not here.\n");
      return 1;
   }
     if (new -> query_level () < 5) {
      write("Life: "+new->query_name()+" is not ready to join yet.\n");
      return 1;
   }
   move_object(clone_object("/players/"+randname+"/life.c"),find_living(str));
   tell_object(find_living(str),RN()+" has just given you a new life.\n");
   new->set_guild_name("undead");
   write("You raise your powerful hands and give "+new->query_name()+" a new life!\n");
   say(RN()+" just recruited "+new->query_name()+".\n");
   command("ut "+new->query_name()+" is now an Undead!\n",new);
   return 1;
}

reject(str) {
   object new,aura;
   if(guild_level() < 10 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!str) return;
   sscanf(str,"%s undead",str);
   new=find_player(str);
   if(!new) {
      write("Life: I could not find '"+str+"'\n");
      return 1;
   }
   if(!present(new,environment(me())))  {
      write("Life: "+new->query_name()+" is not here.\n");
      return 1;
   }
   aura=present("aura-undead",new);
   if(!aura)  {
      write("Life: "+new->query_name()+" is not an Apprentice yet!\n");
      return 1;
   }
   say(RN()+" banishes "+new->query_name()+" from the Undead Apprenticeship.\n");
   write("You force "+new->query_name()+" to abandon the Undead Apprenticeship.\n");
   command("ut "+RN()+" rejects "+new->query_name()+" from joining the Undead!\n",this);
   destruct(aura);
   new->set_guild_name();
   return 1;
}
follow(str)  {
   if(guild_level() < 2 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if (!str)
      if( flag_follow==1)  {
      write("Follow off.\n");
      flag_follow=0;
      return 1;
   }
   else {
      write("You are not following anyone.\n");
      return 1;
   }
   if(flag_follow==1)
      write("You are no longer following "+call_other(name,"query_name")+".\n");
   flag_follow = 0;
   name=present(str,environment(me()));
   if(!name)  {
      write("No "+str+" here!\n");
      return 1;
   }
   if(name->query_level()>20) {
      write("You can't follow a wizard.\n");
      return 1;
   }
   flag_follow=1;
   this=me();
   write("You now are following "+capitalize(str)+".\n");
   return 1;
}

heartb()  {
   object att;
   int hit;
/*
   call_out("check_whimpy",0);
   call_out("check_mon",0);
*/
   if(flag_follow==1)  {
      if(environment(this)!=environment(name))  {
/*
   call_out ("test_whimpy", 0);
*/

/* temp fix, note to add to new gob header 888 mizan */
/*
  if(guild_whimpy && this_player()->query_hp() < (this_player()->query_mhp() * guild_whimpy / 100)) {
    flag_follow = 0;
  name = 0;
  write("Follow forced off by wimpy. (temporary fix)\n");
}
*/
/* end */
         if(environment(name)->realm()=="NT")
            {
            flag_follow=0;
            tell_object(this,"You can't follow in this area.\nFollow off.\n");
         }
         else
            {
            move_object(this,environment(name));
            command("look",this);
         }
      }
   }
   if(glow_flag)  {
      --glow_turn;
      if(!glow_turn)  {
         tell_object(this,"Your body slowly stops glowing.\n");
         tell_room(environment(this),this->query_name()+" stops glowing.\n");
         glow_flag=0;
         set_light(-1);
      }
   }
   if(hand_on)  {
write("Sorry, Hand Removed Due to being Illegal.\n");
/*add by hawkeye 2/19/95*/
return 1;}
/*
      att=call_other(this,"query_attack");
      if(att->query_hp()<HAND_SPELL || !att || att!=ex_att || (this->query_sp() <= 0))  {
         tell_object(this,"The magical hand disappears in a puff of smoke.\n");
         hand_on=0;
      }
      else  {
         tell_object(this,"Your hand hits "+att->query_name()+".\n");
         hit=att->hit_player(HAND_SPELL);
         call_other(this,"add_spell_point",-hit);
      }
   }
*/
   call_out("clean_morph",0);
   if(this->query_attack())  call_out("heartb",1);
   else
      call_out("heartb",3);
}
test_whimpy () {
  if(guild_whimpy && this_player()->query_hp() < (this_player()->query_mhp() * guild_whimpy / 100)) {
    flag_follow = 0;
  name = 0;
  write("Follow forced off by wimpy. (temporary fix)\n");
 }
}
check_whimpy() {
 object blah;
   blah=this->query_attack();
   if(guild_whimpy>-1&&blah&&this->query_hp()<(this->query_mhp()*guild_whimpy/100))
      if(environment(blah)==environment(this))
      {
      flag_follow=0;
      call_other(this,"run_away");
      tell_object(this,esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+
         "You are LUCKY, your Guild Whimpy just saved your b*tt!!!"+esc+"[0m\n->> ");
   }
}

check_mon()
{ object att;
  object moo;
   int max,cur;
  moo = environment(this_object());
   if((mon_on==1) && (lasthp!=moo->query_hp() || lastsp!=moo->query_sp()))  {
      att=call_other(moo,"query_attack");
      tell_object(moo,
         "Hp:["+moo->query_hp()+"/"+moo->query_mhp()+"] " +
         "Sp:["+moo->query_sp()+"/"+moo->query_msp()+"] " +
         "Al:["+moo->query_intoxination()+"]");
      if(att) {max=att->query_mhp();
         if(max!=0)  {
            cur=att->query_hp();
            cur=(cur*100)/max;
            tell_object(moo," Ene:["+cur+"%]");
         }
      }
      tell_object(moo,"\n");
      lasthp=moo->query_hp();
      lastsp=moo->query_sp();
   }
}

clean_morph()
{
   if(find_living("sph_"+this->query_name()) && find_living("morph_"+this->query_name()) && interactive(this))  {
      destruct(find_living("morph_"+lower_case(me()->query_name())));
      destruct(find_living("sph_"+lower_case(me()->query_name())));
      hide_on=0;
   }
}

vision(str) {
   object ob, ob_tmp, pla;
   string item;
   string it;
   int max;
   if(guild_level() < 4 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if (!str) {
      write("Who do you want to vision?\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < VISION_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   pla=find_player(str);
   if(!pla)  {
      write("No "+str+" on!\n");
      return 1;
   }
   write("**********************************************************\n");
   call_other(me(),"add_spell_point",-VISION_SPELL);
   write(call_other(environment(pla), "short")); write("\n");
   call_other(environment(pla), "long");
   ob = first_inventory(environment(pla));
   max = 20;
   while(ob && max > 0) {
      string short_str;
      short_str = call_other(ob, "short");
      if (short_str) {
         max -= 1;
         write(short_str + ".\n");
         it = short_str;
         }
      ob = next_inventory(ob);
   }
   write("**********************************************************\n");
   return 1;
}

emote(str){
   if(!str)
      return 0;
   str = format(str,60);
   write("You emote:\n");
   say(call_other(me(), "query_name", 0) + " "+ str +"\n");
   write(call_other(me(), "query_name", 0) + " "+ str +"\n");
   return 1;
}


melt(str)  {
   object obj;
   int value,weight;
   if(guild_level() < 3 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!str)  {
      write("Usage: umelt <item>\n");
      return 1;
   }
   obj=present(str,me());
   if(!obj)  {
      write("What do you want to melt?\n");
      return 1;
   }
   value=obj->query_value();
   if (!value) {
      write("You can't melt worthless things!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < MELT_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   weight = call_other(obj, "query_weight", 0);
   call_other(me(), "add_weight", - weight);
   if (value > 1000)  value = 1000 + random(200);
   call_other(me(),"add_spell_point",-MELT_SPELL);
   write("As you gaze the "+str+" glows.\nThe item melts into "+value+" coins.\n");
   say("You see "+call_other(me(),"query_name")+"'s eyes glow and a "+str+" melts.\n");
   call_other(me(), "add_money", value);
   destruct(obj);
   return 1;
}

send(str)
{ 
   string stuff,rece;
   int stweight;
   object stuff1,rece1;
   if(guild_level() < 3 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if((!str) || ((sscanf(str,"%s %s",stuff,rece) !=2)))
      {   write("You fail to send.\n");
      return 1;
   }
   if(!present(stuff) || !find_living(rece))
      {   write("Stuff or receiver not present.\n");
      return 1;
   }
   if(present(stuff)->drop())  {
      write("You can't send this object.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < SEND_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   rece1=find_living(rece);
   stuff1=present(stuff);
   stweight=stuff1->query_weight();
/*
   if(!present("soul-undead",rece1)) {
      write("You can send only to a guild mate!\n");
      return 1;
   }
*/
   if(!rece1->add_weight(stweight))
      { write("Your mate can't carry that much.\n"); return 1; }
   move_object(stuff1,rece1);
   this->add_weight(-stweight);
   tell_object(rece1,"A spirit arrives and gives you a "+stuff+" saying it's from "+RN()+".\n");
   write("You send a "+stuff+" to "+rece1->query_name()+".\n");
   call_other(me(),"add_spell_point",-SEND_SPELL);    
   return 1;
}


mon()  {
   if(mon_on)
      {
      mon_on=0;
      write("Guild monitor off.\n");
   }
   else {
      mon_on=1;
      write("Guild monitor on.\n");
      lasthp=call_other(me(),"query_hp");
      lastsp=call_other(me(),"query_sp");
      this=me();
   }
   return 1;
}


fog(arg)  {
   object who,obj;
   if(guild_level() < 4 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to fog?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < FOG_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-FOG_SPELL);
   write("You cast a magical fog on "+who->query_name()+".\n");
   say("A black fog invades the room and starts to choke "+who->query_name()+".\n");
   me()->attack_object(who);
   who->hit_player(FOG_SPELL-random(-10));
   /* there should be some randomness here -Bp */
   return 1;
}


lightning(arg)  {
   object who,obj;
   int flagarg;
   if(guild_level() < 6 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg)  {
      flagarg=0;
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to lightning?\n");
         return 1;
      }
   }
   else  {
      flagarg=1;
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(flagarg)
      who=present(arg,environment(me()));
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < LIGHTNING_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-LIGHTNING_SPELL);
   write("You cast a black lightning on "+who->query_name()+".\n");
   say(RN()+" releases a black bolt of energy and "+who->query_name()+" staggers.\n");
   me()->attack_object(who);
   who->hit_player((LIGHTNING_SPELL/2)+random(LIGHTNING_SPELL/2));
   /* some randomness */
   return 1;
}


shadows(arg)  {
   object who,obj;
   if(guild_level() < 5 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to shadows?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < SHADOWS_SPELL-10) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   obj=present("quartz",me());
   if(!obj)  {
      write("You need a magical quartz to shadows someone!\n");
      return 1;
   }
   destruct(obj);
   write("As you pronounce the magical words the quartz glows and crumbles away.\n");
   call_other(me(),"add_spell_point",-SHADOWS_SPELL-10);
   write("You summon the shadows from the depth of the earth.\n");
   write("The shadows attack "+who->query_name()+".\n");
   me()->attack_object(who);
   who->hit_player(SHADOWS_SPELL-random(20));
   say("You see "+who->query_name()+" surrounded by "+RN()+"'s shadows.\n");
   return 1;
}


glare(arg)  {
   object who,obj;
   if(guild_level() < 5 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to glare?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < GLARE_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-GLARE_SPELL);
   write("You gaze "+who->query_name()+" in the eyes and he starts to hit himself!\n");
   say("As "+RN()+" gazes "+who->query_name()+" the monster starts to hit himself.\n");
   me()->attack_object(who);
   who->hit_player(GLARE_SPELL+random(20)); /* Changed by Beren. */
   return 1;
}


charm(arg)  {
   object who,obj;
   if(guild_level() < 3 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to charm?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < CHARM_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-CHARM_SPELL);
   write("You charm "+who->query_name()+" and smash its head against your knee.\n");
   say(who->query_name()+" seems to be stunned.\n");
   say(RN()+" smashes "+who->query_name()+"'s head against his knee.\n");
   me()->attack_object(who);
   who->hit_player(CHARM_SPELL-random(10));
   return 1;
}


touch(arg)  {
   object who,obj;
    int flagarg;
   if(guild_level() < 2 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg)  {
        flagarg=0;
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to touch?\n");
         return 1;
      }
   }
   else  {
        flagarg=1;
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
    if(flagarg)
        who=present(arg,environment(me()));
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < touch_spell) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-touch_spell);
   write("As you touch "+who->query_name()+", he seems to lose power.\n");
   say(RN()+" touches "+who->query_name()+" which seems to grow weaker.\n");
   me()->attack_object(who);
   who->hit_player(random(touch_spell+random(touch_spell/2)));
   /* this should be random */
   return 1;
}


title(arg)  {
   if(guild_level() < 2 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < TITLE_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   if(!arg) {
      call_other(me(),"set_title","");
      write("Your title is now clear.\n");
      return 1;
   }
   if(strlen(arg)>70) {
      write("You can only set titles up to 70 characters.\n");
      return 1;
   }
   call_other(me(),"set_title",arg);
   write("Your title is now:\n"+arg+".\n");
   return 1;
}

/*
title(arg)  {
   if(arg) return;
   
   call_other(me(),"set_title","the Undead "+morph);
   write("Your title is now: the Undead "+morph+".\n");
   return 1;
}
*/
rankme()  {
   int lev,olev,xlev,lev_exp,spexp,next_lev;
   lev=guild_level();
   write(RN()+" the "+morph+".\n");
   write("Guild level: "+lev+".\n");
   write("Guild experience: "+me()->query_guild_exp()+".\n");
   if(lev==1)
      next_lev=SECOND_LEVEL;
   else if(lev==2)
      next_lev=THIRD_LEVEL;
   else if(lev==3)
      next_lev=FOURTH_LEVEL;
   else if(lev==4)
      next_lev=FIFTH_LEVEL;
   else if(lev==5)
      next_lev=SIXTH_LEVEL;
   else if(lev==6)
      next_lev=SEVENTH_LEVEL;
   else if(lev==7)
      next_lev=EIGHTH_LEVEL;
   if(lev<=7)
      {
      olev = this->query_level();
      if(olev>19) olev=19;
      xlev = this->query_extra_level();
      if(xlev>19) xlev = 19;
      if(olev > 18&&xlev>0) lev_exp = call_other("/room/exlv_guild","get_next_exp",xlev-1);
      else lev_exp = call_other("/room/adv_guild","get_next_exp",olev-1);
      spexp=this->query_exp()-lev_exp;
      next_lev-=(spexp+this->query_guild_exp());
      write("Next guild level: "+next_lev+" gxp needed.\n");
   }
   else write("Maximum guild level.\n");
   write("Guild Whimpy: ");
   if(guild_whimpy<1)
      write("OFF.\n");
   else
      write(guild_whimpy+"%.\n");
   write("Current morph: ");
   if(!hide_on)
      write("None.\n");
   else
      write(morph+".\n");
   write("Touch power: "+touch_spell+".\n");
   return 1;
}


burn()  {
   object corpse;
   int heal;
   if(guild_level() < 2 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   corpse=present("corpse",environment(me()));
   if(!corpse || corpse->query_level()!=0)  {
      write("No corpse to burn here.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < BURN_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-BURN_SPELL);
   heal=corpse->heal_value();
   me()->heal_self(heal);
   write("You burn the corpse of your opponent filling yourself up with its energy.\n"+
      "The corpse turns into ash and the wind blows it away.\n");
   say(RN()+" burns a corpse and glows with its energy.\nThe corpse turns into ash and the wind blows it away.\n");
   destruct(corpse);
   return 1;
}

glow()  {
   glow_turn=50;
   if(guild_level() < 3 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < GLOW_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-GLOW_SPELL);
   write("Your body begins to emit a soft glow enabling you to see.\n");
   say(RN()+" starts to glow.\n");
   command("look",me());
   glow_flag=1;
   this=me();
   set_light(1);
   return 1;
}

qgm(arg)  {
   int lev,olev,xlev,lev_exp,spexp,next_lev,flagout;
   string m_morph;
   if(guild_level() < 2 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg) {
      write("Whose stats do u want to check?\n");
      return 1;
   }
   mate=find_player(arg);
   if(!mate)  {
      mate=clone_object("/players/trix/closed/guild/qgm");
      call_other(mate,"set_search",arg);
      move_object(mate,this);
      if(mate->query_name()=="<noone>") {
         write("No players called "+arg+".\n");
         return 1;
      }
      flagout=1;
      call_out("destqgm",1);
   }
   if(!present("soul-undead",mate)) {
      if(!flagout||flagout&&mate->query_guild_name()!="undead") {
         write(mate->query_name()+" is not an undead.\n");
         return 1;
      }
   }
   if(guild_level()<10)
      {
      if(call_other(me(),"query_sp") < QGM_SPELL) {
         write("You don't have enough spell points.\n");
         return 1;
      }
      call_other(me(),"add_spell_point",-QGM_SPELL);
   }
   lev=mate->query_guild_exp();
   if(lev < SECOND_LEVEL)
      {
      m_morph="Skeleton";
      lev=1;
      next_lev=SECOND_LEVEL;
   }
   else if(lev < THIRD_LEVEL)
      {
      m_morph="Zombie";
      lev=2;
      next_lev=THIRD_LEVEL;
   }
   else if(lev < FOURTH_LEVEL)
      {
      m_morph="Ghoul";
      lev=3;
      next_lev=FOURTH_LEVEL;
   }
   else if(lev < FIFTH_LEVEL)
      {
      m_morph="Shadow";
      lev=4;
      next_lev=FIFTH_LEVEL;
   }
   else if(lev < SIXTH_LEVEL)
      {
      m_morph="Wight";
      lev=5;
      next_lev=SIXTH_LEVEL;
   }
   else if(lev < SEVENTH_LEVEL)
      {
      m_morph="Wraith";
      lev=6;
      next_lev=SEVENTH_LEVEL;
   }
   else if(lev < EIGHTH_LEVEL)
      {
      m_morph="Spectre";
      lev=7;
      next_lev=EIGHTH_LEVEL;
   }
   else if(lev < GUILD_COM)
      {
      m_morph="Lich";
      lev=8;
   }
   else if(lev < GUILD_COM2)
      {
      m_morph="Special";
      lev=10;
   }
   else
      {
      m_morph="Special";
      lev=50;
   }
   if(mate->query_real_name()=="hurtbrain" ||
         mate->query_real_name()=="trix" ||
      mate->query_real_name()=="gorgan" ) {
      m_morph="Dracolich";
      if(flagout) 
         lev=mate->query_guild_rank();
      else
         lev=call_other(present("soul-undead",mate),"guild_level");
   }
   if(mate->query_real_name()=="nikki" || mate->query_real_name()=="jaraxle") {
      m_morph="Banshee";
      if(flagout) 
         lev=mate->query_guild_rank();
      else
         lev=call_other(present("soul-undead",mate),"guild_level");
   }
   write(capitalize(mate->query_real_name()));
   write(" the "+m_morph+".\n");
   write("Guild level: "+lev+".\n");
   write("Guild experience: "+mate->query_guild_exp()+".\n");
   if(guild_level()>=10)
      {
      if(lev<=7)
         {
         olev = mate->query_level();
         if(olev>19) olev=19;
         xlev = mate->query_extra_level();
         if(xlev>19) xlev = 19;
         if(olev > 18&&xlev>0) lev_exp = call_other("/room/exlv_guild","get_next_exp",xlev-1);
         else lev_exp = call_other("/room/adv_guild","get_next_exp",olev-1);
         spexp=mate->query_exp()-lev_exp;
         next_lev-=(spexp+mate->query_guild_exp());
         write("Next guild level: "+next_lev+" gxp needed.\n");
      }
      else write("Maximum guild level.\n");
   }
   return 1;
}

destqgm() { destruct(mate); }

quartz()  {
   object quartz;
   if(guild_level() < 5 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < QUARTZ_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-QUARTZ_SPELL);
   write("You raise your hands and a magical quartz appears in it.\n");
   say(RN()+" close his eyes and a quartz magically appears.\n");
   quartz=clone_object("/players/hurtbrain/closed/guild/quartz.c");
   move_object(quartz,me());
   return 1;
}

hand()  {
   object obj;
   if(guild_level() < 7 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   obj=call_other(me(),"query_attack");
   if(!obj) {
      write("You are not fighting anyone.\n");
      return 1;
   }
   if(hand_on)  {
      write("The magical hand stops to fight and disappears.\n");
      hand_on=0;
      return 1;
   }
   if(!obj->query_npc())
      {
      write("You can't attack "+obj->query_name()+".\n");
      return 1;
   }
   write("An hand magically appears near you. The hand starts to massacre "+call_other(obj,"query_name")+".\n");
   ex_att=me()->query_attack();
   hand_on=1;
   this=me();
   return 1;
}


animate(arg)
{ object corpse;
   string name;
   int animate_spell;
   object zom;
   if(guild_level() < 5 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(arg!="dead")  {
      write("What do you want to animate?\n");
      return 1;
   }
   if(find_living("zombie_"+lower_case(me()->query_name())))  {
      write("You already have a pet zombie.\n");
      return 1;
   }
   if(find_living("dog_"+lower_case(me()->query_name())))  {
      write("You already have a death dog.\n");
      return 1;
   }
/* blt add. */
  if(!pet_zone()) return 1;
/*    */
   corpse=present("corpse",environment(me()));
   if(!corpse) { write("No corpses in this room.\n"); return 1; }
   animate_spell=30+(30*(corpse->heal_value())/19);
   if(call_other(me(),"query_sp") < animate_spell) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-animate_spell);
   sscanf(call_other(corpse,"short"),"corpse of %s",name);
   zom=clone_object("/players/trix/closed/guild/zombie");
   call_other(zom, "set_ac", 1+(4*(corpse->heal_value())/19));
   call_other(zom, "set_level",3);
   call_other(zom, "set_ep",2283);
   call_other(zom, "set_hp",50+(100*(corpse->heal_value())/19));
   call_other(zom, "set_wc",5+(10*(corpse->heal_value())/19));
   call_other(zom, "set_myname",name);
   call_other(zom, "set_info","z_"+rn());
   call_other(zom, "set_master",me());
   move_object(zom,environment(me()));
   call_other(zom,"toggle_follow");
   write("You summon a zombie from the depth of the earth.\n");
   say(RN()+" summons a zombie.\n");
   destruct(corpse);
   return 1;
}

store_spell_points(){
   object corpse;
   int heal;
   if(guild_level() < 6 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(xsp>100) {
      write("You can't store so many spell points.\n");
      return 1;
   }
   corpse=present("corpse",environment(me()));
   if(!corpse)  {
      write("This spell requires a corpse.\n");
      return 1;
   }
   heal=corpse->heal_value();
   xsp = xsp+heal;
   write("You drain the life energy from the corpse and store it in your life.\n");
   say(RN()+" drains the life energy from the corpse and store it in his life.\n");
   write("You store "+heal+" spell points.\n");
   write("You now have "+xsp+" stored sp.\n");
   destruct(corpse);
   return 1;
}
store_hit_points(){
   object corpse;
   int heal;
   if(guild_level() < 6 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(xhp>75)
      {     write("You can't store so much hit points.\n");
      return 1;
   }
   corpse=present("corpse",environment(me()));
   if(!corpse)  {
      write("This spell requires a corpse.\n");
      return 1;
   }
   heal=corpse->heal_value();
   xhp = xhp+heal;
   write("You drain the life energy from the corpse and store it in your life.\n");
   say(RN()+" drains the life energy from the corpse and store it in his life.\n");
   write("You store "+heal+" spell points.\n");
   write("You now have "+xhp+" stored sp.\n");
   destruct(corpse);
   return 1;
}

xpts(){
   if(guild_level() < 6 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   write("XHP: "+xhp+"\tXSP: "+xsp+"\n");
   return 1;
}

get_spell_points(amt){
   int num;
   if(guild_level() < 6 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!amt){
      write("How many spell points do you want to get.\n");
      return 0;
   }
   else if(sscanf(amt,"%d",num)==1){
      if(num>xsp){
         write("You haven't got that many spell points stored.\n");
         return 1;
         }
      else {
         xsp = xsp-num;
         me()->add_spell_point(num);
         write("You get "+num+" spell points.\n");
         return 1;
         }
   }
   else return 0;
}

get_hit_points(amt){
   int num;
   if(guild_level() < 6 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!amt){
      write("How many hit points do you want to get?\n");
      return 0;
   }
   else if(sscanf(amt,"%d",num)==1){
      if(num>xhp){
         write("You don't have that many hit points stored.\n");
         return 1;
         }
      else{
         xhp=xhp-num;
         me()->add_hit_point(num);
         write("You get "+num+" hit points.\n");
         return 1;
         }
   }
   else return 0;
}

query_xsp(){ return xsp; }

query_xhp(){ return xhp; }

evoke()  {
   object ppl,ppl1;
   if(guild_level() < 6 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   ppl = first_inventory(environment(me()));
   write("You evoke the death upon the room!\n");
   say(RN()+" evokes the death upon the room.\n");
   while(ppl) {
      ppl1 = next_inventory(ppl);
      if(call_other(me(),"query_sp") < EVOKE_SPELL) {
         write("You don't have enough spell points.\n");
         return 1;
         }
      if(ppl!=me() && ppl->query_info()!="z_"+rn())
         if((ppl->query_npc()==1) && (ppl->is_pet()==0))
         {
         call_other(ppl,"attack_object",me());
         ppl->hit_player(EVOKE_SPELL-random(10));
         call_other(me(),"add_spell_point",-EVOKE_SPELL);
         }
      ppl = ppl1;
   }
   return 1;
}


chill(arg)  {
   object who,obj;
   if(guild_level() < 7 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to chill?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(chillwait)
      {
      write("You're still resting from your previous chill!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < CHILL_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-CHILL_SPELL);
   write(who->query_name()+"'s power seems to decrease.\n");
   say(RN()+" makes a gesture and "+who->query_name()+"'s power seems to decrease.\n");
   me()->attack_object(who);
   call_other(who,"set_wc",who->query_wc()-3);
   chillwait=1;
   chillwho=who;
   call_out("remchill",40);
   return 1;
}


weaken(arg)  {
   object who,obj;
   if(guild_level() < 7 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to weaken?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(weakwait)
      {
      write("You're still resting from your previous weaken!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < WEAKEN_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-WEAKEN_SPELL);
   write(who->query_name()+"'s armor starts to melt.\n");
   say(RN()+" makes a gesture and "+who->query_name()+"'s armor starts to melt.\n");
   me()->attack_object(who);
   call_other(who,"set_ac",who->query_ac()-3);
   weakwait=1;
   weakwho=who;
   call_out("remweak",40);
   return 1;
}
remweak()  {
   weakwait=0;
   if(!weakwho)  return 0;
   tell_room(environment(this),weakwho->query_name()+
      " recovers and breaks the weaken spell.\n");
   call_other(weakwho,"set_ac",weakwho->query_ac()+3);
   return 1;
}
remchill()  {
   chillwait=0;
   if(!chillwho)  return 0;
   tell_room(environment(this),chillwho->query_name()+
      " recovers and breaks the chill spell.\n");
   call_other(chillwho,"set_ac",chillwho->query_wc()+3);
   return 1;
}

fing(arg)  {
   object who,obj;
   int hits;
   if(guild_level() < 7 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to fing?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < FING_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-FING_SPELL);
   write("You point your finger and "+who->query_name()+" starts to tremble.\n");
   say(RN()+" points his finger and "+who->query_name()+" starts to tremble.\n");
   me()->attack_object(who);
   hits=who->query_hp()/10;
   if(hits > 50) hits=50;
   who->hit_player(hits);
   return 1;
}

hide () {
   object mons,sph;
   object att;
   if(find_living("sph_"+lower_case(me()->query_name())) && find_living("morph_"+lower_case(me()->query_name())))  hide_on=1;
   else hide_on=0;
   if(!hide_on)
      {
      if(me()->query_attack())  {
         write("You can't hide while attacking.\n");
         return 1;
      }
      write("You hide into your soul! Your corpse turns into a "+morph+".\n");
      say(me()->query_name()+" takes a breath and turns into a "+morph+".\n");
      mons=clone_object("/players/hurtbrain/closed/guild/morph.c");
      sph=clone_object("/players/hurtbrain/closed/guild/sphere.c");
      call_other(mons,"set_name",lower_case(morph));
      call_other(mons,"set_short","A "+morph);
      call_other(mons,"set_alias","morph_"+lower_case(me()->query_name()));
      call_other(mons,"set_info","sph_"+lower_case(me()->query_name()));
      call_other(sph,"set_alias","sph_"+lower_case(me()->query_name()));
      call_other(sph,"set_short","Sphere of "+me()->query_name());
      call_other(sph,"set_info",lower_case(me()->query_name()));
      move_object(sph,environment(me()));
      move_object(mons,environment(me()));
      move_object(me(),sph);
      move_object(sph,mons);
      hide_on=1;
      tell_object(me(),"HIDDEN ->> ");
      input_to("read");
   }
   else {
      command("drop a_pass",me());
      move_object(me(),environment(find_living("morph_"+lower_case(me()->query_name()))));
      destruct(find_living("morph_"+lower_case(me()->query_name())));
      destruct(find_living("sph_"+lower_case(me()->query_name())));
      hide_on=0;
      write("You are no more hidden.\n->> ");
      say("The "+morph+" takes a breath and turns into "+me()->query_name()+".\n");
      att=first_inventory(environment(me()));
      while (att)  {
         if(call_other(att,"query_hunted")==me())
            call_other(att,"attack_object",me());
         att=next_inventory(att);
      }
   }
   return 1;
}

read(str)  {
   object ex_env,str2;
   if(str=="quit" || str=="say" || str=="i" || str=="'")
      command(str,me());
   else if(str && str!="new_command")  {
      ex_env=environment(find_living("morph_"+lower_case(me()->query_name())));
      call_other(find_living("morph_"+lower_case(me()->query_name())),"set_com",str);
      command(str,find_living("morph_"+lower_case(me()->query_name())));
      if(environment(find_living("morph_"+lower_case(me()->query_name())))!=ex_env)
         command("look",find_living("morph_"+lower_case(me()->query_name())));
   }
   tell_object(me(),"HIDDEN ->> ");
   if(str!="hide" && str!="new_command")   input_to("read");
   return 1;
}

quit()  {
   object obj;
   obj=find_living("zombie_"+lower_case(me()->query_name()));
   if(hide_on)
      command("hide",me());
   if(obj)
      command("peace str",me());
}

new_command()  {
   return 1;
}

new_command2()   {
   input_to("read");
   return 1;
}

test_dark() {
   if (set_light(0) <= 0) {
      write("It is too dark.\n");
      return 1;
   }
   return 0;
}

inv() {
   object ob;
   ob = first_inventory(me());
   if (test_dark())
      return 1;
   while (ob) {
      string str;
      str = call_other(ob, "short");
      if (str) {
         write(str + ".\n");
         }
      ob = next_inventory(ob);
   }
   return 1;
}


communicate(str) {
 return;
/* this is not legal -Bp */
   if (!str) {
      write("Say what?\n");
      return 1;
   }
   str = format(str,60);
   if (me()->query_ghost()) {
      say(me()->short() + " says: " + str + ".\n");
      if (me()->query_brief())
         write("Ok.\n");
      else
         write("You say: " + str + "\n");
      return 1;
   }
   say(me()->query_name() + " says: " + str + "\n");
   if (me()->query_brief())
      write("Ok.\n");
   else
      write("You say: " + str + "\n");
   return 1;
}

do_compare(str) 
{
   object enemy;
   string what,enemy_name;      
   int enemy_sp,enemy_hp,enemy_lv,enemy_ac,enemy_wc;
   int pl_sp,pl_hp,pl_lv,pl_ac,pl_wc;
   int diff_hp,diff_sp,diff_ac,diff_wc,diff_lv;
   if(guild_level() < 3 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(str)
      {
      enemy=find_living(str);
      if(!enemy)                          
         {
         write("That is not on the MUD!\n");
         return 1;
      }
      if(enemy==me())                          
         {
         write("You cannot compare yourself !!\n");
         return 1;
      }
      if(me()->query_sp()<KNOW_SPELL) {
         write("You don't have enough spell points.\n");
         return 1;
      }
      call_other(me(),"add_spell_point",-KNOW_SPELL);
      enemy_name=capitalize(enemy->query_name());
      enemy_sp=enemy->query_sp();   
      enemy_hp=enemy->query_hp();   
      enemy_lv=enemy->query_level();
      enemy_ac=call_other(enemy,"query_ac",);
      enemy_wc=call_other(enemy,"query_wc",);
      pl_sp=me()->query_sp();   
      pl_hp=me()->query_hp();   
      pl_lv=me()->query_level();   
      
      pl_ac=call_other(me(),"query_ac",);  
      pl_wc=call_other(me(),"query_wc",);
      
      write("You concentrate for a moment.\n");
      write("Your eyes become red.\n");
      write("Your Undead powers allow you to know that :\n");
      say(capitalize(me()->query_name())+"'s eyes start to shine and become red.\n");
      diff_hp=pl_hp-enemy_hp;
      diff_sp=pl_sp-enemy_sp;
      diff_ac=pl_ac-enemy_ac;
      diff_wc=pl_wc-enemy_wc;
      diff_lv=pl_lv-enemy_lv;
      if (diff_hp>100) 
         write("Hp : You kick "+enemy_name+"'s ass!\n");
      else if(diff_hp>0)
         write("Hp : You are stronger then "+enemy_name+".\n");
      else if(diff_hp==0)
         write("Hp : You have as many hit points as "+enemy_name+".\n");
      else if(diff_hp<-100)
         write("Hp : "+enemy_name+" kicks your ass!\n"); 
      else
         write("Hp : "+enemy_name+" is stronger then you.\n");
      if (diff_sp>100) 
         write("Sp : You kick "+enemy_name+"'s ass!\n");
      else if(diff_sp>0)
         write("Sp : You are stronger then "+enemy_name+".\n");
      else if(diff_sp==0)
         write("Sp : You have as many spell points as "+enemy_name+".\n");
      else if(diff_sp<-100)
         write("Sp : "+enemy_name+" kicks your ass!\n"); 
      else
         write("Sp : "+enemy_name+" is stronger then you.\n");
      if (diff_ac>5) 
         write("Ac : You kick "+enemy_name+"'s ass!\n");
      else if(diff_ac>0)
         write("Ac : You are stronger then "+enemy_name+".\n");
      else if(diff_ac==0)
         write("Ac : You have the same armor class of "+enemy_name+".\n");
      else if(diff_ac<-5)
         write("Ac : "+enemy_name+" kicks your ass!\n"); 
      else
         write("Ac : "+enemy_name+" is stronger then you.\n");
      if (diff_wc>5) 
         write("Wc : You kick "+enemy_name+"'s ass!\n");
      else if(diff_wc>0)
         write("Wc : You are stronger then "+enemy_name+".\n");
      else if(diff_wc==0)
         write("Wc : You have the same weapon class of "+enemy_name+".\n");
      else if(diff_wc<-5)
         write("Wc : "+enemy_name+" kicks your ass!\n"); 
      else
         write("Wc : "+enemy_name+" is stronger then you.\n");
      if (diff_lv>5) 
         write("Level : You kick "+enemy_name+"'s ass!\n");
      else if(diff_lv>0)
         write("Level : You are stronger then "+enemy_name+".\n");
      else if(diff_lv==0)
         write("Level : You are the same level of "+enemy_name+".\n");
      else if(diff_lv<-5)
         write("Level : "+enemy_name+" kicks your ass!\n"); 
      else
         write("Level : "+enemy_name+" is stronger then you.\n");
      
      return 1;
   }                                             
   write("Usage: compare <monster>\n");
   return 1;
}

feign()  {
   object obj;
   if(guild_level() < 4 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < FEIGN_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-FEIGN_SPELL);
   obj=first_inventory(environment(me()));
   while(obj)   {
      call_other(obj,"stop_hunting_mode");
      call_other(obj,"stop_fight");
      obj->attack_object();
      obj->attacked_by();
      call_other(obj,"stop_hunting_mode");
      call_other(obj,"stop_fight");
      obj->attack_object();
      obj->attacked_by();
      obj=next_inventory(obj);
   }
   write("You simulate your death. Everyone in the room stops fighting!\n");
   say(RN()+" died.\nYou stop fighting to see what has happened!\n");
   return 1;
}

scan(str) {
   object obj;
   if(guild_level() < 4 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!str) {
      write("What do you want to scan?\n");
      return 1;
   }
   obj=find_living(str);
   if(!obj)  {
      write("No "+str+" on.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < SCAN_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-SCAN_SPELL);
   write("You gaze into "+capitalize(str)+"'s eyes and see: Hp left: "+
      call_other(obj,"query_hp",)*100/call_other(obj,"query_mhp",)+"%.\n");
   return 1;
}

set_hp_stored(str)  {
   xhp=str;
   return 1;
}

set_sp_stored(str)  {
   xsp=str;
   return 1;
}

set_guild_whimpy(str)  {
   guild_whimpy=str;
   return 1;
}

query_whimpy() { return guild_whimpy; }
set_prev_touch(str)  {
   touch_spell=str;
   return 1;
}

renew()         {
   object obj;
   if(plagwait || stormwait || chillwait || weakwait || grabwait)  {
      write("You can't renew now. Try later\n");
      return 1;
   }
   if(hide_on)
      command("hide",me());
   write("Refreshing life.\n");
   obj=clone_object("/players/"+randname+"/life.c");
   move_object(obj,me());
   obj->set_hp_stored(xhp);
   obj->set_sp_stored(xsp);
   if(guild_level() > 5 )  {
      write("HP stored: "+xhp+".\n");
      write("SP stored: "+xsp+".\n");
   }
   if(obj->query_whimpy()!=guild_whimpy)
      {
      obj->set_guild_whimpy(guild_whimpy);
      write("Whimpy mode restored  to "+guild_whimpy+"%.\n");
   }
   obj->set_noentrance();
   obj->set_prev_touch(touch_spell);
   write("Touch power set to "+touch_spell+".\n");
   destruct(this_object());
   return 1;
}

aid(str)  {
   int points;
   string name;
   object who;
   if(guild_level() < 4 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!str)  {
      write("Usage : aid <player> <nn>.\n");
      return 1;
   }
   if (sscanf(str,"%s %d",name,points)!=2)  {
      write("Usage : aid <player> <nn>.\n");
      return 1;
   }
   who=find_player(name);
   if(!who)  {
      write("No "+capitalize(name)+" on.\n");
      return 1;
   }
   if(points<0 || points>me()->query_sp())  {
      write("Spell points out of range.\n");
      return 1;
   }
   call_other(who,"add_spell_point",points);
   call_other(me(),"add_spell_point",-points);
   write("You aid "+who->query_name()+" and send him "+points+" spell points.\n");
   tell_object(who,RN()+" helps you and sends you "+points+" spell points.\n");
   return 1;
}

raise(str)  {
   object who;
   if(guild_level() < 7 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!str)  {
      write("Who do you want to revive?\n");
      return 1;
   }
   who=find_player(str);
   if(!who || !present(who,environment(me())))  {
      write("No "+capitalize(str)+" here!\n");
      return 1;
   }
   if(!who->query_ghost())  {
      write(who->query_name()+" doesn't seem to need it.\n");
      return 1;
   }
   if(me()->query_sp() < RAISE_SPELL)  {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-RAISE_SPELL);
   if(random(101) > 50)  {
      write("Your eyes and your hands start to glow...\n");
      write("The ghost of "+capitalize(str)+" trembles...\n");
      write("You try but nothing happen.\n");
      write("You fail to revive "+capitalize(str)+"!\n");
      say(RN()+"'s eyes and hands start to glow.\n");
      say(RN()+" just fail to revived "+capitalize(str)+" from the death.\n");
      return 1;
   }
   write("Your eyes and your hands start to glow...\n");
   write("The ghost of "+capitalize(str)+" trembles...\n");
   write("The ghost begins to take the shape of "+who->query_name()+"!\n");
   write("You just revived "+capitalize(str)+"!\n"); 
   call_other(who, "remove_ghost", 0);
   tell_object(who,"You feel a very strong force.\n");
   tell_object(who,"You are sucked away...\n");
   tell_object(who,"You reappear in a more solid form.\n");
   say(RN()+"'s eyes and hands start to glow.\n");
   say(RN()+" just revived "+capitalize(str)+" from the death.\n");
   return 1;
}

low_armor()  {
   object obj;
   if(guild_level() < 3 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(call_other(me(),"query_money") < LOW_ARMOR_SPELL) {
      write("You don't have enough gold coins.\n");
      return 1;
   }
   call_other(me(),"add_money",-LOW_ARMOR_SPELL);
   write("You utter some words unknown to the living and a magical vest appears.\n");
   say(RN()+" utters unknown words and a magical vest appears.\n");
   obj=clone_object("/players/hurtbrain/closed/guild/vest");
   move_object(obj,me());
   return 1;
}

low_weapon()  {
   object obj;
   if(guild_level() < 3 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(call_other(me(),"query_money") < LOW_WEAPON_SPELL) {
      write("You don't have enough gold coins.\n");
      return 1;
   }
   call_other(me(),"add_money",-LOW_WEAPON_SPELL);
   write("You utter some words unknown to the living and a ball of fire appears.\n");
   say(RN()+" utters unknown words and creates a ball of fire.\n");
   obj=clone_object("/players/hurtbrain/closed/guild/ball");
   move_object(obj,me());
   return 1;
}

high_armor()  {
   object obj;
   if(guild_level() < 4 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(call_other(me(),"query_money") < HIGH_ARMOR_SPELL) {
      write("You don't have enough gold coins.\n");
      return 1;
   }
   call_other(me(),"add_money",-HIGH_ARMOR_SPELL);
   write("You magically create a force field!\n");
   say(RN()+" magically creates a force field.\n");
   obj=clone_object("/players/hurtbrain/closed/guild/field");
   move_object(obj,me());
   return 1;
}

high_weapon()  {
   object obj;
   if(guild_level() < 4 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(call_other(me(),"query_money") < HIGH_WEAPON_SPELL) {
      write("You don't have enough gold coins.\n");
      return 1;
   }
   call_other(me(),"add_money",-HIGH_WEAPON_SPELL);
   write("You utter some words unknown to the living and a firewhip appears.\n");
   say(RN()+" utters unknown words and creates a firewhip.\n");
   obj=clone_object("/players/hurtbrain/closed/guild/whip");
   move_object(obj,me());
   return 1;
}

call()  {
   object obj;
   object mor;
   object env;
   if(guild_level() < 5 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   obj=find_living("zombie_"+lower_case(RN()));
   if(!obj)  {
      write("No zombie to call.\n");
      return 1;
   }
   mor=find_living("morph_"+lower_case(RN()));
   if(mor) env=environment(mor);
   else env=environment(me());
   tell_room(environment(obj),"As you hear a whistle "+obj->query_name()+" shades off from your view.\n");
   move_object(obj,environment(me()));
   command("zomfo",me());
   move_object(obj,env);
   tell_room(env,obj->query_name()+" appears near his master, "+RN()+".\n");
   write("Your zombie arrives and stands at your side.\n");
   return 1;
}

promote(str)  {
   object obj;
   int lev;
   int gexp;
   if(guild_level() != 10 && guild_level() != 100 && guild_level() != 25)  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!str)  {
      write("Who do you want to promote?.\n");
      return 1;
   }
   obj=find_player(str);
   if(!obj)  {
      write("No "+capitalize(str)+" on.\n");
      return 1;
   }
   if(!present("soul-undead",obj))  {
      write(obj->query_name()+" is not an Undead!\n");
      return 1;
   }
   gexp=obj->query_guild_exp();
   if(gexp < SECOND_LEVEL)  {
      call_other(obj,"add_guild_exp",SECOND_LEVEL-gexp);
      lev=2;
   }
   else if(gexp < THIRD_LEVEL)  {
      call_other(obj,"add_guild_exp",THIRD_LEVEL-gexp);
      lev=3;
   }
   else if(gexp < FOURTH_LEVEL)  {
      call_other(obj,"add_guild_exp",FOURTH_LEVEL-gexp);
      lev=4;
   }
   else if(gexp < FIFTH_LEVEL)  {
      call_other(obj,"add_guild_exp",FIFTH_LEVEL-gexp);
      lev=5;
   }
   else if(gexp < SIXTH_LEVEL)  {
      call_other(obj,"add_guild_exp",SIXTH_LEVEL-gexp);
      lev=6;
   }
   else if(gexp < SEVENTH_LEVEL)  {
      call_other(obj,"add_guild_exp",SEVENTH_LEVEL-gexp);
      lev=7;
   }
   else if(gexp < EIGHTH_LEVEL)  {
      call_other(obj,"add_guild_exp",EIGHTH_LEVEL-gexp);
      lev=8;
   }
   else if(gexp < GUILD_COM)  {
      call_other(obj,"add_guild_exp",GUILD_COM-gexp);
      lev=10;
   }
   else  {
      write("You can't promote to wiz's level!\n");
      return 1;
   }
   tell_object(obj,"You are promoted in the guild by "+RN()+".\n");
   write("You promoted "+obj->query_name()+" to level "+lev+".\n");
   log_file("hurtbrain.pro",RN()+" promoted "+obj->query_name()+" to level "+lev+".\n");
   return 1;
}

gdemote(str)  {
   object obj;
   int lev;
   int gexp;
   string name;
   if(guild_level() != 10 && guild_level() != 100 && guild_level() != 25)  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!str)  {
      write("Who do you want to demote?.\n");
      return 1;
   }
   obj=find_player(str);
   if(!obj)  {
      write("No "+capitalize(str)+" on.\n");
      return 1;
   }
   if(!present("soul-undead",obj))  {
      write(obj->query_name()+" is not an Undead!\n");
      return 1;
   }
   name=obj->query_real_name();
   if(name=="hurtbrain" || name=="trix" || name=="gorgan")  {
      write("You can't demote guild wizard.\n");
      return 1;
   }
   gexp=obj->query_guild_exp();
   if(gexp < SECOND_LEVEL)  {
      write(obj->query_name()+" is already level 1.\n");
      return 1;
   }
   else if(gexp < THIRD_LEVEL)  {
      call_other(obj,"add_guild_exp",-gexp);
      lev=1;
   }
   else if(gexp < FOURTH_LEVEL)  {
      call_other(obj,"add_guild_exp",SECOND_LEVEL-gexp);
      lev=2;
   }
   else if(gexp < FIFTH_LEVEL)  {
      call_other(obj,"add_guild_exp",THIRD_LEVEL-gexp);
      lev=3;
   }
   else if(gexp < SIXTH_LEVEL)  {
      call_other(obj,"add_guild_exp",FOURTH_LEVEL-gexp);
      lev=4;
   }
   else if(gexp < SEVENTH_LEVEL)  {
      call_other(obj,"add_guild_exp",FIFTH_LEVEL-gexp);
      lev=5;
   }
   else if(gexp < EIGHTH_LEVEL)  {
      call_other(obj,"add_guild_exp",SIXTH_LEVEL-gexp);
      lev=6;
   }
   else if(gexp < GUILD_COM)  {
      call_other(obj,"add_guild_exp",SEVENTH_LEVEL-gexp);
      lev=7;
   }
   else  {
      call_other(obj,"add_guild_exp",EIGHTH_LEVEL-gexp);
      lev=8;
   }
   tell_object(obj,"You are demoted in the guild by "+RN()+".\n");
   write("You demoted "+obj->query_name()+" to level "+lev+".\n");
   log_file("hurtbrain.pro",RN()+" demoted "+obj->query_name()+" to level "+lev+".\n");
   return 1;
}

set_lev(str)  {
   int num;
   if(rn()!="hurtbrain" && rn()!="trix" && rn()!="gorgan")  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!str)  {
      write("Guild level set to 100.\n");
      lev_out=100;
      return 1;
   }
   sscanf(str,"%d",num);
   if(num<=0)   {
      write("Guild level set to 100.\n");
      lev_out=100;
      return 1;
   }
   write("Guild level set to "+num+".\n");
   lev_out=num;
   guild_level();
   return 1;
}

leave(str)  {
   object obj;
   if(str)  return 0;
   write("YOU ARE A TRAITOR!!!!!!!\nResetting your guild levels.\n");
   write("You lose 1/6 of your xp.\nYou feel your power decreasing.\n");
   write("You turn human again.\n");
   obj=find_living("zombie_"+lower_case(me()->query_name()));
   if(hide_on) command("hide",me());
   if(obj) command("peace str",me());
   me()->set_guild_name(0);
   me()->add_guild_exp(-me()->query_guild_exp());
   me()->add_guild_rank(-me()->query_guild_rank());
   me()->add_exp(-(me()->query_exp()/3));
   destruct(this_object());
   return 1;
}

awho(str){
   object us;
   int x;
   if(str) return;
   us = users();
   write("*-----------------------------------------------------------------------------*\n");
   write("|*Name*---*Sex*Level*-*Guild*-------*Location*--------------------------------|\n");
   write("*-----------------------------------------------------------------------------*\n");
   for(x=0;x<sizeof(us);x++){
      int invis;
      invis=us[x]->query_invis();
      if(invis<this_player()->query_level()){
         if(invis) { write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"); }
         write(capitalize(us[x]->query_real_name()));
         if(strlen(us[x]->query_real_name())>7)
            write("\t"); else write("\t\t");
         write(esc+"[0m");
         write("\b\b\b\b");
         if(us[x]->query_gender()=="male")
            write("M   ");
         else
            if(us[x]->query_gender()=="female")
            write("F   ");
         else 
            write("C   ");
         write(us[x]->query_level()+"\t\b");
         if(us[x]->query_guild_name())
            if(us[x]->query_guild_name()=="Black Circle Mage")
            write("BC Mage\t\t");
         else
            write(capitalize(us[x]->query_guild_name())+"\t");
         
         else 
            write("None\t");
         if(!us[x]->query_guild_name()||strlen(us[x]->query_guild_name())<=8) write("\t");
         write("\b\b\b\b");
         if(!environment(us[x])) write("Logging in");
         else write(environment(us[x])->short());
         write("\n");}
   }
   write("*----------------------Players currently logged on: "+x);
   if(x<10) write("-");
   write("------------------------*\n");
   return 1;
}

tell(str) {
   object ob;
   string who;
   string msg;
   string it;
   if (me()->query_ghost()) {
      write("You fail.\n");
      return 1;
   }
   if (me()->query_spell_point() < 0) {
      write("You are low on power.\n");
      return 1;
   }
   if (!str || sscanf(str, "%s %s", who, msg) != 2) {
      write("Tell what?\n");
      return 1;
   }
   it = lower_case(who);
   ob = find_player(it);
   if (!ob) ob = find_living(it);
   if (!ob) {
      write("No player with that name.\n");
      return 1;
   }
   if (interactive(ob)) {
      if (ob->query_invis() >= 100) {
         write("No player with that name.\n");
         return 1;
       }
      if (in_editor(ob)) {
         write("That person is editing. Please try again later.\n");
         return 1;
       }
   }
   if (call_other( me(), "query_invis", 0) > 0 && call_other(me(), "query_level", 0) < 999)
      {
      write( "Don't be annoying.  Become visible before you talk to someone!\n" );
      return 1;
   }
   msg = format(msg, 60);
   tell_object(ob, me()->query_name() + " tells you: " + msg + "\n");
   write("Ok.\n");
   write("You tell "+who+ " " + msg);
   if(me()->query_level() < 20)
      call_other(me(),"add_spell_points",-5);
   return 1;
}

kill(str) {
   if(hide_on)  {
      write("You can't kill anyone while morphed!\n");
      return 1;
   }
}

tomb()  {
   if(environment(me())->realm()=="NT"&&this->query_level()<20)  {
      write("This room blocks your try to escape.\n");
      return 1;
   }
   
   if(environment(this)->short()!="Village church")
      {
      if(call_other(me(),"query_sp") < TOMB_SPELL) {
         write("You don't have enougth spell points.\n");
         return 1;
      }
      call_other(me(),"add_spell_point",-TOMB_SPELL);
   }
   write("You enter your own soul, travelling to your guild room.\n");
   say(RN()+" disappears in a flash of light.\n");
   move_object(me(),"/players/gorgan/closed/guild/guild_room.c");
   write("You reached undead's guild room!\n");
   say(RN()+" appears in a flash of light.\n");
   return 1;
}
set_whimpy(str)  {
   int num;
   if(!str)  {
      write("Guild Whimpy is ");
      if(guild_whimpy==-1)
         write("OFF.\n");
      else
         write("set to "+guild_whimpy+"%.\n");
      return guild_whimpy;
   }
   if(!sscanf(str,"%d",num))
      {
      write("Usage: set_whimpy <number>.\n");
      return 1;
   }
   if(num < 0 || num > 90)
      {
      write("Guild Whimpy can be set [0-90] only.\n");
      return 1;
   }
   if(num==0)
      {
      guild_whimpy=-1;
      write("You set Guild Whimpy OFF.\n");
      return guild_whimpy;
   }
   write("You set Guild Whimpy to "+num+"%.\n");
   guild_whimpy=num;
   return guild_whimpy;
}

utp(str) {
   object ob;
   string who;
   string msg;
   string it;
   string msg2;
   if (!str || sscanf(str, "%s %s", who, msg) != 2) {
      write("What do you want to tell?\n");
      return 1;
   }
   it = lower_case(who);
   ob = find_player(it);
   if (!ob) ob = find_living(it);
   if (!ob) {
      write("No player with that name.\n");
      return 1;
   }
   if (interactive(ob)) {
      if (ob->query_invis() >= 100) {
         write("No player with that name.\n");
         return 1;
       }
      if (in_editor(ob)) {
         write("That person is editing. Please, do not disturb.\n");
         return 1;
       }
   }
   msg2 = format(msg, 62);
   msg = format(msg, 53);
   tell_object(ob, "<*>"+me()->query_name() + "<*> " + msg2 + "\n");
   write("You undead_tell "+who+ ": " + msg);
   return 1;
}

uep(str)  {
   object ob;
   string who;
   string msg;
   string it;
   string msg2;
   if (!str || sscanf(str, "%s %s", who, msg) != 2) {
      write("What do you want to emote?\n");
      return 1;
   }
   it = lower_case(who);
   ob = find_player(it);
   if (!ob) ob = find_living(it);
   if (!ob) {
      write("No player with that name.\n");
      return 1;
   }
   if (interactive(ob)) {
      if (ob->query_invis() >= 100) {
         write("No player with that name.\n");
         return 1;
       }
      if (in_editor(ob)) {
         write("That person is editing. Please, do not disturb.\n");
         return 1;
       }
   }
   msg2 = format(msg, 64);
   msg = format(msg, 68);
   tell_object(ob, "<***> "+me()->query_name() + " " + msg2 + "\n");
   write("You undead_emote "+who+ ":\n " +me()->query_name()+" "+ msg);
   return 1;
}
trance(arg)
{int num;
   if(guild_level() < 3 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg){
      write("How many hit points do u want to heal?\n");
      return 1;
   }
   else if(sscanf(arg,"%d",num)==1){
      if(num<0) { write("You can't do it! Try with a positive number.\n");
         return 1;
         }
      
      if(num>me()->query_sp()){
         write("You don't have that many spell points!\n");
         return 1;
         }
      if(this->query_mhp()-this->query_hp()<num)
         {  write("Your hit points are not that low, try with a lower amount.\n");
         return 1;
         } 
      say(capitalize(me()->query_real_name())+
         " enters a contemplative trance and suddenly looks healthier.\n",this);
      write("You enter a contemplative trance and feel suddenly better.\n");
      this->add_spell_point(-num);
      this->add_hit_point(num);
      return 1;
   }
}
score()
{  int lev,olev,xlev,lev_exp,spexp,next_lev;
   write("\n*============================> You are an UNDEAD <============================*");
   call_other(this,"score");
   write("Touch Power: "+touch_spell);
   if(touch_spell<100)
      write("\t");
   write("\t\t\tMorphing: ");
   if(hide_on)
      write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mOn"+esc+"[0m.\n");
   else    write("Off.\n");
   lev=guild_level();
   if(lev==1)
      next_lev=SECOND_LEVEL;
   else if(lev==2)
      next_lev=THIRD_LEVEL;
   else if(lev==3)
      next_lev=FOURTH_LEVEL;
   else if(lev==4)
      next_lev=FIFTH_LEVEL;
   else if(lev==5)
      next_lev=SIXTH_LEVEL;
   else if(lev==6)
      next_lev=SEVENTH_LEVEL;
   else if(lev==7)
      next_lev=EIGHTH_LEVEL;
   write("Time: "+ctime(time())+" CST\tGuild Whimpy: ");
   if(guild_whimpy>-1)
      write(guild_whimpy+"%.\n");
   else
      write("Off.\n");
   write("Guild Level: "+guild_level()+"  \t\t\tGxp to next level: ");
   if(lev<=7)
      {
      olev = this->query_level();
      if(olev>19) olev=19;
      xlev = this->query_extra_level();
      if(xlev>19) xlev = 19;
      if(olev > 18&&xlev>0) lev_exp = call_other("/room/exlv_guild","get_next_exp",xlev-1);
      else lev_exp = call_other("/room/adv_guild","get_next_exp",olev-1);
      spexp=this->query_exp()-lev_exp;
      next_lev-=(spexp+this->query_guild_exp());
      write(next_lev+".\n");
   }
   else write("--.\n");
   write("*=============================================================================*\n");
   return 1;
}

lead()  {
   object who;
   if(guild_level() < 5 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!me()->query_attack())  {
      write("You are not fighting anyone!\n");
      return 1;
   }
   who=me()->query_attack();
   if(who->query_attack()==me())  {
      write("You already lead the fight!\n");
      return 1;
   }
   write("You break throught the crowd and stand between "+who->query_name(
         )+" and "+(who->query_attack())->query_name()+".\n");
   say(RN()+" leads the fight now!\n");
   who->attack_object(me());
   return 1;
}
grab()  {
   int delay;
   object facade;
   if(guild_level() < 8 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   grabwho=call_other(this,"query_attack");
   if(!grabwho)  {
      write("You are not attacking anyone!\n");
      return 1;
   }
   if(!grabwho->query_npc())  {
      write("You can't grab players!\n");
      return 1;
   }
   if(call_other(this,"query_sp") < GRAB_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   if(grabwait)
      {
      write("Your concentration is still too low!\n");
      return 1;
   }
   grabwait=1;
   grabwc=grabwho->query_wc();
   grabwho->set_wc("GRABBED");
   tell_object(this,"You concentrate on the ground around your opponent and a lot of skeletal hands\n"+
      "come out of the ground holding it still and helpless.\n");
   say(capitalize(this->query_real_name())+" summons some skeletal hands to block the opponent.\n",this);
   call_other(this,"add_spell_point",-GRAB_SPELL);
   call_out("grabrestore",20);
   call_out("grabrem",90);
   return 1;
}
grabrestore()
{ 
   if(grabwho)
      {
      tell_room(environment(grabwho),"The grabbing hands lose their power and sink into the ground.\n");
      grabwho->set_wc(grabwc);
      grabwho->attack_object(this);
   }
}

grabrem() 
{  tell_object(this,"You recover from your previous grab effort.\n");
   grabwait=0; }
fix(arg) {
   object ob;
   if(guild_level() < 8 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if (!arg) return 0;
   ob=present(arg,this);
   if(!ob) ob = present(arg,environment(this));
   if(!ob) {
      write("There's no "+arg+" here.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < FIX_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   if(!ob->fix_weapon()) {
      write("The "+arg+" is not broken.\n");
      return 1; 
   }
   call_other(this,"add_spell_point",-FIX_SPELL);
   write("You hold a broken "+arg+" still in your hands, close your eyes and a glowing\n"+
      "red light encircles the fracture. When the light is gone u notice the weapon is\n"+
      "perfectly fixed.\n");
   say(capitalize(this->query_real_name())+" holds a broken "+arg+" still in the hands, he closes"+
      " the eyes and a\n"+
      "glowing red light encircles the fracture line. When the light is gone u notice\n"+
      "the weapon is perfectly fixed.\n");
   return 1;
}


plague()  {
   if(guild_level() < 8 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   plagwho=call_other(this,"query_attack");
   if(!plagwho)  {
      write("You are not attacking anyone!\n");
      return 1;
   }
   if(!plagwho->query_npc())  {
      write("You can't plague players!\n");
      return 1;
   }
   if(call_other(this,"query_sp") < PLAGUE_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   if(plagwait)
      {
      write("You're still resting from your previous plague!\n");
      return 1;
   }
   plagwait=1;
   plagdur=5;
   tell_object(this,"You turn your palms in the direction of your enemy and its skin is suddenly\n"+
      "covered with pulsing sores.\n");
   say(capitalize(this->query_real_name())+" turns the palms in the direction of the enemy whose skin is suddenly\n"+
      "covered with pulsing sores.\n",this);
   call_other(this,"add_spell_point",-PLAGUE_SPELL);
   plageff();
   call_out("remplag",70);
   return 1;
}

plageff()
{ 
   plagdur--;
   if(plagwho)
      {
      plagwho->hit_player(5+random(6));
      tell_room(environment(plagwho),capitalize(plagwho->query_name())+"'s skin cracks and rots, falling on the ground.\n");
   }
   if(plagdur>0&&plagwho && plagwho==this->query_attack()) call_out("plageff",6);
   else tell_room(environment(plagwho),"Monster's skin stops rotting.\n");
}

remplag() { 
   tell_object(this,"You recover from your previous plague effort.\n");
   plagwait=0; }
storm()  {
   if(guild_level() < 8 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   stormwho=call_other(this,"query_attack");
   if(!stormwho)  {
      write("You are not attacking anyone!\n");
      return 1;
   }
   if(!stormwho->query_npc())  {
      write("You can't storm players!\n");
      return 1;
   }
   if(call_other(this,"query_sp") < STORM_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   if(stormwait)
      {
      write("You're still resting from your previous storm!\n");
      return 1;
   }
   stormwait=1;
   stormdur=60;
   tell_object(this,"You raise your hands to the sky that suddenly becomes dark and cloudy.\n"+
      "A furious wind blows all around "+stormwho->query_name()+", while rain and lightnings strikes violently.\n");
   say(capitalize(this->query_real_name())+" raises the hands to the sky that suddenly becomes dark and cloudy.\n"+
      "A furious wind blows all around "+stormwho->query_name()+", while rain and lightnings strikes violently.\n",this);
   call_other(this,"add_spell_point",-STORM_SPELL);
   stormeff();
   call_out("remstorm",120);
   return 1;
}
stormeff()
{ 
   int stormnum;
   stormnum=7+random(8);
   stormdur-=stormnum;
   if(stormwho)
      {
      stormwho->hit_player(15+random(15));
      tell_room(environment(stormwho),capitalize(stormwho->query_name())+" is hit by the fury of a violent storm and flashed by the lightning.\n");
   }
   if(stormdur>0&&stormwho && stormwho==this->query_attack()) call_out("stormeff",stormnum);
   else tell_room(environment(stormwho),"The clouds are carried away by a strong wind.\n");
}
remstorm() { 
   tell_object(this,"You recover from your previous storm effort.\n");
   stormwait=0; }
blast(arg)  {
   object who,obj;
   int oldhp;
   if(guild_level() < 8 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg)  {
      who=call_other(me(),"query_attack");
      if(!who)  {
         write("Who do you want to send the blast to?\n");
         return 1;
      }
   }
   else  {
      who=present(arg,environment(me()));
      if(!who)  {
         write("No "+capitalize(arg)+" here.\n");
         return 1;
      }
      who=find_living(arg);
      if(!who)  {
         write("You can't attack objects.\n");
         return 1;
      }
        who=present(arg,environment(me()));
      if(who==find_player(arg) && !(who->query_pl_k() && me()->query_pl_k()))  {
         write("You can't attack "+who->query_name()+".\n");
         return 1;
      }
   }
   if(!who->query_npc())  {
      write("You can't attack players!\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < BLAST_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   call_other(me(),"add_spell_point",-BLAST_SPELL);
   write("You swing an arm in the air in the direction of "+who->query_name()+".\n"+
      "A massive blast overcomes "+who->query_name()+".\n");
   say(RN()+" swings an arm in the air in the direction of "+who->query_name()+".\n"+
      "A massive blast overcomes "+who->query_name()+".\n");
   me()->attack_object(who);
   oldhp=who->query_hp();
   who->hit_player(20);
   who->hit_player(20);
   who->hit_player(20);
   who->hit_player(10+random(10));
   who->hit_player(random(20));
   if(oldhp-who->query_hp()<60)    who->hit_player(40);
   return 1;
}
guildfix(arg)
{ object who,life;
   if(guild_level() != 10 && guild_level() != 100 && guild_level() != 25)  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg)  {
      write("Whose guild object do you want to fix?\n");
      return 1;
   }
   who=find_living(arg);
   if(!who){
      write("No "+arg+" on.\n");
      return 1;
   }
   if(who->query_guild_name()!="undead")
      {
      write(capitalize(arg)+" is not an Undead, forget about it!\n");
      return 1;
   }
   if(present("soul-undead",who))
      {
      write(capitalize(arg)+" already has a life!!!\n");
      return 1;
   }
   life=clone_object("/players/hurtbrain/life");
   move_object(life,who);
   command("renew",who);
   return 1;
}
ecnart(arg)
{int num;
   if(guild_level() < 3 ){
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(!arg){
      write("How many hit points do u want to swap?\n");
      return 1;
   }
   else if(sscanf(arg,"%d",num)==1){
      if(num<0) { write("You can't do it! Try with a positive number.\n");
         return 1;
         }
      
      if(me()->query_hp()-num<20){
         write("It's not safe to concentrate so hard!\n");
         return 1;
         }
      if(this->query_msp()-this->query_sp()<num)
         {  write("Your spell points are not that low, try with a lower amount.\n");
         return 1;
         }
      say(capitalize(me()->query_real_name())+
         " enters a contemplative trance and with a huge physical effort increases\n"+
         "their magical skills.\n",this);
      write("You enter a contemplative trance and feel weaker but better magically skilled.\n");
      this->add_spell_point(num);
      this->add_hit_point(-num);
      return 1;
   }
}
speed() {
   if(guild_level() < 2 ){
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(present("speedster",me())){
      write("You already have your speedster.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < SPEED_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
   }
   write("You receive a speedster from Hurtbrain.\n");
   call_other(me(),"add_spell_point",-SPEED_SPELL);
   move_object(clone_object("/players/hurtbrain/obj/newspeed.c"),me());
   return 1;
}

whistle()  {
   object obj;
   object mor;
   object env;
   if(guild_level() < 3 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   obj=find_living("dog_"+lower_case(RN()));
   if(!obj)  {
      write("You have no dog to call.\n");
      return 1;
   }
   mor=find_living("morph_"+lower_case(RN()));
   if(mor) env=environment(mor);
   else env=environment(me());
   tell_room(environment(obj),"As you hear a whistle "+obj->query_name()+" trots away to its master.\n");
   move_object(obj,environment(me()));
   command("dogfo",me());
   move_object(obj,env);
   tell_room(env,obj->query_name()+" appears near his master, "+RN()+".\n");
   write("Your dog trots and stops at your side.\n");
   return 1;
}

dog()
{ object dog;
   if(guild_level() < 3 )  {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   if(find_living("zombie_"+lower_case(me()->query_name())))  {
      write("You already have a pet zombie.\n");
      return 1;
   }
   if(find_living("dog_"+lower_case(me()->query_name())))  {
      write("You already have a death dog.\n");
      return 1;
   }
   if(call_other(me(),"query_sp") < DOG_SPELL) {
      write("You don't have enough spell points.\n");
      return 1;
/* blt add. */

  if(!pet_zone()) return 1;

/*      */
   }
   call_other(me(),"add_spell_point",-DOG_SPELL);
   dog=clone_object("/players/trix/closed/guild/ddog");
   call_other(dog, "set_master",this_player());
   move_object(dog,environment(this_player()));
   call_other(dog,"toggle_follow");
   write("You whistle loudly and a huge death dog rises from the shadows.\n");
   say(RN()+" whistles loudly and a huge death dog rises from the shadows.\n");
   return 1;
}

creat_flyer()
{
   if(guild_level() < 10)   {
      write("This spell is too powerful for you.\n");
      return 1;
   }
   write("You clap your hands and a Undead's guild flyer appears in it.\n");
   say(RN()+" claps his hands and a flyer appears.\n");
   move_object(clone_object("/players/hurtbrain/guildflyer.c"),this);
   return 1;
}
cl_edit() {
    if(guild_level() != 25 && guild_level() != 100) return 0;
    if(present("editor",me()))  {
        write("You already have one!\n");
        return 1;
        }
    move_object(clone_object("/players/hurtbrain/closed/guild/editor"),me()); 
    write("Ok.\n");
    return 1;
}
/* BEGINNING OF EMOTE SECTION */
find(arg) { return present(arg,environment(me())); }

check_edit(edwho)  { if(edwho->query_level()>20&&in_editor(edwho)) return 1; }

sex(arg) { return call_other(arg,"query_gender"); }

uname(arg){ return capitalize(call_other(arg,"query_real_name")); }

pos(arg) { if(sex(arg)=="male") return "his";
           else if(sex(arg)=="female") return "her";
           return "its";
         } 
pro(arg) { if(sex(arg)=="male") return "he";
           else if(sex(arg)=="female") return "she";
           return "it";
         } 
ogg(arg) { if(sex(arg)=="male") return "him";
           else if(sex(arg)=="female") return "her";
           return "it";
         } 
prp(arg) { if(sex(arg)=="male") return "his";
           else if(sex(arg)=="female") return "hers";
           return "its";
         } 

ugrin(arg) {
 write("You grin wickedly, your eyes glow with a red sick light.\n");
 say(uname(this)+" grins wickedly, "+pos(this)+" eyes glow with a red sick light.\n",this);
 return 1;
}

usmile(arg) {
 string self,aim,others;
 if(!arg) {  write("You smile an evil smile, your eyes betraying no signs of human feelings.\n");
             say(uname(this)+" smiles an evil smile, "+pos(this)+" eyes betraying no signs of human feelings.\n",this);
             return 1;
          }
 ewho=find(arg);
 if(!ewho) { write("No players with that name in this room.\n"); return 1; }
 self="You smile evilly at "+uname(ewho)+", your eyes betraying no signs of human feelings.\n";
 aim=uname(this)+" smiles evilly at you, "+pos(this)+" eyes betraying no signs of human feelings.\n"; 
 others=uname(this)+" smiles evilly at "+uname(ewho)+", "+pos(this)+" eyes betraying no signs of human feelings.\n";
 phone(self,aim,others);
 return 1;
}

uglare(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 ewho=find(arg);
 if(!ewho) { write("No players with that name in this room.\n"); return 1; }
 self="You glare at "+uname(ewho)+", red flashes coming out of your eyes reduced to two narrow slits.\n";
 aim=uname(this)+" glares at you, red flashes coming out of "+pos(this)+" eyes reduced to two narrow slits.\n"; 
 others=uname(this)+" glares at "+uname(ewho)+", red flashes coming out of "+pos(this)+" eyes reduced to two narrow slits.\n";
 phone(self,aim,others);
 return 1;
}


ugreet(arg) {
 string self,aim,others,bro;
 if(!arg) {  object us,life;
             string name;
             int x;
             write("You close your eyes and mentally greet your brothers undead.\n");
             say(uname(this)+" closes "+pos(this)+" eyes, "+pos(this)+" body relaxes as "+pro(this)+
                 " abandones it for an instant, then it quivers violently when "+pro(this)+" takes"+ 
                 " possession back.\n",this);
             us=users();
             name=uname(this);
             for(x=0;x<sizeof(us); x++) {
                    life=present("soul-undead",us[x]);
                    if(life&&!life->query_muffle()&&!check_edit(us[x])&&us[x]!=this)
                    {
                     tell_object(us[x],"You feel "+uname(this)+" enter your mind and greet you as an undead");
                     if(sex(us[x])=="female") tell_object(us[x]," sister.\n");
                     else tell_object(us[x]," brother.\n");                    
                    }
           }
             return 1;
          }
 ewho=find_living(arg);
 if(!ewho) { write("No players with that name in this room.\n"); return 1; } 
 if(ewho->query_guild_name()!="undead")
          {  write(capitalize(arg)+" is not an Undead.\n");
             return 1;

          }
 if(check_edit(ewho))
    {  write(uname(ewho)+" is editing. Please, do not disturb.\n");
       return 1;
    }
 if(sex(ewho)=="female") bro="sister";
 else bro="brother";
 self="You close your eyes and mentally greet "+uname(ewho)+" as an Undead "+bro+".\n";
 aim="You feel "+uname(this)+" enter your mind and greet you as an undead "+bro+".\n"; 
 others=uname(this)+" closes "+pos(this)+", "+pos(this)+" body relaxes as "+pro(this)+
                 " abandones it for an instant, then it quivers violently when "+pos(this)+" takes"+ 
                 " possession back.\n";
 phone(self,aim,others);
 return 1;
}

uwater(arg) {
 write("You express your repulsion for water.\n");
  say(uname(this)+" goes \"Water?!?!?! Eeeeeeek!!!!\".\n",this);
 return 1;
}

uoblige(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 ewho=find(arg);
 if(!ewho) { write("No players with that name in this room.\n"); return 1; }
 self="You force "+uname(ewho)+" to bow.\n";
 aim=uname(this)+" stares at you with red glowing eyes, you feel a tremendous power pushing"+
     " down on you, forcing you to bow.\n"; 
 others=uname(this)+" stares at "+uname(ewho)+" with red glowing eyes, "+uname(ewho)+" is"+
        " forced to bow deeply before "+ogg(this)+".\n";
 phone(self,aim,others);
 return 1;
}

uthreaten(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 ewho=find(arg);
 if(!ewho) { write("No players with that name in this room.\n"); return 1; }
 self="You suddenly spring and move behind "+uname(ewho)+", staring greedily at the"+
      " back of "+pos(ewho)+" neck.\n";
 aim="You bat your eyelids and when u reopen up your eyes "+uname(this)+" is not in front"+
     " of you anymore, shivers run up and down your spine as you feel two red eyes staring"+
     " at you from behind.\n"; 
 others=uname(this)+" moves quickly behind "+uname(ewho)+" and stares greedily at the back of "+pos(ewho)+" neck.\n";
 phone(self,aim,others);
 return 1;
}

phone(self,aim,others)
{object ob;
write(format(self, 80));
tell_object(ewho,format(aim, 80));
 ob=first_inventory(environment(this_player())); 
 while(ob) { if(ob!=ewho&&ob!=me()) tell_object(ob,others);
 ob=next_inventory(ob); } 
}  

/* END OF EMOTE SECTION */ 
uemotes(str) {
   if(str)  return;   
   write("\n  @====================== Undead Special Emotes ======================@\n");
   write("  ||**|uglare      ||* |ugreet      ||  |ugrin       ||**|uoblige     |\n");
   write("  ||* |usmile      ||**|uthreaten   ||  |uwater      ||  |            |\n");
   write("  @===================================================================@\n");
   return 1;
}
apprentice(str) {
  object new,aura;
        if(guild_level() < 10 )  {
                notify_fail("This spell is too powerful for you.\n");
                return 0;
                }
  if(!str) return;
  sscanf(str,"%s undead",str);
  new = find_player(str);
  if(!new) {
    write("Life: I could not find '"+str+"'\n");
    return 1;
  }
  if(!present(new,environment(me())))  {
        notify_fail("Life: "+new->query_name()+" is not here.\n");
        return 0;
        }
  if(present("soul-undead",new))  {
        notify_fail("Life: "+new->query_name()+" is already an Undead!\n");
        return 0;
        }
  if(present("aura-undead",new))  {
        notify_fail("Life: "+new->query_name()+" is already an Undead Apprentice!\n");
        return 0;
        }
  if((new->query_guild_name()&&lower_case(new->query_guild_name())!="none") || new->query_guild_exp())
  {
      notify_fail("Life: "+new->query_name()+" is already in another guild.\n");
      return 0;
      }
  if(new->query_level() < 3)  {
        notify_fail("Life: "+new->query_name()+" needs to be at least level 3.\n");
        return 0;
        }
  aura=clone_object("/players/trix/closed/guild/apprentice.c");
  move_object(aura,new);
  call_other(aura,"set_age",new->query_age());
  tell_object(new,RN()+" just made you an Undead Apprentice.\n");
  write("You raise your powerful hands and mark "+new->query_name()+" as an Undead Apprentice!\n");
  say(RN()+" just marked "+new->query_name()+" as an Undead Apprentice.\n",new);
  command("ut "+new->query_name()+" is now an Undead Apprentice!\n",this_player());
  return 1;
}
appfix(arg)
{ object who,aura;
    if(guild_level()!= 10 && guild_level() != 100)  {
                notify_fail("This spell is too powerful for you.\n");
                return 0;
                }
    if(!arg)  {
                notify_fail("Whose apprentice aura do you want to fix?\n");
                        return 0;
                }
  who=find_living(arg);
  if(!who){
         notify_fail("No "+arg+" on.\n");
         return 0;
        }
  if(who->query_guild_name()!="[UndApp]")
   {
        write(capitalize(arg)+" is not an Undead Apprentice, forget about it!\n");
        return 1;
   }
  if(present("aura-undead",who))
   {
        write(capitalize(arg)+" already has an aura!!!\n");
        return 1;
   }
  aura=clone_object("/players/trix/closed/guild/apprentice");
  call_other(aura,"set_age",who->query_age()-7500);
  move_object(aura,who);
  command("renew",who);
  return 1;
}
