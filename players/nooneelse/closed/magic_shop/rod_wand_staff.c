/*
  rod_wand_staff.c - can be a rod, staff or wand
*/

int item_value, item_weight, nbr_charges, polymorph_monster_nbr;
int this_is_a; /* 0=rod 1=staff 2=wand */
string spell_name, illusion_str;
object illusion_obj;

init() {
  if (this_is_a==0 || this_is_a==2)
    add_action("wave_it", "wave");
  else
    add_action("wave_it", "use");
}

wave_it(str) {
  object obj, target_obj, item_obj, next_obj;
  string target_name, item_name, illusion_text, tmp, tmp2;
  string new_monster_name, new_monster_short, new_monster_long;
  int monster_level, random_nbr;
  if (spell_name=="illusion") str=str+" x";
  sscanf(str, "%s %s", tmp, tmp2);
  if (!str || !id(tmp)) return;
  target_name=0;
  if (this_is_a==0) item_name="rod";
  if (this_is_a==1) item_name="staff";
  if (this_is_a==2) item_name="wand";
  if (spell_name=="illusion") {
    illusion_obj=clone_object("/players/nooneelse/closed/magic_shop/illusion");
    illusion_obj->set_owner(lower_case(this_player()->query_real_name()));
    move_object(illusion_obj, environment(this_player()));
    say(this_player()->query_name()+
        " makes a few gestures and concentrates for a moment.\n");
    write("You make a few gestures and concentrate for a moment and begin to\n"+
          "create an illusion here.\n\n");
    illusion_str=0;
    input_to("illusion_2");
    write("Enter the description of the illusion  (end with **):\n"+
          "ex:\n"+
          "A HUGE black dragon says:  I'm here to kill Hendrek!\n"+
          "**\n\n"+
          "<illusion text>]");
    return 1;
  }
  if (this_is_a==0 || this_is_a==2)
    sscanf(str, item_name+" at %s", target_name);
  else
    sscanf(str, item_name+" on %s", target_name);
  if (!target_name) {
    write("But, "+capitalize(str)+" isn't here.\n");
    return 1;
  }
  target_obj=present(target_name, environment(this_player()));
  if (!target_obj) {
    write("But, "+capitalize(target_name)+" isn't here.\n");
    return 1;
  }
  if (target_obj->query_level()>=21 && this_player()->query_level() < 21) {
    write("You can't activate the device on a wizard!\n");
    return 1;
  }
  if (this_player()->query_level() < 21 &&
      (!target_obj->query_npc() && !target_obj->query_pl_k())) {
    write("You can't damn a player that hasn't set player-killer!\n");
    return 1;
  }
  if (this_player()->query_level() < 21 &&
      !target_obj->query_npc() &&
      !my_player()->query_pl_k()) {
    write("You can't damn a player unless you set player-killer!\n");
    return 1;
  }
  if (spell_name=="magic missile") {
    write(capitalize(target_name)+" shrieks in agony as a magic missile "+
          "streaks from the "+item_name+".\n");
    say(this_player()->query_name()+" aims a "+item_name+" at "+
        capitalize(target_name)+", who shrieks in agony\n"+
        "as a magic missile streaks from it.\n", this_player());
    target_obj->hit_player(5+random(20));
    reduce_charges();
    return 1;
  }
  if (spell_name=="energy bolt") {
    write(capitalize(target_name)+" shrieks in agony as an energy bolt "+
          "streaks from the "+item_name+".\n");
    say(this_player()->query_name()+" aims a "+item_name+" at "+
        capitalize(target_name)+", who shrieks in agony\n"+
        "as an energy bolt streaks from it.\n", this_player());
    target_obj->hit_player(10+random(25));
    reduce_charges();
    return 1;
  }
  if (spell_name=="fireball") {
    write(capitalize(target_name)+" shrieks in agony as a ball of fire "+
          "streaks from the "+item_name+".\n");
    say(this_player()->query_name()+" aims a "+item_name+" at "+
        capitalize(target_name)+", who shrieks in agony\n"+
        "as a ball of firestreaks from it.\n", this_player());
    target_obj->hit_player(15+random(30));
    reduce_charges();
    return 1;
  }
  if (spell_name=="lightning bolt") {
    write(capitalize(target_name)+" shrieks in agony as a lightning bolt "+
          "streaks from the "+item_name+".\n");
    say(this_player()->query_name()+" aims a "+item_name+" at "+
        capitalize(target_name)+", who shrieks in agony\n"+
        "as a lightning bolt streaks from it.\n", this_player());
    target_obj->hit_player(20+random(35));
    reduce_charges();
    return 1;
  }
  if (spell_name=="polymorph") {
    if (target_obj->is_player()) {
      write("You can't activate the device on a player!\n");
      return 1;
    }
    obj=clone_object("obj/monster");
    random_nbr=random(5);
    if (random_nbr==polymorph_monster_nbr) random(5);
    if (random_nbr==polymorph_monster_nbr) random(5);
    if (random_nbr==polymorph_monster_nbr) random(5);
    if (random_nbr==polymorph_monster_nbr) random(5);
    if (random_nbr==polymorph_monster_nbr) random(5);
    polymorph_monster_nbr=random_nbr;
    if (polymorph_monster_nbr==0) {
      new_monster_name="lion";
      new_monster_short="A large male lion";
      new_monster_long="A large, hungry lion glares back at you.\n";
    }
    if (polymorph_monster_nbr==1) {
      new_monster_name="tiger";
      new_monster_short="A large bengal tiger";
      new_monster_long="A large, black & orange tiger glares back at you.\n";
    }
    if (polymorph_monster_nbr==2) {
      new_monster_name="bear";
      new_monster_short="A huge grizzly bear";
      new_monster_long="A huge angry grizzly bear snarls at you.\n";
    }
    if (polymorph_monster_nbr==3) {
      new_monster_name="wyvern";
      new_monster_short="A large wyvern";
      new_monster_long="A large cold looking, reptile glares back at you.\n";
    }
    if (polymorph_monster_nbr==4) {
      new_monster_name="dragon";
      new_monster_short="A small blue dragon";
      new_monster_long=
        "A large cold looking, blue dragon stares back at you.\n";
    }
    obj->set_name(new_monster_name);
    if (random(100) < 49)
      monster_level-=3;
    else
      monster_level+=3;
    monster_level=target_obj->query_level()+monster_level;
    if (monster_level <= 0) monster_level=target_obj->query_level();
    obj->set_level(monster_level);
    obj->set_alias(target_obj->query_name());
/*
    obj->set_hp(target_obj->query_mhp());
    obj->set_ep(target_obj->query_exp());
*/
    obj->set_al(target_obj->query_alignment());
    obj->set_short(new_monster_short);
    obj->set_long(new_monster_long);
/*
    obj->set_wc(target_obj->query_wc());
    obj->set_ac(target_obj->query_ac());
*/
    obj->set_aggressive(target_obj->query_aggressive());
    obj->set_whimpy(target_obj->query_wimpy());
    obj->add_money(target_obj->query_money());
    item_obj = first_inventory(target_obj);
    while (item_obj) {
      next_obj=next_inventory(item_obj);
      move_object(item_obj, obj);
      item_obj=next_obj;
    }
    move_object(obj, environment(this_player()));
    destruct(target_obj);
    write("A violet beam from your "+item_name+" strikes the "+
          capitalize(target_name)+" and its\n"+
          "shape wavers for a moment.  When it solidifies, you see \n"+
          capitalize(new_monster_short)+" standing there.\n");
    say("A violet beam from "+this_player()->query_name()+"'s "+item_name+
        " strikes the "+capitalize(target_name)+" and its\n"+
        "shape wavers for a moment.  When it solidifies, you see \n"+
        capitalize(new_monster_short)+" standing there.\n", this_player());
    reduce_charges();
    return 1;
  }
  return 1;
}

illusion_2(str) {
  if (str=="**") {
    illusion_obj->set_illusion(illusion_str);
    illusion_obj->start_illusion();
    write("The illusion is completed.\n");
    return 1;
  }
  if (!illusion_str)
    illusion_str=str+"\n";
  else
    illusion_str=illusion_str+str+"\n";
  input_to("illusion_2");
  write("<illusion text>]");
  return 1;
}

reset(arg) { return; }

query_save_flag() { return 1; }

short() {
  if (this_is_a==0) return "A rod of "+capitalize(spell_name);
  if (this_is_a==1) return "A staff of "+capitalize(spell_name);
  if (this_is_a==2) return "A wand of "+capitalize(spell_name);
  destruct(this_object());
  return "This object is screwed up!  Destructing!";
}

long() {
  write(short()+" with "+nbr_charges+" charges.\n");
  if (this_is_a==0)
    if (spell_name=="illusion")
      write("To activate it, type:  wave rod\n");
    else
      write("To activate it, type:  wave rod at <who>\n");
  if (this_is_a==1)
    if (spell_name=="illusion")
      write("To activate it, type:  use staff\n");
    else
      write("To activate it, type:  use staff on <who>\n");
  if (this_is_a==2)
    if (spell_name=="illusion")
      write("To activate it, type:  wave wand\n");
    else
      write("To activate it, type:  wave wand at <who>\n");
  return 1;
}

query_value() { return item_value; }
query_weight() { return item_weight; }

set_item_value(arg) { item_value=arg; }
set_spell_name(arg) { spell_name=arg; }
set_this_is_a(arg) {
  this_is_a=arg;
  /* rod */
  if (this_is_a==0) {
    nbr_charges=5;
    item_weight=1;
  }
  /* staff */
  if (this_is_a==1) {
    nbr_charges=10;
    item_weight=2;
  }
  /* wand */
  if (this_is_a==2) {
    nbr_charges=15;
    item_weight=3;
  }
}

reduce_charges() {
  string item_name;
  nbr_charges=nbr_charges-1;
  if (nbr_charges <= 0) {
    if (this_is_a==0) item_name="rod";
    if (this_is_a==1) item_name="staff";
    if (this_is_a==2) item_name="wand";
    write("The "+spell_name+" "+item_name+
          " runs out of charges and crumbles to dust.\n");
    say("As "+this_player()->query_name()+" uses the last charge in "+
        this_player()->query_possessive()+spell_name+" "+item_name+
        " it crumbles to dust.\n", this_player());
    destruct(this_object());
  }
}

get() { return 1; }
drop() { return; }

id(str) {
  if (this_is_a==0) return str=="rod" || str==spell_name+" rod";
  if (this_is_a==1) return str=="staff" || str==spell_name+" staff";
  if (this_is_a==2) return str=="wand" || str==spell_name+" wand";
}

dump() {
  write("item_value="+item_value+"\n");
  write("item_weight="+item_weight+"\n");
  write("nbr_charges="+nbr_charges+"\n");
  write("polymorph_monster_nbr="+polymorph_monster_nbr+"\n");
  write("this_is_a="+this_is_a+" (0=rod 1=staff 2=wand)\n");
  write("spell_name="+spell_name+"\n");
}
