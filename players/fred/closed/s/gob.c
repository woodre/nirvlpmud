#include "/players/fred/mages/defs.h"

int block;


id(str) {
 object flip, flop;
   flip = environment(this_object());
     if(flip) 
     flop = environment(flip);
       if(flop) {
         if(present("blood",flop)) 
            return str == "saiyan_blood" || str == "SAIYANBLOOD" || str == "guild_object"; 
         }
     return str == "saiyan_blood" || str == "SAIYANBLOOD" || str == "blood" || str == "guild_object";
   }

init()
{
    if(!ENV()) return;
      if(TP->query_level() > 19 && TPRN != "fred" && TPRN != "catacomb"){
         tell_object(this_player(),
           "You can not clone this object!!!!  Talk to Fred or Catacomb if you're interested. Thanks!\n");
           write_file("/players/fred/closed/s/log/CLONED",
             capitalize(TPRN)+" tried to clone the saiyan object on " + ctime()[4..15] + "\n");
         destruct(this_object());
      return 1;
    }

    add_action("talk","st");
    add_action("talkem","ste");
    add_action("msave","msave");
    add_action("block_channel", "block");
    add_action("spell_block", "missle",2);
    add_action("spell_block", "shock",2);
    add_action("spell_block", "fireball",2);
    add_action("spell_block", "sonic",2);
    add_action("invis_no", "invisible");
    add_action("wield_no", "Wield");
    add_action("check_baby_check", "study");
    add_action("guild_who", "saiyans");
    add_action("leave_saiyans","leave_saiyans");
    add_action("new_tell","tell");
    add_action("new_say","say");
    add_action("new_say"); add_xverb("'");
    add_action("saiyan","saiyan");
    add_action("semotes","S_emotes");
  }

query_auto_load(){ return "/players/fred/closed/s/gob.c:";}

int drop() { return 1; }

int get() { return 1; }

extra_look() { 
    if(environment() == this_player())
        write("You are of proud saiyan descent. Type "+HIR+"saiyan"+NORM+" for more info.\n");
    else write(environment()->query_name() + " is of "+HIY+"saiyan"+NORM+" descent.\n");
    }


talk(str) {
   string peep;
   object *stuff, blood;
   int x;
  
   if(block) {
     write("You are blocking the Saiyan line.\n");
     return 1;
   }
  if (!str) { write("Say what?\n"); return 1; }
  stuff = users();
  str = format(str,60);
  peep = capitalize((string)TPRN);
     for(x=0; x<sizeof(stuff); x++) {
        blood = present("saiyan_blood",stuff[x]);
        if (blood && !blood->query_block()) {
        tell_object(stuff[x], BOLD+HIR+
        "[]"+HIY+"Saiyan"+HIR+"[] "+NORM+peep+": "+str);  
        }
     }
  return 1;
}

talkem(str) {
   string peep;
   object *stuff, blood;
   int x;
  
   if(block) {
     write("You are blocking the Saiyan line.\n");
     return 1;
   }
   if (!str) { write("Emote what?\n"); return 1; }
   stuff = users();
   str = format(str,60);
   peep = capitalize((string)TPRN);
     for(x=0; x<sizeof(stuff); x++) {
        blood = present("saiyan_blood",stuff[x]);
        if (blood && !blood->query_block()) {
        tell_object(stuff[x], BOLD+HIR+
          "[]"+HIY+"Saiyan"+HIR+"[] "+NORM+peep+" "+str);  	            
        }
     }
  return 1;
}

block_channel(str) {
   block = !block;
   if (block){
     talkem("blocks the Saiyan line");}
   else {
     talkem("rejoins the Saiyan line");
     }
  return 1; 
}
  
query_block() { return block; }

leave_saiyans() {
   write_file("/players/fred/closed/s/log/QUITERS!",
      capitalize(TPRN)+" the ungrateful jerk left the guild on " + ctime()[4..15] + "\n");
   
   talkem("has left the Saiyan ranks");   
   TP->set_guild_file(0);
   TP->set_home(0);
   TP->set_guild_rank(0);
   TP->set_guild_name(0);
   TP->add_guild_exp(-TP->query_guild_exp());
   TP->add_guild_rank(-TP->query_guild_rank());
   write("The price of leaving the guild is death.......\n");
   TP->death();
   /*
   rm("/players/fred/closed/s/members/"+TPRN+".o");
   */
   destruct(this_object());
   return 1;
}

new_tell(str) {
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
  BOLD+BLK+"[]"+HIY+capitalize(TPRN)+BLK+"[]"+NORM+": "+what+"\n");
  write(BOLD+HIY+"You tell "+capitalize(str)+": "+BLK+what+NORM+"\n");
  who->add_tellhistory(capitalize(this_player()->query_name())+" tells you: "+what+"");
  return 1; }

new_say(str){
  if(!str) { write("Say what?");
  return 1; }
  write(BOLD+HIY+"You say: "+BLK+str+NORM+"\n");
  say(BOLD+HIY+capitalize(TPRN)+" says: "+BLK+str+NORM+"\n");
  return 1; }

spell_block(){
  write("Saiyans are not allowed to use petty game spells.\n");
  return 1; }

invis_no(){
  write("A true saiyan doen't ambush or hide from "+environment()->query_possessive()+" enemies.\n"+
        "Saiyans fight with Pride!\n");
  return 1; }

wield_no(){
  write("Saiyans rely on hand-to-hand combat and have no need for normal weapons.\n");
  return 1; }

msave(object ob){
 if(!ob) ob = environment();
 save_object(SAVE_PATH+ob->query_real_name());
  tell_object(ob,
   BOLD+BLK+"Saving Dark Circle...\n"+NORM);
  return 1;
 }

   
