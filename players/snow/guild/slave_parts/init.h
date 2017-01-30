/* INIT */
  init() {
  if(ENV(TO)) setup(ENVTO);
  add_action("cyborg_reset","creset");
/* EYES */
if(eyes) {
  add_action("cyborg_flash","eyeflash");
  add_action("cyborg_look","look");
  add_action("cyborg_look","l");
  add_action("cyborg_get","get");
  add_action("cyborg_get","take");
  add_action("cyborg_put","put");
  }
/* LEGS */
if(legs) {
  add_action("run","run");
  }
/* ARMS */
if(arms) {
  }
  }
