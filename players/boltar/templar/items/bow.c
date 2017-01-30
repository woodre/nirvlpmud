#define tp this_player()
int w;
string use_type;
 inherit "obj/weapon.c";
init() {
  ::init();
  add_action("set_arrows","arrow");
}
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("long bow");
    set_alt_name("longbow");
     set_short("A Composite Long Bow");
    set_long("This long bow is made of strange composite material.\n"+
             "It has a number of pulleys and other additions to improve its.\n"+
             "accuracy. This looks like a weapon of the 20th century.\n"+
             "If you have more than one type of arrow, use: arrow <arrow type>\n"+
             "to set the arrows you wish to use first.\n");
    set_class(4);
    set_weight(4);
    set_type("bow");
    set_value(900);
    set_hit_func(this_object());
}
weapon_hit(attacker){
object att,arrowob;
int t,r,dam;
if(use_type)
arrowob=present(use_type,tp);
if(!arrowob)
arrowob=present("arrow",tp);
att=tp->query_attack();
if(!arrowob) {
  set_type("club");
  write("You have no arrows so you grab your bow like a club and take a\n");
  write("swing at your opponent with the bow.\n");
  return 0;
}
if(!arrowob->query_arrow_ok()) { 
  set_type("club");
  write("Your arrow does not seem to fit this bow.\n");
  write("You use your bow as a club.\n");
  return 0;
}
dam = arrowob->query_arrow_str();
if(att) {
  t = random(100);
  r = arrowob->query_recover();
  if(r == 0) r = 50;
  if(t < r) {
    object yy,uu;
    yy=present("arrows",att);
    if(!yy || yy->query_type() != arrowob->query_type()) {
      uu=clone_object("players/boltar/templar/items/arrows");
      uu->set_short(arrowob->query_short_desc());
      uu->set_long(arrowob->short());
      uu->set_arrow_(dam);
      uu->set_num_ar(1);
      uu->set_value(10);
      uu->set_type(arrowob->query_type());
      uu->set_recover(arrowob->query_recover());
      move_object(uu,att);
   } else {
     yy->add_num_ar(1);
   }
  }
arrowob->use_arrow();
  }
return dam;
}
set_arrows(str) { 
  use_type = str;
  write("You set up your bow to use "+str+".\n");
  return 1;
}
