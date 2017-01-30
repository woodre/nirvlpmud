#include "/players/boltar/things/esc.h"

#define LOGGINMESSAGE "     Welcome back, deadhead        "
#define HEART "/players/hurtbrain/closed/guild/uheart.c"
#define SECOND_LEVEL 5000
#define THIRD_LEVEL 15000
#define FOURTH_LEVEL 35000
#define FIFTH_LEVEL 75000
#define SIXTH_LEVEL 155000
#define SEVENTH_LEVEL 315000
#define EIGHTH_LEVEL 635000
#define GUILD_COM 700000
#define GUILD_COM2 1000000
string dirname;
string randname;
int noentrance;
int hide_on;
object name,this;
int flag_follow,lasthp,lastsp,mon_on;
int muffled,gmuffled,touch_spell;
int guild_whimpy;
int first;
int glow_turn,glow_flag;
string morph;
object ex_att;
string inp;
int hand_on;
int xsp, xhp;
int num_more;
int lev_out;
object ewho;
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
query_auto_load()
{  return "/players/"+randname+"/life.c:";
}
long() {
   write("\tThis is the 'UNDEAD' symbol.\n"+
      "Use 'comm <command>' for a detailed description of a command.\n"+
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
     if(environment(this_object()))
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

/*
query_dirname() { tell_object(this_player(),capitalize(dirname)+".\n"); return 1; }
query_randname() { tell_object(this_player(),capitalize(randname)+".\n"); return 1; }
*/
query_dirname() { return dirname; }
query_randname() { return randname; }
init() {
   int prob;
   int lev;
   string nname;
   mon_on=0;
   lev=guild_level();
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
   /* LEVEL 1 SPELLS */
   add_action("communicate"); add_verb("say");
   add_action("communicate"); add_xverb("\"");
   add_action("communicate"); add_xverb("'");
   add_action("du","du");
   add_action("ut","ut");
   add_action("ue","ue");
   add_action("emote","emote");
   add_action("title","title");
   add_action("rankme","rankme");
   add_action("utm","utm");
   add_action("hide","hide");
   add_action("new_command","new_command");
   add_action("new_command2","new_command2");
   add_action("renew","renew");
   add_action("uquit","quit");
   add_action("uemotes","uemotes");
   add_action("kill"); add_verb("kill");
/* NOT ALLOWED -Bp
   add_action("tell"); add_verb("tell");
*/
   add_action("awho","nwho");
   add_action("tomb","tomb");
   add_action("leave","guildleave");
   add_action("com1","com1");
   add_action("com2","com2");
   add_action("com3","com3");
   add_action("com4","com4");
   add_action("com5","com5");
   add_action("comm","comm");
   add_action("inv","i");
   add_action("uep","uep");
   add_action("utp","utp");
 /*  add_action("quit","quit");  */
   add_action("score","sc");
   add_action("score","score");
   add_action("set_whimpy","set_whimpy");
/* BEGINNING OF EMOTE ADD_ACTIONS */
    add_action("ugrin","ugrin");
    add_action("usmile","usmile");
    add_action("uglare","uglare");
    add_action("ugreet","ugreet");
    add_action("uwater","uwater");
    add_action("uoblige","uoblige");
    add_action("uthreaten","uthreaten");
/* END OF EMOTE ADD_ACTIONS */
/*
   add_action("mon","mon");
*/
/* END OF LEVEL 1 SPELLS */

    if(lev<2) return 1;

/* LEVEL 2 SPELLS */
   add_action("qgm","qgm");
   add_action("burn","burn");
   add_action("set_touch","set_touch");
   add_action("touch","Touch");
   add_action("speed","speed");
/* END OF LEVEL 2 SPELLS */

    if(lev<3) return 1;

/* LEVEL 3 SPELLS */
   add_action("melt","umelt");
   add_action("send","send");
   add_action("do_compare","know");
   add_action("charm","charm");
   add_action("glow","glow");
   add_action("dog","dog");
   add_action("whistle","whystle");
   add_action("trance","trance");
   add_action("ecnart","ecnart");
   add_action("low_armor","mvest");
   add_action("low_weapon","fball");
/* END OF LEVEL 3 SPELLS */

    if(lev<4) return 1;

/* LEVEL 4 SPELLS */
   add_action("fog","fog");
   add_action("vision","vision");
   add_action("scan","scan");
   add_action("feign","feign");
   add_action("aid","aid");
   add_action("high_armor","ffield");
   add_action("high_weapon","fwhip");
/* END OF LEVEL 4 SPELLS */

    if(lev<5) return 1;

/* LEVEL 5 SPELLS */
   add_action("animate","animate");
   add_action("call","call");
   add_action("quartz","quartz");
   add_action("shadows","shadows");
   add_action("glare","Glare");
   add_action("lead","lead");
/* END OF LEVEL 5 SPELLS */

    if(lev<6) return 1;

/* LEVEL 6 SPELLS */
   add_action("store_spell_points","ssp");
   add_action("store_hit_points","shp");
   add_action("xpts","stored");
   add_action("get_spell_points","gsp");
   add_action("get_hit_points","ghp");
   add_action("evoke","evoke");
   add_action("turn","turn");
   add_action("lightning","lightning");
/* END OF LEVEL 6 SPELLS */
    if(lev<7) return 1;
/*   LEVEL 7 SPELLS  */
   add_action("possess","possess");
   add_action("raise","revive");
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  @@@@@ START COMMENT:     LEVEL 7 AND 8 TEMPORARILY DOWN @@@@ 
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   add_action("hand","hand");
   add_action("chill","chill");
   add_action("weaken","weaken");
   add_action("fing","fing");
   END OF LEVEL 7 SPELLS

    if(lev<8) return 1;
   LEVEL 8 SPELLS    
   add_action("grab","grab");
   add_action("fix","fix");
   add_action("plague","plague");
   add_action("blast","blast");
   END OF LEVEL 8 SPELLS 


  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  @@@@@ STOP COMMENT:      LEVEL 7 AND 8 TEMPORARILY DOWN @@@@ 
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/*
   add_action("apprentice","apprentice");
*/
   if(lev==50) return 1;
   add_action("reject","reject");
   add_action("creat_flyer","flyer");
   add_action("promote","promote");
   add_action("gdemote","gdemote");
   add_action("gcw","gcw");
   add_action("gcm","gcm");
   add_action("gct","gct");
   add_action("gce","gce");
   add_action("comh","comh");
   add_action("guildfix","guildfix");
/*
*/
/* add_action("appfix","appfix"); */
   /* END MORTAL LEVELS SPELLS */
   if(lev<100) return 1;
   add_action("cl_edit","editor");
   add_action("set_lev","set_lev");
}

entrance()
{
   if(!noentrance)
      {
           tell_object(this,"\n\n\t\t"+esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+
            "  ***>>> "+LOGGINMESSAGE+" <<<***"+esc+"[0m"+
          "\n\t           Read the guild bullettin board for news!\n\n\n");
      tell_object(this,"->> ");
      HEART->guild_channel_mess(this->query_name()+" comes back to non-life.\n",this);
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
      noentrance=1;
   }
   return 1;
}

uquit() { return HEART->uquit(hide_on);}

guild_channel_mess(str){  return HEART->guild_channel_mess(str); }

set_touch(str)  { int touchy; touchy=HEART->set_touch(str,guild_level());
                  if(touchy) touch_spell=touchy;
                  return 1; }

communicate(str) { return HEART->communicate(str); }
utm()  { muffled=HEART->utm(muffled); return 1;}

gcw(str) { return HEART->gcw(); }

gcm()  { gmuffled=HEART->gcm(gmuffled); return 1;}

drop() { return 1; }

comm(str) {
   if(str) {
   write("\n*-----------------------------------------------------------------------------*\n");
   cat("/players/"+dirname+"/closed/guild/helpdir/"+str);
   write("*-----------------------------------------------------------------------------*\n");
   return 1;
   }
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
com1() { return HEART->com1(); }
com2() { return HEART->com2(); }
com3() { return HEART->com3(); }
com4() { return HEART->com4(); }
com5() { return HEART->com5(); }
comh() { return HEART->comh(); }

ut(str) { return HEART->ut(str,muffled); }

ue(str) { return HEART->ue(str,muffled); }

gct(str) { return HEART->gct(str,gmuffled); }

gce(str) { return HEART->gce(str,gmuffled); }

du() { return HEART->du(); }

turn(str) { return HEART->turn(str,randname); }

reject(str) { return HEART->reject(str); }

heartb()  {
   object att;
   int hit;
   if(glow_flag)  {
      --glow_turn;
      if(!glow_turn)  {
         tell_object(this,"Your body slowly stops glowing.\n");
         tell_room(environment(this),this->query_name()+" stops glowing.\n");
         glow_flag=0;
         set_light(-1);
      }
   }
   call_out("clean_morph",0);
   /*if(this->query_attack())  call_out("heartb",1);
   else */
      call_out("heartb",3);
}

clean_morph()
{
   if(find_living("sph_"+this->query_name()) && find_living("morph_"+this->query_name()) && interactive(this))  {
      destruct(find_living("morph_"+lower_case(me()->query_name())));
      destruct(find_living("sph_"+lower_case(me()->query_name())));
      hide_on=0;
   }
}

vision(str) { return HEART->vision(str); }

emote(str){ return HEART->emote(str); }

melt(str) { return HEART->melt(str); }

send(str) { return HEART->send(str); }

fog(arg)  { return HEART->fog(arg); }

lightning(arg)  { return HEART->lightning(arg); }

possess(arg)  { return HEART->possess(arg); }

raise(arg)  { return HEART->raise(arg); }

shadows(arg)  { return HEART->shadows(arg); }

glare(arg)  { return HEART->glare(arg); }

charm(arg)  { return HEART->charm(arg); }

touch(arg)  { return HEART->touch(arg,touch_spell); }

title(arg)  { return HEART->title(arg); }

rankme()  { return HEART->rankme(hide_on,morph,touch_spell,guild_level()); }

burn()  { return HEART->burn(); }

glow()  {
   glow_turn=50;
   if(HEART->glow()) {
          glow_flag=1;
          set_light(1);
   }
   return 1;
}

qgm(arg) { return HEART->qgm(arg,guild_level()); }

quartz()  { return HEART->quartz(); }

animate(arg) { return HEART->animate(arg); }

store_spell_points(){ 
   xsp+=HEART->store_spell_points(xsp);
   return 1;
}
store_hit_points(){ 
   xhp+=HEART->store_hit_points(xhp);
   return 1;
}

xpts(){ write("XHP: "+xhp+"\tXSP: "+xsp+"\n"); return 1; }

get_spell_points(amt){
   xsp-=HEART->get_spell_points(amt,xsp);
   return 1;
}

get_hit_points(amt){
   xhp-=HEART->get_hit_points(amt,xhp);
   return 1;
}

query_xsp(){ return xsp; }

query_xhp(){ return xhp; }

evoke()  { return HEART->evoke(); }

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
      call_other(sph,"set_short",me()->query_name()+"'s soul");
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
   object ex_env,str2,drunk;

   if(drunk=present("drunk",me())) destruct(drunk);
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


new_command()  {
   return 1;
}

new_command2()   {
   input_to("read");
   return 1;
}

inv() { return HEART->inv(); }

do_compare(str) { return HEART->do_compare(str); }

feign()  { return HEART->feign(); }

scan(str) { return HEART->scan(str); }

set_hp_stored(str)  { xhp=str; return 1; }

set_sp_stored(str)  { xsp=str; return 1; }


set_prev_touch(str)  {
   touch_spell=str;
   return 1;
}

renew() { return HEART->renew(randname,hide_on,touch_spell,xsp,xhp,this_object()); }

aid(str)  { return HEART->aid(str); }

low_armor()  { return HEART->low_armor(); }
low_weapon()  { return HEART->low_weapon(); }
high_armor()  { return HEART->high_armor(); }
high_weapon()  { return HEART->high_weapon(); }

call()  { return HEART->call(); }

promote(str)  { return HEART->promote(str); }

gdemote(str)  { return HEART->gdemote(str); }

leave()  { return HEART->leave(hide_on); }

awho(str){ return HEART->awho(str); }

tell(str) { return HEART->tell(str); }

kill(str) { if(hide_on)  { write("You can't kill anyone while morphed!\n"); return 1; } }

tomb()  { return HEART->tomb(); }

utp(str) { return HEART->utp(str); }

uep(str) { return HEART->uep(str); }

trance(arg) { return HEART->trance(arg); }

score() { return HEART->score(hide_on,touch_spell,guild_level()); } 

lead()  { return HEART->lead(); }

guildfix(arg) { return HEART->guildfix(arg); }

ecnart(arg) { return HEART->ecnart(arg); }

speed() { return HEART->speed(); }

whistle()  { return HEART->whistle(); }

dog() { return HEART->dog(); }

creat_flyer() { return HEART->creat_flyer(); }

cl_edit() { return HEART->cl_edit(); }

/* BEGINNING OF EMOTE SECTION */

ugrin(arg) { return HEART->ugrin(arg); }

usmile(arg) { return HEART->usmile(arg); }

uglare(arg) { return HEART->uglare(arg); }

ugreet(arg) { return HEART->ugreet(arg); }

uwater(arg) { return HEART->uwater(arg); }

uoblige(arg) { return HEART->uoblige(arg); }

uthreaten(arg) { return HEART->uthreaten(arg); }


/* END OF EMOTE SECTION */
uemotes(str) {
   if(str)  return;
   write("\n  @====================== Undead Special Emotes ======================@\n");
   write("  ||**|uglare      ||* |ugreet      ||  |ugrin       ||**|uoblige     |\n");
   write("  ||* |usmile      ||**|uthreaten   ||  |uwater      ||  |            |\n");
   write("  @===================================================================@\n");
   return 1;
}
apprentice(str) { return HEART->apprentice(str); }

appfix(arg) { return HEART->appfix(arg); }

query_hide() { return hide_on; }

fix_hide() { hide_on=0;}
