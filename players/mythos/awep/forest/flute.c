/*********************************
*
*   approved by saber
*
*********************************/
#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
inherit "obj/weapon.c";
string str;
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("flute");
  set_alias("flute");
  set_short("Wooden Flute");
  set_long("The flute is made of hard wood... you may play it or attack with it.\n"+
    "It seems very special.  There seems to be some odd scratches on it.\n");
  set_read("The wooden flute that Yoshitsune used on Benkei.\n"+
           "It is a flute that you may <play> music on.\n"+
           "To get a list of music pieces type <flute_list>.\n");
  set_class(12);
  set_weight(1);
  set_value(2000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(20);
if(W>16)  {
  say(tp+" swings the flute.\n\n"+
    HIG+"\tS L A P"+NORM+"\n\n"+"That seems to hurt!\n");
  write("You swing the flute and connect!\n\n"+
    HIG+"\tS L A P"+NORM+"\n\n"+"That seemes to hurt!\n");
return 6;

   }
   return;
}

init() {
  ::init();
  add_action("play","play");
  add_action("flute_list","flute_list");
  }
  
flute_list() {
write(U+"\nName of Piece              Effect                      Arg       \n\n"+
            NORM+
 	       "Salute            Officer salute <peace>          <all> or <name>\n"+
	       "Leading           Makes another follow you                 <name>\n"+
	       "Music             Plays entrancing music          <all> or <name>\n");
return 1;}
	
play(str) {
  string music, who;
  object ob;
  
  if(!str) {
    write("To use play <music piece> <arg>\n"); 
    return 1;
  }
  sscanf(str,"%s %s",music,who);
  
  if(music=="salute") {
    
    if(this_player()->query_hp() < 40 || this_player()->query_sp() < 35) {
      write("You do not have enough power to play the salute.\n");
      return 1; 
    }
  
    if(who=="all") {
      ob=first_inventory(environment(this_player()));
      while(ob) {
        
        if(living(ob)) {
          
          if(ob->query_attack()) { 
            (ob->query_attack())->stop_fight();
            ob->stop_fight(); 
          }
        }
        
        ob=next_inventory(ob);
      }
      
      write("You play the musical piece of command and all stop to salute you\n");
      say("All stop fighting to salute "+capitalize(tp)+"\n");
      /*this_player()->heal_self(-30-random(30));*/
      this_player()->hit_player(30, "other|mythos");
      return 1;
    }
    else {
      if(!present(who, environment(this_player()))) {
        write("Not here to command.\n");  
        return 1;
      }
      ob = present(who,environment(this_player()));
      if(ob->query_attack()) {
        (ob->query_attack())->stop_fight();
        ob->stop_fight(); 
        (ob->query_attack())->stop_fight();
        ob->stop_fight();
        write(capitalize(who)+" stands at attention and salutes you.\n");
        say(capitalize(who)+" stands at attention and salutes "+capitalize(tp)+"\n");
        this_player()->heal_self(-40-random(30));
      }
      else {
        write(capitalize(who)+" is not in battle!\n");
      }
      return 1;
    } 
    return 1;
  }
   if(music=="leading") {
   if(present(who, environment(this_player()))) {
     if(!find_player(who)) { write("That player s not in the game!\n"); return 1;}
     if(find_player(who)->query_invis()) { write("That player s not in the game!\n"); return 1;}
     if(find_player(who)->query_attack()) {
       write("That player is in combat. The music falters.\n");
     return 1; }
     ob=clone_object("/players/mythos/amisc/forest/ask.c");
     ob->set_asker(this_player()->query_real_name());
     move_object(ob,find_player(who));
     return 1;}
     write("Who do you wish to ask to follow?\n");
   return 1;}
   if(music=="music") {
   if(who=="all") {
     write("You play a soft and entrancing tune for all.\n");
     say(capitalize(tp)+" plays a soft and entrancing tune for all.\n");
     ob=first_inventory(environment(this_player()));
  while(ob) {
  if(living(ob)) {
     tell_object(ob,"You feel moved as "+capitalize(tp)+
     " plays a soft tune on a flute.\n");
    tell_room(environment(this_player()),(ob->query_name())+" stands entranced.\n");
   }
  ob=next_inventory(ob);
   }
   return 1;}
   else {
   if(present(who,environment(this_player()))) {
     write("You play a soft and entrancing tune for "+capitalize(who)+".\n");
     say( capitalize(tp)+" plays a soft and entrancing tune for "+capitalize(who)+".\n");
     tell_object(find_player(who),"You feel moved as "+capitalize(tp)+
         " plays a soft tune on a flute.\n");
     tell_room(environment(this_player()),capitalize(who)+" stands entranced.\n");
   return 1;}
return 1;}
return 1;}
return 1;}


query_save_flag() {return 1;}
