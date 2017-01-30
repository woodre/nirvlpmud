string names;
int votes,i,j,answer;
inherit "room/room"; 
reset(arg) {
        object board;
    if(arg) return;
    names=allocate(500);
    for(i=0;i<500;i++) names[i]="";
    restore_object("players/trix/closed/guild/census");
    set_light(1);
    long_desc = "This is the meeting room where Undead powers initiates gather to know the will\n"+
		"of the Unnameable and follow the path He traced to make Undead breed better\n"+
		"and lead us all to the final reward. A soft fluroscence coming from the ceiling\n"+
		"light the room and relaxes you, in the middle of the room you see a huge marble\n"+
		"table with three high marble thrones and six slightly smaller seats.\n"+
 		"You notice a sign engraved on a wall.\n";
   short_desc = "Undead Powers Room";
    dest_dir = ({ "/players/trix/closed/guild/guild_room.c", "down"});
    items = ({ "table", "A huge marble table where important decisions are made",
	       "sign", "The sign reads: Type 'adepts' to see the list of our breed" });
    board=clone_object("/players/trix/closed/guild/gcboard.c");
    move_object(board,this_object());
}
init()
{ 
   object obj;
   ::init();
}

impulse(str)
{  int j; 
    for(j=0;names[j]!=""&&names[j]!=str;j++)
      if(j==499)
      if(!str)
        { write("---- NULL ----\n");
	  return 1;
        }
    if(names[j]="")
	names[j]=str;
    save_object("players/trix/closed/guild/census");
    return 1;
}

alist() 
{ 
i=0;
write("This list contains the names of who ever owned an undead life.\n"); 
list();
return 1;
}
list()
{ int nume;
  nume=0;
  while(nume<10)
   { i++;
     nume++;
        if(names[i]=="") return 1;
   write(i+": "+capitalize(names[i])+"\n");
   }	
  write("More (q or Q to exit):");
  input_to("more");
}

more(arg)  {
	if(arg=="q" || arg=="Q")
         {
		write("\n");
			}
	else  {
		list();
		}
	return 1;
	}
correct(arg)
 { int i,start;
   if(!arg) { write("Number???\n"); return 1; }
   if(!sscanf(arg,"%d",i)) { write("Wrong Syntax!\n"); return 1; }
   start=i;
   while(names[i]!=""||start==i)
    names[i]=names[++i];
   save_object("players/trix/closed/guild/census");
   return 1;
 }
