#include <iostream>
#include "automaton.h"

int main() {
    Automaton automaton(100, 100);
    
    automaton.updateSpriteSize();

    automaton.start();

    return 0;
}