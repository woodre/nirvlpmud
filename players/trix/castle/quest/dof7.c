inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"  This is a room with a high ceiling.  The musk which has accompanied you\n"+
"until now has disappeared.  Its green glow has been replaced by a red one\n"+
"coming from a giant marble statue.\n";
    short_desc = "The room of the Statue";
    dest_dir = ({
/* Was dof6.c now Edof7.c to fit with Eurale's changes -Feldegast 5/2/98 */
                  "/players/trix/castle/quest/Edof7","west"
                                                        });
    items=({
      "statue","This is a giant statue of Melko.  The devout followers of his cult used to\n"+
               "kneel before it.  Do you belong to the cult?\n"
    });
}
init(){
 ::init();
    add_action("kneel","kneel");
}
kneel(str)
{ string what;
  if(!str||sscanf(str,"before %s",what)!=1) return;
  if(what!="statue") { write("Kneel before what?!?\n"); return 1; }
  if(!present("trixpendant",this_player())) { 
            write("You're not a member of the cult!  You lack the proper symbol!\n"+
                   "A strange force takes you somewhere else...\n");
           tell_room("/room/church",call_other(this_player(),"query_name")+" arrives in a puff of smoke.\n");
           move_object(this_player(),"/room/church");
           return 1;}
  write("You kneel in front of the statue.  The statue looks at you and, recognizing\n"+
        "you as a believer, it smiles in a fatherly way at you.  A little portal\n"+
        "between its feet and you are forced to enter it.\n");
  move_object(this_player(),"/players/trix/castle/quest/dof8");
  command("look",this_player());
  return 1;
}

realm(){return "NT";}
