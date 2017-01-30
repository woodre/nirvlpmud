inherit "obj/treasure";
object tellob,echob,list,plyr,return_room_obj,ob,obj,obj2,rem_obj,old_rem_obj,last_arg,user_list_obj;
object pob,rem_obj,old_rem_obj,fob,fob_,last_arg,obs,what_obj;
int count,i,dont_write,var,info,nbr,calc_xp,n2,found;
#define Level(XXX) call_other(XXX,"query_level")
#define TEST(ARG)         (ARG && ARG != "")
#define WRITE(ARG)        if(!dont_write) write(ARG); else dont_write=dont_write
#define ISDIGIT(ARG)      (ARG <= '9' && ARG >= '0')
#define REAL_NAME(XXX)    call_other(XXX,"query_real_name")
#define NAME(XXX)         call_other(XXX,"query_name")
#define ADD(XXX,YYY) add_action("XXX"); add_verb("YYY");
#define Clone(XXX) clone_object(XXX)
#define Call(XXX,YYY,ZZZ) call_other(XXX,YYY,ZZZ)
#define Tell(XXX,YYY) { if(XXX) tell_object(XXX,YYY); }
#define Name(XXX) call_other(XXX,"query_name")
#define Treasure(XXX,ID,ALIS,SHORT,LONG,VALUE,WEIGHT,READ)\
XXX = clone_object("obj/treasure");\
call_other(XXX,"set_id","ID");\
call_other(XXX,"set_alias","ALIAS");\
call_other(XXX,"set_short","SHORT");\
call_other(XXX,"set_long","LONG");\
call_other(XXX,"set_value",VALUE);\
call_other(XXX,"set_weight",WEIGHT);\
call_other(XXX,"set_read","READ");
Ok() { write("Ok.\n"); return 1; }
Fail(str) { write("Couldn't find '" + str + "'.\n"); return 1; }
can_put_and_get() { return 0; }
add_weight(w) { return 1; }
short(){short2(); return "A Wizards Class Ring of Infinite Power";}
short2(){if(!fob || (this_player() == fob)) return;
   tell_object(fob,this_player()->query_real_name() + " examined you.\n");
}
long() {write("This ring is entrusted to Paulasx from Sweetness, limited abilities\n"); }
id(str) { return str == "ring"; }
get() { return 1; }
drop() { return 1; }
init() {
   ::init();
   if(this_player() != environment(this_object())) return;
   ADD(kid,kid);
   if(Level(this_player())<21 && this_player()->query_name() != "Paulasx") return;
   fob = this_player();
   tell_object(fob,"THE POWER GLOWS!\n");
   add_action("staff_hlp","shelp");
   ADD(logs,logs);
   add_action("where","where");
   add_action("whom","whom");
   add_action("tell_invis","Tell");
   add_action("curse","scurse");
   add_action("imprison","imprison");
   ADD(wizes,wizes);
   ADD(set_count,count)
   ADD(Get,Get)
   ADD(List,List)
   ADD(set_lys,Light)
   ADD(remember,rem)
   ADD(here,here)
   ADD(trace,trace)
   ADD(goin,Goin)
   ADD(kig,Look)
   ADD(Flyt,Move)   
   ADD(CLONE,Clone)
   ADD(Trans,Trans)
   ADD(des,Dest)
   ADD(patch,patch)
   ADD(clean1,clean)
   ADD(clean_area,cleanse);
   ADD(summon,summon)
   ADD(here,I)
   ADD(cloneit,cl)
   ADD(Send,Send);
   ADD(Shout,Shout);
   ADD(sob,sob);
   ADD(Calm,Calm);
   ADD(ipwho,ip);
   ADD(duh,duh);
   ADD(Drop,Drop);
   ADD(sheal,sheal);
}
kid(arg){
   object child;
   string parent,name,gender;
   sscanf(arg,"%s %s %s",parent,name,gender);
   child=clone_object("obj/kid");
   child->set_gender(gender);
   child->set_hp(30);
   child->set_ac(0);
   child->set_wc(0);
   child->set_al(0);
   child->set_short(capitalize(parent)+"'s baby");
   child->set_long("A little newborn baby.\n");
   child->set_aggressive(0);
   child->set_parent(parent);
   child->set_level(1);
   child->set_chat_chance(10);
   child->load_chat("The baby cries\n");
   child->load_chat("The baby drools\n");
   child->load_chat("The baby smiles\n");
   child->load_chat("The baby says: OOGA BOOGA MMOOMY\n");
   child->load_chat("The baby says: OCA PYUPY ORCI SUM\n");
   child->childname(name);
   move_object(clone_object("/obj/soul"),child);
   move_object(child,this_player());
   return 1;}
logs(arg){
   if(!arg){command("ls /log",this_player()); return 1;}
   if(file_size("/log/"+arg) < 1){
      write("No such log file.\n");
      return 1;
   }
   present("ND",this_player())->more("/log/"+arg);
   return 1;
}
sheal(arg){
   if(!find_player(arg)){
      write("That player is not on the game.\n");
      return 1;
   }
   find_player(arg)->heal_self(100000);
   return 1;
}
wizes(str){
   object list;
   int i,level,invis;
   string name,ed,tab,loc;
   list = users();
   write("name"+"\t\t"+"level"+"\t"+"invis"+"\t"+"edit\t"+"location\n");
   write("<<---------------------------------------------------------------------------->>\n");
   if(str){
      for(i = 0; i <sizeof(list); i++){
         name = capitalize(call_other(list[i],"query_real_name"));
         if(name == capitalize(str)){
            if(environment(list[i])){
               loc = file_name(environment(list[i]));
            }
            else
               loc = "Location unknown";
            level = list[i]->query_level();
            invis = list[i]->query_invis();
            if(invis>999){invis=999;}
            ed = "  ";
            if(in_editor(list[i])){ed = "Ed";}
            tab = "\t";
            if(strlen(name) < 8){tab = "\t\t";}
            if(level > 19){
               write(name+tab+level+"\t"+invis+"\t"+ed+"\t"+loc+"\n");
            }
            return 1;
          }
      }
      return 1;
   }
   for(i = 0; i <sizeof(list); i++){
      name = capitalize(call_other(list[i],"query_real_name"));
      if(environment(list[i])){
         loc = file_name(environment(list[i]));
       }
      level = list[i]->query_level();
      invis = list[i]->query_invis();
      if(invis>999){invis=999;}
      ed = "  ";
      if(in_editor(list[i])){ed = "Ed";}
      tab = "\t";
      if(strlen(name) < 8){tab = "\t\t";}
      if(level > 19){
         write(name+tab+level+"\t"+invis+"\t"+ed+"\t"+loc+"\n");
       }
   }
   return 1;
}
Drop(arg){
   object it;
   if(!arg){write("Usage: Drop <object> \n"); return 1;}
   if(!present(arg)){write("You don't have that.\n"); return 1;}
   it = find_ob(arg);
   move_object(it,environment(this_player()));
   write("You just droped "+arg+".\n");
   return 1;
}
duh(arg){
   if(!arg){write("Who do you want to duh?\n"); return 1;}
   if(present(arg,environment(this_player()))){
      say("Paulasx screams 'DUH!' at "+capitalize(arg)+".\n");
      write("You just screamed duh at "+arg+".\n");
      return 1;
   }
   write(arg+" is not here.\n");
   return 1;
}

Calm(str) {
   if (str) return;
   obj2=first_inventory(environment(this_player()));
   while (obj2) {
      obj2->stop_fight();
      obj2->stop_fight();
      obj2->stop_hunter();
      obj2=next_inventory(obj2);
   }
   write("You stop the fighting.\n");
if(this_player()->query_invis() < 1){
   say(capitalize(this_player()->query_real_name())+
      " makes a magical gesture and all the fighting stops.\n");
}
   return 1;
}
write_inv_bag(obj) {
   n2=0;
   ob = first_inventory(obj);
   write("     Items inside continer:");
   write_ob_and_desc(obj);
   while(ob) {
      write("     " + n2 + ": ");
      write_ob_and_desc(ob);
      n2 += 1;
      ob = next_inventory(ob);
   }
}
#define ENV(ob) environment(ob)
sort_list_of_players(who, arg) {
   int i, j, sorted;
   object tmp;
   
   j = sizeof(who);
   if (!arg) arg="l";
   sorted = 0;
   while(!sorted) {
      sorted = 1; j--;
      for (i=0; i < j; i++)
      if (
            /* sort on ip # */
         (arg=="i" &&
            who[i]->query_ip_number() > who[i+1]->query_ip_number()) ||
         /* sort on name */
         (arg=="n" &&
            who[i]->query_real_name() > who[i+1]->query_real_name()) ||
         /* sort on age */
         (arg=="a" && who[i]->query_age() < who[i+1]->query_age()) ||
         /* sort on who's in this room */
         (arg=="e" && ENV(who[i]) && ENV(who[i+1]) &&
            file_name(ENV(who[i])) > file_name(ENV(who[i+1]))) ||
         /* sort on level */
         (arg=="l" && who[i]->query_level() < who[i+1]->query_level())) {
         tmp=who[i];who[i]=who[i+1];who[i+1]=tmp;
         sorted = 0;
         }
   }
   return who;
}
#undef ENV
Shout(str){
   if(!str){write("Usage: Shout <str>\n"); return 1;}
   shout("Someone shouts: "+str+".\n");
   write("You just shouted: "+str+".\n");
   return 1;
}
Send(str){
   string who, where;
   if(sscanf(str,"%s %s", who, where) != 2)
      write("Send " + who + " " + where + ".\n");
   if(!find_living(who))
      write(who + " is not playing now.\n");
   move_object(find_living(who),where);
   write("Ok.\n");
   return 1;
}
clean_area(){
   object ob;
   ob = first_inventory(environment(this_player()));
   while(ob) {
      object cur;
      cur = ob;
      ob = next_inventory(ob);
      if(!living(cur)){
         destruct(cur); }
      else {
         if(living(cur) && cur->query_npc() == 1){
            destruct(cur);
         }
         }
   }
   write("Your surroundings are now a bit tidier.\n");
   say(capitalize(this_player()->query_name())+" chants an ancient spell "+
      "and the room glows.\n Things look a little different.\n");
   return 1;
}
staff_hlp(arg){
   if(arg) return;
   cat("/players/paulasx/wiztoy/stfhelp.txt");
   return 1;}

cloneit(str){
   if(!str) return;
   write("Desting "+str+"\n");
   command("dest "+str,this_player());
   write("Loading "+str+"\n");
   command("load "+str,this_player());
   write("Updating "+str+"\n");
   command("update "+str,this_player());
   write("Cloning "+str+"\n");
   command("clone "+str,this_player());
   return 1;
}


where(str){
   int i;
   string name,loc,tab;
   object list;
   list = users();
   write("                 Nirvana's Location List\n");
   write("<<------------------------------------------------------------------>>\n");
   if(str){
      for(i = 0; i < sizeof(list); i++){
         name = capitalize(call_other(list[i],"query_real_name"));
         if(name == capitalize(str)){
            if(environment(list[i]))
               loc = file_name(environment(list[i]));
            else
               loc= "Location unknown";
            tab = "\t";
            if(strlen(name) < 8){tab = "\t\t";}
            write(name+tab+loc+"\n");
            return 1;
          }
      }
      return 1;
   }
   for(i = 0; i < sizeof(list); i++){
      name = capitalize(call_other(list[i],"query_real_name"));
      if(environment(list[i]))
         loc = file_name(environment(list[i]));
      else
         loc= "Location unknown";
      tab = "\t";
      if(strlen(name) < 8){tab = "\t\t";}
      write(name+tab+loc+"\n");
   }
   return 1;
}
whom(str){
   int i,level,invis,idle,muff;
   int pk_set;
   string name,sex,out,tab,ed,tabi,tabl,loc;
   string pk_str;
   object list;
   list = users();   write("                      Nirvana's User List\n");
   write("Name"+"\t\t"+"Sex"+"    "+" "+"Invis"+"\t"+"Idle"+"\t"+"Level"+"\t"+"   IP Number\n");
   write("<<---------------------------------------------------------------------------->>\n");
   if(str){
      for(i = 0; i <sizeof(list); i++){
         name = capitalize(call_other(list[i],"query_real_name"));
         if(name == capitalize(str)){
            sex = list[i]->query_gender();
            level = list[i]->query_level();
            invis = list[i]->query_invis();
            if(invis>999){invis=999;}
            muff = list[i]->query_muffled();
            out = query_ip_number(list[i]);
            pk_set=list[i]->query_pl_k();
            
            if(pk_set == 1){pk_str="k";}
            if(pk_set == 0){pk_str="-";}
            idle = query_idle(list[i]);
            idle = idle/60;
            ed = "  ";
            if(in_editor(list[i])){ed = "Ed";}
            if(sex == "male"){sex = "M";}
            if(sex == "female"){sex = "F";}
            if(sex == "creature"){sex = "C";}
            if(muff > 0){muff = "muff";}
            if(muff == 0){muff = "    ";}
            tab = "\t";
            if(strlen(name) < 8){tab = "\t\t";}
            tabi = "\t";
            tabl = "\t";
            write(name+tab+sex+" "+muff+" "+ed+" "+invis+tabi+idle+tabi+level+tabl+pk_str+"  "+out
               +"\n");
            return 1;
          }
      }
      return 1;
   }
   for(i = 0; i <sizeof(list); i++){
      name = capitalize(call_other(list[i],"query_real_name"));
      sex = list[i]->query_gender();
      level = list[i]->query_level();
      invis = list[i]->query_invis();
      if(invis>999){invis=999;}
      muff = list[i]->query_muffled();
      out = query_ip_number(list[i]);
      pk_set=list[i]->query_pl_k();
      
      if(pk_set == 1){pk_str="k";}
      if(pk_set == 0){pk_str="-";}
      idle = query_idle(list[i]);
      idle = idle/60;
      ed = "  ";
      if(in_editor(list[i])){ed = "Ed";}
      if(sex == "male"){sex = "M";}
      if(sex == "female"){sex = "F";}
      if(sex == "creature"){sex = "C";}
      if(muff > 0){muff = "muff";}
      if(muff == 0){muff = "    ";}
      tab = "\t";
      if(strlen(name) < 8){tab = "\t\t";}
      tabi = "\t";
      tabl = "\t";
      write(name+tab+sex+" "+muff+" "+ed+" "+invis+tabi+idle+tabi+level+tabl+pk_str+"  "+out
         +"\n");
   }
   return 1;
}
tell_invis(str){
   string who,what;
   object whoo;
   if(!str){write("Tell who what?\n");return 1;}
   if(sscanf(str,"%s %s",who,what) == 2){
      whoo = find_player(who);
      if(find_player(who)){
         if(!in_editor(find_player(who))){
            tell_object(whoo,"Someone tells you: "+what+"\n");
            write("You told "+who+":"+what+"\n");
            return 1;}
         write("That person is editing...try again later.\n");
         return 1;
      }
      write("That person is not playing right now.\n");
      return 1;
      write("Tell who what?\n");return 1;}
   return 1;
}
curse(arg){
   object scurse;
   if(!arg){
      write("Curse who?\n");
      return 1;
   }
   plyr=find_player(arg);
   scurse=clone_object("/players/sweetness/closed/shout_curse");
   write("You just put a shout curse on "+arg+".\n");
   tell_object(plyr,"Your throat feels kinda sore.\n");
   return 1;
}
imprison(arg){
   if(!arg){
      write("Imprison who?\n");
      return 1;
   }
   plyr = find_player(arg);
   plyr->move_player("#/players/paulasx/hell/hell1");
   write("You just imprisoned "+arg+".\n");
   tell_object(plyr,"You have just been sent to HELL by Paulasx.\n");
   return 1;
}
write_ob_and_desc(obj) {
   string str;
   if(!obj) return 0;
   if(dont_write) {
      write(obj); write("\n");
   } else {
      write(obj);write(" <-> ");
      if(!info) { write("Info disabled.\n"); return 1; }
      str = obj->short();
      if(!str) {
         str = NAME(obj);
         if(str == "Someone") str = "("+REAL_NAME(obj)+")";
        }
      if(!TEST(str)) str = "Invisible object.";
      write(str + "\n");
   }
   return 1;
}
Trans(str) {
   if(!str) { write("Usage: Trans [object]\n"); return 1; }
   pob = find_ob(str);
   if(!pob) pob = Clone(str);
   if(!pob) { Fail(str); return 1; }
   move_object(pob, environment(fob));
   Ok();
   return 1;
}

CLONE(str) {
   object ob;
   string s;
   if(sscanf(str,"/%s",s) == 1) ob = Clone(s);
   else ob = Clone("players/"+ call_other(fob,"query_real_name") +"/"+ str);
   if(!ob) { Fail(str); return 1; }
   if(Call(ob,"get",0)) move_object(ob,fob);
   else move_object(ob,environment(fob));
   Ok();
   return 1;
}

Flyt(str) {
   object ob1, ob2;
   string what1, what2;
   if(!str) {
      write("Usage : Move <object1> into <object2>\n");
      write("WARNING: Don't make object1 = pathname; can be fatal!\n");
      return 1;
   }
   if(sscanf(str,"%s into %s",what1, what2) !=2)
      if(sscanf(str,"%s %s",what1, what2) !=2) { Flyt(); return 1; }
   ob1 = find_ob(what1);
   if(!ob1) ob1 = Clone(what1);
   if(!ob1) { Fail(what1); return 1; }
   ob2 = find_ob(what2);
   if(!ob2) ob2 = Clone(what2);
   if(!ob2) { Fail(what2); return 1; }
   move_object(ob1, ob2);
   Ok();
   return 1;
}


des(str) {
   object dob;
   if(!str) { write("Destruct what ?\n"); return 1; }
   if(str == "rem") {
      dob = environment(rem_obj);
      write("Destructing\n   ");write_ob_and_desc(rem_obj);
      destruct(rem_obj);
      rem_obj = dob;
      if(rem_obj) {
         write("New rem_obj :\n   ");
         write_ob_and_desc(rem_obj);
      }
      Ok();
      return 1;
   }
   dob = find_ob(str);
   if(!dob) { Fail(str); return 1; }
   write("Destructing\n   ");write_ob_and_desc(dob);
   destruct(dob);
   Ok();
   return 1;
}

Get(str) {
   object ob;
   string what, item;
   if(!str) { write("Get what ?\n"); return 1; }
   if(sscanf(str,"%s from %s", item, what) == 2) {
      ob = find_ob(what);
      if(!ob) { Fail(what); return 1; }
      ob = present(item, ob);
      if(!ob) { Fail(what); return 1; }
      move_object(ob, fob);
      Ok(); return 1;
   }
   ob = find_ob(str);
   if(!ob) { Fail(str); return 1; }
   move_object(ob, fob); Ok(); return 1;
}

clean1(str) {
   object tob, ob;
   if(!str){
      ob=environment(this_player());
   }
   else
      ob = find_ob(str);
   if(!ob) { Fail(str); return 1; }
   write("Cleaning :\n   "); write_ob_and_desc(ob);
   clean2(ob);
   Ok(); return 1;
}

clean2(ob) {
   object tob;
   int check;
   ob = first_inventory(ob);
   while(ob) {
      tob = next_inventory(ob);
      if(living(ob) && !Call(ob,"query_npc",0)) check = 1;
      else if(Call(ob,"id","soul")) check = 1;
      else if(Call(ob,"id","ring")) check = 1;
      else if(Call(ob,"id","wiz_soul")) check = 1;
      else if(first_inventory(ob)) clean2(ob);
      if(!check) destruct(ob);
      check = 0;
      ob = tob;
      return 1;
   }
   return 1;}
goin(str) {
   object ob;
   if(!str) { write("Usage : Goin [object]\n"); return 1; }
   ob = find_ob(str);
   if(!ob) { Fail(str); return 1; }
   move_object(fob,ob);
   Ok();
   return 1;
}

trace(str) {
   object ob;
   if(!str) { write("Usage : trace [object]\n"); return 1; }
   ob = find_ob(str);
   if (!ob) { Fail(str); return 1; }
   write("Object   : ");write_ob_and_desc(ob);
   write("Location : ");
   if(environment(ob)) write_ob_and_desc(environment(ob));
   else write("None !\n");
   return 1;
}

kig(str) {
   object ob;
   if(!str) ob = environment(fob);
   else ob = find_ob(str);
   if(!ob) { Fail(str); return 1; }
   Call(ob, "long",0);
   if(!str) here("env"); else here(str);
   return 1;
}

reset(arg) {
   if(arg)
      return;
   info = 1;
}

set_lys(str) {
   int n;
   string what;
   if(!str) {
      write("Current light-strength = " + set_light(0) + "\n");
      return 1;
   }
   if(sscanf(str, "%d", n) == 1) {
      set_light(n);
      if(n > 0) {
         say(Name(fob) + "'s staff glows brightly !!\n");
         write("Your staff lights up this dark place > :-)\n");
      }
      else
         tell_room(environment(fob),"Everything suddenly gets darker.\n");
      return 1;
   }
}

set_count(n)
{ if(sscanf(n,"%d",count) == 1) Ok(); else return 0; count -= 1; return 1; }

patch(str) {
   object ob;
   string who, do_str, arg, cap_name;
   int iarg, check;
   if(!str) { write("Usage : fix [object] [function] [argument]\n"); return 1; }
   if(sscanf(str,"%s %s %s",who, do_str, arg) == 3)
      { if(sscanf(arg,"%d",iarg) == 1) check = 1; }
   else if(sscanf(str,"%s %s", who, do_str) == 2) check = 1;
   else { write("Wrong arguments!!\n"); return 1; }
   ob = find_ob(who);
   if(!ob) { Fail(who); return 1; }
   if(check) last_arg = Call(ob,do_str,iarg);
   else {
      string x1,x2,x3,x4,x5;
      if(sscanf(arg,"%s,%s",x1,x2) != 2)
         last_arg = Call(ob,do_str,arg);
      else if(sscanf(arg,"%s,%s,%s,%s,%s",x1,x2,x3,x4,x5) == 5)
         last_arg = call_other(ob,do_str,x1,x2,x3,x4,x5);
      else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3,x4) == 4)
         last_arg = call_other(ob,do_str,x1,x2,x3,x4);
      else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3) == 3)
         last_arg = call_other(ob,do_str,x1,x2,x3);
      else if(sscanf(arg,"%s,%s,%s,%s",x1,x2) == 2)
         last_arg = call_other(ob,do_str,x1,x2);
      else { write("Too many arguments.\n"); return 1; }
   }
   write("Result : "); write(last_arg); write("\n");
   while(count) {
      if(check) Call(ob,do_str,iarg);
      else Call(ob,do_str,arg);
      count -= 1;
   }
   return 1;
}

search_next(str, obj) {
   int nr;
   if(sscanf(str, "%d", nr) == 1)
      return nr_in_ob(nr, obj);
   else if(str == "env")
      return environment(obj);
   return present(str, obj);
}

find_ob(str) {
   object ob;
   string s1, s2, tmp;
   int nr;
   if(!str) { Error("No arg to find_ob."); return 1; }
   if(sscanf(str, "%s,%s", s1, s2) != 2) {
      if(sscanf(str, "%d", nr) == 1) {
         return nr_in_ob(nr, environment(this_player()));
      }
      else {
         return search_all(str);
      }
   }
   ob = search_all(s1);
   while(s2 && ob) {
      tmp = 0;
      if(sscanf(s2, "%s,%s", s1, tmp) != 2) s1 = s2;
      ob = search_next(s1, ob);
      s2 = tmp;
   }
   return ob;
}

search_all(str) {
   object ob;
   if(!str) { Error("No arg to search_all()."); return 1; }
   if(str == "rem") ob = rem_obj;
   else if(str == "arg") ob = last_arg;
   else if(str == "old") ob = old_rem_obj;
   else if(str == "me") ob = fob;
   else if(str == "env") ob = environment(fob);
   else if(sscanf(str,"who%d",i) == 1) ob = users()[i];
   if(!ob) ob = present(str, fob);
   if(!ob) ob = present(str, environment(fob));
   if(!ob) ob = find_object(str);
   if(!ob) ob = find_living(str);
   if(!ob) ob = find_living("ghost of " + str);
   return ob;
}

ipwho(str) {
   string dummy1, dummy2, myip, name;
   object players;
   int i,j,d;
   object ob;
   
   if(!TEST(str)) {
      write("Usage: ipwho <string>\n");
      write("\n  <string> can be either a name, or part of an IP-address\n");
      return 1;
   }
   if(!ISDIGIT(str[0])) {
      ob = find_player(lower_case(str));
      if(!ob) {
         write("I couldn't find '"+str+"'.\n");
         return 1;
      }
      myip = query_ip_number(ob);
      if(!myip) {
         write("I couldn't find '"+str+"'s ip-number.\n");
         return 1;
      }
      if(sscanf(myip,"%d.%d.%d", dummy1, dummy2, str) != 3) {
         write("Corrupted IP-number\n");
         return 1;
      }
      str = dummy1+"."+dummy2;
   }
   write("Searching on ip-number '"+str+"'.\n");
   players = users();
   for(i=0; i<sizeof(players); i++) {
      myip = query_ip_number(players[i]);
      if(myip) {
         if(sscanf(myip,"%s"+str+"%s", dummy1, dummy2) == 2)
            write(get_name_and_level(players[i])+" <-> "+myip+"\n");
       } else
         write(get_name_and_level(players[i])+" <-> "+" <undefined>\n");
   }
   write("Ok.\n");
   return 1;
}

get_name_and_level(obj) {
   string name, str;
   int level, len;
   if(!obj)
      return 0;
   
   name  = obj->query_real_name();
   level = obj->query_level();
   
   str = name;
   len = strlen(name);
   while(len < 12) {
      str = str+" ";
      len++;
   }
   
   str = str+" ("+level+")";
   len = strlen(str);
   while(len < 20) {
      str = str+" ";
      len++;
   }
   return str;
}
remember(str) {
   object ob;
   int nr;
   string who, what;
   if(!str) {
      if(rem_obj) {
         write("Current rem_obj is :\n");write("   ");
         write_ob_and_desc(rem_obj);
         return 1;
      }
      write("There is currently no rem_obj.\n");
      return 1;
   }
   if(str == "env") {
      if(rem_obj) ob = environment(rem_obj);
      else ob = environment(fob);
   }
   else if(str == "old") ob = old_rem_obj;
   else if(str == "del") { rem_obj = 0; Ok(); return 1; }
   else ob = find_ob(str);
   if(!ob) { Fail(str); return 1; }
   write("  ");write_ob_and_desc(ob);
   old_rem_obj = rem_obj;
   rem_obj = ob;
   return 1;
}

here(str) {
   object ob, where;
   int n;
   if(str) where = find_ob(str);
   else where = fob;
   if(!where) { Fail(str); return 1; }
   write_inv_ob(where);
   return 1;
}

write_inv_ob(obj) {
   object ob;
   int n;
   ob = first_inventory(obj);
   write("Inventory of ");write_ob_and_desc(obj);
   while(ob) {
      write(" " + n + ": ");
      if (ob->can_put_and_get())
         write_inv_bag(ob);
      else
         write_ob_and_desc(ob);
      n += 1;
      ob = next_inventory(ob);
   }
   write("That's all.\n");
   return 1;
}

Error(str) {
   write("*** Error");
   if(!str) write(".\n");
   else write(": " + str + "\n");
   return 1;
}

nr_in_ob(n, obj) {
   object ob;
   int nr;
   nr = n;
   if((nr < 0) || !obj) return 0;
   ob = first_inventory(obj);
   while(ob && nr) {
      ob = next_inventory(ob);
      nr -= 1;
   }
   return ob;
}

List() {
   write("Currently remembered objects :\n");
   if(rem_obj)
      write("rem: ");write_ob_and_desc(rem_obj);
   if(old_rem_obj)
      write("old: ");write_ob_and_desc(old_rem_obj);
   if(last_arg)
      write("arg: ");write(last_arg);
   write("\n");
   return 1;
}
query_rem() { return rem_obj; }
query_old_rem() { return old_rem_obj; }
query_arg() { return last_arg; }

