inherit "obj/clean";

int use = 0;
string pow;

id(str) { return str=="eyes"; }
short() { return "Eyes of Fire"; }
long() {
   write("Eyes of Fire!\n");
}

howto() {
 write("Two large red sapphires rest in the palms of your hands.\n"+
  "They glow with luminescent beauty.  If you put them up to\n"+
  "your eyes and look out of them, you can do the following:\n"+
  "'view   [object on you / player logged on]'\n"+
  "'viewon [object on a player]'\n"+
  "Interesting things will be revealed to you.\n");
}

view(str) {
   object ob;
   int levthat;
   if (!str) {
      write("View what or who?\n"); return 1;}
   if(find_player(str)) {
      ob = find_player(str);
      levthat = ob->query_level();
      if (levthat >= 20) {
         queryw(); return 1;}
      queryp(str, ob);
      return 1;}
   if(find_living(str)) {
      ob = find_living(str);
      queryp(str, ob);
      return 1;}
   write("No "+str+" found.\n");
   return 1;
}

viewon(str) {
object ob;
string who, what;
if (!str) {
   write("Usage: Viewon [person] [object].\n"); return 1;}
if(!sscanf(str, "%s %s", who, what)) {
   write("Usage: Viewon [person] [object].\n");
   return 1;}
if((find_player(who)) && (find_player(who)->query_level() >= 20)) {
   queryw(); return 1;}
if(find_living(who) && present(what,find_living(who))) {
   ob = present(what, find_living(who));
   queryo(what, ob);
   return 1;}
else write("No "+what+" found on "+capitalize(who)+".\n");
return 1;
}

queryp(string str, object ob) {
write("Through the fiery eyes, you see:\n");
write("Stats of "+capitalize(str)+".\n");
write("True Name : "+ob->query_real_name()+"\n");
write("Level: "+ob->query_level()+"\n");
write("Max Hit Pts. : "+ob->query_mhp()+"\n");
write("Max Spell Pts. : "+ob->query_msp()+"\n");
check();
return 1;
}

queryo(string str, object ob) {
int num;
write("Through the fiery eyes, you see:\n");
write("Stats of "+capitalize(str)+".\n");
write("True Name : "+ob->query_name()+"\n");

num = ob->weapon_class();
querynumb(num);
write("WC : "+pow+"\n");

num = ob->armor_class();
querynumb(num);
write("AC : "+pow+"\n");

write("Value : "+ob->query_value()+"\n");
check();
return 1;
}

queryw() {
write("Through the fiery eyes, you see:\n");
write("A shimmer of light to intense for your mortal eyes!\n");
return 1;
}

string querynumb(int num) {
if (num <= -10) { pow = "greatly cursed!"; return pow; }
if (num <= -1)  { pow = "cursed!"; return pow; }
if (num ==  0)  { pow = "nothing"; return pow; }
if (num ==  1)  { pow = "ordinary"; return pow; }
if (num ==  2)  { pow = "enhanced"; return pow; }
if (num <=  4)  { pow = "sturdy"; return pow; }
if (num <=  6)  { pow = "strong"; return pow; }
if (num <=  8)  { pow = "special"; return pow; }
if (num <= 10)  { pow = "rare"; return pow; }
if (num <= 12)  { pow = "remarkable"; return pow; }
if (num <= 14)  { pow = "exceptional"; return pow; }
if (num == 15)  { pow = "amazing"; return pow; }
if (num == 16)  { pow = "incredible"; return pow; }
if (num == 17)  { pow = "monstrous"; return pow; }
if (num == 18)  { pow = "unearthly"; return pow; }
if (num == 19)  { pow = "godly"; return pow; }
if (num >= 20)  { pow = "beyond"; return pow; }
return pow;
}

int check() {
object obb;
   if(use > 0) {
     obb = present("eyes",this_player());
     if (obb) {
        destruct(obb);
        write("You exhaust the power of the eyes!\n");
        }
     else write("Corrupt data!\n");
     return 1;
     }
   use++;
   return 1;
}
