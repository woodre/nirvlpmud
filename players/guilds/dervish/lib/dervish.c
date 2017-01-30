#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	write("\n");
	write(BOLD+RED+"\tThe sands whirl about you...\n"+OFF+OFF);
	if(!str) {
	cat(HELPPATH+"/general.txt");
	write("\n"); return 1; }
	if(str == "advanced"){cat(HELPPATH+"/advanced.txt"); return 1	;}
	if(str == "rules"){cat(HELPPATH+"/rules.txt"); return 1;}
	if(str == "dreset"){cat(HELPPATH+"/dreset.txt"); return 1;}
	if(str == "leavedervish"){cat(HELPPATH+"/leave.txt"); return 1;}
	if(str == "LeaveDervish"){cat(HELPPATH+"/leave.txt"); return 1;}
	if(str == "dhome"){cat(HELPPATH+"/dhome.txt"); return 1;}
	if(str == "dinvis"){cat(HELPPATH+"/dinvis.txt"); return 1;}
	if(str == "dtitle"){cat(HELPPATH+"/dtitle.txt"); return 1;}
	if(str == "run"){cat(HELPPATH+"/run.txt"); return 1;}
	if(str == "scatter"){cat(HELPPATH+"/scatter.txt"); return 1;}

	if(str == "transfer"){cat(HELPPATH+"/transfer.txt"); return 1;}
	if(str == "dchant"){cat(HELPPATH+"/dchant.txt"); return 1;}
	if(str == "dpray"){cat(HELPPATH+"/dpray.txt"); return 1;}
	if(str == "confuse"){cat(HELPPATH+"/confuse.txt"); return 1;}

	if(str == "dheal"){cat(HELPPATH+"/dheal.txt"); return 1;}
	if(str == "offwield"){cat(HELPPATH+"/offwield.txt"); return 1;}
	if(str == "sandblast"){cat(HELPPATH+"/sandblast.txt"); return 1;}
	if(str == "dcleanse"){cat(HELPPATH+"/dcleanse.txt"); return 1;}
	if(str == "sandstorm"){cat(HELPPATH+"/sandstorm.txt"); return 1; }
	if(str == "doasis"){cat(HELPPATH+"/doasis.txt"); return 1; }
	if(str == "dsharpen"){cat(HELPPATH+"/dsharpen.txt"); return 1; }
	if(str == "whirlwind"){cat(HELPPATH+"/whirlwind.txt"); return 1; }
	write("That help topic is not available.\n");
	return 1;
}