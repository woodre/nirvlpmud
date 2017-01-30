inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"You've passed the hall and entered a circular room. The room is filled with\n"+
"dust and cobwebs. The dust seems to have never totally settled. You can\n"+
"feel a slight draft blow up your leg. There seems to be no exits except\n"+
"that in which you entered which is to the northwest.\n";
    short_desc ="A circular room";
    dest_dir = ({
            /*     
                  "/players/trix/closed/guild/castle/base","down", */
                  "/players/trix/closed/guild/castle/first3.c","northwest"
                                                        });
}
realm(){return "NT";}
