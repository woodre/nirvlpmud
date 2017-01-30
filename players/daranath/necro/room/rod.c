#include "../defs.h"
inherit ROOM;
string *RIFTS;

reset(arg){
    is_pk = 1;
  if(arg) return;
    is_pk = 1;
   RIFTS = ({ "Guild Hall#/players/daranath/necro/room/necro5.c", });
  short_desc = "The Realm of Death";
  long_desc = "  "+
  "Dark, swirling mists obscure the view of any tangible surroundings.  Spirits\n"+
  "fly across the vast landscape of nothingness.  The stale air of death fills the\n"+
  "void as the blackness collapses upon itself.\n";

  items= ({
  "mist","It is thick and black",
  "landscape","You see only darkness",
  "spirits","They are translucent white.  They fly through the clouds of mist.\n"+
        "You might want to '"+BOLD+"ask"+OFF+"' them '"+BOLD+"about joining"+OFF+"' or perhaps '"+BOLD+"about costs"+OFF+"'\n"+
        "to be trained.  You also might want to '"+BOLD+"ask"+OFF+"' them '"+BOLD+"to teach"+OFF+"' you", 
  "rift","It is a large hole within the void that crosses between the planes of the\n"+
         "living and the dead.  It is large enough for one to '"+BOLD+"enter"+OFF+"'"+"\n"+
         "Usage: enter rift <number>",
  "air","You see only darkness",
  "mists","They are thick and black",
  "void","You see only darkness",
  "surroundings","You see only darkness",
  });
  
  smells = ({
  "default","It smells with the stench of death and decay",
  "air","It smells with the stench of death and decay",
  });

  listens = ({
  "default","You hear screams, wails, and moans in the muffled distance",
  });

  set_light(1);
}

long(str){
string short,location;
int i,a;
  ::long(str);
  if(!str){
  for(i=0,a=sizeof(RIFTS);i<a;i++){
    sscanf(RIFTS[i],"%s#%s",short,location);
    write("A rift ("+short+")\n");
  }
  }
}
 
init(){
  ::init();
  spirit_talk("Welcome to the Realm of Death.");
  add_action("enterrift","enter");
  add_action("ask_spirits","ask");
  add_action("join","join");
  if(!GOB && tp->query_level() > 5){ hurtmebaby(tp); }
  if(!GOB && !tp->query_guild_exp() && !tp->query_guild_name() && tp->query_level() < 21 ){
    spirit_talk("If you are interested in joining you may ask us questions.");
  }
}

hurtmebaby(player){
  remove_call_out("hurtmebaby");
  if( environment(player) == this_object() && !present(GUILD_ID,player) && (player->query_guild_exp() || player->query_guild_name()) && player->query_level() < 21 ){ 
   tell_object(player,"An etherreal hand claws through yours soul taking youre life force with it.\n");
   spirit_talk("Begone you intruder.  Your not welcome!");
   player->heal_self(-50);
   call_out("hurtmebaby",10,player);
 }
}  

spirit_talk(str){
  tell_room(this_object(),BOLD+"The Spirits say, \""+OFF+str+BOLD+"\"\n"+OFF);
}

ask_spirits(str){
string who,what;
if(!str){ 
  notify_fail("Who would you like to ask?\n");
  return 0;
}
sscanf(str,"%s %s",who,what);
if(!what) who = str;
if(who != "spirits"){
  notify_fail("Who would you like to ask?\n");
  return 0;
}
if(!what){
  notify_fail("What would you like to ask the spirits?\n");
  return 0;
}
if(str != "spirits about costs" && str != "spirits to teach" && str != "spirits about joining"){
  write("The spirits seem to ignore your question.\n");
  return 1;
}
  if(str == "spirits about costs") return cost();
  if(str == "spirits to teach") return advance();
  if(str == "spirits about joining")  return joining();
}

joining(){
   write("You ask about joining the necromancers.\n");
   say(tpn+" asks about joining the necromancers.\n");
   spirit_talk("If you want to join then join fool.  Don't ask stupid questions.");
   return 1;
}

join() {
 write("You ask to join the necromancers.\n");
 say(tpn+" asks to join the necromancers.\n"); 
 if(tp->query_level() < 5) {
    spirit_talk("You are to young of a soul for us to train.  Begone!");
    return 1; 
  }
  if(tp->query_guild_name() || tp->query_guild_rank() || tp->query_guild_file() || tp->query_guild_exp()) {
    spirit_talk("You already have ties with other guilds.  We will not teach you!");
    return 1;
  }
  if(tp->query_level() > 5 || tp->query_extra_level() > 0) {
    spirit_talk("You must be willing to dedicate your life to following Sagan and serving\n"+
                "\tthe Realm of Death to join the Necromancers.");
    spirit_talk("A sacrifice is required to the Realm of Death.\n"+
                "\tAre you willing to be reduced to level 5? (y/n) ");
               input_to("accept");
               return 1; 
  }
  spirit_talk("You must be willing to dedicate your life to following Sagan and serving\n"+
                "\tthe Realm of Death to join the Necromancers.");
  spirit_talk("Are you willing to do this? (y/n) ");
  input_to("accept");
  return 1;
}

accept(str) {
  if(!str) {
   spirit_talk("Hit 'Y' if you are willing to be reduced to level 5.");
   input_to("accept"); 
   return 1;
  }
  if(str != "Y" && str != "y") {
   command("say NO!",tp);
   spirit_talk("Begone then you fool.");
   return 1; 
  }
  setup();
  return 1;
}

setup(){
object ob;
string file;
  write("You say you are ready.\n");
  say(tpn+" says "+tp->query_pronoun()+" is ready.\n");
  file = LOG+"/JOIN";
  write_file(file,ctime(time())+" "+tp->query_real_name()+"  level: "+tp->query_level()+"+"+tp->query_extra_level() +"\n");
  tp->add_exp(10000 - this_player()->query_exp());
  tp->set_level(5);
  tp->set_extra_level(0);
  ob = clone_object(PATH+"/guildob.c");
  file = LOG+"/JOIN";
  move_object(ob,tp);

spirit_talk("Then we shall take what we need!");
write(ROD+"You feel the knowledge you once had drained from you and replaced with something new.\n");
write(ROD+"You are a necromancer.\n");
GOB->save_me();
command("save",tp);
}

cost() {
int min_xp, c_xp, a, g_level;
int extra_xp, need_xp;
int c_val, need_val, amount;
  write("You ask the spirits what more you need to be trained.\n");
  if(!GOB){
    spirit_talk("You are not a necromancer.  Be gone with you!");
    return 1;
  }
  say(tpn+" asks the spirits what more "+tp->query_pronoun()+" needs to be trained.\n");
  if(tp->query_level() > 20) {
    spirit_talk("You have no need for this little one.");
    return 1; 
  }
  if(tp->query_extra_level()) 
    min_xp = call_other("/room/exlv_guild","get_next_exp",tp->query_extra_level()-1); 
  else
    min_xp = call_other("/room/adv_guild","get_next_exp",tp->query_level()-1);
  c_xp = tp->query_exp();
  extra_xp = c_xp - min_xp;
  c_val = GOB->query_val();
  g_level = tp->query_guild_rank();
  if(g_level > 8){
    spirit_talk("You have advanced your level as far as we can teach you.\n");
    return 1;
  }
   a = get_needed_xp_val(g_level);
  need_xp = a[0];
  need_val = a[1];
   amount = need_xp - extra_xp; 
   if(amount > 0) 
     spirit_talk("You still need "+amount+" more exp to learn more from us.");
   else 
     spirit_talk("You have enough exp to advance your Necromantic Level.");
   if(c_val < need_val) 
     spirit_talk("But we still hunger from you.");
   else
     spirit_talk("The Realm of Death is pleased with your actions.");
return 1; 
}

advance() {
string file;
int *a;
int min_xp, c_xp, g_level;
int extra_xp, need_xp;
int c_val, need_val;
  write("You ask the spirits to teach you.\n");
  say(tpn+" asks the spirits to teach "+tp->query_objective()+".\n");
  if(!GOB){
    spirit_talk("You are not a necromancer.  How dare you ask us to teach you.");
    return 1;
  }
  if(tp->query_extra_level()) 
    min_xp = call_other("/room/exlv_guild","get_next_exp",tp->query_extra_level()-1);
  else
    min_xp = call_other("/room/adv_guild","get_next_exp",tp->query_level()-1);
  c_xp = tp->query_exp();
  extra_xp = c_xp - min_xp;
  c_val = GOB->query_val();
  g_level = tp->query_guild_rank();
  if(g_level > 8){
    spirit_talk("You have advanced your level as far as we can teach you.\n");
    return 1;
  }
  a = get_needed_xp_val(g_level);
  need_xp = a[0];
  need_val = a[1];
   
   if(extra_xp < need_xp) {
     spirit_talk("You are not ready to learn from us.");
     return 1; 
   }
   if(c_val < need_val) {
     spirit_talk("We are not ready to teach you.");
     return 1;
   }
   tp->add_guild_exp(need_xp);
   tp->add_exp(-need_xp);
   tp->add_guild_rank(1); 
   GOB->set_val(0);
     spirit_talk("We shall teach you.");
   write(ROD+"Knowledge you did not have before seeps into you as part of your life is removed.\n");
   write(ROD+"You have advanced your Necromantic Level.\n");
   GOB->save_me();
   tp->reset(1);
   file = LOG+"/ADVANCE";
   write_file(file,ctime(time())+" "+tp->query_real_name()+"  level:"+
     (tp->query_level()+tp->query_extra_level())+"  To guildlevel:"+tp->query_guild_rank()+"\n");
   command("save",tp);
return 1; 
}

enterrift(str){
int which;
string short,location;
 if(!str){
   notify_fail("What would you like to enter?\n");
   return 0;
 }
 if(sizeof(RIFTS) == 1){ 
   which = 1;
 }
 sscanf(str,"rift %d",which);
 if(!which){
   notify_fail("Which rift would you like to enter?\n");
   return 0;
 }
 if(which > sizeof(RIFTS)){
  if(sizeof(RIFTS) == 1){
   notify_fail("There is only one rift to enter.\n");
   return 0;
  }
  if(sizeof(RIFTS) > 9){
    notify_fail("There are only "+sizeof(RIFTS)+" rifts to enter.\n");
    return 0;
  }
  else{
   notify_fail("There are only "+convert_number(sizeof(RIFTS))+" rifts to enter.\n");
   return 0;
  }
 }
 write("You enter rift "+which+".\n"+
       "You feel the energy of the dark portal flow into your body\n"+
       "as you enter and move to a new location.\n\n");
 say(tpn+" enters rift "+which+".\n");
 sscanf(RIFTS[which-1],"%s#%s",short,location);
 move_object(tp,location);
 command("glance",tp);
 return 1;
}

add_rift(str){
  RIFTS += ({ str, });
}

remove_rift(str){
  RIFTS -= ({ str, });
}
realm(){ return "NT"; }

get_needed_xp_val(i){
int need_xp,need_val;
   switch(i){
        case 1:  need_xp = 50000;     need_val = 150;  break;
        case 2:  need_xp = 75000;     need_val = 400;  break;
        case 3:  need_xp = 100000;    need_val = 550;  break;
        case 4:  need_xp = 200000;    need_val = 750;  break;
        case 5:  need_xp = 300000;    need_val = 850;  break;
        case 6:  need_xp = 500000;    need_val = 1000; break;
        case 7:  need_xp = 1000000;   need_val = 1250; break;
        case 8:  need_xp = 1500000;   need_val = 5000; break;
   }
   return ({ need_xp,need_val });
}