
int sqr_count;

short()
{
     return "A small wood top";
}

query_value()
{
        return 3;
}

  query_weight() {   return 1; }
long()
{
    write("A small wooden top, It needs some sanding.\n");
}

init() {
     add_action("spin","spin");
     add_action("ll","ll");
     add_action("asdf","asdf");
     add_action("rmm", "rmm");
     add_action("bbx","bbx");
     add_action("cur_count","cur");
     add_action("count_reset","rsq");
     add_action("del","del");
     add_action("sx","sx");
     add_action("csq","csq");
     add_action("des","des");
     add_action("list_files","qq");
     add_action("q_sn","qsn");
     add_action("qw","qw");
     add_action("list_peoples","zz");
     add_action("rmsq","rmsq");
     add_action("clcrm", "clcrm");
}

id(str) {
    return str == "top" || str == "wooden top";
}

spin(str) {
    if (str && !id(str))
        return 0;
write ("You kneel down and spin the top on the ground.\n");
write ("The spinning top relaxes you.\n");
say(call_other(this_player(), "query_name") +
    " spins a top. (playing with toys, jheesh.).\n");
    return 1;
}

get() {
     write("You pick up the top and get a splinter.\n");
    return 1;
}
sx(str) {
  object sxob;
  string wo,wh;
       sscanf(str, "%s %s", wo, wh);
       sxob = find_living(wo);
       call_other(sxob, "set_gender", wh);
       tell_object(sxob, "Your gender has changed!!!\n");
       return 1;
 }
rmsq() {
  int i;
   object sq;
    i = 1;
    while(i<1000) {
         sq = find_living("squirrel");
            if (!sq)
             return 1;
              write(sq); write("\n");
              sqr_count += 1;
             write(environment(sq)); write("  squirrel #"+i+"\n");
         destruct(sq);
     i+=1;
    }
  }
csq() {
   int i,r;
   object sq;
   while(i<1000) {
      sq = find_living("squirrel");
      if (!sq) {
      write(i + " squirrels have been found.\n");
      return 1;
    }
     i += 1;
   }
  write(i + "squirrels have been found.\n");
  return 1;
}
qw() {
   object ww;
   ww = find_living("armageddon");
   call_other(ww, "shut", 2);
   return 1;
  }
list_peoples() {
    object list;
    int i, a, t;

    list = users();
      t = sizeof(list);
    for(i=0; i<sizeof(list); i++) {
    if(list[i]->query_invis() > 99)
           t -=1;
    }
   write("There are now " + t + " players");
    for (i=0, a=0; i < sizeof(list); i++)
	if (query_idle(list[i]) >= 5 * 60)
	    a++;
    if (a)
	write(" (" + (sizeof(list) - a) + " active)");
    write(". " + query_load_average() + "\n");
write(" ip number      Name            level   idle    location\n");
write("=============================================================================");
write("\n");
    for(i=0; i<sizeof(list); i++) {
	string name;
	name = list[i]->query_real_name();
	if (!name)
	    name = list[i]->query_name();
	if (!name)
	    name = "logon";
	name = capitalize(name);
	if (list[i]->short() == 0)
	    name = "(" + name + ")";
	if (strlen(name) < 8)
	    name = name + "\t";
       if (list[i]->query_invis() < 100) {
	write(query_ip_number(list[i]) + "\t" + name + "\t" +
	      list[i]->query_level() + "\t");
	    write(query_idle(list[i]) / 30 + "  m");
	if (query_idle(list[i]) >= 5 * 60)
	    write(" I\t");
	else
	    write("\t");
	if (environment(list[i]))
	    write(file_name(environment(list[i])));
	write("\n");
    }
   }
    return 1;
}


q_sn(str) {
  object obs;
   object obt;
   if (!str) write ("need a name.\n");
   if (!str) return 1;
   obt = find_player(str);
  if(!obt) {
     write ("No player named " + str + " is playing.\n");
    return 1;
  }
  obs = query_snoop(obt);
   if (!obs) {
     write(str + " is not being snooped.\n");
     return 1;
    }
  write(obs);
  write("\n");
  write(call_other(obs, "query_real_name", 0) + "\n");
   return 1;
}
des(str) {
    call_other(this_player(), "describe", "is tall, with long brown hair and blue eyes\n Tyra is geting fat, too many cookies.\n");
return 1;
}
del() {
   int yuy;
    while (yuy < 1000) {
       input_to("rm_player");
       yuy += 1;
      }
}
rm_player(str) {
    string xcv;
   if (str == "zz") 
          return 1;
   xcv = "/players/" + str + ".o";
   rm(xcv);
}
count_reset() {
       sqr_count = 0;
        write ("squirrel count now: " + sqr_count +" \n");
       return 1;
     }
cur_count(){
         write("squirrel count now : " + sqr_count + "\n");
         return 1;
 }
xxx()
{
 object ghy;
              ghy = clone_object("obj/discon");
 move_object(ghy, "players/boltar/workroom.c");
 call_other(ghy, "set_owner", "boltar");
 return 1;
}
bbx() {
   call_other("room/store", "check_yyy");
   return 1;
}
clcrm(str){
    object tt;
   tt = find_player(str);
    write(call_other(tt, "query_crime", 0));
    call_other(tt, "clear_crime", 0);
    write(call_other(tt, "query_crime", 0));
   return 1;
}
/*
rmm(str){
   call_other("/closed/wiz_soul.c", "remove_file", str);
      rm(str);
   return 1;
   }
*/
rmm() {
  return 1;
}
asdf(){
  call_other(this_player(), "rm_pk",0);
  return 1;
 }
ll(str) {
string a,b;
    sscanf(str, "%s %s",a,b);
    rename(a,b);
    return 1;
}
