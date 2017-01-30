#define HEALCOST 60

/* HEALCOST defined at 40 because each heal point only counts */
/* for one hit point OR one spell point rather then calling   */
/* heal_self and healing both */

int heals;
string shrt;

id(str) { return str == "heal"; }

reset() {}

long() {
   if(!heals) heals = 0;
   write("A heal from The Bigelow Heal Shop.\n");
   write("It has "+heals+" power remaining\n");
   write("You can 'heal h' for hit point heal.\n");
   write("You can 'heal s' for spell point heal.\n");
   write("Or you can just 'heal' to heal both.\n");
    }

short() {
  if(!heals) heals = 0;
  if(!shrt)
  return "A heal";
  return shrt+" ["+heals+"]";
  }

init() {
    add_action("heal","heal");
}

heal(str) {
    if(!shrt) shrt = "a heal";
    if(!str){
       heal_hp();
       heal_sp();
       }
    if(str=="h") heal_hp();
    if(str=="s") heal_sp();
    if(heals == 0){
     write("You feel a bit better.\n");
     write("You have used up "+shrt+".\n");
     destruct(this_object());
     }
    else{
     write("You feel much better.\n");
     write("The "+shrt+" has "+heals+" points of healing left.\n");
     }
       return 1;
}
heal_hp(){
   int dif;
    dif = this_player()->query_mhp() - this_player()->query_hp();
    if(dif >= heals){
     this_player()->add_hit_point(heals);
     heals = 0;
     }
    else{
     heals = heals - dif;
     this_player()->add_hit_point(dif);
     }
    return;
    }
heal_sp(){
    int dif;
    dif = this_player()->query_msp() - this_player()->query_sp();
    if(dif >= heals){
     this_player()->add_spell_point(heals);
    heals = 0;
     }
    else{
     heals = heals - dif;
     this_player()->add_spell_point(dif);
     }
    return;
    }


set_strength(s){
 heals = s;
 }

set_short(blah){
 shrt = blah;
 }

get() { return 1; }

query_weight() { return 1; }

query_value() { return heals*HEALCOST; }

