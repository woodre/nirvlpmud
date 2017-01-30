/* I have added charges and a charge up time as well for this 
  item to make it legal - mythos <10-31-96> */
inherit "obj/treasure";
int x;
int charge;   /* charges are needed */
int chargemax;
reset(arg) {
if (arg) return;
set_short("Talisman of Health");
set_long
("The local cleric sells these as a means of keeping his church\n"+
"looking nice. It grants the owner the ability to transform magical\n"+
"energy into healing energy. To use it, just type 'tonic'.\n");
set_weight(1);
set_alias("talisman");
set_value(500);
chargemax = 15 - random(8);
charge = 5 + random(10);
call_out("chargeup",600 + random(1000));
}

query_save_flag() { return 1; }
init()
{
::init();
add_action("do_tonic", "tonic");
}
do_tonic()
{
x=this_player()->query_sp();
if(x>=30)
{
write("You feel healthier.\n");
this_player()->add_hit_point(15);
this_player()->add_spell_point(-30);
  charge = charge - 1;
  if(charge < 1 + random(7)) {
    write("You have used up all the charges on this item\n");
   destruct(this_object()); }
return 1;
}
write("You dont have enough spell points to do that.\n");
return 1;
}

chargeup() {
  if(!environment(this_object())) { destruct(this_object()); return 1; }
  if(charge < chargemax) {
    charge = charge + 1;
   tell_object(environment(this_object()),"The Talisman glows for a second.\n");
  }
call_out("chargeup",600 + random(1000));
return 1; }
