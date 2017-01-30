/*
 vampire_bite.c
*/

#include "/players/eurale/defs.h"

inherit "obj/treasure";

int STR,STA,WIL;
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
  set_no_clean(1);

  set_value(0);
  set_weight(0);
  vampire_name_1 = " ";
  vampire_name_2 = " ";
  vampire_name_3 = " ";
  vampire_name_4 = " ";
}

init() {
  add_action("add_a_bite", "addbite");
  add_action("query_bite", "querybite");
}

add_a_bite(str) {
  str = lower_case(str);
  biter_name = str;
  my_name = lower_case(environment(TO)->query_name());
  if (!ok_bite()) return 0;
  if (vampire_name_1 == " ") vampire_name_1 = str;
  else if(vampire_name_2 == " ") vampire_name_2 = str;
  else if(vampire_name_3 == " ") vampire_name_3 = str;
  else if(vampire_name_4 == " ") vampire_name_4 = str;
/*
   1 = 3 bites
   2 = 4 bites
*/
if(number_of_bites <= 1) {
  number_of_bites = number_of_bites+1;
  vampire_obj = find_living(str);
  return 1; }

my_obj = environment(this_object());
my_obj->add_guild_exp(- my_obj->query_guild_exp());
my_obj->add_guild_exp(666);
my_obj->set_guild_name("vampire");
my_obj->set_title("the Newbie Vampire Apprentice");
call_other(MEMBER, "???", 0);
call_other(MEMBER, "add_player", my_obj->query_real_name());
obj = clone_object(FANGS);
move_object(obj, environment(this_object()));

STR = my_obj->query_attrib("str");
STA = my_obj->query_attrib("sta");
WIL = my_obj->query_attrib("wil");
my_obj->add_exp(-(my_obj->query_exp()/100));
my_obj->set_attrib("str",STR -2);
my_obj->set_attrib("sta",STA -2);
my_obj->set_attrib("wil",WIL -2);
ETO->save();

obj->telepathy(
  "From deep in the chest of "+capitalize(my_obj->query_real_name())+
  " comes a death rattle....\n"+
  "They die.... and are reborn a member of the Vampire family.\n");
tell_object(my_obj,
  "Welcome to the Vampire's Guild!\n\n"+
  "You have been given fangs indicating membership.\n"+
  "You can see the cult's command by typing '"+BOLD+"vhelp cult"+NORM+"'.\n");
write_file("/players/eurale/VAMPIRES/BITERS", ctime(time())+"  "+
  capitalize(ETO->query_real_name())+" was REBORN a vampire!\n");
destruct(this_object());
return 1;
}

extra_look() {
  if (number_of_bites == 1)
    str = capitalize(environment(this_object())->query_name())+
        " has a pair of puncture wounds on "+
        environment(this_object())->query_possessive()+" neck";
  else {
    str2 =0;
    if (number_of_bites == 2) str2 = "two";
    if (number_of_bites == 3) str2 = "three";
    if (number_of_bites == 4) str2 = "four";
    if (!str2) str2="too many";
    str=capitalize(environment(this_object())->query_name())+
        " has "+str2+" pairs of puncture wounds on "+
        environment(this_object())->query_possessive()+" neck";
  }
  if(this_player() && present("vampire_fangs", this_player())) {
    write("~:~  This player has been bitten by a vampire!\n");
   }

  return str;
}

query_bite() {
  str = "Status of vampire bite";
  if (environment()->query_real_name())
    str = str+" on "+capitalize(environment()->query_real_name())+":\n";
  else
    str = str+":\n";
  str = str+"     name1 = "+vampire_name_1+"\n"+
          "     name2 = "+vampire_name_2+"\n"+
          "     name3 = "+vampire_name_3+"\n"+
          "     name4 = "+vampire_name_4+"\n"+
          "   # bites="+number_of_bites+"\n";
  write(str);
  return 1;
}

ok_bite() {
  /* Added this in just for me... cause I'm special like that */
  if (this_player()->query_real_name() == "rumplemintz" || 
      this_player()->query_real_name() == "dragnar" ) return 1;
  if (!vampire_name_1 && !vampire_name_2 &&
      !vampire_name_3 && !vampire_name_4)
    return 1;

  /* guild officers can bite all three times */
if(TPGEXP > 670) return 1;

  if ((vampire_name_1 && biter_name == vampire_name_1) ||
      (vampire_name_2 && biter_name == vampire_name_2) ||
      (vampire_name_2 && biter_name == vampire_name_3) ||
      (vampire_name_3 && biter_name == vampire_name_4)) {
    write("You have already bitten this player.  "+
          "You cannot bite them twice.\n");
    return 0;
  }
  return 1;
}

id(str) { return str=="vampire bite" ||
                 str=="vampirebite" ||
                 str=="eurale vampire bite" ||
                 str=="bite"; }

query_auto_load () {
  string whoami;
  whoami=environment()->query_real_name();
  save_object("players/eurale/VAMPIRES/OBJ/bites/"+whoami);
  return "players/eurale/VAMPIRES/OBJ/vampire_bite:"+whoami;
}

init_arg(arg) {
  restore_object("players/eurale/VAMPIRES/OBJ/bites/"+arg);
}  
