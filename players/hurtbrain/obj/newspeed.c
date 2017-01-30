int k;
string backp,bpatt,patt,ggg;
string comment;
object obj;

query_auto_load() {
        return "/players/hurtbrain/obj/newspeed.c:";
}
id(str) { return str == "speedster"; }

reset(arg) {
        if(arg) return;
patt=allocate(10);
bpatt=allocate(10);
backp=allocate(10);
comment=allocate(10);
if(this_player())
restore_object("players/hurtbrain/obj/spedir/"+lower_case(this_player()->query_real_name()));
}

long() { write("Undead's speedster.\n");
        write("Available commands are :\n");
        write("exe <num>     : execute path labeled 'num'.\n");
        write("exe <str>     : execute commands <str>.\n");
        write("back <num>    : execute backword path labeled 'num'.\n");
	write("                (if path = n,e,sw,u it executes d,ne,w,s.)\n");
        write("rev <num>     : execute backword path labeled 'num'.\n");
	write("                (if path = n,e,sw,u it executes u,sw,e,n.)\n");
        write("add <pattern> : add a pattern on the speedster.\n");
        write("del <number>  : delete a pattern on the speedster.\n");
        write("path          : show the patterns on the speedster.\n");
        write("ref           : refresh the speedster.\n");
        write("info speed    : info on the speedster.\n");
        write("comment <num> <str> : set comment to str for path number num\n");
        write("                      (just type comment <num> none if you\n");
        write("                      want to reset the comment.\n");
        return 1; }

short() { return "Undead's speedster";}

init() {
    add_action("go","exe");
    add_action("back","back");
    add_action("rev","rev");
    add_action("add","add");
    add_action("del","del");
    add_action("path","path");
    add_action("ref","ref");
    add_action("info","info");
    add_action("comment","comment");
    write("NEWS ON SPEEDSTER : type `info speed` to see what's up.\n");
}

comment(str)  {
        int num;
        string comms;
        if(!str || sscanf(str,"%d %s",num,comms)!=2)  
                {
                notify_fail("No such pattern in the speedster.\n");
                return 0;
                }
        if(num<1 || num>k)   {
                notify_fail("No such pattern in the speedster.\n");
                return 0;
                }
        if(comms=="none")  {
                write("You reset comment number "+num+".\n");
                comment[num-1]="";
                }
        else  {
                comment[num-1]=comms;
                write("Comment to pattern number "+num+" set to: \n"+comms+".\n");
                }
        save_object("players/hurtbrain/obj/spedir/"+lower_case(this_player()->query_real_name()));
        return 1;
        }

info(str)  {
        if(str!="speed")
                return 0;
        cat("/players/hurtbrain/helpdir/helpspeed");
        return 1;
        }

ref()  {
	int num;
	move_object(clone_object("/players/hurtbrain/obj/newspeed"),this_player());
	write("You refreshed your speedster.\n");
        write("Fixing "+capitalize(lower_case(this_player()->query_real_name()))+"'s speedster.\n");
        for(num=0;num<k;++num) {
                backp[num]=volta(patt[num]);
                }
        write(capitalize(lower_case(this_player()->query_real_name()))+"'s speedster fixed.\n");
	save_object("players/hurtbrain/obj/spedir/"+lower_case(this_player()->query_real_name()));
	destruct(this_object());
	return 1;
}

rev(str)  {
        int num,con;
        obj=this_player();
        if(!str || !sscanf(str,"%d",num))  return 0;
        if(num<1 || num>k)   {
                notify_fail("No such pattern in the speedster.\n");
                return 0;
                }
        ggg=bpatt[num-1];
	write("Executing path: "+ggg+".\n");
        funza();
        return 1;
}

back(str)  {
        int num,con;
        obj=this_player();
        if(!str || !sscanf(str,"%d",num))  return 0;
        if(num<1 || num>k)   {
                notify_fail("No such pattern in the speedster.\n");
                return 0;
                }
        ggg=backp[num-1];
	write("Executing path: "+ggg+".\n");
        funza();
        return 1;
}

go(str) {
        int num;
        obj=this_player();
        if(!str)  return 0;
        if(!sscanf(str, "%d", num))
          ggg = str;
        else {
          if(num<1 || num>k)   {
                  notify_fail("No such pattern in the speedster.\n");
                  return 0;
                  }
          ggg=patt[num-1];
          }
	write("Executing path: "+ggg+".\n");
        funza();
        return 1;
}

funza()  {
        string path;
        int cont;
        int number;
        number=5;
        if(obj->query_brief()==1)
                number=5;
        for(cont=0;cont<number;++cont)  {
                if(sscanf(ggg,"%s,%s",path,ggg)==2)  {
                        if(path=="e")
                                call_other(obj,"go_east");
                        else if(path=="w")
                                call_other(obj,"go_west");
                        else if(path=="n")
                                call_other(obj,"go_north");
                        else if(path=="s")
                                call_other(obj,"go_south");
                        else if(path=="ne")
                                call_other(obj,"go_northeast");
                        else if(path=="nw")
                                call_other(obj,"go_northwest");
                        else if(path=="se")
                                call_other(obj,"go_southeast");
                        else if(path=="sw")
                                call_other(obj,"go_southwest");
                        else if(path=="u")
                                call_other(obj,"go_up");
                        else if(path=="d")
                                call_other(obj,"go_down");
                        else
                                tell_object(obj,"Illegal move!\n");
                }
                else {  
                        if(ggg=="e")
                                call_other(obj,"go_east");
                        else if(ggg=="w")
                                call_other(obj,"go_west");
                        else if(ggg=="n")
                                call_other(obj,"go_north");
                        else if(ggg=="s")
                                call_other(obj,"go_south");
                        else if(ggg=="ne")
                                call_other(obj,"go_northeast");
                        else if(ggg=="nw")
                                call_other(obj,"go_northwest");
                        else if(ggg=="se")
                                call_other(obj,"go_southeast");
                        else if(ggg=="sw")
                                call_other(obj,"go_southwest");
                        else if(ggg=="u")
                                call_other(obj,"go_up");
                        else if(ggg=="d")
                                call_other(obj,"go_down");
                        else
                                tell_object(obj,"Illegal move!\n");
                        tell_object(obj,"Done.\n");
                        return 1;
                        }
        }
        call_out("funza",1);
        return 1;
}


add(str)  {
        if(!str)  {
                notify_fail("What do you want to add?\n");
                return 0;
                }
        if(k>9)   {
                notify_fail("The speedster is full.\n");
                return 0;
                }
        patt[k]=str;
        bpatt[k]=gira(str);
        backp[k]=volta(str);
        ++k;
        write("Path number "+k+": "+str+" added.\n");
	save_object("players/hurtbrain/obj/spedir/"+lower_case(this_player()->query_real_name()));
        return 1;
}

del(str)  {
        int num;
        if(!str || (!sscanf(str,"%d",num)) || (num>k) || (num<1))  {
                notify_fail("What do you want to delete from the speedster?\n");
                return 0;
                }
        write("You deleted the path number "+num+".\n");
        for(num;num<k;++num)  {
                patt[num-1]=patt[num];
                bpatt[num-1]=bpatt[num];
                }
        --k;
        patt[k]="";
        bpatt[k]="";
        backp[k]="";
	save_object("players/hurtbrain/obj/spedir/"+lower_case(this_player()->query_real_name()));
        return 1;
}

path()  {
        int num;
        if(!k)  {
                write("No pattern in the speedster.\n");
                return 1;
                }
        for(num=0;num<k;++num)  {
                if(!comment[num])
                        write(".\n");
                else write(comment[num]+".\n");
                write((num+1)+" : "+patt[num]+".\n");
                }
        return 1;
}

gira(str) {
        int cont;
        string pri,sec,rets;
        cont=1;
        rets="";
        while(cont!=0)  {
                cont=0;
                sec=str;
                str="";
                while(sscanf(sec,"%s,%s",pri,sec)==2)  {
                        if(cont!=0)
                                str+=",";
                        str+=pri;
                        ++cont;
                        }
                rets+=sec;
                if(cont!=0)
                        rets+=",";
                }
        return rets;
}

volta(str) {
        int cont;
        string pri,sec,rets;
        cont=1;
        rets="";
        while(cont!=0)  {
                cont=0;
                sec=str;
                str="";
                while(sscanf(sec,"%s,%s",pri,sec)==2)  {
                        if(cont!=0)
                                str+=",";
                        str+=pri;
                        ++cont;
                        }
                if(sec=="e")
                        sec="w";
                else if(sec=="w")
                        sec="e";
                else if(sec=="n")
                        sec="s";
                else if(sec=="s")
                        sec="n";
                else if(sec=="ne")
                        sec="sw";
                else if(sec=="nw")
                        sec="se";
                else if(sec=="se")
                        sec="nw";
                else if(sec=="sw")
                        sec="ne";
                else if(sec=="u")
                        sec="d";
                else if(sec=="d")
                        sec="u";
                rets+=sec;
                if(cont!=0)
                        rets+=",";
                }
        return rets;
}

get() { return 1; }

query_weight() { return 0; }

query_value() { return 0; }

drop() { return 1; }
