#include "/players/mythos/closed/guild/name.h"
#include "/room/clean.c"
#define  MASTER  "/players/mythos/droom/master.c"
string dest_dir;
string short_desc;
string long_desc;
string items;
int no_castle_flag;
int no_exits;
int grid;
int lvalue, svalue;
string realms;
string init_monsters;
int init_chance;
int lifepreserve;
static int tog;
int pk;

id(str) {
    int i;
    if (!items[0])
	return;
    while(i < sizeof(items)) {
	if (items[i] == str)
	    return 1;
	i += 2;
    }
    return 0;
}

reset(arg) { if(arg) return; 
  grid = allocate(2); short_desc = allocate(6); long_desc = allocate(6); 
  lvalue = svalue = 0; realms = 0; init_chance = allocate(10); 
  init_monsters = allocate(9);
  lifepreserve = 0; tog = 0; items = allocate(20);
  dest_dir = allocate(20); pk = 0;
  call_out("life_check",300);}

set_grid(int x,int y) {  grid[0] = x; grid[1] = y; 
      MASTER->add_grid(this_object(),x,y);}

query_grid(int n) { if(!n) return grid; 
                   if(n == 1) return grid[0]; 
                   if(n == 2) return grid[1]; }

set_pk(n) { if(n) pk = 1; else pk = 0; }
set_dir(string paths,string where,int n) { 
          if(!n) { int h; h = 0; n = 0;
                   while(h<sizeof(dest_dir)) {  
                    if(dest_dir[h]) n = h + 1; h++; }
                 }
                 if(n) { int a; a = n/2; if(a*2 != n) n = n + 1; }
                 if(n > 20) { write("DEST DIR IS FULL.\n"); return 1; }
                 dest_dir[n] = paths;
                 dest_dir[n+1] = where;
           }
           
           /*
remove_dir(str) { 
int hh,nn;
           if(!str) { clear_dir(); return 1; } 
              nn = hh = 0;
                while(hh<sizeof(dest_dir)) {
                  if(dest_dir[hh] == str) {
                    dest_dir[hh] = 0;
                    nn = 1;
                  return 1; } hh++;}
                if(!nn) { write("dest_dir of "+str+" non-existant.\n"); return 1; }
             }
remove_whole_dir(str,int chc) { int k,j; k = 0; j = 666;
                  while(k<sizeof(dest_dir)) { if(dest_dir[k] == str) j = k; k++;}
                  if(j == 666) { write("dest_dir of "+str+" non-existant.\n"); return 1; }
                  if(!chc) remove_dir(dest_dir[j-1]);
                  else remove_dir(dest_dir[j+1]);
                  remove_dir(str);
                  }
                  
replace_dir(string before,string become,int chc) {
            int k,j; k = 0; j = 666;
            while(k<sizeof(dest_dir)) { if(dest_dir[k] == before) j = k; k++;}
            if(j==666) { write("dest_dir of "+before+" non-existant.\n"); return 1; }
            if(chc != 66 && chc != 666) remove_dir(before);
            if(chc == 66) { remove_dir(dest_dir[j-1]); 
                            set_dir(become,before,j-1); }
            if(chc == 666) { remove_dir(dest_dir[j+1]);
                             set_dir(before,become,j); }
            if(!chc) set_dir(dest_dir[j-1],become,j-1);
            if(chc == 1) set_dir(become,dest_dir[j+1],j);
            }
             */
             
clear_dir() { int h; h = 0; while(h<sizeof(dest_dir)) { dest_dir = 0; h++; } }
clear_items() { int h; h = 0; while(h<sizeof(items)) { items = 0; h++; } }
clear_init_chance() { int h; h = 0; while(h<sizeof(init_chance)) { init_chance = 0; h++; } }
clear_init_monsters() { int h; h = 0; while(h<sizeof(init_monsters)) { init_monsters = 0; h++; } }

set_items(string what,string dscr,int n) { 
          if(!n) { int h; h = 0; n = 0;
                   while(h<sizeof(items)) {  
                    if(items[h]) n = h + 1; h++; }
                 }
                 if(n) { int a; a = n/2; if(a*2 != n) n = n + 1; }
                 if(n > 20) { write("ITEMS IS FULL.\n"); return 1; }
                 items[n] = what;
                 items[n+1] = dscr;
           }
set_light_switch(int n) { set_light(n); }
query_light() { return set_light(0); }
set_lifepreserve(int n) { if(!n) n = 1; lifepreserve = n; 
            if(n == 69) { call_out("life_check",300); return 1; }}
set_short(str,int x) { if(!x) x = 0; short_desc[x] = str; }
set_short_value(n) { if(!n) n = 0; svalue = n; }
set_long_value(n) { if(!n) n = 0; lvalue = n; }
query_lvalue() { return lvalue; }
query_svalue() { return svalue; }
set_long(str,int x) { if(!x) x = 0; long_desc[x] = str; }
set_realm(str) { if(!str) realms = "NT"; else if(str == "0") realms = 0; 
                 else realms = str; }
set_init_chance(int x,int y) { if(x > 0) init_chance[0] = 1; init_chance[x] = y; }
set_init_monsters(str,int x) { string path;
                               if(!x) x = 0; 
                               path = str;
                               if(sscanf(str,"~%s",path) == 1) 
                                  path = "/players/mythos/dmon/"+path;
                               init_monsters[x] = path; 
                               if(!init_chance[0]) init_chance[0] = 1;
                               if(!init_chance[x+1]) init_chance[x+1] = 50;}

init() {
    int i,h;
    string att,moo;
    if(this_player() && this_player()->is_player()) {
    if(!pk) this_player()->set_fight_area();
    tog = 1;
    if(init_chance[0]) {
    if(oknum()) {
    if(sizeof(init_chance) - 1 != sizeof(init_monsters)) {
      write("init size is wrong.\n");
    return 1; }
    h = 1;
      while(h < sizeof(init_chance)) {
      if(random(100) < init_chance[h]) {
      att = 0;
      att = init_monsters[h-1];
      if(att) {
      if(sscanf(att,"~%s",moo) == 1) 
        att = "/players/mythos/dmon/"+moo+".c";
      move_object(clone_object(att),this_object()); }
      }
      h += 1;
      }
    } }
    }
    if (!dest_dir[0])
	return;
    i = 1;
    while(i < sizeof(dest_dir)) {
	if(dest_dir[i]) add_action("move", dest_dir[i]);
	i += 2;
    }
}

long(str) {
    int i,ii;
    if (set_light(0) == 0  && !present(fear,this_player())){
       write("It is dark.\n");
       return;
    }
    if (!str) {
    write(short_desc[svalue]+"\n");
	write(long_desc[lvalue]);
   if(!dest_dir[0] || no_exits) write("    No obvious exits.\n");
	else {
	ii = 0;
	for(i=0;i<sizeof(dest_dir);i+=2) {
	  if(dest_dir[i]) ii = ii + 1;
	}
	    i = 1;
	    if (ii == 1)
		write("    There is one obvious exit:");
	    else
		write("    There are " + convert_number(ii) +
		      " obvious exits:");
	    while(i < sizeof(dest_dir)) {
	    if(dest_dir[i]) {
		write(" " + dest_dir[i]); }
		i += 2;
		if(dest_dir[i - 2]) {
		if (i == ii*2 - 1)
		    write(" and");
		else if (i < ii*2)
		    write(","); }
	    }
	    write(".\n");
	}
	return;
    }
    if (!items[0])
	return;
    i = 0;
    while(i < sizeof(items)) {
	if (items[i] == str) {
	    write(items[i+1] + ".\n");
	    return;
	}
	i += 2;
    }
}

query_property() {  return 0; }

move(str) {
    int i;
    string place;
    object placed;
    placed = 0;
    i = 1;
    while(i < sizeof(dest_dir)) {
	if (query_verb() == dest_dir[i]) {
	   if(sscanf(dest_dir[i-1],"~%s",place) == 1) {
	   this_player()->move_player(dest_dir[i]+"#"+"players/mythos/droom/"+place+".c");
	   return 1; 
	   } 
	   else if(sscanf(dest_dir[i-1],"yy%syy",place) == 1) {
	     int ldc, sdc, lsw, gx, gy;
	     int item, ic, idi;
	     object abs;
	     int jj;
	     sscanf(place,"grid %dx%dy sh %d lg %d light %d %d %d %d",
	            gx,gy,sdc,ldc,lsw,item,ic,idi);
	     abs = all_inventory(this_object());
	     for(jj=0;jj<sizeof(abs);jj++) {
	       if(!abs[jj]->is_pet() && !abs[jj]->is_player()) destruct(abs[jj]); 
	     }
	     MASTER->add_grid(this_object(),gx,gy);
	     lvalue = ldc; svalue = sdc;
	     this_object()->set_light(-set_light(0) + lsw);
	     if(item) clear_items();
	     if(ic) { clear_init_chance(); clear_init_monsters(); }
	     if(idi) { clear_dir(); }
	     init();
	     command("look",this_player());
	     return 1; }
	   else if(sscanf(dest_dir[i-1],"xx%sxx",place) == 1) {
	     int gxx, gyy, llsw;
	     string rlm, sh, lg, imon;
	     string dirs;
	     string it,ich;
	     int hh,xyx1,xyx2;
	     sscanf(place,
	         "grid %dx%dy light %d realm %s sht %s log %s dir %s item %s ic %s im %s",
	                   gxx,gyy,llsw,rlm,sh,lg,dirs,it,ich,imon);
	     dirs = explode(dirs,"vv");
	     it = explode(it,"vv");
	     ich = explode(ich,"vv");
	     imon = explode(imon,"vv");
	     placed = MASTER->query_exist(gxx,gyy);
	     if(!placed) {
	     placed = clone_object("/players/mythos/droom/drom.c");
	     placed->set_light_switch(llsw);
	     placed->set_short(sh);
	     placed->set_long(lg);
	     placed->set_grid(gx,gy);
	     hh = 0;
	     while(hh<sizeof(dirs)) {
	     placed->set_dir(dirs[hh],dirs[hh+1]);
	     hh = hh + 2; }
	     hh = 0;
	     while(hh<sizeof(it)) {
	     placed->set_items(it[hh],it[hh+1]);
	     hh = hh + 2; }
	     placed->set_realms(rlm);
	     hh = 0;
	     while(hh<sizeof(ich)) {
	     sscanf(ich[hh],"%d",xyx1);
	     sscanf(ich[hh+1],"%d",xyx2);
	     placed->set_init_chance(xyx1,xyx2);
	     hh = hh + 2; }
	     hh = 0;
	     while(hh<sizeof(imon)) {
	     sscanf(imon[hh+1],"%d",xyx1);
	     placed->set_init_monsters(imon[hh],xyx1); 
	     hh = hh + 2; }
	     }
	     move_object(this_player(),placed);
	     command("look",this_player());
	   if(!this_player()->query_invis()) {
	      tell_room(this_object(),this_player()->query_name()+
	                " leaves "+query_verb()+".\n");
	      tell_room(this_object(),this_player()->query_name()+
	                " arrives.\n"); }
	    return 1; }
	    this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
	    return 1;
	}
	i += 2;
    }
}

short() {
  int i;
  string temp;
    if (set_light(0) || this_player()->query_level() > 100)
	{
	  temp = short_desc[svalue];
             if(this_player())
	  if(this_player()->query_level() > 100) {
	     temp += " <"+grid[0]+","+grid[1]+">";
	     if(!set_light(0)) temp += " o";
	  }
	  temp += " [";
	  if (!dest_dir[0] || no_exits) temp += "no exits";
	  else
	    for (i=1;i<sizeof(dest_dir);i+=2)
                {
                if(dest_dir[i]) {
	          temp += translate_exit(dest_dir[i]);
                  if (i < sizeof(dest_dir)-2 && dest_dir[i + 2]) temp += ","; 
                }
		}
	  temp += "]";
          return temp;
	}
    return "Dark room";
}

translate_exit(str) {
  if (str == "north") return "n";
  if (str == "south") return "s";
  if (str == "east") return "e";
  if (str == "west") return "w";
  if (str == "northeast") return "ne";
  if (str == "northwest") return "nw";
  if (str == "southeast") return "se";
  if (str == "southwest") return "sw";
  if (str == "up") return "u";
  if (str == "down") return "d";
  return str;
}

query_dest_dir() {
    return dest_dir;
}

query_destdir(n) {
    return dest_dir[n];
}

query_destname(str) {
int q;
q = 0;
  while(q<sizeof(dest_dir)) {
    if(str == dest_dir[q]) return q;
    q++;
  }
return 69; }

query_long() {
    return long_desc[lvalue];
}

string numbers;

convert_number(n) {
    if (!pointerp(numbers))
	numbers = query_numbers();
    if (n > 9)
	return "lot of";
    return numbers[n];
}

query_numbers() {
    if (!numbers) {
	if (object_name(this_object()) == "players/mythos/droom/droom")
	    numbers = ({"no", "one", "two", "three", "four", "five",
			    "six", "seven", "eight", "nine" });
	else
	    numbers = call_other("players/mythos/droom/droom", "query_numbers");
    }
    return numbers;
}

query_drop_castle() {
    return no_castle_flag;
}

realm() { return realms; }

lifecheck() { 
object here;
int boo,blah,h;
blah = 0;
boo = 0;
h = 0;
if(lifepreserve) return 1; 
  here = all_inventory(this_object());
  while(h<sizeof(here)) {
    if(living(here[h])) blah = 1;
    if(here[h]->is_pet() || here[h]->is_player()) {
      boo = 1;
    }
    h++;
 }
 if(blah && boo) { call_out("lifecheck",180); return 1; }
 if(blah && !boo) { call_out("lifecheck_tog",120); return 1; }
 MASTER->add_grid(0,grid[0],grid[1]);
 destruct(this_object());
return 1; } 

lifecheck_tog() {
object here;
int boo,h;
boo = 0;
h = 0;
if(lifepreserve) return 1; 
  here = all_inventory(this_object());
  while(h<sizeof(here)) {
    if(here[h]->is_pet() || here[h]->is_player()) {
      boo = 1;
    }
    h++;
 }
 if(boo || tog) { tog = 0; call_out("lifecheck",300); return 1; }
 else { 
   MASTER->add_grid(0,grid[0],grid[1]);
   destruct(this_object()); 
 }
return 1; }

oknum() {
object wh;
int v,z;
  wh = all_inventory(this_object());
  v = 0;
  z = 0;
  while(v<sizeof(wh)) {
    if(living(wh[v])) if(wh[v]->query_npc()) if(!wh[v]->is_pet()) if(!wh[v]->is_kid())z = z + 1;
  if(z > 7) return 0;
  v = v + 1; }
return 1; }
