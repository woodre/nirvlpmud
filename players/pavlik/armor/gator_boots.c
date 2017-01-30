inherit "obj/armor";
#define ME capitalize(this_player()->query_name())
#define IT capitalize(ob->query_name())

reset(arg){
 ::reset(arg);
 set_short("Gator-skin Boots");
 set_arm_light(0);
 set_ac(2);
 set_weight(1);
 set_value(5500);
 set_alias("boots");
 set_name("Gator-skin Boots");
 set_type("boots");
 set_save_flag(1);
 set_long(
 "A pair of finely crafted alligator skin boots.  These boots were\n"+
 "obviously made by the hands of a master.  They look really\n"+
 "comfortable to wear and the thick alligator hide provides excellent\n"+
 "protection.  The initials 'MM' are inscribed on the heal.\n");
}

init() {
  ::init();
  add_action("stomp","stomp");
}

stomp(str) {
  object ob;

  if(worn) {
    if(!str) return 0;
    ob = present(str, environment(this_player()));
    if(!living(ob)) return 0;
    write("You stomp on "+IT+"'s foot and ground it to a beefy pulp!\n");
    say(ME+" stomps on "+IT+"'s foot and grounds it to a beefy pulp!\n");
    if(this_player()->query_attack() == ob)
    {
      if(this_player()->query_sp() > 2)
     {
       this_player()->add_sp(-1);
      ob->hit_player(random(3));
    }
     }
    return 1;
  }
}

