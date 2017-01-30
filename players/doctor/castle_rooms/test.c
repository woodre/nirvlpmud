string vars;
object stores;
string query_list;

init(){
  if(call_other(this_player(),"query_level")>=21){
    add_action("force_command","force");
    add_action("add_exper","addxp");
    add_action("ck_invis","check");
    add_action("get_player","get");
    add_action("send_player","send");
    add_action("info","info");
  }
}

reset(arg){
  if(arg)
    return;
    query_list = init_query();
}

info(str){
  int i,tmp;
  object person;
  string who;

  if(sscanf(str,"%s",who) != 1)
    write("Who?\n");
  person = find_living(who);
  if(!person)
    write("Not playing.\n");
  if(person){
    write(person);
    write("\n");
    write(call_other(person,"short"));
    write("\n");
    tmp = query_snoop(person);
    if(tmp)
      write("Snooped by " + tmp->query_real_name() + ".\n");
    i = 0;
    while(i < sizeof(query_list)){
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

  if(sccanf(str,"%s",who) != 1)
    write("Who?\n");
  if(!find_player(who))
    write("Not playing.\n");
  else
    move_object(find_player(who),environment(this_player()));
  return 1;
}

send_player(str){
  string who,where;

  if(sscanf(str,"%s %s",who, where) != 2)
    write("Huh?\n.");
  if(!find_player(who))
    write("Not playing.\n");
  else
    move_object(find_player(who),where);
  return 1;
}

ck_invis(str){
  string who;

  if(sscanf(str,"%s",who) != 1)
    write("Who?\n");
  if(find_player(who)->is_invis() > 0)
    write("Yep...invisible.\n");
  else
    write("Not playing.\n");
  return 1;
}

force_command(str){
  object ob;
  string who,cmd,obj,cmd1;
  
  if(sscanf(str,"%s %s %s",cmd,obj,who) != 3){
    if(sscanf(str,"%s %s",cmd,who) != 2){
      return 0;
    }
    command(cmd, find_player(who));
    return "Ok.\n";
  }
  if(sscanf(str,"%s %s %s",cmd,obj,who) == 3){
    cmd1 = cmd + " " + obj;
    command(cmd1,find_player(who));
    return "Ok.\n";
  }
}

add_exper(str){
  string who;
  int amount;

  if(sscanf(str,"%s %d",who,amount) != 2)
    write("Huh?\n");
  find_player(who)->add_exp(amount);
  return "WHAT A GUY!\n";
}

id(str){
  return str == "tag";
}

short(){
  return 0;
}

long(){
  write("A tag\n");
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
    "query_ac",
    "query_alignment",
    "query_attack",
    "query_auto_load",
    "query_code",
    "query_create_room",
    "query_dir",
    "query_exp",
    "query_frog",
    "query_ghost",
    "query_hit_point",
    "query_hp",
    "query_info",
    "query_intoxication",
    "query_stuffed",
    "query_soaked",
    "query_level",
    "query_listening",
    "query_max_weight",
    "query_money",
    "query_name",
    "query_npc",
    "query_race",
    "query_real_name",
    "query_spell_point",
    "query_title",
    "query_type",
    "query_value",
    "query_wc",
    "query_weight",
    "query_wimpy",
    "query_worn",
    "weapon_class",
    "armor_class",
    "query_age",
    "query_gender_string"
    });
  return query_list;
}
