inherit "room/room";
 
reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc = 
"  You have reached the western end of Trixtown.  To the north there's a dusty\n"+
"alley with fir trees at its sides.  To the west you glimpse the top of a hill\n"+
"hidden by a nice forest, but it's unreachable because of a little river.\n";
   short_desc = "Trixtown Main Road";
   dest_dir = ({ "/players/trix/castle/town/alley1.c","north",
                 "/players/trix/closed/guild/guild_ent.c","river",
                 "/players/trix/castle/town/mainroad4.c","east"});
}
init(){
  ::init();
  add_action("west","river");
}
west(){
/* guild entrance moved! */
/*
   write("You cross the river and get to a wierd and arcane place.\n"); 
   this_player()->move_player("river#"+"players/trix/closed/guild/guild_ent");
 */
  write("You try to cross the river, but the current is too strong.\n");
  return 1;
}
