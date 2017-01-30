int k;
string bpatt,patt,ggg;
object obj;

query_auto_load() {
        return "/players/hurtbrain/obj/myspeed.c:";
}
id(str) { return str == "speedster"; }

reset(arg) {
        if(arg) return;
patt=allocate(10);
bpatt=allocate(10);
if(this_player())
	restore_object("players/hurtbrain/obj/spedir/"+lower_case(this_player()->query_real_name()));
}

long() { write("A speedster. Type 'go <num>' or 'back <num>' to start.\n");
	write("Other commands are :\n");
        write("add <pattern>.\ndel <number>.\npath.\nref.\n");
	return 1; }

short() { return "Speedster";}

init() {
    add_action("go","go");
    add_action("back","back");
    add_action("add","add");
    add_action("del","del");
    add_action("path","path");
    add_action("ref","ref");
}

ref()  {
move_object(clone_object("/players/hurtbrain/obj/speeds"),this_player());
write("You refreshed your speedster.\n");
destruct(this_object());
return 1;
}

back(str)  {
	int num,con;

	obj=this_player();
	if(!str || !sscanf(str,"%d",num))  return 0;
	if(num<1 || num>k)   {
		notify_fail("No such a pattern in the speedster.\n");
		return 0;
		}
	ggg=bpatt[k-1];
	funza();
	return 1;
}

go(str) {
	int num;
	obj=this_player();
	if(!str || !sscanf(str,"%d",num))  return 0;
	if(num<1 || num>k)   {
		notify_fail("No such a pattern in the speedster.\n");
		return 0;
		}
	ggg=patt[num-1];
	funza();
	return 1;
}

funza()  {
	string path;
	int cont;
	for(cont=0;cont<6;++cont)  {
		if(sscanf(ggg,"%s,%s",path,ggg)==2)  {
			command(path,obj);
		}
		else {  command(ggg,obj);  write("Done.\n"); return 1; }
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
	save_object("players/hurtbrain/obj/spedir/"+lower_case(this_player()->query_real_name()));
	return 1;
}

path()  {
	int num;
	if(!k)  {
		write("No pattern in the speedster.\n");
		return 1;
		}
	for(num=0;num<k;++num)  write((num+1)+" : "+patt[num]+".\n");
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

get() { return 1; }

query_weight() { return 0; }

query_value() { return 0; }

drop() { return 1; }

