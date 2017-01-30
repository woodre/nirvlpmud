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
"     Outstretches a dark plain, shadowed and mysterious, unbroken\n"+
"by any major feature.  Against a dark sky, ridges flow, shuddering\n"+
"into each other, moving with a slowness that seems caught in the\n"+
"magic of a land beyond reason.  The unsettled sky is luminous with\n"+
"unseen geysers and gas clouds.  Ciphers race overhead, lightning\n"+
"strikes as the sky crackles, then the ground twitches and rumbles.\n"+
"The plain leads further into the darkness.\n";
   items = ({
         "sky", "The sky is luminous with geysers and gas clouds",
         "ridges","The ridges have jagged edges",
         "geysers","Puffed and luminous",
         "clouds","Glyph-like, having an ornamental channel or groove",
         "gas clouds","Glyph-like, having an ornamental channel or groove",
         "plain","The plain is shadowed and mysterious with minor differences in elevation",
         "lightning","Lightning strikes across the sky",
         "ground","The ground twitches and rumbles",
         "ciphers","Dissipating into bright darting sparks, maybe you can 'grab' one",
});
   dest_dir = ({
"/players/brittany/inferno/infenter.c","back",
"/players/brittany/inferno/inf1a.c","east",
});
}

init(){
::init();
if(random(3) == 0) {
this_player()->set_fight_area(); }
add_action("grab","grab");
add_action("back","back");
}
 

back(str) {
   this_player()->move_player("back#/players/brittany/inferno/infenter.c");
   return 1;
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
 
