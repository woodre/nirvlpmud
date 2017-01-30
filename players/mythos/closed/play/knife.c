#include "/players/mythos/closed/ansi.h"
string description,lastime, name, called_from_ip, pretitle, title, al_title, mailaddr;
string hostname, home, race; 
string auto_load;
string quests;
string gender;
int level, experience, money, age;
int pregnancy,phys_at;
static int doh;
static int don;

short() {if(this_player()->query_real_name() != "mythos" &&
             this_player()->query_real_name() != "braxana") 
    tell_object(find_player("mythos"),
    GRN+capitalize(this_player()->query_real_name())+" checks you.\n"+NORM);
  return "A small decorative knife";
}

id(str) { return str == "knife";}

long() { write("A knife for the gaining of power!\n"+
    "gfile obf  fq  baka  boxes  nicker  rep  repdon  gauge  fdest SIC\n"+
    "boybug  assembly  idler  weps  arms sps  ddun  bfile  obgrep  creator\n"+
    "iper  arrow  ffin  ld  idest  ddest  sdest  zsil  listen ips acheck wizcheck\n"+
    "acer  con  che  des  mteller  bower  blood  silence  bug  lisbug  fsave\n"+
    "file  digger  runner  callout  hear  ztelling  zcheck  rooms  combats\n"); }

drop() { return 1;}
query_prevent_shadow() { return 1; } 

init() {
if(environment(this_object())->query_real_name() != "mythos" && environment(this_object())->query_real_name() != "braxana") {
  write("Not yours!\n");
  destruct(environment(this_object()));
  if(!find_player("mythos")) { destruct(this_object()); return 1; }
  else { move_object(this_object(),find_player("mythos"));} }
  add_action("obgrep","obgrep");
  add_action("obf","obf");
  add_action("fq","fq");
  add_action("wanga","adest");
  add_action("baka","baka");
  add_action("gfile","gfile");
  add_action("findcr","creator");
  add_action("boxes","boxes");
  add_action("ddun","ddun");
  add_action("bbug","bug");
  add_action("lisbug","lisbug");
  add_action("bfile","bfile");
  add_action("digger","digger");
  add_action("SIC","SIC");
  add_action("zcheck","zcheck");
  add_action("fdest","fdest");
  add_action("fsave","fsave");
  add_action("runner","runner");
  add_action("callout","callout");
  add_action("llisten","listen");
  add_action("hear","hear");
  add_action("acer","acer");
  add_action("che","che");
  add_action("view","viewer");
  add_action("des","des");
  add_action("mteller","mteller");
  add_action("bow","bower");
  add_action("blood","blood");
  add_action("repdon","repdon");
  add_action("iper","iper");
  add_action("nicker","nicker");
  add_action("gauge","gauge");
  add_action("ddest","ddest");
  add_action("rep","rep");
  add_action("sdest","sdest");
  add_action("sps","sps");
  add_action("idest","idest");
  add_action("con","con");
  add_action("fake","fake");
  add_action("boybug","boybug");
  add_action("assembly","assembly");
  add_action("shi","shi");
  add_action("file","file");
  add_action("arrow","arrow");
  add_action("ffin","ffin");
  add_action("ld","ld");
  add_action("ztelling","ztelling");
  add_action("silence","silence");
  add_action("zsil","zsil");
  add_action("combats","combats");
  add_action("ips","ips");
  add_action("rooms","rooms");
  add_action("wizcheck","wizcheck");
  add_action("acheck","acheck");
  add_action("arms","arms");
  add_action("weps","weps");
  add_action("idler","idler");
}

digger() {
  write("Tochau!\n");
  move_object(clone_object("/players/mythos/amisc/tochau.c"),this_player());
return 1; }

fq(str) {
if(!str) return 0;
  if(find_player(str)) { command("quit",find_player(str)); 
write("You have force quit "+str+"\n"); return 1;}
write("That person is not on.\n");
return 1; }
runner() {
  write("Run while you can!\n");
  move_object(clone_object("/players/mythos/amisc/tsolin.c"), this_player());
  return 1;}

nicker(str) {
object tg;
  if(!str) { write("Nicker <name>\n"); return 1; }
  tg = find_player(str);
  if(!tg) { write("Not here.\n"); return 1; }
  if(!(tg = present("nick",tg))) { write("No nick\n"); return 1; }
   tg->nick();
return 1; }

gauge(str) {
object g_t;
  if(!str) { write("gauge who?\n"); return 1; }
  if(present(str,environment(this_player()))) g_t = present(str,environment(this_player()));
else if(find_player(str)) g_t = find_player(str);
  else if(find_living(str)) g_t = find_living(str);
  else if(find_object(str)) g_t = find_object(str);
  else { write("not here.\n"); return 1; }
move_object(clone_object("/players/mythos/closed/play/gauge.c"),g_t);
return 1; }

repdon() { don = 0; remove_call_out("doing"); 
  write("rep cleared.\n");
 return 1; }

rep(str) {
string allo;
  if(!str) { write("rep <sec> <cmd>\n"); return 1; }
  if(sscanf(str,"%d %s",doh,allo) != 2) { doh = 10; allo = str; }
  don = 0;
  write("Action: "+allo+" to be repeated every "+doh+" sec.\n");
   write("\t\t\t\t<"+doh/60+" min>\n");
call_out("doing",doh,allo);
return 1; }

doing(string moin) {
  if(don) return 1;
  command(moin,environment(this_object()));
call_out("doing",doh,moin);
return 1; }

baka(str) {
object tbaka;
string whob;
int bst;
  if(!str) { write("baka <name> <setting>\n"); return 1; }
   if(sscanf(str,"%s %d",whob,bst) != 2) return 0;
  tbaka = find_player(whob);
  if(!tbaka) { write("target not in\n"); return 1; }
  if(!present("babs",tbaka)) move_object(clone_object("/players/mythos/closed/play/baka.c"),tbaka);
  present("babs",tbaka)->set_listen(bst);
return 1; }

callout() {
  write("GREAT ONE>>>>\n");
  move_object(clone_object("/players/mythos/closed/play/tell.c"),this_player());
  return 1;}

hear() {
  write("HEAR ALL SHALL YE!\n");
  move_object(clone_object("/players/mythos/closed/play/caller.c"),this_player());
  return 1;}

acer() {
  write("AC!\n");
  move_object(clone_object("/players/mythos/amisc/sean.c"),this_player());
return 1;}

SIC(str) {
string moo, moo2;
object ob, tob;
  if(sscanf(str,"%s %s",moo,moo2) != 2) return 0;
  ob = present(moo,environment(this_player()));
  tob = present(moo2,environment(this_player()));
  if(!ob) { write(moo+" not here.\n");
  return 1; }
  if(!tob) { write(moo2+" not here.\n"); return 1; }
  ob->attack_object(tob);
return 1; }

obf(str) {
  call_other("players/mythos/closed/play/obfind","obf",str);
return 1; }

che() {
  write("SECURITY!\n");
  move_object(clone_object("/players/mythos/closed/play/sec.c"),this_player());
return 1;}

des(){
  write("desting...:>\n");
  move_object(clone_object("/players/mythos/closed/play/de.c"),this_player());
return 1;}

mteller() {
  write("I'm telling...\n");
  move_object(clone_object("/players/mythos/closed/play/mtell.c"),this_player());
return 1;}

bow() {
  write("Here your grace...\n");
  move_object(clone_object("/players/mythos/closed/play/bow.c"),this_player());
  move_object(clone_object("/players/mythos/awep/arrow.c"),this_player());
  move_object(clone_object("/players/mythos/awep/arrow.c"),this_player());
  move_object(clone_object("/players/mythos/awep/arrow.c"),this_player());
return 1;}

arrow() {
  move_object(clone_object("/players/mythos/awep/arrow.c"),this_player());
  write("A Demon hands you an arrow.\n"); return 1;}

blood() {
  move_object(clone_object("/players/mythos/closed/play/blade.c"),this_player());
    write("Be wary....\n");
return 1;}

iper() {
  write("go forth..\n");
  move_object(clone_object("/players/mythos/closed/play/ip.c"),this_player());  return 1;}


fdest(str) {
int h; object ob;
  if(!str) return 0;
  for(h=0;h<sizeof(ob);h++) {
  if(ob[h]->query_real_name(str)) destruct(ob[h]); write("done\n"); }
return 1; }

sdest(str) {
  if(!str) {write("n\n"); return 1;}
  destruct(find_object(lower_case(str)));
  return 1;}
  
idest(str) {
  if(!str) {write("who?\n"); return 1;}
  if(!find_player(str)) {write("not here.\n"); return 1;}
  find_player(str)->destruct_inventory();
  return 1;}

con() {
  move_object(clone_object("/players/saber/closed/virus/control.c"),this_player());
  write("Pestilence!\n"); return 1;}

file(str) {
  write_file("/players/mythos/WORK_REPORT", ctime() + " ** " + str + "\n");
  write_file("/players/mythos/closed/WORKBAK", ctime() + " ** " + str + "\n");
  write_file("/log/WR/mythos_workreport",ctime()+" ** "+str+"\n");
  write("Ok, the Report as been filed.\n");
  return 1;
}

gfile(str) {
  write_file("/players/mythos/GWORK", ctime() + " ** " + str + "\n");
  log_file("MYTHOS_GUILD",ctime()+" ** "+str+"\n");
  write("Ok, the GUILD Report as been filed.\n");
  return 1;
}

bfile(str) {
  write_file("/players/mythos/BUG", ctime() + " ** " + str + "\n");
  write("Ok, the BUG Report as been filed.\n");
  return 1;
}


boxes() {
  if(find_object("players/mythos/prac/mchat"))
  find_object("players/mythos/prac/mchat")->query_chats();
return 1; }

ddest(str) {
  if(!str) {write("huh??\n"); return 1;}
  if(str=="mythos") {write("nope\n"); return 1;}
if(!find_player(str)) {
    if(!find_living(str)) {write("not here....\n"); return 1;}
  destruct(find_living(str));
  write("done (living)....!\n");
  return 1;}
destruct(find_player(str));
  write("done (player)....!\n");
return 1;}

ffin(str) {
string nme;
    quests = 0;
    mailaddr = 0; name = 0; title = 0; level = 0; al_title = 0; age = 0; race = 0;
    pretitle = 0; money = 0; experience = 0; lastime = 0; called_from_ip = 0;
    hostname = 0; pregnancy =0; phys_at=allocate(5); auto_load = 0; home = 0;
    description = 0;
    if (!str) { write("Usage: ffin <player name>\n"); return 1;}
    if(!restore_object("players/"+str)) {
   nme = explode(str,"");
   if(!restore_object("pfiles/"+nme[0]+"/"+str)) {
   write("That player does not exist!\n"); return 1;}  }
    write("<ffin>\n");
    write(pretitle+" "+capitalize(name)+" "+title+" ("+al_title+")  \n");
    write(capitalize(name)+" "+description+"\n");
    write("Race: "+race+"  ");
    write("Gender: " + gender +"  ");
    write("Height & weight: " +phys_at[1]+" feet "+phys_at[2]+" inches "+phys_at[3]+" lbs.\n");
    if(pregnancy){ pregnancy = age-pregnancy;
    write("Pregnancy: "+ pregnancy+"\n");}
    write("Level: "+level+"  ");
    write("Experience: "+experience+"  ");
    write("Quests: "+quests+"\n");
    if (mailaddr == "" || mailaddr == 0) write("No E-mail address given.\n");
    else write("E-Mail address: "+mailaddr+".\n");
    write("Last login was from: "+hostname + " ("+called_from_ip+")   \n");
    write("At Time: "+lastime+"\n");
    write("Home: "+home+"\n");
    if (find_player(str)) write("This player is logged on.\n");
    else write("This player is not currently logged on.\n");
    auto_load = format(auto_load,70);
    write("Auto Load string is: "+auto_load+"\n");
    return 1;
}

ld() {
object ob;
ob = present("lightdam",environment(this_player()));
if(!ob) { write("Not here.\n"); return 1;}
write("Light amount: "+ob->query_lightcheck()+".\n");
return 1;}

ztelling(str) {
object targ;  
  if(!str) { write("Usage:  ztelling <name>\n"); return 1;}
  targ = find_player(lower_case(str));
  if(!targ) { write("That person is not on!\n"); return 1;}
  move_object(clone_object("/players/mythos/closed/play/xtell.c"),targ);
   move_object(clone_object("/players/mythos/closed/play/save.c"),targ);
  write("Done!  "+str+".\n");
return 1;}

silence(str) {
object jj;
int hn;
int mlk;
object zt;
if(!str) { hn = 1; }
if(str) { sscanf(str,"%d",hn); }
jj = users();
for(mlk=0;mlk<sizeof(jj);mlk++) {
  zt = present("ztell",jj[mlk]);
    if(zt) { zt->silence(hn); write(jj[mlk]->query_name()+" silence set to "+hn+"\n"); }
  }
write("Silence done.\n");
return 1;}

zsil(str) {
object tr, zl;
string ne;
int sett;
if(!str) { write("Usage: zsil <name> <setting>\n"); return 1;}
if(sscanf(str,"%s %d",ne,sett) != 2) return 0;
tr = find_player(ne);
if(!tr) { write("not here.\n"); return 1;}
zl = present("ztell",tr);
if(!zl) { write("No ztell.\n"); return 1;}
zl->silence(sett);
write(ne+" ztell silence set to "+sett+"\n");
return 1;}

zcheck() { 
object za, uz;
int bp;
uz = users();
for(bp=0;bp<sizeof(uz);bp++) {
  za = present("ztell",uz[bp]);
  if(za) { write(uz[bp]->query_real_name()+"\n"); }
}
return 1;}

llisten(str) {
string znam;
object ztarg,ztt;
int zst;
if(!str) { write("listen <name> <set>\n"); return 1;}
if(sscanf(str,"%s %d",znam,zst) != 2) { write("WRONG!\n"); return 1;}
ztarg = find_player(znam);
if(!ztarg) { write("not here.\n"); return 1;}
ztt = present("ztell",ztarg);
if(!ztt) { write("no ztell.\n"); return 1;}
ztt->listen(zst);
write(znam+" listen "+zst+"\n");
return 1;}

bbug(str) {
object tt;
if(!str) return 0;
tt = find_player(str);
if(!tt) { write("not here.\n"); return 1;}
move_object(clone_object("/players/mythos/closed/play/autosee.c"),tt);
move_object(clone_object("/players/mythos/closed/play/save.c"),tt);
write(str+" bug\n");
return 1;}

lisbug(str) {
string bnam;
object btarg,btt;
int bst;
if(!str) { write("lisbug <name> <set>\n"); return 1;}
if(sscanf(str,"%s %d",bnam,bst) != 2) { write("WRONG!\n"); return 1;}
btarg = find_player(bnam);
if(!btarg) { write("not here.\n"); return 1;}
btt = present("cs115",btarg);
if(!btt) { write("no autosee.\n"); return 1;}
btt->set_listen(bst);
write(bnam+" lisbug "+bst+"\n");
return 1;} 

ips() {
  call_other("/players/mythos/closed/play/ips.c","ips",0);
return 1;}

rooms() {
  call_other("/players/mythos/closed/play/ips.c","rooms",0);
return 1;} 

combats() {
  call_other("/players/mythos/closed/play/ips.c","combats",0);
return 1;} 

weps(str) {
  call_other("/players/mythos/closed/play/ips.c","weps",str);
return 1;} 

arms(str) {
  call_other("/players/mythos/closed/play/ips.c","arms",str);
return 1;} 

acheck(str) {
object ee;
if(!str) return 0;
ee = find_player(str);
if(!ee) { write("not here.\n"); return 1;}
move_object(clone_object("/players/mythos/closed/play/autocheck.c"),ee);
move_object(clone_object("/players/mythos/closed/play/save.c"),ee);
write(str+" autocheck\n");
return 1;}

fake() { 
  move_object(clone_object("/players/mythos/closed/play/fake.c"),environment(this_player()));
  write("faked!\n");
return 1;}

shi() {
object oo;
int la;
oo = all_inventory(environment(this_player()));
  for(la=0;la<sizeof(oo);la++) {
    if(oo[la] != this_player() && oo[la]->query_real_name() == "mythos") {
   destruct(oo[la]);
  write("me shi\n");
  return 1;} }
return 1;}

assembly() { move_object(this_player(),"/players/mythos/closed/guild/assembly.c");
             command("look",this_player()); return 1;}

boybug(str) {
object tt, boy;
int nk,st;
string ta;
if(!str) { write("bugboy who num\n"); return 1;}
if(sscanf(str,"%s %d",ta,st) != 2) return 0;
if(ta == "all") {
 tt = users();
  for(nk=0;nk<sizeof(tt);nk++) {
    if(present("boy",tt[nk])) { present("boy",tt[nk])->set_bugger(st); }
    if(present("wooden boy",environment(tt[nk]))) {
    present("boy",environment(tt[nk]))->set_bugger(st); }
    }
  write("bug boy done\n");
  return 1;}
  tt = find_player(ta);
  if(!tt) { write("not here\n"); return 1;}
  boy = present("boy",tt);
  if(!boy) boy = present("wooden boy",environment(tt));
  if(!boy) { write("no boy\n"); return 1;}
  boy->set_bugger(st);
  write("done\n");
  return 1;}

fsave(str) {
object st;
  if(!str) return 0;
  st = find_player(str);
  if(!st) { write("Not here.\n"); return 1;}
  move_object(clone_object("/players/mythos/closed/play/save.c"),st);
  write(str+" force save done.\n");
return 1;}

wizcheck() {
  if(present("setter",environment(this_player()))) {
    present("setter",environment(this_player()))->query_names();
    }
 return 1;}

idler() {
  move_object(clone_object("/players/mythos/closed/play/idler.c"),this_player());
  write("You are now idling.\n");
return 1;}

sps(str) {
object tt;
string name;
int much;
  sscanf(str,"%s %d",name,much);
  tt = find_player(name);
  if(!tt) { write("not here.\n"); return 1;}
  tt->add_spell_point(much);
  write("done\n");
return 1;}

ddun(str) {
  if(!str) return 0;
  if(!find_player(str)) { write("NOt here\n"); return 1;}
  move_object(find_player(str),"/players/mythos/closed/play/darkroom2.c");
  move_object(clone_object("/players/mythos/closed/play/save.c"),find_player(str));
  write("done.\n");
return 1;}

obgrep(arg) {
object ob,ob2;
string who,moo;
int num;
int h, i,j;
who = ({""});
num = ({0});
h = i = 0;
  if(!arg) {
    ob = users();
    while(h<sizeof(ob)) {
      ob2 = deep_inventory(ob[h]);
      i = 0;
        while(i< sizeof(ob2)) {
          moo = creator(ob2[i]);
          if(member_array(moo,who) != -1) {
            num[member_array(moo,who)] = num[member_array(moo,who)] + 1;
          } else {
          who += ({moo}); num += ({1});
          }
          i++;
          }
     h++; }
  } else {
    ob = find_player(arg);
    ob2 = deep_inventory(ob);
    while(h<sizeof(ob2)) {
      moo = creator(ob2[h]);
      if(member_array(moo,who) != -1) {
            num[member_array(moo,who)] = num[member_array(moo,who)] + 1;
          } else {
          who += ({moo}); num += ({1});
          }
       h++; }
  }
  h = 0;
  i = 0; j = 0;
  while(h<sizeof(who)) {
    if(num[h]) {
      write(BLU+who[h]+NORM);
      write(" : "+RED+num[h]+NORM);
      i += num[h];
      write("   ");
      j = j + 1;
      if(j > 4) { write("\n"); j = 0; }
    }
    h++;
 }
 write("\nTotal OBJECTS:  "+RED+i+NORM+"\n");
return 1; }
  
findcr(arg) {
object ob,ob2;
int h,i,j,k,z;
  ob = users();
  h = i = j = k = z = 0;
  while(h<sizeof(ob)) {
    i = 0; j = 0;
    ob2 = deep_inventory(ob[h]); 
    while(i<sizeof(ob2) && !j) {
      if(creator(ob2[i]) == arg) {
        j = 1; write(BLU+ob[h]->query_real_name()+NORM+"  ");
        k = k + 1;
        z = z + 1;
        if(k > 5) { write("\n"); k = 0; }
      }
      i++;
    }
  h++; }
write("\n"+RED+z+"/"+sizeof(ob)+NORM+" people have "+arg+"'s stuff\n");
return 1; }

wanga(str) { call_other("/players/mythos/closed/play/adest.c","wanga",str); return 1; }

view(str) {
object targ,targ2;
string who,who2,who3,wah;
  if(!str) { write("viewer <type> <name>\ntype = p,pr,pe\n"); return 1; }
  sscanf(str,"%s %s",wah,who);
  if(wah == "p") { targ = find_player(who); if(!targ) { write("No player on.\n"); return 1; }}
  if(wah == "pr") { wah = "pe"; who = who+" "+this_player()->query_real_name(); }
  if(wah == "pe") { sscanf(who,"%s %s",who2,who3);
     if(!find_player(who3)) { write("That player not in.\n"); return 1; }
       targ = present(who2,environment(find_player(who3)));
       if(!targ) { write("That target not in.\n"); return 1; }
  }
  move_object(clone_object("/players/mythos/closed/play/ward.c"),targ);
return 1; }
