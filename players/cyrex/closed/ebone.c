/*
an extract of a larger wiztoy

by Nightshade and Leopard of Nightmare (134.181.1.12 2666)
Leopard (kyle@irie.ais.org)
Nightshade (ktefft@wpi.wpi.edu)

*/
#define WIZ 21
#define LEVEL this_player()->query_level()
#define FILENAME "players/cyrex/private/neon"
#define PLAYERDIR "/players/"+this_player()->query_real_name()+"/"
#define SOULFILE "players/"+this_player()->query_real_name()+"/soul"
#define Call(XXX,YYY,ZZZ) call_other(XXX,YYY,ZZZ)
static object owner_ob,last_arg,seek,seeker,drag,dragger;
static object temp,ob;
static int count;
static string alt_name, path;
static string filename;
static string stats;
static string name;
static string type,file_text,weapon_fname,armor_fname,treasure_fname,filename;static string extra1,extra2,ex_race;
static string longs,arm_type;
static string old_long;
static string chat_str,a_chat_str;
static string short_desc,long_desc,alias,race,spell_mess1,spell_mess2,name;
static string mess1;
static status long;
static int value,weight,old_num,abort_flag;
static int line_num,coins,worn,wielded;
static int chat_chance,in_edit;
static int extra_wc,extra_chance;
static int level,hp,al,wc,ac,aggressive,chance,dam,random_pick,num_chat,num_a_chat;
static int dest_flag;
static int lighted, i;

id(str)  { return str == "wand" || str == "neon green wand" || str == "generator";  }

short()  { return "A ebone wand";  }
long() {
write("A ebone wand which grants your powers to generate\n"+
      "monsters weapons, armors and such. Use the command 'create'\n");
}

get() {
  if(LEVEL >= WIZ) return 1;
  dest_flag = 1;
  return 1;
}

drop() { return 1; }

query_auto_load() { return FILENAME+":"; }

init() {
  if(!dest_flag) {
    if(!present(this_object(),this_player())) return 1;
    if(LEVEL >= WIZ) {
      add_action("make","create");
    }
    set_heart_beat(1);
    return 1;
  }
  write("You are not ready for the powers of a wizard!\n");
  say(this_player()->query_name()+" foolishly thinks himself worthy of a wizardsskills.\n");
  destruct(this_object());
}

make() {
  line_num = 1;
  abort_flag = 0;
  coins = 0;
  type = "";
  weight = 0;
  value = 0;
  longs = allocate(40);
  mess1 = allocate(20);
  if(LEVEL < WIZ) {
    write("Sorry, this is only for wizzes.\n");
    return 1; }
  wielded = 0;
  worn = 0;
  treasure_fname = "";
  weapon_fname = "";
  armor_fname = "";
  in_edit = 0;
  extra1 = "";
  extra2 = "";
  ex_race = "";
  if(chat_str) {
    i = 0;
    while(i < num_chat) {
      chat_str[i] = "";
      i +=1;
    }
  }
  if(a_chat_str) {
    i = 0;
    while(i < num_a_chat) {
      a_chat_str[i] = "";
      i += 1;
    }
  }
  num_chat = 0;
  num_a_chat = 0;
  hp = 0;
  wc = 0;
  ac = 0;
  aggressive = 0;
  chance = 0;
  spell_mess1 = "";
  spell_mess2 = "";
  dam = 0;
  random_pick = 0;
  alias = "";
  write("\n"+
        "The wand will let you make these types of objects:\n"+
        "monster, treasure, weapon, armor.\n"+
        "Please enter a type to create.\n"+
        ": ");
  input_to("start");
  return 1;
}
get_name(str) {
  if(!str || str == "") {
    write("Aborted.\n");
    if(in_edit) {
      main_menu();
      return 1; }
    return 1; }
  name = str;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Alias(optional): ");
  input_to("get_alias");
  return  1; }

get_alias(str) {
  if(str) alias = str;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Short Description: ");
  input_to("get_short");
  return 1;
}

get_short(str) {
  if(!str || str == "") {
    write("Aborted.\n");
    if(in_edit) {
      main_menu();
      return 1; }
    return 1; }
  short_desc = str;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Enter Long Description. End with ** on a blank line.\n");
  input_to("get_long");
  old_long = long_desc;
  long_desc = "";
  write(line_num+">>");
  return 1;
}

get_long(str) {
  if(str == "**") {
    if(in_edit && long_desc == "") {
      long_desc = old_long;
      line_num = old_num;
    }
    if(in_edit) {
      main_menu();
      return 1; }
    if(type != "monster") {
      write("Value: ");
      input_to("get_value");
      return 1; }
    write("Level: ");
    input_to("get_level");
    return 1;
  }
  long_desc = long_desc + str + "\n";
  longs[line_num] = str;
  line_num = line_num + 1;
  write(line_num+">>");
  input_to("get_long");
  return 1;
}

get_level(str) {
  if(!str || str == "") {
    write("Aborted.\n");
    if(in_edit) {
      main_menu();
      return 1;  }
    return 1;
  }
  sscanf(str,"%d",level);
  if(level <1) {
    write("Please enter a valid level.\n");
    write("Level: ");
    input_to("get_level");
    return 1;
  }
  if(in_edit) {
    main_menu();
    return 1; }
  write("HPs(optional): ");
  input_to("get_hp");
  return 1;
}

get_hp(str) {
  if(str && str != "") sscanf(str,"%d",hp);
  if(in_edit) {
    main_menu();
    return 1; }
  write("Race(Enter for Human): ");
  input_to("get_race");
  return 1;
}

get_race(str) {
  if(str && str != "") race = str;
  else race = "human";
  if(in_edit) {
    main_menu();
    return 1; }
  write("Alignment(Enter for 0): ");
  input_to("get_al");
  return 1; }

get_al(str) {
  if(str && str != "") sscanf(str,"%d",al);
  else al = 0;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Chance of "+short_desc+" picking up objects: ");
  input_to("get_random");
  return 1; }

get_random(str) {
  if(str) sscanf(str,"%d",random_pick);
  if(!str || str == "") random_pick = 0;
  if(random_pick > 100) random_pick = 100;
  if(in_edit) {
    main_menu();
    return 1; }
  write("WC(optional): ");
  input_to("get_wc");
  return 1; }

get_wc(str) {
  if(str && str != "") sscanf(str,"%d",wc);
  if(in_edit) {
    main_menu();
    return 1; }
  write("AC(optional): ");
  input_to("get_ac");
  return 1; }

get_ac(str) {
  if(str && str != "") sscanf(str,"%d",ac);
  if(in_edit) {
    main_menu();
    return 1; }
  write("Coins(Enter = 0): ");
  input_to("get_coins");
  return 1; }

get_coins(str) {
  if(!str || str == "") coins = 0;
  else sscanf(str,"%d",coins);
  if(coins < 0) coins = 0;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Aggressive(Enter = 0): ");
  input_to("get_aggressive");
  return 1; }

get_aggressive(str) {
  if(str) sscanf(str,"%d",aggressive);
  if(!str || str == "") aggressive = 0;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Does this monster cast spells? ");
  input_to("spells");
  return 1; }

spells(str) {
  if(str != "n" && str != "no") {
    write("Spell_mess1(Seen by others): ");
    input_to("get_mess1");
    return 1; }
  write("Does this monster talk? ");
  input_to("chats");
  return 1; }

get_mess1(str) {
  if(!str) {
    write("You must enter a spell_mess1");
    write("Spell_mess1: ");
    input_to("get_mess1");
    return 1; }
  spell_mess1 = str;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Spell_mess2(Seen by attacker): ");
  input_to("get_mess2");
  return 1; }

get_mess2(str) {
  if(!str) {
    write("You must enter a spell_mess2");
    write("Spell_mess2: ");
    input_to("get_mess2");
    return 1; }
  spell_mess2 = str;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Spell Damage: ");
  input_to("get_dam");
  return 1; }

get_dam(str) {
  if(str && str != "") sscanf(str,"%d",dam);
  if(!dam) dam = 5;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Spell Chance: ");
  input_to("spell_chance");
  return 1; }

spell_chance(str) {
  if(str && str != "") sscanf(str,"%d",chance);
  if(!chance || chance < 0 || chance > 100) chance = 10;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Can the monster talk? ");
  input_to("chats");
  return 1;
}

chats(str) {
  if(str == "y" || str == "yes") {
    write("Talk Chance(1-100): ");
    input_to("get_chance");
    return 1; }
  write("Weapon filename(Enter = none): ");
  input_to("weapon_fname");
  return 1; }

get_chance(str) {
  if(str && str != "") sscanf(str,"%d",chat_chance);
  if(!chat_chance || chat_chance < 1 || chat_chance > 100) chat_chance = 10;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Number of chats: ");
  input_to("get_num_chats");
  return 1; }

get_num_chats(str) {
  if(str) sscanf(str,"%d",num_chat);
  if(num_chat > 0) {
    write("Chat message 1: ");
    chat_str = allocate(num_chat);
    i = 1;
    input_to("chat_msgs");
    return 1;
  }
  if(in_edit) {
    main_menu();
    return 1; }
  write("Number of attack_chats: ");
  input_to("num_achat");
  return 1;
}

chat_msgs(str) {
  if(str) chat_str[i-1] = str+"\n";
  else chat_str[i-1] = "";
  i += 1;
  if(i > num_chat) {
    if(in_edit) {
      main_menu();
      return 1; }
    write("Number of attack_chats: ");
    input_to("num_achat");
    return 1; }
  write("Chat message "+i+": ");
  input_to("chat_msgs");
  return 1; }

num_achat(str) {
  if(str) sscanf(str,"%d",num_a_chat);
  if(num_a_chat > 0) {
    write("A_Chat message 1: ");
    a_chat_str = allocate(num_a_chat);
    i = 1;
    input_to("achat_msgs");
    return 1; }
  write("Weapon filename(Enter = none): ");
  input_to("weapon_fname");
  return 1; }

achat_msgs(str) {
  if(str) a_chat_str[i-1] = str+"\n";
  else a_chat_str[i-1] = "";
  i += 1;
  if(i <= num_a_chat) {
    write("A_Chat message "+i+": ");
    input_to("achat_msgs");
    return 1; }
  write("Weapon filename(Enter = none): ");
  input_to("weapon_fname");
  return 1; }

weapon_fname(str) {
  if(str && str != "") {
    weapon_fname = PLAYERDIR+str;
    write("Wielded?: ");
    input_to("get_wielded");
    return 1; }
  weapon_fname = "";
  wielded = 0;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Armour filename(Enter = none): ");
  input_to("armor_fname");
  return 1; }

get_wielded(str) {
  if(str == "yes" || str == "y") wielded = 1;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Armour filename(Enter = none): ");
  input_to("armor_fname");
  return 1; }

armor_fname(str) {
  if(str && str != "") {
    armor_fname = PLAYERDIR+str;
    write("Worn?: ");
    input_to("get_worn");
    return 1; }
  worn = 0;
  armor_fname = "";
  if(in_edit) {
    main_menu();
    return 1; }
  write("Treasure filename(Enter = none): ");
  input_to("treasure_fname");
  return 1; }

get_worn(str) {
  if(str == "y" || str == "yes") worn = 1;
  if(in_edit) {
    main_menu();
    return 1; }
  write("Treasure filename(Enter = none): ");
  input_to("treasure_fname");
  return 1; }

treasure_fname(str) {
  if(str && str != "") treasure_fname =
    PLAYERDIR+str;
  else treasure_fname = "";
  main_menu();
  return 1; }

start(str) {
if(!str) {
write("Aborted.\n");
return 1; }
if(str == "monster" || str == "weapon" || str == "armor" || str == "treasure"){
type = str;
write("Name: ");
input_to("get_name");
return 1; }
write("Invalid type.\n");
write(": ");
input_to("start");
return 1;
}
main_menu() {
in_edit = 1;
if(type == "monster") {
write("Object: Monster\n");
write("\n");
write("1) Name            : "+name+"\n");
write("2) Alias           : ");
if(alias && alias != "") write(alias+"\n");
else write("(Not Defined)\n");
write("3) Race            : "+race+"\n");
write("4) Short           : "+short_desc+"\n");
write("5) WC              : ");
if(wc) write(wc+"\n");
else write("Default\n");
write("6) AC              : ");
if(ac) write(ac+"\n");
else write("Default\n");
write("7) HP              : ");
if(hp) write(hp+"\n");
else write("Default\n");

write("8) Level           : "+level+"\n");
write("9) Alignment       : "+al+"\n");
 write("10) Aggressive     : "+aggressive+"\n");
write("11) Chance/Take    : "+random_pick+"\n");
write("12) Coins          : "+coins+"\n");
write("13) Spell Message 1: ");
if(spell_mess1 && spell_mess1 != "") write(spell_mess1+"\n");
else write("(Not Defined)\n");
write("14) Spell Message 2: ");
if(spell_mess2 && spell_mess2 != "") write(spell_mess2+"\n");
else write("(Not Defined)\n");
write("15) Spell Chance   : "+chance+"\n");
write("16) Spell Damage   : "+dam+"\n");
write("17) Number/Chats   : ");
if(num_chat > 0) write(num_chat+"\n");
else write("(Not Defined)\n");
write("18) Number/A_Chats : ");
if(num_a_chat > 0) write(num_a_chat+"\n");
else write("(Not Defined)\n");
write("19) Weapon filename: ");
if(weapon_fname != "") {
write(weapon_fname);
if(wielded) write(" (wielded)\n");
else write("\n"); }
else write("(Not Defined)\n");
write("20) Armour filename: ");
if(armor_fname != "") {
write(armor_fname);
if(worn) write(" (worn)\n");
else write("\n");
   }
else write("(Not Defined)\n");
write("21) Treasure fname : ");
if(treasure_fname != "") write(treasure_fname+"\n");
else write("(Not Defined)\n");
write("22) Edit Long Description");
write("\n");
   }
if(type == "treasure") {
write("Object: Treasure\n");
write("1) Name           : "+name+"\n");
write("2) Alias          : ");
if(alias != "") write(alias+"\n");
else write("(Not Defined)\n");
write("3) Short          : "+short_desc+"\n");
write("4) Value          : "+value+"\n");
write("5) Weight         : "+weight+"\n");
write("6) Edit Long Description.\n");
   }
if(type == "armor") {
write("Object: Armour\n");
write("1) Name           : "+name+"\n");
write("2) Alias          : ");
if(alias != "") write(alias+"\n");
else write("(Not Defined)\n");
write("3) Short          : "+short_desc+"\n");
write("4) Value          : "+value+"\n");
write("5) Weight         : "+weight+"\n");
write("6) Armour Class   : "+ac+"\n");
write("7) Type           : "+arm_type+"\n");
write("8) Edit Long Description.\n");
   }
if(type == "weapon") {
write("Object: Weapon\n");
write("1) Name           : "+name+"\n");
write("2) Alias          : ");
if(alias != "") write(alias+"\n");
else write("(Not Defined)\n");
write("3) Short          : "+short_desc+"\n");
write("4) Value          : "+value+"\n");
write("5) Weight         : "+weight+"\n");
write("6) Weapon Class   : "+wc+"\n");
write("7) Extra Hit msg 1: ");
if(extra1 != "") write(extra1 + "\n");
else write("(Not Defined)\n");
write("8) Extra Hit msg 2: ");
if(extra2 != "") write(extra2 + "\n");

else write("(Not Defined)\n");
write("9) Extra Hit WC+  : ");
if(extra_wc) write(extra_wc+"\n");
else write("(Not Defined)\n");
write("10) Extra Chance  : ");
if(extra_chance) write(extra_chance+"\n");
else write("(Not Defined)\n");
write("11) Extra hit race: ");
if(ex_race != "") write(ex_race+"\n");
else write("ALL\n");
write("12) Edit Long Description.\n");
  }
write("\nw)rite e)dit q)uit r)ead long: ");
input_to("main_edit");

return 1; }
main_edit(str) {
if(str == "q") return 1;
if(str == "e") {
write("Edit Which?: ");
input_to(type+"_edit");
return 1; }
if(str == "w") {
write("Filename: ");
input_to("write_"+type);
return 1; }
if(str == "r") {
write("-----\nLong:\n-----\n"+long_desc);
main_menu();
return 1; }
main_menu();
return 1; }
treasure_edit(str) {
sscanf(str,"%d",i);
if(i==1) {
write("Name: ");
input_to("get_name");
return 1; }
if(i==2) {
write("Alias: ");
input_to("get_alias");
return 1; }
if(i==3) {
write("Short: ");
input_to("get_short");
return 1; }
if(i==4) {
write("Value: ");
input_to("get_value");
return 1; }
if(i==5) {
write("Weight: ");
input_to("get_weight");
return 1; }
if(i==6) {
write("Enter Long Description. End with ** on a blank line.\n");
write("1>>");
old_num = line_num;
line_num = 1;
old_long = long_desc;
long_desc = "";
input_to("get_long");
return 1; }
main_menu();
return 1; }
weapon_edit(str) {
sscanf(str,"%d",i);
if(i==1) {
write("Name: ");
input_to("get_name");
return 1; }
if(i==2) {
write("Alias: ");
input_to("get_alias");
return 1; }
if(i==3) {
write("Short: ");
input_to("get_short");
return 1; }
if(i==4) {
write("Value: ");
input_to("get_value");
return 1; }
if(i==5) {
write("Weight: ");
input_to("get_weight");
return 1; }
if(i==6) {
write("Weapon Class: ");
input_to("weapon_class");
return 1; }
if(i==7) {
write("$MN$ = Monster name, $TP$ = Player name, $CR$ = carriage return.\n");
write("Extra String 1: ");
input_to("get_extra1");
return 1; }
if(i==8) {
write("$MN$ = Monster name, $TP$ = Player name, $CR$ = carriage return.\n");
write("Extra String 2: ");
input_to("extra2");
return 1; }
if(i==9) {
write("WC+ in an extra hit(1-10): ");
input_to("extra_wc");
return 1; }
if(i==10) {
write("Chance of extra hit(1-100): ");
input_to("extra_chance");
return 1; }
if(i==11) {
write("Does this extra hit work on only one race?\nRace(Enter for all): ");
input_to("ex_race");
return 1;
 }
if(i==12) {
write("Enter Long Description. End with ** on a blank line.\n");
write("1>>");
old_num = line_num;
line_num = 1;
old_long = long_desc;
long_desc = "";
input_to("get_long");
return 1; }
main_menu();
return 1; }
armor_edit(str) {
sscanf(str,"%d",i);
if(i==1) {

write("Name: ");
input_to("get_name");
return 1; }
if(i==2) {
write("Alias: ");
input_to("get_alias");
return 1; }
if(i==3) {
write("Short: ");
input_to("get_short");
return 1; }
if(i==4) {
write("Value: ");
input_to("get_value");
return 1; }
if(i==5) {
write("Weight: ");
input_to("get_weight");
return 1; }
if(i==6) {
write("Armour Class: ");
input_to("armor_class");
return 1; }
if(i==7) {
write("Armour Type: ");
input_to("get_arm");
return 1; }
if(i==8) {
write("Enter Long Description. End with ** on a blank line.\n");
old_num = 1;
line_num = 1;
old_long = long_desc;
long_desc = "";
write("1>>");
input_to("get_long");
return 1; }
main_menu();
return 1; }
write_monster(str) {
string test;
string temp;
string slask;
file_text = "";
slask = "\\nx";
check_name(str);
if(abort_flag) {
abort_flag = 0;
main_menu();
return 1; }
add_line("");
add_line("inherit\"obj/monster\";");
add_line("reset(arg) {");
if(coins) add_line("object money;");
if(armor_fname != "") add_line("object armor;");
if(weapon_fname != "") add_line("object weapon;");
if(treasure_fname != "") add_line("object treasure;");
if(num_chat || num_a_chat) {
if(num_chat) add_line("string chat_str;");
if(num_a_chat) add_line("string a_chat_str;");
  }
add_line("::reset(arg);");
add_line("if(arg) return;");
if(num_chat && !num_a_chat) add_line("if(!chat_str) {");
if(num_a_chat && !num_chat) add_line("if(!a_chat_str) {");
if(num_chat && num_a_chat) add_line("if(!chat_str) {");
if(num_chat || num_a_chat) {
if(num_chat) add_line("chat_str = allocate("+num_chat+");");
if(num_a_chat) add_line("a_chat_str = allocate("+num_a_chat+");");
i = 0;
if(num_chat) {
while(i<num_chat) {
sscanf(chat_str[i],"%s\n",temp);
add_line("chat_str["+i+"] = \""+temp+extract(slask,0,0)+"n\";");
i += 1;
   }
 }
if(num_a_chat) {
i=0;
while(i < num_a_chat) {
sscanf(a_chat_str[i],"%s\n",temp);
add_line("a_chat_str["+i+"] = \""+temp+extract(slask,0,0)+"n\";");
i += 1;
   }
 }
add_line("  }");
 }
add_line("set_name(\""+name+"\");");
if(alias && alias != "") add_line("set_alias(\""+alias+"\");");
add_line("set_short(\""+short_desc+"\");");
i=1;
add_long();
add_line("set_level("+level+");");
add_line("set_race(\""+race+"\");");
if(hp) add_line("set_hp("+hp+");");
if(al) add_line("set_al("+al+");");
if(wc) add_line("set_wc("+wc+");");
if(ac) add_line("set_ac("+ac+");");
if(aggressive) add_line("set_aggressive(1);");
if(chance) add_line("set_chance("+chance+");");
if(dam) add_line("set_spell_dam("+dam+");");
if(spell_mess1 && spell_mess1 != "")
add_line("set_spell_mess1(\""+spell_mess1+"\");");
add_line("set_spell_mess2(\""+spell_mess2+"\");");
if(num_chat && chat_str != "")
add_line("load_chat("+chat_chance+",chat_str);");
if(num_a_chat && a_chat_str != "")
add_line("load_a_chat("+chat_chance+",a_chat_str);");
if(random_pick) add_line("set_random_pick("+random_pick+");");
if(coins) {
add_line("money = clone_object(\"obj/money\");");
add_line("money->set_money("+coins+");");
add_line("move_object(money, this_object());");
}
if(armor_fname != "") {
add_line("armor = clone_object(\""+armor_fname+"\");");
add_line("if(armor) {");
add_line("move_object(armor,this_object());");
if(worn) add_line("command(\"wear \"+armor->query_name());");
add_line("  }");
   }
if(weapon_fname != "") {
add_line("weapon = clone_object(\""+weapon_fname+"\");");
add_line("if(weapon) {");
add_line("move_object(weapon,this_object());");
if(wielded) add_line("command(\"wield \"+weapon->query_name());");
add_line("   }");
   }
if(treasure_fname != "") {
add_line("treasure = clone_object(\""+treasure_fname+"\");");
add_line("if(treasure) move_object(treasure,this_object());");
    }
add_line("}");
write_it();
return 1;
}
add_line(str) {
if(file_text == 0) file_text = "";
file_text = file_text +str+"\n";
}
add(str) {
if(file_text == 0) file_text = "";
file_text = file_text +str;
}
monster_edit(str) {
if(!str && str == "") main_menu();
sscanf(str,"%d",i);
if(i==1) {
write("Name: ");
input_to("get_name");
return 1; }
if(i==2) {
write("Alias: ");
input_to("get_alias");
return 1; }
if(i==3) {
write("Race(Enter for Human): ");
input_to("get_race");
return 1; }
if(i==4) {
write("Short Description: ");
input_to("get_short");
return 1; }
if(i==5) {
write("WC(optional): ");
input_to("get_wc");
return 1; }
if(i==6) {
write("AC(optional): ");
input_to("get_ac");
return 1; }
if(i==7) {
write("HPs(optional): ");
input_to("get_hp");
return 1; }
if(i==8) {
write("Level: ");
input_to("get_level");
return 1; }
if(i==9) {
write("Alignment(Enter for 0): ");
input_to("get_al");
return 1; }
if(i==10) {
write("Aggressive(Enter = 0): ");
input_to("get_aggressive");
return 1; }
if(i==11) {
write("Chance of "+short_desc+" picking up objects: ");
input_to("get_random");
return 1; }
if(i==12) {
write("Coins(Enter = 0): ");
input_to("get_coins");
return 1; }
if(i==13) {
write("Spell_mess1(Seen by others): ");
input_to("get_mess1");
return 1; }
if(i==14) {
write("Spell_mess2(Seen by attacker): ");
input_to("get_mess2");
return 1; }
 if(i==15) {
write("Spell Chance: ");
input_to("spell_chance");

return 1; }
if(i==16) {
write("Spell Damage: ");
input_to("get_dam");
return 1; }
if(i==17) {
write("Number of Chats: ");
input_to("get_num_chats");
return 1; }
if(i==18) {
write("Number of attack_chats: ");
input_to("num_achat");
return 1; }
if(i==19) {
write("Weapon filename(Enter = none): ");
input_to("weapon_fname");
return 1; }
if(i==20) {
write("Armour filename(Enter = none): ");
input_to("armor_fname");
return 1; }
if(i==21) {
write("Treasure filename(Enter = none): ");

input_to("treasure_fname");
return 1; }
if(i==22) {
write("Enter Long Description. End with ** on a blank line.\n");
old_num = line_num;
line_num = 1;
write("1>>");
old_long = long_desc;
long_desc = "";
input_to("get_long");
return 1; }
main_menu();
return 1; }

get_value(str) {
if(str != "") sscanf(str,"%d",value);
if(in_edit) {
main_menu();
return 1; }
write("Weight: ");
input_to("get_weight");
return 1; }
get_weight(str) {
if(str != "") sscanf(str,"%d",weight);
if(in_edit) {
main_menu();
return 1; }
if(type == "treasure") {
main_menu();
return 1; }
if(type == "weapon") {
write("Weapon Class: ");
input_to("weapon_class");
return 1; }
if(type == "armor") {
write("Armour Class: ");
input_to("armor_class");
return 1; }
return 1; }

static weapon_class(str) {
if(!str || str == "") {
write("You must enter a weapon class.\nWeapon Class: ");
input_to("weapon_class");
return 1; }
sscanf(str,"%d",wc);
if(in_edit) {
main_menu();
return 1; }
write("Does the "+short_desc+" have extra hits?: ");
input_to("does_extra");
return 1; }
does_extra(str) {
if(str != "y" && str != "yes") {
main_menu();
return 1; }
write("This message is seen by others in the room."+
"  The next message will be the one\n"+
"that is printed to the wielder of the weapon.\n");
print_macros();
write("Extra String 1: ");
input_to("get_extra1");
return 1; }
get_extra1(str) {
if(str != "") extra1 = str;
else extra1 = "$MN$ is slammed by $TP$'s "+name+".";
if(in_edit) {
main_menu();
return 1; }
write("This message is the one printed to the wielder"+
" of the weapon during an extra\n"+
"hit.\n");
print_macros();
write("Extra string 2: ");
input_to("extra2");
return 1; }
extra2(str) {
if(str != "") extra2 = str;
else extra2 = "$MN$ is slammed by your "+name+".";
if(in_edit) {
main_menu();
return 1; }
write("WC+ in an extra hit(1-10): ");
input_to("extra_wc");
return 1; }
extra_wc(str) {
if(str != "") sscanf(str,"%d",extra_wc);
if(extra_wc < 1 || extra_wc > 10) extra_wc = 2;
if(in_edit) {
main_menu();
return 1; }
write("Chance of extra hit(1-100): ");
input_to("extra_chance");
return 1; }
extra_chance(str) {
if(str != "") sscanf(str,"%d",extra_chance);
if(extra_chance < 1 || extra_chance > 100) extra_chance = 20;
if(in_edit) {
main_menu();
return 1; }
write("Does the extra hit work on only one race?\nRace(Enter for all): ");
input_to("ex_race");
return 1; }
static armor_class(str) {
if(str != "") sscanf(str,"%d",ac);
if(!ac) ac = 1;
if(in_edit) {
main_menu();
return 1; }
write("Armour type: ");
input_to("get_arm");
return 1;
  }
get_arm(str) {
if(str != "") arm_type = str;
if(str != "helmet" && str != "amulet" && str != "armor" && str != "shield" &&
str != "ring" && str != "glove" && str != "cloak" && str != "boot") {
write("Valid armor types are:\n\nhelmet, amulet, armor, shield,"+
" ring, glove, cloak, and boot.\n\n");

write("Armour type: ");
input_to("get_arm");
return 1; }
main_menu();
return 1; }
add_long() {
string slask;
i= 1;
slask = "\\nx";
if(long_desc != "") {
add_line("set_long(");
while(i<line_num) {
if(i>1) add("+ ");
add("\"");
add(longs[i]);
add(extract(slask,0,0));
add("n\"");
if(i == line_num - 1) add_line(");");
else add_line("");
i += 1;
   }
 }
}
write_treasure(str) {
string test;
string t1,t2;
check_name(str);
if(abort_flag) {
abort_flag = 0;
main_menu();
return 1; }
file_text = "";
add_line("inherit\"obj/treasure\";");
add_line("reset(arg) {");
add_line("if(arg) return;");
add_line("set_id(\""+name+"\");");
if(alias != "") add_line("set_alias(\""+alias+"\");");
add_line("set_short(\""+short_desc+"\");");
add_long();
add_line("set_value("+value+");");
add_line("set_weight("+weight+");");
add_line("}");
write_it();
return 1; }
write_armor(str) {
string test;
file_text = "";
check_name(str);
if(abort_flag) {
abort_flag = 0;
main_menu();
return 1; }
add_line("inherit\"obj/armor\";");
add_line("reset(arg) {");
add_line("::reset(arg);");
add_line("if(arg) return;");
add_line("set_name(\""+name+"\");");
if(alias != "") add_line("set_alias(\""+alias+"\");");
add_line("set_short(\""+short_desc+"\");");
add_long();
add_line("set_weight("+weight+");");
add_line("set_value("+value+");");
add_line("set_ac("+ac+");");
add_line("set_type(\""+arm_type+"\");");
add_line("}");
write_it();
return 1; }

write_weapon(str) {
string slask;
string test;
check_name(str);
if(abort_flag) {
abort_flag = 0;
main_menu();
return 1; }
file_text = "";
slask = "\\nx";
add_line("inherit\"obj/weapon\";");
add_line("reset(arg) {");
add_line("::reset(arg);");
add_line("if(arg) return;");
add_line("set_name(\""+name+"\");");
if(alias != "") add_line("set_alias(\""+alias+"\");");
add_line("set_short(\""+short_desc+"\");");
add_long();
add_line("set_value("+value+");");
add_line("set_weight("+weight+");");
add_line("set_class("+wc+");");
if(extra1 != "" && extra2 != "" && extra_wc && extra_wc)
add_line("set_hit_func(this_object());");
add_line("}");
if(extra1 != "" && extra2 != "" && extra_wc && extra_chance) {
add_line("weapon_hit(attacker) {");
if(ex_race != "") add_line("if(random(100)<"+extra_chance+" && attacker->query_race() == \""+ex_race+"\") {");
else add_line("if(random(100) < "+extra_chance+") {");
add("write(");
parse(extra2);
add_extra();
add_line("");
add("say(");
parse(extra1);
add_extra();
add_line("");
add_line("return "+extra_wc+";");
add_line("   }");
add_line("return 0;");
add_line(" }");
    }
write_it();
return 1; }
ex_race(str) {
if(str != "") ex_race = str;
else ex_race = "";
main_menu();
return 1; }
write_it() {
filename =
PLAYERDIR+filename+".c";
if(file_size(filename) >= 0) {
write("Warning! "+filename+" exists! Overwrite? (y/n): ");
input_to("write_ok");
return 1; }
save_file();
return 1; }
write_ok(str) {
if(str != "y" && str != "yes") {
main_menu();
return 1; }
rm(filename);
save_file();
return 1;  }
save_file() {
write_file(filename,file_text);
if(file_size(filename) < 0) {
write("Error: Could not write file.\n");

main_menu();
return 1; }
write("\nDone.. "+short_desc+" created.\n");
write("Do you want to create another object?: ");
input_to("make_more");
}
check_name(str) {
string t1,t2;
if(sscanf(str,"%s.%s",t1,t2)>0) {
write(". and .. are not allowed in filenames!\(\".c\" is automatically added.)\n");
write("\n");
abort_flag = 1; }
else filename = str;
   }
make_more(str) {
if(str ==  "y" || str == "yes") {
make();
return 1; }
return 1; }

parse(str) {
string cmd;
if(!str) return;
i = 0;
while(i < 20) {
mess1[i] = "";
i += 1;
}
mess1[0] = str;
i = 0;
while(sscanf(mess1[i],"%s$%s$%s",mess1[i],cmd,mess1[i+2]) >0) {
if(cmd == "MN" || cmd == "TP" || cmd == "CR") {
mess1[i+1] = cmd;
i += 2;
    }
else { mess1[i+1] = "";
i += 2; }
 }
}
add_extra() {
int k;
k = 0;
while(k < i+1) {
if(k==1 && mess1[0] != "") add("+");
if(k > 1 && mess1[k] != "") add("+");
if(mess1[k]=="TP") add("this_player()->query_name()");
else if(mess1[k]=="MN") add("attacker->query_name()");
else if(mess1[k]=="CR") {
add("\""+extract("\\nx",0,0)+"n");
if(k<i) add("\"");
      }
else if(mess1[k] != "") {
add("\""+mess1[k]);
if(k < i) add("\"");
   }
k += 1;
  }
if(find_last() == "MN" || find_last() == "TP") add("+\"");
add(extract("\\nx",0,0)+"n\");");
  }
print_macros() {
write("The following symbols can be placed in your message."+
" The wand will convert\n"+
"them while writing the file for this weapon.\n");
write("Command -- Function\n");
write("   $MN$ -- includes monster's name in message.\n");
write("   $TP$ -- includes this player's name in message.\n");
write("   $CR$ -- includes a carriage return in message.\n");
write("\nNote: No spaces are needed between these commands.\n");
}
find_last() {
int k;
k = i;
while(k  >= 0) {
if(mess1[k] != "") return mess1[k];
k -= 1;
   }
}
