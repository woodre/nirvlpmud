inherit "obj/weapon";
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("wicked flail");
   set_alias("flail");
   set_short("wicked flail");
   set_long(
      "A flail of somewhat poor quality, it has an iron shaft and a small iron\n"+
      "ball with spikes attached by a steel chain. It looks like it has been\n"+
      "used to crush several heads between cleaning as it is covered with a \n"+
      "bloody colored rust.\n");
   set_value(50+random(25));
   set_weight(2);
   set_class(8+random(5));
}
