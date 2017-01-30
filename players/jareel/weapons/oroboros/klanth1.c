#include "/players/jareel/ansi.h"
#include "/players/jareel/define.h"
inherit "/obj/weapon.c";

  int disrupt;
  int flame;
  int MAGIC;

  reset(arg){
    ::reset(arg);
    if(arg) return 1;

  set_alt_name("klanth");

  get_short();
  set_class(19);
  set_type("sword");
  set_weight(1);
  set_value(8000);
  set_long(
    "This elegant blade is composed of a very lite white bone.  The blade\n"+
    "is very sharp and holds a perfect edge.  The hilt of the blade holds\n"+
    "two separate spell matrix.  The blade has the perfect balence for\n"+ 
    "fast attacks.\n");

  set_read("\n"+
    ""+BOLD+"The three matrix on the hit read as such.\n\n"+
    "   "+BOLD+"disrupt"+NORM+"     25sp\n"+
    "   "+BOLD+"flame"+NORM+"     25sp\n"+
    "\n"+ 
    "\n");

  set_hit_func(this_object());
}

  weapon_hit(attacker){
    int i;
      if(flame != 1){
    return 0;
}

  i = random(10);
    if(i<5){
      tell_room(environment(this_player()),
                 "\n\n"+
      BOLD+BLINK+YEL+" F L A M E S"+NORM+" splinter off the Klanth.\n\n");
    attacker->hit_player(2+random(3), "other|fire");}

  if(i==9){
    write(BOLD+"\nThe klanth's"+BOLD+YEL+" Flame burns"+NORM+" as it bites into "+this_player()->query_attack()->query_name()+".\n\n");
  attacker->hit_player(4+random(3), "other|fire");}
}

  init(){
    ::init();
      add_action("klanth_blast","disrupt");
      add_action("flameon","flame");
  }

  check_wielded(){
    if(this_player()->query_weapon() == this_object()){
  return 1;
  }
  else {
    notify_fail(BOLD+"You must be wielding the Klanth to use its powers.\n"+NORM);
  return 0;
}}

  check_magic(){
    int i;
      i = this_player()->query_attrib("int");
        if(i > 30) i = 30;
        if(i < 0) i = 0;
    return i;
}

  flameon(){
     int time;
       MAGIC = check_magic();
         if(check_wielded() == 0) return 0;
         if(this_player()->query_spell_point() < 25){
           notify_fail(BOLD+"You lack the energy to charge the Klanth.\n"+NORM);
         return 0;}

     this_player()->add_spell_point(-25);
       flame = 1;

     get_short();
       time = ((1500+random(500))*MAGIC)/20;
         call_out("remove_energy",time);
       write("\nYou invoke the Flame Matrix.\n\n"+
         "        "+BOLD+BLINK+YEL+"F L A M E S "+NORM+"erupt over your blade.\n\n");
     return 1;}

     remove_energy(){
       write("The Klanth's flame fades.\n");
       say("The flame from the klanth gos out.\n");

     flame = 0;

     get_short();
     return 1;
}

  static klanth_blast(str){
    int dam;
      string at_msg,vi_msg,rm_msg;
      MAGIC = check_magic();
      if(check_wielded() == 0) return 0;
      if(!this_player()->query_attack()){
        notify_fail(BOLD+"You must be in combat to use this matrix.\n"+NORM);
      return 0;}

      if(this_player()->query_spell_point() < 25){
        notify_fail(BOLD+"You lack the energy to use this matrix.\n"+NORM);
      return 0;}

    at_msg = ""+BOLD+"A stream of energy flows from the Klanth burning "+this_player()->query_attack()->query_name()+""+NORM+".\n\n";
    vi_msg = "A burst of energy sears into you.\n";
    rm_msg = this_player()->query_name()+" speaks an incantation, energy flows over the blade.\n";
      dam = (random(30)+12);
    this_player()->spell_object(this_player()->query_attack(),"blast",dam,28,at_msg,vi_msg,rm_msg);
    return 1;}

  get_short(){
    string str;
  str = ""+BOLD+"Ivory Klanth"+NORM+"";

  if(flame == 1){
    str += ""+RED+" ["+BOLD+YEL+"Flaming"+NORM+RED+"]"+NORM+"";
  }
  
  set_short(str);
  }

  query_wear() { return 0; }
