#include "/players/data/ansi.h"
#define Larn present("larn_obj", this_player())
#define Gothic present("gothic_obj", this_player())
#define Feline present("feline_obj", this_player())
#define Blade present("blade_obj", this_player())
#define Succubus present("succubus_obj", this_player())
#define Gypsy present("gypsy_obj", this_player())
#define Kender present("kender_obj", this_player())
#define TP this_player()
#define USER this_player()
inherit "players/vertebraker/closed/std/monster.c";

int nojoin;

reset(arg)  {
object anhk;
  ::reset(arg);
  if(arg) return;

set_name("master");
set_alias("student_master");
set_race("elf");
set_short(HIW+"The Master of the Tower"+NORM);
set_long(
"  Sitting before you is the Master of the Tower. He is\n"+
"dressed in simple robes with golden bracers on each\n"+
"forearm. Long brown hair flows down over his shoulders\n"+
"with small pointy ears jutting out from behind locks\n"+
"that run in front of his ears.  All you need do is\n"+
"'parlay' with him.\n");
set_level(20);
set_aggressive(0);
nojoin = 1;
}  

init(){
 ::init();
 add_action("parlay", "parlay");
 add_action("join", "join");
 add_action("no_join", "jblock");
 }

no_join(){
 if(this_player()->query_level() < 100) return 0;
 if(nojoin) nojoin = 0;
 else nojoin = 1;
 return 1;
 }

parlay(){
if(present("prof_guild_object", this_player())){
  write("The master says, 'Sorry, but I do not have time to talk.'\n");
  return 1;
  }
write(
"The Master stands and faces you...\n"+
"He then says,\"You have come here to join the Warriors?  If so, then\n"+
"please know that it will cost 50,000 coins for tuition, and consume\n"+
"your life. The opportunities though are well worth the challenge that\n"+
"is presented.  If you truly wish to become a Warrior, then first make\n"+
"sure you have read the library and know what it is you are getting\n"+
"into.  If you decide that is what you want, then simply come back here\n"+
"and 'join warriors'.\"\n"+
"The Master of the Tower then sits and returns to writing something.\n");
return 1;
} 

join(str){
int minexp;
if(!str){ write("Join what?\n"); return 1; }
if(str == "warriors"){
if(present("prof_guild_object", this_player())){
  write("The Master looks at you and chuckles.\n");
  return 1;
  }
if(this_player()->query_level() < 5){
  write("The Master says,'You are too low of a level. "+HIR+"READ"+NORM+" next time.'\n");
  return 1;
  }
if(this_player()->query_money() < 50000){
  write("The Master says,'You cannot afford tuition.'\n");
  return 1;
  }
if(this_player()->query_guild_name() && TP->query_guild_name() != 0){
  write("You are in a guild.\n"); 
  return 1; 
  }
if(this_player()->query_guild_rank()){ 
  write("You are in a guild.\n"); 
  return 1; 
  }
if(this_player()->query_guild_exp()){ 
  write("You are in a guild.\n"); 
  return 1; 
  } 

     if(Larn){
        destruct(Larn);
         }
     if(Gothic){
            destruct(Gothic);
     }
     if(Feline){        
        destruct(Feline);
     }
     if(Blade){
        destruct(Blade);
     }
     if(Succubus){
        destruct(Succubus);
     }
     if(Gypsy){
        destruct(Gypsy);
     }
     if(Kender){
        destruct(Kender);
     }  
     tell_object(environment(),"Mini-guilds destroyed...\n");
     move_object(clone_object("/players/data/closed/wizard/gobj"), this_player());
     command("psave", this_player());
     this_player()->add_money(-50000);
     TP->save_me();
     TP->reset();
write("The Master of the Tower smiles and welcomes you in.\n");
return 1;
}
write("Join what?\n");
return 1;
}
