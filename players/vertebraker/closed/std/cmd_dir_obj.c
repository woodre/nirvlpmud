static string cmd_dir;

void reset(status x)
{
 if(x) return;
 cmd_dir="";
}

void add_cmds()
{
 int s; string *x,y;
 s=sizeof(x=get_dir(cmd_dir));
 while(s--)
 {
  sscanf(x[s],"_%s.c",y);
  add_action("cmd_hook",y);
 }
}

void init()
{
 add_cmds();
}

status cmd_hook(string str)
{
 string x;
 return (int)call_other(cmd_dir+"_"+
  (x=query_verb())+".c","cmd_"+x,str);
}

status drop() { return 1; }
status get() { return 1; }
