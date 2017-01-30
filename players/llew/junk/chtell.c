#include "/players/llew/closed/ansi.h"
inherit "obj/treasure";

reset(arg) {
   if(arg)return;
   set_id("tell");
   set_alias("teller");
set_short("A Chaos Tell");
   set_long("A spell burning its influence into your thoughts.\n"+
            "Be careful as to what you say as strange things may occur.\n"+
            "Use chtell <player> <what>\n"+
            "Or chtelle <player> <what>\n");
   set_value(0);
   set_weight(0);
}

drop() { return 1; }

init() {
   ::init();
   add_action("chtell","chtell");
   add_action("chtell","chtelle");
}

chtell(str){
   string who,what,chwhat;
   string *words, *colors;
   int n;
   chwhat = "";
   colors = ({ RED,HIR,BLU,HIB,CYN,HIC,YEL,HIY,WHT,HIW,GRN,HIG,MAG,HIM });
   colors = ({ NORM+RED,HIR,NORM+BLU,HIB,NORM+GRN,HIG,NORM+YEL,HIY,NORM+CYN,HIC,NORM+MAG,HIM,NORM+WHT,HIW });
   if(this_player()->query_spell_point() < 5) {write("You need more spell points...\n"); return 1; }
   if(!str) return 0;
   if(sscanf(str,"%s %s",who,what) != 2) return 0;
   if(!find_player(who)) {write(capitalize(who)+" is not here...\n"); return 1;}
   if(random(100)==99) who = ((object)users())[random(sizeof(users()))]->query_real_name();
   if(find_player(who)->query_level() > 19 && find_player(who)->query_invis() > 0) {
      write(capitalize(who)+" is not here...\n"); return 1;}
   if(find_player(who)->query_level() > 19) { write("You shouldn't bother wizards.\n"); return 1;}
   if(in_editor(find_player(who))) { write(capitalize(who)+" is in edit right now.\n"); return 1;}
   if(find_player(who)->query_tellblock()) {
      write(capitalize(who)+" is currently blocking tells.  Please try again later.\n");
      return 1;
   }
   if(interactive(find_player(who))) {
      words = explode(what," ");
      for(n=0;n < sizeof(words);++n) {
         chwhat += colors[random(14)]+words[n]+" ";
         if(random(100) > 95) --n;
      }
      chwhat=chwhat+NORM;
      write("You "+query_verb()+" "+capitalize(who)+": "+chwhat+"\n");
      if(query_verb() == "chtell") chwhat="tells you: "+chwhat;
      else chwhat=chwhat+"  "+"("+RED+"C"+BOLD+"h"+HIW+"a"+RED+"o"+NORM+RED+"s"+NORM+")";
      tell_object(find_player(who),this_player()->query_name()+" "+chwhat+"\n");
      this_player()->add_spell_points(-5);
   }
else write(capitalize(who)+" is disconnected.\n");
   return 1;
}

