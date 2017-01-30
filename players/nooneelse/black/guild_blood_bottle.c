/*
  guild_blood_bottle.c
*/

inherit "obj/treasure";

string str;
int number_of_corpses, healing_in_bottle;

init(arg) {
  if (!living(environment(this_object())) ||
      !present("vampire fangs", environment(this_object())))
    call_out("trash_this", 10);
  add_action("fill_bottle",  "fill");
  add_action("sip_bottle",    "sip");
}

trash_this() { destruct(this_object()); }


fill_bottle(str) {
  object target_obj;
  string str2;
  if (!str || sscanf(str, "%s bottle", str2) != 1) return;
  if (!str2=="blood") return;
  if (number_of_corpses >= 10) {
    write("Your bottle is full!\n");
    return 1;
  }
  target_obj=present("corpse", environment(this_player()));
  if (!target_obj) target_obj=present("corpse", this_player());
  if (!target_obj) {
    write("A corpse must be present to do that.\n");
    return 1;
  }
  number_of_corpses += 1;
  healing_in_bottle=target_obj->heal_value();
  destruct(target_obj);
  this_player()->add_alignment(- 25);
  write("You drain the corpse's blood into your bottle.\n");
  say(capitalize(this_player()->query_name())+
      " drains the corpse's blood into "+this_player()->query_possessive()+
      " bottle.\n");
  return 1;
}

sip_bottle(str) {
  string str2;
  int nbr;
  if (!str || sscanf(str, "%s bottle", str2) != 1) return;
  if (!str2=="blood") return;
  if (number_of_corpses==0) {
    write("Your bottle is empty!\n");
    return 1;
  }
  nbr = healing_in_bottle / number_of_corpses;
  this_player()->heal_self(nbr);
  number_of_corpses -= 1;
  healing_in_bottle = healing_in_bottle - nbr;
  write("You sip blood from your bottle.\n");
  if (number_of_corpses==0) {
    healing_in_bottle=0;
    write("Your bottle is now empty!\n");
    return 1;
  }
  say(capitalize(this_player()->query_name())+
      " sips blood from "+this_player()->query_possessive()+
      " bottle.\n");
  return 1;
}

reset(arg) {
  set_value(0);
  set_weight(1);
}

short() { return "A blood bottle, with the blood of "+number_of_corpses+
                 " corpses in it";
}

long() {
  write(short()+".\n"+
        " You can: fill blood bottle (you need a fresh corpse for this)\n"+
        "          sip from bottle\n\n"+
        " NOTE: if you get one of those 'your sensitive mind...' messages\n"+
        "       when you use this item, try removing your alises dealing\n"+
        "       with the bottle & do it manually.\n");
}

prevent_insert() {
  write("The blood bottle won't fit in there.\n");
  return 1;
}

id(str) { return str=="blood bottle"; }
