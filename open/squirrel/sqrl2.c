inherit "obj/living.c";

int handnum, gold, flg, starts_thinking;
int atflg;
object yesply, notply;
int busyct;
string short_desc;

short() { return short_desc; }

long(str) {
  write(short()+". It's really cute.\n");
  return;
}

id(str) {
  return str == "squirrel";
}

reset(arg) {
  if (arg) return;

  short_desc = "A squirrel";
  cap_name = "A Squirrel";
  name = "squirrel";
  level = 3;
  experience = 2000;
  max_hp = 99;
  hit_point = 99;
  weapon_class = 5;
  armor_class = 3;
  is_npc = 1;
  alignment = 60;
  enable_commands();
}

heart_beat() {
  age += 1;
  already_fight = 0;
  attack();
}

random_move() {
  int n;

  n = random(4);
  if (n == 0) command("west");
  else if (n == 1) command("east");
  else if (n == 2) command("south");
  else if (n == 3) command("north");
}

living_save(){ return 1;}

