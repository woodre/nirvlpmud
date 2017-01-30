#define TP this_player()
#define TO this_object()
#define TPN capitalize(TP->query_name())
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TR tell_room
 
string guarded;
object toguard;
set_toguard(object ob) { toguard = ob; }
set_guarded(string str) { guarded = str; }
query_guarded() { return guarded; }
query_toguard() { return toguard->query_real_name(); }
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
 
     set_name("guard monster");
     set_short("A guard");
     set_race("guardmon");
     set_alias("guard");
    set_long("A guard. It will guard.\n");
     set_level(random(3)+15);
     set_ac(random(7)+5);
     set_wc(random(12)+20);
     set_hp(random(100)+250);
     set_heal(1,1);
     set_al(0);
     set_aggressive(0);
  call_out("rebeat",10);
   }
}
 
heart_beat() {
  ::heart_beat();
  guard_guard();
return 1;
}
 
guard_guard() {
  object gobj, meat;
  if(guarded) gobj = present(guarded,TO);
  if(toguard) gobj = toguard;
  if(!gobj) return 1;
  if(gobj->query_attack()) meat = gobj->query_attack();
  if(meat && meat != MEAT) {
    write("The Guard leaps to protect its liege.\n");
    TO->attack_object(meat);
    return 1;
  }
  return 1;
}

rebeat() { call_out("rebeat",20); set_heart_beat(1); heart_beat(); return 1; }
