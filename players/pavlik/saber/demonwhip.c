#define tp this_player()->query_name()

int w,n,ahp;

inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;
    
    set_name("demonwhip");
    set_alias("whip");
    set_type("whip");         /* set type added by Pavlik */
    set_alt_name("demon whip");
    set_short("An evil looking whip");
    set_long("An evil looking whip made from tanned human skin.\n"+
             "You could probably 'crack' people with it.\n");
    set_class(16);
    set_weight(2);
    set_value(900);
    set_hit_func(this_object());
}

weapon_hit(attacker){
   w=random(10);
   if (w>6) {
      write("You engulf your foe in a column of fire.\n");
      write("You smell smoke.\n");
      say(tp+" engulfs "+attacker->query_name()+" in a column of raging fire.\n");
      say(tp+" is covered in a dark aura.\n");
      n = random(5);
      ahp = attacker->query_hp();
      if(n>ahp) { n = ahp - 1; }
      attacker->hit_player(n);
      return n;
    }
    return;
}

init() {
  ::init();
add_action("crack", "crack");
       }

crack(str){

  if(!str){
    write("You crack the whip with a loud snap!\n");
    say(tp+" cracks an evil looking whip with a loud snap.\n");
    return 1;   
           }
  str = capitalize(str);
  write("You crack the whip at "+str+", almost taking off an ear!\n");
  say(tp+" cracks an evil looking whip at "+str+", almost taking off an ear!\n");
  return 1;  
           }

quest_ob()  { return 1; }
