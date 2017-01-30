/*
    Speedster Code orginally done by Hurtbrain
    Modified by Pavlik for usage in the Monks Guild
    (orginal code = /players/hurtbrain/obj/newspeed.c)
    VERSION 1.1A
*/
int k;
string backp,bpatt,patt,ggg;
string comment;
object obj;

id(str){
  return str == "speed" || str == "monk_speed" || str == "speedster";
}

reset(arg) {
        if(arg) return;
patt=allocate(10);
bpatt=allocate(10);
backp=allocate(10);
comment=allocate(10);
restore_object("players/hawkeye/closed/monk/speed/"+lower_case(this_player()->query_real_name()));
}

long(){
  write(
  "A Monk Speedster.\n"+
  "Type 'info' for a list of commands.\n");
  return;
}

short(){ return "A Monk Speedster"; }

init() {
    add_action("go"); add_verb("go");
    add_action("back"); add_verb("back");
    add_action("rev"); add_verb("rev");
    add_action("add"); add_verb("add");
    add_action("del"); add_verb("del");
    add_action("path"); add_verb("paths");
    add_action("ref"); add_verb("newspeed");
    add_action("info_speedster"); add_verb("info");
    add_action("comment"); add_verb("comment");
}

info_speedster(){
  write(
  "This is a Monk Speedster.\n"+
  "Avaliable Commanders are : \n"+
  "  go <#> or <cmds>   -- execute path <#> or commands <cmds>\n"+
  "                        go 1  or go e,e,s,e\n"+
  "  back <#>           -- execute path in backwards.\n"+
  "                        e,e,s,e == w,n,w,w\n"+
  "  rev <#>            -- execute commands in reverse.\n"+
  "                        e,e,s,e == w,w,n,w\n"+
  "  add <cmds>         -- add path of commands <cmds> into speedster.\n"+
  "  del <#>            -- delete a path from the speedster.\n"+
  "  paths              -- display paths in speedster.\n"+
  "  newspeed           -- refresh your speedster.\n"+
  "  info               -- this menu\n"+
  "  comment <#> <str>  -- add comment <str> to path <#>.\n"+
  "                        comment 1 church_to_guild\n"+
  "  Monk Speedster version 1.1A, another cool Pavlik Production.\n");
  return 1;
}

comment(str)  {
        int num;
        string comms;
  if(!monk_check())  return 0;
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
        save_object("players/hawkeye/closed/monk/speed/"+lower_case(this_player()->query_real_name()));
        return 1;
        }

ref()  {
	int num;
  if(!monk_check()) return 0;
	move_object(clone_object("/players/hawkeye/closed/monk/monk_speed"),this_player());
  write("Speedster Refreshed - Ok.\n");
        for(num=0;num<k;++num) {
                backp[num]=volta(patt[num]);
                }
	save_object("players/hawkeye/closed/monk/speed/"+lower_case(this_player()->query_real_name()));
	destruct(this_object());
	return 1;
}

rev(str)  {
        int num,con;
  if(!monk_check()) return 0;
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
  if(!monk_check())  return 0;
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
  if(!monk_check())  return 0;
        obj=this_player();
      if(!str)
        return 0;
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
        for(cont=0;cont<number;cont++)  {
                if(sscanf(ggg,"%s,%s",path,ggg)==2)  {
      if(path == "n") call_other(obj, "go_north"); else
      if(path == "s") call_other(obj, "go_south"); else
      if(path == "e") call_other(obj, "go_east"); else
      if(path == "w") call_other(obj, "go_west"); else
      if(path == "ne") call_other(obj, "go_northeast"); else
      if(path == "nw") call_other(obj, "go_northwest"); else
      if(path == "se") call_other(obj, "go_southeast"); else
      if(path == "sw") call_other(obj, "go_southwest"); else
      if(path == "u") call_other(obj, "go_up"); else
      if(path == "d") call_other(obj, "go_down"); else
      tell_object(obj, "Invalid Command.\n");
                 } else {
      if(ggg == "n") call_other(obj, "go_north"); else
      if(ggg == "s") call_other(obj, "go_south"); else
      if(ggg == "e") call_other(obj, "go_east"); else
      if(ggg == "w") call_other(obj, "go_west"); else
      if(ggg == "ne") call_other(obj, "go_northeast"); else
      if(ggg == "nw") call_other(obj, "go_northwest"); else
      if(ggg == "se") call_other(obj, "go_southeast"); else
      if(ggg == "sw") call_other(obj, "go_southwest"); else
      if(ggg == "u") call_other(obj, "go_up"); else
      if(ggg == "d") call_other(obj, "go_down"); else
      tell_object(obj, "Invalid Command.\n");
                    tell_object(obj,"Done.\n");
                    return 1;
                    }
        }
        call_out("funza",1);
        return 1;
}


add(str)  {
  if(!monk_check())  return 0;
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
	save_object("players/hawkeye/closed/monk/speed/"+lower_case(this_player()->query_real_name()));
        return 1;
}

del(str)  {
        int num;
  if(!monk_check())  return 0;
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
	save_object("players/hawkeye/closed/monk/speed/"+lower_case(this_player()->query_real_name()));
        return 1;
}

path()  {
        int num;
  if(!monk_check())  return 0;
        if(!k)  {
                write("No pattern in the speedster.\n");
                return 1;
                }
    write("Your speedster contains the Patterns: \n");
        for(num=0;num<k;++num)  {
           write((num+1));
           if(comment[num])
            write(" ("+comment[num]+")");
           write(" : "+patt[num]+".\n");
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

monk_check(){
if(this_player()->query_guild_name() != "monk") {
    write("This curious object just doesn't do anything "+
    "for you.\n");
    return 0;
    }
  return 1;
}

get() { return 1; }

query_weight() { return 0; }

query_value() { return 0; }

drop() { return 1; }
