#include "../defs.h"

inherit WAXFUNS;

#define UNAUTHORIZED ((string)this_player()->query_real_name() != "earwax")
#define ME this_player()
#define HERE environment(this_player())
#define NAME call_other(this_player(),"query_name")
#define LEVEL call_other(this_player(),"query_level")
#define ULEV(LEV) (call_other(this_player(),"query_level") < LEV)
#define AAA(ACT,VERB) add_action(ACT);add_verb(VERB);
#define ADD(VERB) add_action(VERB);add_verb(VERB);
 
/* ======================================================================
 * Global Variables
 * ======================================================================
*/

object old_dest,ownob,gob,gob2,doob;
object glq0,glq1,glq2,glq3,glq4,glq5,glq6,glq7,glq8,glq9;
int gmax;
string sv_str,dofun,doarg;
 
/* ======================================================================
 * Item Setup
 * ======================================================================
*/

short() { return "The " + HIR + "King" + NORM + NORM + " of the " + HIR + "Q-Tips" + NORM + NORM; }
long() { write("Type '"+HIW+"waxhelp"+NORM+NORM+"' for the powers of this staff.\n"); return 1; }

reset(status arg) { return; }

query_value() { return 0; }

id(str) { return (str == "qtip" || str == "tool" || str == "wiztool" || str == "waxtool"); }

drop() {return 1;}
get() {return 1;}
 
init(){
  if UNAUTHORIZED {
    write("Only he who defeated the King of the Q-Tips can command him.\n");
    return;
  }

  ADD("panel")
  ADD("lizard");
  ADD("des")
  ADD("mov")
  ADD("patch")
  AAA("patch","p")
  ADD("list")
  AAA("list","lis")
  ADD("tel")
  ADD("pas")
  ADD("sob")
  ADD("rev")
}
 

des(str){
 if UNAUTHORIZED return 0;
 dofun="dodest";if (str) selob(str);

 return 1;
 }
 
list(str) {
 if UNAUTHORIZED return 0;
 if (!str) str="all in here";
 dofun="dolist";selob(str);
 return 1;
 }
 
tel(str) {
 string s1,s2;
 if UNAUTHORIZED return 0;
 if (sscanf(str,"%s,%s",s1,s2)!=2) {
  write("Format: tel object,message\n"); return 1; }
 dofun="dotell";doarg=s2;selob(s1);
 return 1;
 }
 
mov(str) {
 string s1,s2;
 if UNAUTHORIZED return 0;

 if (sscanf(str,"%s,%s",s1,s2)!=2) {
  write("Format: mov object1,object2\n"); return 1;}
 dofun="move1";doarg=s2;selob(s1);
 return 1;
 }
 
sob(str) {
 string s1,s2,s3;
 if UNAUTHORIZED return 0;
 if (sscanf(str,"%s=%s,%s",s1,s2,s3)==3) {
  doob=s1;dofun="dopas";doarg=s3;selob(s2);
  return 1;}
 if (sscanf(str,"%s=%s",s1,s2)==2) {
  doob=s1;dofun="dosob";selob(s2);
  return 1;}
 write("Format: sob ob1=object\n"+
       "    or: sob ob1=korg,query_soul\n"+
       "    or: sob ob1=test,obj_n,100\n");
 return 1;
 }
 
rev(str) {


 write("ob0="); listob(glq0); write("ob1="); listob(glq1);
 write("ob2="); listob(glq2); write("ob3="); listob(glq3);
 write("ob4="); listob(glq4); write("ob5="); listob(glq5);
 write("ob6="); listob(glq6); write("ob7="); listob(glq7);
 write("ob8="); listob(glq8); write("ob9="); listob(glq9);
 return 1;
 }
 
listob(ob) {
 string ss;
 if(!ob) { write("No object\n");return;}
 write(ob);
 ss=call_other(ob,"short");
 if (ss) write("\t"+ss+".\n"); else write("\tINVISIBLE OBJ\n");
 }
 
dopatch(str) {
 string fun,sarg,valu;
 int iarg;
 if (!gob) return;
if (sscanf(str,"%s,ob%d",fun,iarg)==2) { valu=call_other(gob,fun,obval(iarg));
   }

 if (sscanf(str,"%s,%d",fun,iarg)==2) { valu=call_other(gob,fun,iarg); }
 else if (sscanf(str,"%s,%s",fun,sarg)==2) { valu=call_other(gob,fun,sarg); }
 else { valu=call_other(gob,str); }
 write("Got: "+valu+"\n");
 }
dodest() {
 if (gob) {
  write("Dested: -->: ");
  listob(gob);
  if(living(gob)) {
    gob->set_heart_beat(0);
  }
  destruct(gob);
  }
 }
 
dolist() {
 string ss;

 if (gob) listob(gob);
 }
 
dotell(str) {
 string ss;
 if (gob) {
  tell_object(gob,str+"\n");
  ss=call_other(gob,"query_name");
  if (ss) { write("Told "+ss+": "+str+"\n"); }
  else {write("Told "); write(gob); write(": "+str+"\n"); }
  }
 }
 
move1(str) { gob2=gob;dofun="move2";selob(str);dofun="move1"; }
 
move2() {
 if (gob && gob2) {
  write("Moving "+call_other(gob2,"short")+" into "+
  call_other(gob,"short")+".\n");
  move_object(gob2,gob);
  }
 }


 
#define CHKST(NIM,VBL) else if(doob==NIM) VBL=gob;
dosob() {
 if (!gob) return;
 CHKST("ob0",glq0) CHKST("ob3",glq3) CHKST("ob6",glq6)  CHKST("ob9",glq9)
 CHKST("ob1",glq1) CHKST("ob4",glq4) CHKST("ob7",glq7)
 CHKST("ob2",glq2) CHKST("ob5",glq5) CHKST("ob8",glq8)
 else {write("set What?! (use: ob0 through ob9)\n"); return;}
 write("Set "+doob+" to object: "); listob(gob);
 }
 
dopas(str) {
 string fun,sarg;
 object vob;
 int iarg;
 if (!gob) return;
if (sscanf(str,"%s,ob%d",fun,iarg)==2) { vob=call_other(gob,fun,obval(iarg)); 
}
 if (sscanf(str,"%s,%d",fun,iarg)==2) { vob=call_other(gob,fun,iarg); }
else if (sscanf(str,"%s,%s",fun,sarg)==2) { vob=call_other(gob,fun,sarg); }
 else { vob=call_other(gob,str); }
 if(vob) gob=vob; dosob();

 }
 
obval(nn) {
 if(nn==0) return glq0;  if(nn==5) return glq5;
 if(nn==1) return glq1;  if(nn==6) return glq6;
 if(nn==2) return glq2;  if(nn==7) return glq7;
 if(nn==3) return glq3;  if(nn==8) return glq8;
 if(nn==4) return glq4;  if(nn==9) return glq9;
 }
 
selob(str) {
 object ob;
 string s1,s2,myfun,myarg;
 myfun=dofun;myarg=doarg;
 if (sscanf(str,"obj %s %s",s1,s2)==2) {
  ob=findob(s2);
  if (!ob) return;
  if (s1=="near") ob=environment(ob);
  gob=first_inventory(ob);
  gmax=50;
  showone();
  return;

  }
 if (sscanf(str,"all %s %s",s1,s2)==2) {
  ob=findob(s2);
  if (!ob) return;
  if (s1=="near") ob=environment(ob);
  gob=first_inventory(ob);
  gmax=200;
  while (gob && gmax > 0) {
   ob=next_inventory(gob);
   call_other(this_object(),myfun,myarg);
   gob=ob;gmax -= 1; }
  return;
  }
 gob=findob(str);
 if (gob) call_other(this_object(),myfun,myarg);
 }
 
findob(str) {
 object ob;
 string s1,s2;
 int nval;
 if (sscanf(str,"%s in %s",s1,s2)==2) {

  if (ob) ob=present(s1,ob);
  if (ob) return ob; }
 if (sscanf(str,"%s near %s",s1,s2)==2) {
  ob=findob(s2);
  if (ob) ob=present(s1,environment(ob));
 if (ob) return ob; }
 if (sscanf(str,"room of %s",s2)==1) {
  ob=findob(s2);
  if (ob) ob=environment(ob);
  if (ob) return ob; }
 if (str=="here") ob=HERE;
 if (str=="me") ob=ME;
 if (!ob) ob=present(str,ME);
 if (!ob) ob=present(str,HERE);
 if (!ob) ob=find_player(str);
 if (!ob) ob=find_living(str);
 if (!ob) ob=find_object(normalize_path(str, ME));
 if (!ob) {if (sscanf(str,"ob%d",nval)==1) ob=obval(nval);}
  if (!ob) ob=find_invis(str);
 if (!ob) write(str+" not found.\n");
 return ob;

 }

find_invis(str) {
  object user;
  int i, size;

  user = users();
  size = sizeof(user);
  for(i = 0; i < size; i++)
    if(user[i]->query_real_name() == str) return user[i];
}
 
showone() {
 string ss;
 if (gob && gmax>0) {
  listob(gob);
  write("This One? [ynq]:");
  input_to("thisone");
  }
 }
 

thisone(str) {
 if(str=="yes" || str=="y") { call_other(this_object(),dofun,doarg);return; }
 if (str=="q" || str=="quit" || str=="stop") {write("Aborted.\n");return; }
 gob=next_inventory(gob);gmax -= 1;
 showone();
 }

here(str){
 object ob;
 ob=present(str,ME);
 if(!ob) ob=present(str,HERE);
if (!ob) {
   if (HERE->id(str)) return 0;  
return 0; }
 return ob;
 }
 
wtmess(wt) {
if (wt>19) return "is incredibly heavy";
if (wt>14) return "is extremely heavy";
if (wt>11) return "is very very heavy";
if (wt>9) return "is very heavy";


if (wt>7) return "is heavy";
if (wt>5) return "is fairly heavy";
if (wt>4) return "is slightly heavy";
if (wt>3) return "is medium weight";
if (wt>2) return "is fairly light";
if (wt>1) return "is light";
return "is very light";
}
 
hpmess(hp) {
if(hp>200) return "is extremely tough";
if(hp>160) return "is in very good shape";
if(hp>120) return "is in good shape";
if(hp>80) return "is in fair shape";
if(hp>40) return "is in bad shape";
if(hp>10) return "is weak and frail";
return "is probably drawing his last breath";
}
 
panel(str){
int wiz;
 

write(
"Welcome, "+NAME+", to the Lizard Guild." +
" Your commands are VERY powerful.\n"+
"  COMMAND      DESCRIPTION\n"+
"patch LO,F,A  call function F in object LO with argument A\n"+
"tel LO,M      send raw message M to object LO\n"+
"mov LO1,LO2   move object LO1 into object LO2\n"+
"lis LO        list filename of object LO\n"+
"des LO        destroy object LO\n"+
"sob V=LO      set variable V to object LO\n"+
"sob V=LO,F,A  set variable V to object returned by function F in obj LO\n"+
"rev           shows current variable settings\n"+
"");
write(
"There are 10 variables to use for V: ob0 though ob9\n"+
"|--LO Formats---------" + 
"------|--SO Formats------------|---FILENAME Examples----|\n"+
"|SO          -Simple Object |" + 
"SO in SO   -Inside      |players/korg/entrance   |\n"+
"|obj in SO   -Selection List|" + 
"SO near SO -Near        |room/village/pub2      #|\n"+
"|obj near SO                |ro" +

"om of SO -Room of     |---ID Examples----------|\n"+
"|all in SO   -All objects   |" +
"FILENAME   -(filename)  |sword,bag,corpse 2,korg,|\n"+
"|all near SO               " +
" |ID         -(name or ID)|troll,me,here,ob0,ob9  #|\n"+
"|---------------------" + 
"------|------------------------|------------------------|\n"+
" # 'me' and 'here' are sp" + 
"ecial ID's which mean you and your current room.\n"+
"   'ob0' though 'ob9' are " +
"special ID's which refer to one of the 10 variables\n"+
"EXAMPLES:\n"+
"patch obj in me,set_id,gem  mov bag in room\church,korg  mov korg,here\n"+
"patch bag 2 in korg,long,0  mov sword in bag in korg,me  lis all in me\n"+
"patch here,reset,0    " +
"      mov me,room\village\pub2     lis room of korg\n"+
"tel all near me,Ding D" +
"ong!  mov me,room of korg          des obj near korg\n");
return 1; }

lizard() {
   write("panel            --- show old help message.\n");


   write("ptell            --- tell thru busy.\n");
   write("value/identify   --- show value info on object.\n");
   write("l                --- look at <object>.\n");
   write("hp               --- show hitpoints of <object>.\n");
   write("stat             --- show stats of <object>.\n");
   write("des              --- silent destruct.\n");
   write("mov              --- move object1 into object2.\n");
   write("patch            --- call_other into an object.\n");
   write("croak            --- quit the Lizardguild.\n");
   write("lis[t]           --- write filname of object.\n");
   write("tel              --- send raw message to object.\n");
   write("trans            --- move living object over here.\n");
   write("in               --- in pathname, execute command.\n");
write("\n\tFor more info on these commands, type \"panel\".\n");
return 1;
}
