object peep;

randperson() {
   peep=users()[random(sizeof(users()))];
   write("Random person is "+capitalize(peep->query_real_name())+".\n");
   return 1;
}

query_person() {
   return peep;
}
