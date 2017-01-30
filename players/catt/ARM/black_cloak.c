
inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
   set_name("cloak of darkness");
   set_alias("cloak");
   set_short("Cloak of Darkness");
   set_long("This is the mystical cloak of the sorceress \n"+
         "Dairine. It exudes pure darkness and evil.\n");
set_value(1000);
set_weight(4);
set_ac(4);
set_type("armor");
}

int do_special(object c) {
  object e, atk;
  if(!c) return 0;

  if(!(e = environment())) {
    return 0;
  }

  if(!(atk = (object)e->query_attack())) {
    return 0;
  }

  if(!random(5) && (int)atk->query_alignment() > 333) {
   tell_object(e, "Evil floods into you.\n");
    tell_room(environment(e),
   "Evil floods into "+(string)e->query_name()+"\n",({e}));
    e->add_alignment(-(50 + random(50)));
    return 5;
  }
}
