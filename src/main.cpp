#include <iostream>
#include "automaton.h"

int main() {
    Automaton automaton(150, 150);
    
    automaton.updateSpriteSize();

    automaton.start();

    return 0;
}