id(str){return str == "speed";}
short(){return "Speed";}
query_auto_load(){ return "/players/dersharp/closed/speedster:0"; }
long(){write("Usage: ex # cmd1, # cmd2, # cmd3, etc...\n");
	}
get(){return 1;}
drop(){return 0;}
query_value(){return 0;}
query_weight(){return 0;}
init(){add_action("do_com","ex");}
do_com(str){
string cmd, acmd, bcmd;
object tp;
int a, n;
tp = this_player();

if(!str){return 1;}
else if(sscanf(str,"%s,%s",acmd,bcmd)==2){
	str = acmd;
	if(sscanf(str,"%d %s",n,cmd)==2){
		a=0;
		while(a < n){
			command(cmd,tp);
			a++;
		}
	str = bcmd;
	do_com(str);
	return 1;
	}
	command(acmd,tp);
	str = bcmd;
	do_com(str);
	return 1;
}
else{
	if(sscanf(str,"%d %s",n,cmd)==2){
		a = 0;
		while(a<n){
			command(cmd,tp);
			a++;
		}
		write("Done\n");
		return 1;
	}
	command(str,tp);
	write("Done.\n");
	return 1;
}
return 1;
}
