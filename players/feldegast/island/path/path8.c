#include "/players/mythos/closed/ansi.h"
#define TPRN this_player()->query_real_name()
#define CAP(z) capitalize(z)
object targ;
is_bugged() {return 1;}
start(object ob) {
targ=ob;
shadow(ob,1);}
stop(object ob) {
shadow(ob,0);
destruct(this_object());}
int tell_us(string str){
object *user;
string msg;
int i;
user=users();
if(!str) { write("Clan <msg>\n"); return 1; }
msg = (string)TPRN;
if(str[0] == ':') msg=(RED+"[wizclan]"+NORM+" "+CAP(msg)+" "+NORM+str[1..(strlen(str) - 1)] + NORM + "\n");
else msg=(RED+"[wizclan]"+NORM+" "+CAP(msg)+" says: " + NORM + str + NORM +"\n");
for(i=0; i < sizeof(user); i++)
if(present("yackreceiver",user[i]))
tell_object(user[i],msg);
if(targ)
return (int)targ->tell_us(str);
else return 0;}
