
inherit "/obj/monster.c";
#include <ansi.h>


#define ENV environment
#define TO this_object()



reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  set_name("mob");
  set_race("critter");

  set_short("A test mob");
  set_long(
    "  A test mob.\n"+
    "  A test mob.\n");
  set_al(0);

  set_level(27);
  set_hp(1900);
  set_wc(58);
  set_ac(27);
  set_wc_bonus(26);
  set_hp_bonus(600);


  set_gender("male");
  /*set_dead_ob(this_object());*/
  set_aggressive(0);
  set_chat_chance(0);
   load_chat("chat 1.\n");
   load_chat("chat 2.\n");
   load_chat("chat 3.\n");
   
   
  }
  
  
init() {
  ::init();

  tell_room(environment(), "INIT CHECK 1\n");

tell_room(ENV(TO),"  \n");  
tell_room(ENV(TO),HIR+"                                                 .                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                                `s                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                                o/                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                                d-                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                               `M:                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                           .,  `Ms                         \n"+NORM);
tell_room(ENV(TO),HIR+"                                           `y` `mh                         \n"+NORM);
tell_room(ENV(TO),HIR+"                ``                          yo  yM-                        \n"+NORM);
tell_room(ENV(TO),HIR+"                `o.                         dh  :Mh`     '                 \n"+NORM);
tell_room(ENV(TO),HIR+"                 :m.                       -Mh  `dMs    `/`                \n"+NORM);
tell_room(ENV(TO),HIR+"                 -Nd   -           ,      `dM/   :MMs    -y`               \n"+NORM);
tell_room(ENV(TO),HIR+"       ,         -MM: -o           o      +Md     yMM+    hy               \n"+NORM);
tell_room(ENV(TO),HIR+"       o`        /MM: /d           m      mMy     .NMN:   oN.  :           \n"+NORM);
tell_room(ENV(TO),HIR+"      .N         yMm  :M/          N.    -NMd      hMMm   hN- `o           \n"+NORM);
tell_room(ENV(TO),HIR+"      /N        -NM+   yN/`     /` No    .NMMo`   -NMMM: `Nm   m-          \n"+NORM);
tell_room(ENV(TO),HIR+"  `   +M       `dMm`   `sNh:    +o oN-    hMMMdsshNMMMM+ oMo   om+`        \n"+NORM);
tell_room(ENV(TO),HIR+"  .o` /M/      yMMy      :mMs`  -d `dm:   .NMMMMMMMMMMM+.NM.    /Nd.       \n"+NORM);
tell_room(ENV(TO),HIR+"   No `mm-    -MMMo       /MMo  /h  .dNs`  :NMMMMMMMMMM.-MM`     hMd`      \n"+NORM);
tell_room(ENV(TO),HIR+"   Nm  /Nm/   /MMMy       .MMN.`m/   `mMd.  -dMMMMMMMMy -MMy-```.mMM: .+   \n"+NORM);
tell_room(ENV(TO),HIR+"  :My   +MN/  /MMMNo.`  `.yMMM-yM:    yMMm.  .hMMMMMMm. `dMMMmhhNMMN. d+   \n"+NORM);
tell_room(ENV(TO),HIR+"  hM+    dMN. .NMMMMNdhydNMMMM.NMs` `-NMMMs   `dMMMMN-   :MMMMMMMMM+ :M+   \n"+NORM);
tell_room(ENV(TO),HIR+" +MM+    hMM+  yMMMMMMMMMMMMNs hMMdyhNMMMMd    -MMMMo     hMMMMMMN/  .Nd`  \n"+NORM);
tell_room(ENV(TO),HIR+" MMMy` `/NMM+  `dMMMMMMMMMMN/  -mMMMMMMMMM+    `MMMM:     +MMMMMN:    +Mh` \n"+NORM);
tell_room(ENV(TO),HIR+" \MMMdydMMMN.   -NMMMMMMMMM-    .hMMMMMMN+     oMMMMo     yMMMMMd      oMd`\n"+NORM);
tell_room(ENV(TO),HIR+" -MMMMMMMMM+     hMMMMMMMMy      :MMMMMMm`    /MMMMMNs/-/yMMMMMMd      :MMh\n"+NORM);
tell_room(ENV(TO),HIR+"  hMMMMMMMM-    `dMMMMMMMMh`     sMMMMMMMmo:/hMMMMMMMMMMMMMMMMMMMo`   .dMMM\n"+NORM);
tell_room(ENV(TO),HIR+"  :MMMMMMMMm+..:hMMMMMMMMMMh:../hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdddMMMMM\n"+NORM);
tell_room(ENV(TO),HIR+"` /MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"+NORM);
tell_room(ENV(TO),HIR+"MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm\n"+NORM);
tell_room(ENV(TO),HIR+"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss.\n"+NORM);
tell_room(ENV(TO),"  \n");


}

/*
heart_beat() {
    ::heart_beat();



}
*/