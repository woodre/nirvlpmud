#include "/players/quicksilver/closed/color.h"

int i;

init()
{
  add_action("q_tell1","t");
  add_action("q_em1","em");
}

get() { return 1; }
drop() { return 1; }
id(str) { return str=="jtell"; }
query_auto_load() { return "/players/quicksilver/closed/jtell.c:"; }

q_tell1(str) {
	object ob;
	string who, msg;

	if(sscanf(str, "%s %s", who, msg)!=2) return 0;
	ob = find_player(who);
	who=capitalize(who);
	if(!ob) { write(BOLD+GRE+who+NOSTYLE+" "+CYA+"is not logged in."+NOSTYLE+"\n"); return 1;}
        if (in_editor(ob)) { write(BOLD+GRE+who+NOSTYLE+" "+CYA+"is editing."+NOSTYLE+"\n"); return 1;}
        if (ob->query_tellblock()) { write(BOLD+GRE+who+NOSTYLE+" "+CYA+"is currently blocking tells."+NOSTYLE+"\n"); return 1;}
        if(!interactive(ob)) { write(BOLD+GRE+who+NOSTYLE+" "+CYA+"is disconnected."+NOSTYLE+"\n"); return 1;}
        if(query_idle(ob) > 120) write(BOLD+GRE+who+NOSTYLE+" "+CYA+"has been idle for "+(query_idle(ob)/60)+"m"+((query_idle(ob)%60) ? (" "+(query_idle(ob)%60)+"s.") : ".")+NOSTYLE+"\n");
        tell_object(ob, BOLD+GRE+"Judas"+NOSTYLE+" "+CYA+"tells you: "+NOSTYLE+msg+"\n");
        write(CYA+"You tell "+NOSTYLE+BOLD+GRE+who+NOSTYLE+CYA+": "+NOSTYLE+msg+"\n");
	return 1;
}

q_em1(str) {
	object ob;
	string who, msg;

	if(sscanf(str, "%s %s", who, msg)!=2) return 0;
	ob = find_player(who);
	who=capitalize(who);
	if(!ob) { write(BOLD+GRE+who+NOSTYLE+" "+CYA+"is not logged in."+NOSTYLE+"\n"); return 1;}
        if (in_editor(ob)) { write(BOLD+GRE+who+NOSTYLE+" "+CYA+"is editing."+NOSTYLE+"\n"); return 1;}
        if (ob->query_tellblock()) { write(BOLD+GRE+who+NOSTYLE+" "+CYA+"is currently blocking tells."+NOSTYLE+"\n"); return 1;}
        if(!interactive(ob)) { write(BOLD+GRE+who+NOSTYLE+" "+CYA+"is disconnected."+NOSTYLE+"\n"); return 1;}
        if(query_idle(ob) > 120) write(BOLD+GRE+who+NOSTYLE+" "+CYA+"has been idle for "+(query_idle(ob)/60)+"m"+((query_idle(ob)%60) ? (" "+(query_idle(ob)%60)+"s.") : ".")+NOSTYLE+"\n");
        tell_object(ob, CYA+"* "+NOSTYLE+BOLD+GRE+"Judas"+
                    NOSTYLE+" "+CYA+msg+NOSTYLE+"\n");
        write(CYA+"You emote to "+NOSTYLE+BOLD+GRE+who+NOSTYLE+CYA+": "+NOSTYLE+BOLD+GRE+"Judas"+
                        NOSTYLE+" "+CYA+msg+NOSTYLE+"\n");
	return 1;
}
