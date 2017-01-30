/*
  WIZARD_LEVEL.c - inherit this into my stuff that needs to check player level
*/

int WIZARD_LEVEL;

reset(arg) { WIZARD_LEVEL=1000; }

query_wizard_level() { return WIZARD_LEVEL; }
