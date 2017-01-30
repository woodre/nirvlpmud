/* axe.c: Logger's guild forge-able weapon */
#define MASTER "players/wizardchild/closed/logger/masterob"
inherit "/obj/weapon.c";
reset(arg) {
  if(arg) return 0;
  ::reset(arg);
  set_name("axe");
  set_alias("logger axe");
  set_short("A Logger's axe");
  set_long("A long, sturdy stick, bearing an expensive head. Only a trained person\n"
          +"could handle this.\n");
  set_weight(5);
  set_class(16);
  set_value(2);
  set_hit_func(this_object());
/* i _believe_ this will prevent saving */
  set_save_flag();
}
id(str) { return str == "axe" || str == "logger axe"; }   
weapon_hit() {
  int i;
  object ob, gobj, me;
  i = random(50);
  me = this_player();
  gobj = present("logger pack", me);
  ob = me->query_attack();
  if(i <= 24) {
    if(!gobj) {
      write("You are untrained with this axe, and it slips!\n");  
      say(me->query_name()+" tries to swing the axe and fails!\n");
      me->add_hit_point(-25);
      command("drop logger axe", me);
      write("The axe falls to the ground!\n");
      say(me->query_name()+" looses an axe!\n");
    } else {
      if(i >= 8 && i <= 10) {  /* 3 in 50 chance - 6% */
        write("You swing the axe with deadly accuracy!\n");
        if(i == gobj->query_grank()) {
          write("The blow breaks "+ob->query_name()+"'s arm!\n");
          say(me->query_name()+" breaks "+ob->query_name()+"'s arm with "+MASTER->query_gender_term(me)+" axe!\n");
          return i+2;
        } else {
          write("It skims your foe's scalp!\n");
          say(me->query_name()+" runs "+MASTER->query_gender_term(me)+" axe along "+ob->query_name()+"'s hairline!\n");
          return i/2;
        }
      } 
    }
  }
  return 0;
}
