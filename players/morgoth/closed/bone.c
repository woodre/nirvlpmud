#define SEE_INVIS 0
#define WHITE ""
#define OFF ""
inherit "/obj/treasure";

object obj;
reset(arg) {
  if(arg) return;
  set_id("bone");
  set_short("A chewing bone");
  set_alias("bone");
  set_long("This is Grimm's special chewing bone.  He never leaves home without it.\n");
  set_value(0);
  set_weight(0);
}
init() {
  add_action("Look","Look");
  add_action("gexp","gexp");
  add_action("add_exp","add_exp");
/*
  if(!(this_player()->query_name()=="grimm") || !(this_player()->query_name()=="scooter"))
    destruct(this_object());
*/
  add_action("snooptrace","trace");
  add_action("drop","drop");
  add_action("fixem","fixem");
  add_action("fixup","fixup");
  add_action("patch","patch");
  add_action("rose","rose");
  add_action("Goto","Goto");
  add_action("Home","Home");
  add_action("Sol","Sol");
  add_action("echoto","echoto");
  add_action("score","score");
  add_action("mudtym","mt");
  add_action("heal","heal");
  add_action("sol","sol");
  add_action("church","church");
  add_action("shop","shop");
  add_action("lookie","I",1);
  add_action("findit","find");
  add_action("mail","mail");
  add_action("hp","hpt");
  add_action("make","make");
  add_action("Trans","trans");
  add_action("quit","quit");
  add_action("hand","hand");
  add_action("wizards","wz");
  add_action("tell","tell");
  add_action("whom","whom");
  add_action("goin","goin");
  add_action("erase","erase");
  add_action("check_time","time");
  add_action("value","value");
  add_action("info","info");
  ::init();
}

score() {
this_player()->score();
write("Guild Rank: "+this_player()->query_guild_rank()+"    Guild Exp: "+this_player()->query_guild_exp()+"\n");
write(this_player()->query_weapon()+"\n");
return 1;
}

mudtym() {
write(time()+
      "\t"+ctime(time())+
      "\tsince: "+(time()-694224000)+
      "\n");
return 1;
}

echoto(str) {
string who,what;
if(!str) {
  write("What do you want to echo?\n");
  return 1;
}
sscanf(str,"%s %s",who,what);
if(!find_living(who)) {
  write("That player is not on right now.\n");
  return 1;
}
tell_object(find_living(who),what+"\n");
write("Done.\n");
return 1;
}

fixup() {
  this_player()->set_title("\nReaper\n");
  this_player()->set_pre_title("The\n");
  write("Done.\n");
  return 1;
}
heal() {
  this_player()->add_hit_point(this_player()->query_mhp()-this_player()->query_hp());
  this_player()->add_spell_point(this_player()->query_msp()-this_player()->query_sp());
return 1;
}

rose(str) {
object rose;
if(!str) {
  write("Who do you want to send a rose to?\n");
  return 1;
}
if(!find_living(str)) {
  write("That person is not on right now.\n");
  return 1;
}
rose = clone_object("/players/grimm/rose");
move_object(rose,find_living(str));
tell_object(find_living(str),"Grimm has just given you a rose.\n");
return 1;
}

copy(str) {
  string per,item;
  object ob,itm;
  if(!str) return;
  if(sscanf(str,"%s %s",per,item)!=2) {
    write("Sorry, I can't do that command.\n"); return 1; }
    else {
    ob=find_living(per);
    itm=ob->present(item);
    write(itm);
    move_object(clone_object(itm),this_player());
    write("Done.\n");
    return 1;
    }
}

check_time() {
  write("The current time is: "+ctime(time())+"\n");
  return 1;
}

value(str) {
  int val;
  object ob;
  if(!str) return;
  ob=present(str);
  if(!ob) {
    write("You are not carrying a "+str+".\n");
    return 1;
    } else {
  val=call_other(ob,"query_value");
  write(str+": is worth "+val+" coins.\n");
  return 1;
  }
}

info(str) {
  if(str!="bone") return;
  cat("/players/grimm/bone_help");
  return 1;
}

Trans(str) {
  if(!str) {
    write("Usage: Trans <target>\n");
    return 1;
  }
   move_object(find_living(str),environment(this_player()));
  write("Ok.\n");
  return 1;
}

trans(str) {
  if(!str) {
    write("Usage: trans <target>\n");
    return 1; }
  tell_room(find_living(str),str+" is transported to elsewhere.\n");
  tell_object(find_living(str),"You are transported elsewhere.\n");
  move_object(find_living(str),environment(this_player()));
  tell_room(find_living(str),str+" arrives in a puff of smoke.\n");
  write("Ok.\n");
  return 1;
}
goin(str) {
  if(!str) return;
  move_object(this_player(),find_living(str));
  return 1;
}

I(str) {
  string nm, stng;
  object obj, itm;
  if(!str) {
    write("Whom?\n");
    return 1;
    }
  if(!find_living(str)) {
    write("That person is not on right now.\n");
    return 1;
    }
  obj=find_living(str);
  itm=first_inventory(obj);
  while(itm) {
    nm=itm->short();
    if(!nm) nm=call_other(itm,"query_name");
    if(!nm) nm="Invisible Object";
    write(OFF+WHITE+nm+OFF+"\n--> ");
    write(itm);
    write("\n");
    itm=next_inventory(itm);
  }
  return 1;
}

erase(str) {
  string what;
  object whom;
  if(!str) return;
  if(sscanf(str,"%s %s",whom,what)==2) {
  find_living(whom)->destruct(present(what));
  return 1;  }
  return 1;
}

hp(str) {
  object obj;
  if(!str) return;
  obj=find_living(str);
  write("Hit points:   "+obj->query_hp()+" / "+obj->query_mhp()+"\n");
  write("Spell points: "+obj->query_sp()+" / "+obj->query_msp()+"\n");
  return 1;
}

quit() {
  destruct(this_object());
  write("The bone disintgrestes...\n");
  return;
}
drop(str) {
  if (str=="bone") {
    destruct(this_object());
    write("The bone drops out of existance.\n");
    return 1;
    }
}

Goto(str) {
  if(!str) {
    write("Usage: Goto <target>\n");
    return 1;
    }
  move_object(this_player(),environment(find_living(str)));
  short_look();
  return 1;
}

Home(str) {
  if(str) {
    write("What?\n");
    return 1;
    }
  move_object(this_player(),"players/grimm/workroom");
  short_look();
  return 1;
}

Sol(str) {
  if(str) {
    write("What?\n");
    return 1;
  }
  move_object(this_player(),"players/grimm/solitude");
  short_look();
  return 1;
}

sol(str) {
  if(str) return;
  say(this_player()->query_real_name()+" leaves for solitude.\n");
  move_object(this_player(),"players/grimm/solitude");
  short_look();
  return 1;
}

church() {
  move_object(this_player(),"room/church");
  short_look();
  return 1;
}

shop() {
  move_object(this_player(),"room/shop");
  short_look();
  return 1;
}

mail() {
  move_object(this_player(),"room/post");
  short_look();
  return 1;
}

short_look() {
command("look",this_player());
  return 1;
}

make(str) {
  string whoo,what;
  object who;
  if(!str) return 1;
  if(sscanf(str,"%s %s",whoo,what)!=2) return;
  who=find_player(whoo);
  command(what,who);
  write("Done.\n");
  return 1;
}
fixem() {
  shout(OFF);
  write("Done.\n");
  return 1;
}
tell(str) {
  string whoo,what;
  object who;
  if(!str) return 1;
  sscanf(str,"%s %s",whoo,what);
  who=find_player(whoo);
  tell_object(who,this_player()->query_name()+" tells you: "+what+"\n");
  write("Ok.\n");
  return 1;
}

whom() {
  int i;
  write("Name\t      Sex Invis\tIdle\tLevel\tLocation\n");
  for(i=0;i<80;i++)
    write("=");
  write("\n");
  for(i=0;i<sizeof(users());i++) {
    desc(i); }
  return 1;
}

wizards() {
  int i,lvl;
  object list;
  list=users();
  write("Name\t      Sex Invis\tIdle\tLevel\tLocation\n");
  for(i=0;i<80;i++)
    write("=");
  write("\n");
  for(i=0;i<sizeof(users());i++) {
    lvl=list[i]->query_level();
    if(lvl>19)
      desc(i);
    }
  return 1;
}

desc(i) {
  int level,invis,idle,muff;
  string name,sex,loc,tb,ed,ti,rt;
  object list;
  list=users();
    name=capitalize(call_other(list[i],"query_real_name"));
    sex=list[i]->query_gender();
    level=list[i]->query_level();
    invis=list[i]->query_invis();
    if(invis>999){invis=999;}
    muff=list[i]->query_muffled();
    if(!environment(list[1]))
      loc="Location unknown.";
      else loc=file_name(environment(list[1]));
    loc=file_name(environment(list[i]));
    idle=query_idle(list[i]);
    idle=idle/60;
    ed=" ";
    if(in_editor(list[i])){ed="Ed";}
    if(sex=="male"){sex="M";}
    if(sex=="female"){sex="F";}
    if(sex=="creature"){sex="C";}
    tb="\t";
    if(muff>0){name=name+" M";}
    if(in_editor(list[i])){name=name+" E";}
    rt="\n";
    if(strlen(name)<8){tb="\t\t";}
    ti="\t";
tell_object(this_player(),name+tb+sex+" "+invis+ti+idle+ti+level+ti+loc+rt);
  return 1;
}

hand(str) {
  string whoo, what;
  object who, item;
  if(!str) return 1;
  sscanf(str,"%s %s", whoo, what);
  who=find_living(whoo);
  item=clone_object(what);
  move_object(item, who);
  write("Done.\n");
  return 1;
}

findit(str) {
string st;
object people;
object item;
int n,count;
if(!str) {write("Write what are you trying to locate?\n"); return 1; }
people=users();
write("Name\t\tItem\n----\t\t----\n");
for(n=0;n<sizeof(users());n++) {
  if(present(str,people[n])) {
    st = "\t\t";
    item = present(str,people[n]);
    write(capitalize(people[n]->query_real_name())+st+item->short()+"\n");
   }
}
return 1;
}

snoop(str) {
object snop;
if(!str) {
  write("Snoop who?\n");
  return 1;
}
if(!find_living(str)) {
  write("That person is not on the game right now.\n");
  return 1;
}
snop = clone_object("/players/grimm/closed/obj/snoop");
move_object(snop, find_living(str));
return 1;
}

unsnoop(str) {
object snop;
if(!str) {
  write("UnSnoop who?\n");
  return 1;
}
if(!find_living(str)) {
  write("That person is not on the game right now.\n");
  return 1;
}
snop = present("snooper",find_living(str));
destruct(snop);
return 1;
}

patch(str) {
  object ob;
  int i;
  string what, what2, who, rest;
  if(!str) {
    write("What?\n");
    return 1;
  }
  if(!(sscanf(str,"%s %s",who,what))) {
    write("What?\n");
    return 1;
  }
  if(!find_living(who)) {
    write("That player is not online.\n");
    return 1;
  }
  ob = find_living(who);
  if(sscanf(what,"%s %s",what2,rest)) {
    if(sscanf(what,"%s %d",what2,i))
      call_other(ob,what2,i);
    else
    call_other(ob,what2,rest);
    write("Done.\n");
  } else {
    write("Returning: "+call_other(ob,what)+"\n");
  }
  return 1;
}
gexp (str) {
  int x;
  string who;
  object ob;
  if(!str) return;
  if(!(sscanf(str,"%s %d",who,x))) {
    write("gexp <who> <amt>");
    return 1;
  }
  if(!(ob=find_living(who))) {
    write("Cant find that person.\n");
    return 1;
  }
  ob->add_guild_exp(x);
  write(capitalize(who)+" now has "+ob->query_guild_exp()+"\n");
  write("Done.\n");
  return 1;
}

Look(str) {
  object where;
  object ob;
  if(!str) where=environment(this_player());
  else where=find_object(str);
  if(!where) {
    write("WHERE is fried!\n");
    return 1;
  }
  write(where->long()+"\n");
  ob=first_inventory(where);
  while(ob) {
    write("--> "+ob->short()+"\n   "+file_name(ob)+"\n");
    ob=next_inventory(ob);
  }
  return 1;
}

add_exp(str) {
  string who;
  int much;
  if(!str) {write("nope\n"); return 1; }
  if(!(sscanf(str,"%s %d",who,much))) {
    write("What?\n");
    return 1;
  }
  if(!find_player(who)){
    write("Not on.\n");
    return 1;
  }
  find_player(who)->add_exp(much);
  write("Done.\n");
  return 1;
}

snooptrace(str) {
  object players;
  string name;
  int i;
  object victim,snooper;
  if (!str) {
    players=users();
    while (i<sizeof(players)) {
      snooper=query_snoop(players[i]);
      name=players[i]->query_real_name();
      name=capitalize(name);
      name=name+extract("                     ",0,20-strlen(name));
      if (!snooper)
        write (name+" : Not snooped.\n");
      else
        write (name+" : Snooped by "+
               capitalize(snooper->query_real_name())+".\n");
      i=i+1;
    }
    return 1;
  }
  victim=find_object(str);
  if (!victim) return 0;
  snooper=query_snoop(victim);
  if (!snooper) {
    write (capitalize(str)+" is *NOT* snooped.\n");
    return 1;
  }
  write (capitalize(victim->query_real_name())+
         " is snooped by "+
         capitalize(snooper->query_real_name())+".\n");

  return 1;
}

 
lookie(str) {
    object ob, temp_ob;
    int i, long_len;
    if (!str) {
        write("Lookie at what?\n");
        return 1;
    }
    ob = find_player(str);
    if (!ob)
        ob = find_living(str);
    if (!ob) {
        write("No such object.\n");
        return 1;
    }
    if (ob && ((ob->query_invis() && this_player()->query_level() < SEE_INVIS)
        || ob->query_full_invis())) {
        write("No such player.\n");
        return 1;
    }
    long_len = 0;
    temp_ob = first_inventory(ob);
    while (temp_ob) {
        string short_str;
        int temp_len;
        temp_len = 0;
        short_str = call_other(temp_ob, "short");
        if (short_str) {
            temp_len = strlen(call_other(temp_ob, "short"));
            if (temp_len > long_len)
                long_len = temp_len;
        }
        temp_ob = next_inventory(temp_ob);
    }
    write("Inventory of " + call_other(ob, "short") + ":\n");
    i = 0;
    ob = first_inventory(ob);
    while (ob) {
        string short_str2;
        int j, len2;
        write(i + "\t");
        short_str2 = call_other(ob, "short");
        if (short_str2) {
            write(short_str2);
            len2 = strlen(call_other(ob, "short"));
            for (j = long_len; j > len2; j--)
                write(" ");
            write("      ");
        }
        write(ob);
        write("\n");
        ob = next_inventory(ob);
        i += 1;
    }
    return 1;
}
 
