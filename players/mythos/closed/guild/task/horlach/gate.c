#include "/players/mythos/closed/guild/def.h"
#define fpl  command("look",tp)
#define homer  move_player("time#players/mythos/closed/guild/task/horlach/home")

int a,b,c,d,e,f,g,h,i;
int j,k,l,m,n,o,p,z;
string aa,bb,cc,dd,ee;
string ff,gg,hh,ii;
string jj;
object ob;

inherit "room/room";
reset(arg) {
if(arg) return;
  if(!arg) {
  set_light(-2);
    short_desc = "Where Death and Time Collide   ";
    cen();
    k = 0;
    aa = "You stand in a large field.  All around is bare except\n"+
         "for the odd post that stands in the middle of the field.\n"+
         "You may go south, southeast, or southwest.\n";
    bb = "You stand within a forest.  Pine trees shade you and time\n"+
         "seems endless.  Before you stands a post.\n"+
         "You may go west, northwest, southwest, or south.\n";
    cc = "All is barren where you stand.  This is a wasteland- the sun\n"+
         "beats down upon the dusty plain.  An odd post stands before you.\n"+
         "You may go east, northeast, southeast, or south.\n";
    dd = "All around you is water.  Blue green water splashes around your\n"+
         "feet.  Rising from this water is a post.\n"+
         "You may go north, west, southwest, or south.\n";
    ee = "It is hot.  Lava surrounds you.  Sweat pours from your body as\n"+
         "you try and deal with this heat.  Rising from the midst of molten\n"+
         "rock is a post.\n"+
         "You may go north, east, southeast, or south.\n";
    ff = "You are surrounded by large stones, mansize, that create a boundary\n"+
         "several meters in radius.  In the center lies a stone altar.  A cloaked\n"+
         "figure stands before the altar and is slowly chanting.\n"+
         "You may go north, east, west, south, northeast, northwest,\n"+
         "           southeast, or southwest.\n";
    gg = "You are surrounded in mist.  All is quiet.  Rising within this mist\n"+
         "stands a post.\n"+
         "You may go north, west, south, northwest, or southwest.\n";
    hh = "You stand within a great hall.  The ceiling stretches miles above you.\n"+
         "Great figures of metal line the hall.  In the middle of the wood floor\n"+
         "stand a post\n"+
         "You may go north, east, south, northeast, or southeast.\n";
    ii = "You stand before a large glowing portal.  Around you is blackness.\n"+
         "You may go north, south, northeast, or northwest.\n";
    jj = "You stand atop a mountain.  Ice covers everything and all is cold.\n"+
         "Sitting atop a pillar of ice is a crystal sphere.\n"+
         "You may go north, northeast, or northwest.\n";
    long_desc = aa;
    a = 1;
    set_heart_beat(1);
} }

realm() { return "NT";}

query_k() { return k; }

cleanse() {
ob = all_inventory(this_object()); 
  for(z=0;z<sizeof(ob);z++) { 
    if(!ob[z]->is_player()) destruct(ob[z]); 
  }
return 1; }


heart_beat() {
object obs;
int zz;
int zzz;
zzz = 0;
k = k + 1;
obs = all_inventory(this_object());
for(zz=0;zz<sizeof(obs);zz++) {
  if(obs[zz]->is_player()) {  
    zzz = 1;
    if(obs[zz]->query_ghost()) {
      obs[zz]->remove_ghost();
      obs[zz]->heal_self(10000);
      tell_object(obs[zz],"You have failed.  Try again.\n");
      obs[zz]->save_me();
      obs[zz]->homer;
      destruct(this_object());
    return 1; }
   }
 }
 if(!zzz) {
   destruct(this_object());
 return 1; }
}

init() {
  ::init();
  if(tl < 100) {
    if(!pp && tp->is_player()) { 
       tell_object(tp,"Something flashes!\n");
        tp->heal_self(-1000);
        move_object(tp,"/room/church.c"); 
        return 1;}
        if(pp && tp->is_player() && tgl != 9 && tl < 19 && tx < 5) {
          write(BOLD+BLINK+"\n\tYou Do Not Have Enough To Enter!!\n\n"+NORM);
        if(present("bold",tp)) { destruct(present("bold",tp)); }
        tp->set_home("/players/mythos/closed/guild/assembly.c");
        move_object(tp,"/room/church.c");
        fpl;
        tp->save_me();
        return 1; }
        if(pp && tp->is_player()) { pp->set_ggt(1);
        if(!present("bold",tp)) {
        move_object(clone_object("/players/mythos/closed/guild/task/horlach/bold.c"),
                    tp);
        tp->save_me(); } } }
    add_action("nnorth","north");
    add_action("eeast","east");
    add_action("sssouth","south");
    add_action("wwest","west");
    add_action("nne","northeast");
    add_action("nnw","northwest");
    add_action("sse","southeast");
    add_action("ssw","southwest");
}

nnorth() {
  if(a || b || c) return 0;
  cleanse();
  if(f) { aaa(); fpl; return 1; }
  if(d) { bbb(); fpl; return 1; }
  if(e) { ccc(); fpl; return 1; }
  if(g) { ddd(); fpl; return 1; }
  if(h) { eee(); fpl; return 1; }
  if(i) { fff(); fpl; return 1; }
  if(j) { iii(); fpl; return 1; }
}

eeast() {
  if(a || b || d || g || i || j) return 0;
  cleanse();
  if(c) { bbb(); fpl; return 1; }
  if(e) { ddd(); fpl; return 1; }
  if(f) { ddd(); fpl; return 1; }
  if(h) { ggg(); fpl; return 1; }
}

sssouth() {
  if(j) return 0;
  cleanse();
  if(a) { fff(); fpl; return 1; }
  if(b) { ddd(); fpl; return 1; }
  if(c) { eee(); fpl; return 1; }
  if(d) { ggg(); fpl; return 1; }
  if(e) { hhh(); fpl; return 1; }
  if(f) { iii(); fpl; return 1; }
  if(h) { jjj(); fpl; return 1; }
  if(g) { jjj(); fpl; return 1; }
  if(i) { jjj(); fpl; return 1; }
}

wwest() {
  if(a || c || e || h || i || j) return 0;
  cleanse();
  if(b) { ccc(); fpl; return 1; }
  if(d) { eee(); fpl; return 1; }
  if(f) { eee(); fpl; return 1; }
  if(g) { hhh(); fpl; return 1; }
}

nne() {
  if(a || b || e || d || g) return 0;
  cleanse();
  if(c) { aaa(); fpl; return 1; }
  if(f) { bbb(); fpl; return 1; }
  if(h) { fff(); fpl; return 1; }
  if(i) { ggg(); fpl; return 1; }
  if(j) { ggg(); fpl; return 1; }
}

nnw() {
  if(a || c || e || d || h) return 0;
  cleanse();
  if(b) { aaa(); fpl; return 1; }
  if(f) { ccc(); fpl; return 1; }
  if(g) { fff(); fpl; return 1; }
  if(i) { hhh(); fpl; return 1; }
  if(j) { hhh(); fpl; return 1; }
}

sse() {
  if(b || d || g || i || j) return 0;
  cleanse();
  if(a) { bbb(); fpl; return 1; }
  if(c) { fff(); fpl; return 1; }
  if(e) { fff(); fpl; return 1; }
  if(f) { ggg(); fpl; return 1; }
  if(h) { iii(); fpl; return 1; }
}

ssw() {
  if(c || e || h || i || j) return 0;
  cleanse();
  if(a) { ccc(); fpl; return 1; }
  if(b) { fff(); fpl; return 1; }
  if(d) { fff(); fpl; return 1; }
  if(f) { hhh(); fpl; return 1; }
  if(g) { iii(); fpl; return 1; }
}

aaa() {
  long_desc = aa;
  cen();
  a = 1; 
return 1; }

bbb() {
object post;
  long_desc = bb;
  cen();
  b = 1;
  post = clone_object("/players/mythos/closed/guild/task/horlach/post.c");
  post->set_alias("star ruby");
  post->set_short(RED+"* Star Ruby Post"+NORM);
  post->set_long("A post made of pure ruby.\n"+
                 "Deep within a white globe seems to glow.\n");
  move_object(post,this_object());
return 1; }

ccc() {
object post;
  long_desc = cc;
  cen();
  c = 1; 
  post = clone_object("/players/mythos/closed/guild/task/horlach/post.c");
  post->set_alias("pearl");
  post->set_short("Pearl Post");
  post->set_long("A post made of white gleaming pearl.\n"+
                 "The light scatters across it, creating\n"+
                 "a shimmering display of colors.\n");
  move_object(post,this_object());
return 1; }

ddd() {
object post;
  long_desc = dd;
  cen();
  d = 1; 
  post = clone_object("/players/mythos/closed/guild/task/horlach/post.c");
  post->set_alias("sapphire");
  post->set_short(CYN+"Sapphire Post"+NORM);
  post->set_long("A post made of pure sapphire.\n"+
                 "Blinding light reflects off it.\n");
  move_object(post,this_object());
return 1; } 

eee() {
object post;
  long_desc = ee;
  cen();
  e = 1;
  post = clone_object("/players/mythos/closed/guild/task/horlach/post.c");
  post->set_alias("ruby");
  post->set_short(HIR+"Ruby Post"+NORM);
  post->set_long("A post made of pure ruby.\n"+
                 "It glows with a light that makes\n"+
                 "all look drenched in blood.\n");
  move_object(post,this_object());
return 1; } 

fff() {
object horlach, altar;
  long_desc = ff;
  cen();
  f = 1;
  horlach = clone_object("/players/mythos/closed/guild/task/horlach/horlach.c");
  horlach->set_time(k);
  move_object(horlach,this_object());
  altar = clone_object("/players/mythos/closed/guild/task/horlach/stone.c");
  altar->set_time(k);
  move_object(altar,this_object());
return 1; }

ggg() {
object post;
  long_desc = gg;
  cen();
  g = 1; 
  post = clone_object("/players/mythos/closed/guild/task/horlach/post.c");
  post->set_alias("emerald");
  post->set_short(GRN+"Emerald Post"+NORM);
  post->set_long("A post made of pure emerald.\n"+
                 "A pulsating light is at its center.\n");
  move_object(post,this_object());
return 1; } 

hhh() {
object post;
  long_desc = hh;
  cen();
  h = 1; 
  post = clone_object("/players/mythos/closed/guild/task/horlach/post.c");
  post->set_alias("black opal");
  post->set_short(BOLD+"Black Opal Post"+NORM);
  post->set_long("A post made of ebony black opal.\n"+
                 "Darkness eminates from it.\n");
  move_object(post,this_object());
return 1; } 

iii() {
  long_desc = ii;
  cen();
  i = 1; 
return 1; }

jjj() {
  long_desc = jj;
  cen();
  j = 1; 
return 1; } 

cen() {
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  e = 0;
  f = 0;
  g = 0;
  h = 0;
  i = 0;
  j = 0;
return 1; }