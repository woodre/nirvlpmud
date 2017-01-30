inherit "room/room";
 
reset(arg) {
    object recharger,sign,fixer;
    if(arg) return;
    set_light(1);
   long_desc=
"  Welcome to Trix's realm!  You can see a huge gothic cathedral north\n"+
"of here.  A big blinking neon sign points south towards a disco, while\n"+
"to the west a road leads into Trixtown.\n";
   short_desc = "Trix's realm";
    dest_dir = ({ "/players/trix/castle/primo/entrance1.c", "north",
                  "/players/trix/castle/disco/in1.c", "south",
                  "/players/trix/castle/town/mainroad1.c", "west",
                      "/room/townh.c","exit"}); /* New exit -Feld 5-7-98 */
    recharger=clone_object("/players/trix/closed/obj/recharger.c");
    move_object(recharger,this_object());
    sign=clone_object("/players/trix/closed/realmboard.c");
    move_object(sign,this_object());
}
