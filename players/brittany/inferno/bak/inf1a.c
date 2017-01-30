#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/brittany/room";

status cipher;
reset(arg) {
   cipher = 1;
   if(arg) return;
   set_light(0);
   
short_desc = RED+"Inferno"+NORM;
   long_desc =
"     The plain reaches further into the darkness.  In the dark\n"+
"sky, ridges flow, shuddering intto each other.  The unsettled\n"+
"sky is luminous with geysers and gas clouds.  Ciphers race overhead,\n"+
"lightning strikes as the sky crackles.  The plain continues from\n"+
"here.\n";
   items = ({
         "sky", "The sky is luminous with geysers and gas clouds",
         "ridges","The ridges have jagged edges",
         "geysers","Puffed and luminous",
         "clouds","Glyph-like, having an ornamental channel or groove",
         "gas clouds","Glyph-like, having an ornamental channel or groove",
         "plain","The plain is shadowed and mysterious with minor differences in elevation",
         "lightning","Lightning strikes across the sky",
         "ciphers","Dissipating into bright darting sparks, maybe you can 'grab' one",
});
   dest_dir = ({
"/players/brittany/inferno/inf1.c","west",
"/players/brittany/inferno/inf2.c","east",
});
}

init(){
::init();
add_action("grab","grab");
}
 
grab(str){
   object cloud;
   if(!str ||  str != "cipher") {
   notify_fail("What do you want to grab?\n");
   return 0; }
 
   if(cipher) {
  write("You grab a spark and it throws you to the ground.\n\n"+
   ""+HIY+"A black cloud appears."+NORM+"\n");
      cloud = clone_object("/players/brittany/inferno/NPC/cloud.c");
      move_object(cloud,this_object());
      cloud->attack_object(this_player());
     cipher = 0;
   }
   else write("Nothing happens.\n");
   return 1; }
 
