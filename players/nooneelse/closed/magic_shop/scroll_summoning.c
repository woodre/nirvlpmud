/*
  scroll_summon.c - scroll to summon either an elemental or a golem
                  - the read/activation mechanism was inspired by boltar's
                    scrolls on nirvana
*/

int scroll_value;
int elemental_scroll; /* 1=elemental 2=golem */
string elemental_type;
       /* ELEMENTALS=fire, water, earth, air  GOLEMS=wood, earth, stone, iron */
string elemental_name;

init() {
  add_action("read",     "read");
  add_action("read",     "examine");
  add_action("activate", "activate");
}

read(str) {
  if (!str || !id(str)) return;
  long();
  return 1;
}

activate(str) {
  object obj;
  string elemental_golem_msg, a_an;
  if (!str) return 0;
  elemental_name=0;
  sscanf(str, elemental_type+" scroll %s", elemental_name);
  if (!elemental_name) {
    write("You do not name the "+elemental_golem_msg+
          " so the process is stopped.\n");
    return 1;
  }
  if (elemental_scroll)
    elemental_golem_msg="elemental";
  else
    elemental_golem_msg="golem";
  obj=clone_object(
        "/players/nooneelse/closed/magic_shop/scroll_elemental_golem");
  if (elemental_type=="earth" ||
      elemental_type=="air" ||
      elemental_type=="iron")
    a_an="an";
  else
    a_an="a";
  obj->set_creature_type(elemental_scroll); /* 1=elemental 2=golem */
  obj->set_elemental_type(elemental_type);  /* what kind of elemental/golem */
  obj->set_elemental_name(elemental_name);  /* give it a name */
  obj->set_elemental_master(this_player()->query_real_name()); /* set master */
  move_object(obj, environment(this_player()));
  write("The scroll begins to glow, then crumbles to dust.\n"+
        "The dust swirls out of your hands and begins to glow brightly.\n"+
        "It forms the general outling of a huge humanoid, then fades.\n"+
        "As it fades, "+a_an+" "+elemental_type+" "+elemental_golem_msg+
        " appears.\n");
  say(this_player()->query_name()+" reads from a scroll.  It starts to glow\n"+
      "then crumbles into dust.\n"+
      "The dust swirls out of "+this_player()->query_possessive()+
      " hands and begins to glow brightly.\n"+
      "It forms the general outling of a huge humanoid, then fades.\n"+
      "As it fades, "+a_an+" "+elemental_type+" "+elemental_golem_msg+
      " appears.\n", this_player());
  destruct(this_object());
  return 1;
}

reset(arg) { return; }

query_save_flag() { return 1; }

short() {
  string a_an, type_str;
  if (elemental_type=="earth" ||
      elemental_type=="air" ||
      elemental_type=="iron")
    a_an="An";
  else
    a_an="A";
  if (elemental_scroll)
    return a_an+" "+capitalize(elemental_type)+" elemental summoning scroll";
  else
    return a_an+" "+capitalize(elemental_type)+" golem summoning scroll";
}

long() {
  string a_an, type_str;
  if (elemental_type=="earth" ||
      elemental_type=="air" ||
      elemental_type=="iron")
    a_an="an";
  else
    a_an="a";
  if (elemental_scroll)
    type_str=" elemental";
  else
    type_str=" golem";
  write(short()+".\n"+
        "You can't make out most of the words, but you do see that, it will\n"+
        "summon "+a_an+" "+capitalize(elemental_type)+type_str+" "+
        "to fight for you in one battle.\n\n"+
        "To activate it, type:\n"+
        "   activate "+elemental_type+" scroll <critter name>\n"+
        "   (you must supply the "+elemental_type+
        "'s name so you can command it)\n");
  return 1;
}

query_value() { return scroll_value; }
query_weight() { return 1; }

set_scroll_value(arg) { scroll_value=arg; }
set_scroll_type(elemental_scroll);   /* 1=elemental 2=golem */
set_elemental_type(arg) { elemental_type=arg; }
    /* ELEMENTALS=fire, water, earth, air  GOLEMS=wood, earth, stone, iron */

get() { return 1; }
drop() { return 0; }

id(str) {
  return str=="scroll" ||
         str==elemental_type+" summoning scroll" ||
         str==elemental_type+" scroll";
}
