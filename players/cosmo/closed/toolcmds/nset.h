nset(str) {
string who,what;
int num;
object ob;
  if(!str) { write("nset <who> <what> <num> \n"); return 1; }
  sscanf(str,"%s %s %d",who,what,num);
  ob = find_player(who);
  if(!ob) { write("not logged on.... \n"); return 1; }
if(what == "exl") { ob->set_extra_level(num);
        write("extra level of "+who+" set at "+num+".\n"); return 1; }
if(what == "level") { ob->set_level(num);
        write("level of "+who+" set at "+num+".\n"); return 1; }
if(what == "align") {ob->add_alignment(num);
    write("alignment of "+who+" is altered by "+num+".\n"); return 1; }
if(what == "wc") { ob->set_wc(num);
        write("weapon class of "+who+" set at "+num+".\n"); return 1; }
if(what == "dead") { ob->set_dead(num);
        write("dead of "+who+" set at "+num+".\n"); return 1; }
if(what == "soak") { ob->add_soaked(num);
        write("soak of "+who+" set at "+num+".\n"); return 1; }
if(what == "stuff") { ob->add_stuffed(num);
        write("stuff of "+who+" set at "+num+".\n"); return 1; }
if(what == "intox") { ob->add_intoxication(num);
        write("intox of "+who+" set at "+num+".\n"); return 1; }
if(what == "ac") { ob->set_ac(num);
        write("ac of "+who+" set at "+num+".\n"); return 1; }
if(what == "frog") { ob->frog_curse(num);
        write("frog of "+who+" set at "+num+".\n"); return 1; }
if(what == "wiz") { ob->set_wiz_level(num);
        write("wiz level of "+who+" set at "+num+".\n"); return 1; }
if(what == "xp") { ob->add_exp(num);
  write("You have altered "+who+"'s experience by "+num+"\n"); return 1; }
return 1;
}

