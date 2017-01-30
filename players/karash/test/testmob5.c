
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
  
tell_room(ENV(TO),"                                                 .                         \n");
tell_room(ENV(TO),"                                                `s                         \n");
tell_room(ENV(TO),"                                                o/                         \n");
tell_room(ENV(TO),"                                                d-                         \n");
tell_room(ENV(TO),"                                               `M:                         \n");
tell_room(ENV(TO),"                                           .,  `Ms                         \n");
tell_room(ENV(TO),"                                           `y` `mh                         \n");
tell_room(ENV(TO),"                ``                          yo  yM-                        \n");
tell_room(ENV(TO),"                `o.                         dh  :Mh`     '                 \n");
tell_room(ENV(TO),"                 :m.                       -Mh  `dMs    `/`                \n");
tell_room(ENV(TO),"                 -Nd   -           ,      `dM/   :MMs    -y`               \n");
tell_room(ENV(TO),"       ,         -MM: -o           o      +Md     yMM+    hy               \n");
tell_room(ENV(TO),"       o`        /MM: /d           m      mMy     .NMN:   oN.  :           \n");
tell_room(ENV(TO),"      .N         yMm  :M/          N.    -NMd      hMMm   hN- `o           \n");
tell_room(ENV(TO),"      /N        -NM+   yN/`     /` No    .NMMo`   -NMMM: `Nm   m-          \n");
tell_room(ENV(TO),"  `   +M       `dMm`   `sNh:    +o oN-    hMMMdsshNMMMM+ oMo   om+`        \n");
tell_room(ENV(TO),"  .o` /M/      yMMy      :mMs`  -d `dm:   .NMMMMMMMMMMM+.NM.    /Nd.       \n");
tell_room(ENV(TO),"   No `mm-    -MMMo       /MMo  /h  .dNs`  :NMMMMMMMMMM.-MM`     hMd`      \n");
tell_room(ENV(TO),"   Nm  /Nm/   /MMMy       .MMN.`m/   `mMd.  -dMMMMMMMMy -MMy-```.mMM: .+   \n");
tell_room(ENV(TO),"  :My   +MN/  /MMMNo.`  `.yMMM-yM:    yMMm.  .hMMMMMMm. `dMMMmhhNMMN. d+   \n");
tell_room(ENV(TO),"  hM+    dMN. .NMMMMNdhydNMMMM.NMs` `-NMMMs   `dMMMMN-   :MMMMMMMMM+ :M+   \n");
tell_room(ENV(TO)," +MM+    hMM+  yMMMMMMMMMMMMNs hMMdyhNMMMMd    -MMMMo     hMMMMMMN/  .Nd`  \n");
tell_room(ENV(TO)," MMMy` `/NMM+  `dMMMMMMMMMMN/  -mMMMMMMMMM+    `MMMM:     +MMMMMN:    +Mh` \n");
tell_room(ENV(TO)," \MMMdydMMMN.   -NMMMMMMMMM-    .hMMMMMMN+     oMMMMo     yMMMMMd      oMd`\n");
tell_room(ENV(TO)," -MMMMMMMMM+     hMMMMMMMMy      :MMMMMMm`    /MMMMMNs/-/yMMMMMMd      :MMh\n");
tell_room(ENV(TO),"  hMMMMMMMM-    `dMMMMMMMMh`     sMMMMMMMmo:/hMMMMMMMMMMMMMMMMMMMo`   .dMMM\n");
tell_room(ENV(TO),"  :MMMMMMMMm+..:hMMMMMMMMMMh:../hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdddMMMMM\n");
tell_room(ENV(TO),"` /MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
tell_room(ENV(TO),"MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm\n");
tell_room(ENV(TO),"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss.\n");

}

heart_beat() {
    ::heart_beat();



}