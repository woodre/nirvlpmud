#define tp this_player()
#define tl tp->query_level()
#define tpn tp->query_real_name()
#define master "/obj/wiz_tool_master.c"
#define to this_object()
#define ep environment(to)
#define eep environment(ep)
#include "/players/maledicta/closed/sigils/vmail.h"
#include "/players/jaraxle/ansi.h"
id(str) { return str == "wiz_tool" || str == "tool" || str == "wiztool"; }

extra_look(){ write(HIR+"   -["+BOLD+""+BLK+"Motivation"+HIR+"]-\n"+NORM); return; }

long() { 
   write("This is a general all-purpose wiztool.\n"+
         "Commands:\n"+
         "wlog <action>#<reason>      writes a log of your actions\n"+
         "rules                       lists wizard rules & guidelines\n"+
         "I <name>                    inventory of name\n"+
         "IR <name>                   inv of room that name is in\n"+
         "hand <name> <path>          hands name object of path\n"+
         "place <name> <path>         moves name to path\n"+
         "church <name>               moves name to church\n"+
         "                            note:no name meansyourself\n"+
         "trans <name>                moves name to you\n"+
         "peace                       forces all combat to stop\n"+
         "money                       gives you 80k coins\n"+
         "heal <name>                 heal someone in the room\n"+
         "                            note: no name is yourself\n"+
         "set_level <name> <#>        sets the level of name\n"+
         "set_extra_level <name> <#>  sets the extra level of name\n"+
         "set_home <name> <path>      sets the home of name to path\n"+
         "add_xp <name> <#>           adds # xp to name\n"+
         "set_stat <name> <what> <#>  sets the stat what of name to #\n"+
         "idest <name> <object>       dests object from name's inv\n");
}

drop(){ write("Tool not dropped.\n"); return 1; }
get() { if(tl > 20) return 1;  else destruct(to); return 1;}

init() {
  if(tl < 21) { destruct(to); return 1; }
  add_action("wizard_log", "wlog");
  add_action("wizard_rules", "rules");
  add_action("inv","I");
  add_action("invr","IR");
  add_action("hand","hand");
  add_action("place","place");
  add_action("idest","idest");
  add_action("church","church");
  add_action("trans","trans");
  add_action("peace","peace");
  add_action("money","money");
  add_action("heal","heal");
  add_action("add_xp","add_xp");
  add_action("set_ex","set_extra_level");
  add_action("set_stat","set_stat");
  add_action("set_level","set_level");
  add_action("set_home","set_home");
  add_action("vmail", "vmail");
  add_action("cmd_INV", "INV");
  add_action("ww", "ww");
  add_action("cmd_st", "jt");
  add_action("cmd_tell", "tell");
  add_action("cmd_emote", "jmote");
  add_action("cmd_say","say");
  add_action("cmd_say"); add_xverb("'"); 
 }

wizard_log(str) { master->wizard_log(str); return 1; }
wizard_rules() { master->wizard_rules(); return 1; }
inv(str) { master->inv(str); return 1; }
invr(str) { master->invr(str); return 1;}
hand(str) { master->hand(str); return 1; }
place(str) { master->place(str); return 1; }
church(str) { master->church(str); return 1; }
trans(str) { master->trans(str); return 1; }
idest(str) { master->idest(str); return 1; }
heal(str) { master->heal(str); return 1; }
set_ex(str) { master->set_ex(str); return 1; }
money() { master->money(); return 1; }
peace() { master->peace(); return 1; }
set_stat(str) { master->set_stat(str); return 1; }
set_level(str) { master->set_level(str); return 1; }
add_xp(str) { master->add_xp(str); return 1; }
set_home(str) { master->set_home(str); return 1; }

ww() {
   object peep,wizzy;
   int x;
   write("\n");
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   write("          Wizards\n");
   write("---------------------------\n");
   for(peep=users(),x=0;x<sizeof(peep);x++) {
      if(peep[x]->query_level() > 19) {
         wizzy += ({peep[x]});
      }
   }
   for(x=1;x<sizeof(wizzy);x++) {
      write(pad(capitalize(wizzy[x]->query_real_name()),15));
      write(pad(wizzy[x]->query_level(),-6));
      write(pad(wizzy[x]->query_invis(),-6)+"\n");
write(GRN+pad((query_idle(wizzy[x])/60), 5)+NORM);
      write(" "+wizzy[x]->query_pwd()+"\n");
   }
write("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   return 1;
}

void full_inventory(object ob,string indent) {  
   object *inv;
   int size,x;
   string sh;
   if(!indent) indent="";
   inv=all_inventory(ob);
   size=sizeof(inv);
   sh=(string)ob->short();
   write(indent+(sh?sh:"INVIS")+"  <"+file_name(ob)+">\n");
   if(!size)
      return;
   else
      for(x=0;x<size;x++)
         full_inventory(inv[x],indent+"    ");
   return;
}
int cmd_INV(string str) {
   object who;
   if(!str) {
      notify_fail("INV who?\n");
      return 0;
   }
   who=find_player(str);
   if(!who) {
      notify_fail("There is no "+str+" online.\n");
      return 0;
   }
   full_inventory(who,"");
   return 1;
}

cmd_tell(str) {
   object plyr;
   int X, CK;
   string myname, who, what;  
   if(!str) { 
      write("Excuse me?\n"); 
      return 1; 
   }
   /* attempt to type fewer letters */
   
   if(sscanf(str,"%s %s",who,what) < 2) 
      {
      write("Tell <who> <what>.\n"); 
      return 1; 
   }
   plyr = find_living(who);
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) { write(capitalize(who)+" is not on now.\n");
      return 1; 
   }
   X = random(14);
   if(X == 0){ CK = HIR; }
   if(X == 1){ CK = HIG; }
   if(X == 2){ CK = HIM; }
   if(X == 3){ CK = HIB; }
   if(X == 4){ CK = HIC; }
   if(X == 5){ CK = HIY; }
   if(X == 6){ CK = YEL; }
   if(X == 7){ CK = GRN; }
   if(X == 8){ CK = BLU; }
   if(X == 9){ CK = HIW; }
   if(X == 10){ CK = CYN; }
   if(X == 11){ CK = MAG; }
   if(X == 12){ CK = RED; }
   if(X == 13){ CK = BLK; }
   if(this_player()->query_invis()){
      tell_object(plyr,HIW+"<"+BLK+BOLD+"invis"+HIW+"> "+HIC+"Jaraxle tells you"+CK+": "+NORM+what+"\n");
      write(HIW+"<"+BLK+BOLD+"invis"+HIW+"> "+HIC+"You tell "+capitalize(who)+CK+": "+NORM+what+"\n");
      plyr->add_tellhistory(HIC + "Jaraxle told you"+CK+":"+NORM+" " + what + NORM + " ["+HIB+"invis tell"+NORM+"]\n");
      plyr->Replyer("jaraxle");
      return 1; }
   tell_object(plyr,HIC+"Jaraxle tells you"+CK+" : "+NORM+what+"\n");
   write(HIC+"You tell "+capitalize(who)+CK+": "+NORM+what+"\n");
      plyr->add_tellhistory(HIC + "Jaraxle told you"+CK+":"+NORM+" " + what + NORM + " ["+HIB+"tell"+NORM+"]\n");
   plyr->Replyer("jaraxle");
   return 1;
}

cmd_say(str) {
   int X, CK, JK, Z;
   X = random(6);
   Z = random(6);
   if(X == 0){ CK = HIR; }
   if(X == 1){ CK = HIG; }
   if(X == 2){ CK = HIM; }
   if(X == 3){ CK = HIB; }
   if(X == 4){ CK = HIC; }
   if(X == 5){ CK = HIY; }
   if(Z <= 3){ Z = BLINK; }
   if(Z == 4){ Z = NORM; }
   if(Z == 5){ Z = NORM; }
   if(!str) {
      notify_fail("Excuse me?\n");
      return 0; 
   }
   write("You say"+Z+CK+": "+NORM+str+"\n");
   say(this_player()->query_name()+" says"+Z+CK+":"+NORM+" "+NORM+str+"\n");
   return 1; 
}

cmd_emote(str) {
   object plyr;
   int X, CK;
   string myname, who, what;  
   if(!str) { 
      write("Excuse me?\n"); 
      return 1; 
   }
   /* attempt to type fewer letters */
   
   if(sscanf(str,"%s %s",who,what) < 2) 
      {
      write("Jmote <who> <what>.\n"); 
      return 1; 
   }
   plyr = find_living(who);
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) { write(capitalize(who)+" is not on now.\n");
      return 1; 
   }
   if(this_player()->query_invis()){
      tell_object(plyr,HIW+"<"+BLK+BOLD+"invis"+HIW+"> "+HIC+"Jaraxle "+what+NORM+" ("+HIB+"emote"+NORM+")\n"+NORM);
      write(HIW+"<"+BLK+BOLD+"invis"+HIW+"> "+HIC+"Jaraxle "+what+NORM+" ["+HIB+capitalize(who)+NORM+"]\n");
      plyr->add_tellhistory(HIC + "Jaraxle " + what +NORM + " ["+HIB+"invis emote"+NORM+"]\n");
      plyr->Replyer("jaraxle");
      return 1; }
   tell_object(plyr,HIC+"Jaraxle "+what+NORM+" ("+HIB+"emote"+NORM+")\n");
   write(HIC+"Jaraxle "+what+NORM+" ["+HIB+capitalize(who)+NORM+"]\n");
   plyr->add_tellhistory(HIC + "Jaraxle " + what +NORM + " ["+HIB+"emote"+NORM+"]\n");
   plyr->Replyer("jaraxle");
   return 1;
}


short() { 
object ob;
ob = this_player();
if (ob && ob !=environment() && (int)ob->query_level() > 19) {
tell_object(environment(),capitalize((string)ob->query_real_name())+" just scanned you.\n"); }
return; }
