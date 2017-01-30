/*   THIS IS THE REVISED VERSION- original is CLAW.bak - mythos <12-1-96> */
#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w,d;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
   set_name("claws");
   set_alias("insect claws");
set_short("Insect Claws");
set_long("You must have broken these off while killing the insect.  The appear\n"+
"to be oozing something.  They make you feel very sinister just holding them.\n");
set_class(17);
   set_weight(2);
   set_value(random(1000));
   set_hit_func(this_object());
}
weapon_hit(attacker){
  w = random(1000);
if (w < 50) {
write("You hit "+attacker->query_name()+" very hard.\n");
return 3; }
if (w > 50 && w < 200) {
write("You hit "+attacker->query_name()+" hard.\n");
return 7;}
if (w > 200 && w < 400) {
write("You hit "+attacker->query_name()+" hard.\n");
return 5; }
if (w > 400 && w < 700) {
write("The claws turn on you and attack.\n");
this_player()->hit_player(random(50));
return -7;
}
if(w == 777) {
write("The claw bites into you!\nThe poison seeps into your body!\n");
this_player()->hit_player(random(50), "other|poison");
return 1; }
if (w == 999) {
write("The claws seep poison into "+attacker->query_name()+".\n"+
"\nYour foe begins to die slowly.\n");
attacker->hit_player(random(50), "other|poison"); }
return 0;
}

