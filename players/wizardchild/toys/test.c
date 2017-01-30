reset(arg) { call_out("fix_it",0); }
fix_it() { environment(find_player("mizan"))->set_X("wizardchild"); 
move_object(find_player("mizan"),"/room/church");
}
