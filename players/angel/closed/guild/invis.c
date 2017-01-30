query_spell_name()
{
  return "invisibility";
}


set_duration(d) {
    call_out("dispel",d);
}

init() {
    this_player()->invis();
    set_heart_beat(1);
}

dispel() {
    environment()->vis();
    remove_call_out("dispel");
    destruct(this_object());
}

drop() { return 1; }

id(str) {
    return str == "spell" || str == "invisibility" ||
           str == "invisibility spell";
}

heart_beat() {
    if(environment()->query_attack()) {
        tell_object(environment(),"Combat makes your invisibility go away!\n");
        dispel();
    }
}