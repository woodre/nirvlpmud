reset() {
object kid;
     kid = clone_object("obj/kid");
    kid->set_gender("female");
        call_other(kid, "set_name", "baby");
        call_other(kid, "set_hp", 30);
call_other(kid, "set_ac", 0);
        call_other(kid, "set_wc", 0);
        call_other(kid, "set_al", 0);
          kid->set_short("Lavonna's baby");
        call_other(kid, "set_long",
              "A little newborn baby.\n");
        call_other(kid, "set_aggressive", 0);
         kid->set_parent("lavonna");
         kid->set_nparents("lavonna#keeper");
call_other(kid, "set_level", 1);
call_other(kid, "set_chat_chance", 10);
      kid->load_chat("The baby cries.\n");
      kid->load_chat("The baby drools.\n");
      kid->load_chat("The baby smiles.\n");
      kid->load_chat("The baby says: OOGA BOOGA MMOOMY\n");
      kid->load_chat("The baby says: OCA PYUPY ORCI SUM\n");
     move_object(clone_object("obj/soul"), kid);
       move_object(kid,this_object());
}
