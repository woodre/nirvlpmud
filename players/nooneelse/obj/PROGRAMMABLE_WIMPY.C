/*
 programmable_wimpy.c - a programmable wimpy
*/

inherit "obj/treasure";

string str, wimpy_direction, direction_str;
int wimpy_on, wimpy_hp, i, made_it;
object my_player, here_obj, enemy_obj;

init() {
  add_action("pwimpydir", "pwimpydir");
  add_action("pwimpydir", "pdir");
  add_action("pwimpyhp",  "pwimpyhp");
  add_action("pwimpyhp",  "php");
  add_action("pwimpy",    "pwimpy");
  add_action("pwimpy",    "pw");
  add_action("drop",      "drop");
  add_action("quit",      "quit");
  add_action("wimpy",     "wimpy");
}

pwimpydir(str) {
  if (!str) {
    write("You must supply a direction.  "+
          "Use: pwimpydir <direction> or pdir <direction>\n"+
          "     pwimpydir clear or pdir clear\n");
    return 1;
  }
  if (str=="clear") str=0;
  if (str=="n") str="north";
  if (str=="e") str="east";
  if (str=="s") str="south";
  if (str=="w") str="west";
  if (str=="ne") str="northeast";
  if (str=="se") str="southeast";
  if (str=="sw") str="southwest";
  if (str=="nw") str="northwest";
  if (str=="d") str="down";
  if (str=="u") str="up";
  wimpy_direction = str;
  if (!wimpy_direction)
    write("Programmable wimpy direction cleared\n");
  else
    write("Programmable wimpy direction set to: "+wimpy_direction+"\n");
  return 1;
}

pwimpyhp(str) {
  if (!str) {
    write("You must supply the number of hit points to wimp at.\n"+
          "Use: pwimpyhp <hp> or php <hp>\n");
    return 1;
  }
  wimpy_hp = 0;
  sscanf(str, "%d", wimpy_hp);
  if (wimpy_hp <= 0) {
    write("You must supply the number of hit points to wimp at.\n"+
          "Use: pwimpyhp <hp>\n");
    return 1;
  }
  write("Programmable wimpy hit points set to: "+wimpy_hp+"\n");
  return 1;
}

pwimpy(str) {
  my_player=environment(this_object());
  if (!str) {
    if (wimpy_on)
      str = "on";
    else
      str = "off";
    write("Programmable wimpy settings:\n"+
          "   Wimpy is           :"+str+"\n"+
          "         direction is :"+wimpy_direction+"\n"+
          "         hp is set at :"+wimpy_hp+"\n");
    return 1;
  }
  if (str=="on") {
    if (my_player->query_wimpy()) {
      write("Normal wimpy must be turned off to use this.\n");
      return 1;
    }
    wimpy_on = 1;
    write("Programmable wimpy turned on.\n");
    write("Programmable wimpy settings:\n"+
          "         direction is :"+wimpy_direction+"\n"+
          "         hp is set at :"+wimpy_hp+"\n");
    return 1;
  }
  if (str=="off") {
    wimpy_on = 0;
    write("Programmable wimpy turned off.\n");
    if (!this_player()->query_wimpy())
      write("\n\nREMEMBER TO TURN NORMAL WIMPY ON!!!\n\n");
    return 1;
  }
}

drop(str) {
  string str2;
  my_player=environment(this_object());
  str2=0;
  if (str) sscanf(str, "wimpy%s", str2);
  if (str=="wimpy" || str=="all" || str2) {
    write("As you drop your programmable wimpy, it crumbles to dust.\n");
    say("As "+my_player->query_name()+
        " drops a programmable wimpy, it crumbles to dust.\n");
    if (!my_player->query_wimpy())
      write("\n\nREMEMBER TO TURN NORMAL WIMPY ON!!!\n\n");
    destruct(this_object());
    if (str=="wimpy") return 1;
    if (str=="all") return;
  }
}

quit(str) {
  drop("wimpy");
  return;
}

wimpy() {
  if (wimpy_on) {
    write("You cannot use wimpy while the programmable wimpy is on.\n");
    return 1;
  }
}

reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(1);
  fill_direction_str();
  enable_commands();
  set_heart_beat(1);
  wimpy_on=0;
}

heart_beat() {
  /* is the wimpy on? is there an enemy present? */
  my_player=environment(this_object());
  here_obj=environment(environment(this_object()));
  if (my_player->query_attack() &&
      present(my_player->query_attack(), here_obj) &&
      (!my_player->query_wimpy() && !wimpy_on))
    tell_object(my_player, "\n\nYOUR PROGRAMMABLE WIMPY IS NOT ON & "+
                           "NEITHER IS YOUR NORMAL WIMPY!!!\n\n");
  if (wimpy_on) {
    enemy_obj=0;
    if (my_player->query_attack() &&
        present(my_player->query_attack(), here_obj))
      enemy_obj=present(my_player->query_attack(), here_obj);
    if (enemy_obj && my_player->query_hp() <= wimpy_hp)
      if (wimpy_direction) {
        command(wimpy_direction, my_player);
        if (environment(environment(this_object()))==here_obj) {
          tell_object(my_player,
            "\n\nYOUR SET WIMPY FAILED!  Trying random directions!!!!\n\n");
          made_it=0;
          for (i = 0; i < 20; i++) {
            command(direction_str[i], my_player);
            if (environment(environment(this_object())) != here_obj) {
              made_it=1;
              break;
            }
          }
          if (made_it)
            write("\nYou wimped: "+direction_str[i]+"\n\n");
          else
             write("\n\nWIMPY FAILED!  RUN!!!!\n\n");
        }
        else
          write("\nYou wimped: "+wimpy_direction+"\n\n");
      }
      else {
        made_it=0;
        for (i = 0; i < 20; i++) {
        command(direction_str[i], my_player);
        if (environment(environment(this_object())) != here_obj) {
          made_it=1;
          break;
        }
        if (made_it)
          write("\nYou wimped: "+direction_str[i]+"\n\n");
        else
           write("\n\nWIMPY FAILED!  RUN!!!!\n\n");
      }
    }
  }
}

query_weight() { return 0; }

short() {
  if (wimpy_on) 
    return "wimpy   {ON, direction="+wimpy_direction+", hp="+wimpy_hp+"}";
  else
    return "wimpy   {OFF, direction="+wimpy_direction+". hp="+wimpy_hp+"}";
}

long() {
  write(
short()+"\n"+
"A programmable wimpy command.\n"+
"Use: pwimpydir <direction> to set the first direction to try or\n"+
"                           {pdir <direction>} or \n"+
"     pwimpydir clear       to clear the wimpydir, but leave wimpy on or\n"+
"                           {pdir clear}\n"+
"     pwimpyhp <hp>         to set the hp's at which you will wimp or\n"+
"                           {php <hp>}\n"+
"     pwimpy [off/on]       to turn the programmable wimpy off or back on\n"+
"                           {pw off/on}\n\n"+
"     pwimpy or pw          to display the programmable wimpy settings\n"+
"\nNOTE:  Setting direction or hp does NOT turn the programmable wimpy on.\n"+
"       They only set it.\n\n"+
"\nWARNING:  Using this device turns off your normal wimpy.\n"+
"          If it fails you're on your own!\n");
  return;
}

id(str){ return (str=="wimpy item" ||
                 str=="wimpy" ||
                 str=="programmable wimpy"); }

fill_direction_str() {
  direction_str = allocate(20);

  direction_str[19]     ="fore";
  direction_str[18]     ="aft";
  direction_str[17]     ="port";
  direction_str[16]     ="starboard";
  direction_str[15]     ="north";
  direction_str[14]     ="east";
  direction_str[13]     ="south";
  direction_str[12]     ="west";
  direction_str[11]     ="northeast";
  direction_str[10]     ="southeast";
  direction_str[9]      ="southwest";
  direction_str[8]      ="northwest";
  direction_str[7]      ="down";
  direction_str[6]      ="up";
  direction_str[5]      ="exit";
  direction_str[4]      ="leave";
  direction_str[3]      ="in";
  direction_str[2]      ="enter";
  direction_str[1]      ="portal";
  direction_str[0]      ="enter portal";
}
