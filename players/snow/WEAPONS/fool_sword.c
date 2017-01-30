inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("foolsword");
    set_alias("sword");
    set_short("Fool's Sword");
    set_long(
"This short sword belonged to Fool, Snow's court jester. It looks somewhat dull.\n");
    set_class(12);
    set_weight(2);
    set_value(100);
    set_hit_func(this_object());
}
weapon_hit() {
int W,foolnum;
    W = random(15);
    foolnum = call_other(this_player(),"query_attrib","int");
  if(W >  foolnum) {
  say(capitalize(this_player()->query_name())+
" uses foolish tactics!\n");
  write("You use foolish tactics!\n");
return (10 - foolnum);
   }
       return;
}
 
