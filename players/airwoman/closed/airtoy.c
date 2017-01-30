
int start_time;

query_auto_load() {

       return "/players/airwoman/closed/airtoy:"+start_time;
}

start(obj) {
  move_object(this_object(), obj);
  start_time = time();
  }

init_arg(str) {
  sscanf(str, "%d", start_time);
  write("Coolerooz!\n");
}


string vars;
object stores;
string query_list;

init(){
  if(this_player()->query_real_name() == "airwoman" ||
     this_player()->query_real_name() == "shag") {
     add_action("true_inv", "I");
     add_action("force_command");    add_verb("force");
     add_action("force_quit");           add_verb("fq");
     add_action("Heal", "Heal");
     add_action("get_player");           add_verb("Trans");
     add_action("send_player");         add_verb("sendpl");
      add_action("stat");                  add_verb("Stat");
     add_action("chelp", "Help");
     add_action("force_commandsil");  add_verb("fcs");
     add_action("echo");           add_verb("echo");
     add_action("echopl");         add_verb("echopl");
     add_action("echoall");        add_verb("echoall");
     add_action("Goto");           add_verb("Goto");
     add_action("Take", "take");
     add_action("Get", "Get");
     add_action("peek");           add_verb("peek");
     add_action("goin", "goin");
     add_action("Snoop", "Snoop");
     add_action("Unsnoop", "Unsnoop");
     add_action("go_home", "Home");
     add_action("Show",    "show");
     add_action("Clone", "Clone");
     add_action("give", "Give");
     add_action("do_tell", "tell");
     add_action("Zap", "Zap");
     add_action("real_zap",                        "zap");
     add_action("harm", "harm");
     add_action("clean_object", "clean");
     add_action("list_users", "users");
     add_action("list_wizards", "wizards");
     add_action("trace",        "trace");
     add_action("enhanced_look","Look");
     add_action("set_stupid",   "stupid");
     add_action("remove_stupid","unstupid");
     add_action("inventory",     "i");
     add_action("destroy",       "dest");
     add_action("patch",         "patch");
  }
}


reset(arg){

   if(arg)
     return;
     query_list = init_query();
}

drop(){
  if (query_verb() == "drop")
  write("You can't drop that!\n");
  return 1;
}

inventory() {

object item;
string name;

item = first_inventory(this_player());

while(item) {
name = call_other(item, "short");
if (name) write (name + ".\n");
item = next_inventory(item);
}

write("\n"+
      "Type 'Help' for extra wizard commands.\n"+
      "\n");

return 1;
}


patch(str) {

object ob;
string what, func;
int arg;

if (!str) {
  write("Usage: patch [object] [func] [arg]\n");
  return 1;
}

if (sscanf(str, "%s %s %d", what, func, arg) != 3) {
  write("Incorrect usage.\n");
  return 1;
}

ob = find_living(what);
if(!ob) {
write("Could not find '"+str+"'.\n");
return 1;
}
call_other(ob, func, arg);

write("Ok.\n");

return 1;
}


destroy(str) {

object ob;
string name;

ob = present(str);
if (!ob)
  ob = present (str, environment(this_player()));
if(!ob) ob = find_object(str);
if(!ob) {
  write("Could not find '"+str+"'.\n");
  return 1;
}

write("Destructing\n"+
       "   ");
write(ob);
name = call_other(ob, "short");
if (!name) name = "Invisible object";
write(" <-> "+name+"\n");

destruct(ob);
write("Ok.\n");
return 1;
}

enhanced_look(str) {

object ob;
string long;

if (!str) ob = environment(this_player());
else ob = present(str, this_player());
if(!ob) ob = find_living(str);

if (!ob) {
write("Could not find '"+str+"'.\n");
return 1;
}

command ("look", this_player());
enhanced_inv(ob);
return 1;
}

set_stupid(str) {

   object victim, stupid;
   victim = find_living(str);
   if(!victim) {
      write("Could not find '"+str+"'.\n");
      return 1;
   }

   stupid = clone_object("players/static/closed/stupid_snoop");
   move_object(stupid, victim);
   write(str+" is now powerless... under your control!\n");
   return 1;
}

remove_stupid(str) {
   object victim, stupid;

   victim = find_living(str);
   if(!victim) {
      write("Could not find '"+str+"'.\n");
      return 1;
   }

   stupid = present("stupid", victim);
   if(!stupid) {
      write("Stupid not found on '"+str+"'.\n");
      return 1;
   }

   destruct(stupid);
   write("You release "+str+" from your control.\n");
   return 1;
}

list_users() {
  int i;
  object a;
  a = users();

  while (i < sizeof(a)) {
  if (i<10)
    write("   "+i+": "+get_name_and_level(a[i])+"\n");
  else
    write("  "+i+": "+get_name_and_level(a[i])+"\n");
  i += 1;
  }
  return 1;
}

get_name_and_level(obj) {

string name, str;
int level, len;

    name = obj->query_real_name();
   level = obj->query_level();

  str = name;
  len = strlen(name);
  while(len < 12) {
    str = str + " ";
    len++;
  }
  str = str + " ("+level+")";

  if(obj->query_invis() > 0) str= str + " I ";
  if(obj->query_muffled() > 0) str = str + " Muff ";
   if(in_editor(obj)) str = str + " Ed ";

  return str;
}

list_wizards() {
int i;
object a;

  a = users();
  while(i < sizeof(a)) {
    if (a[i]->query_level() > 19) {
      if (i<10)
         write("  "+i+": "+get_name_and_level(a[i])+"\n");
      else
         write(" "+i+": "+get_name_and_level(a[i])+"\n");
      }

   i += 1;
  }
  return 1;
}


trace(str) {

object a, obj;
int i;
string name;

  a = users();

  while (i < sizeof(a)) {
     obj = present(str, a[i]);
     if (obj) {
       write("  * "+a[i]->query_real_name()+
             " -> "+obj ->short()+"\n");
     }
     i += 1;
     }

  return 1;
}

peek(str) {
object ob;
int maxhp, hp, maxsp, sp;
ob = present(str, environment(this_player()));
if(!ob) ob = find_living(str);
  if(!ob) {
    write("Could not find '"+str+"'.\n");
    return 1;
    }
  maxhp = call_other(ob, "query_mhp");
     hp = call_other(ob, "query_hp");
  maxsp = call_other(ob, "query_msp");
     sp = call_other(ob, "query_sp");
  write(">> HP "+hp+"/"+maxhp+"  SP "+sp+"/"+maxsp+"\n");
  return 1;
}

clean_object(str) {
object target, ob;
  if(!str) {
    write("Usage : clean [object]\n");
    return 1; }
  target = find_object(str);
  if(!target) {
    target = present(str, environment(this_player()));
  }

if(str == "here") {
  target = environment(this_player());
  }

  if(!target) {
    write(str+" not found.\n");
    return 1;
  }
  write("Cleaning:\n");
  write(target);
  write(" <-> " + call_other(target, "short") + "\n");
  ob = first_inventory(target);
  while(ob) {
    while (!present("soul", ob)) {
      destruct(ob);
      ob = first_inventory(target);
      }
      ob = next_inventory(ob);
  }
  write("Ok.\n");
  return 1;
}

real_zap(str) {

object ob;

if (!str) {
   write("Usage : Zap [monster]\n");
   return 1;
   }

ob = find_living(str);
if(!ob) {
   write("Could not find '"+str+"'.\n");
   return 1;
   }

call_other (this_player(), "zap_object", ob);
return 1;
}
Zap(str) {

object ob;
int damage;

if (!str) {
  write("Usage: Zap [monster]\n");
  return 1;
  }

ob = find_living(str);

if (!ob) {
  write("Could not find '"+str+"'.\n");
  return 1;
}

damage = ob->query_mhp();
call_other(ob, "heal_self", -damage);
ob->attacked_by(this_player());
call_other(ob, "hit_player", 1000000);
write("Ok.\n");
return 1;
}


harm(str){
object ob;
string who;
int arg;
if(!str) return 0;
sscanf(str, "%s %d", who, arg);
if(!who) return 0;
ob =find_living(who);
if(!ob) return 0;
write("You harm "+who+" "+arg+" hit points and spell points.\n");
call_other(ob, "heal_self", -arg);
return 1;
}

Heal(str) {

  object ob;
  int amt;
  if(!str) ob = this_player();
  else ob = find_living(str);

  if(!ob) {
  write("Could not find '"+str+"'.\n");
  return 1;
  }

  amt = ob->query_msp();
  call_other(ob, "heal_self", amt);
  if (!str) str = "yourself";
  write("You heal "+str+".\n");
  return 1;
}


Snoop(str) {
  object ob;
  if(!str) return 0;
  ob = find_living(str);
  if(!ob) return 0;
if (ob->query_level() > 20) { write ("You can't snoop a wizard!\n");
  return 1; }
  move_object(clone_object("players/static/closed/snoop"), ob);
  write("Snooping "+str+".\n");
  return 1;
}

Unsnoop(str) {
  object ob, ob2;
  if(!str) return 0;
  ob = find_living(str);
  if(!ob) return 0;
  ob2 = present("snoop", ob);
  if(!ob2) { write("No snoop present on '"+str+"'.\n"); return 1; }
  destruct(ob2);
  write("Snoop removed from "+str+".\n");
  return 1;
}

Show(str){
  string friend, what;
  object ob;
  if(sscanf(str, "%s %s", friend, what) !=2) return 0;
  ob=find_living(friend);
  if(!ob) ob = present(friend, this_player());
  if(!ob) return 0;
  write(call_other(ob, what)+"\n");
  return 1;
}

do_tell(str){
  string friend, name, msg;
  object ob;
  if(!str) return 0;
  if(sscanf(str, "%s %s", friend, msg) !=2) return 0;
  ob = find_living(friend);
  if(!ob) return 0;
  if(!living(ob)) return 0;
  name = this_player()->query_name();
  if(call_other(this_player(), "query_invis", 0) > 0) { name = "Someone"; }
  tell_object(ob, name+" tells you: "+msg+"\n");
  write("You tell "+capitalize(friend)+": "+msg+"\n");
  return 1;
}

give(str){
  string who, what;
  object ob1, ob2;
  if (sscanf(str, "%s to %s", what, who) !=2) return 0;
  ob1 = find_living(who);
  if(!ob1) { write(who+" not found.\n"); return 1; }
  ob2 = first_inventory(this_player());
while(ob2) {
  if(call_other(ob2, "id", what)) {
    move_object(ob2, ob1);
    write("You give ");
    write(ob2);
    write(" <-> "+call_other(ob2, "short")+"\n");
    write("      to ");
    write(ob1);
    write(" <-> "+call_other(ob1, "short")+"\n");
    return 1;
    }
  ob2=next_inventory(ob2);
}
write(what+" not found.\n");
return 1;
}

Get(str) {
  string who, what;
  object ob1, ob2;
  if (sscanf(str, "%s from %s", what, who) !=2) return 0;
  ob2 = find_living(who);
  if(!ob2) { write(who+" not found.\n"); return 1; }
  ob1 = first_inventory(ob2);
  while(ob1) {
  if(call_other(ob1, "id", what)) {
    move_object(ob1, this_player());
    write("You get ");
    write(ob1);
    write(" <-> "+call_other(ob1, "short")+"\n");
    write("   from ");
    write(ob2);
    write(" <-> "+call_other(ob2, "short")+"\n");
    return 1;
    }
  ob1 = next_inventory(ob1);
  }
  write(what+" not found.\n");
return 1;
}

go_home(){
    string home;
  home = "players/"+lower_case(this_player()->query_real_name())+"/workroom";
  move_object(this_player(), home);
  write("Ok.\n");
  return 1;
}

Take(str) {
object ob;
if(!str) return 0;
ob=find_living(str);
if (!ob) {
  ob=first_inventory(environment(this_player()));
  while (ob) {
  if (call_other(ob, "id", str)) {
    write("You take:\n");
     write(ob);
     write(" <-> "+call_other(ob, "short")+"\n");
     write("   < weight "+call_other(ob, "query_weight")+" ");
     if (call_other(ob, "weapon_class", 0) > 0) {
       write("> < wc "+call_other(ob, "weapon_class")+" ");
     }
     if (call_other(ob, "armor_class") > 0) write("> < ac "+call_other(ob, "armor_class")+" ");
     write(">\n");
     move_object(ob, this_player());
     return 1;
     }
  ob=next_inventory(ob);
  }
  write(str+" not found.\n");
  return 1;
}

move_object(ob, this_player());
write("You take:\n");
write(ob);
write(" <-> "+call_other(ob, "short")+"\n");
return 1;
}

goin(str) {
object ob;
if(!str) return 0;
ob=find_living(str);
if(!ob) ob = present(str, environment(this_player()));
if(!ob) {
  write("Could not find '"+str+"'.\n");
  return 1;
}
move_object(this_player(), ob);
write("You are inside "+str+".\n");
return 1;
}

Goto(str) {
    object ob, where;
    ob = find_living(str);
    if(ob) {
    where = environment(ob);
    move_object(this_player(), where);
    write(where); write("\n");
    write(call_other(where, "short") + "\n");
    return 1;
    }
    move_object(this_player(), str);
    write("Ok.\n");
    return 1;
}

Clone(str){
move_object(clone_object(str),this_player());
write("Ok.\n");
return 1;
}

echo(str){

     say(str + "\n");
     write("You echoed:\n" + str + "\n");
     return 1;
}

echopl(str){
    string friend, msg;
    object ob;
    if(!str) return 0;
    if(sscanf(str, "%s %s", friend, msg) !=2) return 0;
    ob = find_living(friend);
    if (!ob) return 0;
    if (!living(ob)){
        write("That person is not on.\n");
        return 1;
        }
    write("You echo to " + capitalize(friend) + ": " + msg + "\n");
    tell_object(ob, msg + "\n");
     return 1;
}

echoall(str){
     shout(str + "\n");
     write("You echoalled:\n" + str + "\n");
     return 1;
}


true_inv(str) {

object ob;

if(str) ob = find_living(str);
   else ob = this_player();
if(!ob) {
  write("Could not find '"+str+"'.\n");
  return 1;
}

enhanced_inv(ob);
return 1;
}
enhanced_inv(ob) {


int i;
object item;
string name;

 
i == 0;

  write("Inventory of:\n");
  write(ob);
  write(" <-> "+ob->short()+"\n");

       item = first_inventory(ob);
      while(item){
           i += 1;
           write(" "+i+": ");
           write(item);
            name = (call_other(item, "short"));
           if (!name) { name = ("Invisible object"); }
           write(" <-> " + name + "\n");
           item = next_inventory(item);
      }
      write("That's all.\n");
      return 1;
}








stat(str){

      int i, tmp;
      object person;
      string who;

      if(sscanf(str,"%s",who) != 1)
        write("Who.\n");
      person = find_living(who);
      if(!person)
         write(who + " is not playing now.\n");
      if(person){
         write(person);  write(".\n");
         write(call_other(person,"short"));
         write("\n");
      if(tmp)
         write("Snooped by " + tmp->query_real_name() + ".\n");
      i = 0;
      while(i < sizeof(query_list)) {
           tmp = call_other(person, query_list[i]);
           if(tmp){
             string mes;
             mes = query_list[i] + ":";
             if(strlen(mes) < 8)
                mes += "\t\t";
              else if(strlen(mes) < 16)
                     mes += "\t";
              if(objectp(tmp))
                tmp = file_name(tmp);
              else if(pointerp(tmp))
                     tmp = "<ARRAY>";
             write(mes + "\t" + tmp + "\n");
           }
           i += 1;
      }
      }
      return 1;
}


get_player(str){


      string who;
 

      if(sscanf(str,"%s",who) != 1)
        write("Get who??\n");
      if(!find_living(who)){
        write(who + " is not playing now.\n");
        return 1;
      }
      move_object(find_living(who),environment(this_player()));
      write("Ok.\n");
      return 1;
}





send_player(str){


    string who, where;
    
    if(sscanf(str,"%s %s", who, where) != 2){
      write("Send " + who + " " + where + ".\n");
      return 1;
     }
     if(!find_living(who)){
      write(who + " is not playing now.\n");
      return 1;
    }
    if(find_living(where)){
      move_object(find_living(who),environment(find_living(where)));
      return 1;
    }
    move_object(find_living(who),where);
    return 1;
}









force_command(str){

     object ob;
     string who, cmd;
     if(sscanf(str, "%s %s",who,cmd) != 2) {
         return 0;}
     if (!find_player(who)) return 0;
   tell_object(find_player(who), this_player()->query_name()+" forced you to '"+
      cmd+"'.\n");
      command(cmd, find_player(who));
      write("Ok.\n");
      return 1;
}


force_commandsil(str){

     object ob;
     string who, cmd;
     if(!str) { write("Usage : fcs <player> <cmd>\n"); return 1; }
     if (sscanf(str, "%s %s", who, cmd) != 2) {
        write("Usage : fcs <player> <cmd>\n"); return 1; }
     ob = find_living(who);
     if(!ob) { write ("Could not find '"+who+"'.\n"); return 1; }
     command(cmd, ob);
     write("Ok.\n");
     return 1;
     }




force_quit(str){

   string who;
  
   if(sscanf(str, "%s", who) !=1)
     write("Who!\n");
   if(!find_player(who))
     write(who + " is not playing now.\n");
   command("quit", find_player(who));
  return 1;
}





id(str){

     return str == "charge";
}


 short(){
   tell_object(find_living("airwoman"),
   "-=> "+
   capitalize(this_player()->query_real_name())+
   " just examined you.\n");
}


  

long(){
  
  write("Type 'Help' for extra wizard commands.\n");
}



get(){


  if(this_player() && this_player()->query_level() < 21)
     destruct(this_object());
     return 1;

}


  


init_query(){

    if(query_list)
      return query_list;
    query_list = ({
      "query_ac","query_alignment","query_attack","query_auto_load",
      "query_code","query_create_room","query_dir","query_exp",
      "query_frog","query_ghost","query_hit_point","query_hp",
      "query_info","query_intoxination","query_stuffed",
      "query_soaked","query_level","query_listening","query_max_weight",
      "query_money","query_name","query_npc","query_race",
      "query_real_name","query_spell_point","query_title",
      "query_type","query_value","query_wc","query_weight",
      "query_wimpy","query_worn","weapon_class","armor_class",
      "query_age","query_gender_string",
     });
     return query_list;
}


chelp(){

string path;
path = ("/players/"+
       this_player()->query_real_name()+
       "/closed/toyhelp");
command ("more ~/closed/toyhelp", this_player());
return 1;
}
