inherit "/obj/armor.c";

void reset(status arg) {
   if(arg)
      return;
   ::reset(arg);
   set_name("vilya");
   set_alias("ring");
   set_short("Vilya, the Ring of Sapphire");
   set_long("\
      It is generally considered that vilya was the mightiest of the three \n\
      bands. When Sauron laid waste to Eregion, Vilya was sent to the \n\
      Elven-King Gil-galad far away in Lindon, where it was later given to \n\
      Elrond, who bore it through the later years of the Second Age and all \n\
      of the Third. As Gil-galad was the High King of the Noldor elves at the \n\
      time of the rings' distribution it was thought that he was best fit to \n\
      car for the most powerful of the three Elven rings. \n\
      	\n");
   set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc */
   set_ac(2);
   set_weight(1);
   set_value(5000);
}
