#include <ansi.h>

#define tell_v(x) if(find_player("vertebraker")) tell_object(find_player("vertebraker"), x)

#define LOG "/log/SCAVENGER"
#define NUM 1000

string *items;
string *paths;
int    line;

void reset(status arg)
{
  if(arg) return;
  items=paths=({});
  line = 1;
  this_object()->process_list();
}

void process_list()
{
 string sh, *shs,i,p,x;
 int s;
 int z;
 
 z = 0;
 sh="";
 while(z < file_size(LOG))
 {
  sh+=read_bytes(LOG,z,z+NUM);
  z+=(NUM+1);
 }
 shs=explode(sh,"\n");
 s = sizeof(shs);
 write("s items: "+s+"\n");
 while(s--)
 {
 sscanf(shs[s],"%s###%s",i,p);
 items += ({ i });
 paths += ({ p });
}
 if(!sh) return;
}

int query_sizeof() {
  return sizeof(items);
}

mixed *pick() {
  int ip;
  string it,x,y,z;
  ip = random(sizeof(items));
  it = items[ip];
  return ({ it, paths[ip] });
}

string *picks() {
  int s;
  mixed *p;
  p=({});
  s = 20;
  while(s--)
    p += ({ pick() });
  return p;
}

mixed *get_data() {
  mixed *g;
 int ip;
  string it;
  int s;
  int nomatch;
  g = ({ ({ }), ({ }) });
  s = 25;
  while(s--) {
     ip = random(sizeof(items));
     it = items[ip];
     if(member_array(it, g[0]) == -1)
     {
      g[0] += ({ it });
      g[1] += ({ paths[ip] });
     }
     else
     {
       nomatch=1;
       while(nomatch)
       {
         ip = random(sizeof(items));
         it = items[ip];
         nomatch = (member_array(it,g[0]) > -1);
       }
       g[0] += ({ it });
       g[1] += ({ paths[ip] });
    }       
  }
  return g;
}
