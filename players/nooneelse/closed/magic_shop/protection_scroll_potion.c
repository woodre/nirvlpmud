/*
  protection_scroll_potion.c - can be scroll or potion
                             - the read/activation mechanism was inspired by
                               boltar's scrolls on nirvana
*/

int item_activated, item_value, seal_broken;
int this_is_a_scroll; /* 1=scroll; 0=potion */
string spell_name;
object who_obj;

init() {
  add_action("read",         "read");
  add_action("read",         "examine");
  add_action("break_seal",   "break");
  if (this_is_a_scroll)
    add_action("activate",   "activate");
  else
    add_action("drink",      "drink");
}

read(str) {
  if (!str || !id(str) || item_activated) return 0;
  long();
  return 1;
}

break_seal(str) {
  string str2;
  string scroll_potion;
  if (!str || str!="seal" || item_activated) return 0;
  if (this_is_a_scroll)
    scroll_potion="scroll";
  else
    scroll_potion="potion";
  if (seal_broken) {
    write("The wax seal is already broken on the "+scroll_potion+".\n");
    return 1;
  }
  write ("You break the wax seal on the "+scroll_potion+".\n");
  seal_broken = 1;
  say(this_player()->query_name()+" breaks the wax seal on a "+
      scroll_potion+".\n", this_player());
  return 1;
}

activate(str) {
  object obj;
  if (!str || !id(str) || item_activated) return 0;
  if(!seal_broken) {
    write("You need to break the seal first.\n");
    return 1;
  }
  start_spell();
  write("The scroll begins to glow, then crumbles to dust.\n");
  say(this_player()->query_name()+" reads from a scroll.  It starts to glow\n"+
      "then crumbles into dust.\n", this_player());
  item_activated=1;
  return 1;
}

drink(str) {
  object obj;
  if (!str || !id(str) || item_activated) return 0;
  if(!seal_broken) {
    write("You need to break the seal first.\n");
    return 1;
  }
  start_spell();
  write("The potion seems to evaportate as it touches your tongue.\n"+
        "A little tingle surprises you and you drop the empty vial,\n"+
        "which shatters into tiny shards.\n");
  say(this_player()->query_name()+" drinks from a tiny vial, then seems\n"+
      "a little startled and drops the empty vial, which shatters into\n"+
      "tiny shards.\n", this_player());
  item_activated=1;
  return 1;
}

reset(arg) { return; }

query_save_flag() { return 1; }

short() {
  string scroll_potion;
  if (this_is_a_scroll)
    scroll_potion="scroll";
  else
    scroll_potion="potion";
  if (item_activated) {
    if (this_player()->query_level()>=21)
      return capitalize(spell_name)+" "+scroll_potion+
             " effects (only wiz can see)";
    else
      return;
  }
  if (this_is_a_scroll) return "A "+capitalize(spell_name)+" protection scroll";
  if (!seal_broken)
    return "A sealed "+capitalize(spell_name)+" protection potion";
  else
    return "A "+capitalize(spell_name)+" protection potion with a broken seal";
}

long() {
  if (this_is_a_scroll) {
    if (seal_broken) {
      write(short()+".\n"+
            "You can't make out most of the words, but you do see\n"+
            "that, for a time, it gives protection from "+
            capitalize(spell_name)+".\n\n"+
            "To read it, type:      break seal\n"+
            "To activate it, type:  activate "+spell_name+" scroll\n");
      return 1;
    }
    else {
      write(short()+".\n"+
            "You cannot read it until you break the seal.\n");
      return 1;
    }
  }
  write(short()+".\n"+
        "This label on this potion says: "+capitalize(spell_name)+"\n"+
        "You figure that, for a time, it gives protection from "+
        capitalize(spell_name)+".\n\n"+
        "To open it, type:      break seal\n"+
        "To activate it, type:  drink "+spell_name+" potion\n");
  return 1;
}

drop() {
  if (item_activated)
    return 1;
  else
    return 0;
}

query_value() {
  if (item_activated)
    return 0;
  else
    return item_value;
}

query_weight() { return 1; }

set_item_value(arg) { item_value=arg; }
set_spell_name(arg) { spell_name=arg; }
set_this_is_a_scroll(arg) { this_is_a_scroll=arg; } /* 1=scroll; 0=potion */

start_spell() {
  who_obj=environment();
  if (!who_obj || !living(who_obj)) destruct(this_object());
  who_obj->add_immunity(spell_name);
  if (this_is_a_scroll)
    call_out("trash_this", 1200);
  else
    call_out("trash_this", 2400);
}

trash_this() {
  if (who_obj && living(who_obj)) {
    who_obj->remove_immunity(spell_name);
    tell_object(who_obj,
                "\nThe "+capitalize(spell_name)+
                " protection has worn off.\n\n");
  }
  destruct(this_object());
}

id(str) {
  if (item_activated) { return str=="protection spell" || str=="spell"; }

  if (this_is_a_scroll) {
    return str=="scroll" ||
           str==spell_name+" protection scroll" ||
           str==spell_name+" scroll";
  }
  else
    return str=="potion" ||
           str==spell_name+" protection potion" ||
           str==spell_name+" potion";
}
