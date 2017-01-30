#define POSS environment(this_object())->query_possessive()
inherit "obj/armor.c";

int NUMBER, old_hp, current_count;

reset(arg){
  NUMBER = 100;
   ::reset(arg);
   set_name("force_shield");
   set_short();
   set_long();
   set_type("shield");
   set_ac(1);
   set_weight(0);
   set_value(0);
call_out("count_down", 1);
}
drop() {return 1;}
get() {return 1;}

count_down()  {
object ob;
  ob = environment(this_object());
  current_count = ob->query_hp();
  if(current_count < old_hp)  {
    current_count = old_hp - current_count;
    NUMBER = NUMBER - current_count;
      if(NUMBER < 0)  {
        tell_room(environment(ob),
        environment(this_object())->query_name()+" stops glowing.\n");
        remove_call_out("count_down");
        command("drop shield", ob);
        destruct(this_object());
        return 1;
        }
        }
  old_hp = ob->query_hp();
  call_out("count_down",1);
  return 1;
        }

