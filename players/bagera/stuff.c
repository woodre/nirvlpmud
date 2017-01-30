inherit "/obj/thing.c";
  string Esc;
    Esc = " ";
    Esc[0] = 27;
  int max,now,ANSIhp,oldhp;

create() {
  set_light(3);
  set_id("ansi hp shower");
  set_alias("shower");
  set_short("Ansi HP Shower");
  set_wrap(1);
  set_long(An ansi hp showering item, it'll override your normal hitpoint command"+
"It's functions are: \nhp - shows stats.  hpon - turns on hpwatch.  hpoff - turns off hpwatch.\n");
  set_weight(0);
  set_value(0);
}
  int() {
    ::init();
    add_action("hp_stuff", "hp");
}
  player_hit() {
    if (ANSIhp)
      show_hp(" ");
      return 0;
}
  colorit() {
    if ( now > (max / 4 * 3 ) ){
    write(Esc+"[32;1m");
    return 0;
}
  if ( now > ( max / 2 ) ){
    write(Esc+"[32m");
    return 0;
}
  if ( now > ( max / 4 ) ){
    write(Esc+"[33;1m);
    return 0;
}
  if ( now > 0 )
    write(Esc+"[30;1m");
}
  hp_stuff(string str) {
    if (str){
    if (str == "on")
      ANSIhp = 1;
    if (str == "off")
      ANSIhp = 0;
}
else{
   max = this_player()->query_max_hp();
   now = this_player()->query_hit_points();
 colorit();
   write("HP: "+now+"/"+max+"      ");
   max = this_player()->query_max_sp();
   now = this_player()->query_spell_points();
 colorit();
   write("SP: "+now+"/"+max+"     ");
   write(Esc+"[m\n");
}
return 1;
}
