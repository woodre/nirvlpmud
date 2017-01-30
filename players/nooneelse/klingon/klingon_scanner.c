/*
 klingon_scanner.c
*/

inherit "obj/treasure";

string str;
object view_obj;
int nbr, random_nbr;

init() {
  ::init();

  add_action("scan_item", "scan");
}

scan_item(str) {
  object stuff_obj;
  string who, what;
  int calc_xp;

  if (!str) {
    tell_room(environment(this_player()),
             "The scanner beeps and says:\n"+
        "   Scan what?\n");
    return 1;
  }
  str = lower_case(str);
  view_obj = present(str, environment(this_player()));
  if (!view_obj) {
    tell_room(environment(this_player()),
              "The scanner beeps and says:\n"+
        "   This scanner cannot get a reading on "+str+".\n");
    return 1;
  }
  write("The scanner beeps and says:\n"+
        "   The approximate readings on "+str+" are:\n\n");
  if (this_player()->query_brief()) {
      write(environment(view_obj)->short()+".\n\n");
      write(view_obj->short()+"\n");
  }
  else {
      environment(view_obj)->long();
      write("\n");
      view_obj->long();
  }
  if (present("vampire fangs", view_obj))
    write("guild:        vampire\n");
  if (present("seal", view_obj))
    write("guild:        mason\n");
  if (present("license", view_obj))
    write("guild:        assassin\n");
  if (present("robes", view_obj))
    write("guild:        cleric\n");
  if (present("books", view_obj))
    write("guild:        necromancer\n");
  if (view_obj->query_value()) {
    random_nbr = random(100);
    nbr = view_obj->query_value();
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("value:        "+nbr+"\n");
  }
  if (view_obj->query_weight()) {
    random_nbr = random(100);
    nbr = view_obj->query_weight();
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("weight:       "+nbr+"\n");
  }
  if (view_obj->query_info()) {
    write("info:         "+view_obj->query_info()+"\n");
  }
  if (view_obj->weapon_class()) {
    random_nbr = random(100);
    nbr = view_obj->weapon_class();
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("wc:           "+nbr+"\n");
  }
  if (view_obj->armor_class()) {
    random_nbr = random(100);
    nbr = view_obj->armor_class();
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("ac:           "+nbr+"\n");
  }
  if (view_obj->query_type()) {
    write("armor type:  "+view_obj->query_type()+"\n");
  }
  if (view_obj->query_money()) {
    random_nbr = random(100);
    nbr = view_obj->query_money();
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("money:        "+nbr+"\n");
  }
  if (view_obj->query_level()) {
    random_nbr = random(100);
    nbr = view_obj->query_level();
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("level:        "+nbr+"\n");
  }
  if (view_obj->query_hp()) {
    random_nbr = random(100);
    nbr = view_obj->query_hp();
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("hp:           "+nbr+"\n");
  }
  if (view_obj->query_sp()) {
    random_nbr = random(100);
    nbr = view_obj->query_sp();
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("sp:           "+nbr+"\n");
  }
  if (view_obj->query_wc()) {
    random_nbr = random(100);
    nbr = view_obj->query_wc();
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("weapon class: "+nbr+"\n");
  }
  if (view_obj->query_ac()) {
    random_nbr = random(100);
    nbr = view_obj->query_ac();
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("armor class: "+nbr+"\n");
  }
  if (view_obj->query_alignment()) {
    random_nbr = random(100);
    nbr = view_obj->query_alignment();
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("alignmnet:    "+nbr+"\n");
  }
  if (view_obj->query_exp()) {
    random_nbr = random(100);
    nbr = view_obj->query_exp() / 35;
    if (random_nbr < 45) nbr = nbr - (nbr / random(20));
    else
    if (random_nbr > 65) nbr = nbr + (nbr / random(20));
    write("experience:   "+nbr+"\n");
  }
  return 1;
}

reset(arg) {
  if (arg) return;

  set_short("A Klingon scanner");
  set_long(
    "This is a Klingon scanner.  It is not as good as the Federation\n"+
    "scanners, but you can still use it to get approximate readings on\n"+
    "monsters/players/objects, with:\n"+
    "   scan <what> to get an approximate description of <what>\n");
  set_value(5000);
  set_weight(5);
}

id(str) { return (str=="klingon scanner" || str=="scanner"); }
