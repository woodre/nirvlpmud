inherit "obj/monster";
string chats;
reset (arg){
    ::reset(arg);
    if(arg) return;
    set_name("gurru");
    set_alias("Mahariji");
    set_alias("man");
    set_short("An Old religious Gurru");
    set_long("You see a very old man you think from the robe he is wearing that\n" +
      "he may be a Gurru or Mahariji.  You also notice that he seems to be\n" +
      "missing something\n");
    set_level (20);
    set_wc (100);
    set_ac (5000);
    set_hp (500);
    set_al(0);
    set_gender (1);
    set_aggressive(0);
}   
attack()
{
    (this_player()->stop_fight());
    return 1;
}
