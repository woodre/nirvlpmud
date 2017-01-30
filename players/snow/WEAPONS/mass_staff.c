/*
The MASS Staff is a weapon that uses strength and willpower to determine
extra_hit stuff. It is 'cursed' in that it adds weight every time it
does a special hit.
*/
 
#define TP this_player()
#define TPS call_other(TP,"query_attrib","str")
#define TPW call_other(TP,"query_attrib","wil")
#define MEAT TP->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TPN capitalize(TP->query_name())
 
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("mass staff");
    set_alias("staff");
    set_short("The MASS Staff");
    set_long(
"A long, knobbed staff of iron. It seems to be a formidable weapon.\n");
    set_class(16);
    set_weight(5);
    set_value(1000);
    set_hit_func(this_object());
set_save_flag(0);
}
weapon_hit() {
int W;
    W = random(TPS + TPW);
  if(W > 20)  {
  say(TPN+"'s MASS Staff glows a greyish-blue!\n");
  write("Your MASS Staff glows a greyish-blue!\n");
mass1();
  tell_room(environment(TP),MEATN+" screams in withered pain!\n");
   }
   if(W > 30) {
   say(TPN+" glows a greenish hue!\n");
   write("You glow a greenish hue!\n");
mass2();
   }
return (TPS + TPW)/10;
}
 
mass1() {
  call_other(MEAT,"heal_self",-(TPS/8));
  call_other(TP,"add_weight",random(TPS/8));
return 1;
}
 
mass2() {
  call_other(MEAT,"heal_self",-(TPW/5));
  call_other(TP,"add_weight",random((TPS + TPW)/8));
return 1;
}
