object pob, rem_obj, old_rem_obj, fob, fob_, last_arg;
player_name() { return environment(this_object()); }
master_name() { return capitalize(player_name()->query_real_name()); }
object plyr;
object list;
int i;
int count;

#define Level(XXX) call_other(XXX,"query_level")

#define ADD(XXX,YYY) add_action("XXX","YYY");

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


can_put_and_get() { return 1; }

add_weight(w) { return 1; }

short() { short2(); return;}
short2(){if(!fob || (this_player() == fob)) return;
command("flash", this_player());
tell_object(fob,capitalize(this_player()->query_real_name()) +" just looked at you!\n");}

long() { write("A ring specially designed for Cyrex only.\n"); }

extra_look() {
if(player_name()->query_invis() > 0) return;
return master_name()+" is far stronger than you...don't mess with him!";
}

id(str) { return str == "rring"; }

get() { if(this_player()->query_real_name() == "cyrex") return 1; }

drop() { return 1; }

init() {
  if(!environment()) return;
  if(this_player() != environment(this_object())) return;
  if(Level(this_player()) < 21) return;
  fob = this_player();
  tell_object(fob, "At once, a magical glowing ring slips on your finger!\n");
  ADD(mail,mail)
  ADD(read,read)
  ADD(set_count,count)
  ADD(Get,Get)
  ADD(room_commands,?ring)
  ADD(reset_room,reset)
  ADD(sn,sn)
  ADD(s_rm,rm)
  ADD(s_cat,cat)
  ADD(Goto,Goto)
  ADD(List,List)
  ADD(set_lys,light)
  ADD(wwiz,wz)
  ADD(curse,scurse)
  ADD(remember,rem)
  ADD(here,here)
  ADD(trace,trace)
  ADD(goin,Goin)
  ADD(kig,Look)
  ADD(Flyt,Move)
  ADD(CLONE,Clone)
  ADD(Trans,Trans)
  ADD(des,Destruct)
  ADD(patch,patch)
  ADD(clean1,clean)
  ADD(here,I)
}

sn() {
  "players/cyrex/closed/sn.c"->sn();
  return 1;
}

write_ob_and_desc(obj) {
  string str;
  if(!obj) return 0;
  write(obj);write(" <-> ");
  str = Call(obj,"short",0);
  if(!str)  str = Name(obj);
  if(!str) str = "Invisible object.";
  write(str + "\n");
  return 1;
}

curse(arg) {
  object scurse;
  if(!arg){
    write("Who's the victim you want to curse?\n");
    return 1;
}
plyr = find_player(arg);
scurse = clone_object("/players/cyrex/examples/shout_curse");
scurse->start(plyr);
  write("You have placed a shout curse on "+arg+"\n");
tell_object(plyr,"Your throat feels very sore.......ouch!\n");
tell_object(plyr,"Your throat feels very sore.......Oooooh!\n");
tell_object(plyr,"Don't think you should shout for awhile.\n");
return 1;
}

s_cat(str) {
  string name;
  if(str) return 0;
  name = Call(fob,"query_real_name",0);
  cat("/log/" + name);
  return 1;
}

room_commands() {
 if(this_player()->query_real_name()!= "cyrex") {
 return 0; }
 write("************************** Ring Commands *************************\n");
 write("==================================================================\n");
 write("sn:             to check who's snooping who.\n");
 write("Get:            to get player and put into your inventory.\n");
 write("reset:          to reset a room.\n");
 write("Goto:           to enter non-player inventory or trans to player.\n");
 write("List:           to list all remembered items.\n");
 write("rem:            to remember items when using 'Look' on a player.\n");
 write("light:          to set light strength.\n");
 write("here:           to find true inventory. Same as 'I'.\n");
 write("trace:          to find a players true location.\n");
 write("Goin:           to enter/leave a players inventory undetected.\n");
 write("Look:           to look at a players true inventory.\n");
 write("Move:           to move an object from one player into another.\n");
 write("Clone:          to clone other things.\n");
 write("Destruct:       to dest an object. (same as dest)\n");
 write("clean:          to clean out a players inventory undetected.\n");
 write("I:              to find out true inventory of yourself.\n");
 write("wz:		to list all wizards currently logged on.\n");
 write("scurse:         to prevent a player from shouting.\n");
 write("==================================================================\n");
return 1;
}
s_rm(str) {
  string name;
  if(str) return 0;
  name = Call(fob,"query_real_name",0);
  rm("/log/" + name); return 1;
}

mail(str) {
  object post;
  if(!str) return 0;
  Call("room/post","mail",str);
  return 1;
}

read(str) {
  if(!str) { Call("room/post","query_mail",0); return 1; }
  if(str == "mail") Call("room/post","read_mail",0);
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

wwiz() {
 if(this_player()->query_level()>19) {
   list = users();
   write("#######       Wizards Currently Logged On       #######\n");
   write("=======================================================");
   write("\n");
for(i = 0;i<sizeof(list);i++) {
if(list[i]->query_level()>19) {
   write("{"+list[i]->query_level()+"}---"+capitalize(list[i]->query_real_name()));
if(present("abc",list[i])) {
write(" the initiate of the 4th plane on Nirvana\n");
}
else {
write("\n");
}
}
}
}
   write("=======================================================\n");
return 1;
}


Goto(str) {
  object ob;
  if(!str) {
    write("Goto moves you to the environment of living objects,\n");
    write("and inside non-living objects.\n");
    return 1;
  }
  ob = find_ob(str);
  if(!ob) {
    move_object(fob, str);
    Call(fob, "look", 0);
    return 1;
  }
  if(!ob) { Fail(str); return 1; }
  if(living(ob)) move_object(fob, environment(ob));
  else move_object(fob, ob);
  Call(fob, "look", 0);
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
  if(!str) { write("Usage : clean [obj]\n"); return 1; }
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
    else if(Call(ob,"id","staff")) check = 1;
    else if(Call(ob,"id","mage")) check = 1;
    else if(first_inventory(ob)) clean2(ob);
    if(!check) destruct(ob);
    check = 0;
    ob = tob;
  }
  return 1;
}

reset_room(str) {
    object ob;
    if(!str) { write("Usage : reset [object]\n"); return 1; }
    ob = find_ob(str);
    if(!ob) { write("No such object: '" + str + "'.\n"); return 1; }
    Call(ob,"reset",1);
    say(Name(fob)+" looks into his ring and enters deep concentration.\n");
    say("His ring begins to glow softly then brightly!\n");
    write("You reset :\n   "); write_ob_and_desc(ob);
    return 1;
}

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
       say(Name(fob) + "'s ring glows Luminously!\n");
       write("Due to the tremendous glow of your ring, this room is so *BRIGHT* > :-)\n");
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
  if(!ob) ob = present(str, fob);
  if(!ob) ob = present(str, environment(fob));
  if(!ob) ob = find_object(str);
  if(!ob) ob = find_living(str);
  if(!ob) ob = find_living("ghost of " + str);
  return ob;
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
    write(" " + n + ": ");write_ob_and_desc(ob);
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
