int unlockedA;
int unlockedB;
int unlockedC;

query_unlockedA() { return unlockedA; }
set_unlockedA() { unlockedA = 1; }
set_lockedA() { unlockedA = 0; }

query_unlockedB() { return unlockedB; }
set_unlockedB() { unlockedB = 1; }
set_lockedB() { unlockedB = 0; }

query_unlockedC() { return unlockedC; }
set_unlockedC() { unlockedC = 1; }
set_lockedC() { unlockedC = 0; }
