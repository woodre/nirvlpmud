/*
 vampire_bite.c
*/

#include "/players/nooneelse/black/lib/defs.h"

inherit "obj/treasure";

object obj, vampire_bite, vampire_obj, my_obj;
string str, str2, my_name;
string vampire_name_1, vampire_name_2, vampire_name_3, vampire_name_4;
string biter_name;
int number_of_bites;

get() { return 1; }

drop() { return 1; }

query_save_flag() { return 1; }

reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(0);
  vampire_name_1=" ";
  vampire_name_2=" ";
  vampire_name_3=" ";
  vampire_name_4=" ";
}

init() {
  add_action("add_a_bite", "addbite");
  add_action("query_bite", "querybite");
}

add_a_bite(str) {
  str=lower_case(str);
  biter_name=str;
  my_name=lower_case(environment(this_object())->query_name()); 
  if (!ok_bite()) return 0;
  if (vampire_name_1==" ") vampire_name_1=str;
  else
  if (vampire_name_2==" ") vampire_name_2=str;
  else
  if (vampire_name_3==" ") vampire_name_3=str;
  else
  if (vampire_name_4==" ") vampire_name_4=str;
/*
   1 = 3 bites
   2 = 4 bites
*/
  if (number_of_bites <= 1) {
    number_of_bites=number_of_bites+1;
    vampire_obj=find_living(str);
    return 1;
  }
  my_obj=environment(this_object());
  my_obj->add_guild_exp(- my_obj->query_guild_exp());
  my_obj->add_guild_exp(666);
  my_obj->set_guild_name("vampire");
  call_other("players/nooneelse/black/guild_members_room", "???");
  call_other("players/nooneelse/black/guild_members_room", "add_player",
             my_obj->query_real_name());
  obj=clone_object("players/nooneelse/black/vampire_fangs");
  move_object(obj, environment(this_object()));


/* added so Mouzar could get the names of new vamps for his web page easier */
  write_file("/open/mouzar/nv", my_obj->query_real_name());


  obj->telepathy("WELCOME, "+capitalize(my_obj->query_real_name())+
                 ", A NEW MEMBER TO THE VAMPIRE GUILD!");
  tell_object(my_obj,
              "Welcome to the Vampire's Guild!\n\n"+
              "You have been given fangs indicating membership.\n"+
              "You can see the guild's commands by typing 'help guild'.\n");
  destruct(this_object());
  return 1;
}

extra_look() {
  if (number_of_bites==1)
    str=capitalize(environment(this_object())->query_name())+
        " has a pair of puncture wounds on "+
        environment(this_object())->query_possessive()+" neck";
  else {
    str2=0;
    if (number_of_bites==2) str2="two";
    if (number_of_bites==3) str2="three";
    if (number_of_bites==4) str2="four";
    if (!str2) str2="too many";
    str=capitalize(environment(this_object())->query_name())+
        " has "+str2+" pairs of puncture wounds on "+
        environment(this_object())->query_possessive()+" neck";
  }
  return str;
}

query_bite() {
  str="Status of vampire bite";
  if (environment()->query_real_name())
    str=str+" on "+capitalize(environment()->query_real_name())+":\n";
  else
    str=str+":\n";
  str=str+"     name1="+vampire_name_1+"\n"+
          "     name2="+vampire_name_2+"\n"+
          "     name3="+vampire_name_3+"\n"+
          "     name4="+vampire_name_4+"\n"+
          "   # bites="+number_of_bites+"\n";
  write(str);
  return 1;
}

ok_bite() {
  if (!vampire_name_1 && !vampire_name_2 &&
      !vampire_name_3 && !vampire_name_4)
    return 1;

  /* guild officers can bite all three times */
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(biter_name)==GUILD_MASTER) return 1;
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(biter_name)==GUILD_ASSISTANT)
     return 1;
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(biter_name)==GUILD_LIEUTENANT)
     return 1;

  if ((vampire_name_1 && biter_name==vampire_name_1) ||
      (vampire_name_2 && biter_name==vampire_name_2) ||
      (vampire_name_2 && biter_name==vampire_name_3) ||
      (vampire_name_3 && biter_name==vampire_name_4)) {
    write("You have already bitten this player.  "+
          "You cannot bite them twice.\n");
    return 0;
  }
  return 1;
}

id(str) { return str=="vampire bite" ||
                 str=="vampirebite" ||
                 str=="nooneelse vampire bite" ||
                 str=="bite"; }

