/*
  potion_haste.c - speed up a specific action a bit (multiply the # of times)
*/

inherit "obj/treasure";

int potion_used, haste_counter;
string str, hasted_command;

init() {
  ::init();

  add_action("drink",         "drink");
}

drink(str) {
  if (!str || !id(str) || potion_used) return;
  say(this_player()->query_real_name()+
      " drinks from a vial,  which then crumbles to dust.\n", this_player());
  write("You drink the potion and the vial crumbles to dust.\n"+
        "Enter the name of the activity you want to haste.\n"+
        "(Ex: for 'fireball orc' or 'fireball troll' you answer 'fireball'\n"+
        "     for 'demon wrath' you answer 'demon wrath')\n");
  potion_used=1;
  input_to("haste_this");
  return 1;
}

haste_this(str) {
  if (!str) {
    write("Enter the name of the activity you want to haste.\n"+
          "(Ex: for 'fireball orc' or 'fireball troll' you answer 'fireball'\n"+
          "     for 'demon wrath' you answer 'demon wrath')\n");
    input_to("haste_this");
    return 1;
  }
  hasted_command=str;
  add_action("haste_command", hasted_command);
  call_out("trash_this", 300);
  return 1;
}

trash_this() { destruct(this_object()); }

haste_command(str) {
  if (haste_counter==2) {
    haste_counter=0;
    return 0;
  }
  haste_counter++;
  command(hasted_command+" "+str, this_player());
}

reset(arg) {
  if (arg) return;

  set_short("A glass vial");
  set_long("It is a small glass vial filled with a glowing blue liquid.\n");
  set_value(1000);
  set_weight(1);
}

query_save_flag() { return 1; }

short() {
  if (potion_used)
    if (this_player()->query_level()>=21)
      return "Haste potion effects ["+hasted_command+"](only wiz can see)";
    else
      return;
  else
    return "A glass vial";
}

drop() {
  if (potion_used)
    return 1;
  else
    return 0;
}

query_value() {
  if (potion_used)
    return 0;
  else
    return 1000;
}

id(str) { return (str=="vial" ||
                  str=="glass vial" ||
                  str=="small vial" ||
                  str=="small glass vial" ||
                  str=="potion" ||
                  str=="haste potion"); }
