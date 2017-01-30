#define TO this_object()
#define ep environment(TO)
#define att ep->query_attack()
object alt_at,main_at;
int time;
int percent;

id(str) { return str == "shielding" || str == "field"; }

short() { return "A Shield of Light"; }

long() { write("The light is too blinding.\n"); }

query_weight() { return 0; }
drop() { return 1; }
get() { return 0; }

reset(arg) {
  if(arg) return;
  set_light(2);
  alt_at = main_at = 0;
  percent = -1;
  time = 50;
  set_heart_beat(1);
}

set_base(int a) { time = time + a; percent = 2*a; }

clear() {
 set_heart_beat(0);
 if(ep) tell_object(ep,"The Shield of Light vanishes.\n");
    if(environment(ep)) tell_room(environment(ep),"The Shield of Light vanishes from around "+ep->query_name()+".\n");
 destruct(this_object());
return 1; }

heart_beat() {
  if(!ep) { set_heart_beat(0); return 1; }
  if(ep->query_ghost()) { clear(); return 1; }
  if(att) main_at = att; 
  if(ep->query_alt_attacker()) alt_at = ep->query_alt_attacker();
  if(main_at) {
    main_at->set_spell_dam(main_at->query_wc() * -percent/100);
    main_at->spell_object(ep,"",main_at->query_wc() * -percent/100,0,
            "The field absorbs some of your blow.\n",
            "The field absorbs some of the blow.\n",
            "There is a brilliant flash as the blow is deflected.\n");
    main_at = 0;
  }
  if(alt_at) {
    alt_at->set_spell_dam(alt_at->query_wc() * -percent/100);
    alt_at->spell_object(ep,"",alt_at->query_wc() * -percent/100,0,
            "The field absorbs some of your blow.\n",
            "The field absorbs some of the blow.\n",
            "There is a brilliant flash as the blow is deflected.\n");
    alt_at = 0;
  } 
  if(time) time = time - 1;
  else clear();
}

query_save_flag() { return 1; }
