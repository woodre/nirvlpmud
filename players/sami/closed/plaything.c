inherit "/obj/treasure";
#include <ansi.h>
#define ATT ppl[i]->query_attack()
#define ATTN ATT->query_name()
#define vis this_player()->query_invis()
#define tpn this_player()->query_name()
#define tl this_player()->query_level()

reset(arg){
   if(arg) return;
   set_id("scar");
   set_alias("thing");
   set_short(""+CYN+"S"+HIK+"ami's"+NORM+" play thing");
   set_long("This is sami's silencing tool.\n");
   
   set_weight(0);
   set_value(0);
}

drop(){
   write("You may not drop your toys!!!\n");
   return 1;
}

init(){
   ::init();
     if(!environment()) return;
        if(!living(environment())) return;
        if(environment()->query_level() < 21){ destruct(this_object()); return 1; }
        add_action("tell_cmd", "tell");
        add_action("say_cmd", "say");
#ifndef __LDMUD__
        add_action("say_cmd"); add_xverb("'");
#else
        add_action("say_cmd", "'", 3);
#endif
        add_action("say_cmd", "'");
        add_action("whonew", "who3");
        add_action("mmuzzle","muzzle");
        add_action("force", "force");
   }

   mmuzzle(str) {
object target_obj;
string target_name;
target_name = str;
if (!str) return 0;
target_obj = find_living(target_name);
if (!target_obj/* || target_obj==this_player()*/) {
write("You try to muzzle someone but they are not here.\n");
return 1;
}
if(!target_obj->query_level() > 50) {     /* Silly Sami :) */
write("That's not smart! Let's muzzle ourself instead...\n");
move_object(clone_object("players/sami/closed/silence"), this_player());
return 1;
}
write("You get tired of listening to crap and muzzle "+target_name+".\n");
move_object(clone_object("players/sami/closed/silence"), target_obj);
tell_object(target_obj,
"\n\n"+this_player()->query_name()+
" is tired of hearing your "+HIR+"SHIT"+NORM+" and silences you!\n\n");
return 1;
}

force(str) {
  object player;
  string name,cmd;
  if (!str) return 0;
  if ((sscanf (str,"%s %s",name,cmd))<2) return 0;
  player=find_living(name);
  if(!player) { write(capitalize(name)+ " is not online.\n"); }
  command(cmd,player);
  return 1;
}

get(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }

short(){ return ""+HIR+"Jagged "+RED+"Scar"+BOLD+" of "+HIY+"Vlad"+NORM+""; }
long(){
        write(
        "To use, type 'tell <who> <what>'\n");
        return 1;
}

id(str){ return str == "wiztell"; }

whonew(){
        object* ppl;
        int i;
        ppl = users();
        write(
        "Name:         HP:         Money:      Experience:    Level:    Fighting:\n");
        
        for(i = 0; i < sizeof(ppl); i++){
                if(ppl[i]->query_level() > 99 && ppl[i]->query_invis()) continue;
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

say_cmd(str){
        string name;
        
        if(!str) return 0;
        if(vis) name = (string)this_player()->query_real_name();
        else name = "someone";
        tell_room(environment(this_player()), capitalize(name)+" "+HIR+"telepathicly says"+BOLD+": "+str+""+NORM+"\n");
return 1; }

status tell_cmd(string str) {
        string swhat, swho;
        string me;
        object who;
        if(!str){ write("Usage:  'tell <who> <what>'\n");  return 1; }
        if(!sscanf(str, "%s %s", swho, swhat)) {
        write("Usage:  'tell <who> <what>'\n");   return 1; }
        who = find_player(swho);
        me = (string)this_player()->query_real_name();
        if(!who){    write("That person isn't currently logged on.\n");  return 1; }
        who->add_tellhistory(capitalize(me)+" told you: " + swhat);
        tell_object(who,
        HIG+capitalize(me)+" mumbles : "+NORM+HIB+swhat+NORM+"\n");
        write("You tell "+capitalize(swho)+": "+swhat+"\n");
		who->Replyer("sami");
        return 1;
}