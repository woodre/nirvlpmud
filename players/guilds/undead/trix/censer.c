string names;
int votes,i,j,answer;
reset(arg) {
	int i;
        if(arg) return;
	names=allocate(500);
	for(i=0;i<500;i++) names[i]="";
        restore_object("players/trix/closed/guild/census");
}
id( str ) {
        if(str=="censer") return 1;
        return 0;
}

long() {
        write( "A censer.\n");
}

short()
  { return "Censer"; }
init()
{
  add_action( "alist","list");
  add_action( "impulse","impulse");
}

impulse(str)
{  int j; 
    for(j=0;names[j]!=""&&names[j]!=str;j++)
      if(j==49)
	{ write("Guild list is full.\n");
	  return 1;
        }
    if(names[j]="")
	names[j]=str;
    save_object("players/trix/closed/guild/census");
    return 1;
}

alist() { i=0; list(); return 1; }
list()
{ int nume;
  nume=0;
  while(nume<10)
   { i++;
     nume++;
        if(names[i-1]=="") return 1;
	write(i+": "+capitalize(names[i-1])+"\n");
   }	
  write("More (q or Q to exit):");
  input_to("more");
  write("Dopo\n");
}

more(arg)  {
	if(arg=="q" || arg=="Q")
         {
                write("hey\n");
		write("\n");
			}
	else  {
		write("ELSE\n");
		list();
		}
	return 1;
	}
get() {
        return 1;
}
drop() {
        return 0;
}
