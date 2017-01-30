inherit "/obj/weapon.c";
int bullets;
reset(arg){
   int bullets;
   bullets = 0;
   set_name("m16");
   set_alias("rifle");
   set_short("M16 Rifle");
   set_long("The M16 Rifle is a very potent weapon, with its 5.56mm\n"+
      "rounds, it tears the insides of a person to shreds.\n"+
      "To use the M16 type shoot <target>.\n");
   set_class(11);
   set_value(2500);
   set_weight(6);
}
init() {
   ::init();
   add_action("shoot","shoot");}
   
shoot(str){
   if(!present(str,environment(this_player()))) {
      write("Sorry they are not here idiot!\n");
      say(this_player()->query_real_name() + " is an idiot.\n");
      return 1;
   } else {
      object target;
      target=present(find_living(str), environment(this_player()));
      if(!str) { write("Who do you wish to shoot?\n"); return 1;}
      if(!target->query_npc()){write("You can't shoot players!\n");
         return 1;}
      if(bullets <= 0){write("You are out of ammo.\n");
         return 1;
        }
      if(!target) {write("What were you planning to shoot Idiot?\n"); return 1
         ;}
         /* lowering damage was rnd(18)+1 - mythos <6-21-96> */
      call_other(target,"heal_self",-random(5)-1);
      write("You fire the Sternmeyer.\n");
      call_other(target, "attacked_by", this_player());
      target->attack_object(this_player());
      say("BOOM!!!\n");
      bullets = bullets -1;
      return 1;
   }
}
load(){
   bullets = 20;
}
