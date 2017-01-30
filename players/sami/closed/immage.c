inherit "obj/monster.c";
#include <ansi.h>
object owner;
int jj;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("image");
  set_race("image");
  set_short("image");
  set_level(1);
  set_hp(100);
  set_al(0);
  set_wc(3);  
  set_ac(0);
  jj = 0;
  set_dead_ob(this_object());
  call_out("checks",40);
}
set_own(ob) { owner = ob; }

checks() { 
  if(!find_object(owner)) { monster_died(); return 1; }
  if(environment(owner) != environment(this_object())) {
    monster_died(); return 1; }
call_out("checks",40);
return 1; }

monster_died() {
  tell_room(environment(this_object()),"An Image winks out of existance!\n");
  destruct(this_object());
  return 1;
}

heart_beat() {
  ::heart_beat();
    if(environment(owner) == environment(this_object())) {
      if(owner->query_attack()) { 
        if(!query_attack()) 
        this_object()->attack_object(owner->query_attack());
        else if(owner->query_attack() != query_attack())
          this_object()->attack_object(owner->query_attack());
          jj = 0;
      } else {
       jj = jj + 1; 
       if(jj > 5) { monster_died(); return 1; }
      }
    }
}
