inherit "obj/monster";

#define TO this_object()

reset(arg) {
  if (arg) return;
  set_name("odo");
  set_short("Constable Odo");
  set_long(
    format("Odo is the head of security for Deep Space Nine. He worked "+
           "for the Cardassians when they were here, and after they left "+
           "he stayed on with the Federation. Odo used to be a "+
           "shapeshifter, but as punishment for killing another "+
           "shapeshifter, his people turned him into a human. He is "+
           "still trying to get used to being human. As you look at him "+
           "you notice that his face is not quite perfect, that was part "+
           "of his punishment. You also notice the suspicious look in his "+
           "eye, almost as if he expects you to be up to no good.\n",75));
  set_wc(30+random(10));
  set_ac(20);
  set_hp(850+random(300));
  set_level(30);
  set_al(3000);
}
