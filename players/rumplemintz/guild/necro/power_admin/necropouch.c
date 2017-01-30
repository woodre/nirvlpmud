cmd(){
    object ob;
    ob = present("necro_ob", this_player());
    ob->add_blood(100);
    ob->add_skin(100);
    ob->add_eye(100);
    ob->add_spine(100);
    ob->add_heart(100);
    ob->add_soul(100);
    write("Your necro pouch has been replenished.\n");
    return 1;
}
