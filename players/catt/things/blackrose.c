int i;
id(str) { return str == "rose"; }
get() { return 1; }
short() { return "Black rose of the Demon Lords"; }
long() {
write("The black rose specially grown by the demon lords. Its \n" +
"gift is great for to have one is to have much power if you only know\n" +
"how to use it.\n");
return 1; }
reset(arg) {
  if(arg) return;
}
init() {
   add_action("smile","smile");
   add_action("frown","frown");
add_action("propose","propose");
add_action("kneel","kneel");
   add_action("miss_wendy","miss");
}
smile() {
if(this_player()->query_real_name() == "catt") {
write("The black rose blooms beside the red expressing\n"+
"love and harmony.\n");
shout("The Black rose from northern reaches blooms beside\n" +
"the red... proving that love and harmony exist beside death\n" +
"and darkness.\n");
}}
kneel() {
if(this_player()->query_real_name() == "catt") {
  write("The Demon Lord kneels before you and takes your hand\n");
say("The Demon Lord kneels before you and takes your hand\n");
}}
frown() {
if(this_player()->query_real_name() == "catt") {
write("The rose wilts and blows to dust for the demon lords sorrow\n");
shout("The black rose wilts and blows to dust for the demon lords sorrow\n");
destruct(this_object());
}}
propose() {
if(this_player()->query_real_name() == "catt") {
write("WENDY WILL YOU MARRY THIS POOR DEMON LORD?");
shout("WENDY.. WILL YOU MARRY THIS POOR LONELY DEMON LORD?");
}}
miss_wendy() {
   if(this_player()->query_real_name() == "catt") {
/*
   write("A swirling wind blows in from the north.");
   write("The wind starts howling around you, stinging your eyes with dust.\n");
   shout("A swirling wind blows in from the north.\n");
   shout("The wind starts howling around you, stinging your eyes with dust.\n");
   shout("You see demons riding the wind, screaming in both fear and pain.\n");
   shout("They lament their Demon Lords sorrow at losing his mate.\n");
*/
   call_out("miss_message", 5);
   return 1;
}
   return 0;
}
miss_message() {
   if(i==1) {
      shout("A swirling wind blows in from the north.\n");
      }
   if(i==2) {
      shout("The wind starts howling around you, stinging your eyes with dust.\n");
      }
   if(i==3) {
      shout("You see demons riding the wind, screaming in both fear and pain.\n");
      }
   if(i==4) {
      shout("They lament their Demon Lords sorrow at losing his mate.\n");
      }
   if(i==5) {
      shout("The shrieking winds continue to the south, leaving you "+
            "baffled, and in silence.\n");
      }
   if(i==6) {
      remove_callout();
      set_i();
      return 1;
      }
   i++;
   call_out("miss_message", 5);
   return 1;
}
set_i() {
   i = 1;
   return 1;
   }
