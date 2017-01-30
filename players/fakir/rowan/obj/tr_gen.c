
/*
 * RANDOM TREASURE GENERATOR
 * Called by monsters/rooms from reset()  Will randomly clone and 
 * move object to monsters/rooms.
 */

#define PATH "players/molasar/rowan/"

object weapons;
object magic1, magic2, magic3, magic4, magic5;
object scroll1;

reset(arg) {
   if(arg)
     return;
   extra_reset();
}

/* set up arrays */

extra_reset() {
   magic1 = allocate(1);
   magic1 = ({ "magic/deck" });
   magic2 = allocate(4);
   magic2 = ({ "magic/r_invis", "magic/r_shock", "magic/w_flame",
               "magic/p_heal" });
   magic3 = allocate(6);
   magic3 = ({ "magic/esp_med", "magic/sc_evil",
               "magic/sc_good", "magic/bag_hold" });
   magic4 = allocate(3);
   magic4 = ({ "magic/m_train", "magic/rod_might" });
   magic5 = allocate(5);
   magic5 = ({ "magic/fam_stn", "magic/o_impact",
               "magic/gem_see", "magic/dust_app" });
   scroll1 = allocate(6);
   scroll1 = ({ "magic/sc_cl_1", "magic/sc_mu_1",
                "magic/sc_mu_2", "magic/sc_mu_3", "magic/sc_mu_4" });
   weapons = allocate(4);
   weapons = ({ "arms/gsword", "arms/gmace", "arms/gflail", "arms/gaxe" });
}

/*
 * Called from /players/molasar/rowan/mtn/lair.c
 */

get_magic1(obj) {
   object magic;
   int n;

   if(!obj)
     obj = previous_object();
   n = random(sizeof(magic1));
   magic = clone_object(PATH+magic1[n]);
   move_object(magic, obj);
}

get_magic2(obj) {
   object magic;
   int n;
   if(!obj)
     obj = previous_object();
   n = random(sizeof(magic2));
   magic = clone_object(PATH+magic2[n]);
   move_object(magic, obj);
  
}

get_magic3(obj) {
   object magic;
   int n;
   n = random(sizeof(magic3));
   if(!obj)
     obj = previous_object();
   magic = clone_object(PATH+magic3[n]);
   move_object(magic, obj);
}

get_magic4(obj) {
   object magic;
   int n;
   n = random(sizeof(magic4));
   if(!obj)
     obj = previous_object();
   magic = clone_object(PATH+magic4[n]);
   move_object(magic, obj);
}

get_magic5(obj) {
   object magic;
   int n;
   n = random(sizeof(magic5));
   if(!obj)
     obj = previous_object();
   magic = clone_object(PATH+magic5[n]);
   move_object(magic, obj);
}

get_scroll1(obj) {
   object scroll;
   int n;
   if(!obj)
     obj = previous_object();
   n = random(sizeof(scroll1));
   scroll = clone_object(PATH+scroll1[n]);
   move_object(scroll, obj);
}

get_weapon(wc, obj) {
   object weap;
   int n;

   if(!obj)
     obj = previous_object();
   n = random(sizeof(weapons));
   weap = clone_object(PATH+weapons[n]);
   weap->set_class(wc);
   if(wc > 14) weap->set_value(40*wc);
   move_object(weap, obj);
}

get_money(amt,obj) {
   object money;
   if(!obj)
     obj = previous_object();
   money = clone_object("obj/money");
   money->set_money(random(amt));
   move_object(money, obj);
}



