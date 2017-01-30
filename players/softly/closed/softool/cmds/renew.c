status main() 
{ write("Updating cmds...\n"); 
 previous_object()->add_softly_cmds(); 
 write("Update done.\n"); 
 return 1; 
}
