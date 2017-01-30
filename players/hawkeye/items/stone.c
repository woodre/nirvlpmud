inherit "obj/treasure";

reset(arg) {
 if(arg) return;
    set_short("A Stone");
    set_alias("stone");
  set_long("This is a very magical stone of light and dark, maybe you could rub it.\n");
   set_weight(2);
    set_value(5000);
}
 id(str) { return str == "stone" || str == "grey stone"; }

init() {
 ::init();
  add_action("rub","rub");
}

rub(str) {
     int was, to_be;
     int num,lvl,xlvl,myexp,cexp;
      object ob;
  if(!str) {
    write("rub STONE.\n");
     return 1;
       }
   if (!(ob=present(str, this_player()))) {
      write("You dont have one of those!\n");
        return 1;
        }
  if(this_player()->is_kid()) {
   write("Children may not use the stone.\n");
   return 1;
  }
  if(this_player()->query_exp() < 50000) {
write("You cant do that with such little XP!\n");
return 1;
}

/* Prevent level reductions -Bp */

lvl = this_player()->query_level();
cexp=call_other("room/adv_guild", "check_level", lvl)+50000;
xlvl = this_player()->query_extra_level();
myexp = this_player()->query_exp();
if(myexp < cexp) {
  write("You rub the stone.\n");
  return 1;
}
if(xlvl) {
  cexp=call_other("room/exlv_guild", "check_level", xlvl)+50000;
  if(myexp < cexp) {
  write("You rub the stone.\n");
  return 1;
}}


/*
if(random(150) < 4) {
  this_player()->add_exp(50000);
  this_player()->save_me();
  write("The stone shivers in your hand and in a flash of light, gives you 50,000 experience points\n");
destruct(this_object());
return 1;
}
  else {
  this_player()->add_exp(-50000);
this_player()->save_me();
   write("The stone shivers in your hand and in a flash of light, steals 50,000 experience points\n");
*/
num=random(150);
if(num < 4) {
  this_player()->add_exp(50000);
  this_player()->save_me();
/* add to prevent cheating -Bp */
write("The stone shivers in your hand and in a flash of light, gives you 50,000 experience points\n");
destruct(this_object());
return 1;
}
if(num > 4 && num < 40) {
   this_player()->add_exp(2000);
   this_player()->save_me();
   write("The stone shivers in your hand and in a flash of light, gives you 2000 experience points\n");
}
if(num > 40 && num < 140) {



   this_player()->add_exp(-2000);
   this_player()->save_me();
   write("The stone shivers in your hand and in a flash of light, steals 2000 experience points\n");
   destruct(this_object());
return 1;
}
if (num > 140) {
    this_player()->add_exp(-50000);
this_player()->save_me();
/* add to prevent cheating -Bp */
write("The stone shivers in your hand and in a flash of light, steals 50,000 experience points\n");
  destruct(this_object());
  return 1;
}
destruct(this_object());
  return 1;
this_player()->save_me();
/* add to prevent cheating -Bp */
}
