inherit"obj/monster";

reset(arg) {
   ::reset(arg);

   if(!arg){

   set_name("rat");
   set_short("An ugly rat");
   set_long("It brown, furry, and sqeaks when you hit it.\n");
   set_level(1);
   set_ac(2);
   set_wc(4);
   set_hp(20);
  }
}
