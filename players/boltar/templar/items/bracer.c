#include "/players/maledicta/ansi.h"
#define ALLY "players/boltar/templar/daemon/Ally.c"
#define CRIM "/players/boltar/templar/daemon/Criminal.c"
#define LOG "/players/boltar/templar/log/Ally"
#define TP this_player()
#define USER environment()
query_weight(){ return 0; }
query_value(){ return 0; }
drop(){ return 1; }
get(){ return 1; }
int bard;
int block;
int ref_flag;

object jj;
static object owner;
string *has_read;
id(str){
	if(bard){
   return str == "KnightInvite" || str == "coat" || str == "coat of arms" ||
   str == "alliancebracer";
	}
	else{
	return str == "KnightInvite" || str == "bracer" || str == "silver bracer" ||
   str == "alliancebracer";
	}
}

query_auto_load(){ return "/players/boltar/templar/items/bracer.c:"; }


short(){
if(bard){
   return HIW+"Coat of Arms"+NORM+" (worn)";
	}
   return "a Silver Bracer "+BOLD+"["+NORM+GRN+"Templar"+NORM+BOLD+"]"+NORM+" (worn)";
}

long(){
	if(bard){
   write(
      "This is a Coat of Arms that hangs around your shoulder and neck\n"+
	  "on a chain, and fits over your heart.  It is engraved with the\n"+
	  "symbol of the Knights Templar and the Bards across its shining\n"+
	  "surface. It is a symbol of the bond you have made with them to\n"+
	  "preserve good in the realm and assist and be assisted in your\n"+
	  "everyday trials. For more information on the powers it holds,\n"+
      "type: "+BOLD+"ally_info"+NORM+"\n");
   return 1;
	}
	else{
	write(
      "This is a lightweight silver bracer that fits easily over your\n"+
      "arm.  It is engraved with the symbol of the Knights Templar\n"+
      "across its shining surface. It is a symbol of the bond you have\n"+
      "made with them to preserve good in the realm and assist and be\n"+
      "assisted in your everyday trials. For more information on the\n"+
      "powers it holds, type: "+HIY+"bracer_info"+NORM+"\n");
   return 1;
	}
}

init(){
   if(!environment()) return;
   if(previous_object() && previous_object()->id("ambassador")) ALLY->Insert(environment()->query_real_name());
   if(!ALLY->Query(environment(this_object())->query_real_name()) && 
         environment(this_object())->query_level() < 20){
      tell_object(environment(),
         "You are no longer part of the Knights Alliance. If this\n"+
         "is a mistake, please notify a Knight.\n");
      destruct(this_object());
   }
  /* for some reason some shardak are refusing to leave the alliance -bog!  <ill> */
  if(environment())
  if(environment()->query_level() < 20 && environment()->query_guild_name()=="shardak") {
    write("\n\n\nThose allied with evil may not be a part of the alliance!\n\n\n");
   destruct(this_object());
   return;
  }
   add_action("ally_who", "awho");
   add_action("criminal_who", "cwho");
   add_action("criminal", "criminal");
   add_action("ally_line", "att");
   add_action("ally_emote", "ate");
   add_action("ally_block", "ablock");
   add_action("ally_help", "ahelp");
   add_action("ally_list", "alist");
   add_action("leave_alliance", "break_alliance");
   add_action("bracer_info", "bracer_info");
   add_action("bracer_info", "ally_info");
    add_action("bracer_refresh","al_refresh");
   if(this_player()->query_level() < 20 && !this_player()->is_npc())
      ally_emote("enters the game.\n");
   if(this_player()->query_guild_name() == "bard"){
	   bard = 1;
   }
}


ally_block(){
   if(!block){
      write("You block the alliance channel.\n");
      block = 1;
   }
   else{
      write("You turn the alliance channel on.\n");
      block = 0;
   }
   return 1;
}

query_block(){ return block; }


ally_emote(str) {
   object list;
   object cross;
   int i;
   string myname;
   if(block) {
      write("You are blocking the Templar Channel.\n");
      return 1;
   }
   if (!str) { write("Use: ate <what>\n"); return 1; }
   list = users();
   if(str == "block") {
      for(i=0;i<sizeof(list);i++) {
         cross = present("KnightInvite",list[i]);
         if(cross && cross->query_block()) {
            write(list[i]->query_name()+" is blocking the Templar channel.\n");
          }
      }
      return 1;
   }
   /* $ color by verte */
   str = "/players/vertebraker/closed/std/color"->filter_msg(str);
   /* $ end color by verte */
   myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightInvite",list[i]);
      if (cross && !cross->query_block()) {
         tell_object(list[i], 
            BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+" "+str+"\n");
       }
   }
   /* added by verte */
   "/obj/user/chistory"->add_history("Knight Alliance",
     BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+this_player()->query_name()+" "+str+"\n");
   return 1;
}




ally_line(str) {
   object list;
   object cross;
   int i;
   string myname;
   string history;
   if(block) {
      write("You are blocking the Templar Channel.\n");
      return 1;
   }
   if (!str) { write("Use: att <what>\n"); return 1; }
   list = users();
   if(str == "block") {
      for(i=0;i<sizeof(list);i++) {
         cross = present("KnightInvite",list[i]);
         if(cross && cross->query_block()) {
            write(list[i]->query_name()+" is blocking the Templar channel.\n");
          }
      }
      return 1;
   }
   if(str == "history" || str == "-h")
      {
      history = "/obj/user/chistory"->query_history("Knight Alliance");
      write(history+"\n");
      return 1;
   }
   /* $ color by verte */
   str = "/players/vertebraker/closed/std/color"->filter_msg(str);
   /* $ end color by verte */
/*
str += "\n";
*/
   myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightInvite",list[i]);
      if (cross && !cross->query_block()) {
		  if(bard){
         tell_object(list[i], 
            BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+" sings: "+str+"\n");
		  }
		  else{
		 tell_object(list[i], 
            BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+": "+str+"\n");
		  }
       }
   }
   /* added by verte */
   "/obj/user/chistory"->add_history("Knight Alliance",
     BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+this_player()->query_name()+": "+str+"\n");
   return 1;
}

ally_help() {
   object list;
   object cross;
   int i;
   string myname;
   if(block) {
      write("You are blocking the Templar Channel.\n");
      return 1;
   }
   list = users();
   
   myname=TP->query_name();
   for(i=0; i<sizeof(list); i++) {
      cross = present("KnightInvite",list[i]);
      if (cross && !cross->query_block()) {
         tell_object(list[i], 
            BOLD+"-=["+NORM+GRN+"Alliance"+NORM+BOLD+"]=- "+NORM+myname+" calls for assistance!\n"+
            "               Location: "+environment(this_player())->short()+"\n");
         if(this_player()->query_attack()){
            tell_object(list[i],
               "               Fighting: "+this_player()->query_attack()->query_name()+"\n");
          }
         
       } 
   }
   
   return 1;
}





bracer_info(){
	if(bard){
   write(
      "*************************************************************\n"+
      "*         [Welcome to the Bard-Templar Alliance]            *\n"+
      "* As a member you may do any of the following:              *\n"+
      "*                                                           *\n"+
      "* awho.............A listing of all allies currently on.    *\n"+
      "* cwho.............A listing of all criminals currently on. *\n"+
      "* criminal <who> ..Shows why someone is a criminal.         *\n"+
      "*                  Will only work if they are online        *\n"+
      "* att..............The alliance channel. No profanity       *\n"+
      "*                  please.                                  *\n"+
      "* ate..............An emote on the alliance channel.        *\n"+
      "* ahelp............A call for help over the alliance        *\n"+
      "*                  channel that states your position and    *\n"+
      "*                  what you are currently fighting.         *\n"+
      "* alist............A full listing of all allies.            *\n"+
      "* al_refresh.......Refresh your alliance object.            *\n"+
      "* break_alliance...This is the command to leave the         *\n"+
      "*                  alliance.                                *\n"+
      "*************************************************************\n");
   return 1;
}
	else{
write(
      "*************************************************************\n"+
      "*         [Welcome to the Templar Alliance]                 *\n"+
      "* As a member you may do any of the following:              *\n"+
      "*                                                           *\n"+
      "* awho.............A listing of all allies currently on.    *\n"+
      "* cwho.............A listing of all criminals currently on. *\n"+
      "* criminal <who> ..Shows why someone is a criminal.         *\n"+
      "*                  Will only work if they are online        *\n"+
      "* att..............The alliance channel. No profanity       *\n"+
      "*                  please.                                  *\n"+
      "* ate..............An emote on the alliance channel.        *\n"+
      "* ahelp............A call for help over the alliance        *\n"+
      "*                  channel that states your position and    *\n"+
      "*                  what you are currently fighting.         *\n"+
      "* alist............A full listing of all allies.            *\n"+
      "* al_refresh.......Refresh your alliance object.            *\n"+
      "* break_alliance...This is the command to leave the         *\n"+
      "*                  alliance.                                *\n"+
      "*************************************************************\n");
   return 1;
	}
	return 1;
}
leave_alliance(){
   write("You decide to leave the Knights alliance.\n");
   ALLY->Delete(this_player()->query_real_name());
   destruct(this_object());
   return 1;
}


ally_list() {
  tail("/players/boltar/templar/daemon/ally_record");
   return 1;
}


criminal_who() {
   int i, z, crim;
   object *list;
   
   list = users();
   write(GRN);
   write(pad("",40,'~')+"\n");
   write("@"+NORM+BOLD+"  Name:\tLevel:\tGuild:         "+NORM+GRN+"@\n");
   
   
   write(NORM+GRN);
   write("@"+pad("",38,'~')+"@\n");
   write("@"+pad("",38)+"@\n");
   write(NORM);
   for(i = 0, z = 0; i < sizeof(list); i++) {
      
      crim = CRIM->Query(list[i]->query_real_name());
      if(!environment(list[i]) || list[i]->query_level() > 19 || ALLY->Query(list[i]->query_real_name())) continue;
      if(crim || (list[i]->query_level() > 8 && list[i]->query_alignment() < -40)) {
         
         if(crim)
            if(list[i]->query_attack())
            write(GRN+"@ "+BOLD+RED+"*"+pad(list[i]->query_name(),14)+NORM);
         else
            write(GRN+"@  "+BOLD+RED+pad(list[i]->query_name(),14)+NORM);
         else 
            if(list[i]->query_attack())
            write(GRN+"@ "+NORM+HIR+"*"+NORM+pad(list[i]->query_name(),14));
         else
            write(GRN+"@  "+NORM+pad(list[i]->query_name(),14));
         z++;
         
         if (list[i]->query_pl_k())
            write(list[i]->query_level() + "*\t");
         else
            write(list[i]->query_level() + "\t");
         
         if (!list[i]->query_guild_name())
            write(pad("None",15));
         else
            write(pad(capitalize(list[i]->query_guild_name()),15));
         write(GRN+"@\n");
       }
   }
   if(!z) write(GRN+"@  "+NORM+pad("No Criminals logged in.",36)+NORM+GRN+"@\n");
   write(GRN);
   write("@"+pad("",38)+"@\n");
   write(pad("",40,'@')+"\n");
   write(NORM);
   write(HIR+"Red"+NORM+": criminals  White: Evil players\n");
   return 1;
}



ally_who() {
   int i, z, ally;
   object *list;
   
   list = users();
   write(HIB);
   write(pad("",41,'~')+"\n");
   write("@"+NORM+BOLD+"  Name:\tLevel:\tGuild:         "+NORM+HIB+" @\n");
   write(NORM+HIB);
   write("@"+pad("",39,'~')+"@\n");
   write("@"+pad("",39)+"@\n");
   write(NORM);
   for(i = 0, z = 0; i < sizeof(list); i++) {
      
      ally = ALLY->Query(list[i]->query_real_name());
      if(!environment(list[i]) || list[i]->query_level() > 19) continue;
      if(ally || list[i]->query_guild_name() == "Knights Templar"){
         write(HIB+"@  "+HIW+pad(list[i]->query_name(),14)+NORM);
         z++;
         
         if (list[i]->query_pl_k())
            write(list[i]->query_level() + "*\t");
         else
            write(list[i]->query_level() + "\t");
         
         if (!list[i]->query_guild_name())
            write(pad("None",16));
         else if(list[i]->query_guild_name() == "Knights Templar")
            write(HIR+pad(capitalize(list[i]->query_guild_name()), 16));
         else if(list[i]->query_guild_name() == "bard")
            write(HIY+pad(capitalize(list[i]->query_guild_name()), 16));

		 else
            write(pad(capitalize(list[i]->query_guild_name()),16));
         write(NORM+HIB+"@\n");
       }
   }
   if(!z) write(HIB+"@  "+NORM+pad("No Allies logged in.",37)+NORM+HIB+"@\n");
   write(HIB);
   write("@"+pad("",39)+"@\n");
   write(pad("",41,'@')+"\n");
   write(NORM);
   return 1;
}

criminal(string str) {
  if(!str) return 0;
  if(CRIM->Query(str)) write(CRIM->DetailedQuery(str));
  else write(capitalize(str)+" is not a criminal.\n");
  return 1;
}

add_has_read(hr) {
   if(!has_read) has_read = ({ });
   has_read += ({ hr });
}

remove_has_read(hr) {
   if(!has_read) has_read = ({ });
has_read -= ({hr });
}

query_has_read() { return has_read; }

bracer_refresh(arg){
owner = TP;
if(!arg || arg != 786) {
  ref_flag= 1;
  jj=clone_object("/players/boltar/templar/items/bracer.c");
  move_object(jj,environment(this_object()));
  jj->refresh(786);
  destruct(this_object());
  return 1;
  }
if(arg == 786) ref_flag = 0;
   owner = TP;
   write("Ok.\n");
   return 1;
}
