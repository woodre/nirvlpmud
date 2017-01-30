/* boots.c: boots of gorp */
inherit "obj/armor";
reset(arg) {
  if(arg)
    return ;
  set_name("boots");
  set_short("Boots of Gorp (sloshy)");
  set_long("These are the mystical Boots of Gorp.\n"
          +"By their appearance, you see nothing unordinary. However, at a\n"
          +"closer look, you notice that their sloshiness would be a defensive\n"
          +"advantage.\n");
  set_ac(1);
set_type("boots");
  set_value(200);
  set_weight(2);
  call_out("random_func", 1500);
}
id(str) { return str == "boots" || str == "boots of gorp"; }
random_func() {
  object ob;
  ob = environment(this_object());
  if(ob && living(ob) && environment(ob) && ob->query_attack()) {
    tell_object(ob, "Your Boots of Gorp suddenly slosh and contort, and assault your foe!\n");
    say(ob->query_name()+"'s Boots of Gorp fly off and nail ");
    ob = ob->query_attack();
    say(ob->query_name()+" in the head!\n");
    tell_object(ob, "You are hit in the head with the Boots of Gorp!\n");
    ob->heal_self(-(random(10)));
    environment(this_object())->add_weight(-query_weight());
    if(ob->add_weight(query_weight()))
      move_object(this_object(), ob);
    else
      move_object(this_object(), environment(ob));
  } else
    call_out("random_func", 1500);
}
