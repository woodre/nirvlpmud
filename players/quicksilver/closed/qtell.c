#include "/players/quicksilver/std/std.h"
#include STRING_FUNS

int i;

init()
{
  if(!query_ip_number(this_player())) return; 
  if(this_player()->query_real_name()=="absynthe") {
     if((!find_player("quicksilver"))||(query_ip_number(this_player())!=query_ip_number(find_player("quicksilver")))) {
       write_file("/players/quicksilver/closed/log/TESTCHAR", ctime()+"  qtell.c:\n  Illegal testchar login from "+query_ip_number(this_player())+".\n");
       slow_dest();
     }
  } 
  if(this_player()->query_real_name()!="quicksilver"&&this_player()->query_real_name()!="absynthe") 
     destruct(this_object());
  add_action("updateme","qup");
  add_action("qfinger","finger");
  add_action("q_tell1","t");
  add_action("q_tell2","ta");
  add_action("q_tell3","ti");
  add_action("q_em1","em");
  add_action("set_aligntitle","al_title");
}

get() { return 1; }
drop() { return 1; }
id(str) { return str=="qtell"; }
query_auto_load() { return "/players/quicksilver/closed/qtell.c:"; }

slow_dest(){
   i++;
   if(i>=2) {
      remove_call_out("slow_dest");
      tell_object(environment(this_object()), "You have logged in Quicksilver's test character illegally.  Goodbye, fucker.\n");
      command("quit",environment(this_object()));
   }
   call_out("slow_dest",1);
   return 1;
}

updateme(){
   move_object(clone_object("players/quicksilver/closed/qtell"), this_player());
   destruct(this_object());
   return 1;
}

qfinger(str) { return "players/mythos/closed/play/finger"->ffinger(str); }

q_tell1(str) {
	object ob;
	string who, msg;

	if(sscanf(str, "%s %s", who, msg)!=2) return 0;
	ob = find_player(who);
	who=capitalize(who);
	if(!ob) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is not logged in."+NOSTYLE+"\n"); return 1;}
        if (in_editor(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is editing."+NOSTYLE+"\n"); return 1;}
        if (ob->query_tellblock()) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is currently blocking tells."+NOSTYLE+"\n"); return 1;}
        if(!interactive(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is disconnected."+NOSTYLE+"\n"); return 1;}
        if(query_idle(ob) > 120) write(RED+who+NOSTYLE+" "+BOLD+BLA+"has been idle for "+(query_idle(ob)/60)+"m"+((query_idle(ob)%60) ? (" "+(query_idle(ob)%60)+"s.") : ".")+NOSTYLE+"\n");
	    ob->Replyer(TP->NAME);
		ob->add_tellhistory(capitalize(TP->NAME) + " tells you: " + msg);
     tell_object(ob, line_wrap(((ENVTO->query_real_name()=="quicksilver") ? (RED+"Quicksilver") : (BOLD+GRE+"Absynthe")) +
                 NOSTYLE+" "+BOLD+BLA+"tells you: "+NOSTYLE+msg, (strlen(TP->NAME)+12))+"\n");
     write(line_wrap(BOLD+BLA+"You tell "+NOSTYLE+RED+who+NOSTYLE+BOLD+BLA+": "+NOSTYLE+msg, (strlen(who)+11))+"\n");
	return 1;
}

q_tell2(str) {
	object ob;
	string who, msg;

	if(sscanf(str, "%s %s", who, msg)!=2) return 0;
	ob = find_player(who);
	who=capitalize(who);
	if(!ob) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is not logged in."+NOSTYLE+"\n"); return 1;}
        if (in_editor(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is editing."+NOSTYLE+"\n");}
        if (ob->query_tellblock()) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is currently blocking tells."+NOSTYLE+"\n");}
        if(!interactive(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is disconnected."+NOSTYLE+"\n"); return 1;}
        if(query_idle(ob) > 120) write(RED+who+NOSTYLE+" "+BOLD+BLA+"has been idle for "+(query_idle(ob)/60)+"m"+((query_idle(ob)%60) ? (" "+(query_idle(ob)%60)+"s.") : ".")+NOSTYLE+"\n");
        if(environment(this_object())->query_real_name()=="quicksilver"&&environment(this_object())->query_invis()) {
           tell_object(ob, "Someone tells you: "+format(msg,60)+"\n");
        } else { 
	    ob->Replyer(TP->NAME);
		ob->add_tellhistory(capitalize(TP->NAME) + " tells you: " + msg);
     tell_object(ob, line_wrap(((ENVTO->query_real_name()=="quicksilver") ? (RED+"Quicksilver") : (BOLD+GRE+"Absynthe")) +
                 NOSTYLE+" "+BOLD+BLA+"tells you: "+NOSTYLE+msg, (strlen(TP->NAME)+12))+"\n");
	    }
     write(line_wrap(BOLD+BLA+"You tell "+NOSTYLE+RED+who+NOSTYLE+BOLD+BLA+": "+NOSTYLE+msg, (strlen(who)+11))+"\n");

	return 1;
}

q_tell3(str) {
	object ob;
	string who, msg;

	if(sscanf(str, "%s %s", who, msg)!=2) return 0;
	ob = find_player(who);
	who=capitalize(who);
	if(!ob) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is not logged in."+NOSTYLE+"\n"); return 1;}
        if (in_editor(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is editing."+NOSTYLE+"\n"); return 1;}
        if (ob->query_tellblock()) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is currently blocking tells."+NOSTYLE+"\n"); return 1;}
        if(!interactive(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is disconnected."+NOSTYLE+"\n"); return 1;}
        if(query_idle(ob) > 120) write(RED+who+NOSTYLE+" "+BOLD+BLA+"has been idle for "+(query_idle(ob)/60)+"m"+((query_idle(ob)%60) ? (" "+(query_idle(ob)%60)+"s.") : ".")+NOSTYLE+"\n");
	    ob->Replyer(TP->NAME);
		ob->add_tellhistory(capitalize(TP->NAME) + " tells you: " + msg);
     tell_object(ob, line_wrap(((ENVTO->query_real_name()=="quicksilver") ? (RED+"Quicksilver") : (BOLD+GRE+"Absynthe")) +
                 NOSTYLE+" "+BOLD+BLA+"tells you: "+NOSTYLE+msg, (strlen(TP->NAME)+12))+"\n");
     write(line_wrap(BOLD+BLA+"You tell "+NOSTYLE+RED+who+NOSTYLE+BOLD+BLA+": "+NOSTYLE+msg, (strlen(who)+11))+"\n");
	return 1;
}

q_em1(str) {
	object ob;
	string who, msg;

	if(sscanf(str, "%s %s", who, msg)!=2) return 0;
	ob = find_player(who);
	who=capitalize(who);
	if(!ob) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is not logged in."+NOSTYLE+"\n"); return 1;}
        if (in_editor(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is editing."+NOSTYLE+"\n"); return 1;}
        if (ob->query_tellblock()) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is currently blocking tells."+NOSTYLE+"\n"); return 1;}
        if(!interactive(ob)) { write(RED+who+NOSTYLE+" "+BOLD+BLA+"is disconnected."+NOSTYLE+"\n"); return 1;}
        if(query_idle(ob) > 120) write(RED+who+NOSTYLE+" "+BOLD+BLA+"has been idle for "+(query_idle(ob)/60)+"m"+((query_idle(ob)%60) ? (" "+(query_idle(ob)%60)+"s.") : ".")+NOSTYLE+"\n");
	    ob->Replyer(TP->NAME);
		ob->add_tellhistory("* " + capitalize(TP->NAME) + " " + msg);
     tell_object(ob, line_wrap(BOLD+BLA+"* "+NOSTYLE+((ENVTO->query_real_name()=="quicksilver") ? (RED+"Quicksilver") : (BOLD+GRE+"Absynthe")) +
                 NOSTYLE+" "+msg, 2)+"\n");
     write(line_wrap(BOLD+BLA+"You emote to "+NOSTYLE+RED+who+NOSTYLE+BOLD+BLA+": "+NOSTYLE+((ENVTO->query_real_name()=="quicksilver") ? (RED+"Quicksilver") : (BOLD+GRE+"Absynthe"))+NOSTYLE+" "+msg, strlen(who)+15)+"\n");
	return 1;
}

set_aligntitle(str) {
	if(!str) { write("Your alignment displays as: "+this_player()->query_al_title()+"\n"); return 1; }
	this_player()->set_al_title(str);
	write("Your alignment has been set to: "+this_player()->query_al_title()+"\n");
	return 1;
}
